/* GStreamer
 * Copyright (C) 2019 Seungha Yang <seungha.yang@navercorp.com>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 51 Franklin St, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 *
 * NOTE: some of implementations are copied/modified from Chromium code
 *
 * Copyright 2015 The Chromium Authors. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 *    * Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 *    * Redistributions in binary form must reproduce the above
 * copyright notice, this list of conditions and the following disclaimer
 * in the documentation and/or other materials provided with the
 * distribution.
 *    * Neither the name of Google Inc. nor the names of its
 * contributors may be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include "gstd3d11decoder.h"
#include "gstd3d11memory.h"
#include "gstd3d11bufferpool.h"
#include "gstd3d11device.h"
#include <string.h>

GST_DEBUG_CATEGORY (d3d11_decoder_debug);
#define GST_CAT_DEFAULT d3d11_decoder_debug

enum
{
  PROP_0,
  PROP_DEVICE,
};

struct _GstD3D11DecoderPrivate
{
  GstD3D11Device *device;

  ID3D11VideoDevice *video_device;
  ID3D11VideoContext *video_context;

  ID3D11VideoDecoder *decoder;

  GstBufferPool *internal_pool;

  /* for staging */
  ID3D11Texture2D *staging;
  D3D11_TEXTURE2D_DESC staging_desc;
  D3D11_BOX staging_box;

  GUID decoder_profile;
};

#define OUTPUT_VIEW_QUARK _decoder_output_view_get()
static GQuark
_decoder_output_view_get (void)
{
  static volatile gsize g_quark = 0;

  if (g_once_init_enter (&g_quark)) {
    gsize quark =
        (gsize) g_quark_from_static_string ("GstD3D11DecoderOutputView");
    g_once_init_leave (&g_quark, quark);
  }
  return (GQuark) g_quark;
}

static void gst_d3d11_decoder_constructed (GObject * object);
static void gst_d3d11_decoder_set_property (GObject * object, guint prop_id,
    const GValue * value, GParamSpec * pspec);
static void gst_d3d11_decoder_get_property (GObject * object, guint prop_id,
    GValue * value, GParamSpec * pspec);
static void gst_d3d11_decoder_dispose (GObject * obj);

#define parent_class gst_d3d11_decoder_parent_class
G_DEFINE_TYPE_WITH_PRIVATE (GstD3D11Decoder,
    gst_d3d11_decoder, GST_TYPE_OBJECT);

static void
gst_d3d11_decoder_class_init (GstD3D11DecoderClass * klass)
{
  GObjectClass *gobject_class = G_OBJECT_CLASS (klass);

  gobject_class->constructed = gst_d3d11_decoder_constructed;
  gobject_class->set_property = gst_d3d11_decoder_set_property;
  gobject_class->get_property = gst_d3d11_decoder_get_property;
  gobject_class->dispose = gst_d3d11_decoder_dispose;

  g_object_class_install_property (gobject_class, PROP_DEVICE,
      g_param_spec_object ("device", "Device",
          "D3D11 Devicd to use", GST_TYPE_D3D11_DEVICE,
          G_PARAM_READWRITE | G_PARAM_CONSTRUCT_ONLY | G_PARAM_STATIC_STRINGS));

  GST_DEBUG_CATEGORY_INIT (d3d11_decoder_debug,
      "d3d11decoder", 0, "Direct3D11 Base Video Decoder object");
}

static void
gst_d3d11_decoder_init (GstD3D11Decoder * self)
{
  self->priv = gst_d3d11_decoder_get_instance_private (self);
}

static void
gst_d3d11_decoder_constructed (GObject * object)
{
  GstD3D11Decoder *self = GST_D3D11_DECODER (object);
  GstD3D11DecoderPrivate *priv = self->priv;
  HRESULT hr;
  ID3D11Device *device_handle;
  ID3D11DeviceContext *device_context_handle;

  if (!priv->device) {
    GST_ERROR_OBJECT (self, "No D3D11Device available");
    return;
  }

  device_handle = gst_d3d11_device_get_device_handle (priv->device);
  device_context_handle =
      gst_d3d11_device_get_device_context_handle (priv->device);

  hr = ID3D11Device_QueryInterface (device_handle, &IID_ID3D11VideoDevice,
      (void **) &priv->video_device);

  if (!gst_d3d11_result (hr, priv->device) || !priv->video_device) {
    GST_WARNING_OBJECT (self, "Cannot create VideoDevice Object: 0x%x",
        (guint) hr);
    priv->video_device = NULL;

    return;
  }

  hr = ID3D11DeviceContext_QueryInterface (device_context_handle,
      &IID_ID3D11VideoContext, (void **) &priv->video_context);

  if (!gst_d3d11_result (hr, priv->device) || !priv->video_context) {
    GST_WARNING_OBJECT (self, "Cannot create VideoContext Object: 0x%x",
        (guint) hr);
    priv->video_context = NULL;

    goto fail;
  }

  return;

fail:
  if (priv->video_device) {
    ID3D11VideoDevice_Release (priv->video_device);
    priv->video_device = NULL;
  }

  if (priv->video_context) {
    ID3D11VideoContext_Release (priv->video_context);
    priv->video_context = NULL;
  }

  return;
}

static void
gst_d3d11_decoder_set_property (GObject * object, guint prop_id,
    const GValue * value, GParamSpec * pspec)
{
  GstD3D11Decoder *self = GST_D3D11_DECODER (object);
  GstD3D11DecoderPrivate *priv = self->priv;

  switch (prop_id) {
    case PROP_DEVICE:
      priv->device = g_value_dup_object (value);
      break;
    default:
      G_OBJECT_WARN_INVALID_PROPERTY_ID (object, prop_id, pspec);
      break;
  }
}

static void
gst_d3d11_decoder_get_property (GObject * object, guint prop_id,
    GValue * value, GParamSpec * pspec)
{
  GstD3D11Decoder *self = GST_D3D11_DECODER (object);
  GstD3D11DecoderPrivate *priv = self->priv;

  switch (prop_id) {
    case PROP_DEVICE:
      g_value_set_object (value, priv->device);
      break;
    default:
      G_OBJECT_WARN_INVALID_PROPERTY_ID (object, prop_id, pspec);
      break;
  }
}

static gboolean
gst_d3d11_decoder_close (GstD3D11Decoder * self)
{
  GstD3D11DecoderPrivate *priv = self->priv;

  gst_d3d11_decoder_reset (self);

  if (priv->video_device) {
    ID3D11VideoDevice_Release (priv->video_device);
    priv->video_device = NULL;
  }

  if (priv->video_context) {
    ID3D11VideoContext_Release (priv->video_context);
    priv->video_context = NULL;
  }

  return TRUE;
}

static void
gst_d3d11_decoder_reset_unlocked (GstD3D11Decoder * decoder)
{
  GstD3D11DecoderPrivate *priv;

  priv = decoder->priv;
  gst_clear_object (&priv->internal_pool);

  if (priv->decoder) {
    ID3D11VideoDecoder_Release (priv->decoder);
    priv->decoder = NULL;
  }

  if (priv->staging) {
    ID3D11Texture2D_Release (priv->staging);
    priv->staging = NULL;
  }

  decoder->opened = FALSE;
}

void
gst_d3d11_decoder_reset (GstD3D11Decoder * decoder)
{
  GstD3D11DecoderPrivate *priv;

  g_return_if_fail (GST_IS_D3D11_DECODER (decoder));

  priv = decoder->priv;
  gst_d3d11_device_lock (priv->device);
  gst_d3d11_decoder_reset_unlocked (decoder);
  gst_d3d11_device_unlock (priv->device);
}

static void
gst_d3d11_decoder_dispose (GObject * obj)
{
  GstD3D11Decoder *self = GST_D3D11_DECODER (obj);
  GstD3D11DecoderPrivate *priv = self->priv;

  if (priv->device) {
    gst_d3d11_decoder_close (self);
    gst_object_unref (priv->device);
    priv->device = NULL;
  }

  G_OBJECT_CLASS (parent_class)->dispose (obj);
}

GstD3D11Decoder *
gst_d3d11_decoder_new (GstD3D11Device * device)
{
  GstD3D11Decoder *decoder;
  GstD3D11DecoderPrivate *priv;

  g_return_val_if_fail (GST_IS_D3D11_DEVICE (device), NULL);

  decoder = g_object_new (GST_TYPE_D3D11_DECODER, "device", device, NULL);
  priv = decoder->priv;

  if (!priv->video_device || !priv->video_context) {
    gst_object_unref (decoder);
    return NULL;
  }

  gst_object_ref_sink (decoder);

  return decoder;
}

static void
gst_d3d11_decoder_output_view_free (GstD3D11DecoderOutputView * view)
{
  GST_DEBUG_OBJECT (view->device, "Free view %p", view);

  if (view->handle) {
    gst_d3d11_device_lock (view->device);
    ID3D11VideoDecoderOutputView_Release (view->handle);
    gst_d3d11_device_unlock (view->device);
  }

  gst_clear_object (&view->device);
  g_free (view);
}

static gboolean
gst_d3d11_decoder_ensure_output_view (GstD3D11Decoder * self,
    GstBuffer * buffer)
{
  GstD3D11DecoderPrivate *priv = self->priv;
  D3D11_VIDEO_DECODER_OUTPUT_VIEW_DESC view_desc = { 0, };
  GstD3D11Memory *mem;
  GstD3D11DecoderOutputView *view;
  ID3D11VideoDecoderOutputView *view_handle;
  HRESULT hr;

  mem = (GstD3D11Memory *) gst_buffer_peek_memory (buffer, 0);

  view = (GstD3D11DecoderOutputView *)
      gst_mini_object_get_qdata (GST_MINI_OBJECT_CAST (mem), OUTPUT_VIEW_QUARK);

  if (view)
    return TRUE;

  view_desc.DecodeProfile = priv->decoder_profile;
  view_desc.ViewDimension = D3D11_VDOV_DIMENSION_TEXTURE2D;
  view_desc.Texture2D.ArraySlice = mem->subresource_index;

  GST_LOG_OBJECT (self,
      "Create decoder output view with index %d", mem->subresource_index);

  hr = ID3D11VideoDevice_CreateVideoDecoderOutputView (priv->video_device,
      (ID3D11Resource *) mem->texture, &view_desc, &view_handle);
  if (!gst_d3d11_result (hr, priv->device)) {
    GST_ERROR_OBJECT (self,
        "Could not create decoder output view, hr: 0x%x", (guint) hr);
    return FALSE;
  }

  view = g_new0 (GstD3D11DecoderOutputView, 1);
  view->device = gst_object_ref (priv->device);
  view->handle = view_handle;
  view->view_id = mem->subresource_index;

  gst_mini_object_set_qdata (GST_MINI_OBJECT_CAST (mem), OUTPUT_VIEW_QUARK,
      view, (GDestroyNotify) gst_d3d11_decoder_output_view_free);

  return TRUE;
}

/* Must be called from D3D11Device thread */
static gboolean
gst_d3d11_decoder_prepare_output_view_pool (GstD3D11Decoder * self,
    GstVideoInfo * info, guint coded_width, guint coded_height,
    guint pool_size, const GUID * decoder_profile)
{
  GstD3D11DecoderPrivate *priv = self->priv;
  GstD3D11AllocationParams *alloc_params = NULL;
  GstBufferPool *pool = NULL;
  GstStructure *config = NULL;
  GstCaps *caps = NULL;
  GstVideoAlignment align;

  gst_clear_object (&priv->internal_pool);

  alloc_params = gst_d3d11_allocation_params_new (priv->device, info,
      GST_D3D11_ALLOCATION_FLAG_TEXTURE_ARRAY, D3D11_BIND_DECODER);

  if (!alloc_params) {
    GST_ERROR_OBJECT (self, "Failed to create allocation param");
    goto error;
  }

  alloc_params->desc[0].ArraySize = pool_size;
  gst_video_alignment_reset (&align);

  align.padding_right = coded_width - GST_VIDEO_INFO_WIDTH (info);
  align.padding_bottom = coded_height - GST_VIDEO_INFO_HEIGHT (info);
  if (!gst_d3d11_allocation_params_alignment (alloc_params, &align)) {
    GST_ERROR_OBJECT (self, "Cannot set alignment");
    return FALSE;
  }

  pool = gst_d3d11_buffer_pool_new (priv->device);
  if (!pool) {
    GST_ERROR_OBJECT (self, "Failed to create buffer pool");
    goto error;
  }

  /* Setup buffer pool */
  config = gst_buffer_pool_get_config (pool);
  caps = gst_video_info_to_caps (info);
  if (!caps) {
    GST_ERROR_OBJECT (self, "Couldn't convert video info to caps");
    goto error;
  }

  gst_buffer_pool_config_set_params (config, caps, GST_VIDEO_INFO_SIZE (info),
      0, pool_size);
  gst_buffer_pool_config_set_d3d11_allocation_params (config, alloc_params);
  gst_caps_unref (caps);
  gst_d3d11_allocation_params_free (alloc_params);
  gst_buffer_pool_config_add_option (config, GST_BUFFER_POOL_OPTION_VIDEO_META);

  if (!gst_buffer_pool_set_config (pool, config)) {
    GST_ERROR_OBJECT (self, "Invalid pool config");
    goto error;
  }

  if (!gst_buffer_pool_set_active (pool, TRUE)) {
    GST_ERROR_OBJECT (self, "Couldn't activate pool");
    goto error;
  }

  priv->internal_pool = pool;

  return TRUE;

error:
  if (alloc_params)
    gst_d3d11_allocation_params_free (alloc_params);
  if (pool)
    gst_object_unref (pool);
  if (caps)
    gst_caps_unref (caps);

  return FALSE;
}

gboolean
gst_d3d11_decoder_get_supported_decoder_profile (GstD3D11Decoder * decoder,
    const GUID ** decoder_profiles, guint profile_size, GUID * selected_profile)
{
  GstD3D11DecoderPrivate *priv;
  GUID *guid_list = NULL;
  const GUID *profile = NULL;
  guint available_profile_count;
  gint i, j;
  HRESULT hr;

  g_return_val_if_fail (GST_IS_D3D11_DECODER (decoder), FALSE);
  g_return_val_if_fail (decoder_profiles != NULL, FALSE);
  g_return_val_if_fail (profile_size > 0, FALSE);
  g_return_val_if_fail (selected_profile != NULL, FALSE);

  priv = decoder->priv;

  available_profile_count =
      ID3D11VideoDevice_GetVideoDecoderProfileCount (priv->video_device);

  if (available_profile_count == 0) {
    GST_WARNING_OBJECT (decoder, "No available decoder profile");
    return FALSE;
  }

  GST_DEBUG_OBJECT (decoder,
      "Have %u available decoder profiles", available_profile_count);
  guid_list = g_alloca (sizeof (GUID) * available_profile_count);

  for (i = 0; i < available_profile_count; i++) {
    hr = ID3D11VideoDevice_GetVideoDecoderProfile (priv->video_device,
        i, &guid_list[i]);
    if (!gst_d3d11_result (hr, priv->device)) {
      GST_WARNING_OBJECT (decoder, "Failed to get %d th decoder profile", i);
      return FALSE;
    }
  }

#ifndef GST_DISABLE_GST_DEBUG
  GST_LOG_OBJECT (decoder, "Supported decoder GUID");
  for (i = 0; i < available_profile_count; i++) {
    const GUID *guid = &guid_list[i];

    GST_LOG_OBJECT (decoder,
        "\t { %8.8x-%4.4x-%4.4x-%2.2x%2.2x-%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x }",
        (guint) guid->Data1, (guint) guid->Data2, (guint) guid->Data3,
        guid->Data4[0], guid->Data4[1], guid->Data4[2], guid->Data4[3],
        guid->Data4[4], guid->Data4[5], guid->Data4[6], guid->Data4[7]);
  }

  GST_LOG_OBJECT (decoder, "Requested decoder GUID");
  for (i = 0; i < profile_size; i++) {
    const GUID *guid = decoder_profiles[i];

    GST_LOG_OBJECT (decoder,
        "\t { %8.8x-%4.4x-%4.4x-%2.2x%2.2x-%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x }",
        (guint) guid->Data1, (guint) guid->Data2, (guint) guid->Data3,
        guid->Data4[0], guid->Data4[1], guid->Data4[2], guid->Data4[3],
        guid->Data4[4], guid->Data4[5], guid->Data4[6], guid->Data4[7]);
  }
#endif

  for (i = 0; i < profile_size; i++) {
    for (j = 0; j < available_profile_count; j++) {
      if (IsEqualGUID (decoder_profiles[i], &guid_list[j])) {
        profile = decoder_profiles[i];
        break;
      }
    }
  }

  if (!profile) {
    GST_WARNING_OBJECT (decoder, "No supported decoder profile");
    return FALSE;
  }

  *selected_profile = *profile;

  GST_DEBUG_OBJECT (decoder,
      "Selected guid "
      "{ %8.8x-%4.4x-%4.4x-%2.2x%2.2x-%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x }",
      (guint) selected_profile->Data1, (guint) selected_profile->Data2,
      (guint) selected_profile->Data3,
      selected_profile->Data4[0], selected_profile->Data4[1],
      selected_profile->Data4[2], selected_profile->Data4[3],
      selected_profile->Data4[4], selected_profile->Data4[5],
      selected_profile->Data4[6], selected_profile->Data4[7]);

  return TRUE;
}

gboolean
gst_d3d11_decoder_open (GstD3D11Decoder * decoder, GstD3D11Codec codec,
    GstVideoInfo * info, guint coded_width, guint coded_height,
    guint pool_size, const GUID ** decoder_profiles, guint profile_size)
{
  GstD3D11DecoderPrivate *priv;
  const GstD3D11Format *d3d11_format;
  HRESULT hr;
  BOOL can_support = FALSE;
  guint config_count;
  D3D11_VIDEO_DECODER_CONFIG *config_list;
  D3D11_VIDEO_DECODER_CONFIG *best_config = NULL;
  D3D11_VIDEO_DECODER_DESC decoder_desc = { 0, };
  GUID selected_profile;
  gint i;
  guint aligned_width, aligned_height;
  guint alignment;

  g_return_val_if_fail (GST_IS_D3D11_DECODER (decoder), FALSE);
  g_return_val_if_fail (codec > GST_D3D11_CODEC_NONE, FALSE);
  g_return_val_if_fail (codec < GST_D3D11_CODEC_LAST, FALSE);
  g_return_val_if_fail (info != NULL, FALSE);
  g_return_val_if_fail (coded_width >= GST_VIDEO_INFO_WIDTH (info), FALSE);
  g_return_val_if_fail (coded_height >= GST_VIDEO_INFO_HEIGHT (info), FALSE);
  g_return_val_if_fail (pool_size > 0, FALSE);
  g_return_val_if_fail (decoder_profiles != NULL, FALSE);
  g_return_val_if_fail (profile_size > 0, FALSE);

  priv = decoder->priv;
  decoder->opened = FALSE;

  d3d11_format = gst_d3d11_device_format_from_gst (priv->device,
      GST_VIDEO_INFO_FORMAT (info));
  if (!d3d11_format || d3d11_format->dxgi_format == DXGI_FORMAT_UNKNOWN) {
    GST_ERROR_OBJECT (decoder, "Could not determine dxgi format from %s",
        gst_video_format_to_string (GST_VIDEO_INFO_FORMAT (info)));
    return FALSE;
  }

  gst_d3d11_device_lock (priv->device);
  if (!gst_d3d11_decoder_get_supported_decoder_profile (decoder,
          decoder_profiles, profile_size, &selected_profile)) {
    goto error;
  }

  hr = ID3D11VideoDevice_CheckVideoDecoderFormat (priv->video_device,
      &selected_profile, d3d11_format->dxgi_format, &can_support);
  if (!gst_d3d11_result (hr, priv->device) || !can_support) {
    GST_ERROR_OBJECT (decoder,
        "VideoDevice could not support dxgi format %d, hr: 0x%x",
        d3d11_format->dxgi_format, (guint) hr);
    goto error;
  }

  gst_d3d11_decoder_reset_unlocked (decoder);

  /* NOTE: other dxva implementations (ffmpeg and vlc) do this
   * and they say the required alignment were mentioned by dxva spec.
   * See ff_dxva2_common_frame_params() in dxva.c of ffmpeg and
   * directx_va_Setup() in directx_va.c of vlc.
   * But... where it is? */
  switch (codec) {
    case GST_D3D11_CODEC_H265:
      alignment = 128;
      break;
    default:
      alignment = 16;
      break;
  }

  aligned_width = GST_ROUND_UP_N (coded_width, alignment);
  aligned_height = GST_ROUND_UP_N (coded_height, alignment);
  if (aligned_width != coded_width || aligned_height != coded_height) {
    GST_DEBUG_OBJECT (decoder,
        "coded resolution %dx%d is not aligned to %d, adjust to %dx%d",
        coded_width, coded_height, alignment, aligned_width, aligned_height);
  }

  decoder_desc.SampleWidth = aligned_width;
  decoder_desc.SampleHeight = aligned_height;
  decoder_desc.OutputFormat = d3d11_format->dxgi_format;
  decoder_desc.Guid = selected_profile;

  hr = ID3D11VideoDevice_GetVideoDecoderConfigCount (priv->video_device,
      &decoder_desc, &config_count);
  if (!gst_d3d11_result (hr, priv->device) || config_count == 0) {
    GST_ERROR_OBJECT (decoder, "Could not get decoder config count, hr: 0x%x",
        (guint) hr);
    goto error;
  }

  GST_DEBUG_OBJECT (decoder, "Total %d config available", config_count);

  config_list = g_alloca (sizeof (D3D11_VIDEO_DECODER_CONFIG) * config_count);

  for (i = 0; i < config_count; i++) {
    hr = ID3D11VideoDevice_GetVideoDecoderConfig (priv->video_device,
        &decoder_desc, i, &config_list[i]);
    if (!gst_d3d11_result (hr, priv->device)) {
      GST_ERROR_OBJECT (decoder, "Could not get decoder %dth config, hr: 0x%x",
          i, (guint) hr);
      goto error;
    }

    /* FIXME: need support DXVA_Slice_H264_Long ?? */
    /* this config uses DXVA_Slice_H264_Short */
    if (codec == GST_D3D11_CODEC_H264 && config_list[i].ConfigBitstreamRaw == 2) {
      best_config = &config_list[i];
      break;
    }

    if ((codec == GST_D3D11_CODEC_VP9 || codec == GST_D3D11_CODEC_H265)
        && config_list[i].ConfigBitstreamRaw == 1) {
      best_config = &config_list[i];
      break;
    }
  }

  if (best_config == NULL) {
    GST_ERROR_OBJECT (decoder, "Could not determine decoder config");
    goto error;
  }

  if (!gst_d3d11_decoder_prepare_output_view_pool (decoder,
          info, aligned_width, aligned_height, pool_size, &selected_profile)) {
    GST_ERROR_OBJECT (decoder, "Couldn't prepare output view pool");
    goto error;
  }

  hr = ID3D11VideoDevice_CreateVideoDecoder (priv->video_device,
      &decoder_desc, best_config, &priv->decoder);
  if (!gst_d3d11_result (hr, priv->device) || !priv->decoder) {
    GST_ERROR_OBJECT (decoder,
        "Could not create decoder object, hr: 0x%x", (guint) hr);
    goto error;
  }

  GST_DEBUG_OBJECT (decoder, "Decoder object %p created", priv->decoder);

  /* create stage texture to copy out */
  memset (&priv->staging_desc, 0, sizeof (D3D11_TEXTURE2D_DESC));
  priv->staging_desc.Width = GST_VIDEO_INFO_WIDTH (info);
  priv->staging_desc.Height = GST_VIDEO_INFO_HEIGHT (info);
  priv->staging_desc.MipLevels = 1;
  priv->staging_desc.Format = d3d11_format->dxgi_format;
  priv->staging_desc.SampleDesc.Count = 1;
  priv->staging_desc.ArraySize = 1;
  priv->staging_desc.Usage = D3D11_USAGE_STAGING;
  priv->staging_desc.CPUAccessFlags = D3D11_CPU_ACCESS_READ;

  priv->staging = gst_d3d11_device_create_texture (priv->device,
      &priv->staging_desc, NULL);
  if (!priv->staging) {
    GST_ERROR_OBJECT (decoder, "Couldn't create staging texture");
    goto error;
  }

  /* This D3D11_BOX structure is used to copy decoder view to staging texture,
   * in case of system memory downstream.
   * Since resolution of decoder view might be larger than this staging texture,
   * this D3D11_BOX structure will guide the target area which need to be copied.
   */
  priv->staging_box.left = 0;
  priv->staging_box.top = 0;
  priv->staging_box.front = 0;
  priv->staging_box.back = 1;
  priv->staging_box.right = GST_VIDEO_INFO_WIDTH (info);
  priv->staging_box.bottom = GST_VIDEO_INFO_HEIGHT (info);

  priv->decoder_profile = selected_profile;
  decoder->opened = TRUE;
  gst_d3d11_device_unlock (priv->device);

  return TRUE;

error:
  gst_d3d11_device_unlock (priv->device);

  return FALSE;
}

gboolean
gst_d3d11_decoder_begin_frame (GstD3D11Decoder * decoder,
    GstD3D11DecoderOutputView * output_view, guint content_key_size,
    gconstpointer content_key)
{
  GstD3D11DecoderPrivate *priv;
  guint retry_count = 0;
  HRESULT hr;

  g_return_val_if_fail (GST_IS_D3D11_DECODER (decoder), FALSE);
  g_return_val_if_fail (output_view != NULL, FALSE);
  g_return_val_if_fail (output_view->handle != NULL, FALSE);

  priv = decoder->priv;

  do {
    GST_LOG_OBJECT (decoder, "Try begin frame, retry count %d", retry_count);
    gst_d3d11_device_lock (priv->device);
    hr = ID3D11VideoContext_DecoderBeginFrame (priv->video_context,
        priv->decoder, output_view->handle, content_key_size, content_key);
    gst_d3d11_device_unlock (priv->device);

    if (hr == E_PENDING && retry_count < 50) {
      GST_LOG_OBJECT (decoder, "GPU busy, try again");

      /* HACK: no better idea other than sleep...
       * 1ms waiting like msdkdec */
      g_usleep (1000);
    } else {
      if (gst_d3d11_result (hr, priv->device))
        GST_LOG_OBJECT (decoder, "Success with retry %d", retry_count);
      break;
    }

    retry_count++;
  } while (TRUE);

  if (!gst_d3d11_result (hr, priv->device)) {
    GST_ERROR_OBJECT (decoder, "Failed to begin frame, hr: 0x%x", (guint) hr);
    return FALSE;
  }

  return TRUE;
}

gboolean
gst_d3d11_decoder_end_frame (GstD3D11Decoder * decoder)
{
  GstD3D11DecoderPrivate *priv;
  HRESULT hr;

  g_return_val_if_fail (GST_IS_D3D11_DECODER (decoder), FALSE);

  priv = decoder->priv;

  gst_d3d11_device_lock (priv->device);
  hr = ID3D11VideoContext_DecoderEndFrame (priv->video_context, priv->decoder);
  gst_d3d11_device_unlock (priv->device);

  if (!gst_d3d11_result (hr, priv->device)) {
    GST_WARNING_OBJECT (decoder, "EndFrame failed, hr: 0x%x", (guint) hr);
    return FALSE;
  }

  return TRUE;
}

gboolean
gst_d3d11_decoder_get_decoder_buffer (GstD3D11Decoder * decoder,
    D3D11_VIDEO_DECODER_BUFFER_TYPE type, guint * buffer_size,
    gpointer * buffer)
{
  GstD3D11DecoderPrivate *priv;
  UINT size;
  void *decoder_buffer;
  HRESULT hr;

  g_return_val_if_fail (GST_IS_D3D11_DECODER (decoder), FALSE);

  priv = decoder->priv;

  gst_d3d11_device_lock (priv->device);
  hr = ID3D11VideoContext_GetDecoderBuffer (priv->video_context,
      priv->decoder, type, &size, &decoder_buffer);
  gst_d3d11_device_unlock (priv->device);

  if (!gst_d3d11_result (hr, priv->device)) {
    GST_WARNING_OBJECT (decoder, "Getting buffer type %d error, hr: 0x%x",
        type, (guint) hr);
    return FALSE;
  }

  *buffer_size = size;
  *buffer = decoder_buffer;

  return TRUE;
}

gboolean
gst_d3d11_decoder_release_decoder_buffer (GstD3D11Decoder * decoder,
    D3D11_VIDEO_DECODER_BUFFER_TYPE type)
{
  GstD3D11DecoderPrivate *priv;
  HRESULT hr;

  g_return_val_if_fail (GST_IS_D3D11_DECODER (decoder), FALSE);

  priv = decoder->priv;

  gst_d3d11_device_lock (priv->device);
  hr = ID3D11VideoContext_ReleaseDecoderBuffer (priv->video_context,
      priv->decoder, type);
  gst_d3d11_device_unlock (priv->device);

  if (!gst_d3d11_result (hr, priv->device)) {
    GST_WARNING_OBJECT (decoder, "ReleaseDecoderBuffer failed, hr: 0x%x",
        (guint) hr);
    return FALSE;
  }

  return TRUE;
}

gboolean
gst_d3d11_decoder_submit_decoder_buffers (GstD3D11Decoder * decoder,
    guint buffer_count, const D3D11_VIDEO_DECODER_BUFFER_DESC * buffers)
{
  GstD3D11DecoderPrivate *priv;
  HRESULT hr;

  g_return_val_if_fail (GST_IS_D3D11_DECODER (decoder), FALSE);

  priv = decoder->priv;

  gst_d3d11_device_lock (priv->device);
  hr = ID3D11VideoContext_SubmitDecoderBuffers (priv->video_context,
      priv->decoder, buffer_count, buffers);
  gst_d3d11_device_unlock (priv->device);

  if (!gst_d3d11_result (hr, priv->device)) {
    GST_WARNING_OBJECT (decoder, "SubmitDecoderBuffers failed, hr: 0x%x",
        (guint) hr);
    return FALSE;
  }

  return TRUE;
}

GstBuffer *
gst_d3d11_decoder_get_output_view_buffer (GstD3D11Decoder * decoder)
{
  GstD3D11DecoderPrivate *priv;
  GstBuffer *buf = NULL;
  GstFlowReturn ret;

  g_return_val_if_fail (GST_IS_D3D11_DECODER (decoder), FALSE);

  priv = decoder->priv;

  ret = gst_buffer_pool_acquire_buffer (priv->internal_pool, &buf, NULL);

  if (ret != GST_FLOW_OK || !buf) {
    GST_ERROR_OBJECT (decoder, "Couldn't get buffer from pool, ret %s",
        gst_flow_get_name (ret));
    return NULL;
  }

  if (!gst_d3d11_decoder_ensure_output_view (decoder, buf)) {
    GST_ERROR_OBJECT (decoder, "Output view unavailable");
    gst_buffer_unref (buf);

    return NULL;
  }

  return buf;
}

GstD3D11DecoderOutputView *
gst_d3d11_decoder_get_output_view_from_buffer (GstD3D11Decoder * decoder,
    GstBuffer * buffer)
{
  GstMemory *mem;
  GstD3D11DecoderOutputView *view;

  g_return_val_if_fail (GST_IS_D3D11_DECODER (decoder), NULL);
  g_return_val_if_fail (GST_IS_BUFFER (buffer), NULL);

  mem = gst_buffer_peek_memory (buffer, 0);
  if (!gst_is_d3d11_memory (mem)) {
    GST_WARNING_OBJECT (decoder, "nemory is not d3d11 memory");
    return NULL;
  }

  view = (GstD3D11DecoderOutputView *)
      gst_mini_object_get_qdata (GST_MINI_OBJECT_CAST (mem), OUTPUT_VIEW_QUARK);

  if (!view) {
    GST_WARNING_OBJECT (decoder, "memory does not have output view");
  }

  return view;
}

guint
gst_d3d11_decoder_get_output_view_index (GstD3D11Decoder * decoder,
    ID3D11VideoDecoderOutputView * view_handle)
{
  D3D11_VIDEO_DECODER_OUTPUT_VIEW_DESC view_desc;

  g_return_val_if_fail (GST_IS_D3D11_DECODER (decoder), 0xff);
  g_return_val_if_fail (view_handle != NULL, 0xff);

  ID3D11VideoDecoderOutputView_GetDesc (view_handle, &view_desc);

  return view_desc.Texture2D.ArraySlice;
}

static gboolean
copy_to_system (GstD3D11Decoder * self, GstVideoInfo * info,
    GstBuffer * decoder_buffer, GstBuffer * output)
{
  GstD3D11DecoderPrivate *priv = self->priv;
  D3D11_TEXTURE2D_DESC *desc = &priv->staging_desc;
  GstVideoFrame out_frame;
  gint i;
  GstD3D11Memory *in_mem;
  D3D11_MAPPED_SUBRESOURCE map;
  gsize offset[GST_VIDEO_MAX_PLANES];
  gint stride[GST_VIDEO_MAX_PLANES];
  gsize dummy;
  HRESULT hr;
  ID3D11DeviceContext *device_context =
      gst_d3d11_device_get_device_context_handle (priv->device);

  if (!gst_video_frame_map (&out_frame, info, output, GST_MAP_WRITE)) {
    GST_ERROR_OBJECT (self, "Couldn't map output buffer");
    return FALSE;
  }

  in_mem = (GstD3D11Memory *) gst_buffer_peek_memory (decoder_buffer, 0);

  gst_d3d11_device_lock (priv->device);
  ID3D11DeviceContext_CopySubresourceRegion (device_context,
      (ID3D11Resource *) priv->staging, 0, 0, 0, 0,
      (ID3D11Resource *) in_mem->texture, in_mem->subresource_index,
      &priv->staging_box);

  hr = ID3D11DeviceContext_Map (device_context,
      (ID3D11Resource *) priv->staging, 0, D3D11_MAP_READ, 0, &map);

  if (!gst_d3d11_result (hr, priv->device)) {
    GST_ERROR_OBJECT (self, "Failed to map, hr: 0x%x", (guint) hr);
    gst_d3d11_device_unlock (priv->device);
    return FALSE;
  }

  gst_d3d11_dxgi_format_get_size (desc->Format, desc->Width, desc->Height,
      map.RowPitch, offset, stride, &dummy);

  for (i = 0; i < GST_VIDEO_FRAME_N_PLANES (&out_frame); i++) {
    guint8 *src, *dst;
    gint j;
    gint width;

    src = (guint8 *) map.pData + offset[i];
    dst = GST_VIDEO_FRAME_PLANE_DATA (&out_frame, i);
    width = GST_VIDEO_FRAME_COMP_WIDTH (&out_frame, i) *
        GST_VIDEO_FRAME_COMP_PSTRIDE (&out_frame, i);

    for (j = 0; j < GST_VIDEO_FRAME_COMP_HEIGHT (&out_frame, i); j++) {
      memcpy (dst, src, width);
      dst += GST_VIDEO_FRAME_PLANE_STRIDE (&out_frame, i);
      src += map.RowPitch;
    }
  }

  gst_video_frame_unmap (&out_frame);
  ID3D11DeviceContext_Unmap (device_context, (ID3D11Resource *) priv->staging,
      0);
  gst_d3d11_device_unlock (priv->device);

  return TRUE;
}

static gboolean
copy_to_d3d11 (GstD3D11Decoder * self, GstVideoInfo * info,
    GstBuffer * decoder_buffer, GstBuffer * output)
{
  GstD3D11DecoderPrivate *priv = self->priv;
  gint i;
  ID3D11DeviceContext *device_context =
      gst_d3d11_device_get_device_context_handle (priv->device);

  gst_d3d11_device_lock (priv->device);
  for (i = 0; i < gst_buffer_n_memory (output); i++) {
    GstD3D11Memory *in_mem;
    GstD3D11Memory *out_mem;
    D3D11_BOX src_box;
    D3D11_TEXTURE2D_DESC desc;

    in_mem = (GstD3D11Memory *) gst_buffer_peek_memory (decoder_buffer, i);
    out_mem = (GstD3D11Memory *) gst_buffer_peek_memory (output, i);

    ID3D11Texture2D_GetDesc (out_mem->texture, &desc);

    src_box.left = 0;
    src_box.top = 0;
    src_box.front = 0;
    src_box.back = 1;
    src_box.right = desc.Width;
    src_box.bottom = desc.Height;

    ID3D11DeviceContext_CopySubresourceRegion (device_context,
        (ID3D11Resource *) out_mem->texture,
        out_mem->subresource_index, 0, 0, 0,
        (ID3D11Resource *) in_mem->texture, in_mem->subresource_index,
        &src_box);

    GST_MINI_OBJECT_FLAG_SET (out_mem, GST_D3D11_MEMORY_TRANSFER_NEED_DOWNLOAD);
  }
  gst_d3d11_device_unlock (priv->device);

  return TRUE;
}

gboolean
gst_d3d11_decoder_copy_decoder_buffer (GstD3D11Decoder * decoder,
    GstVideoInfo * info, GstBuffer * decoder_buffer, GstBuffer * output)
{
  GstD3D11DecoderPrivate *priv;
  gboolean can_device_copy = TRUE;

  g_return_val_if_fail (GST_IS_D3D11_DECODER (decoder), FALSE);
  g_return_val_if_fail (GST_IS_BUFFER (decoder_buffer), FALSE);
  g_return_val_if_fail (GST_IS_BUFFER (output), FALSE);

  priv = decoder->priv;

  if (gst_buffer_n_memory (decoder_buffer) == gst_buffer_n_memory (output)) {
    gint i;

    for (i = 0; i < gst_buffer_n_memory (output); i++) {
      GstMemory *mem;
      GstD3D11Memory *dmem;

      mem = gst_buffer_peek_memory (output, i);

      if (!gst_is_d3d11_memory (mem)) {
        can_device_copy = FALSE;
        break;
      }

      dmem = (GstD3D11Memory *) mem;

      if (dmem->device != priv->device) {
        can_device_copy = FALSE;
        break;
      }
    }
  } else {
    can_device_copy = FALSE;
  }

  if (can_device_copy) {
    return copy_to_d3d11 (decoder, info, decoder_buffer, output);
  }

  return copy_to_system (decoder, info, decoder_buffer, output);
}

static const gchar *
gst_d3d11_decoder_status_code_to_verbose_string (guint status_code)
{
  const gchar *status = NULL;

  switch (status_code) {
    case 0:
      status = "The operation succeeded";
      break;
    case 1:
      status = "Minor problem in the data format. "
          "The host decoder should continue processing";
      break;
    case 2:
      status = "Significant problem in the data format. The host decoder may "
          "continue executing or skip the display of the output picture";
      break;
    case 3:
      status = "Severe problem in the data format. The host decoder should "
          "restart the entire decoding process, starting at a sequence or "
          "random-access entry point";
      break;
    case 4:
      status =
          "Other severe problem. The host decoder should restart the entire "
          "decoding process, starting at a sequence or random-access entry point";
      break;
    default:
      status = "Unknown status";
      break;
  }

  return status;
}

gboolean
gst_d3d11_decoder_get_status_report (GstD3D11Decoder * decoder,
    GstDXVAStatus * status, GError ** err)
{
  GstD3D11DecoderPrivate *priv;
  HRESULT hr;
  D3D11_VIDEO_DECODER_EXTENSION extension = { 0, };
  gboolean ret;

  g_return_val_if_fail (GST_IS_D3D11_DECODER (decoder), FALSE);
  g_return_val_if_fail (status != NULL, FALSE);

  priv = decoder->priv;

  /* For status report */
  extension.Function = 7;
  extension.pPrivateOutputData = (PVOID) status;
  extension.PrivateOutputDataSize = sizeof (GstDXVAStatus);

  gst_d3d11_device_lock (priv->device);
  hr = ID3D11VideoContext_DecoderExtension (priv->video_context, priv->decoder,
      &extension);
  gst_d3d11_device_unlock (priv->device);

  ret = gst_d3d11_result (hr, priv->device);

  if (ret && status->bStatus != 0) {
    /* TODO: if status code is 3 or 4, we might need to restart decoding
     * from new keyframe */
    GST_WARNING_OBJECT (decoder,
        "Status code: %d, StatusReportFeedbackNumber: %d, "
        "CurrPic.Index7Bits: %d, CurrPic.AssociatedFlag: %d, bBufType: %d, "
        "wNumMbsAffected: %d", status->bStatus,
        status->StatusReportFeedbackNumber,
        status->CurrPic.Index7Bits, status->CurrPic.AssociatedFlag,
        status->bBufType, status->wNumMbsAffected);

    if (status->bStatus > 1) {
      const gchar *status_str =
          gst_d3d11_decoder_status_code_to_verbose_string (status->bStatus);

      g_set_error_literal (err, GST_STREAM_ERROR,
          GST_STREAM_ERROR_DECODE, status_str);
    }
  }

  return ret;
}

/* Keep sync with chromium and keep in sorted order.
 * See supported_profile_helpers.cc in chromium */
static const guint legacy_amd_list[] = {
  0x130f, 0x6700, 0x6701, 0x6702, 0x6703, 0x6704, 0x6705, 0x6706, 0x6707,
  0x6708, 0x6709, 0x6718, 0x6719, 0x671c, 0x671d, 0x671f, 0x6720, 0x6721,
  0x6722, 0x6723, 0x6724, 0x6725, 0x6726, 0x6727, 0x6728, 0x6729, 0x6738,
  0x6739, 0x673e, 0x6740, 0x6741, 0x6742, 0x6743, 0x6744, 0x6745, 0x6746,
  0x6747, 0x6748, 0x6749, 0x674a, 0x6750, 0x6751, 0x6758, 0x6759, 0x675b,
  0x675d, 0x675f, 0x6760, 0x6761, 0x6762, 0x6763, 0x6764, 0x6765, 0x6766,
  0x6767, 0x6768, 0x6770, 0x6771, 0x6772, 0x6778, 0x6779, 0x677b, 0x6798,
  0x67b1, 0x6821, 0x683d, 0x6840, 0x6841, 0x6842, 0x6843, 0x6849, 0x6850,
  0x6858, 0x6859, 0x6880, 0x6888, 0x6889, 0x688a, 0x688c, 0x688d, 0x6898,
  0x6899, 0x689b, 0x689c, 0x689d, 0x689e, 0x68a0, 0x68a1, 0x68a8, 0x68a9,
  0x68b0, 0x68b8, 0x68b9, 0x68ba, 0x68be, 0x68bf, 0x68c0, 0x68c1, 0x68c7,
  0x68c8, 0x68c9, 0x68d8, 0x68d9, 0x68da, 0x68de, 0x68e0, 0x68e1, 0x68e4,
  0x68e5, 0x68e8, 0x68e9, 0x68f1, 0x68f2, 0x68f8, 0x68f9, 0x68fa, 0x68fe,
  0x9400, 0x9401, 0x9402, 0x9403, 0x9405, 0x940a, 0x940b, 0x940f, 0x9440,
  0x9441, 0x9442, 0x9443, 0x9444, 0x9446, 0x944a, 0x944b, 0x944c, 0x944e,
  0x9450, 0x9452, 0x9456, 0x945a, 0x945b, 0x945e, 0x9460, 0x9462, 0x946a,
  0x946b, 0x947a, 0x947b, 0x9480, 0x9487, 0x9488, 0x9489, 0x948a, 0x948f,
  0x9490, 0x9491, 0x9495, 0x9498, 0x949c, 0x949e, 0x949f, 0x94a0, 0x94a1,
  0x94a3, 0x94b1, 0x94b3, 0x94b4, 0x94b5, 0x94b9, 0x94c0, 0x94c1, 0x94c3,
  0x94c4, 0x94c5, 0x94c6, 0x94c7, 0x94c8, 0x94c9, 0x94cb, 0x94cc, 0x94cd,
  0x9500, 0x9501, 0x9504, 0x9505, 0x9506, 0x9507, 0x9508, 0x9509, 0x950f,
  0x9511, 0x9515, 0x9517, 0x9519, 0x9540, 0x9541, 0x9542, 0x954e, 0x954f,
  0x9552, 0x9553, 0x9555, 0x9557, 0x955f, 0x9580, 0x9581, 0x9583, 0x9586,
  0x9587, 0x9588, 0x9589, 0x958a, 0x958b, 0x958c, 0x958d, 0x958e, 0x958f,
  0x9590, 0x9591, 0x9593, 0x9595, 0x9596, 0x9597, 0x9598, 0x9599, 0x959b,
  0x95c0, 0x95c2, 0x95c4, 0x95c5, 0x95c6, 0x95c7, 0x95c9, 0x95cc, 0x95cd,
  0x95ce, 0x95cf, 0x9610, 0x9611, 0x9612, 0x9613, 0x9614, 0x9615, 0x9616,
  0x9640, 0x9641, 0x9642, 0x9643, 0x9644, 0x9645, 0x9647, 0x9648, 0x9649,
  0x964a, 0x964b, 0x964c, 0x964e, 0x964f, 0x9710, 0x9711, 0x9712, 0x9713,
  0x9714, 0x9715, 0x9802, 0x9803, 0x9804, 0x9805, 0x9806, 0x9807, 0x9808,
  0x9809, 0x980a, 0x9830, 0x983d, 0x9850, 0x9851, 0x9874, 0x9900, 0x9901,
  0x9903, 0x9904, 0x9905, 0x9906, 0x9907, 0x9908, 0x9909, 0x990a, 0x990b,
  0x990c, 0x990d, 0x990e, 0x990f, 0x9910, 0x9913, 0x9917, 0x9918, 0x9919,
  0x9990, 0x9991, 0x9992, 0x9993, 0x9994, 0x9995, 0x9996, 0x9997, 0x9998,
  0x9999, 0x999a, 0x999b, 0x999c, 0x999d, 0x99a0, 0x99a2, 0x99a4
};

static const guint legacy_intel_list[] = {
  0x102, 0x106, 0x116, 0x126, 0x152, 0x156, 0x166,
  0x402, 0x406, 0x416, 0x41e, 0xa06, 0xa16, 0xf31,
};

static gint
binary_search_compare (const guint * a, const guint * b)
{
  return *a - *b;
}

/* Certain AMD GPU drivers like R600, R700, Evergreen and Cayman and some second
 * generation Intel GPU drivers crash if we create a video device with a
 * resolution higher then 1920 x 1088. This function checks if the GPU is in
 * this list and if yes returns true. */
gboolean
gst_d3d11_decoder_util_is_legacy_device (GstD3D11Device * device)
{
  const guint amd_id[] = { 0x1002, 0x1022 };
  const guint intel_id = 0x8086;
  guint device_id = 0;
  guint vendor_id = 0;
  guint *match = NULL;

  g_return_val_if_fail (GST_IS_D3D11_DEVICE (device), FALSE);

  g_object_get (device, "device-id", &device_id, "vendor-id", &vendor_id, NULL);

  if (vendor_id == amd_id[0] || vendor_id == amd_id[1]) {
    match =
        (guint *) gst_util_array_binary_search ((gpointer) legacy_amd_list,
        G_N_ELEMENTS (legacy_amd_list), sizeof (guint),
        (GCompareDataFunc) binary_search_compare,
        GST_SEARCH_MODE_EXACT, &device_id, NULL);
  } else if (vendor_id == intel_id) {
    match =
        (guint *) gst_util_array_binary_search ((gpointer) legacy_intel_list,
        G_N_ELEMENTS (legacy_intel_list), sizeof (guint),
        (GCompareDataFunc) binary_search_compare,
        GST_SEARCH_MODE_EXACT, &device_id, NULL);
  }

  if (match) {
    GST_DEBUG_OBJECT (device, "it's legacy device");
    return TRUE;
  }

  return FALSE;
}

gboolean
gst_d3d11_decoder_supports_format (GstD3D11Decoder * decoder,
    const GUID * decoder_profile, DXGI_FORMAT format)
{
  GstD3D11DecoderPrivate *priv;
  HRESULT hr;
  BOOL can_support = FALSE;

  g_return_val_if_fail (GST_IS_D3D11_DECODER (decoder), FALSE);
  g_return_val_if_fail (decoder_profile != NULL, FALSE);
  g_return_val_if_fail (format != DXGI_FORMAT_UNKNOWN, FALSE);

  priv = decoder->priv;

  hr = ID3D11VideoDevice_CheckVideoDecoderFormat (priv->video_device,
      decoder_profile, format, &can_support);
  if (!gst_d3d11_result (hr, priv->device) || !can_support) {
    GST_DEBUG_OBJECT (decoder,
        "VideoDevice could not support dxgi format %d, hr: 0x%x",
        format, (guint) hr);

    return FALSE;
  }

  return TRUE;
}

/* Don't call this method with legacy device */
gboolean
gst_d3d11_decoder_supports_resolution (GstD3D11Decoder * decoder,
    const GUID * decoder_profile, DXGI_FORMAT format, guint width, guint height)
{
  D3D11_VIDEO_DECODER_DESC desc;
  GstD3D11DecoderPrivate *priv;
  HRESULT hr;
  UINT config_count;

  g_return_val_if_fail (GST_IS_D3D11_DECODER (decoder), FALSE);
  g_return_val_if_fail (decoder_profile != NULL, FALSE);
  g_return_val_if_fail (format != DXGI_FORMAT_UNKNOWN, FALSE);

  priv = decoder->priv;

  desc.SampleWidth = width;
  desc.SampleHeight = height;
  desc.OutputFormat = format;
  desc.Guid = *decoder_profile;

  hr = ID3D11VideoDevice_GetVideoDecoderConfigCount (priv->video_device,
      &desc, &config_count);
  if (!gst_d3d11_result (hr, priv->device) || config_count == 0) {
    GST_DEBUG_OBJECT (decoder, "Could not get decoder config count, hr: 0x%x",
        (guint) hr);
    return FALSE;
  }

  return TRUE;
}

/**
 * gst_d3d11_decoder_class_data_new:
 * @device: (transfer none): a #GstD3D11Device
 * @sink_caps: (transfer full): a #GstCaps
 * @src_caps: (transfer full): a #GstCaps
 *
 * Create new #GstD3D11DecoderClassData
 *
 * Returns: (transfer full): the new #GstD3D11DecoderClassData
 */
GstD3D11DecoderClassData *
gst_d3d11_decoder_class_data_new (GstD3D11Device * device,
    GstCaps * sink_caps, GstCaps * src_caps)
{
  GstD3D11DecoderClassData *ret;

  g_return_val_if_fail (GST_IS_D3D11_DEVICE (device), NULL);
  g_return_val_if_fail (sink_caps != NULL, NULL);
  g_return_val_if_fail (src_caps != NULL, NULL);

  ret = g_new0 (GstD3D11DecoderClassData, 1);

  /* class data will be leaked if the element never gets instantiated */
  GST_MINI_OBJECT_FLAG_SET (sink_caps, GST_MINI_OBJECT_FLAG_MAY_BE_LEAKED);
  GST_MINI_OBJECT_FLAG_SET (src_caps, GST_MINI_OBJECT_FLAG_MAY_BE_LEAKED);

  g_object_get (device, "adapter", &ret->adapter,
      "device-id", &ret->device_id, "vendor-id", &ret->vendor_id,
      "description", &ret->description, NULL);
  ret->sink_caps = sink_caps;
  ret->src_caps = src_caps;

  return ret;
}

void
gst_d3d11_decoder_class_data_free (GstD3D11DecoderClassData * data)
{
  if (!data)
    return;

  gst_clear_caps (&data->sink_caps);
  gst_clear_caps (&data->src_caps);
  g_free (data->description);
  g_free (data);
}
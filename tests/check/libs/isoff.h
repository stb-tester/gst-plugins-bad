#ifndef __DASH_ISOFF_H__
#define __DASH_ISOFF_H__

#include <glib.h>

static const guint8 moof1[] = {
  0x00, 0x00, 0x04, 0xdc, 0x6d, 0x6f, 0x6f, 0x66, 0x00, 0x00, 0x00, 0x10,
  0x6d, 0x66, 0x68, 0x64, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
  0x00, 0x00, 0x04, 0xc4, 0x74, 0x72, 0x61, 0x66, 0x00, 0x00, 0x00, 0x14,
  0x74, 0x66, 0x68, 0x64, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x01,
  0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x14, 0x74, 0x66, 0x64, 0x74,
  0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x04, 0x94, 0x74, 0x72, 0x75, 0x6e, 0x01, 0x00, 0x0e, 0x01,
  0x00, 0x00, 0x00, 0x60, 0x00, 0x00, 0x04, 0xe4, 0x00, 0x00, 0x00, 0xd1,
  0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x29,
  0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x00, 0x00, 0x05, 0xa5,
  0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0xff, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0xff, 0xff, 0xff, 0xf8, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0xff, 0xff, 0xff, 0xf8, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0xff, 0xff, 0xff, 0xf8, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0xff, 0xff, 0xff, 0xf8, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0xff, 0xff, 0xff, 0xf8, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0xff, 0xff, 0xff, 0xf8, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0xff, 0xff, 0xff, 0xf8, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0xff, 0xff, 0xff, 0xf8, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0xff, 0xff, 0xff, 0xf8, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0xff, 0xff, 0xff, 0xf8, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0xff, 0xff, 0xff, 0xf8, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0xff, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0xff, 0xff, 0xff, 0xf8, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0xff, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0xff, 0xff, 0xff, 0xf8, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0xff, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0xff, 0xff, 0xff, 0xf8, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0xff, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0xff, 0xff, 0xff, 0xf8, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0xff, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0xff, 0xff, 0xff, 0xf8, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0xff, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0xff, 0xff, 0xff, 0xf8, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0xff, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0xff, 0xff, 0xff, 0xf8, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0xff, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0xff, 0xff, 0xff, 0xf8, 0x00, 0x00, 0x09, 0x47,
  0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x00, 0x00, 0x07, 0xdd,
  0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0xff, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0xff, 0xff, 0xff, 0xf8, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0xff, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x0a, 0x70,
  0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x06, 0xb4,
  0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0xff, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0d, 0x9b,
  0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x8f,
  0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

/* Fragments taken from http://www.bok.net/dash/tears_of_steel/cleartext/stream.mpd
 *
 * Audio stream (aac)
 * Header (moov only) + first fragment (moof only) + second fragment (moof only)
 */

/* http://www.bok.net/dash/tears_of_steel/cleartext/audio/en/init.mp4 (except for ftyp box) */
static const guint8 init_mp4[] = {
  0x00, 0x00, 0x02, 0x50, 0x6d, 0x6f, 0x6f, 0x76, 0x00, 0x00, 0x00, 0x6c,
  0x6d, 0x76, 0x68, 0x64, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xe8, 0x00, 0x0b, 0x33, 0xd7,
  0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x01, 0xa4,
  0x74, 0x72, 0x61, 0x6b, 0x00, 0x00, 0x00, 0x5c, 0x74, 0x6b, 0x68, 0x64,
  0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0b, 0x33, 0xbc,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x01, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x01, 0x40, 0x6d, 0x64, 0x69, 0x61, 0x00, 0x00, 0x00, 0x20,
  0x6d, 0x64, 0x68, 0x64, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xac, 0x44, 0x00, 0x00, 0x00, 0x00,
  0x15, 0xc7, 0x00, 0x00, 0x00, 0x00, 0x00, 0x35, 0x68, 0x64, 0x6c, 0x72,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x73, 0x6f, 0x75, 0x6e,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x42, 0x65, 0x6e, 0x74, 0x6f, 0x34, 0x20, 0x53, 0x6f, 0x75, 0x6e, 0x64,
  0x20, 0x48, 0x61, 0x6e, 0x64, 0x6c, 0x65, 0x72, 0x00, 0x00, 0x00, 0x00,
  0xe3, 0x6d, 0x69, 0x6e, 0x66, 0x00, 0x00, 0x00, 0x10, 0x73, 0x6d, 0x68,
  0x64, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x24, 0x64, 0x69, 0x6e, 0x66, 0x00, 0x00, 0x00, 0x1c, 0x64, 0x72, 0x65,
  0x66, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
  0x0c, 0x75, 0x72, 0x6c, 0x20, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
  0xa7, 0x73, 0x74, 0x62, 0x6c, 0x00, 0x00, 0x00, 0x5b, 0x73, 0x74, 0x73,
  0x64, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
  0x4b, 0x6d, 0x70, 0x34, 0x61, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00,
  0x10, 0x00, 0x00, 0x00, 0x00, 0xac, 0x44, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x27, 0x65, 0x73, 0x64, 0x73, 0x00, 0x00, 0x00, 0x00, 0x03, 0x19, 0x00,
  0x00, 0x00, 0x04, 0x11, 0x40, 0x15, 0x00, 0x00, 0x00, 0x00, 0x01, 0xf4,
  0x01, 0x00, 0x01, 0xf4, 0x01, 0x05, 0x02, 0x12, 0x10, 0x06, 0x01, 0x02,
  0x00, 0x00, 0x00, 0x14, 0x73, 0x74, 0x73, 0x7a, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10,
  0x73, 0x74, 0x73, 0x63, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x10, 0x73, 0x74, 0x74, 0x73, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x73, 0x74, 0x63, 0x6f,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x38,
  0x6d, 0x76, 0x65, 0x78, 0x00, 0x00, 0x00, 0x10, 0x6d, 0x65, 0x68, 0x64,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x0b, 0x33, 0xd7, 0x00, 0x00, 0x00, 0x20,
  0x74, 0x72, 0x65, 0x78, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02,
  0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00
};

/* http://www.bok.net/dash/tears_of_steel/cleartext/audio/en/seg-1.m4f (except for mdat box) */
static const guint8 seg_1_m4f[] = {
  0x00, 0x00, 0x04, 0x60, 0x6d, 0x6f, 0x6f, 0x66, 0x00, 0x00, 0x00, 0x10,
  0x6d, 0x66, 0x68, 0x64, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02,
  0x00, 0x00, 0x04, 0x48, 0x74, 0x72, 0x61, 0x66, 0x00, 0x00, 0x00, 0x10,
  0x74, 0x66, 0x68, 0x64, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02,
  0x00, 0x00, 0x00, 0x14, 0x74, 0x66, 0x64, 0x74, 0x01, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x1c,
  0x74, 0x72, 0x75, 0x6e, 0x00, 0x00, 0x03, 0x01, 0x00, 0x00, 0x00, 0x81,
  0x00, 0x00, 0x04, 0x68, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x73,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x74, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x01, 0xdd, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x02, 0x12,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0xe9, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x01, 0xce, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0xb9,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0xa5, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x01, 0xa4, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x9a,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x92, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x01, 0x8e, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x7d,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x7d, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x01, 0x82, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x82,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x71, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x01, 0x72, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x6a,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x5a, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x01, 0x65, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x63,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x78, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x01, 0x50, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x55,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x66, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x01, 0x5e, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x6a,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x4d, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x01, 0x9f, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x82,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x6c, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x01, 0x58, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x82,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x66, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x01, 0x6d, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x94,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x56, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x01, 0x69, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x6e,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x69, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x01, 0x5e, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x86,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x5c, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x01, 0x6e, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x67,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x65, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x01, 0x68, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x5d,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x64, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x01, 0x6d, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x89,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x61, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x01, 0x81, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x7d,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x5c, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x01, 0x59, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x9e,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x74, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x01, 0x71, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x91,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x87, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x01, 0x4d, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x53,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0xa7, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x01, 0x57, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0xbd,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0xa9, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x01, 0xa6, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x9f,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x96, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x01, 0x85, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x8b,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x77, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x01, 0x64, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0xba,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0xb0, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x01, 0x87, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x81,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x53, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x01, 0x15, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x25,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x3c, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x01, 0x47, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x35,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x85, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x01, 0x67, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0xab,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x46, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x01, 0xa4, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x97,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x3c, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x01, 0x6a, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0xa3,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x5d, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x01, 0x83, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x46,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x48, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x01, 0x6f, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x58,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0xa9, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x01, 0x49, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x7b,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x93, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x01, 0x3a, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x8d,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x70, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x01, 0x85, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x7c,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x75, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x01, 0x56, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x57,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x70, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x01, 0xb4, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x67,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x60, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x01, 0x69, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x6e,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x5e, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x01, 0xa3, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x4b,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0xaa, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x01, 0x91, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x7e,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x46, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x01, 0x9b, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x6c,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x52, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x01, 0x59
};
static const guint seg_1_m4f_len = 1120;

static const guint seg_1_sample_sizes[] = {
  371, 372, 477, 530, 489, 462, 441, 421, 420, 410, 402, 398, 381, 381, 386,
  386, 369, 370, 362, 346, 357, 355, 376, 336, 341, 358, 350, 362, 333, 415,
  386, 364, 344, 386, 358, 365, 404, 342, 361, 366, 361, 350, 390, 348, 366,
  359, 357, 360, 349, 356, 365, 393, 353, 385, 381, 348, 345, 414, 372, 369,
  401, 391, 333, 339, 423, 343, 445, 425, 422, 415, 406, 389, 395, 375, 356,
  442, 432, 391, 385, 339, 277, 293, 316, 327, 309, 389, 359, 427, 326, 420,
  407, 316, 362, 419, 349, 387, 326, 328, 367, 344, 425, 329, 379, 403, 314,
  397, 368, 389, 380, 373, 342, 343, 368, 436, 359, 352, 361, 366, 350, 419,
  331, 426, 401, 382, 326, 411, 364, 338, 345
};

/* http://www.bok.net/dash/tears_of_steel/cleartext/audio/en/seg-2.m4f (except for mdat box) */
static const guint8 seg_2_m4f[] = {
  0x00, 0x00, 0x04, 0x60, 0x6d, 0x6f, 0x6f, 0x66, 0x00, 0x00, 0x00, 0x10,
  0x6d, 0x66, 0x68, 0x64, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04,
  0x00, 0x00, 0x04, 0x48, 0x74, 0x72, 0x61, 0x66, 0x00, 0x00, 0x00, 0x10,
  0x74, 0x66, 0x68, 0x64, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02,
  0x00, 0x00, 0x00, 0x14, 0x74, 0x66, 0x64, 0x74, 0x01, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x04, 0x00, 0x00, 0x00, 0x04, 0x1c,
  0x74, 0x72, 0x75, 0x6e, 0x00, 0x00, 0x03, 0x01, 0x00, 0x00, 0x00, 0x81,
  0x00, 0x00, 0x04, 0x68, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x45,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x65, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x01, 0x79, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x90,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x58, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x01, 0x6b, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x98,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x75, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x01, 0x82, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0xa8,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x47, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x01, 0x5f, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x54,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x6a, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x01, 0xaf, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x60,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x6a, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x01, 0x66, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x59,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x98, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x01, 0x77, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x72,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x62, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x01, 0x65, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x6c,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x64, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x01, 0xa0, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x7e,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x6a, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x01, 0x6e, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x70,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x5e, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x01, 0x77, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0xab,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x74, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x01, 0x7c, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x6c,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x61, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x01, 0x6a, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x64,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x62, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x01, 0x5f, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x63,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x6b, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x01, 0x6d, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x6b,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x67, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x01, 0x64, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x6f,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x6d, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x01, 0x77, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x71,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x6f, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x01, 0x6e, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x70,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x6c, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x01, 0x6c, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x82,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x77, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x01, 0x76, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x76,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x6c, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x01, 0xc8, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x64,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0xbc, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x01, 0xad, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0xa6,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0xa5, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x01, 0x9a, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x95,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x89, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x01, 0x75, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x8e,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x51, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x01, 0x3c, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x66,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x3b, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x01, 0x50, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x45,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x5e, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x01, 0x5d, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x65,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x6e, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x01, 0x60, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x8c,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x59, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x01, 0x51, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x6c,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x5f, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x01, 0xdd, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x6c,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x92, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x01, 0xbc, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x59,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x97, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x01, 0xa5, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0xa2,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x89, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x01, 0x91, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x60,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x7c, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x01, 0x35, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x48,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x58, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x01, 0x89, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x7b,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x87, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x01, 0xb1, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x8a,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x4d, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x01, 0x51, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x75,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x73, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x01, 0x95, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x89,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x4d, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x01, 0x48, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x79,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x8a, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x01, 0x49, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x78,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x94, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x01, 0xa2, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x86,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x4f, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x01, 0x4f, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x5d,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x60, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x01, 0x59
};
static const guint seg_2_m4f_len = 1120;

static const guint seg_2_sample_sizes[] = {
  325, 357, 377, 400, 344, 363, 408, 373, 386, 424, 327, 351, 340, 362, 431,
  352, 362, 358, 345, 408, 375, 370, 354, 357, 364, 356, 416, 382, 362, 366,
  368, 350, 375, 427, 372, 380, 364, 353, 362, 356, 354, 351, 355, 363, 365,
  363, 359, 356, 367, 365, 375, 369, 367, 366, 368, 364, 364, 386, 375, 374,
  374, 364, 456, 356, 444, 429, 422, 421, 410, 405, 393, 373, 398, 337, 316,
  358, 315, 336, 325, 350, 349, 357, 366, 352, 396, 345, 337, 364, 351, 477,
  364, 402, 444, 345, 407, 421, 418, 393, 401, 352, 380, 309, 328, 344, 393,
  379, 391, 433, 394, 333, 337, 373, 371, 405, 393, 333, 328, 377, 394, 329,
  376, 404, 418, 390, 335, 335, 349, 352, 345
};

/* in timescale */
static const GstClockTime seg_sample_duration = 1024;
static const guint32 seg_timescale = 44100;

/* Fragments taken from smooth-streaming live manifest
 * http://profficialsite.origin.mediaservices.windows.net/9cc5e871-68ec-42c2-9fc7-fda95521f17d/dayoneplayready.ism/manifest
 * (except for mdat box)
 */
static const guint8 Fragments_audio[] = {
  0x00, 0x00, 0x06, 0xa8, 0x6d, 0x6f, 0x6f, 0x66, 0x00, 0x00, 0x00, 0x10,
  0x6d, 0x66, 0x68, 0x64, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7c,
  0x00, 0x00, 0x06, 0x90, 0x74, 0x72, 0x61, 0x66, 0x00, 0x00, 0x00, 0x14,
  0x74, 0x66, 0x68, 0x64, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x01,
  0x00, 0x00, 0x80, 0x02, 0x00, 0x00, 0x02, 0xc4, 0x74, 0x72, 0x75, 0x6e,
  0x00, 0x00, 0x03, 0x01, 0x00, 0x00, 0x00, 0x56, 0x00, 0x00, 0x06, 0xb0,
  0x00, 0x03, 0x8b, 0x07, 0x00, 0x00, 0x01, 0x5c, 0x00, 0x03, 0x8b, 0x08,
  0x00, 0x00, 0x01, 0x4e, 0x00, 0x03, 0x8b, 0x07, 0x00, 0x00, 0x01, 0xa8,
  0x00, 0x03, 0x8b, 0x08, 0x00, 0x00, 0x01, 0x5a, 0x00, 0x03, 0x8b, 0x07,
  0x00, 0x00, 0x01, 0x57, 0x00, 0x03, 0x8b, 0x08, 0x00, 0x00, 0x01, 0x6b,
  0x00, 0x03, 0x8b, 0x07, 0x00, 0x00, 0x01, 0x91, 0x00, 0x03, 0x8b, 0x08,
  0x00, 0x00, 0x01, 0x6e, 0x00, 0x03, 0x8b, 0x07, 0x00, 0x00, 0x01, 0x6a,
  0x00, 0x03, 0x8b, 0x08, 0x00, 0x00, 0x01, 0x50, 0x00, 0x03, 0x8b, 0x08,
  0x00, 0x00, 0x01, 0x76, 0x00, 0x03, 0x8b, 0x07, 0x00, 0x00, 0x01, 0x70,
  0x00, 0x03, 0x8b, 0x08, 0x00, 0x00, 0x01, 0x5f, 0x00, 0x03, 0x8b, 0x07,
  0x00, 0x00, 0x01, 0x7f, 0x00, 0x03, 0x8b, 0x08, 0x00, 0x00, 0x01, 0x70,
  0x00, 0x03, 0x8b, 0x07, 0x00, 0x00, 0x01, 0x68, 0x00, 0x03, 0x8b, 0x08,
  0x00, 0x00, 0x01, 0x7c, 0x00, 0x03, 0x8b, 0x07, 0x00, 0x00, 0x01, 0x76,
  0x00, 0x03, 0x8b, 0x08, 0x00, 0x00, 0x01, 0x56, 0x00, 0x03, 0x8b, 0x08,
  0x00, 0x00, 0x01, 0x65, 0x00, 0x03, 0x8b, 0x07, 0x00, 0x00, 0x01, 0x85,
  0x00, 0x03, 0x8b, 0x08, 0x00, 0x00, 0x01, 0x5c, 0x00, 0x03, 0x8b, 0x07,
  0x00, 0x00, 0x01, 0x69, 0x00, 0x03, 0x8b, 0x08, 0x00, 0x00, 0x01, 0x75,
  0x00, 0x03, 0x8b, 0x07, 0x00, 0x00, 0x01, 0x38, 0x00, 0x03, 0x8b, 0x08,
  0x00, 0x00, 0x01, 0xa8, 0x00, 0x03, 0x8b, 0x07, 0x00, 0x00, 0x01, 0x6a,
  0x00, 0x03, 0x8b, 0x08, 0x00, 0x00, 0x01, 0x7a, 0x00, 0x03, 0x8b, 0x08,
  0x00, 0x00, 0x01, 0x69, 0x00, 0x03, 0x8b, 0x07, 0x00, 0x00, 0x01, 0x6e,
  0x00, 0x03, 0x8b, 0x07, 0x00, 0x00, 0x01, 0x5c, 0x00, 0x03, 0x8b, 0x08,
  0x00, 0x00, 0x01, 0x82, 0x00, 0x03, 0x8b, 0x08, 0x00, 0x00, 0x01, 0x6e,
  0x00, 0x03, 0x8b, 0x07, 0x00, 0x00, 0x01, 0x6b, 0x00, 0x03, 0x8b, 0x08,
  0x00, 0x00, 0x01, 0x5f, 0x00, 0x03, 0x8b, 0x07, 0x00, 0x00, 0x01, 0x78,
  0x00, 0x03, 0x8b, 0x08, 0x00, 0x00, 0x01, 0x5b, 0x00, 0x03, 0x8b, 0x08,
  0x00, 0x00, 0x01, 0x6c, 0x00, 0x03, 0x8b, 0x07, 0x00, 0x00, 0x01, 0x7d,
  0x00, 0x03, 0x8b, 0x07, 0x00, 0x00, 0x01, 0x77, 0x00, 0x03, 0x8b, 0x08,
  0x00, 0x00, 0x01, 0x60, 0x00, 0x03, 0x8b, 0x08, 0x00, 0x00, 0x01, 0x74,
  0x00, 0x03, 0x8b, 0x07, 0x00, 0x00, 0x01, 0x61, 0x00, 0x03, 0x8b, 0x08,
  0x00, 0x00, 0x01, 0x5d, 0x00, 0x03, 0x8b, 0x07, 0x00, 0x00, 0x01, 0x5c,
  0x00, 0x03, 0x8b, 0x08, 0x00, 0x00, 0x01, 0x7e, 0x00, 0x03, 0x8b, 0x07,
  0x00, 0x00, 0x01, 0x7a, 0x00, 0x03, 0x8b, 0x08, 0x00, 0x00, 0x01, 0x67,
  0x00, 0x03, 0x8b, 0x07, 0x00, 0x00, 0x01, 0x73, 0x00, 0x03, 0x8b, 0x08,
  0x00, 0x00, 0x01, 0x72, 0x00, 0x03, 0x8b, 0x08, 0x00, 0x00, 0x01, 0x63,
  0x00, 0x03, 0x8b, 0x07, 0x00, 0x00, 0x01, 0x6c, 0x00, 0x03, 0x8b, 0x07,
  0x00, 0x00, 0x01, 0x6e, 0x00, 0x03, 0x8b, 0x08, 0x00, 0x00, 0x01, 0x5e,
  0x00, 0x03, 0x8b, 0x08, 0x00, 0x00, 0x01, 0x6a, 0x00, 0x03, 0x8b, 0x07,
  0x00, 0x00, 0x01, 0x86, 0x00, 0x03, 0x8b, 0x08, 0x00, 0x00, 0x01, 0x6d,
  0x00, 0x03, 0x8b, 0x07, 0x00, 0x00, 0x01, 0x5b, 0x00, 0x03, 0x8b, 0x08,
  0x00, 0x00, 0x01, 0x81, 0x00, 0x03, 0x8b, 0x08, 0x00, 0x00, 0x01, 0x72,
  0x00, 0x03, 0x8b, 0x07, 0x00, 0x00, 0x01, 0x60, 0x00, 0x03, 0x8b, 0x07,
  0x00, 0x00, 0x01, 0x71, 0x00, 0x03, 0x8b, 0x08, 0x00, 0x00, 0x01, 0x6c,
  0x00, 0x03, 0x8b, 0x08, 0x00, 0x00, 0x01, 0x52, 0x00, 0x03, 0x8b, 0x07,
  0x00, 0x00, 0x01, 0x8d, 0x00, 0x03, 0x8b, 0x08, 0x00, 0x00, 0x01, 0x59,
  0x00, 0x03, 0x8b, 0x07, 0x00, 0x00, 0x01, 0x6c, 0x00, 0x03, 0x8b, 0x08,
  0x00, 0x00, 0x01, 0x40, 0x00, 0x03, 0x8b, 0x07, 0x00, 0x00, 0x01, 0x90,
  0x00, 0x03, 0x8b, 0x08, 0x00, 0x00, 0x01, 0x73, 0x00, 0x03, 0x8b, 0x07,
  0x00, 0x00, 0x01, 0x6f, 0x00, 0x03, 0x8b, 0x08, 0x00, 0x00, 0x01, 0x53,
  0x00, 0x03, 0x8b, 0x08, 0x00, 0x00, 0x01, 0x90, 0x00, 0x03, 0x8b, 0x07,
  0x00, 0x00, 0x01, 0x66, 0x00, 0x03, 0x8b, 0x07, 0x00, 0x00, 0x01, 0x71,
  0x00, 0x03, 0x8b, 0x08, 0x00, 0x00, 0x01, 0x71, 0x00, 0x03, 0x8b, 0x08,
  0x00, 0x00, 0x01, 0x65, 0x00, 0x03, 0x8b, 0x07, 0x00, 0x00, 0x01, 0x66,
  0x00, 0x03, 0x8b, 0x08, 0x00, 0x00, 0x01, 0x77, 0x00, 0x03, 0x8b, 0x07,
  0x00, 0x00, 0x01, 0x84, 0x00, 0x03, 0x8b, 0x08, 0x00, 0x00, 0x01, 0x5c,
  0x00, 0x03, 0x8b, 0x08, 0x00, 0x00, 0x01, 0x6f, 0x00, 0x03, 0x8b, 0x07,
  0x00, 0x00, 0x01, 0x70, 0x00, 0x03, 0x8b, 0x07, 0x00, 0x00, 0x01, 0x6e,
  0x00, 0x03, 0x8b, 0x08, 0x00, 0x00, 0x01, 0x4b, 0x00, 0x03, 0x8b, 0x08,
  0x00, 0x00, 0x01, 0x8a, 0x00, 0x00, 0x00, 0x62, 0x73, 0x64, 0x74, 0x70,
  0x00, 0x00, 0x00, 0x00, 0x28, 0x28, 0x28, 0x28, 0x28, 0x28, 0x28, 0x28,
  0x28, 0x28, 0x28, 0x28, 0x28, 0x28, 0x28, 0x28, 0x28, 0x28, 0x28, 0x28,
  0x28, 0x28, 0x28, 0x28, 0x28, 0x28, 0x28, 0x28, 0x28, 0x28, 0x28, 0x28,
  0x28, 0x28, 0x28, 0x28, 0x28, 0x28, 0x28, 0x28, 0x28, 0x28, 0x28, 0x28,
  0x28, 0x28, 0x28, 0x28, 0x28, 0x28, 0x28, 0x28, 0x28, 0x28, 0x28, 0x28,
  0x28, 0x28, 0x28, 0x28, 0x28, 0x28, 0x28, 0x28, 0x28, 0x28, 0x28, 0x28,
  0x28, 0x28, 0x28, 0x28, 0x28, 0x28, 0x28, 0x28, 0x28, 0x28, 0x28, 0x28,
  0x28, 0x28, 0x28, 0x28, 0x28, 0x28, 0x00, 0x00, 0x00, 0x2c, 0x75, 0x75,
  0x69, 0x64, 0x6d, 0x1d, 0x9b, 0x05, 0x42, 0xd5, 0x44, 0xe6, 0x80, 0xe2,
  0x14, 0x1d, 0xaf, 0xf7, 0x57, 0xb2, 0x01, 0x00, 0x00, 0x00, 0x00, 0x04,
  0x38, 0x93, 0xfd, 0xb6, 0x13, 0x32, 0x00, 0x00, 0x00, 0x00, 0x01, 0x30,
  0xb4, 0x89, 0x00, 0x00, 0x00, 0x3d, 0x75, 0x75, 0x69, 0x64, 0xd4, 0x80,
  0x7e, 0xf2, 0xca, 0x39, 0x46, 0x95, 0x8e, 0x54, 0x26, 0xcb, 0x9e, 0x46,
  0xa7, 0x9f, 0x01, 0x00, 0x00, 0x00, 0x02, 0x00, 0x04, 0x38, 0x93, 0xfe,
  0xe6, 0xc7, 0xbb, 0x00, 0x00, 0x00, 0x00, 0x01, 0x30, 0xb4, 0x88, 0x00,
  0x04, 0x38, 0x94, 0x00, 0x17, 0x7c, 0x43, 0x00, 0x00, 0x00, 0x00, 0x01,
  0x30, 0xb4, 0x8a, 0x00, 0x00, 0x02, 0xc0, 0x73, 0x65, 0x6e, 0x63, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x56, 0x3c, 0x21, 0x71, 0x12, 0x17,
  0x53, 0x51, 0x87, 0xcb, 0xef, 0x57, 0xe7, 0x1d, 0x07, 0xea, 0x59, 0x4c,
  0x40, 0xad, 0xbf, 0xa6, 0x52, 0xb6, 0x9d, 0x3a, 0x57, 0x97, 0x11, 0x51,
  0x88, 0x4a, 0x07, 0xda, 0x88, 0x5f, 0xa6, 0xd2, 0x50, 0x67, 0x28, 0x55,
  0xbb, 0x96, 0xe4, 0xb2, 0x79, 0x7d, 0x93, 0xa6, 0x19, 0xd1, 0xd8, 0x8f,
  0x66, 0xa6, 0xa2, 0x4c, 0xc7, 0x88, 0x4c, 0xac, 0x35, 0x8a, 0x43, 0xb3,
  0x78, 0x81, 0x7e, 0x3a, 0x89, 0x59, 0xdd, 0x1e, 0x86, 0xc6, 0xa9, 0x69,
  0x36, 0x6e, 0x58, 0x88, 0x84, 0xdc, 0xc1, 0x4a, 0x29, 0xc7, 0x13, 0x24,
  0x4a, 0xd8, 0x22, 0x34, 0xd1, 0xdc, 0xce, 0xba, 0x2d, 0x56, 0xf1, 0x93,
  0x23, 0x74, 0xfa, 0x3b, 0xa3, 0xd1, 0x49, 0xa2, 0x85, 0xbf, 0x5d, 0x0f,
  0x3b, 0x4d, 0x4c, 0x1f, 0x7d, 0xba, 0x4f, 0x38, 0x8c, 0xf9, 0x39, 0xd7,
  0xac, 0x02, 0x15, 0x36, 0x66, 0x1b, 0x1d, 0x9d, 0x3f, 0x6c, 0x51, 0xf5,
  0x89, 0xbc, 0xd1, 0xda, 0xb2, 0xf7, 0xbf, 0xc3, 0xf3, 0x63, 0x0e, 0x86,
  0xb8, 0xbf, 0x8a, 0xf6, 0x2c, 0xd6, 0x42, 0xbd, 0xcd, 0x10, 0x6e, 0xea,
  0x79, 0xc7, 0x44, 0xb3, 0xe5, 0xae, 0x49, 0x04, 0xcc, 0x5d, 0x93, 0x20,
  0x9c, 0xb6, 0xc5, 0x22, 0xf1, 0x94, 0x1b, 0x32, 0x56, 0xba, 0x0c, 0x31,
  0x3f, 0xac, 0x82, 0x72, 0x20, 0x8f, 0xc2, 0x55, 0x62, 0xbf, 0xc6, 0x24,
  0xc3, 0xd6, 0x3a, 0xd4, 0xe3, 0x77, 0x1a, 0xfd, 0xa8, 0x42, 0xe7, 0x80,
  0xc2, 0x42, 0x5e, 0x10, 0xe0, 0xc1, 0x61, 0x6a, 0x61, 0xef, 0x6d, 0x82,
  0x69, 0x38, 0x0b, 0x2d, 0x81, 0xef, 0xf0, 0xde, 0xe7, 0xdb, 0xea, 0x32,
  0x61, 0xbe, 0x13, 0xe4, 0xd9, 0x1a, 0x41, 0x6b, 0xed, 0xc1, 0xaf, 0xe2,
  0xfd, 0x62, 0x8e, 0x66, 0xa9, 0x4f, 0xfb, 0x73, 0x49, 0x8f, 0x02, 0x6e,
  0x0f, 0xb3, 0x40, 0xbc, 0x89, 0x2d, 0xa1, 0x5b, 0xb8, 0xba, 0xc8, 0xcb,
  0x6d, 0xfe, 0x4f, 0x98, 0xcb, 0x7d, 0x1c, 0x1a, 0xd6, 0x83, 0xe7, 0x3b,
  0xd1, 0x8e, 0xf0, 0x7e, 0xe1, 0x54, 0x05, 0xb6, 0x74, 0x24, 0x60, 0x75,
  0xff, 0x9f, 0x71, 0xa0, 0xdb, 0xb4, 0x9e, 0x3d, 0x15, 0x70, 0x6e, 0xab,
  0xc7, 0xf1, 0xcf, 0x52, 0x65, 0xec, 0x83, 0x2f, 0xeb, 0x63, 0x09, 0xa3,
  0x1e, 0xfb, 0x1d, 0x6e, 0xf9, 0x02, 0x96, 0x4d, 0x23, 0x35, 0x95, 0x7f,
  0xeb, 0xc5, 0x68, 0x4f, 0x71, 0xc8, 0x52, 0xe4, 0x82, 0x51, 0x20, 0xdc,
  0xb6, 0xc2, 0x06, 0xdc, 0x8d, 0xae, 0x81, 0x5d, 0x7a, 0xaf, 0x36, 0xd0,
  0x02, 0x21, 0x42, 0x45, 0x3c, 0x8d, 0xca, 0x7a, 0x2e, 0x12, 0x00, 0x10,
  0xb5, 0x20, 0x3c, 0x14, 0x5d, 0x4c, 0x71, 0xf2, 0x32, 0x08, 0xd9, 0xa0,
  0x6d, 0x5b, 0x17, 0x12, 0x54, 0xdd, 0xaf, 0xfb, 0x8e, 0x37, 0x93, 0xbb,
  0x4a, 0x4a, 0xcc, 0x9e, 0xb1, 0xbd, 0xf7, 0x24, 0x70, 0x27, 0xfa, 0xe3,
  0x63, 0x2a, 0xd6, 0xb3, 0x3f, 0x81, 0x5a, 0xfa, 0x6f, 0x5c, 0xdd, 0xf5,
  0x66, 0x9b, 0x3e, 0x56, 0xb0, 0x78, 0x8f, 0xa2, 0x41, 0x1c, 0x65, 0xd5,
  0x4a, 0xf1, 0x18, 0x8b, 0x59, 0xb9, 0x5f, 0x69, 0xde, 0xd4, 0x6d, 0x31,
  0x8c, 0xe2, 0x1b, 0x48, 0xa5, 0x3b, 0x22, 0xcd, 0x70, 0xf6, 0x68, 0x5e,
  0x59, 0x7f, 0xa9, 0x59, 0x68, 0x1c, 0x87, 0x80, 0x53, 0x5a, 0x16, 0xf4,
  0x19, 0x0a, 0xc7, 0x5e, 0x94, 0x3c, 0x8a, 0x01, 0xb2, 0x42, 0x94, 0xfd,
  0x97, 0x02, 0x65, 0x0b, 0x74, 0xa9, 0x2a, 0x47, 0xe2, 0xd9, 0xc3, 0x15,
  0xbc, 0x60, 0xb7, 0xc6, 0x0a, 0xd9, 0xdf, 0x7d, 0x8f, 0x77, 0x97, 0xce,
  0x16, 0xfc, 0x0c, 0x1e, 0xd9, 0x53, 0xd0, 0x09, 0x1f, 0xb7, 0x27, 0x0d,
  0x28, 0xfd, 0x69, 0x4f, 0x20, 0xce, 0xfa, 0x24, 0x4a, 0xd8, 0xce, 0x5e,
  0x87, 0x87, 0xa8, 0x32, 0x51, 0x28, 0xa1, 0x58, 0x61, 0xa4, 0x55, 0x2f,
  0x84, 0xe3, 0x65, 0x8d, 0xd3, 0x0e, 0x23, 0xfb, 0x49, 0xb0, 0x63, 0xde,
  0x1d, 0x68, 0x32, 0x08, 0x14, 0xd7, 0xc2, 0x15, 0x0f, 0x18, 0x54, 0x34,
  0xf3, 0xd7, 0xe2, 0x71, 0x06, 0xed, 0x7d, 0xfb, 0x7a, 0x68, 0x4b, 0x90,
  0x6b, 0x55, 0x94, 0x60, 0x60, 0x03, 0xb6, 0xac, 0xbe, 0xa0, 0xa6, 0x13,
  0xfe, 0x2d, 0x26, 0x38, 0xdb, 0x65, 0xce, 0x49, 0x7c, 0x83, 0x2b, 0xe2,
  0xab, 0x86, 0xa7, 0x54, 0xc0, 0x13, 0x27, 0x27, 0x04, 0x2e, 0xa4, 0x08,
  0xc6, 0xc4, 0xa9, 0x8c, 0xda, 0xdd, 0x59, 0xbf, 0xe9, 0x92, 0xac, 0x93,
  0x99, 0x76, 0x9a, 0x7b, 0x38, 0x58, 0xb0, 0x2f, 0x1b, 0x63, 0x72, 0x12,
  0x8b, 0x23, 0x4e, 0x81, 0x12, 0x8b, 0xec, 0x5f, 0x7e, 0x62, 0x37, 0x19,
  0x59, 0x17, 0xab, 0x24, 0x5e, 0x15, 0xa8, 0x1f, 0x47, 0x26, 0xe3, 0x64,
  0xdf, 0xc6, 0x83, 0xc5, 0x83, 0x69, 0xe5, 0x2f, 0x10, 0xb2, 0x43, 0x6e,
  0xe9, 0x99, 0xcd, 0xad, 0x43, 0x06, 0x35, 0x80, 0x71, 0xa0, 0x4c, 0x9f,
  0xa0, 0x17, 0xa3, 0xb1, 0xe2, 0x22, 0xbb, 0x32, 0x60, 0xb0, 0xcb, 0x00,
  0x00, 0x00, 0x11, 0x73, 0x61, 0x69, 0x7a, 0x00, 0x00, 0x00, 0x00, 0x08,
  0x00, 0x00, 0x00, 0x56, 0x00, 0x00, 0x00, 0x14, 0x73, 0x61, 0x69, 0x6f,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x03, 0xd3
};

static const guint Fragments_audio_len = 1704;

#endif
/*
 * BRLTTY - A background process providing access to the console screen (when in
 *          text mode) for a blind person using a refreshable braille display.
 *
 * Copyright (C) 1995-2017 by The BRLTTY Developers.
 *
 * BRLTTY comes with ABSOLUTELY NO WARRANTY.
 *
 * This is free software, placed under the terms of the
 * GNU Lesser General Public License, as published by the Free Software
 * Foundation; either version 2.1 of the License, or (at your option) any
 * later version. Please see the file LICENSE-LGPL for details.
 *
 * Web Page: http://brltty.com/
 *
 * This software is maintained by Dave Mielke <dave@mielke.cc>.
 */

#ifndef BRLTTY_INCLUDED_PROFILE_TYPES
#define BRLTTY_INCLUDED_PROFILE_TYPES

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

typedef struct {
  const wchar_t *name;
  char **defaultValue;
  int (*change) (const char *value);
} ProfileProperty;

typedef struct {
  const char *category;
  const char *extension;

  int (*begin) (void);
  int (*end) (void);

  struct {
    const ProfileProperty *array;
    unsigned int count;
  } properties;
} ProfileDescriptor;

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* BRLTTY_INCLUDED_PROFILE_TYPES */

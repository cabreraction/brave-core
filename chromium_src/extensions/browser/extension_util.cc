/* Copyright (c) 2020 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

// Disable non-component extensions for tor OTR profile
#define BRAVE_IS_INCOGNITO_ENABLED                             \
  if (context->IsTor() &&                                      \
      !Manifest::IsComponentLocation(extension->location())) { \
    return false;                                              \
  }
#include "../../../../extensions/browser/extension_util.cc"
#undef BRAVE_IS_INCOGNITO_ENABLED
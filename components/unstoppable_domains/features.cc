/* Copyright (c) 2021 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "brave/components/unstoppable_domains/features.h"

#include "base/feature_list.h"

namespace unstoppable_domains {
namespace features {

const base::Feature kUnstoppableDomains{"UnstoppableDomains",
                                        base::FEATURE_DISABLED_BY_DEFAULT};

}  // namespace features
}  // namespace unstoppable_domains
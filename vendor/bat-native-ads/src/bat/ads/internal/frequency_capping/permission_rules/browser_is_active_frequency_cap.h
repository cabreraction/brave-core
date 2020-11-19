/* Copyright (c) 2020 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef BAT_ADS_INTERNAL_FREQUENCY_CAPPING_PERMISSION_RULES_BROWSER_IS_ACTIVE_FREQUENCY_CAP_H_  // NOLINT
#define BAT_ADS_INTERNAL_FREQUENCY_CAPPING_PERMISSION_RULES_BROWSER_IS_ACTIVE_FREQUENCY_CAP_H_  // NOLINT

#include <string>

#include "bat/ads/internal/frequency_capping/permission_rules/permission_rule.h"

namespace ads {

class BrowserIsActiveFrequencyCap : public PermissionRule {
 public:
  BrowserIsActiveFrequencyCap();

  ~BrowserIsActiveFrequencyCap() override;

  BrowserIsActiveFrequencyCap(const BrowserIsActiveFrequencyCap&) = delete;
  BrowserIsActiveFrequencyCap& operator=(
      const BrowserIsActiveFrequencyCap&) = delete;

  bool ShouldAllow() override;

  std::string get_last_message() const override;

 private:
  std::string last_message_;

  bool DoesRespectCap();
};

}  // namespace ads

#endif  // BAT_ADS_INTERNAL_FREQUENCY_CAPPING_PERMISSION_RULES_BROWSER_IS_ACTIVE_FREQUENCY_CAP_H_  // NOLINT
// Copyright 2020 The Brave Authors. All rights reserved.
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this file,
// you can obtain one at http://mozilla.org/MPL/2.0/.

function setupEvents() {
  $('body').classList.add('unstoppable_domains');
  $('icon').classList.add('icon');

  $('primary-button').addEventListener('click', function() {
    sendCommand(SecurityInterstitialCommandId.CMD_PROCEED);
  });

  $('main-content').classList.remove(HIDDEN_CLASS);

  $('dont-proceed-button').addEventListener('click', function(event) {
    sendCommand(SecurityInterstitialCommandId.CMD_DONT_PROCEED);
  });
}

document.addEventListener('DOMContentLoaded', setupEvents);
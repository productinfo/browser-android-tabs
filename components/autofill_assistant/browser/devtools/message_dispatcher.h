// Copyright 2018 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Copied and modified from
// https://chromium.googlesource.com/chromium/src/+/a3f9d4fac81fc86065d867ab08fa4912ddf662c7/headless/public/internal/message_dispatcher.h
// Modifications include namespace and path.

#ifndef COMPONENTS_AUTOFILL_ASSISTANT_BROWSER_DEVTOOLS_MESSAGE_DISPATCHER_H_
#define COMPONENTS_AUTOFILL_ASSISTANT_BROWSER_DEVTOOLS_MESSAGE_DISPATCHER_H_

#include <memory>

#include "base/callback_forward.h"

namespace base {
class Value;
}

namespace autofill_assistant {

// An internal interface for sending DevTools messages from the domain agents.
class MessageDispatcher {
 public:
  virtual void SendMessage(
      const char* method,
      std::unique_ptr<base::Value> params,
      base::OnceCallback<void(const base::Value&)> callback) = 0;
  virtual void SendMessage(const char* method,
                           std::unique_ptr<base::Value> params,
                           base::OnceClosure callback) = 0;

  virtual void RegisterEventHandler(
      const char* method,
      base::RepeatingCallback<void(const base::Value&)> callback) = 0;

 protected:
  virtual ~MessageDispatcher() {}
};

}  // namespace autofill_assistant

#endif  // COMPONENTS_AUTOFILL_ASSISTANT_BROWSER_DEVTOOLS_MESSAGE_DISPATCHER_H_

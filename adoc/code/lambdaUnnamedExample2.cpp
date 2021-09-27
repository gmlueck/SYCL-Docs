// Copyright (c) 2011-2021 The Khronos Group, Inc.
// SPDX-License-Identifier: Apache-2.0

#include <sycl/sycl.hpp>
using namespace sycl; // (optional) avoids need for "sycl::" before SYCL names

// This usage of __SYCL_DEVICE_ONLY__ produces undefined behavior because
// the name of the function (i.e. scope) containing the lambda is named
// differently depending on whether the macro is defined.

#if __SYCL_DEVICE_ONLY__
# define MACRO_THAT_NAMES_MY_FUNC(X) Device##X
#else
# define MACRO_THAT_NAMES_MY_FUNC(X) X
#endif

void MACRO_THAT_NAMES_MY_FUNC(foo)() {
  queue myQueue;

  myQueue.submit([&](handler& cgh) {
    cgh.single_task(([=] {/* ... */}));
  });

  myQueue.wait();
}

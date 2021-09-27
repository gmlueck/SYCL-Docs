// Copyright (c) 2011-2021 The Khronos Group, Inc.
// SPDX-License-Identifier: Apache-2.0

#include <sycl/sycl.hpp>
using namespace sycl; // (optional) avoids need for "sycl::" before SYCL names

// This usage of __SYCL_DEVICE_ONLY__ produces undefined behavior because
// the translation unit contains an unnamed kernel lambda and another lambda
// is conditionally declared depending on whether that macro is defined.

#ifdef __SYCL_DEVICE_ONLY__
# define LOG(X)
#else
# define LOG(X) log_func([](){}, X);  // This statement declares a lambda
#endif

int main() {
  queue myQueue;

  LOG("BAR");
  myQueue.submit([&](handler& cgh) {
    cgh.single_task(([=] {/* ... */}));
  });

  myQueue.wait();
}

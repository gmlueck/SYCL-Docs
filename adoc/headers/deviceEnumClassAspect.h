// Copyright (c) 2011-2022 The Khronos Group, Inc.
// SPDX-License-Identifier: MIT

namespace sycl {

enum class aspect : /* unspecified */ {
  cpu,
  gpu,
  accelerator,
  custom,
  emulated,
  host_debuggable,
  fp16,
  fp64,
  atomic64,
  image,
  online_compiler,
  online_linker,
  queue_profiling,
  usm_device_allocations,
  usm_host_allocations,
  usm_atomic_host_allocations,
  usm_concurrent_host_allocations,
  usm_shared_allocations,
  usm_atomic_shared_allocations,
  usm_cross_device_shared_allocations,
  usm_concurrent_shared_allocations,
  usm_system_allocations
};

} // namespace sycl

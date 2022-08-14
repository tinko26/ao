---
author: "Stefan Wagner"
date: 2022-08-13
description: "The ao_alloc.h module of the ao real-time operating system."
draft: true
permalink: /modules/alloc/
title: "ao_alloc.h"
---

# ao_alloc.h

This module encapsulates an allocator that supports dynamic memory management.

- dynamic memory management
- reference counting
- allocate, release, retain
- actual implementation in a submodule, that must be chosen via configuration
- allocator functions can be called from both task and interrupt context.
- consequently, the allocator does not track, which block is allocated to which task. the application must take care thereof, in order to avoid memory leaks.

- the allocator is a dynamic memory management option, that both the kernel and the application can. However, neither is committed to using the allocator.

- wiki: "provide ways to dynamically allocate portions of memory to programs at their request, and free it for reuse when no longer needed"

## Configuration

- AO_ALLOC

| Module | |
|--------|-|
| [`ao_alloc_0.h`](alloc-0.md) | Stub |
| [`ao_alloc_1.h`](alloc-1.md) | Implements a fixed-size blocks allocator. |
| [`ao_alloc_2.h`](alloc-2.md) | Implements a constant-time dynamic storage allocator based on the two-level segregated fit (TLSF) algorithm proposed by Masmano et al. |

- AO_ACQUIRED
- AO_RELEASED
- AO_RETAINED

## Types

- ao_acquired_t
- ao_released_t
- ao_retained_t

## Functions

- ao_acquire()
- ao_release()
- ao_retain()

- ao_acquired()
- ao_released()
- ao_retained()

- ao_new()
- ao_delete()


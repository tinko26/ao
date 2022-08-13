---
author: "Stefan Wagner"
date: 2022-08-13
description: ""
draft: true
permalink: /kernel/alloc-2/
title: "Allocator 2"
---

# Allocator 2

The `ao_alloc_2.h` module implements a constant-time dynamic storage allocator based on the two-level segregated fit (TLSF) algorithm proposed by Masmano et al.

## Constants

The maximum and minimum segregation value.

```c
#define AO_ALLOC_SEGREGATION_MAX
#define AO_ALLOC_SEGREGATION_MIN
```

## Configuration

| Option | |
|--------|-|
| `AO_ALLOC_ALLOCATED` | Indicates, whether to keep track of the current number of allocated bytes. |
| `AO_ALLOC_ALLOCATED_MAX` | Indicates, whether to keep track of the maximum number of allocated bytes. |
| `AO_ALLOC_FREE` | Indicates, whether to keep track of the current number of free bytes. |
| `AO_ALLOC_FREE_MIN` | Indicates, whether to keep track of the minimum number of free bytes. |
| `AO_ALLOC_SEGREGATION` | The base-2 logarithm of the number of secondary levels. |
| `AO_ALLOC_SIZE` | The total size of the heap, in bytes. |

## Variables

The allocator provides the following global variables for diagnostic purposes. Each one is present only if the respective configuration option is enabled.

| Variable | |
|----------|-|
| `ao_alloc_allocated` | The current number of allocated bytes. |
| `ao_alloc_allocated_max` | The maximum number of allocated bytes. |
| `ao_alloc_free` | The current number of available bytes. |
| `ao_alloc_free_min` | The minimum number of available bytes. |

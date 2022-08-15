---
author: "Stefan Wagner"
date: 2022-08-15
description: "The ao_alloc_2.h module of the ao real-time operating system."
draft: true
permalink: /modules/alloc-2/
title: "ao_alloc_2.h"
---

# ao_alloc_2.h

This module implements a constant-time dynamic storage allocator based on the two-level segregated fit (TLSF) algorithm proposed by Masmano et al.

...

- allocation
- deallocation
- constant time

...

## Configuration

### Allocated

The allocator can be configured to keep track of the current and maximum numbers of allocated bytes. By default, these options are disabled.

```c
#define AO_ALLOC_ALLOCATED
```

```c
#define AO_ALLOC_ALLOCATED_MAX
```

### Free

Accordingly, the allocator can be configured to keep track of the current and minimum numbers of free bytes. By default, these options are disabled, too.

```c
#define AO_ALLOC_FREE
```

```c
#define AO_ALLOC_FREE_MIN
```

### Segregation

The segregation must be configured. Thereby, the chosen value must be in the range determined by the minimum and maximum segregation [constants](#constants). The default value is `3`.

```c
#define AO_ALLOC_SEGREGATION
```

The segregation has an influence on the performance of the allocator with respect to fragmentation. That is, a high segregation potentially leads to high external fragmentation, but low internal fragmentation. On the other hand, a low segregation potentially leads to low external fragmentation, but high internal fragmentation.

### Size

Finally, the size of the heap must be configured. The default value is `8192` bytes.

```c
#define AO_ALLOC_SIZE
```

## Constants

The maximum and minimum segregation.

```c
#define AO_ALLOC_SEGREGATION_MAX
```

```c
#define AO_ALLOC_SEGREGATION_MIN
```

## Variables

The module exposes the following global variables.

| Variable | |
|----------|-|
| `ao_alloc_allocated` | The current number of allocated bytes across all pools. This variable is absent, if both the `AO_ALLOC_ALLOCATED` and `AO_ALLOC_ALLOCATED_MAX` configuration options are disabled. |
| `ao_alloc_allocated_max` | The maximum number of allocated bytes across all pools. This variable is absent, if the `AO_ALLOC_ALLOCATED_MAX` configuration option is disabled. |
| `ao_alloc_free` | The current number of free bytes across all pools. This variable is absent, if both the `AO_ALLOC_FREE` and `AO_ALLOC_FREE_MIN` configuration options are disabled. |
| `ao_alloc_free_min` | The minimum number of free bytes across all pools. This variable is absent, if the `AO_ALLOC_FREE_MIN` configuration option is disabled. |

## External Links

[https://doi.org/10.1002/spe.858](https://doi.org/10.1002/spe.858)

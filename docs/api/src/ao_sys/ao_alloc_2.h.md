---
author: "Stefan Wagner"
date: 2022-09-27
draft: true
external:
- https://dx.doi.org/10.1007/s11241-008-9052-7 : "A constant-time dynamic storage allocator for real-time systems. Masmano et al. 2008."
- https://dx.doi.org/10.1002/spe.858 : "Implementation of a constant-time dynamic storage allocator. Masmano et al. 2007."
permalink: /api/src/ao_sys/ao_alloc_2.h/
toc: true
---

# Notes

This module implements a constant-time dynamic storage allocator based on the two-level segregated fit (TLSF) algorithm proposed by Masmano et al.

...

- allocation
- deallocation
- constant time

...

# Include

| [`ao_size.h`](../ao/ao_size.h.md) |
| `stdbool.h` |
| `stddef.h` |

# Configuration

## `AO_ALLOC_ALLOCATED`
## `AO_ALLOC_ALLOCATED_MAX`

```c
#define AO_ALLOC_ALLOCATED     (false)
#define AO_ALLOC_ALLOCATED_MAX (false)
```

Defines whether to keep track of the current and maximum number of allocated bytes, respectively.

## `AO_ALLOC_FREE`
## `AO_ALLOC_FREE_MIN`

```c
#define AO_ALLOC_FREE     (false)
#define AO_ALLOC_FREE_MIN (false)
```

Defines whether to keep track of the current and minimum number of free bytes, respectively.

## `AO_ALLOC_SEGREGATION`

```c
#define AO_ALLOC_SEGREGATION (3)
```

Defines the segregation, which has an influence on the performance of the allocator with respect to fragmentation. That is, a high segregation potentially leads to high external fragmentation, but low internal fragmentation. On the other hand, a low segregation potentially leads to low external fragmentation, but high internal fragmentation.

## `AO_ALLOC_SIZE`

```c
#define AO_ALLOC_SIZE (8192)
```

Defines the allocator size, in bytes.

# Constants

## `AO_ALLOC_SEGREGATION_MAX`
## `AO_ALLOC_SEGREGATION_MIN`

```c
#define AO_ALLOC_SEGREGATION_MAX (AO_SIZE_BITS_LOG)
#define AO_ALLOC_SEGREGATION_MIN (0)
```

The maximum and minimum segregation.

# Variables

## `ao_alloc_allocated`
## `ao_alloc_allocated_max`

```c
extern size_t volatile ao_alloc_allocated;
extern size_t volatile ao_alloc_allocated_max;
```

The current and maximum number of allocated bytes.

## `ao_alloc_free`
## `ao_alloc_free_min`

```c
extern size_t volatile ao_alloc_free;
extern size_t volatile ao_alloc_free_min;
```

The current and minimum number of free bytes.

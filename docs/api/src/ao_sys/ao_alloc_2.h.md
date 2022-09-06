---
api: true
author: "Stefan Wagner"
date: 2022-08-31
description: "The /src/ao_sys/ao_alloc_2.h file of the ao real-time operating system."
draft: true
permalink: /api/src/ao_sys/ao_alloc_2.h/
seealso:
- /api/src/ao_sys/ao_alloc.h/
subtitle: "Constant-time allocator based on the two-level segregated fit algorithm"
title: "ao_alloc_2.h"
toc: true
---

# Overview

This module implements a constant-time dynamic storage allocator based on the two-level segregated fit (TLSF) algorithm proposed by Masmano et al.

...

- allocation
- deallocation
- constant time

...

# Include

```c
#include <ao_size.h>
#include <stdbool.h>
#include <stddef.h>
```

# Constants

The maximum and minimum segregation, respectively.

```c
#define AO_ALLOC_SEGREGATION_MAX (AO_SIZE_BITS_LOG)
#define AO_ALLOC_SEGREGATION_MIN (0)
```

# Configuration

Keep track of the current and maximum number of allocated bytes, respectively.

```c
#define AO_ALLOC_ALLOCATED       (false)
#define AO_ALLOC_ALLOCATED_MAX   (false)
```

Keep track of the current and minimum number of free bytes, respectively.

```c
#define AO_ALLOC_FREE            (false)
#define AO_ALLOC_FREE_MIN        (false)
```

The segregation has an influence on the performance of the allocator with respect to fragmentation. That is, a high segregation potentially leads to high external fragmentation, but low internal fragmentation. On the other hand, a low segregation potentially leads to low external fragmentation, but high internal fragmentation.

```c
#define AO_ALLOC_SEGREGATION     (3)
```

The allocator size.

```c
#define AO_ALLOC_SIZE            (8192)
```

# Variables

The current and maximum number of allocated bytes, respectively.

```c
extern size_t volatile ao_alloc_allocated;
extern size_t volatile ao_alloc_allocated_max;
```

The current and minimum number of free bytes, respectively.

```c
extern size_t volatile ao_alloc_free;
extern size_t volatile ao_alloc_free_min;
```

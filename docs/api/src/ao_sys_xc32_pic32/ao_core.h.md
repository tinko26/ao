---
author: "Stefan Wagner"
date: 2022-09-05
draft: true
permalink: /api/src/ao_sys_xc32_pic32/ao_core.h/
toc: true
---

# Notes

This module provides information about identical processor cores and is to support symmetric multiprocessing systems.

# Include

| `stdint.h` |

# Constants

## `AO_CORE_COUNT`

```c
#define AO_CORE_COUNT (1)
```

The number of identical processor cores.

# Types

## `ao_core_t`

```c
typedef uint32_t ao_core_t;
```

This type is an alias for the `uint32_t` unsigned integer type. It is to hold the zero-based index of a processor core.

# Functions

## `ao_core`

```c
#define ao_core() (0)
```

Gets the zero-based index of the processor core, on which the calling thread of execution is running. This function always returns `0`.

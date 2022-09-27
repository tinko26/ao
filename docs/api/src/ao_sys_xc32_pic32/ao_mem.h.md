---
author: "Stefan Wagner"
date: 2022-09-27
draft: true
permalink: /api/src/ao_sys_xc32_pic32/ao_mem.h/
toc: true
---

# Notes

This module provides three functions for copying, moving, and filling memory blocks, respectively.

# Include

| `string.h` |

# Functions

## `ao_mem_copy`

```c
#define ao_mem_copy(d, s, n) \
(                            \
    memcpy(d, s, n)          \
)
```

Copies the first `n` bytes from the memory block beginning at `s` to the memory block beginning at `d`. This function copies the data directly. Therefore, the memory blocks should not overlap. This function returns `d`.

## `ao_mem_move`

```c
#define ao_mem_move(d, s, n) \
(                            \
    memmove(d, s, n)         \
)
```

Copies the first `n` bytes from the memory block beginning at `s` to the memory block beginning at `d`. This function copies the data using a temporary buffer. Therefore, the memory blocks can overlap. This function returns `d`.

## `ao_mem_set`

```c
#define ao_mem_set(p, v, n)  \
(                            \
    memset(p, (int) (v), n)  \
)
```

Writes `v` to the first `n` bytes of the memory block beginning at `p`. This function returns `p`.

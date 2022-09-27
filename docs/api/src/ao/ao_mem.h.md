---
author: "Stefan Wagner"
date: 2022-09-27
draft: true
permalink: /api/src/ao/ao_mem.h/
toc: true
---

# Notes

This module provides three functions for copying, moving, and filling memory blocks, respectively. Although the standard library contains such functions, too, they are not available in a freestanding runtime environment. Nonetheless, many toolchains provide implementations for these functions, that are highly optimized for the target platform. Therefore, this module is abstract, that is, an implementation must be provided by a port.

# Include

| `stddef.h` |
| `stdint.h` |

# Functions

## `ao_mem_copy`

```c
void * ao_mem_copy(void * d, void const * s, size_t n);
```

Copies the first `n` bytes from the memory block beginning at `s` to the memory block beginning at `d`. This function copies the data directly. Therefore, the memory blocks should not overlap. This function returns `d`.

## `ao_mem_move`

```c
void * ao_mem_move(void * d, void const * s, size_t n);
```

Copies the first `n` bytes from the memory block beginning at `s` to the memory block beginning at `d`. This function copies the data using a temporary buffer. Therefore, the memory blocks can overlap. This function returns `d`.

## `ao_mem_set`

```c
void * ao_mem_set(void * p, uint8_t v, size_t n);
```

Writes `v` to the first `n` bytes of the memory block beginning at `p`. This function returns `p`.

---
api: true
author: "Stefan Wagner"
date: 2022-08-30
description: "The /src/ao/ao_mem.h file of the ao real-time operating system."
draft: false
permalink: /api/src/ao/ao_mem.h/
subtitle: "Memory blocks"
title: "ao_mem.h"
toc: true
---

# Overview

This module provides three functions for copying, moving, and filling memory blocks, respectively. Although the standard library contains such functions, too, they are not available in a freestanding runtime environment. Nonetheless, many toolchains provide implementations for these functions, that are highly optimized for the target platform. Therefore, this module is abstract, that is, an implementation must be provided by a port package.

# Include

```c
#include <stddef.h>
#include <stdint.h>
```

# Functions

Copy the first `n` bytes from the memory block beginning at `s` to the memory block beginning at `d`. This function copies the data directly. Therefore, the memory blocks should not overlap. This function returns `d`.

```c
void * ao_memcpy(void * d, void const * s, size_t n);
```

Copy the first `n` bytes from the memory block beginning at `s` to the memory block beginning at `d`. This function copies the data using a temporary buffer. Therefore, the memory blocks can overlap. This function returns `d`.

```c
void * ao_memmove(void * d, void const * s, size_t n);
```

Write `v` to the first `n` bytes of the memory block beginning at `p`. This function returns `p`.

```c
void * ao_memset(void * p, uint8_t v, size_t n);
```

# Example

A memory block can be copied to another location.

```c
char block[512];
```

```c
ao_memcpy(block + 256, block, 256);
```

This function copies the data directly, that is, without using a temporary buffer. Therefore, the two memory blocks should not overlap. However, if that is the case, then another function can be used.

```c
ao_memmove(block + 32 , block, 256);
```

Finally, a memory block can be filled with a constant value.

```c
ao_memset(block, 'a', 512);
```

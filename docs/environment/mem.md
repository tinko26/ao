---
author: "Stefan Wagner"
date: 2022-08-07
description: "Memory Blocks in the ao Real-Time Operating System (RTOS)."
draft: false
permalink: /environment/mem/
title: "Memory Blocks"
---

# Memory Blocks

The `ao_mem.h` module declares three functions for copying, moving, and filling memory blocks, respectively. Although the standard library defines such functions, too, they are not available in a freestanding runtime environment.

## Functions

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

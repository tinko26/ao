---
author: "Stefan Wagner"
date: 2022-08-12
description: "The ao_mem.h module of the ao real-time operating system."
draft: false
permalink: /modules/mem/
title: "<code>ao_mem.h</code>"
---

# Overview

This module provides three functions for copying, moving, and filling memory blocks, respectively. Although the standard library contains such functions, too, they are not available in a freestanding runtime environment. Nonetheless, many toolchains provide implementations for these functions, that are highly optimized for the target platform. Therefore, this module is abstract, that is, an implementation must be provided by a port package.

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

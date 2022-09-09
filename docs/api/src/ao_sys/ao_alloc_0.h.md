---
author: "Stefan Wagner"
date: 2022-08-31
draft: true
permalink: /api/src/ao_sys/ao_alloc_0.h/
seealso:
- /api/src/ao_sys/ao_alloc.h/
toc: true
---

# Overview

This module provides a stub implementation for the allocator. That is, it does not facilitate the allocation or deallocation of memory blocks. Instead, all the functions simply ignore the input and return a standard value indicating failure.

# Identifiers

## `AO_ALLOC_0`

```c
#define AO_ALLOC_0
```

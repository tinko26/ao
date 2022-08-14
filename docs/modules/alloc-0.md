---
author: "Stefan Wagner"
date: 2022-08-13
description: ""
draft: true
permalink: /modules/alloc-0/
title: "ao_alloc_0.h"
---

# ao_alloc_0.h

This module provides a stub implementation for the [allocator](alloc.md). That is, it does not facilitate the allocation or deallocation of memory blocks. Instead, all the functions simply ignore the input and return standard values.

| Function | Returns |
|----------|---------|
| `ao_acquire()` | `NULL` |
| `ao_release()` | `false` |
| `ao_retain()` | `false` |

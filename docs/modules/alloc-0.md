---
author: "Stefan Wagner"
date: 2022-08-13
description: "The ao_alloc_0.h module of the ao real-time operating system."
draft: false
permalink: /modules/alloc-0/
title: "ao_alloc_0.h"
---

# Overview

This module provides a stub implementation for the [allocator](../allocator.md). That is, it does not facilitate the allocation or deallocation of memory blocks. Instead, all the functions simply ignore the input and return standard values.

| Function | Returns |
|----------|---------|
| `ao_acquire()` | `NULL` |
| `ao_release()` | `false` |
| `ao_retain()` | `false` |

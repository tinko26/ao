---
author: "Stefan Wagner"
date: 2022-08-12
description: "The ao_core.h module of the ao real-time operating system."
draft: false
permalink: /modules/core/
title: "<code>ao_core.h</code>"
---

# Overview

This module provides information about identical processor cores and is to support symmetric multiprocessing systems.

Therefore, it defines the number of cores ...

```c
#define AO_CORE_COUNT
```

... as well as the `ao_core_t` type, which is an unsigned integer type that can hold the zero-based index of a processor core.  Additionally, the module contains a single function that returns the index of the core, on which the calling thread of execution is running.

```c
ao_core_t ao_core();
```

This module is abstract, that is, an implementation must be provided by a port package in order to support [multitasking](../multitasking.md), even on a single-core platform.

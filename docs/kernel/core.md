---
author: "Stefan Wagner"
date: 2022-08-08
description: "Cores in the ao Real-Time Operating System (RTOS)."
draft: false
permalink: /kernel/core/
title: "Cores"
---

# Cores

The `ao_core.h` module provides information about identical processor cores and is to support symmetric multiprocessing systems. 

Therefore, it defines the number of cores ...

```c
#define AO_CORE_COUNT
```

... as well as the `ao_core_t` type, which is an unsigned integer type that can hold the zero-based index of a processor core. 

Additionally, the module contains a single function that returns the index of the core, on which the calling thread of execution is running.

```c
ao_core_t ao_core();
```

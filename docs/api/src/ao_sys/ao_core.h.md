---
author: "Stefan Wagner"
date: 2022-08-31
draft: true
permalink: /api/src/ao_sys/ao_core.h/
toc: true
---

# Overview

This module provides information about identical processor cores and is to support symmetric multiprocessing systems.

This module is abstract, that is, an implementation must be provided by a port package in order to support multitasking, even on a single-core platform.

# Include

```c
#include <stdint.h>
```

# Constants

## `AO_CORE_COUNT`

The number of identical processor cores.

```c
#define AO_CORE_COUNT (1)
```

# Typedefs

```c
typedef uint32_t ao_core_t;
```

# Types

## `ao_core_t`

This type is an alias for an unsigned integer type that can hold the zero-based index of a processor core.

# Functions

## `ao_core`

Get the zero-based index of the processor core, on which the calling thread of execution is running.

```c
ao_core_t ao_core();
```

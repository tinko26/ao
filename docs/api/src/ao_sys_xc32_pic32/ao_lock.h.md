---
author: "Stefan Wagner"
date: 2022-09-05
draft: true
external:
- https://en.wikipedia.org/wiki/Critical_section : "Critical section"
permalink: /api/src/ao_sys_xc32_pic32/ao_lock.h/
toc: true
---

# Notes

This module defines a mechanism for critical sections, that are required by the kernel in order to protect its resources from concurrent accesses.

# Include

```c
#include <ao_ir.h>
#include <ao_sys.h>
#include <stdint.h>
```

# Configuration

## `AO_LOCK_PRIO`

```c
#define AO_LOCK_PRIO (AO_IR_PRIO_MAX)
```

Defines the maximum priority of interrupts to disable.

# Types

## `ao_lock_t`

```c
typedef uint32_t ao_lock_t;
```

This type represents a container for lock-related data.

# Functions

## `ao_lock`
## `ao_unlock`

```c
#define ao_lock(x)
#define ao_unlock(x)
```

Enters or exits a critical section, respectively.

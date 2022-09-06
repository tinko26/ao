---
api: true
author: "Stefan Wagner"
date: 2022-09-05
description: "The /src/ao_sys_xc32_pic32/ao_lock.h file of the ao real-time operating system."
draft: true
permalink: /api/src/ao_sys_xc32_pic32/ao_lock.h/
subtitle: "Locks"
title: "ao_lock.h"
toc: true
wiki:
- critical-section
---

# Overview

This module defines a mechanism for critical sections, that are required by the kernel in order to protect its resources from concurrent accesses.

# Include

```c
#include <ao_ir.h>
#include <ao_sys.h>
#include <stdint.h>
```

# Typedefs

This type represents a container for lock-related data.

```c
typedef uint32_t ao_lock_t;
```

# Configuration

The maximum priority of interrupts to disable.

```c
#define AO_LOCK_PRIO (AO_IR_PRIO_MAX)
```

# Functions

Enter or exit a critical section, respectively.

```c
#define ao_lock(x)
#define ao_unlock(x)
```

---
api: true
author: "Stefan Wagner"
date: 2022-08-31
description: "The /src/ao_sys/ao_lock.h file of the ao real-time operating system."
draft: true
permalink: /api/src/ao_sys/ao_lock.h/
subtitle: "Locks"
title: "ao_lock.h"
toc: true
wiki:
- critical-section
---

# Overview

This module defines a mechanism for critical sections, that are required by the kernel in order to protect its resources from concurrent accesses. Since kernel-level critical sections utilize hardware features, this module is abstract. Therefore, an implementation must be provided by a port package. 

# Typedefs

```c
typedef struct ao_lock_t ao_lock_t;
```

# Types

## `ao_lock_t`

This type represents a container for lock-related data. The actual make-up of this type is up to the implementation provided by the port package. For the kernel modules, this type is completely opaque, that is, no assumptions are made about its inner structure.

```c
struct ao_lock_t { };
```

# Functions

Enter or exit a critical section, respectively.

```c
void ao_lock(  ao_lock_t * x);
void ao_unlock(ao_lock_t * x);
```

# Usage

```c
ao_lock_t * l;
```

```c
ao_lock(l);
{
    // Critical section.
}
ao_unlock(l);
```

# Porting

On a single-core platform, a critical section must disable all interrupts that call kernel functions. This includes both the alarm interrupt and the task switch interrupt. Potentially, additional measures must be taken on a multi-core platform, such as spinlocks. However, the implementation must ensure, that no two threads of execution can be inside a critical section simultaneously. Additionally, the implementation must support calls from both tasks and interrupt handlers.

Furthermore, the implementation should support nesting, although this is not strictly required by the kernel package. However, it can be assumed, that a call to `ao_lock()` is always followed by a call to `ao_unlock()` with the same parameter and from the same block scope, and that nesting calls do not overlap.

```c
ao_lock_t * l1;
ao_lock_t * l2;
```

```c
ao_lock(l1);
{
    // ...
    ao_lock(l2);
    {
        // ...
    }
    ao_unlock(l2);
    // ...
}
ao_unlock(l1);
```

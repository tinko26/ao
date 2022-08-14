---
author: "Stefan Wagner"
date: 2022-08-12
description: "The ao_lock.h module of the ao real-time operating system."
draft: true
permalink: /modules/lock/
title: "ao_lock.h"
---

# ao_lock.h

This module defines a mechanism for [critical sections](https://en.wikipedia.org/wiki/Critical_section), that are required by the kernel in order to protect its resources from concurrent accesses. Since kernel-level critical sections utilize hardware features, this module is abstract. Therefore, an implementation must be provided by a port package. 

## Type

The `ao_lock_t` type represents a container for lock-related data. The actual make-up of this type is up to the implementation provided by the port package. For the kernel modules, this type is completely opaque, that is, no assumptions are made about its inner structure.

## Functions

The module provides two functions that enter and exit, respectively, a critical section.

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

## Porting

On a single-core platform, a critical section must disable all interrupts that call kernel functions. This includes both the [alarm interrupt](ir-alarm.md) and the [task switch interrupt](ir-task.md). Potentially, additional measures must be taken on a multi-core platform, such as spinlocks. However, the implementation must ensure, that no two threads of execution can be inside a critical section simultaneously. Additionally, the implementation must support calls from both tasks and interrupt handlers.

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

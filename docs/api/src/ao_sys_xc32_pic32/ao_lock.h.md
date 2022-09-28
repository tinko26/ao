---
author: "Stefan Wagner"
date: 2022-09-28
draft: true
external:
- https://en.wikipedia.org/wiki/Critical_section : "Critical section"
permalink: /api/src/ao_sys_xc32_pic32/ao_lock.h/
toc: true
---

# Notes

This module defines a mechanism for critical sections, that are required by the kernel in order to protect its resources from concurrent accesses.

Locking sets the interrupt priority level to the lock priority. That is, locking disables only those interrupts, whose priority is less than or equal to the lock priority. Higher-priority interrupts will remain enabled. However, these interrupts must not make system calls.

# Include

| [`ao_ir.h`](ao_ir.h.md) |
| [`ao_sys.h`](ao_sys.h.md) |
| `stdint.h` |

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

Represents a container for lock-related data.

# Functions

## `ao_lock`

```c
#define ao_lock(lock)                       \
{                                           \
    *(lock) = ao_sys_lock_ir(AO_LOCK_PRIO); \
}
```

Enters a critical section.

## `ao_unlock`

```c
#define ao_unlock(lock)        \
{                              \
    ao_sys_unlock_ir(*(lock)); \
}
```

Exits a critical section.

---
author: "Stefan Wagner"
date: 2022-09-25
draft: true
permalink: /api/src/ao_sys_xc32_pic32mx/ao_sys_lock_ir.h/
toc: true
---

# Notes

This module defines locks to constitue critical sections by disabling interrupts based on their priority. This is accomplished by manipulating the `Status.IPL` bits.

## Example

Lock all interrupts of priority level 4 or less.

```c
uint32_t p = 4;
uint32_t x;

x = ao_sys_lock_ir(p);
{
    // ...

    // Critical section.
    // Interrupts are disabled up to and including priority level p.

    // ...
}
ao_sys_unlock_ir(x);
```

# Include

| `stdint.h` |
| `xc.h` |

# Functions

## `ao_sys_lock_ir`

```c
uint32_t ao_sys_lock_ir(uint32_t p2);
```

Enters a critical section. This function disables all interrupts whose priority is not greater than `p` by manipulating the `Status.IPL` bits.

## `ao_sys_unlock_ir`

```c
void ao_sys_unlock_ir(uint32_t x);
```

Exits a critical section. This function restores the previous value of the `Status.IPL` bits.

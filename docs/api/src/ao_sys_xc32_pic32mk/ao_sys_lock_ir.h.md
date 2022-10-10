---
author: "Stefan Wagner"
date: 2022-10-10
draft: true
permalink: /api/src/ao_sys_xc32_pic32mk/ao_sys_lock_ir.h/
toc: true
---

# Notes

This module defines locks to constitue critical sections by disabling interrupts based on their priority. This is accomplished by manipulating the `Status.IPL` bits via the `View_IPL` register.

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
#define ao_sys_lock_ir(p)              \
({                                     \
    uint32_t x0 = _CP0_GET_VIEW_IPL(); \
    uint32_t x1 = (p) << 2;            \
                                       \
    if (x0 < x1)                       \
    {                                  \
        _CP0_SET_VIEW_IPL(x1);         \
    }                                  \
                                       \
    x0;                                \
})
```

Enters a critical section. This function disables all interrupts whose priority is not greater than `p` by manipulating the `Status.IPL` bits.

## `ao_sys_unlock_ir`

```c
#define ao_sys_unlock_ir(x) \
{                           \
    _CP0_SET_VIEW_IPL(x);   \
}
```

Exits a critical section. This function restores the previous value of the `Status.IPL` bits.

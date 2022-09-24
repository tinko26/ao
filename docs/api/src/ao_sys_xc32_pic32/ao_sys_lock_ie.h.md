---
author: "Stefan Wagner"
date: 2022-09-20
draft: true
permalink: /api/src/ao_sys_xc32_pic32/ao_sys_lock_ie.h/
toc: true
---

# Notes

This module defines locks to constitute critical sections by disabling interrupts globally.

## Example

```c
uint32_t x;

x = ao_sys_lock_ie();
{
    // ...

    // Critical section.
    // Interrupts are disabled globally.

    // ...
}
ao_sys_unlock_ie(x);
```

# Include

| `xc.h` |

# Identifier

```c
#define AO_SYS_LOCK_IE
```

# Functions

## `ao_sys_lock_ie`

```c
#define ao_sys_lock_ie()           \
(                                  \
    __builtin_disable_interrupts() \
)
```

Enters a critical section by disabling interrupts globally. This function clears the `Status.IE` bit and returns the previous value of the `Status` register.

## `ao_sys_unlock_ie`

```c
#define ao_sys_unlock_ie(x) \
{                           \
    _CP0_SET_STATUS(x);     \
}
```

Exits a critical section. This function writes the specified value to the `Status` register.

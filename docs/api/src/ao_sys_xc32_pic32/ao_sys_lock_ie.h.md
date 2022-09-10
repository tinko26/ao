---
author: "Stefan Wagner"
date: 2022-09-05
draft: true
permalink: /api/src/ao_sys_xc32_pic32/ao_sys_lock_ie.h/
toc: true
---

# Notes

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

```c
#include <xc.h>
```

# Functions

## `ao_sys_lock_ie`

```c
#define ao_sys_lock_ie()
```

## `ao_sys_unlock_ie`

```c
#define ao_sys_unlock_ie(x)
```

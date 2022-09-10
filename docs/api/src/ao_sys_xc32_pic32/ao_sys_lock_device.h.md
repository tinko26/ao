---
author: "Stefan Wagner"
date: 2022-09-05
draft: true
external:
- https://microchip.com/DS61112 : "PIC32 Family Reference Manual, Section 6, Oscillators"
permalink: /api/src/ao_sys_xc32_pic32/ao_sys_lock_device.h/
toc: true
---

# Notes

## Example

```c
ao_sys_lock_device_t x;

ao_sys_unlock_device(&x);
{
    // ...

    // Critical section.
    // Device is unlocked.

    // ...
}
ao_sys_lock_device(&x);
```

# Include

```c
#include <stdint.h>
```

# Types

## `ao_sys_lock_device_t`

```c
typedef struct ao_sys_lock_device_t ao_sys_lock_device_t;
```

```c
struct ao_sys_lock_device_t
{
    uint32_t dma;
    uint32_t ie;
};
```

It consists of the following members.

| `dma` | |
| `ie` | |

# Functions

## `ao_sys_unlock_device`
## `ao_sys_lock_device`

```c
void ao_sys_unlock_device(ao_sys_lock_device_t * x);
void ao_sys_lock_device(  ao_sys_lock_device_t * x);
```

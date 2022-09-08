---
author: "Stefan Wagner"
date: 2022-09-05
draft: true
external:
- https://microchip.com/DS61112 : "PIC32 Family Reference Manual, Section 6, Oscillators"
permalink: /api/src/ao_sys_xc32_pic32/ao_sys_lock_device.h/
toc: true
---

# Include

```c
#include <stdint.h>
```

# Typedefs

```c
typedef struct ao_sys_lock_device_t ao_sys_lock_device_t;
```

# Types

## `ao_sys_lock_device_t`

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

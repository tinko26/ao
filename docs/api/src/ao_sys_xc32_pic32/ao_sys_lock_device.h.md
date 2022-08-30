---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The /src/ao_sys_xc32_pic32/ao_sys_lock_device.h file of the ao real-time operating system."
draft: true
permalink: /api/src/ao_sys_xc32_pic32/ao_sys_lock_device.h/
subtitle: ""
title: "ao_sys_lock_device.h"
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

Members:

| `dma` | |
| `ie` | |

# Functions

```c
void ao_sys_unlock_device( ao_sys_lock_device_t * x);
```

```c
void ao_sys_lock_device( ao_sys_lock_device_t * x);
```

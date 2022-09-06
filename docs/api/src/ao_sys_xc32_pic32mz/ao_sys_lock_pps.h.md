---
author: "Stefan Wagner"
date: 2022-08-29
draft: true
permalink: /api/src/ao_sys_xc32_pic32mz/ao_sys_lock_pps.h/
toc: true
---

# Include

```c
#include <ao_sys_lock_device.h>
#include <stdint.h>
```

# Typedefs

```c
typedef struct ao_sys_lock_pps_t ao_sys_lock_pps_t;
```

# Types

## `ao_sys_lock_pps_t`

```c
struct ao_sys_lock_pps_t
{
ao_sys_lock_device_t device;
uint32_t io;
};
```

It consists of the following members.

| `device` | |
| `io` | |

# Functions

```c
void ao_sys_unlock_pps( ao_sys_lock_pps_t * x);
```

```c
void ao_sys_lock_pps( ao_sys_lock_pps_t * x);
```

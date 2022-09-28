---
author: "Stefan Wagner"
date: 2022-09-25
draft: true
permalink: /api/src/ao_sys_xc32_pic32mk/ao_sys_lock_pps.h/
toc: true
---

# Notes

This module defines locks to constitue critical sections by unlocking the peripheral pin select registers.

## Example

```c
ao_sys_lock_pps_t x;

ao_sys_unlock_pps(&x);
{
    // ...

    // Critical section.
    // Peripheral pin select registers can be written.

    // ...
}
ao_sys_lock_pps(&x);
```

# Include

| [`ao_sys_lock_device.h`](../ao_sys_xc32_pic32/ao_sys_lock_device.h.md) |
| `stdint.h` |

# Types

## `ao_sys_lock_pps_t`

```c
typedef struct ao_sys_lock_pps_t ao_sys_lock_pps_t;
```

Represents lock-related data.

# Structs

## `ao_sys_lock_pps_t`

```c
struct ao_sys_lock_pps_t
{
    ao_sys_lock_device_t device;
    uint32_t             io;
};
```

| `device` | The lock-related data for device locks. |
| `io` | The backup of the `CFGCON.IOLOCK` bit. |

# Functions

## `ao_sys_unlock_pps`

```c
void ao_sys_unlock_pps(ao_sys_lock_pps_t * x);
```

Enters a critical section.

## `ao_sys_lock_pps`

```c
void ao_sys_lock_pps(ao_sys_lock_pps_t * x);
```

Exits a critical section.

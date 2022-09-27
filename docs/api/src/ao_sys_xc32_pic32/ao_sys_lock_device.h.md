---
author: "Stefan Wagner"
date: 2022-09-20
draft: true
external:
- https://microchip.com/DS61112 : "PIC32 Family Reference Manual, Section 6, Oscillators"
permalink: /api/src/ao_sys_xc32_pic32/ao_sys_lock_device.h/
toc: true
---

# Notes

This module defines locks to constitute critical sections by executing the system unlock sequence. This is required to write dedicated registers, such as the `OSCCON` register when performing a clock switch.

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

| `stdint.h` |

# Identifier

```c
#define AO_SYS_LOCK_DEVICE
```

# Types

## `ao_sys_lock_device_t`

```c
typedef struct ao_sys_lock_device_t ao_sys_lock_device_t;
```

Represents lock-related data.

# Structs

## `ao_sys_lock_device_t`

```c
struct ao_sys_lock_device_t
{
    uint32_t dma;
    uint32_t ie;
};
```

| `dma` | The backup of the `DMACON.SUSPEND` bit. |
| `ie` | The backup of the `Status` register. |

# Functions

## `ao_sys_unlock_device`

```c
void ao_sys_unlock_device(ao_sys_lock_device_t * x);
```

Enters a critical section. First, this function disables interrupts globally and suspends the DMA controller. Then, it performs the system unlock sequence.

## `ao_sys_lock_device`

```c
void ao_sys_lock_device(ao_sys_lock_device_t * x);
```

Exists a critical section. First, this function performs a system lock. Then, it restores the previous state of both the DMA controller and the global interrupts enable.

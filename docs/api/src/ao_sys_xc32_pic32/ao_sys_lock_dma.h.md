---
author: "Stefan Wagner"
date: 2022-10-18
draft: true
permalink: /api/src/ao_sys_xc32_pic32/ao_sys_lock_dma.h/
toc: true
---

# Notes

This module defines locks to constitute critical sections by suspending the DMA controller.

## Example

```c
uint32_t x;

x = ao_sys_lock_dma();
{
    // ...

    // Critical section.
    // DMA controller is suspended.

    // ...
}
ao_sys_unlock_dma(x);
```

# Include

| `stdint.h` |

# Functions

## `ao_sys_lock_dma`

```c
uint32_t ao_sys_lock_dma();
```

Enters a critical section by suspending the DMA controller. This function returns the previous state of the `DMACON.SUSPEND` bit.

## `ao_sys_unlock_dma`

```c
void ao_sys_unlock_dma(uint32_t x);
```

Exits a critical section. This function restores the previous value of the `DMACON.SUSPEND` bit.

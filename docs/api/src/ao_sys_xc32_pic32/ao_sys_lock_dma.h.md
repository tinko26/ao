---
author: "Stefan Wagner"
date: 2022-09-05
draft: true
external:
- https://microchip.com/DS60001117 : "PIC32 Family Reference Manual, Section 31, DMA Controller"
permalink: /api/src/ao_sys_xc32_pic32/ao_sys_lock_dma.h/
toc: true
---

# Notes

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

```c
#include <stdint.h>
```

# Functions

## `ao_sys_lock_dma`

```c
uint32_t ao_sys_lock_dma();
```

## `ao_sys_unlock_dma`

```c
void ao_sys_unlock_dma(uint32_t x);
```

---
api: true
author: "Stefan Wagner"
date: 2022-09-05
description: "The /src/ao_sys_xc32_pic32/ao_sys_lock_dma.h file of the ao real-time operating system."
draft: true
external:
- https://microchip.com/DS60001117 : "PIC32 Family Reference Manual, Section 31, DMA Controller"
permalink: /api/src/ao_sys_xc32_pic32/ao_sys_lock_dma.h/
subtitle: "System locking (DMA)"
title: "ao_sys_lock_dma.h"
toc: true
---

# Include

```c
#include <stdint.h>
```

# Functions

```c
uint32_t ao_sys_lock_dma();
```

```c
void ao_sys_unlock_dma(uint32_t x);
```

---
api: true
author: "Stefan Wagner"
date: 2022-09-05
description: "The /src/ao_sys_xc32_pic32mz_da/ao_ir_gpu.h file of the ao real-time operating system."
draft: true
permalink: /api/src/ao_sys_xc32_pic32mz_da/ao_ir_gpu.h/
subtitle: "GPU interrupt"
title: "ao_ir_gpu.h"
toc: true
---

# Include

```c
#include <stdbool.h>
#include <sys/attribs.h>
#include <xc.h>
```

# Configuration

## `AO_IR_GPU`

The interrupt handler attribute.

```c
#define AO_IR_GPU_ATTRIBUTE __ISR(_GPU_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_GPU_PRIO      (4)
#define AO_IR_GPU_SUBPRIO   (0)
```

# Functions

## `ao_ir_gpu`

Enable or disable the interrupt.

```c
#define ao_ir_gpu_enable()
#define ao_ir_gpu_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_gpu_request()
#define ao_ir_gpu_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_gpu_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_gpu_is_pending()
```

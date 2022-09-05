---
api: true
author: "Stefan Wagner"
date: 2022-09-05
description: "The /src/ao_sys_xc32_pic32mx_330/ao_ir_rtcc.h file of the ao real-time operating system."
draft: true
permalink: /api/src/ao_sys_xc32_pic32mx_330/ao_ir_rtcc.h/
subtitle: "Real-time clock and calendar interrupt"
title: "ao_ir_rtcc.h"
toc: true
---

# Include

```c
#include <stdbool.h>
#include <sys/attribs.h>
#include <xc.h>
```

# Configuration

## `AO_IR_RTCC`

The interrupt handler attribute.

```c
#define AO_IR_RTCC_ATTRIBUTE __ISR(_RTCC_VECTOR, IPL4SOFT)
```

The interrupt priority and subpriority.

```c
#define AO_IR_RTCC_PRIO      (4)
#define AO_IR_RTCC_SUBPRIO   (0)
```

# Functions

## `ao_ir_rtcc`

Enable or disable the interrupt.

```c
#define ao_ir_rtcc_enable()
#define ao_ir_rtcc_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_rtcc_request()
#define ao_ir_rtcc_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_rtcc_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_rtcc_is_pending()
```

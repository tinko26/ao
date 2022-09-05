---
api: true
author: "Stefan Wagner"
date: 2022-09-05
description: "The /src/ao_sys_xc32_pic32mz_da/ao_ir_sqi.h file of the ao real-time operating system."
draft: true
permalink: /api/src/ao_sys_xc32_pic32mz_da/ao_ir_sqi.h/
subtitle: "SQI interrupt"
title: "ao_ir_sqi.h"
toc: true
---

# Include

```c
#include <stdbool.h>
#include <sys/attribs.h>
#include <xc.h>
```

# Configuration

## `AO_IR_SQI1`

The interrupt handler attribute.

```c
#define AO_IR_SQI1_ATTRIBUTE __ISR(_SQI1_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_SQI1_PRIO      (4)
#define AO_IR_SQI1_SUBPRIO   (0)
```

# Functions

## `ao_ir_sqi1`

Enable or disable the interrupt.

```c
#define ao_ir_sqi1_enable()
#define ao_ir_sqi1_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_sqi1_request()
#define ao_ir_sqi1_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_sqi1_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_sqi1_is_pending()
```

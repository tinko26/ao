---
api: true
author: "Stefan Wagner"
date: 2022-09-05
description: "The /src/ao_sys_xc32_pic32mx_5xx/ao_ir_cn.h file of the ao real-time operating system."
draft: true
permalink: /api/src/ao_sys_xc32_pic32mx_5xx/ao_ir_cn.h/
subtitle: "Change notification interrupt"
title: "ao_ir_cn.h"
toc: true
---

# Include

```c
#include <stdbool.h>
#include <sys/attribs.h>
#include <xc.h>
```

# Configuration

## `AO_IR_CN`

The interrupt handler attribute.

```c
#define AO_IR_CN_ATTRIBUTE __ISR(_CHANGE_NOTICE_VECTOR, IPL4SOFT)
```

The interrupt priority and subpriority.

```c
#define AO_IR_CN_PRIO      (4)
#define AO_IR_CN_SUBPRIO   (0)
```

# Functions

## `ao_ir_cn`

Enable or disable the interrupt.

```c
#define ao_ir_cn_enable()
#define ao_ir_cn_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_cn_request()
#define ao_ir_cn_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_cn_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_cn_is_pending()
```

---
api: true
author: "Stefan Wagner"
date: 2022-09-05
description: "The /src/ao_sys_xc32_pic32mk_gpk/ao_ir_dataee.h file of the ao real-time operating system."
draft: true
permalink: /api/src/ao_sys_xc32_pic32mk_gpk/ao_ir_dataee.h/
subtitle: "Data EEPROM interrupt"
title: "ao_ir_dataee.h"
toc: true
---

# Include

```c
#include <stdbool.h>
#include <sys/attribs.h>
#include <xc.h>
```

# Configuration

## `AO_IR_DATAEE`

The interrupt handler attribute.

```c
#define AO_IR_DATAEE_ATTRIBUTE __ISR(_DATA_EE_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_DATAEE_PRIO      (4)
#define AO_IR_DATAEE_SUBPRIO   (0)
```

# Functions

## `ao_ir_dataee`

Enable or disable the interrupt.

```c
#define ao_ir_dataee_enable()
#define ao_ir_dataee_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_dataee_request()
#define ao_ir_dataee_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_dataee_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_dataee_is_pending()
```

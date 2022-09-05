---
api: true
author: "Stefan Wagner"
date: 2022-09-05
description: "The /src/ao_sys_xc32_pic32mk_gpk/ao_ir_can.h file of the ao real-time operating system."
draft: true
permalink: /api/src/ao_sys_xc32_pic32mk_gpk/ao_ir_can.h/
subtitle: "CAN interrupts"
title: "ao_ir_can.h"
toc: true
---

# Include

```c
#include <stdbool.h>
#include <sys/attribs.h>
#include <xc.h>
```

# Configuration

## `AO_IR_CAN1`

The interrupt handler attribute.

```c
#define AO_IR_CAN1_ATTRIBUTE __ISR(_CAN1_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_CAN1_PRIO      (4)
#define AO_IR_CAN1_SUBPRIO   (0)
```

## `AO_IR_CAN2`

The interrupt handler attribute.

```c
#define AO_IR_CAN2_ATTRIBUTE __ISR(_CAN2_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_CAN2_PRIO      (4)
#define AO_IR_CAN2_SUBPRIO   (0)
```

## `AO_IR_CAN3`

The interrupt handler attribute.

```c
#define AO_IR_CAN3_ATTRIBUTE __ISR(_CAN3_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_CAN3_PRIO      (4)
#define AO_IR_CAN3_SUBPRIO   (0)
```

## `AO_IR_CAN4`

The interrupt handler attribute.

```c
#define AO_IR_CAN4_ATTRIBUTE __ISR(_CAN4_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_CAN4_PRIO      (4)
#define AO_IR_CAN4_SUBPRIO   (0)
```

# Functions

## `ao_ir_can1`

Enable or disable the interrupt.

```c
#define ao_ir_can1_enable()
#define ao_ir_can1_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_can1_request()
#define ao_ir_can1_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_can1_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_can1_is_pending()
```

## `ao_ir_can2`

Enable or disable the interrupt.

```c
#define ao_ir_can2_enable()
#define ao_ir_can2_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_can2_request()
#define ao_ir_can2_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_can2_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_can2_is_pending()
```

## `ao_ir_can3`

Enable or disable the interrupt.

```c
#define ao_ir_can3_enable()
#define ao_ir_can3_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_can3_request()
#define ao_ir_can3_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_can3_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_can3_is_pending()
```

## `ao_ir_can4`

Enable or disable the interrupt.

```c
#define ao_ir_can4_enable()
#define ao_ir_can4_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_can4_request()
#define ao_ir_can4_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_can4_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_can4_is_pending()
```

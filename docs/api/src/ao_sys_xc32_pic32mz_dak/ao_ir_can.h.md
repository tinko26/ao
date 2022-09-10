---
author: "Stefan Wagner"
date: 2022-09-05
draft: true
permalink: /api/src/ao_sys_xc32_pic32mz_dak/ao_ir_can.h/
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

```c
#define AO_IR_CAN1_ATTRIBUTE __ISR(_CAN1_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_CAN1_PRIO    (4)
#define AO_IR_CAN1_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_CAN2`

```c
#define AO_IR_CAN2_ATTRIBUTE __ISR(_CAN2_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_CAN2_PRIO    (4)
#define AO_IR_CAN2_SUBPRIO (0)
```

The interrupt priority and subpriority.

# Functions

## `ao_ir_can1`

```c
#define ao_ir_can1_enable()
#define ao_ir_can1_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_can1_request()
#define ao_ir_can1_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_can1_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_can1_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_can2`

```c
#define ao_ir_can2_enable()
#define ao_ir_can2_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_can2_request()
#define ao_ir_can2_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_can2_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_can2_is_pending()
```

Checks whether the interrupt is pending.

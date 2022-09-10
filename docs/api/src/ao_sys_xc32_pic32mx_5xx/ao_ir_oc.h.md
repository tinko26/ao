---
author: "Stefan Wagner"
date: 2022-09-05
draft: true
permalink: /api/src/ao_sys_xc32_pic32mx_5xx/ao_ir_oc.h/
toc: true
---

# Include

```c
#include <stdbool.h>
#include <sys/attribs.h>
#include <xc.h>
```

# Configuration

## `AO_IR_OC1`

```c
#define AO_IR_OC1_ATTRIBUTE __ISR(_OUTPUT_COMPARE_1_VECTOR, IPL4SOFT)
```

The interrupt handler attribute.

```c
#define AO_IR_OC1_PRIO    (4)
#define AO_IR_OC1_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_OC2`

```c
#define AO_IR_OC2_ATTRIBUTE __ISR(_OUTPUT_COMPARE_2_VECTOR, IPL4SOFT)
```

The interrupt handler attribute.

```c
#define AO_IR_OC2_PRIO    (4)
#define AO_IR_OC2_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_OC3`

```c
#define AO_IR_OC3_ATTRIBUTE __ISR(_OUTPUT_COMPARE_3_VECTOR, IPL4SOFT)
```

The interrupt handler attribute.

```c
#define AO_IR_OC3_PRIO    (4)
#define AO_IR_OC3_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_OC4`

```c
#define AO_IR_OC4_ATTRIBUTE __ISR(_OUTPUT_COMPARE_4_VECTOR, IPL4SOFT)
```

The interrupt handler attribute.

```c
#define AO_IR_OC4_PRIO    (4)
#define AO_IR_OC4_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_OC5`

```c
#define AO_IR_OC5_ATTRIBUTE __ISR(_OUTPUT_COMPARE_5_VECTOR, IPL4SOFT)
```

The interrupt handler attribute.

```c
#define AO_IR_OC5_PRIO    (4)
#define AO_IR_OC5_SUBPRIO (0)
```

The interrupt priority and subpriority.

# Functions

## `ao_ir_oc1`

```c
#define ao_ir_oc1_enable()
#define ao_ir_oc1_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_oc1_request()
#define ao_ir_oc1_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_oc1_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_oc1_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_oc2`

```c
#define ao_ir_oc2_enable()
#define ao_ir_oc2_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_oc2_request()
#define ao_ir_oc2_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_oc2_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_oc2_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_oc3`

```c
#define ao_ir_oc3_enable()
#define ao_ir_oc3_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_oc3_request()
#define ao_ir_oc3_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_oc3_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_oc3_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_oc4`

```c
#define ao_ir_oc4_enable()
#define ao_ir_oc4_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_oc4_request()
#define ao_ir_oc4_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_oc4_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_oc4_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_oc5`

```c
#define ao_ir_oc5_enable()
#define ao_ir_oc5_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_oc5_request()
#define ao_ir_oc5_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_oc5_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_oc5_is_pending()
```

Checks whether the interrupt is pending.

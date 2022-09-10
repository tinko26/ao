---
author: "Stefan Wagner"
date: 2022-09-05
draft: true
permalink: /api/src/ao_sys_xc32_pic32mk_gpk/ao_ir_qei.h/
toc: true
---

# Include

```c
#include <stdbool.h>
#include <sys/attribs.h>
#include <xc.h>
```

# Configuration

## `AO_IR_QEI1`

```c
#define AO_IR_QEI1_ATTRIBUTE __ISR(_QEI1_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_QEI1_PRIO    (4)
#define AO_IR_QEI1_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_QEI2`

```c
#define AO_IR_QEI2_ATTRIBUTE __ISR(_QEI2_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_QEI2_PRIO    (4)
#define AO_IR_QEI2_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_QEI3`

```c
#define AO_IR_QEI3_ATTRIBUTE __ISR(_QEI3_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_QEI3_PRIO    (4)
#define AO_IR_QEI3_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_QEI4`

```c
#define AO_IR_QEI4_ATTRIBUTE __ISR(_QEI4_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_QEI4_PRIO    (4)
#define AO_IR_QEI4_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_QEI5`

```c
#define AO_IR_QEI5_ATTRIBUTE __ISR(_QEI5_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_QEI5_PRIO    (4)
#define AO_IR_QEI5_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_QEI6`

```c
#define AO_IR_QEI6_ATTRIBUTE __ISR(_QEI6_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_QEI6_PRIO    (4)
#define AO_IR_QEI6_SUBPRIO (0)
```

The interrupt priority and subpriority.

# Functions

## `ao_ir_qei1`

```c
#define ao_ir_qei1_enable()
#define ao_ir_qei1_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_qei1_request()
#define ao_ir_qei1_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_qei1_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_qei1_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_qei2`

```c
#define ao_ir_qei2_enable()
#define ao_ir_qei2_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_qei2_request()
#define ao_ir_qei2_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_qei2_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_qei2_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_qei3`

```c
#define ao_ir_qei3_enable()
#define ao_ir_qei3_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_qei3_request()
#define ao_ir_qei3_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_qei3_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_qei3_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_qei4`

```c
#define ao_ir_qei4_enable()
#define ao_ir_qei4_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_qei4_request()
#define ao_ir_qei4_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_qei4_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_qei4_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_qei5`

```c
#define ao_ir_qei5_enable()
#define ao_ir_qei5_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_qei5_request()
#define ao_ir_qei5_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_qei5_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_qei5_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_qei6`

```c
#define ao_ir_qei6_enable()
#define ao_ir_qei6_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_qei6_request()
#define ao_ir_qei6_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_qei6_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_qei6_is_pending()
```

Checks whether the interrupt is pending.

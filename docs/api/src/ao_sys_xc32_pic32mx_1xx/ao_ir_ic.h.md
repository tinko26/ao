---
author: "Stefan Wagner"
date: 2022-09-05
draft: true
permalink: /api/src/ao_sys_xc32_pic32mx_1xx/ao_ir_ic.h/
toc: true
---

# Include

```c
#include <stdbool.h>
#include <sys/attribs.h>
#include <xc.h>
```

# Configuration

## `AO_IR_IC1`

```c
#define AO_IR_IC1_ATTRIBUTE __ISR(_INPUT_CAPTURE_1_VECTOR, IPL4SOFT)
```

The interrupt handler attribute.

```c
#define AO_IR_IC1_PRIO    (4)
#define AO_IR_IC1_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_IC2`

```c
#define AO_IR_IC2_ATTRIBUTE __ISR(_INPUT_CAPTURE_2_VECTOR, IPL4SOFT)
```

The interrupt handler attribute.

```c
#define AO_IR_IC2_PRIO    (4)
#define AO_IR_IC2_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_IC3`

```c
#define AO_IR_IC3_ATTRIBUTE __ISR(_INPUT_CAPTURE_3_VECTOR, IPL4SOFT)
```

The interrupt handler attribute.

```c
#define AO_IR_IC3_PRIO    (4)
#define AO_IR_IC3_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_IC4`

```c
#define AO_IR_IC4_ATTRIBUTE __ISR(_INPUT_CAPTURE_4_VECTOR, IPL4SOFT)
```

The interrupt handler attribute.

```c
#define AO_IR_IC4_PRIO    (4)
#define AO_IR_IC4_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_IC5`

```c
#define AO_IR_IC5_ATTRIBUTE __ISR(_INPUT_CAPTURE_5_VECTOR, IPL4SOFT)
```

The interrupt handler attribute.

```c
#define AO_IR_IC5_PRIO    (4)
#define AO_IR_IC5_SUBPRIO (0)
```

The interrupt priority and subpriority.

# Functions

## `ao_ir_ic1`

```c
#define ao_ir_ic1_enable()
#define ao_ir_ic1_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_ic1_request()
#define ao_ir_ic1_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_ic1_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_ic1_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_ic1e`

```c
#define ao_ir_ic1e_enable()
#define ao_ir_ic1e_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_ic1e_request()
#define ao_ir_ic1e_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_ic1e_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_ic1e_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_ic2`

```c
#define ao_ir_ic2_enable()
#define ao_ir_ic2_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_ic2_request()
#define ao_ir_ic2_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_ic2_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_ic2_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_ic2e`

```c
#define ao_ir_ic2e_enable()
#define ao_ir_ic2e_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_ic2e_request()
#define ao_ir_ic2e_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_ic2e_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_ic2e_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_ic3`

```c
#define ao_ir_ic3_enable()
#define ao_ir_ic3_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_ic3_request()
#define ao_ir_ic3_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_ic3_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_ic3_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_ic3e`

```c
#define ao_ir_ic3e_enable()
#define ao_ir_ic3e_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_ic3e_request()
#define ao_ir_ic3e_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_ic3e_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_ic3e_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_ic4`

```c
#define ao_ir_ic4_enable()
#define ao_ir_ic4_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_ic4_request()
#define ao_ir_ic4_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_ic4_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_ic4_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_ic4e`

```c
#define ao_ir_ic4e_enable()
#define ao_ir_ic4e_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_ic4e_request()
#define ao_ir_ic4e_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_ic4e_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_ic4e_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_ic5`

```c
#define ao_ir_ic5_enable()
#define ao_ir_ic5_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_ic5_request()
#define ao_ir_ic5_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_ic5_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_ic5_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_ic5e`

```c
#define ao_ir_ic5e_enable()
#define ao_ir_ic5e_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_ic5e_request()
#define ao_ir_ic5e_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_ic5e_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_ic5e_is_pending()
```

Checks whether the interrupt is pending.

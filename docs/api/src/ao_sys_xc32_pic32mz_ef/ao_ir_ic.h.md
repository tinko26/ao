---
author: "Stefan Wagner"
date: 2022-09-05
draft: true
permalink: /api/src/ao_sys_xc32_pic32mz_ef/ao_ir_ic.h/
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
#define AO_IR_IC1_ATTRIBUTE __ISR(_INPUT_CAPTURE_1_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_IC1_PRIO    (4)
#define AO_IR_IC1_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_IC1E`

```c
#define AO_IR_IC1E_ATTRIBUTE __ISR(_INPUT_CAPTURE_1_ERROR_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_IC1E_PRIO    (4)
#define AO_IR_IC1E_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_IC2`

```c
#define AO_IR_IC2_ATTRIBUTE __ISR(_INPUT_CAPTURE_2_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_IC2_PRIO    (4)
#define AO_IR_IC2_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_IC2E`

```c
#define AO_IR_IC2E_ATTRIBUTE __ISR(_INPUT_CAPTURE_2_ERROR_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_IC2E_PRIO    (4)
#define AO_IR_IC2E_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_IC3`

```c
#define AO_IR_IC3_ATTRIBUTE __ISR(_INPUT_CAPTURE_3_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_IC3_PRIO    (4)
#define AO_IR_IC3_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_IC3E`

```c
#define AO_IR_IC3E_ATTRIBUTE __ISR(_INPUT_CAPTURE_3_ERROR_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_IC3E_PRIO    (4)
#define AO_IR_IC3E_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_IC4`

```c
#define AO_IR_IC4_ATTRIBUTE __ISR(_INPUT_CAPTURE_4_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_IC4_PRIO    (4)
#define AO_IR_IC4_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_IC4E`

```c
#define AO_IR_IC4E_ATTRIBUTE __ISR(_INPUT_CAPTURE_4_ERROR_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_IC4E_PRIO    (4)
#define AO_IR_IC4E_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_IC5`

```c
#define AO_IR_IC5_ATTRIBUTE __ISR(_INPUT_CAPTURE_5_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_IC5_PRIO    (4)
#define AO_IR_IC5_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_IC5E`

```c
#define AO_IR_IC5E_ATTRIBUTE __ISR(_INPUT_CAPTURE_5_ERROR_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_IC5E_PRIO    (4)
#define AO_IR_IC5E_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_IC6`

```c
#define AO_IR_IC6_ATTRIBUTE __ISR(_INPUT_CAPTURE_6_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_IC6_PRIO    (4)
#define AO_IR_IC6_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_IC6E`

```c
#define AO_IR_IC6E_ATTRIBUTE __ISR(_INPUT_CAPTURE_6_ERROR_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_IC6E_PRIO    (4)
#define AO_IR_IC6E_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_IC7`

```c
#define AO_IR_IC7_ATTRIBUTE __ISR(_INPUT_CAPTURE_7_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_IC7_PRIO    (4)
#define AO_IR_IC7_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_IC7E`

```c
#define AO_IR_IC7E_ATTRIBUTE __ISR(_INPUT_CAPTURE_7_ERROR_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_IC7E_PRIO    (4)
#define AO_IR_IC7E_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_IC8`

```c
#define AO_IR_IC8_ATTRIBUTE __ISR(_INPUT_CAPTURE_8_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_IC8_PRIO    (4)
#define AO_IR_IC8_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_IC8E`

```c
#define AO_IR_IC8E_ATTRIBUTE __ISR(_INPUT_CAPTURE_8_ERROR_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_IC8E_PRIO    (4)
#define AO_IR_IC8E_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_IC9`

```c
#define AO_IR_IC9_ATTRIBUTE __ISR(_INPUT_CAPTURE_9_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_IC9_PRIO    (4)
#define AO_IR_IC9_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_IC9E`

```c
#define AO_IR_IC9E_ATTRIBUTE __ISR(_INPUT_CAPTURE_9_ERROR_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_IC9E_PRIO    (4)
#define AO_IR_IC9E_SUBPRIO (0)
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

## `ao_ir_ic6`

```c
#define ao_ir_ic6_enable()
#define ao_ir_ic6_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_ic6_request()
#define ao_ir_ic6_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_ic6_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_ic6_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_ic6e`

```c
#define ao_ir_ic6e_enable()
#define ao_ir_ic6e_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_ic6e_request()
#define ao_ir_ic6e_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_ic6e_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_ic6e_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_ic7`

```c
#define ao_ir_ic7_enable()
#define ao_ir_ic7_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_ic7_request()
#define ao_ir_ic7_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_ic7_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_ic7_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_ic7e`

```c
#define ao_ir_ic7e_enable()
#define ao_ir_ic7e_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_ic7e_request()
#define ao_ir_ic7e_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_ic7e_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_ic7e_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_ic8`

```c
#define ao_ir_ic8_enable()
#define ao_ir_ic8_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_ic8_request()
#define ao_ir_ic8_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_ic8_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_ic8_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_ic8e`

```c
#define ao_ir_ic8e_enable()
#define ao_ir_ic8e_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_ic8e_request()
#define ao_ir_ic8e_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_ic8e_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_ic8e_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_ic9`

```c
#define ao_ir_ic9_enable()
#define ao_ir_ic9_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_ic9_request()
#define ao_ir_ic9_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_ic9_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_ic9_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_ic9e`

```c
#define ao_ir_ic9e_enable()
#define ao_ir_ic9e_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_ic9e_request()
#define ao_ir_ic9e_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_ic9e_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_ic9e_is_pending()
```

Checks whether the interrupt is pending.

---
api: true
author: "Stefan Wagner"
date: 2022-09-05
description: "The /src/ao_sys_xc32_pic32mz_da/ao_ir_ic.h file of the ao real-time operating system."
draft: true
permalink: /api/src/ao_sys_xc32_pic32mz_da/ao_ir_ic.h/
subtitle: "Input capture interrupts"
title: "ao_ir_ic.h"
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

The interrupt handler attribute.

```c
#define AO_IR_IC1_ATTRIBUTE __ISR(_INPUT_CAPTURE_1_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_IC1_PRIO      (4)
#define AO_IR_IC1_SUBPRIO   (0)
```

## `AO_IR_IC1E`

The interrupt handler attribute.

```c
#define AO_IR_IC1E_ATTRIBUTE __ISR(_INPUT_CAPTURE_1_ERROR_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_IC1E_PRIO      (4)
#define AO_IR_IC1E_SUBPRIO   (0)
```

## `AO_IR_IC2`

The interrupt handler attribute.

```c
#define AO_IR_IC2_ATTRIBUTE __ISR(_INPUT_CAPTURE_2_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_IC2_PRIO      (4)
#define AO_IR_IC2_SUBPRIO   (0)
```

## `AO_IR_IC2E`

The interrupt handler attribute.

```c
#define AO_IR_IC2E_ATTRIBUTE __ISR(_INPUT_CAPTURE_2_ERROR_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_IC2E_PRIO      (4)
#define AO_IR_IC2E_SUBPRIO   (0)
```

## `AO_IR_IC3`

The interrupt handler attribute.

```c
#define AO_IR_IC3_ATTRIBUTE __ISR(_INPUT_CAPTURE_3_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_IC3_PRIO      (4)
#define AO_IR_IC3_SUBPRIO   (0)
```

## `AO_IR_IC3E`

The interrupt handler attribute.

```c
#define AO_IR_IC3E_ATTRIBUTE __ISR(_INPUT_CAPTURE_3_ERROR_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_IC3E_PRIO      (4)
#define AO_IR_IC3E_SUBPRIO   (0)
```

## `AO_IR_IC4`

The interrupt handler attribute.

```c
#define AO_IR_IC4_ATTRIBUTE __ISR(_INPUT_CAPTURE_4_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_IC4_PRIO      (4)
#define AO_IR_IC4_SUBPRIO   (0)
```

## `AO_IR_IC4E`

The interrupt handler attribute.

```c
#define AO_IR_IC4E_ATTRIBUTE __ISR(_INPUT_CAPTURE_4_ERROR_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_IC4E_PRIO      (4)
#define AO_IR_IC4E_SUBPRIO   (0)
```

## `AO_IR_IC5`

The interrupt handler attribute.

```c
#define AO_IR_IC5_ATTRIBUTE __ISR(_INPUT_CAPTURE_5_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_IC5_PRIO      (4)
#define AO_IR_IC5_SUBPRIO   (0)
```

## `AO_IR_IC5E`

The interrupt handler attribute.

```c
#define AO_IR_IC5E_ATTRIBUTE __ISR(_INPUT_CAPTURE_5_ERROR_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_IC5E_PRIO      (4)
#define AO_IR_IC5E_SUBPRIO   (0)
```

## `AO_IR_IC6`

The interrupt handler attribute.

```c
#define AO_IR_IC6_ATTRIBUTE __ISR(_INPUT_CAPTURE_6_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_IC6_PRIO      (4)
#define AO_IR_IC6_SUBPRIO   (0)
```

## `AO_IR_IC6E`

The interrupt handler attribute.

```c
#define AO_IR_IC6E_ATTRIBUTE __ISR(_INPUT_CAPTURE_6_ERROR_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_IC6E_PRIO      (4)
#define AO_IR_IC6E_SUBPRIO   (0)
```

## `AO_IR_IC7`

The interrupt handler attribute.

```c
#define AO_IR_IC7_ATTRIBUTE __ISR(_INPUT_CAPTURE_7_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_IC7_PRIO      (4)
#define AO_IR_IC7_SUBPRIO   (0)
```

## `AO_IR_IC7E`

The interrupt handler attribute.

```c
#define AO_IR_IC7E_ATTRIBUTE __ISR(_INPUT_CAPTURE_7_ERROR_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_IC7E_PRIO      (4)
#define AO_IR_IC7E_SUBPRIO   (0)
```

## `AO_IR_IC8`

The interrupt handler attribute.

```c
#define AO_IR_IC8_ATTRIBUTE __ISR(_INPUT_CAPTURE_8_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_IC8_PRIO      (4)
#define AO_IR_IC8_SUBPRIO   (0)
```

## `AO_IR_IC8E`

The interrupt handler attribute.

```c
#define AO_IR_IC8E_ATTRIBUTE __ISR(_INPUT_CAPTURE_8_ERROR_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_IC8E_PRIO      (4)
#define AO_IR_IC8E_SUBPRIO   (0)
```

## `AO_IR_IC9`

The interrupt handler attribute.

```c
#define AO_IR_IC9_ATTRIBUTE __ISR(_INPUT_CAPTURE_9_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_IC9_PRIO      (4)
#define AO_IR_IC9_SUBPRIO   (0)
```

## `AO_IR_IC9E`

The interrupt handler attribute.

```c
#define AO_IR_IC9E_ATTRIBUTE __ISR(_INPUT_CAPTURE_9_ERROR_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_IC9E_PRIO      (4)
#define AO_IR_IC9E_SUBPRIO   (0)
```

# Functions

## `ao_ir_ic1`

Enable or disable the interrupt.

```c
#define ao_ir_ic1_enable()
#define ao_ir_ic1_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_ic1_request()
#define ao_ir_ic1_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_ic1_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_ic1_is_pending()
```

## `ao_ir_ic1e`

Enable or disable the interrupt.

```c
#define ao_ir_ic1e_enable()
#define ao_ir_ic1e_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_ic1e_request()
#define ao_ir_ic1e_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_ic1e_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_ic1e_is_pending()
```

## `ao_ir_ic2`

Enable or disable the interrupt.

```c
#define ao_ir_ic2_enable()
#define ao_ir_ic2_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_ic2_request()
#define ao_ir_ic2_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_ic2_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_ic2_is_pending()
```

## `ao_ir_ic2e`

Enable or disable the interrupt.

```c
#define ao_ir_ic2e_enable()
#define ao_ir_ic2e_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_ic2e_request()
#define ao_ir_ic2e_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_ic2e_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_ic2e_is_pending()
```

## `ao_ir_ic3`

Enable or disable the interrupt.

```c
#define ao_ir_ic3_enable()
#define ao_ir_ic3_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_ic3_request()
#define ao_ir_ic3_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_ic3_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_ic3_is_pending()
```

## `ao_ir_ic3e`

Enable or disable the interrupt.

```c
#define ao_ir_ic3e_enable()
#define ao_ir_ic3e_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_ic3e_request()
#define ao_ir_ic3e_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_ic3e_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_ic3e_is_pending()
```

## `ao_ir_ic4`

Enable or disable the interrupt.

```c
#define ao_ir_ic4_enable()
#define ao_ir_ic4_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_ic4_request()
#define ao_ir_ic4_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_ic4_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_ic4_is_pending()
```

## `ao_ir_ic4e`

Enable or disable the interrupt.

```c
#define ao_ir_ic4e_enable()
#define ao_ir_ic4e_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_ic4e_request()
#define ao_ir_ic4e_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_ic4e_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_ic4e_is_pending()
```

## `ao_ir_ic5`

Enable or disable the interrupt.

```c
#define ao_ir_ic5_enable()
#define ao_ir_ic5_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_ic5_request()
#define ao_ir_ic5_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_ic5_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_ic5_is_pending()
```

## `ao_ir_ic5e`

Enable or disable the interrupt.

```c
#define ao_ir_ic5e_enable()
#define ao_ir_ic5e_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_ic5e_request()
#define ao_ir_ic5e_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_ic5e_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_ic5e_is_pending()
```

## `ao_ir_ic6`

Enable or disable the interrupt.

```c
#define ao_ir_ic6_enable()
#define ao_ir_ic6_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_ic6_request()
#define ao_ir_ic6_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_ic6_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_ic6_is_pending()
```

## `ao_ir_ic6e`

Enable or disable the interrupt.

```c
#define ao_ir_ic6e_enable()
#define ao_ir_ic6e_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_ic6e_request()
#define ao_ir_ic6e_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_ic6e_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_ic6e_is_pending()
```

## `ao_ir_ic7`

Enable or disable the interrupt.

```c
#define ao_ir_ic7_enable()
#define ao_ir_ic7_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_ic7_request()
#define ao_ir_ic7_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_ic7_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_ic7_is_pending()
```

## `ao_ir_ic7e`

Enable or disable the interrupt.

```c
#define ao_ir_ic7e_enable()
#define ao_ir_ic7e_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_ic7e_request()
#define ao_ir_ic7e_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_ic7e_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_ic7e_is_pending()
```

## `ao_ir_ic8`

Enable or disable the interrupt.

```c
#define ao_ir_ic8_enable()
#define ao_ir_ic8_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_ic8_request()
#define ao_ir_ic8_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_ic8_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_ic8_is_pending()
```

## `ao_ir_ic8e`

Enable or disable the interrupt.

```c
#define ao_ir_ic8e_enable()
#define ao_ir_ic8e_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_ic8e_request()
#define ao_ir_ic8e_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_ic8e_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_ic8e_is_pending()
```

## `ao_ir_ic9`

Enable or disable the interrupt.

```c
#define ao_ir_ic9_enable()
#define ao_ir_ic9_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_ic9_request()
#define ao_ir_ic9_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_ic9_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_ic9_is_pending()
```

## `ao_ir_ic9e`

Enable or disable the interrupt.

```c
#define ao_ir_ic9e_enable()
#define ao_ir_ic9e_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_ic9e_request()
#define ao_ir_ic9e_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_ic9e_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_ic9e_is_pending()
```

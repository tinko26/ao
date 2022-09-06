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

The interrupt handler attribute.

```c
#define AO_IR_IC1_ATTRIBUTE __ISR(_INPUT_CAPTURE_1_VECTOR, IPL4SOFT)
```

The interrupt priority and subpriority.

```c
#define AO_IR_IC1_PRIO      (4)
#define AO_IR_IC1_SUBPRIO   (0)
```

## `AO_IR_IC2`

The interrupt handler attribute.

```c
#define AO_IR_IC2_ATTRIBUTE __ISR(_INPUT_CAPTURE_2_VECTOR, IPL4SOFT)
```

The interrupt priority and subpriority.

```c
#define AO_IR_IC2_PRIO      (4)
#define AO_IR_IC2_SUBPRIO   (0)
```

## `AO_IR_IC3`

The interrupt handler attribute.

```c
#define AO_IR_IC3_ATTRIBUTE __ISR(_INPUT_CAPTURE_3_VECTOR, IPL4SOFT)
```

The interrupt priority and subpriority.

```c
#define AO_IR_IC3_PRIO      (4)
#define AO_IR_IC3_SUBPRIO   (0)
```

## `AO_IR_IC4`

The interrupt handler attribute.

```c
#define AO_IR_IC4_ATTRIBUTE __ISR(_INPUT_CAPTURE_4_VECTOR, IPL4SOFT)
```

The interrupt priority and subpriority.

```c
#define AO_IR_IC4_PRIO      (4)
#define AO_IR_IC4_SUBPRIO   (0)
```

## `AO_IR_IC5`

The interrupt handler attribute.

```c
#define AO_IR_IC5_ATTRIBUTE __ISR(_INPUT_CAPTURE_5_VECTOR, IPL4SOFT)
```

The interrupt priority and subpriority.

```c
#define AO_IR_IC5_PRIO      (4)
#define AO_IR_IC5_SUBPRIO   (0)
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

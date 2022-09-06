---
author: "Stefan Wagner"
date: 2022-09-05
draft: true
permalink: /api/src/ao_sys_xc32_pic32mx_1xx_xlp/ao_ir_t.h/
toc: true
---

# Include

```c
#include <stdbool.h>
#include <sys/attribs.h>
#include <xc.h>
```

# Configuration

## `AO_IR_T1`

The interrupt handler attribute.

```c
#define AO_IR_T1_ATTRIBUTE __ISR(_TIMER_1_VECTOR, IPL4SOFT)
```

The interrupt priority and subpriority.

```c
#define AO_IR_T1_PRIO      (4)
#define AO_IR_T1_SUBPRIO   (0)
```

## `AO_IR_T2`

The interrupt handler attribute.

```c
#define AO_IR_T2_ATTRIBUTE __ISR(_TIMER_2_VECTOR, IPL4SOFT)
```

The interrupt priority and subpriority.

```c
#define AO_IR_T2_PRIO      (4)
#define AO_IR_T2_SUBPRIO   (0)
```

## `AO_IR_T3`

The interrupt handler attribute.

```c
#define AO_IR_T3_ATTRIBUTE __ISR(_TIMER_3_VECTOR, IPL4SOFT)
```

The interrupt priority and subpriority.

```c
#define AO_IR_T3_PRIO      (4)
#define AO_IR_T3_SUBPRIO   (0)
```

## `AO_IR_T4`

The interrupt handler attribute.

```c
#define AO_IR_T4_ATTRIBUTE __ISR(_TIMER_4_VECTOR, IPL4SOFT)
```

The interrupt priority and subpriority.

```c
#define AO_IR_T4_PRIO      (4)
#define AO_IR_T4_SUBPRIO   (0)
```

## `AO_IR_T5`

The interrupt handler attribute.

```c
#define AO_IR_T5_ATTRIBUTE __ISR(_TIMER_5_VECTOR, IPL4SOFT)
```

The interrupt priority and subpriority.

```c
#define AO_IR_T5_PRIO      (4)
#define AO_IR_T5_SUBPRIO   (0)
```

# Functions

## `ao_ir_t1`

Enable or disable the interrupt.

```c
#define ao_ir_t1_enable()
#define ao_ir_t1_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_t1_request()
#define ao_ir_t1_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_t1_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_t1_is_pending()
```

## `ao_ir_t2`

Enable or disable the interrupt.

```c
#define ao_ir_t2_enable()
#define ao_ir_t2_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_t2_request()
#define ao_ir_t2_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_t2_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_t2_is_pending()
```

## `ao_ir_t3`

Enable or disable the interrupt.

```c
#define ao_ir_t3_enable()
#define ao_ir_t3_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_t3_request()
#define ao_ir_t3_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_t3_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_t3_is_pending()
```

## `ao_ir_t4`

Enable or disable the interrupt.

```c
#define ao_ir_t4_enable()
#define ao_ir_t4_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_t4_request()
#define ao_ir_t4_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_t4_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_t4_is_pending()
```

## `ao_ir_t5`

Enable or disable the interrupt.

```c
#define ao_ir_t5_enable()
#define ao_ir_t5_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_t5_request()
#define ao_ir_t5_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_t5_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_t5_is_pending()
```

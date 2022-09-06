---
author: "Stefan Wagner"
date: 2022-09-05
draft: true
permalink: /api/src/ao_sys_xc32_pic32mk_gp/ao_ir_oc.h/
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

The interrupt handler attribute.

```c
#define AO_IR_OC1_ATTRIBUTE __ISR(_OUTPUT_COMPARE_1_VECTOR, IPL4SOFT)
```

The interrupt priority and subpriority.

```c
#define AO_IR_OC1_PRIO      (4)
#define AO_IR_OC1_SUBPRIO   (0)
```

## `AO_IR_OC10`

The interrupt handler attribute.

```c
#define AO_IR_OC10_ATTRIBUTE __ISR(_OUTPUT_COMPARE_10_VECTOR, IPL4SOFT)
```

The interrupt priority and subpriority.

```c
#define AO_IR_OC10_PRIO      (4)
#define AO_IR_OC10_SUBPRIO   (0)
```

## `AO_IR_OC11`

The interrupt handler attribute.

```c
#define AO_IR_OC11_ATTRIBUTE __ISR(_OUTPUT_COMPARE_11_VECTOR, IPL4SOFT)
```

The interrupt priority and subpriority.

```c
#define AO_IR_OC11_PRIO      (4)
#define AO_IR_OC11_SUBPRIO   (0)
```

## `AO_IR_OC12`

The interrupt handler attribute.

```c
#define AO_IR_OC12_ATTRIBUTE __ISR(_OUTPUT_COMPARE_12_VECTOR, IPL4SOFT)
```

The interrupt priority and subpriority.

```c
#define AO_IR_OC12_PRIO      (4)
#define AO_IR_OC12_SUBPRIO   (0)
```

## `AO_IR_OC13`

The interrupt handler attribute.

```c
#define AO_IR_OC13_ATTRIBUTE __ISR(_OUTPUT_COMPARE_13_VECTOR, IPL4SOFT)
```

The interrupt priority and subpriority.

```c
#define AO_IR_OC13_PRIO      (4)
#define AO_IR_OC13_SUBPRIO   (0)
```

## `AO_IR_OC14`

The interrupt handler attribute.

```c
#define AO_IR_OC14_ATTRIBUTE __ISR(_OUTPUT_COMPARE_14_VECTOR, IPL4SOFT)
```

The interrupt priority and subpriority.

```c
#define AO_IR_OC14_PRIO      (4)
#define AO_IR_OC14_SUBPRIO   (0)
```

## `AO_IR_OC15`

The interrupt handler attribute.

```c
#define AO_IR_OC15_ATTRIBUTE __ISR(_OUTPUT_COMPARE_15_VECTOR, IPL4SOFT)
```

The interrupt priority and subpriority.

```c
#define AO_IR_OC15_PRIO      (4)
#define AO_IR_OC15_SUBPRIO   (0)
```

## `AO_IR_OC16`

The interrupt handler attribute.

```c
#define AO_IR_OC16_ATTRIBUTE __ISR(_OUTPUT_COMPARE_16_VECTOR, IPL4SOFT)
```

The interrupt priority and subpriority.

```c
#define AO_IR_OC16_PRIO      (4)
#define AO_IR_OC16_SUBPRIO   (0)
```

## `AO_IR_OC2`

The interrupt handler attribute.

```c
#define AO_IR_OC2_ATTRIBUTE __ISR(_OUTPUT_COMPARE_2_VECTOR, IPL4SOFT)
```

The interrupt priority and subpriority.

```c
#define AO_IR_OC2_PRIO      (4)
#define AO_IR_OC2_SUBPRIO   (0)
```

## `AO_IR_OC3`

The interrupt handler attribute.

```c
#define AO_IR_OC3_ATTRIBUTE __ISR(_OUTPUT_COMPARE_3_VECTOR, IPL4SOFT)
```

The interrupt priority and subpriority.

```c
#define AO_IR_OC3_PRIO      (4)
#define AO_IR_OC3_SUBPRIO   (0)
```

## `AO_IR_OC4`

The interrupt handler attribute.

```c
#define AO_IR_OC4_ATTRIBUTE __ISR(_OUTPUT_COMPARE_4_VECTOR, IPL4SOFT)
```

The interrupt priority and subpriority.

```c
#define AO_IR_OC4_PRIO      (4)
#define AO_IR_OC4_SUBPRIO   (0)
```

## `AO_IR_OC5`

The interrupt handler attribute.

```c
#define AO_IR_OC5_ATTRIBUTE __ISR(_OUTPUT_COMPARE_5_VECTOR, IPL4SOFT)
```

The interrupt priority and subpriority.

```c
#define AO_IR_OC5_PRIO      (4)
#define AO_IR_OC5_SUBPRIO   (0)
```

## `AO_IR_OC6`

The interrupt handler attribute.

```c
#define AO_IR_OC6_ATTRIBUTE __ISR(_OUTPUT_COMPARE_6_VECTOR, IPL4SOFT)
```

The interrupt priority and subpriority.

```c
#define AO_IR_OC6_PRIO      (4)
#define AO_IR_OC6_SUBPRIO   (0)
```

## `AO_IR_OC7`

The interrupt handler attribute.

```c
#define AO_IR_OC7_ATTRIBUTE __ISR(_OUTPUT_COMPARE_7_VECTOR, IPL4SOFT)
```

The interrupt priority and subpriority.

```c
#define AO_IR_OC7_PRIO      (4)
#define AO_IR_OC7_SUBPRIO   (0)
```

## `AO_IR_OC8`

The interrupt handler attribute.

```c
#define AO_IR_OC8_ATTRIBUTE __ISR(_OUTPUT_COMPARE_8_VECTOR, IPL4SOFT)
```

The interrupt priority and subpriority.

```c
#define AO_IR_OC8_PRIO      (4)
#define AO_IR_OC8_SUBPRIO   (0)
```

## `AO_IR_OC9`

The interrupt handler attribute.

```c
#define AO_IR_OC9_ATTRIBUTE __ISR(_OUTPUT_COMPARE_9_VECTOR, IPL4SOFT)
```

The interrupt priority and subpriority.

```c
#define AO_IR_OC9_PRIO      (4)
#define AO_IR_OC9_SUBPRIO   (0)
```

# Functions

## `ao_ir_oc1`

Enable or disable the interrupt.

```c
#define ao_ir_oc1_enable()
#define ao_ir_oc1_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_oc1_request()
#define ao_ir_oc1_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_oc1_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_oc1_is_pending()
```

## `ao_ir_oc2`

Enable or disable the interrupt.

```c
#define ao_ir_oc2_enable()
#define ao_ir_oc2_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_oc2_request()
#define ao_ir_oc2_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_oc2_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_oc2_is_pending()
```

## `ao_ir_oc3`

Enable or disable the interrupt.

```c
#define ao_ir_oc3_enable()
#define ao_ir_oc3_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_oc3_request()
#define ao_ir_oc3_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_oc3_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_oc3_is_pending()
```

## `ao_ir_oc4`

Enable or disable the interrupt.

```c
#define ao_ir_oc4_enable()
#define ao_ir_oc4_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_oc4_request()
#define ao_ir_oc4_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_oc4_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_oc4_is_pending()
```

## `ao_ir_oc5`

Enable or disable the interrupt.

```c
#define ao_ir_oc5_enable()
#define ao_ir_oc5_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_oc5_request()
#define ao_ir_oc5_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_oc5_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_oc5_is_pending()
```

## `ao_ir_oc6`

Enable or disable the interrupt.

```c
#define ao_ir_oc6_enable()
#define ao_ir_oc6_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_oc6_request()
#define ao_ir_oc6_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_oc6_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_oc6_is_pending()
```

## `ao_ir_oc7`

Enable or disable the interrupt.

```c
#define ao_ir_oc7_enable()
#define ao_ir_oc7_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_oc7_request()
#define ao_ir_oc7_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_oc7_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_oc7_is_pending()
```

## `ao_ir_oc8`

Enable or disable the interrupt.

```c
#define ao_ir_oc8_enable()
#define ao_ir_oc8_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_oc8_request()
#define ao_ir_oc8_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_oc8_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_oc8_is_pending()
```

## `ao_ir_oc9`

Enable or disable the interrupt.

```c
#define ao_ir_oc9_enable()
#define ao_ir_oc9_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_oc9_request()
#define ao_ir_oc9_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_oc9_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_oc9_is_pending()
```

## `ao_ir_oc10`

Enable or disable the interrupt.

```c
#define ao_ir_oc10_enable()
#define ao_ir_oc10_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_oc10_request()
#define ao_ir_oc10_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_oc10_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_oc10_is_pending()
```

## `ao_ir_oc11`

Enable or disable the interrupt.

```c
#define ao_ir_oc11_enable()
#define ao_ir_oc11_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_oc11_request()
#define ao_ir_oc11_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_oc11_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_oc11_is_pending()
```

## `ao_ir_oc12`

Enable or disable the interrupt.

```c
#define ao_ir_oc12_enable()
#define ao_ir_oc12_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_oc12_request()
#define ao_ir_oc12_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_oc12_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_oc12_is_pending()
```

## `ao_ir_oc13`

Enable or disable the interrupt.

```c
#define ao_ir_oc13_enable()
#define ao_ir_oc13_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_oc13_request()
#define ao_ir_oc13_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_oc13_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_oc13_is_pending()
```

## `ao_ir_oc14`

Enable or disable the interrupt.

```c
#define ao_ir_oc14_enable()
#define ao_ir_oc14_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_oc14_request()
#define ao_ir_oc14_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_oc14_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_oc14_is_pending()
```

## `ao_ir_oc15`

Enable or disable the interrupt.

```c
#define ao_ir_oc15_enable()
#define ao_ir_oc15_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_oc15_request()
#define ao_ir_oc15_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_oc15_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_oc15_is_pending()
```

## `ao_ir_oc16`

Enable or disable the interrupt.

```c
#define ao_ir_oc16_enable()
#define ao_ir_oc16_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_oc16_request()
#define ao_ir_oc16_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_oc16_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_oc16_is_pending()
```

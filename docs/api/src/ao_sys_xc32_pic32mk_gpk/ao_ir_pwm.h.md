---
api: true
author: "Stefan Wagner"
date: 2022-09-05
description: "The /src/ao_sys_xc32_pic32mk_gpk/ao_ir_pwm.h file of the ao real-time operating system."
draft: true
permalink: /api/src/ao_sys_xc32_pic32mk_gpk/ao_ir_pwm.h/
subtitle: "PWM interrupts"
title: "ao_ir_pwm.h"
toc: true
---

# Include

```c
#include <stdbool.h>
#include <sys/attribs.h>
#include <xc.h>
```

# Configuration

## `AO_IR_PWM1`

The interrupt handler attribute.

```c
#define AO_IR_PWM1_ATTRIBUTE __ISR(_PWM1_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_PWM1_PRIO      (4)
#define AO_IR_PWM1_SUBPRIO   (0)
```

## `AO_IR_PWM10`

The interrupt handler attribute.

```c
#define AO_IR_PWM10_ATTRIBUTE __ISR(_PWM10_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_PWM10_PRIO      (4)
#define AO_IR_PWM10_SUBPRIO   (0)
```

## `AO_IR_PWM11`

The interrupt handler attribute.

```c
#define AO_IR_PWM11_ATTRIBUTE __ISR(_PWM11_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_PWM11_PRIO      (4)
#define AO_IR_PWM11_SUBPRIO   (0)
```

## `AO_IR_PWM12`

The interrupt handler attribute.

```c
#define AO_IR_PWM12_ATTRIBUTE __ISR(_PWM12_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_PWM12_PRIO      (4)
#define AO_IR_PWM12_SUBPRIO   (0)
```

## `AO_IR_PWM2`

The interrupt handler attribute.

```c
#define AO_IR_PWM2_ATTRIBUTE __ISR(_PWM2_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_PWM2_PRIO      (4)
#define AO_IR_PWM2_SUBPRIO   (0)
```

## `AO_IR_PWM3`

The interrupt handler attribute.

```c
#define AO_IR_PWM3_ATTRIBUTE __ISR(_PWM3_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_PWM3_PRIO      (4)
#define AO_IR_PWM3_SUBPRIO   (0)
```

## `AO_IR_PWM4`

The interrupt handler attribute.

```c
#define AO_IR_PWM4_ATTRIBUTE __ISR(_PWM4_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_PWM4_PRIO      (4)
#define AO_IR_PWM4_SUBPRIO   (0)
```

## `AO_IR_PWM5`

The interrupt handler attribute.

```c
#define AO_IR_PWM5_ATTRIBUTE __ISR(_PWM5_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_PWM5_PRIO      (4)
#define AO_IR_PWM5_SUBPRIO   (0)
```

## `AO_IR_PWM6`

The interrupt handler attribute.

```c
#define AO_IR_PWM6_ATTRIBUTE __ISR(_PWM6_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_PWM6_PRIO      (4)
#define AO_IR_PWM6_SUBPRIO   (0)
```

## `AO_IR_PWM7`

The interrupt handler attribute.

```c
#define AO_IR_PWM7_ATTRIBUTE __ISR(_PWM7_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_PWM7_PRIO      (4)
#define AO_IR_PWM7_SUBPRIO   (0)
```

## `AO_IR_PWM8`

The interrupt handler attribute.

```c
#define AO_IR_PWM8_ATTRIBUTE __ISR(_PWM8_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_PWM8_PRIO      (4)
#define AO_IR_PWM8_SUBPRIO   (0)
```

## `AO_IR_PWM9`

The interrupt handler attribute.

```c
#define AO_IR_PWM9_ATTRIBUTE __ISR(_PWM9_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_PWM9_PRIO      (4)
#define AO_IR_PWM9_SUBPRIO   (0)
```

## `AO_IR_PWMPEVT`

The interrupt handler attribute.

```c
#define AO_IR_PWMPEVT_ATTRIBUTE __ISR(_PWM_PRI_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_PWMPEVT_PRIO      (4)
#define AO_IR_PWMPEVT_SUBPRIO   (0)
```

## `AO_IR_PWMSEVT`

The interrupt handler attribute.

```c
#define AO_IR_PWMSEVT_ATTRIBUTE __ISR(_PWM_SEC_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_PWMSEVT_PRIO      (4)
#define AO_IR_PWMSEVT_SUBPRIO   (0)
```

# Functions

## `ao_ir_pwm1`

Enable or disable the interrupt.

```c
#define ao_ir_pwm1_enable()
#define ao_ir_pwm1_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_pwm1_request()
#define ao_ir_pwm1_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_pwm1_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_pwm1_is_pending()
```

## `ao_ir_pwm2`

Enable or disable the interrupt.

```c
#define ao_ir_pwm2_enable()
#define ao_ir_pwm2_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_pwm2_request()
#define ao_ir_pwm2_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_pwm2_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_pwm2_is_pending()
```

## `ao_ir_pwm3`

Enable or disable the interrupt.

```c
#define ao_ir_pwm3_enable()
#define ao_ir_pwm3_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_pwm3_request()
#define ao_ir_pwm3_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_pwm3_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_pwm3_is_pending()
```

## `ao_ir_pwm4`

Enable or disable the interrupt.

```c
#define ao_ir_pwm4_enable()
#define ao_ir_pwm4_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_pwm4_request()
#define ao_ir_pwm4_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_pwm4_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_pwm4_is_pending()
```

## `ao_ir_pwm5`

Enable or disable the interrupt.

```c
#define ao_ir_pwm5_enable()
#define ao_ir_pwm5_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_pwm5_request()
#define ao_ir_pwm5_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_pwm5_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_pwm5_is_pending()
```

## `ao_ir_pwm6`

Enable or disable the interrupt.

```c
#define ao_ir_pwm6_enable()
#define ao_ir_pwm6_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_pwm6_request()
#define ao_ir_pwm6_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_pwm6_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_pwm6_is_pending()
```

## `ao_ir_pwm7`

Enable or disable the interrupt.

```c
#define ao_ir_pwm7_enable()
#define ao_ir_pwm7_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_pwm7_request()
#define ao_ir_pwm7_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_pwm7_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_pwm7_is_pending()
```

## `ao_ir_pwm8`

Enable or disable the interrupt.

```c
#define ao_ir_pwm8_enable()
#define ao_ir_pwm8_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_pwm8_request()
#define ao_ir_pwm8_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_pwm8_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_pwm8_is_pending()
```

## `ao_ir_pwm9`

Enable or disable the interrupt.

```c
#define ao_ir_pwm9_enable()
#define ao_ir_pwm9_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_pwm9_request()
#define ao_ir_pwm9_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_pwm9_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_pwm9_is_pending()
```

## `ao_ir_pwm10`

Enable or disable the interrupt.

```c
#define ao_ir_pwm10_enable()
#define ao_ir_pwm10_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_pwm10_request()
#define ao_ir_pwm10_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_pwm10_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_pwm10_is_pending()
```

## `ao_ir_pwm11`

Enable or disable the interrupt.

```c
#define ao_ir_pwm11_enable()
#define ao_ir_pwm11_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_pwm11_request()
#define ao_ir_pwm11_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_pwm11_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_pwm11_is_pending()
```

## `ao_ir_pwm12`

Enable or disable the interrupt.

```c
#define ao_ir_pwm12_enable()
#define ao_ir_pwm12_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_pwm12_request()
#define ao_ir_pwm12_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_pwm12_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_pwm12_is_pending()
```

## `ao_ir_pwmpevt`

Enable or disable the interrupt.

```c
#define ao_ir_pwmpevt_enable()
#define ao_ir_pwmpevt_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_pwmpevt_request()
#define ao_ir_pwmpevt_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_pwmpevt_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_pwmpevt_is_pending()
```

## `ao_ir_pwmsevt`

Enable or disable the interrupt.

```c
#define ao_ir_pwmsevt_enable()
#define ao_ir_pwmsevt_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_pwmsevt_request()
#define ao_ir_pwmsevt_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_pwmsevt_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_pwmsevt_is_pending()
```

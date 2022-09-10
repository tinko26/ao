---
author: "Stefan Wagner"
date: 2022-09-05
draft: true
permalink: /api/src/ao_sys_xc32_pic32mk_gpk/ao_ir_pwm.h/
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

```c
#define AO_IR_PWM1_ATTRIBUTE __ISR(_PWM1_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_PWM1_PRIO    (4)
#define AO_IR_PWM1_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_PWM10`

```c
#define AO_IR_PWM10_ATTRIBUTE __ISR(_PWM10_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_PWM10_PRIO    (4)
#define AO_IR_PWM10_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_PWM11`

```c
#define AO_IR_PWM11_ATTRIBUTE __ISR(_PWM11_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_PWM11_PRIO    (4)
#define AO_IR_PWM11_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_PWM12`

```c
#define AO_IR_PWM12_ATTRIBUTE __ISR(_PWM12_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_PWM12_PRIO    (4)
#define AO_IR_PWM12_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_PWM2`

```c
#define AO_IR_PWM2_ATTRIBUTE __ISR(_PWM2_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_PWM2_PRIO    (4)
#define AO_IR_PWM2_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_PWM3`

```c
#define AO_IR_PWM3_ATTRIBUTE __ISR(_PWM3_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_PWM3_PRIO    (4)
#define AO_IR_PWM3_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_PWM4`

```c
#define AO_IR_PWM4_ATTRIBUTE __ISR(_PWM4_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_PWM4_PRIO    (4)
#define AO_IR_PWM4_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_PWM5`

```c
#define AO_IR_PWM5_ATTRIBUTE __ISR(_PWM5_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_PWM5_PRIO    (4)
#define AO_IR_PWM5_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_PWM6`

```c
#define AO_IR_PWM6_ATTRIBUTE __ISR(_PWM6_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_PWM6_PRIO    (4)
#define AO_IR_PWM6_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_PWM7`

```c
#define AO_IR_PWM7_ATTRIBUTE __ISR(_PWM7_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_PWM7_PRIO    (4)
#define AO_IR_PWM7_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_PWM8`

```c
#define AO_IR_PWM8_ATTRIBUTE __ISR(_PWM8_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_PWM8_PRIO    (4)
#define AO_IR_PWM8_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_PWM9`

```c
#define AO_IR_PWM9_ATTRIBUTE __ISR(_PWM9_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_PWM9_PRIO    (4)
#define AO_IR_PWM9_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_PWMPEVT`

```c
#define AO_IR_PWMPEVT_ATTRIBUTE __ISR(_PWM_PRI_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_PWMPEVT_PRIO    (4)
#define AO_IR_PWMPEVT_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_PWMSEVT`

```c
#define AO_IR_PWMSEVT_ATTRIBUTE __ISR(_PWM_SEC_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_PWMSEVT_PRIO    (4)
#define AO_IR_PWMSEVT_SUBPRIO (0)
```

The interrupt priority and subpriority.

# Functions

## `ao_ir_pwm1`

```c
#define ao_ir_pwm1_enable()
#define ao_ir_pwm1_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_pwm1_request()
#define ao_ir_pwm1_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_pwm1_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_pwm1_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_pwm2`

```c
#define ao_ir_pwm2_enable()
#define ao_ir_pwm2_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_pwm2_request()
#define ao_ir_pwm2_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_pwm2_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_pwm2_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_pwm3`

```c
#define ao_ir_pwm3_enable()
#define ao_ir_pwm3_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_pwm3_request()
#define ao_ir_pwm3_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_pwm3_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_pwm3_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_pwm4`

```c
#define ao_ir_pwm4_enable()
#define ao_ir_pwm4_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_pwm4_request()
#define ao_ir_pwm4_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_pwm4_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_pwm4_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_pwm5`

```c
#define ao_ir_pwm5_enable()
#define ao_ir_pwm5_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_pwm5_request()
#define ao_ir_pwm5_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_pwm5_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_pwm5_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_pwm6`

```c
#define ao_ir_pwm6_enable()
#define ao_ir_pwm6_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_pwm6_request()
#define ao_ir_pwm6_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_pwm6_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_pwm6_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_pwm7`

```c
#define ao_ir_pwm7_enable()
#define ao_ir_pwm7_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_pwm7_request()
#define ao_ir_pwm7_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_pwm7_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_pwm7_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_pwm8`

```c
#define ao_ir_pwm8_enable()
#define ao_ir_pwm8_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_pwm8_request()
#define ao_ir_pwm8_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_pwm8_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_pwm8_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_pwm9`

```c
#define ao_ir_pwm9_enable()
#define ao_ir_pwm9_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_pwm9_request()
#define ao_ir_pwm9_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_pwm9_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_pwm9_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_pwm10`

```c
#define ao_ir_pwm10_enable()
#define ao_ir_pwm10_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_pwm10_request()
#define ao_ir_pwm10_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_pwm10_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_pwm10_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_pwm11`

```c
#define ao_ir_pwm11_enable()
#define ao_ir_pwm11_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_pwm11_request()
#define ao_ir_pwm11_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_pwm11_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_pwm11_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_pwm12`

```c
#define ao_ir_pwm12_enable()
#define ao_ir_pwm12_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_pwm12_request()
#define ao_ir_pwm12_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_pwm12_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_pwm12_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_pwmpevt`

```c
#define ao_ir_pwmpevt_enable()
#define ao_ir_pwmpevt_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_pwmpevt_request()
#define ao_ir_pwmpevt_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_pwmpevt_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_pwmpevt_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_pwmsevt`

```c
#define ao_ir_pwmsevt_enable()
#define ao_ir_pwmsevt_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_pwmsevt_request()
#define ao_ir_pwmsevt_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_pwmsevt_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_pwmsevt_is_pending()
```

Checks whether the interrupt is pending.

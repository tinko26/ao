---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The /src/ao_sys_xc32_pic32mk_gpk/ao_ir_pwm.h file of the ao real-time operating system."
draft: true
permalink: /api/src/ao_sys_xc32_pic32mk_gpk/ao_ir_pwm.h/
subtitle: ""
title: "ao_ir_pwm.h"
toc: true
---

# Include

```c
#include <stdbool.h>
#include <sys/attribs.h>
#include <xc.h>
```

# Constants

```c
#define AO_IR_PWM1_ATTRIBUTE __ISR(_PWM1_VECTOR, IPL4SRS)
```

```c
#define AO_IR_PWM1_PRIO (4)
```

```c
#define AO_IR_PWM1_SUBPRIO (0)
```

```c
#define AO_IR_PWM10_ATTRIBUTE __ISR(_PWM10_VECTOR, IPL4SRS)
```

```c
#define AO_IR_PWM10_PRIO (4)
```

```c
#define AO_IR_PWM10_SUBPRIO (0)
```

```c
#define AO_IR_PWM11_ATTRIBUTE __ISR(_PWM11_VECTOR, IPL4SRS)
```

```c
#define AO_IR_PWM11_PRIO (4)
```

```c
#define AO_IR_PWM11_SUBPRIO (0)
```

```c
#define AO_IR_PWM12_ATTRIBUTE __ISR(_PWM12_VECTOR, IPL4SRS)
```

```c
#define AO_IR_PWM12_PRIO (4)
```

```c
#define AO_IR_PWM12_SUBPRIO (0)
```

```c
#define AO_IR_PWM2_ATTRIBUTE __ISR(_PWM2_VECTOR, IPL4SRS)
```

```c
#define AO_IR_PWM2_PRIO (4)
```

```c
#define AO_IR_PWM2_SUBPRIO (0)
```

```c
#define AO_IR_PWM3_ATTRIBUTE __ISR(_PWM3_VECTOR, IPL4SRS)
```

```c
#define AO_IR_PWM3_PRIO (4)
```

```c
#define AO_IR_PWM3_SUBPRIO (0)
```

```c
#define AO_IR_PWM4_ATTRIBUTE __ISR(_PWM4_VECTOR, IPL4SRS)
```

```c
#define AO_IR_PWM4_PRIO (4)
```

```c
#define AO_IR_PWM4_SUBPRIO (0)
```

```c
#define AO_IR_PWM5_ATTRIBUTE __ISR(_PWM5_VECTOR, IPL4SRS)
```

```c
#define AO_IR_PWM5_PRIO (4)
```

```c
#define AO_IR_PWM5_SUBPRIO (0)
```

```c
#define AO_IR_PWM6_ATTRIBUTE __ISR(_PWM6_VECTOR, IPL4SRS)
```

```c
#define AO_IR_PWM6_PRIO (4)
```

```c
#define AO_IR_PWM6_SUBPRIO (0)
```

```c
#define AO_IR_PWM7_ATTRIBUTE __ISR(_PWM7_VECTOR, IPL4SRS)
```

```c
#define AO_IR_PWM7_PRIO (4)
```

```c
#define AO_IR_PWM7_SUBPRIO (0)
```

```c
#define AO_IR_PWM8_ATTRIBUTE __ISR(_PWM8_VECTOR, IPL4SRS)
```

```c
#define AO_IR_PWM8_PRIO (4)
```

```c
#define AO_IR_PWM8_SUBPRIO (0)
```

```c
#define AO_IR_PWM9_ATTRIBUTE __ISR(_PWM9_VECTOR, IPL4SRS)
```

```c
#define AO_IR_PWM9_PRIO (4)
```

```c
#define AO_IR_PWM9_SUBPRIO (0)
```

```c
#define AO_IR_PWMPEVT_ATTRIBUTE __ISR(_PWM_PRI_VECTOR, IPL4SRS)
```

```c
#define AO_IR_PWMPEVT_PRIO (4)
```

```c
#define AO_IR_PWMPEVT_SUBPRIO (0)
```

```c
#define AO_IR_PWMSEVT_ATTRIBUTE __ISR(_PWM_SEC_VECTOR, IPL4SRS)
```

```c
#define AO_IR_PWMSEVT_PRIO (4)
```

```c
#define AO_IR_PWMSEVT_SUBPRIO (0)
```

# Functions

```c
#define ao_ir_pwm1_disable()
```

```c
#define ao_ir_pwm1_enable()
```

```c
#define ao_ir_pwm1_is_enabled()
```

```c
#define ao_ir_pwm1_is_pending()
```

```c
#define ao_ir_pwm1_reply()
```

```c
#define ao_ir_pwm1_request()
```

```c
#define ao_ir_pwm2_disable()
```

```c
#define ao_ir_pwm2_enable()
```

```c
#define ao_ir_pwm2_is_enabled()
```

```c
#define ao_ir_pwm2_is_pending()
```

```c
#define ao_ir_pwm2_reply()
```

```c
#define ao_ir_pwm2_request()
```

```c
#define ao_ir_pwm3_disable()
```

```c
#define ao_ir_pwm3_enable()
```

```c
#define ao_ir_pwm3_is_enabled()
```

```c
#define ao_ir_pwm3_is_pending()
```

```c
#define ao_ir_pwm3_reply()
```

```c
#define ao_ir_pwm3_request()
```

```c
#define ao_ir_pwm4_disable()
```

```c
#define ao_ir_pwm4_enable()
```

```c
#define ao_ir_pwm4_is_enabled()
```

```c
#define ao_ir_pwm4_is_pending()
```

```c
#define ao_ir_pwm4_reply()
```

```c
#define ao_ir_pwm4_request()
```

```c
#define ao_ir_pwm5_disable()
```

```c
#define ao_ir_pwm5_enable()
```

```c
#define ao_ir_pwm5_is_enabled()
```

```c
#define ao_ir_pwm5_is_pending()
```

```c
#define ao_ir_pwm5_reply()
```

```c
#define ao_ir_pwm5_request()
```

```c
#define ao_ir_pwm6_disable()
```

```c
#define ao_ir_pwm6_enable()
```

```c
#define ao_ir_pwm6_is_enabled()
```

```c
#define ao_ir_pwm6_is_pending()
```

```c
#define ao_ir_pwm6_reply()
```

```c
#define ao_ir_pwm6_request()
```

```c
#define ao_ir_pwm7_disable()
```

```c
#define ao_ir_pwm7_enable()
```

```c
#define ao_ir_pwm7_is_enabled()
```

```c
#define ao_ir_pwm7_is_pending()
```

```c
#define ao_ir_pwm7_reply()
```

```c
#define ao_ir_pwm7_request()
```

```c
#define ao_ir_pwm8_disable()
```

```c
#define ao_ir_pwm8_enable()
```

```c
#define ao_ir_pwm8_is_enabled()
```

```c
#define ao_ir_pwm8_is_pending()
```

```c
#define ao_ir_pwm8_reply()
```

```c
#define ao_ir_pwm8_request()
```

```c
#define ao_ir_pwm9_disable()
```

```c
#define ao_ir_pwm9_enable()
```

```c
#define ao_ir_pwm9_is_enabled()
```

```c
#define ao_ir_pwm9_is_pending()
```

```c
#define ao_ir_pwm9_reply()
```

```c
#define ao_ir_pwm9_request()
```

```c
#define ao_ir_pwm10_disable()
```

```c
#define ao_ir_pwm10_enable()
```

```c
#define ao_ir_pwm10_is_enabled()
```

```c
#define ao_ir_pwm10_is_pending()
```

```c
#define ao_ir_pwm10_reply()
```

```c
#define ao_ir_pwm10_request()
```

```c
#define ao_ir_pwm11_disable()
```

```c
#define ao_ir_pwm11_enable()
```

```c
#define ao_ir_pwm11_is_enabled()
```

```c
#define ao_ir_pwm11_is_pending()
```

```c
#define ao_ir_pwm11_reply()
```

```c
#define ao_ir_pwm11_request()
```

```c
#define ao_ir_pwm12_disable()
```

```c
#define ao_ir_pwm12_enable()
```

```c
#define ao_ir_pwm12_is_enabled()
```

```c
#define ao_ir_pwm12_is_pending()
```

```c
#define ao_ir_pwm12_reply()
```

```c
#define ao_ir_pwm12_request()
```

```c
#define ao_ir_pwmpevt_disable()
```

```c
#define ao_ir_pwmpevt_enable()
```

```c
#define ao_ir_pwmpevt_is_enabled()
```

```c
#define ao_ir_pwmpevt_is_pending()
```

```c
#define ao_ir_pwmpevt_reply()
```

```c
#define ao_ir_pwmpevt_request()
```

```c
#define ao_ir_pwmsevt_disable()
```

```c
#define ao_ir_pwmsevt_enable()
```

```c
#define ao_ir_pwmsevt_is_enabled()
```

```c
#define ao_ir_pwmsevt_is_pending()
```

```c
#define ao_ir_pwmsevt_reply()
```

```c
#define ao_ir_pwmsevt_request()
```


---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The ao_sys_xc32_pic32mk_gpg/ao_ir_pwm.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys_xc32_pic32mk_gpg/ao_ir_pwm.h/ 
subtitle: ""
title: "ao_ir_pwm.h"
toc: true
---

```c
#include <stdbool.h>
#include <sys/attribs.h>
#include <xc.h>

#ifndef AO_IR_PWM1_ATTRIBUTE

#define AO_IR_PWM1_ATTRIBUTE        __ISR(_PWM1_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_PWM1_PRIO

#define AO_IR_PWM1_PRIO             (4)

#endif

#ifndef AO_IR_PWM1_SUBPRIO

#define AO_IR_PWM1_SUBPRIO          (0)

#endif

#ifndef ao_ir_pwm1_disable

#define ao_ir_pwm1_disable()        { IEC5CLR = _IEC5_PWM1IE_MASK; }

#endif

#ifndef ao_ir_pwm1_enable

#define ao_ir_pwm1_enable()         { IEC5SET = _IEC5_PWM1IE_MASK; }

#endif

#ifndef ao_ir_pwm1_is_enabled

#define ao_ir_pwm1_is_enabled()     ((IEC5 & _IEC5_PWM1IE_MASK) ? true : false)

#endif

#ifndef ao_ir_pwm1_is_pending

#define ao_ir_pwm1_is_pending()     ((IFS5 & _IFS5_PWM1IF_MASK) ? true : false)

#endif

#ifndef ao_ir_pwm1_reply

#define ao_ir_pwm1_reply()          { IFS5CLR = _IFS5_PWM1IF_MASK; }

#endif

#ifndef ao_ir_pwm1_request

#define ao_ir_pwm1_request()        { IFS5SET = _IFS5_PWM1IF_MASK; }

#endif

#ifndef AO_IR_PWM2_ATTRIBUTE

#define AO_IR_PWM2_ATTRIBUTE        __ISR(_PWM2_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_PWM2_PRIO

#define AO_IR_PWM2_PRIO             (4)

#endif

#ifndef AO_IR_PWM2_SUBPRIO

#define AO_IR_PWM2_SUBPRIO          (0)

#endif

#ifndef ao_ir_pwm2_disable

#define ao_ir_pwm2_disable()        { IEC5CLR = _IEC5_PWM2IE_MASK; }

#endif

#ifndef ao_ir_pwm2_enable

#define ao_ir_pwm2_enable()         { IEC5SET = _IEC5_PWM2IE_MASK; }

#endif

#ifndef ao_ir_pwm2_is_enabled

#define ao_ir_pwm2_is_enabled()     ((IEC5 & _IEC5_PWM2IE_MASK) ? true : false)

#endif

#ifndef ao_ir_pwm2_is_pending

#define ao_ir_pwm2_is_pending()     ((IFS5 & _IFS5_PWM2IF_MASK) ? true : false)

#endif

#ifndef ao_ir_pwm2_reply

#define ao_ir_pwm2_reply()          { IFS5CLR = _IFS5_PWM2IF_MASK; }

#endif

#ifndef ao_ir_pwm2_request

#define ao_ir_pwm2_request()        { IFS5SET = _IFS5_PWM2IF_MASK; }

#endif

#ifndef AO_IR_PWM3_ATTRIBUTE

#define AO_IR_PWM3_ATTRIBUTE        __ISR(_PWM3_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_PWM3_PRIO

#define AO_IR_PWM3_PRIO             (4)

#endif

#ifndef AO_IR_PWM3_SUBPRIO

#define AO_IR_PWM3_SUBPRIO          (0)

#endif

#ifndef ao_ir_pwm3_disable

#define ao_ir_pwm3_disable()        { IEC5CLR = _IEC5_PWM3IE_MASK; }

#endif

#ifndef ao_ir_pwm3_enable

#define ao_ir_pwm3_enable()         { IEC5SET = _IEC5_PWM3IE_MASK; }

#endif

#ifndef ao_ir_pwm3_is_enabled

#define ao_ir_pwm3_is_enabled()     ((IEC5 & _IEC5_PWM3IE_MASK) ? true : false)

#endif

#ifndef ao_ir_pwm3_is_pending

#define ao_ir_pwm3_is_pending()     ((IFS5 & _IFS5_PWM3IF_MASK) ? true : false)

#endif

#ifndef ao_ir_pwm3_reply

#define ao_ir_pwm3_reply()          { IFS5CLR = _IFS5_PWM3IF_MASK; }

#endif

#ifndef ao_ir_pwm3_request

#define ao_ir_pwm3_request()        { IFS5SET = _IFS5_PWM3IF_MASK; }

#endif

#ifndef AO_IR_PWM4_ATTRIBUTE

#define AO_IR_PWM4_ATTRIBUTE        __ISR(_PWM4_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_PWM4_PRIO

#define AO_IR_PWM4_PRIO             (4)

#endif

#ifndef AO_IR_PWM4_SUBPRIO

#define AO_IR_PWM4_SUBPRIO          (0)

#endif

#ifndef ao_ir_pwm4_disable

#define ao_ir_pwm4_disable()        { IEC5CLR = _IEC5_PWM4IE_MASK; }

#endif

#ifndef ao_ir_pwm4_enable

#define ao_ir_pwm4_enable()         { IEC5SET = _IEC5_PWM4IE_MASK; }

#endif

#ifndef ao_ir_pwm4_is_enabled

#define ao_ir_pwm4_is_enabled()     ((IEC5 & _IEC5_PWM4IE_MASK) ? true : false)

#endif

#ifndef ao_ir_pwm4_is_pending

#define ao_ir_pwm4_is_pending()     ((IFS5 & _IFS5_PWM4IF_MASK) ? true : false)

#endif

#ifndef ao_ir_pwm4_reply

#define ao_ir_pwm4_reply()          { IFS5CLR = _IFS5_PWM4IF_MASK; }

#endif

#ifndef ao_ir_pwm4_request

#define ao_ir_pwm4_request()        { IFS5SET = _IFS5_PWM4IF_MASK; }

#endif

#ifndef AO_IR_PWM5_ATTRIBUTE

#define AO_IR_PWM5_ATTRIBUTE        __ISR(_PWM5_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_PWM5_PRIO

#define AO_IR_PWM5_PRIO             (4)

#endif

#ifndef AO_IR_PWM5_SUBPRIO

#define AO_IR_PWM5_SUBPRIO          (0)

#endif

#ifndef ao_ir_pwm5_disable

#define ao_ir_pwm5_disable()        { IEC5CLR = _IEC5_PWM5IE_MASK; }

#endif

#ifndef ao_ir_pwm5_enable

#define ao_ir_pwm5_enable()         { IEC5SET = _IEC5_PWM5IE_MASK; }

#endif

#ifndef ao_ir_pwm5_is_enabled

#define ao_ir_pwm5_is_enabled()     ((IEC5 & _IEC5_PWM5IE_MASK) ? true : false)

#endif

#ifndef ao_ir_pwm5_is_pending

#define ao_ir_pwm5_is_pending()     ((IFS5 & _IFS5_PWM5IF_MASK) ? true : false)

#endif

#ifndef ao_ir_pwm5_reply

#define ao_ir_pwm5_reply()          { IFS5CLR = _IFS5_PWM5IF_MASK; }

#endif

#ifndef ao_ir_pwm5_request

#define ao_ir_pwm5_request()        { IFS5SET = _IFS5_PWM5IF_MASK; }

#endif

#ifndef AO_IR_PWM6_ATTRIBUTE

#define AO_IR_PWM6_ATTRIBUTE        __ISR(_PWM6_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_PWM6_PRIO

#define AO_IR_PWM6_PRIO             (4)

#endif

#ifndef AO_IR_PWM6_SUBPRIO

#define AO_IR_PWM6_SUBPRIO          (0)

#endif

#ifndef ao_ir_pwm6_disable

#define ao_ir_pwm6_disable()        { IEC5CLR = _IEC5_PWM6IE_MASK; }

#endif

#ifndef ao_ir_pwm6_enable

#define ao_ir_pwm6_enable()         { IEC5SET = _IEC5_PWM6IE_MASK; }

#endif

#ifndef ao_ir_pwm6_is_enabled

#define ao_ir_pwm6_is_enabled()     ((IEC5 & _IEC5_PWM6IE_MASK) ? true : false)

#endif

#ifndef ao_ir_pwm6_is_pending

#define ao_ir_pwm6_is_pending()     ((IFS5 & _IFS5_PWM6IF_MASK) ? true : false)

#endif

#ifndef ao_ir_pwm6_reply

#define ao_ir_pwm6_reply()          { IFS5CLR = _IFS5_PWM6IF_MASK; }

#endif

#ifndef ao_ir_pwm6_request

#define ao_ir_pwm6_request()        { IFS5SET = _IFS5_PWM6IF_MASK; }

#endif

#ifndef AO_IR_PWM7_ATTRIBUTE

#define AO_IR_PWM7_ATTRIBUTE        __ISR(_PWM7_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_PWM7_PRIO

#define AO_IR_PWM7_PRIO             (4)

#endif

#ifndef AO_IR_PWM7_SUBPRIO

#define AO_IR_PWM7_SUBPRIO          (0)

#endif

#ifndef ao_ir_pwm7_disable

#define ao_ir_pwm7_disable()        { IEC7CLR = _IEC7_PWM7IE_MASK; }

#endif

#ifndef ao_ir_pwm7_enable

#define ao_ir_pwm7_enable()         { IEC7SET = _IEC7_PWM7IE_MASK; }

#endif

#ifndef ao_ir_pwm7_is_enabled

#define ao_ir_pwm7_is_enabled()     ((IEC7 & _IEC7_PWM7IE_MASK) ? true : false)

#endif

#ifndef ao_ir_pwm7_is_pending

#define ao_ir_pwm7_is_pending()     ((IFS7 & _IFS7_PWM7IF_MASK) ? true : false)

#endif

#ifndef ao_ir_pwm7_reply

#define ao_ir_pwm7_reply()          { IFS7CLR = _IFS7_PWM7IF_MASK; }

#endif

#ifndef ao_ir_pwm7_request

#define ao_ir_pwm7_request()        { IFS7SET = _IFS7_PWM7IF_MASK; }

#endif

#ifndef AO_IR_PWM8_ATTRIBUTE

#define AO_IR_PWM8_ATTRIBUTE        __ISR(_PWM8_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_PWM8_PRIO

#define AO_IR_PWM8_PRIO             (4)

#endif

#ifndef AO_IR_PWM8_SUBPRIO

#define AO_IR_PWM8_SUBPRIO          (0)

#endif

#ifndef ao_ir_pwm8_disable

#define ao_ir_pwm8_disable()        { IEC7CLR = _IEC7_PWM8IE_MASK; }

#endif

#ifndef ao_ir_pwm8_enable

#define ao_ir_pwm8_enable()         { IEC7SET = _IEC7_PWM8IE_MASK; }

#endif

#ifndef ao_ir_pwm8_is_enabled

#define ao_ir_pwm8_is_enabled()     ((IEC7 & _IEC7_PWM8IE_MASK) ? true : false)

#endif

#ifndef ao_ir_pwm8_is_pending

#define ao_ir_pwm8_is_pending()     ((IFS7 & _IFS7_PWM8IF_MASK) ? true : false)

#endif

#ifndef ao_ir_pwm8_reply

#define ao_ir_pwm8_reply()          { IFS7CLR = _IFS7_PWM8IF_MASK; }

#endif

#ifndef ao_ir_pwm8_request

#define ao_ir_pwm8_request()        { IFS7SET = _IFS7_PWM8IF_MASK; }

#endif

#ifndef AO_IR_PWM9_ATTRIBUTE

#define AO_IR_PWM9_ATTRIBUTE        __ISR(_PWM9_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_PWM9_PRIO

#define AO_IR_PWM9_PRIO             (4)

#endif

#ifndef AO_IR_PWM9_SUBPRIO

#define AO_IR_PWM9_SUBPRIO          (0)

#endif

#ifndef ao_ir_pwm9_disable

#define ao_ir_pwm9_disable()        { IEC7CLR = _IEC7_PWM9IE_MASK; }

#endif

#ifndef ao_ir_pwm9_enable

#define ao_ir_pwm9_enable()         { IEC7SET = _IEC7_PWM9IE_MASK; }

#endif

#ifndef ao_ir_pwm9_is_enabled

#define ao_ir_pwm9_is_enabled()     ((IEC7 & _IEC7_PWM9IE_MASK) ? true : false)

#endif

#ifndef ao_ir_pwm9_is_pending

#define ao_ir_pwm9_is_pending()     ((IFS7 & _IFS7_PWM9IF_MASK) ? true : false)

#endif

#ifndef ao_ir_pwm9_reply

#define ao_ir_pwm9_reply()          { IFS7CLR = _IFS7_PWM9IF_MASK; }

#endif

#ifndef ao_ir_pwm9_request

#define ao_ir_pwm9_request()        { IFS7SET = _IFS7_PWM9IF_MASK; }

#endif

#ifndef AO_IR_PWMPEVT_ATTRIBUTE

#define AO_IR_PWMPEVT_ATTRIBUTE     __ISR(_PWM_PRI_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_PWMPEVT_PRIO

#define AO_IR_PWMPEVT_PRIO          (4)

#endif

#ifndef AO_IR_PWMPEVT_SUBPRIO

#define AO_IR_PWMPEVT_SUBPRIO       (0)

#endif

#ifndef ao_ir_pwmpevt_disable

#define ao_ir_pwmpevt_disable()     { IEC5CLR = _IEC5_PWMPEVTIE_MASK; }

#endif

#ifndef ao_ir_pwmpevt_enable

#define ao_ir_pwmpevt_enable()      { IEC5SET = _IEC5_PWMPEVTIE_MASK; }

#endif

#ifndef ao_ir_pwmpevt_is_enabled

#define ao_ir_pwmpevt_is_enabled()  ((IEC5 & _IEC5_PWMPEVTIE_MASK) ? true : false)

#endif

#ifndef ao_ir_pwmpevt_is_pending

#define ao_ir_pwmpevt_is_pending()  ((IFS5 & _IFS5_PWMPEVTIF_MASK) ? true : false)

#endif

#ifndef ao_ir_pwmpevt_reply

#define ao_ir_pwmpevt_reply()       { IFS5CLR = _IFS5_PWMPEVTIF_MASK; }

#endif

#ifndef ao_ir_pwmpevt_request

#define ao_ir_pwmpevt_request()     { IFS5SET = _IFS5_PWMPEVTIF_MASK; }

#endif

#ifndef AO_IR_PWMSEVT_ATTRIBUTE

#define AO_IR_PWMSEVT_ATTRIBUTE     __ISR(_PWM_SEC_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_PWMSEVT_PRIO

#define AO_IR_PWMSEVT_PRIO          (4)

#endif

#ifndef AO_IR_PWMSEVT_SUBPRIO

#define AO_IR_PWMSEVT_SUBPRIO       (0)

#endif

#ifndef ao_ir_pwmsevt_disable

#define ao_ir_pwmsevt_disable()     { IEC5CLR = _IEC5_PWMSEVTIE_MASK; }

#endif

#ifndef ao_ir_pwmsevt_enable

#define ao_ir_pwmsevt_enable()      { IEC5SET = _IEC5_PWMSEVTIE_MASK; }

#endif

#ifndef ao_ir_pwmsevt_is_enabled

#define ao_ir_pwmsevt_is_enabled()  ((IEC5 & _IEC5_PWMSEVTIE_MASK) ? true : false)

#endif

#ifndef ao_ir_pwmsevt_is_pending

#define ao_ir_pwmsevt_is_pending()  ((IFS5 & _IFS5_PWMSEVTIF_MASK) ? true : false)

#endif

#ifndef ao_ir_pwmsevt_reply

#define ao_ir_pwmsevt_reply()       { IFS5CLR = _IFS5_PWMSEVTIF_MASK; }

#endif

#ifndef ao_ir_pwmsevt_request

#define ao_ir_pwmsevt_request()     { IFS5SET = _IFS5_PWMSEVTIF_MASK; }

#endif

```

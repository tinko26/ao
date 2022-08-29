---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The ao_sys_xc32_pic32mk_gpk/ao_ir_oc.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys_xc32_pic32mk_gpk/ao_ir_oc.h/ 
subtitle: ""
title: "ao_ir_oc.h"
toc: true
---

# Overview

...

# Includes

```c
#include <stdbool.h>
#include <sys/attribs.h>
#include <xc.h>

#ifndef AO_IR_OC1_ATTRIBUTE

#define AO_IR_OC1_ATTRIBUTE     __ISR(_OUTPUT_COMPARE_1_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_OC1_PRIO

#define AO_IR_OC1_PRIO          (4)

#endif

#ifndef AO_IR_OC1_SUBPRIO

#define AO_IR_OC1_SUBPRIO       (0)

#endif

#ifndef ao_ir_oc1_disable

#define ao_ir_oc1_disable()     { IEC0CLR = _IEC0_OC1IE_MASK; }

#endif

#ifndef ao_ir_oc1_enable

#define ao_ir_oc1_enable()      { IEC0SET = _IEC0_OC1IE_MASK; }

#endif

#ifndef ao_ir_oc1_is_enabled

#define ao_ir_oc1_is_enabled()  ((IEC0 & _IEC0_OC1IE_MASK) ? true : false)

#endif

#ifndef ao_ir_oc1_is_pending

#define ao_ir_oc1_is_pending()  ((IFS0 & _IFS0_OC1IF_MASK) ? true : false)

#endif

#ifndef ao_ir_oc1_reply

#define ao_ir_oc1_reply()       { IFS0CLR = _IFS0_OC1IF_MASK; }

#endif

#ifndef ao_ir_oc1_request

#define ao_ir_oc1_request()     { IFS0SET = _IFS0_OC1IF_MASK; }

#endif

#ifndef AO_IR_OC2_ATTRIBUTE

#define AO_IR_OC2_ATTRIBUTE     __ISR(_OUTPUT_COMPARE_2_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_OC2_PRIO

#define AO_IR_OC2_PRIO          (4)

#endif

#ifndef AO_IR_OC2_SUBPRIO

#define AO_IR_OC2_SUBPRIO       (0)

#endif

#ifndef ao_ir_oc2_disable

#define ao_ir_oc2_disable()     { IEC0CLR = _IEC0_OC2IE_MASK; }

#endif

#ifndef ao_ir_oc2_enable

#define ao_ir_oc2_enable()      { IEC0SET = _IEC0_OC2IE_MASK; }

#endif

#ifndef ao_ir_oc2_is_enabled

#define ao_ir_oc2_is_enabled()  ((IEC0 & _IEC0_OC2IE_MASK) ? true : false)

#endif

#ifndef ao_ir_oc2_is_pending

#define ao_ir_oc2_is_pending()  ((IFS0 & _IFS0_OC2IF_MASK) ? true : false)

#endif

#ifndef ao_ir_oc2_reply

#define ao_ir_oc2_reply()       { IFS0CLR = _IFS0_OC2IF_MASK; }

#endif

#ifndef ao_ir_oc2_request

#define ao_ir_oc2_request()     { IFS0SET = _IFS0_OC2IF_MASK; }

#endif

#ifndef AO_IR_OC3_ATTRIBUTE

#define AO_IR_OC3_ATTRIBUTE     __ISR(_OUTPUT_COMPARE_3_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_OC3_PRIO

#define AO_IR_OC3_PRIO          (4)

#endif

#ifndef AO_IR_OC3_SUBPRIO

#define AO_IR_OC3_SUBPRIO       (0)

#endif

#ifndef ao_ir_oc3_disable

#define ao_ir_oc3_disable()     { IEC0CLR = _IEC0_OC3IE_MASK; }

#endif

#ifndef ao_ir_oc3_enable

#define ao_ir_oc3_enable()      { IEC0SET = _IEC0_OC3IE_MASK; }

#endif

#ifndef ao_ir_oc3_is_enabled

#define ao_ir_oc3_is_enabled()  ((IEC0 & _IEC0_OC3IE_MASK) ? true : false)

#endif

#ifndef ao_ir_oc3_is_pending

#define ao_ir_oc3_is_pending()  ((IFS0 & _IFS0_OC3IF_MASK) ? true : false)

#endif

#ifndef ao_ir_oc3_reply

#define ao_ir_oc3_reply()       { IFS0CLR = _IFS0_OC3IF_MASK; }

#endif

#ifndef ao_ir_oc3_request

#define ao_ir_oc3_request()     { IFS0SET = _IFS0_OC3IF_MASK; }

#endif

#ifndef AO_IR_OC4_ATTRIBUTE

#define AO_IR_OC4_ATTRIBUTE     __ISR(_OUTPUT_COMPARE_4_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_OC4_PRIO

#define AO_IR_OC4_PRIO          (4)

#endif

#ifndef AO_IR_OC4_SUBPRIO

#define AO_IR_OC4_SUBPRIO       (0)

#endif

#ifndef ao_ir_oc4_disable

#define ao_ir_oc4_disable()     { IEC0CLR = _IEC0_OC4IE_MASK; }

#endif

#ifndef ao_ir_oc4_enable

#define ao_ir_oc4_enable()      { IEC0SET = _IEC0_OC4IE_MASK; }

#endif

#ifndef ao_ir_oc4_is_enabled

#define ao_ir_oc4_is_enabled()  ((IEC0 & _IEC0_OC4IE_MASK) ? true : false)

#endif

#ifndef ao_ir_oc4_is_pending

#define ao_ir_oc4_is_pending()  ((IFS0 & _IFS0_OC4IF_MASK) ? true : false)

#endif

#ifndef ao_ir_oc4_reply

#define ao_ir_oc4_reply()       { IFS0CLR = _IFS0_OC4IF_MASK; }

#endif

#ifndef ao_ir_oc4_request

#define ao_ir_oc4_request()     { IFS0SET = _IFS0_OC4IF_MASK; }

#endif

#ifndef AO_IR_OC5_ATTRIBUTE

#define AO_IR_OC5_ATTRIBUTE     __ISR(_OUTPUT_COMPARE_5_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_OC5_PRIO

#define AO_IR_OC5_PRIO          (4)

#endif

#ifndef AO_IR_OC5_SUBPRIO

#define AO_IR_OC5_SUBPRIO       (0)

#endif

#ifndef ao_ir_oc5_disable

#define ao_ir_oc5_disable()     { IEC0CLR = _IEC0_OC5IE_MASK; }

#endif

#ifndef ao_ir_oc5_enable

#define ao_ir_oc5_enable()      { IEC0SET = _IEC0_OC5IE_MASK; }

#endif

#ifndef ao_ir_oc5_is_enabled

#define ao_ir_oc5_is_enabled()  ((IEC0 & _IEC0_OC5IE_MASK) ? true : false)

#endif

#ifndef ao_ir_oc5_is_pending

#define ao_ir_oc5_is_pending()  ((IFS0 & _IFS0_OC5IF_MASK) ? true : false)

#endif

#ifndef ao_ir_oc5_reply

#define ao_ir_oc5_reply()       { IFS0CLR = _IFS0_OC5IF_MASK; }

#endif

#ifndef ao_ir_oc5_request

#define ao_ir_oc5_request()     { IFS0SET = _IFS0_OC5IF_MASK; }

#endif

#ifndef AO_IR_OC6_ATTRIBUTE

#define AO_IR_OC6_ATTRIBUTE     __ISR(_OUTPUT_COMPARE_6_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_OC6_PRIO

#define AO_IR_OC6_PRIO          (4)

#endif

#ifndef AO_IR_OC6_SUBPRIO

#define AO_IR_OC6_SUBPRIO       (0)

#endif

#ifndef ao_ir_oc6_disable

#define ao_ir_oc6_disable()     { IEC2CLR = _IEC2_OC6IE_MASK; }

#endif

#ifndef ao_ir_oc6_enable

#define ao_ir_oc6_enable()      { IEC2SET = _IEC2_OC6IE_MASK; }

#endif

#ifndef ao_ir_oc6_is_enabled

#define ao_ir_oc6_is_enabled()  ((IEC2 & _IEC2_OC6IE_MASK) ? true : false)

#endif

#ifndef ao_ir_oc6_is_pending

#define ao_ir_oc6_is_pending()  ((IFS2 & _IFS2_OC6IF_MASK) ? true : false)

#endif

#ifndef ao_ir_oc6_reply

#define ao_ir_oc6_reply()       { IFS2CLR = _IFS2_OC6IF_MASK; }

#endif

#ifndef ao_ir_oc6_request

#define ao_ir_oc6_request()     { IFS2SET = _IFS2_OC6IF_MASK; }

#endif

#ifndef AO_IR_OC7_ATTRIBUTE

#define AO_IR_OC7_ATTRIBUTE     __ISR(_OUTPUT_COMPARE_7_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_OC7_PRIO

#define AO_IR_OC7_PRIO          (4)

#endif

#ifndef AO_IR_OC7_SUBPRIO

#define AO_IR_OC7_SUBPRIO       (0)

#endif

#ifndef ao_ir_oc7_disable

#define ao_ir_oc7_disable()     { IEC2CLR = _IEC2_OC7IE_MASK; }

#endif

#ifndef ao_ir_oc7_enable

#define ao_ir_oc7_enable()      { IEC2SET = _IEC2_OC7IE_MASK; }

#endif

#ifndef ao_ir_oc7_is_enabled

#define ao_ir_oc7_is_enabled()  ((IEC2 & _IEC2_OC7IE_MASK) ? true : false)

#endif

#ifndef ao_ir_oc7_is_pending

#define ao_ir_oc7_is_pending()  ((IFS2 & _IFS2_OC7IF_MASK) ? true : false)

#endif

#ifndef ao_ir_oc7_reply

#define ao_ir_oc7_reply()       { IFS2CLR = _IFS2_OC7IF_MASK; }

#endif

#ifndef ao_ir_oc7_request

#define ao_ir_oc7_request()     { IFS2SET = _IFS2_OC7IF_MASK; }

#endif

#ifndef AO_IR_OC8_ATTRIBUTE

#define AO_IR_OC8_ATTRIBUTE     __ISR(_OUTPUT_COMPARE_8_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_OC8_PRIO

#define AO_IR_OC8_PRIO          (4)

#endif

#ifndef AO_IR_OC8_SUBPRIO

#define AO_IR_OC8_SUBPRIO       (0)

#endif

#ifndef ao_ir_oc8_disable

#define ao_ir_oc8_disable()     { IEC2CLR = _IEC2_OC8IE_MASK; }

#endif

#ifndef ao_ir_oc8_enable

#define ao_ir_oc8_enable()      { IEC2SET = _IEC2_OC8IE_MASK; }

#endif

#ifndef ao_ir_oc8_is_enabled

#define ao_ir_oc8_is_enabled()  ((IEC2 & _IEC2_OC8IE_MASK) ? true : false)

#endif

#ifndef ao_ir_oc8_is_pending

#define ao_ir_oc8_is_pending()  ((IFS2 & _IFS2_OC8IF_MASK) ? true : false)

#endif

#ifndef ao_ir_oc8_reply

#define ao_ir_oc8_reply()       { IFS2CLR = _IFS2_OC8IF_MASK; }

#endif

#ifndef ao_ir_oc8_request

#define ao_ir_oc8_request()     { IFS2SET = _IFS2_OC8IF_MASK; }

#endif

#ifndef AO_IR_OC9_ATTRIBUTE

#define AO_IR_OC9_ATTRIBUTE     __ISR(_OUTPUT_COMPARE_9_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_OC9_PRIO

#define AO_IR_OC9_PRIO          (4)

#endif

#ifndef AO_IR_OC9_SUBPRIO

#define AO_IR_OC9_SUBPRIO       (0)

#endif

#ifndef ao_ir_oc9_disable

#define ao_ir_oc9_disable()     { IEC2CLR = _IEC2_OC9IE_MASK; }

#endif

#ifndef ao_ir_oc9_enable

#define ao_ir_oc9_enable()      { IEC2SET = _IEC2_OC9IE_MASK; }

#endif

#ifndef ao_ir_oc9_is_enabled

#define ao_ir_oc9_is_enabled()  ((IEC2 & _IEC2_OC9IE_MASK) ? true : false)

#endif

#ifndef ao_ir_oc9_is_pending

#define ao_ir_oc9_is_pending()  ((IFS2 & _IFS2_OC9IF_MASK) ? true : false)

#endif

#ifndef ao_ir_oc9_reply

#define ao_ir_oc9_reply()       { IFS2CLR = _IFS2_OC9IF_MASK; }

#endif

#ifndef ao_ir_oc9_request

#define ao_ir_oc9_request()     { IFS2SET = _IFS2_OC9IF_MASK; }

#endif

#ifndef AO_IR_OC10_ATTRIBUTE

#define AO_IR_OC10_ATTRIBUTE    __ISR(_OUTPUT_COMPARE_10_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_OC10_PRIO

#define AO_IR_OC10_PRIO         (4)

#endif

#ifndef AO_IR_OC10_SUBPRIO

#define AO_IR_OC10_SUBPRIO      (0)

#endif

#ifndef ao_ir_oc10_disable

#define ao_ir_oc10_disable()    { IEC6CLR = _IEC6_OC10IE_MASK; }

#endif

#ifndef ao_ir_oc10_enable

#define ao_ir_oc10_enable()     { IEC6SET = _IEC6_OC10IE_MASK; }

#endif

#ifndef ao_ir_oc10_is_enabled

#define ao_ir_oc10_is_enabled() ((IEC6 & _IEC6_OC10IE_MASK) ? true : false)

#endif

#ifndef ao_ir_oc10_is_pending

#define ao_ir_oc10_is_pending() ((IFS6 & _IFS6_OC10IF_MASK) ? true : false)

#endif

#ifndef ao_ir_oc10_reply

#define ao_ir_oc10_reply()      { IFS6CLR = _IFS6_OC10IF_MASK; }

#endif

#ifndef ao_ir_oc10_request

#define ao_ir_oc10_request()    { IFS6SET = _IFS6_OC10IF_MASK; }

#endif

#ifndef AO_IR_OC11_ATTRIBUTE

#define AO_IR_OC11_ATTRIBUTE    __ISR(_OUTPUT_COMPARE_11_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_OC11_PRIO

#define AO_IR_OC11_PRIO         (4)

#endif

#ifndef AO_IR_OC11_SUBPRIO

#define AO_IR_OC11_SUBPRIO      (0)

#endif

#ifndef ao_ir_oc11_disable

#define ao_ir_oc11_disable()    { IEC6CLR = _IEC6_OC11IE_MASK; }

#endif

#ifndef ao_ir_oc11_enable

#define ao_ir_oc11_enable()     { IEC6SET = _IEC6_OC11IE_MASK; }

#endif

#ifndef ao_ir_oc11_is_enabled

#define ao_ir_oc11_is_enabled() ((IEC6 & _IEC6_OC11IE_MASK) ? true : false)

#endif

#ifndef ao_ir_oc11_is_pending

#define ao_ir_oc11_is_pending() ((IFS6 & _IFS6_OC11IF_MASK) ? true : false)

#endif

#ifndef ao_ir_oc11_reply

#define ao_ir_oc11_reply()      { IFS6CLR = _IFS6_OC11IF_MASK; }

#endif

#ifndef ao_ir_oc11_request

#define ao_ir_oc11_request()    { IFS6SET = _IFS6_OC11IF_MASK; }

#endif

#ifndef AO_IR_OC12_ATTRIBUTE

#define AO_IR_OC12_ATTRIBUTE    __ISR(_OUTPUT_COMPARE_12_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_OC12_PRIO

#define AO_IR_OC12_PRIO         (4)

#endif

#ifndef AO_IR_OC12_SUBPRIO

#define AO_IR_OC12_SUBPRIO      (0)

#endif

#ifndef ao_ir_oc12_disable

#define ao_ir_oc12_disable()    { IEC6CLR = _IEC6_OC12IE_MASK; }

#endif

#ifndef ao_ir_oc12_enable

#define ao_ir_oc12_enable()     { IEC6SET = _IEC6_OC12IE_MASK; }

#endif

#ifndef ao_ir_oc12_is_enabled

#define ao_ir_oc12_is_enabled() ((IEC6 & _IEC6_OC12IE_MASK) ? true : false)

#endif

#ifndef ao_ir_oc12_is_pending

#define ao_ir_oc12_is_pending() ((IFS6 & _IFS6_OC12IF_MASK) ? true : false)

#endif

#ifndef ao_ir_oc12_reply

#define ao_ir_oc12_reply()      { IFS6CLR = _IFS6_OC12IF_MASK; }

#endif

#ifndef ao_ir_oc12_request

#define ao_ir_oc12_request()    { IFS6SET = _IFS6_OC12IF_MASK; }

#endif

#ifndef AO_IR_OC13_ATTRIBUTE

#define AO_IR_OC13_ATTRIBUTE    __ISR(_OUTPUT_COMPARE_13_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_OC13_PRIO

#define AO_IR_OC13_PRIO         (4)

#endif

#ifndef AO_IR_OC13_SUBPRIO

#define AO_IR_OC13_SUBPRIO      (0)

#endif

#ifndef ao_ir_oc13_disable

#define ao_ir_oc13_disable()    { IEC6CLR = _IEC6_OC13IE_MASK; }

#endif

#ifndef ao_ir_oc13_enable

#define ao_ir_oc13_enable()     { IEC6SET = _IEC6_OC13IE_MASK; }

#endif

#ifndef ao_ir_oc13_is_enabled

#define ao_ir_oc13_is_enabled() ((IEC6 & _IEC6_OC13IE_MASK) ? true : false)

#endif

#ifndef ao_ir_oc13_is_pending

#define ao_ir_oc13_is_pending() ((IFS6 & _IFS6_OC13IF_MASK) ? true : false)

#endif

#ifndef ao_ir_oc13_reply

#define ao_ir_oc13_reply()      { IFS6CLR = _IFS6_OC13IF_MASK; }

#endif

#ifndef ao_ir_oc13_request

#define ao_ir_oc13_request()    { IFS6SET = _IFS6_OC13IF_MASK; }

#endif

#ifndef AO_IR_OC14_ATTRIBUTE

#define AO_IR_OC14_ATTRIBUTE    __ISR(_OUTPUT_COMPARE_14_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_OC14_PRIO

#define AO_IR_OC14_PRIO         (4)

#endif

#ifndef AO_IR_OC14_SUBPRIO

#define AO_IR_OC14_SUBPRIO      (0)

#endif

#ifndef ao_ir_oc14_disable

#define ao_ir_oc14_disable()    { IEC6CLR = _IEC6_OC14IE_MASK; }

#endif

#ifndef ao_ir_oc14_enable

#define ao_ir_oc14_enable()     { IEC6SET = _IEC6_OC14IE_MASK; }

#endif

#ifndef ao_ir_oc14_is_enabled

#define ao_ir_oc14_is_enabled() ((IEC6 & _IEC6_OC14IE_MASK) ? true : false)

#endif

#ifndef ao_ir_oc14_is_pending

#define ao_ir_oc14_is_pending() ((IFS6 & _IFS6_OC14IF_MASK) ? true : false)

#endif

#ifndef ao_ir_oc14_reply

#define ao_ir_oc14_reply()      { IFS6CLR = _IFS6_OC14IF_MASK; }

#endif

#ifndef ao_ir_oc14_request

#define ao_ir_oc14_request()    { IFS6SET = _IFS6_OC14IF_MASK; }

#endif

#ifndef AO_IR_OC15_ATTRIBUTE

#define AO_IR_OC15_ATTRIBUTE    __ISR(_OUTPUT_COMPARE_15_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_OC15_PRIO

#define AO_IR_OC15_PRIO         (4)

#endif

#ifndef AO_IR_OC15_SUBPRIO

#define AO_IR_OC15_SUBPRIO      (0)

#endif

#ifndef ao_ir_oc15_disable

#define ao_ir_oc15_disable()    { IEC6CLR = _IEC6_OC15IE_MASK; }

#endif

#ifndef ao_ir_oc15_enable

#define ao_ir_oc15_enable()     { IEC6SET = _IEC6_OC15IE_MASK; }

#endif

#ifndef ao_ir_oc15_is_enabled

#define ao_ir_oc15_is_enabled() ((IEC6 & _IEC6_OC15IE_MASK) ? true : false)

#endif

#ifndef ao_ir_oc15_is_pending

#define ao_ir_oc15_is_pending() ((IFS6 & _IFS6_OC15IF_MASK) ? true : false)

#endif

#ifndef ao_ir_oc15_reply

#define ao_ir_oc15_reply()      { IFS6CLR = _IFS6_OC15IF_MASK; }

#endif

#ifndef ao_ir_oc15_request

#define ao_ir_oc15_request()    { IFS6SET = _IFS6_OC15IF_MASK; }

#endif

#ifndef AO_IR_OC16_ATTRIBUTE

#define AO_IR_OC16_ATTRIBUTE    __ISR(_OUTPUT_COMPARE_16_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_OC16_PRIO

#define AO_IR_OC16_PRIO         (4)

#endif

#ifndef AO_IR_OC16_SUBPRIO

#define AO_IR_OC16_SUBPRIO      (0)

#endif

#ifndef ao_ir_oc16_disable

#define ao_ir_oc16_disable()    { IEC6CLR = _IEC6_OC16IE_MASK; }

#endif

#ifndef ao_ir_oc16_enable

#define ao_ir_oc16_enable()     { IEC6SET = _IEC6_OC16IE_MASK; }

#endif

#ifndef ao_ir_oc16_is_enabled

#define ao_ir_oc16_is_enabled() ((IEC6 & _IEC6_OC16IE_MASK) ? true : false)

#endif

#ifndef ao_ir_oc16_is_pending

#define ao_ir_oc16_is_pending() ((IFS6 & _IFS6_OC16IF_MASK) ? true : false)

#endif

#ifndef ao_ir_oc16_reply

#define ao_ir_oc16_reply()      { IFS6CLR = _IFS6_OC16IF_MASK; }

#endif

#ifndef ao_ir_oc16_request

#define ao_ir_oc16_request()    { IFS6SET = _IFS6_OC16IF_MASK; }

#endif

```

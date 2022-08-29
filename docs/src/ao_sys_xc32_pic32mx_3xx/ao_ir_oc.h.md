---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The /src/ao_sys_xc32_pic32mx_3xx/ao_ir_oc.h file of the ao real-time operating system."
draft: true
permalink: /src/ao_sys_xc32_pic32mx_3xx/ao_ir_oc.h/ 
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

#define AO_IR_OC1_ATTRIBUTE     __ISR(_OUTPUT_COMPARE_1_VECTOR, IPL4SOFT)

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

#define AO_IR_OC2_ATTRIBUTE     __ISR(_OUTPUT_COMPARE_2_VECTOR, IPL4SOFT)

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

#define AO_IR_OC3_ATTRIBUTE     __ISR(_OUTPUT_COMPARE_3_VECTOR, IPL4SOFT)

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

#define AO_IR_OC4_ATTRIBUTE     __ISR(_OUTPUT_COMPARE_4_VECTOR, IPL4SOFT)

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

#define AO_IR_OC5_ATTRIBUTE     __ISR(_OUTPUT_COMPARE_5_VECTOR, IPL4SOFT)

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

```

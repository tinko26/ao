---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The /src/ao_sys_xc32_pic32mx_1xx/ao_ir_t.h file of the ao real-time operating system."
draft: true
permalink: /src/ao_sys_xc32_pic32mx_1xx/ao_ir_t.h/ 
subtitle: ""
title: "ao_ir_t.h"
toc: true
---

# Overview

...

# Includes

```c
#include <stdbool.h>
#include <sys/attribs.h>
#include <xc.h>

#ifndef AO_IR_T1_ATTRIBUTE

#define AO_IR_T1_ATTRIBUTE      __ISR(_TIMER_1_VECTOR, IPL4SOFT)

#endif

#ifndef AO_IR_T1_PRIO

#define AO_IR_T1_PRIO           (4)

#endif

#ifndef AO_IR_T1_SUBPRIO

#define AO_IR_T1_SUBPRIO        (0)

#endif

#ifndef ao_ir_t1_disable

#define ao_ir_t1_disable()      { IEC0CLR = _IEC0_T1IE_MASK; }

#endif

#ifndef ao_ir_t1_enable

#define ao_ir_t1_enable()       { IEC0SET = _IEC0_T1IE_MASK; }

#endif

#ifndef ao_ir_t1_is_enabled

#define ao_ir_t1_is_enabled()   ((IEC0 & _IEC0_T1IE_MASK) ? true : false)

#endif

#ifndef ao_ir_t1_is_pending

#define ao_ir_t1_is_pending()   ((IFS0 & _IFS0_T1IF_MASK) ? true : false)

#endif

#ifndef ao_ir_t1_reply

#define ao_ir_t1_reply()        { IFS0CLR = _IFS0_T1IF_MASK; }

#endif

#ifndef ao_ir_t1_request

#define ao_ir_t1_request()      { IFS0SET = _IFS0_T1IF_MASK; }

#endif

#ifndef AO_IR_T2_ATTRIBUTE

#define AO_IR_T2_ATTRIBUTE      __ISR(_TIMER_2_VECTOR, IPL4SOFT)

#endif

#ifndef AO_IR_T2_PRIO

#define AO_IR_T2_PRIO           (4)

#endif

#ifndef AO_IR_T2_SUBPRIO

#define AO_IR_T2_SUBPRIO        (0)

#endif

#ifndef ao_ir_t2_disable

#define ao_ir_t2_disable()      { IEC0CLR = _IEC0_T2IE_MASK; }

#endif

#ifndef ao_ir_t2_enable

#define ao_ir_t2_enable()       { IEC0SET = _IEC0_T2IE_MASK; }

#endif

#ifndef ao_ir_t2_is_enabled

#define ao_ir_t2_is_enabled()   ((IEC0 & _IEC0_T2IE_MASK) ? true : false)

#endif

#ifndef ao_ir_t2_is_pending

#define ao_ir_t2_is_pending()   ((IFS0 & _IFS0_T2IF_MASK) ? true : false)

#endif

#ifndef ao_ir_t2_reply

#define ao_ir_t2_reply()        { IFS0CLR = _IFS0_T2IF_MASK; }

#endif

#ifndef ao_ir_t2_request

#define ao_ir_t2_request()      { IFS0SET = _IFS0_T2IF_MASK; }

#endif

#ifndef AO_IR_T3_ATTRIBUTE

#define AO_IR_T3_ATTRIBUTE      __ISR(_TIMER_3_VECTOR, IPL4SOFT)

#endif

#ifndef AO_IR_T3_PRIO

#define AO_IR_T3_PRIO           (4)

#endif

#ifndef AO_IR_T3_SUBPRIO

#define AO_IR_T3_SUBPRIO        (0)

#endif

#ifndef ao_ir_t3_disable

#define ao_ir_t3_disable()      { IEC0CLR = _IEC0_T3IE_MASK; }

#endif

#ifndef ao_ir_t3_enable

#define ao_ir_t3_enable()       { IEC0SET = _IEC0_T3IE_MASK; }

#endif

#ifndef ao_ir_t3_is_enabled

#define ao_ir_t3_is_enabled()   ((IEC0 & _IEC0_T3IE_MASK) ? true : false)

#endif

#ifndef ao_ir_t3_is_pending

#define ao_ir_t3_is_pending()   ((IFS0 & _IFS0_T3IF_MASK) ? true : false)

#endif

#ifndef ao_ir_t3_reply

#define ao_ir_t3_reply()        { IFS0CLR = _IFS0_T3IF_MASK; }

#endif

#ifndef ao_ir_t3_request

#define ao_ir_t3_request()      { IFS0SET = _IFS0_T3IF_MASK; }

#endif

#ifndef AO_IR_T4_ATTRIBUTE

#define AO_IR_T4_ATTRIBUTE      __ISR(_TIMER_4_VECTOR, IPL4SOFT)

#endif

#ifndef AO_IR_T4_PRIO

#define AO_IR_T4_PRIO           (4)

#endif

#ifndef AO_IR_T4_SUBPRIO

#define AO_IR_T4_SUBPRIO        (0)

#endif

#ifndef ao_ir_t4_disable

#define ao_ir_t4_disable()      { IEC0CLR = _IEC0_T4IE_MASK; }

#endif

#ifndef ao_ir_t4_enable

#define ao_ir_t4_enable()       { IEC0SET = _IEC0_T4IE_MASK; }

#endif

#ifndef ao_ir_t4_is_enabled

#define ao_ir_t4_is_enabled()   ((IEC0 & _IEC0_T4IE_MASK) ? true : false)

#endif

#ifndef ao_ir_t4_is_pending

#define ao_ir_t4_is_pending()   ((IFS0 & _IFS0_T4IF_MASK) ? true : false)

#endif

#ifndef ao_ir_t4_reply

#define ao_ir_t4_reply()        { IFS0CLR = _IFS0_T4IF_MASK; }

#endif

#ifndef ao_ir_t4_request

#define ao_ir_t4_request()      { IFS0SET = _IFS0_T4IF_MASK; }

#endif

#ifndef AO_IR_T5_ATTRIBUTE

#define AO_IR_T5_ATTRIBUTE      __ISR(_TIMER_5_VECTOR, IPL4SOFT)

#endif

#ifndef AO_IR_T5_PRIO

#define AO_IR_T5_PRIO           (4)

#endif

#ifndef AO_IR_T5_SUBPRIO

#define AO_IR_T5_SUBPRIO        (0)

#endif

#ifndef ao_ir_t5_disable

#define ao_ir_t5_disable()      { IEC0CLR = _IEC0_T5IE_MASK; }

#endif

#ifndef ao_ir_t5_enable

#define ao_ir_t5_enable()       { IEC0SET = _IEC0_T5IE_MASK; }

#endif

#ifndef ao_ir_t5_is_enabled

#define ao_ir_t5_is_enabled()   ((IEC0 & _IEC0_T5IE_MASK) ? true : false)

#endif

#ifndef ao_ir_t5_is_pending

#define ao_ir_t5_is_pending()   ((IFS0 & _IFS0_T5IF_MASK) ? true : false)

#endif

#ifndef ao_ir_t5_reply

#define ao_ir_t5_reply()        { IFS0CLR = _IFS0_T5IF_MASK; }

#endif

#ifndef ao_ir_t5_request

#define ao_ir_t5_request()      { IFS0SET = _IFS0_T5IF_MASK; }

#endif

```

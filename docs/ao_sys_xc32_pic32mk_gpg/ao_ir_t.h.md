---
author: "Stefan Wagner"
date: 2022-08-29
description: "The ao_sys_xc32_pic32mk_gpg/ao_ir_t.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys_xc32_pic32mk_gpg/ao_ir_t.h/ 
subtitle: "<code>ao_sys_xc32_pic32mk_gpg</code>"
title: "<code>ao_ir_t.h</code>"
toc: true
---

#ifndef AO_IR_T1_ATTRIBUTE

#define AO_IR_T1_ATTRIBUTE      __ISR(_TIMER_1_VECTOR, IPL4SRS)

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

#define AO_IR_T2_ATTRIBUTE      __ISR(_TIMER_2_VECTOR, IPL4SRS)

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

#define AO_IR_T3_ATTRIBUTE      __ISR(_TIMER_3_VECTOR, IPL4SRS)

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

#define AO_IR_T4_ATTRIBUTE      __ISR(_TIMER_4_VECTOR, IPL4SRS)

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

#define AO_IR_T5_ATTRIBUTE      __ISR(_TIMER_5_VECTOR, IPL4SRS)

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

#ifndef AO_IR_T6_ATTRIBUTE

#define AO_IR_T6_ATTRIBUTE      __ISR(_TIMER_6_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_T6_PRIO

#define AO_IR_T6_PRIO           (4)

#endif

#ifndef AO_IR_T6_SUBPRIO

#define AO_IR_T6_SUBPRIO        (0)

#endif

#ifndef ao_ir_t6_disable

#define ao_ir_t6_disable()      { IEC2CLR = _IEC2_T6IE_MASK; }

#endif

#ifndef ao_ir_t6_enable

#define ao_ir_t6_enable()       { IEC2SET = _IEC2_T6IE_MASK; }

#endif

#ifndef ao_ir_t6_is_enabled

#define ao_ir_t6_is_enabled()   ((IEC2 & _IEC2_T6IE_MASK) ? true : false)

#endif

#ifndef ao_ir_t6_is_pending

#define ao_ir_t6_is_pending()   ((IFS2 & _IFS2_T6IF_MASK) ? true : false)

#endif

#ifndef ao_ir_t6_reply

#define ao_ir_t6_reply()        { IFS2CLR = _IFS2_T6IF_MASK; }

#endif

#ifndef ao_ir_t6_request

#define ao_ir_t6_request()      { IFS2SET = _IFS2_T6IF_MASK; }

#endif

#ifndef AO_IR_T7_ATTRIBUTE

#define AO_IR_T7_ATTRIBUTE      __ISR(_TIMER_7_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_T7_PRIO

#define AO_IR_T7_PRIO           (4)

#endif

#ifndef AO_IR_T7_SUBPRIO

#define AO_IR_T7_SUBPRIO        (0)

#endif

#ifndef ao_ir_t7_disable

#define ao_ir_t7_disable()      { IEC2CLR = _IEC2_T7IE_MASK; }

#endif

#ifndef ao_ir_t7_enable

#define ao_ir_t7_enable()       { IEC2SET = _IEC2_T7IE_MASK; }

#endif

#ifndef ao_ir_t7_is_enabled

#define ao_ir_t7_is_enabled()   ((IEC2 & _IEC2_T7IE_MASK) ? true : false)

#endif

#ifndef ao_ir_t7_is_pending

#define ao_ir_t7_is_pending()   ((IFS2 & _IFS2_T7IF_MASK) ? true : false)

#endif

#ifndef ao_ir_t7_reply

#define ao_ir_t7_reply()        { IFS2CLR = _IFS2_T7IF_MASK; }

#endif

#ifndef ao_ir_t7_request

#define ao_ir_t7_request()      { IFS2SET = _IFS2_T7IF_MASK; }

#endif

#ifndef AO_IR_T8_ATTRIBUTE

#define AO_IR_T8_ATTRIBUTE      __ISR(_TIMER_8_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_T8_PRIO

#define AO_IR_T8_PRIO           (4)

#endif

#ifndef AO_IR_T8_SUBPRIO

#define AO_IR_T8_SUBPRIO        (0)

#endif

#ifndef ao_ir_t8_disable

#define ao_ir_t8_disable()      { IEC2CLR = _IEC2_T8IE_MASK; }

#endif

#ifndef ao_ir_t8_enable

#define ao_ir_t8_enable()       { IEC2SET = _IEC2_T8IE_MASK; }

#endif

#ifndef ao_ir_t8_is_enabled

#define ao_ir_t8_is_enabled()   ((IEC2 & _IEC2_T8IE_MASK) ? true : false)

#endif

#ifndef ao_ir_t8_is_pending

#define ao_ir_t8_is_pending()   ((IFS2 & _IFS2_T8IF_MASK) ? true : false)

#endif

#ifndef ao_ir_t8_reply

#define ao_ir_t8_reply()        { IFS2CLR = _IFS2_T8IF_MASK; }

#endif

#ifndef ao_ir_t8_request

#define ao_ir_t8_request()      { IFS2SET = _IFS2_T8IF_MASK; }

#endif

#ifndef AO_IR_T9_ATTRIBUTE

#define AO_IR_T9_ATTRIBUTE      __ISR(_TIMER_9_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_T9_PRIO

#define AO_IR_T9_PRIO           (4)

#endif

#ifndef AO_IR_T9_SUBPRIO

#define AO_IR_T9_SUBPRIO        (0)

#endif

#ifndef ao_ir_t9_disable

#define ao_ir_t9_disable()      { IEC2CLR = _IEC2_T9IE_MASK; }

#endif

#ifndef ao_ir_t9_enable

#define ao_ir_t9_enable()       { IEC2SET = _IEC2_T9IE_MASK; }

#endif

#ifndef ao_ir_t9_is_enabled

#define ao_ir_t9_is_enabled()   ((IEC2 & _IEC2_T9IE_MASK) ? true : false)

#endif

#ifndef ao_ir_t9_is_pending

#define ao_ir_t9_is_pending()   ((IFS2 & _IFS2_T9IF_MASK) ? true : false)

#endif

#ifndef ao_ir_t9_reply

#define ao_ir_t9_reply()        { IFS2CLR = _IFS2_T9IF_MASK; }

#endif

#ifndef ao_ir_t9_request

#define ao_ir_t9_request()      { IFS2SET = _IFS2_T9IF_MASK; }

#endif


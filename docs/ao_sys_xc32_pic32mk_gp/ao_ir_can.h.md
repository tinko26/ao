---
author: "Stefan Wagner"
date: 2022-08-29
description: "The ao_sys_xc32_pic32mk_gp/ao_ir_can.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys_xc32_pic32mk_gp/ao_ir_can.h/ 
subtitle: "<code>ao_sys_xc32_pic32mk_gp</code>"
title: "<code>ao_ir_can.h</code>"
toc: true
---

#ifndef AO_IR_CAN1_ATTRIBUTE

#define AO_IR_CAN1_ATTRIBUTE        __ISR(_CAN1_VECTOR, IPL4SOFT)

#endif

#ifndef AO_IR_CAN1_PRIO

#define AO_IR_CAN1_PRIO             (4)

#endif

#ifndef AO_IR_CAN1_SUBPRIO

#define AO_IR_CAN1_SUBPRIO          (0)

#endif

#ifndef ao_ir_can1_disable

#define ao_ir_can1_disable()        { IEC5CLR = _IEC5_CAN1IE_MASK; }

#endif

#ifndef ao_ir_can1_enable

#define ao_ir_can1_enable()         { IEC5SET = _IEC5_CAN1IE_MASK; }

#endif

#ifndef ao_ir_can1_is_enabled

#define ao_ir_can1_is_enabled()     ((IEC5 & _IEC5_CAN1IE_MASK) ? true : false)

#endif

#ifndef ao_ir_can1_is_pending

#define ao_ir_can1_is_pending()     ((IFS5 & _IFS5_CAN1IF_MASK) ? true : false)

#endif

#ifndef ao_ir_can1_reply

#define ao_ir_can1_reply()          { IFS5CLR = _IFS5_CAN1IF_MASK; }

#endif

#ifndef ao_ir_can1_request

#define ao_ir_can1_request()        { IFS5SET = _IFS5_CAN1IF_MASK; }

#endif

#ifndef AO_IR_CAN2_ATTRIBUTE

#define AO_IR_CAN2_ATTRIBUTE        __ISR(_CAN2_VECTOR, IPL4SOFT)

#endif

#ifndef AO_IR_CAN2_PRIO

#define AO_IR_CAN2_PRIO             (4)

#endif

#ifndef AO_IR_CAN2_SUBPRIO

#define AO_IR_CAN2_SUBPRIO          (0)

#endif

#ifndef ao_ir_can2_disable

#define ao_ir_can2_disable()        { IEC5CLR = _IEC5_CAN2IE_MASK; }

#endif

#ifndef ao_ir_can2_enable

#define ao_ir_can2_enable()         { IEC5SET = _IEC5_CAN2IE_MASK; }

#endif

#ifndef ao_ir_can2_is_enabled

#define ao_ir_can2_is_enabled()     ((IEC5 & _IEC5_CAN2IE_MASK) ? true : false)

#endif

#ifndef ao_ir_can2_is_pending

#define ao_ir_can2_is_pending()     ((IFS5 & _IFS5_CAN2IF_MASK) ? true : false)

#endif

#ifndef ao_ir_can2_reply

#define ao_ir_can2_reply()          { IFS5CLR = _IFS5_CAN2IF_MASK; }

#endif

#ifndef ao_ir_can2_request

#define ao_ir_can2_request()        { IFS5SET = _IFS5_CAN2IF_MASK; }

#endif

#ifndef AO_IR_CAN3_ATTRIBUTE

#define AO_IR_CAN3_ATTRIBUTE        __ISR(_CAN3_VECTOR, IPL4SOFT)

#endif

#ifndef AO_IR_CAN3_PRIO

#define AO_IR_CAN3_PRIO             (4)

#endif

#ifndef AO_IR_CAN3_SUBPRIO

#define AO_IR_CAN3_SUBPRIO          (0)

#endif

#ifndef ao_ir_can3_disable

#define ao_ir_can3_disable()        { IEC5CLR = _IEC5_CAN3IE_MASK; }

#endif

#ifndef ao_ir_can3_enable

#define ao_ir_can3_enable()         { IEC5SET = _IEC5_CAN3IE_MASK; }

#endif

#ifndef ao_ir_can3_is_enabled

#define ao_ir_can3_is_enabled()     ((IEC5 & _IEC5_CAN3IE_MASK) ? true : false)

#endif

#ifndef ao_ir_can3_is_pending

#define ao_ir_can3_is_pending()     ((IFS5 & _IFS5_CAN3IF_MASK) ? true : false)

#endif

#ifndef ao_ir_can3_reply

#define ao_ir_can3_reply()          { IFS5CLR = _IFS5_CAN3IF_MASK; }

#endif

#ifndef ao_ir_can3_request

#define ao_ir_can3_request()        { IFS5SET = _IFS5_CAN3IF_MASK; }

#endif

#ifndef AO_IR_CAN4_ATTRIBUTE

#define AO_IR_CAN4_ATTRIBUTE        __ISR(_CAN4_VECTOR, IPL4SOFT)

#endif

#ifndef AO_IR_CAN4_PRIO

#define AO_IR_CAN4_PRIO             (4)

#endif

#ifndef AO_IR_CAN4_SUBPRIO

#define AO_IR_CAN4_SUBPRIO          (0)

#endif

#ifndef ao_ir_can4_disable

#define ao_ir_can4_disable()        { IEC5CLR = _IEC5_CAN4IE_MASK; }

#endif

#ifndef ao_ir_can4_enable

#define ao_ir_can4_enable()         { IEC5SET = _IEC5_CAN4IE_MASK; }

#endif

#ifndef ao_ir_can4_is_enabled

#define ao_ir_can4_is_enabled()     ((IEC5 & _IEC5_CAN4IE_MASK) ? true : false)

#endif

#ifndef ao_ir_can4_is_pending

#define ao_ir_can4_is_pending()     ((IFS5 & _IFS5_CAN4IF_MASK) ? true : false)

#endif

#ifndef ao_ir_can4_reply

#define ao_ir_can4_reply()          { IFS5CLR = _IFS5_CAN4IF_MASK; }

#endif

#ifndef ao_ir_can4_request

#define ao_ir_can4_request()        { IFS5SET = _IFS5_CAN4IF_MASK; }

#endif


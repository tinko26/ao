---
author: "Stefan Wagner"
breadcrumbs: 2
date: 2022-08-29
description: "The ao_sys_xc32_pic32mx_5xx/ao_ir_can.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys_xc32_pic32mx_5xx/ao_ir_can.h/ 
subtitle: "<code>ao_sys_xc32_pic32mx_5xx</code>"
title: "<code>ao_ir_can.h</code>"
toc: true
---

```c
#ifndef AO_IR_CAN1_ATTRIBUTE

#define AO_IR_CAN1_ATTRIBUTE        __ISR(_CAN_1_VECTOR, IPL4SOFT)

#endif

#ifndef AO_IR_CAN1_PRIO

#define AO_IR_CAN1_PRIO             (4)

#endif

#ifndef AO_IR_CAN1_SUBPRIO

#define AO_IR_CAN1_SUBPRIO          (0)

#endif

#ifndef ao_ir_can1_disable

#define ao_ir_can1_disable()        { IEC1CLR = _IEC1_CAN1IE_MASK; }

#endif

#ifndef ao_ir_can1_enable

#define ao_ir_can1_enable()         { IEC1SET = _IEC1_CAN1IE_MASK; }

#endif

#ifndef ao_ir_can1_is_enabled

#define ao_ir_can1_is_enabled()     ((IEC1 & _IEC1_CAN1IE_MASK) ? true : false)

#endif

#ifndef ao_ir_can1_is_pending

#define ao_ir_can1_is_pending()     ((IFS1 & _IFS1_CAN1IF_MASK) ? true : false)

#endif

#ifndef ao_ir_can1_reply

#define ao_ir_can1_reply()          { IFS1CLR = _IFS1_CAN1IF_MASK; }

#endif

#ifndef ao_ir_can1_request

#define ao_ir_can1_request()        { IFS1SET = _IFS1_CAN1IF_MASK; }

#endif

#ifndef AO_IR_CAN2_ATTRIBUTE

#define AO_IR_CAN2_ATTRIBUTE        __ISR(_CAN_2_VECTOR, IPL4SOFT)

#endif

#ifndef AO_IR_CAN2_PRIO

#define AO_IR_CAN2_PRIO             (4)

#endif

#ifndef AO_IR_CAN2_SUBPRIO

#define AO_IR_CAN2_SUBPRIO          (0)

#endif

#ifndef ao_ir_can2_disable

#define ao_ir_can2_disable()        { IEC1CLR = _IEC1_CAN2IE_MASK; }

#endif

#ifndef ao_ir_can2_enable

#define ao_ir_can2_enable()         { IEC1SET = _IEC1_CAN2IE_MASK; }

#endif

#ifndef ao_ir_can2_is_enabled

#define ao_ir_can2_is_enabled()     ((IEC1 & _IEC1_CAN2IE_MASK) ? true : false)

#endif

#ifndef ao_ir_can2_is_pending

#define ao_ir_can2_is_pending()     ((IFS1 & _IFS1_CAN2IF_MASK) ? true : false)

#endif

#ifndef ao_ir_can2_reply

#define ao_ir_can2_reply()          { IFS1CLR = _IFS1_CAN2IF_MASK; }

#endif

#ifndef ao_ir_can2_request

#define ao_ir_can2_request()        { IFS1SET = _IFS1_CAN2IF_MASK; }

#endif

```

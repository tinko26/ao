---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The ao_sys_xc32_pic32mz_da/ao_ir_can.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys_xc32_pic32mz_da/ao_ir_can.h/ 
subtitle: ""
title: "ao_ir_can.h"
toc: true
---

```c
#include <stdbool.h>
#include <sys/attribs.h>
#include <xc.h>

#ifndef AO_IR_CAN1_ATTRIBUTE

#define AO_IR_CAN1_ATTRIBUTE        __ISR(_CAN1_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_CAN1_PRIO

#define AO_IR_CAN1_PRIO             (4)

#endif

#ifndef AO_IR_CAN1_SUBPRIO

#define AO_IR_CAN1_SUBPRIO          (0)

#endif

#ifndef ao_ir_can1_disable

#define ao_ir_can1_disable()        { IEC4CLR = _IEC4_CAN1IE_MASK; }

#endif

#ifndef ao_ir_can1_enable

#define ao_ir_can1_enable()         { IEC4SET = _IEC4_CAN1IE_MASK; }

#endif

#ifndef ao_ir_can1_is_enabled

#define ao_ir_can1_is_enabled()     ((IEC4 & _IEC4_CAN1IE_MASK) ? true : false)

#endif

#ifndef ao_ir_can1_is_pending

#define ao_ir_can1_is_pending()     ((IFS4 & _IFS4_CAN1IF_MASK) ? true : false)

#endif

#ifndef ao_ir_can1_reply

#define ao_ir_can1_reply()          { IFS4CLR = _IFS4_CAN1IF_MASK; }

#endif

#ifndef ao_ir_can1_request

#define ao_ir_can1_request()        { IFS4SET = _IFS4_CAN1IF_MASK; }

#endif

#ifndef AO_IR_CAN2_ATTRIBUTE

#define AO_IR_CAN2_ATTRIBUTE        __ISR(_CAN2_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_CAN2_PRIO

#define AO_IR_CAN2_PRIO             (4)

#endif

#ifndef AO_IR_CAN2_SUBPRIO

#define AO_IR_CAN2_SUBPRIO          (0)

#endif

#ifndef ao_ir_can2_disable

#define ao_ir_can2_disable()        { IEC4CLR = _IEC4_CAN2IE_MASK; }

#endif

#ifndef ao_ir_can2_enable

#define ao_ir_can2_enable()         { IEC4SET = _IEC4_CAN2IE_MASK; }

#endif

#ifndef ao_ir_can2_is_enabled

#define ao_ir_can2_is_enabled()     ((IEC4 & _IEC4_CAN2IE_MASK) ? true : false)

#endif

#ifndef ao_ir_can2_is_pending

#define ao_ir_can2_is_pending()     ((IFS4 & _IFS4_CAN2IF_MASK) ? true : false)

#endif

#ifndef ao_ir_can2_reply

#define ao_ir_can2_reply()          { IFS4CLR = _IFS4_CAN2IF_MASK; }

#endif

#ifndef ao_ir_can2_request

#define ao_ir_can2_request()        { IFS4SET = _IFS4_CAN2IF_MASK; }

#endif

```

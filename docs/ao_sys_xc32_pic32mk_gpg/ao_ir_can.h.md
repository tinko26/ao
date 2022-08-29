---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The ao_sys_xc32_pic32mk_gpg/ao_ir_can.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys_xc32_pic32mk_gpg/ao_ir_can.h/ 
subtitle: "ao_sys_xc32_pic32mk_gpg"
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

```

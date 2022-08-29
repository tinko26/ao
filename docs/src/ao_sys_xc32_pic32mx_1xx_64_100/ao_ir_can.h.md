---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The /src/ao_sys_xc32_pic32mx_1xx_64_100/ao_ir_can.h file of the ao real-time operating system."
draft: true
permalink: /src/ao_sys_xc32_pic32mx_1xx_64_100/ao_ir_can.h/ 
subtitle: ""
title: "ao_ir_can.h"
toc: true
---

# Overview

...

# Includes

```c
#include <stdbool.h>
#include <sys/attribs.h>
#include <xc.h>

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

#define ao_ir_can1_disable()        { IEC2CLR = _IEC2_CAN1IE_MASK; }

#endif

#ifndef ao_ir_can1_enable

#define ao_ir_can1_enable()         { IEC2SET = _IEC2_CAN1IE_MASK; }

#endif

#ifndef ao_ir_can1_is_enabled

#define ao_ir_can1_is_enabled()     ((IEC2 & _IEC2_CAN1IE_MASK) ? true : false)

#endif

#ifndef ao_ir_can1_is_pending

#define ao_ir_can1_is_pending()     ((IFS2 & _IFS2_CAN1IF_MASK) ? true : false)

#endif

#ifndef ao_ir_can1_reply

#define ao_ir_can1_reply()          { IFS2CLR = _IFS2_CAN1IF_MASK; }

#endif

#ifndef ao_ir_can1_request

#define ao_ir_can1_request()        { IFS2SET = _IFS2_CAN1IF_MASK; }

#endif

```

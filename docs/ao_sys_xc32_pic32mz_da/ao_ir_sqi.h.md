---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The ao_sys_xc32_pic32mz_da/ao_ir_sqi.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys_xc32_pic32mz_da/ao_ir_sqi.h/ 
subtitle: ""
title: "ao_ir_sqi.h"
toc: true
---

# Overview

...

# Includes

```c
#include <stdbool.h>
#include <sys/attribs.h>
#include <xc.h>

#ifndef AO_IR_SQI1_ATTRIBUTE

#define AO_IR_SQI1_ATTRIBUTE        __ISR(_SQI1_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_SQI1_PRIO

#define AO_IR_SQI1_PRIO             (4)

#endif

#ifndef AO_IR_SQI1_SUBPRIO

#define AO_IR_SQI1_SUBPRIO          (0)

#endif

#ifndef ao_ir_sqi1_disable

#define ao_ir_sqi1_disable()        { IEC5CLR = _IEC5_SQI1IE_MASK; }

#endif

#ifndef ao_ir_sqi1_enable

#define ao_ir_sqi1_enable()         { IEC5SET = _IEC5_SQI1IE_MASK; }

#endif

#ifndef ao_ir_sqi1_is_enabled

#define ao_ir_sqi1_is_enabled()     ((IEC5 & _IEC5_SQI1IE_MASK) ? true : false)

#endif

#ifndef ao_ir_sqi1_is_pending

#define ao_ir_sqi1_is_pending()     ((IFS5 & _IFS5_SQI1IF_MASK) ? true : false)

#endif

#ifndef ao_ir_sqi1_reply

#define ao_ir_sqi1_reply()          { IFS5CLR = _IFS5_SQI1IF_MASK; }

#endif

#ifndef ao_ir_sqi1_request

#define ao_ir_sqi1_request()        { IFS5SET = _IFS5_SQI1IF_MASK; }

#endif

```

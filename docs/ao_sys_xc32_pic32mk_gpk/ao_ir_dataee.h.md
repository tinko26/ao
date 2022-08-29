---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The ao_sys_xc32_pic32mk_gpk/ao_ir_dataee.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys_xc32_pic32mk_gpk/ao_ir_dataee.h/ 
subtitle: "ao_sys_xc32_pic32mk_gpk"
title: "ao_ir_dataee.h"
toc: true
---

```c
#include <stdbool.h>
#include <sys/attribs.h>
#include <xc.h>

#ifndef AO_IR_DATAEE_ATTRIBUTE

#define AO_IR_DATAEE_ATTRIBUTE      __ISR(_DATA_EE_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_DATAEE_PRIO

#define AO_IR_DATAEE_PRIO           (4)

#endif

#ifndef AO_IR_DATAEE_SUBPRIO

#define AO_IR_DATAEE_SUBPRIO        (0)

#endif

#ifndef ao_ir_dataee_disable

#define ao_ir_dataee_disable()      { IEC5CLR = _IEC5_DATAEEIE_MASK; }

#endif

#ifndef ao_ir_dataee_enable

#define ao_ir_dataee_enable()       { IEC5SET = _IEC5_DATAEEIE_MASK; }

#endif

#ifndef ao_ir_dataee_is_enabled

#define ao_ir_dataee_is_enabled()   ((IEC5 & _IEC5_DATAEEIE_MASK) ? true : false)

#endif

#ifndef ao_ir_dataee_is_pending

#define ao_ir_dataee_is_pending()   ((IFS5 & _IFS5_DATAEEIF_MASK) ? true : false)

#endif

#ifndef ao_ir_dataee_reply

#define ao_ir_dataee_reply()        { IFS5CLR = _IFS5_DATAEEIF_MASK; }

#endif

#ifndef ao_ir_dataee_request

#define ao_ir_dataee_request()      { IFS5SET = _IFS5_DATAEEIF_MASK; }

#endif

```

---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The ao_sys_xc32_pic32mz_da/ao_ir_pre.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys_xc32_pic32mz_da/ao_ir_pre.h/ 
subtitle: ""
title: "ao_ir_pre.h"
toc: true
---

```c
#include <stdbool.h>
#include <sys/attribs.h>
#include <xc.h>

#ifndef AO_IR_PRE_ATTRIBUTE

#define AO_IR_PRE_ATTRIBUTE     __ISR(_PREFETCH_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_PRE_PRIO

#define AO_IR_PRE_PRIO          (4)

#endif

#ifndef AO_IR_PRE_SUBPRIO

#define AO_IR_PRE_SUBPRIO       (0)

#endif

#ifndef ao_ir_pre_disable

#define ao_ir_pre_disable()     { IEC5CLR = _IEC5_PREIE_MASK; }

#endif

#ifndef ao_ir_pre_enable

#define ao_ir_pre_enable()      { IEC5SET = _IEC5_PREIE_MASK; }

#endif

#ifndef ao_ir_pre_is_enabled

#define ao_ir_pre_is_enabled()  ((IEC5 & _IEC5_PREIE_MASK) ? true : false)

#endif

#ifndef ao_ir_pre_is_pending

#define ao_ir_pre_is_pending()  ((IFS5 & _IFS5_PREIF_MASK) ? true : false)

#endif

#ifndef ao_ir_pre_reply

#define ao_ir_pre_reply()       { IFS5CLR = _IFS5_PREIF_MASK; }

#endif

#ifndef ao_ir_pre_request

#define ao_ir_pre_request()     { IFS5SET = _IFS5_PREIF_MASK; }

#endif

```

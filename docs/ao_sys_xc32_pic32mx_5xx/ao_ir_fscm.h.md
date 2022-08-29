---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The ao_sys_xc32_pic32mx_5xx/ao_ir_fscm.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys_xc32_pic32mx_5xx/ao_ir_fscm.h/ 
subtitle: ""
title: "ao_ir_fscm.h"
toc: true
---

```c
#include <stdbool.h>
#include <sys/attribs.h>
#include <xc.h>

#ifndef AO_IR_FSCM_ATTRIBUTE

#define AO_IR_FSCM_ATTRIBUTE        __ISR(_FAIL_SAFE_MONITOR_VECTOR, IPL4SOFT)

#endif

#ifndef AO_IR_FSCM_PRIO

#define AO_IR_FSCM_PRIO             (4)

#endif

#ifndef AO_IR_FSCM_SUBPRIO

#define AO_IR_FSCM_SUBPRIO          (0)

#endif

#ifndef ao_ir_fscm_disable

#define ao_ir_fscm_disable()        { IEC1CLR = _IEC1_FSCMIE_MASK; }

#endif

#ifndef ao_ir_fscm_enable

#define ao_ir_fscm_enable()         { IEC1SET = _IEC1_FSCMIE_MASK; }

#endif

#ifndef ao_ir_fscm_is_enabled

#define ao_ir_fscm_is_enabled()     ((IEC1 & _IEC1_FSCMIE_MASK) ? true : false)

#endif

#ifndef ao_ir_fscm_is_pending

#define ao_ir_fscm_is_pending()     ((IFS1 & _IFS1_FSCMIF_MASK) ? true : false)

#endif

#ifndef ao_ir_fscm_reply

#define ao_ir_fscm_reply()          { IFS1CLR = _IFS1_FSCMIF_MASK; }

#endif

#ifndef ao_ir_fscm_request

#define ao_ir_fscm_request()        { IFS1SET = _IFS1_FSCMIF_MASK; }

#endif

```

---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The ao_sys_xc32_pic32mx_3xx/ao_ir_pmp.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys_xc32_pic32mx_3xx/ao_ir_pmp.h/ 
subtitle: ""
title: "ao_ir_pmp.h"
toc: true
---

```c
#include <stdbool.h>
#include <sys/attribs.h>
#include <xc.h>

#ifndef AO_IR_PMP_ATTRIBUTE

#define AO_IR_PMP_ATTRIBUTE         __ISR(_PMP_VECTOR, IPL4SOFT)

#endif

#ifndef AO_IR_PMP_PRIO

#define AO_IR_PMP_PRIO              (4)

#endif

#ifndef AO_IR_PMP_SUBPRIO

#define AO_IR_PMP_SUBPRIO           (0)

#endif

#ifndef ao_ir_pmp_disable

#define ao_ir_pmp_disable()         { IEC1CLR = _IEC1_PMPIE_MASK; }

#endif

#ifndef ao_ir_pmp_enable

#define ao_ir_pmp_enable()          { IEC1SET = _IEC1_PMPIE_MASK; }

#endif

#ifndef ao_ir_pmp_is_enabled

#define ao_ir_pmp_is_enabled()      ((IEC1 & _IEC1_PMPIE_MASK) ? true : false)

#endif

#ifndef ao_ir_pmp_is_pending

#define ao_ir_pmp_is_pending()      ((IFS1 & _IFS1_PMPIF_MASK) ? true : false)

#endif

#ifndef ao_ir_pmp_reply

#define ao_ir_pmp_reply()           { IFS1CLR = _IFS1_PMPIF_MASK; }

#endif

#ifndef ao_ir_pmp_request

#define ao_ir_pmp_request()         { IFS1SET = _IFS1_PMPIF_MASK; }

#endif

```

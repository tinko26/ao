---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The ao_sys_xc32_pic32mx_1xx_64_100/ao_ir_fce.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys_xc32_pic32mx_1xx_64_100/ao_ir_fce.h/ 
subtitle: "ao_sys_xc32_pic32mx_1xx_64_100"
title: "ao_ir_fce.h"
toc: true
---

```c
#include <stdbool.h>
#include <sys/attribs.h>
#include <xc.h>

#ifndef AO_IR_FCE_ATTRIBUTE

#define AO_IR_FCE_ATTRIBUTE     __ISR(_FCE_VECTOR, IPL4SOFT)

#endif

#ifndef AO_IR_FCE_PRIO

#define AO_IR_FCE_PRIO          (4)

#endif

#ifndef AO_IR_FCE_SUBPRIO

#define AO_IR_FCE_SUBPRIO       (0)

#endif

#ifndef ao_ir_fce_disable

#define ao_ir_fce_disable()     { IEC0CLR = _IEC0_FCEIE_MASK; }

#endif

#ifndef ao_ir_fce_enable

#define ao_ir_fce_enable()      { IEC0SET = _IEC0_FCEIE_MASK; }

#endif

#ifndef ao_ir_fce_is_enabled

#define ao_ir_fce_is_enabled()  ((IEC0 & _IEC0_FCEIE_MASK) ? true : false)

#endif

#ifndef ao_ir_fce_is_pending

#define ao_ir_fce_is_pending()  ((IFS0 & _IFS0_FCEIF_MASK) ? true : false)

#endif

#ifndef ao_ir_fce_reply

#define ao_ir_fce_reply()       { IFS0CLR = _IFS0_FCEIF_MASK; }

#endif

#ifndef ao_ir_fce_request

#define ao_ir_fce_request()     { IFS0SET = _IFS0_FCEIF_MASK; }

#endif

```

---
author: "Stefan Wagner"
breadcrumbs: 2
date: 2022-08-29
description: "The ao_sys_xc32_pic32mz_ef/ao_ir_crpt.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys_xc32_pic32mz_ef/ao_ir_crpt.h/ 
subtitle: "<code>ao_sys_xc32_pic32mz_ef</code>"
title: "<code>ao_ir_crpt.h</code>"
toc: true
---

```c
#ifndef AO_IR_CRPT_ATTRIBUTE

#define AO_IR_CRPT_ATTRIBUTE        __ISR(_CRYPTO_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_CRPT_PRIO

#define AO_IR_CRPT_PRIO             (4)

#endif

#ifndef AO_IR_CRPT_SUBPRIO

#define AO_IR_CRPT_SUBPRIO          (0)

#endif

#ifndef ao_ir_crpt_disable

#define ao_ir_crpt_disable()        { IEC3CLR = _IEC3_CRPTIE_MASK; }

#endif

#ifndef ao_ir_crpt_enable

#define ao_ir_crpt_enable()         { IEC3SET = _IEC3_CRPTIE_MASK; }

#endif

#ifndef ao_ir_crpt_is_enabled

#define ao_ir_crpt_is_enabled()     ((IEC3 & _IEC3_CRPTIE_MASK) ? true : false)

#endif

#ifndef ao_ir_crpt_is_pending

#define ao_ir_crpt_is_pending()     ((IFS3 & _IFS3_CRPTIF_MASK) ? true : false)

#endif

#ifndef ao_ir_crpt_reply

#define ao_ir_crpt_reply()          { IFS3CLR = _IFS3_CRPTIF_MASK; }

#endif

#ifndef ao_ir_crpt_request

#define ao_ir_crpt_request()        { IFS3SET = _IFS3_CRPTIF_MASK; }

#endif

```

---
author: "Stefan Wagner"
breadcrumbs: 2
date: 2022-08-29
description: "The ao_sys_xc32_pic32mz_da/ao_ir_mpll.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys_xc32_pic32mz_da/ao_ir_mpll.h/ 
subtitle: "<code>ao_sys_xc32_pic32mz_da</code>"
title: "<code>ao_ir_mpll.h</code>"
toc: true
---

```c
#ifndef AO_IR_MPLLFLT_ATTRIBUTE

#define AO_IR_MPLLFLT_ATTRIBUTE     __ISR(_MPLL_FAULT_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_MPLLFLT_PRIO

#define AO_IR_MPLLFLT_PRIO          (4)

#endif

#ifndef AO_IR_MPLLFLT_SUBPRIO

#define AO_IR_MPLLFLT_SUBPRIO       (0)

#endif

#ifndef ao_ir_mpllflt_disable

#define ao_ir_mpllflt_disable()     { IEC6CLR = _IEC6_MPLLFLTIE_MASK; }

#endif

#ifndef ao_ir_mpllflt_enable

#define ao_ir_mpllflt_enable()      { IEC6SET = _IEC6_MPLLFLTIE_MASK; }

#endif

#ifndef ao_ir_mpllflt_is_enabled

#define ao_ir_mpllflt_is_enabled()  ((IEC6 & _IEC6_MPLLFLTIE_MASK) ? true : false)

#endif

#ifndef ao_ir_mpllflt_is_pending

#define ao_ir_mpllflt_is_pending()  ((IFS6 & _IFS6_MPLLFLTIF_MASK) ? true : false)

#endif

#ifndef ao_ir_mpllflt_reply

#define ao_ir_mpllflt_reply()       { IFS6CLR = _IFS6_MPLLFLTIF_MASK; }

#endif

#ifndef ao_ir_mpllflt_request

#define ao_ir_mpllflt_request()     { IFS6SET = _IFS6_MPLLFLTIF_MASK; }

#endif

```

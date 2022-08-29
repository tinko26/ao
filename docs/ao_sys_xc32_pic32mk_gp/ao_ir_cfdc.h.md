---
author: "Stefan Wagner"
breadcrumbs: 2
date: 2022-08-29
description: "The ao_sys_xc32_pic32mk_gp/ao_ir_cfdc.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys_xc32_pic32mk_gp/ao_ir_cfdc.h/ 
subtitle: "<code>ao_sys_xc32_pic32mk_gp</code>"
title: "<code>ao_ir_cfdc.h</code>"
toc: true
---

```c
#ifndef AO_IR_CFDC_ATTRIBUTE

#define AO_IR_CFDC_ATTRIBUTE        __ISR(_CORE_FAST_DEBUG_CHAN_VECTOR, IPL4SOFT)

#endif

#ifndef AO_IR_CFDC_PRIO

#define AO_IR_CFDC_PRIO             (4)

#endif

#ifndef AO_IR_CFDC_SUBPRIO

#define AO_IR_CFDC_SUBPRIO          (0)

#endif

#ifndef ao_ir_cfdc_disable

#define ao_ir_cfdc_disable()        { IEC7CLR = _IEC7_CFDCIE_MASK; }

#endif

#ifndef ao_ir_cfdc_enable

#define ao_ir_cfdc_enable()         { IEC7SET = _IEC7_CFDCIE_MASK; }

#endif

#ifndef ao_ir_cfdc_is_enabled

#define ao_ir_cfdc_is_enabled()     ((IEC7 & _IEC7_CFDCIE_MASK) ? true : false)

#endif

#ifndef ao_ir_cfdc_is_pending

#define ao_ir_cfdc_is_pending()     ((IFS7 & _IFS7_CFDCIF_MASK) ? true : false)

#endif

#ifndef ao_ir_cfdc_reply

#define ao_ir_cfdc_reply()          { IFS7CLR = _IFS7_CFDCIF_MASK; }

#endif

#ifndef ao_ir_cfdc_request

#define ao_ir_cfdc_request()        { IFS7SET = _IFS7_CFDCIF_MASK; }

#endif

```

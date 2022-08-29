---
author: "Stefan Wagner"
breadcrumbs: 2
date: 2022-08-29
description: "The ao_sys_xc32_pic32mk_gpg/ao_ir_cpc.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys_xc32_pic32mk_gpg/ao_ir_cpc.h/ 
subtitle: "<code>ao_sys_xc32_pic32mk_gpg</code>"
title: "<code>ao_ir_cpc.h</code>"
toc: true
---

```c
#ifndef AO_IR_CPC_ATTRIBUTE

#define AO_IR_CPC_ATTRIBUTE     __ISR(_CORE_PERF_COUNT_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_CPC_PRIO

#define AO_IR_CPC_PRIO          (4)

#endif

#ifndef AO_IR_CPC_SUBPRIO

#define AO_IR_CPC_SUBPRIO       (0)

#endif

#ifndef ao_ir_cpc_disable

#define ao_ir_cpc_disable()     { IEC7CLR = _IEC7_CPCIE_MASK; }

#endif

#ifndef ao_ir_cpc_enable

#define ao_ir_cpc_enable()      { IEC7SET = _IEC7_CPCIE_MASK; }

#endif

#ifndef ao_ir_cpc_is_enabled

#define ao_ir_cpc_is_enabled()  ((IEC7 & _IEC7_CPCIE_MASK) ? true : false)

#endif

#ifndef ao_ir_cpc_is_pending

#define ao_ir_cpc_is_pending()  ((IFS7 & _IFS7_CPCIF_MASK) ? true : false)

#endif

#ifndef ao_ir_cpc_reply

#define ao_ir_cpc_reply()       { IFS7CLR = _IFS7_CPCIF_MASK; }

#endif

#ifndef ao_ir_cpc_request

#define ao_ir_cpc_request()     { IFS7SET = _IFS7_CPCIF_MASK; }

#endif

```

---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The ao_sys_xc32_pic32mz_da/ao_ir_cpc.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys_xc32_pic32mz_da/ao_ir_cpc.h/ 
subtitle: ""
title: "ao_ir_cpc.h"
toc: true
---

```c
#include <stdbool.h>
#include <sys/attribs.h>
#include <xc.h>

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

#define ao_ir_cpc_disable()     { IEC3CLR = _IEC3_CPCIE_MASK; }

#endif

#ifndef ao_ir_cpc_enable

#define ao_ir_cpc_enable()      { IEC3SET = _IEC3_CPCIE_MASK; }

#endif

#ifndef ao_ir_cpc_is_enabled

#define ao_ir_cpc_is_enabled()  ((IEC3 & _IEC3_CPCIE_MASK) ? true : false)

#endif

#ifndef ao_ir_cpc_is_pending

#define ao_ir_cpc_is_pending()  ((IFS3 & _IFS3_CPCIF_MASK) ? true : false)

#endif

#ifndef ao_ir_cpc_reply

#define ao_ir_cpc_reply()       { IFS3CLR = _IFS3_CPCIF_MASK; }

#endif

#ifndef ao_ir_cpc_request

#define ao_ir_cpc_request()     { IFS3SET = _IFS3_CPCIF_MASK; }

#endif

```

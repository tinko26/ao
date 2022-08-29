---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The ao_sys_xc32_pic32mz_dak/ao_ir_cfdc.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys_xc32_pic32mz_dak/ao_ir_cfdc.h/ 
subtitle: ""
title: "ao_ir_cfdc.h"
toc: true
---

```c
#include <stdbool.h>
#include <sys/attribs.h>
#include <xc.h>

#ifndef AO_IR_CFDC_ATTRIBUTE

#define AO_IR_CFDC_ATTRIBUTE        __ISR(_CORE_FAST_DEBUG_CHAN_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_CFDC_PRIO

#define AO_IR_CFDC_PRIO             (4)

#endif

#ifndef AO_IR_CFDC_SUBPRIO

#define AO_IR_CFDC_SUBPRIO          (0)

#endif

#ifndef ao_ir_cfdc_disable

#define ao_ir_cfdc_disable()        { IEC3CLR = _IEC3_CFDCIE_MASK; }

#endif

#ifndef ao_ir_cfdc_enable

#define ao_ir_cfdc_enable()         { IEC3SET = _IEC3_CFDCIE_MASK; }

#endif

#ifndef ao_ir_cfdc_is_enabled

#define ao_ir_cfdc_is_enabled()     ((IEC3 & _IEC3_CFDCIE_MASK) ? true : false)

#endif

#ifndef ao_ir_cfdc_is_pending

#define ao_ir_cfdc_is_pending()     ((IFS3 & _IFS3_CFDCIF_MASK) ? true : false)

#endif

#ifndef ao_ir_cfdc_reply

#define ao_ir_cfdc_reply()          { IFS3CLR = _IFS3_CFDCIF_MASK; }

#endif

#ifndef ao_ir_cfdc_request

#define ao_ir_cfdc_request()        { IFS3SET = _IFS3_CFDCIF_MASK; }

#endif

```

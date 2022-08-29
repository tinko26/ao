---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The ao_sys_xc32_pic32mz_da/ao_ir_ct.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys_xc32_pic32mz_da/ao_ir_ct.h/ 
subtitle: ""
title: "ao_ir_ct.h"
toc: true
---

# Overview

...

# Includes

```c
#include <stdbool.h>
#include <sys/attribs.h>
#include <xc.h>

#ifndef AO_IR_CT_ATTRIBUTE

#define AO_IR_CT_ATTRIBUTE      __ISR(_CORE_TIMER_VECTOR, IPL3SRS)

#endif

#ifndef AO_IR_CT_PRIO

#define AO_IR_CT_PRIO           (3)

#endif

#ifndef AO_IR_CT_SUBPRIO

#define AO_IR_CT_SUBPRIO        (0)

#endif

#ifndef ao_ir_ct_disable

#define ao_ir_ct_disable()      { IEC0CLR = _IEC0_CTIE_MASK; }

#endif

#ifndef ao_ir_ct_enable

#define ao_ir_ct_enable()       { IEC0SET = _IEC0_CTIE_MASK; }

#endif

#ifndef ao_ir_ct_is_enabled

#define ao_ir_ct_is_enabled()   ((IEC0 & _IEC0_CTIE_MASK) ? true : false)

#endif

#ifndef ao_ir_ct_is_pending

#define ao_ir_ct_is_pending()   ((IFS0 & _IFS0_CTIF_MASK) ? true : false)

#endif

#ifndef ao_ir_ct_reply

#define ao_ir_ct_reply()        { IFS0CLR = _IFS0_CTIF_MASK; }

#endif

#ifndef ao_ir_ct_request

#define ao_ir_ct_request()      { IFS0SET = _IFS0_CTIF_MASK; }

#endif

```

---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The ao_sys_xc32_pic32mz_dak/ao_ir_ctmu.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys_xc32_pic32mz_dak/ao_ir_ctmu.h/ 
subtitle: ""
title: "ao_ir_ctmu.h"
toc: true
---

# Overview

...

# Includes

```c
#include <stdbool.h>
#include <sys/attribs.h>
#include <xc.h>

#ifndef AO_IR_CTMU_ATTRIBUTE

#define AO_IR_CTMU_ATTRIBUTE        __ISR(_CTMU_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_CTMU_PRIO

#define AO_IR_CTMU_PRIO             (4)

#endif

#ifndef AO_IR_CTMU_SUBPRIO

#define AO_IR_CTMU_SUBPRIO          (0)

#endif

#ifndef ao_ir_ctmu_disable

#define ao_ir_ctmu_disable()        { IEC6CLR = _IEC6_CTMUIE_MASK; }

#endif

#ifndef ao_ir_ctmu_enable

#define ao_ir_ctmu_enable()         { IEC6SET = _IEC6_CTMUIE_MASK; }

#endif

#ifndef ao_ir_ctmu_is_enabled

#define ao_ir_ctmu_is_enabled()     ((IEC6 & _IEC6_CTMUIE_MASK) ? true : false)

#endif

#ifndef ao_ir_ctmu_is_pending

#define ao_ir_ctmu_is_pending()     ((IFS6 & _IFS6_CTMUIF_MASK) ? true : false)

#endif

#ifndef ao_ir_ctmu_reply

#define ao_ir_ctmu_reply()          { IFS6CLR = _IFS6_CTMUIF_MASK; }

#endif

#ifndef ao_ir_ctmu_request

#define ao_ir_ctmu_request()        { IFS6SET = _IFS6_CTMUIF_MASK; }

#endif

```

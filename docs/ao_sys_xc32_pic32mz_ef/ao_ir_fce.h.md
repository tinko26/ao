---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The ao_sys_xc32_pic32mz_ef/ao_ir_fce.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys_xc32_pic32mz_ef/ao_ir_fce.h/ 
subtitle: ""
title: "ao_ir_fce.h"
toc: true
---

# Overview

...

# Includes

```c
#include <stdbool.h>
#include <sys/attribs.h>
#include <xc.h>

#ifndef AO_IR_FCE_ATTRIBUTE

#define AO_IR_FCE_ATTRIBUTE     __ISR(_FLASH_CONTROL_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_FCE_PRIO

#define AO_IR_FCE_PRIO          (4)

#endif

#ifndef AO_IR_FCE_SUBPRIO

#define AO_IR_FCE_SUBPRIO       (0)

#endif

#ifndef ao_ir_fce_disable

#define ao_ir_fce_disable()     { IEC5CLR = _IEC5_FCEIE_MASK; }

#endif

#ifndef ao_ir_fce_enable

#define ao_ir_fce_enable()      { IEC5SET = _IEC5_FCEIE_MASK; }

#endif

#ifndef ao_ir_fce_is_enabled

#define ao_ir_fce_is_enabled()  ((IEC5 & _IEC5_FCEIE_MASK) ? true : false)

#endif

#ifndef ao_ir_fce_is_pending

#define ao_ir_fce_is_pending()  ((IFS5 & _IFS5_FCEIF_MASK) ? true : false)

#endif

#ifndef ao_ir_fce_reply

#define ao_ir_fce_reply()       { IFS5CLR = _IFS5_FCEIF_MASK; }

#endif

#ifndef ao_ir_fce_request

#define ao_ir_fce_request()     { IFS5SET = _IFS5_FCEIF_MASK; }

#endif

```

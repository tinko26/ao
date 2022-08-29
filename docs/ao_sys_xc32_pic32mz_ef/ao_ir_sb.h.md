---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The ao_sys_xc32_pic32mz_ef/ao_ir_sb.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys_xc32_pic32mz_ef/ao_ir_sb.h/ 
subtitle: ""
title: "ao_ir_sb.h"
toc: true
---

# Overview

...

# Includes

```c
#include <stdbool.h>
#include <sys/attribs.h>
#include <xc.h>

#ifndef AO_IR_SB_ATTRIBUTE

#define AO_IR_SB_ATTRIBUTE      __ISR(_SYSTEM_BUS_PROTECTION_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_SB_PRIO

#define AO_IR_SB_PRIO           (4)

#endif

#ifndef AO_IR_SB_SUBPRIO

#define AO_IR_SB_SUBPRIO        (0)

#endif

#ifndef ao_ir_sb_disable

#define ao_ir_sb_disable()      { IEC3CLR = _IEC3_SBIE_MASK; }

#endif

#ifndef ao_ir_sb_enable

#define ao_ir_sb_enable()       { IEC3SET = _IEC3_SBIE_MASK; }

#endif

#ifndef ao_ir_sb_is_enabled

#define ao_ir_sb_is_enabled()   ((IEC3 & _IEC3_SBIE_MASK) ? true : false)

#endif

#ifndef ao_ir_sb_is_pending

#define ao_ir_sb_is_pending()   ((IFS3 & _IFS3_SBIF_MASK) ? true : false)

#endif

#ifndef ao_ir_sb_reply

#define ao_ir_sb_reply()        { IFS3CLR = _IFS3_SBIF_MASK; }

#endif

#ifndef ao_ir_sb_request

#define ao_ir_sb_request()      { IFS3SET = _IFS3_SBIF_MASK; }

#endif

```

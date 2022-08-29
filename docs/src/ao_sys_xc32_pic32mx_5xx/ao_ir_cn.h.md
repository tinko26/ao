---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The /src/ao_sys_xc32_pic32mx_5xx/ao_ir_cn.h file of the ao real-time operating system."
draft: true
permalink: /src/ao_sys_xc32_pic32mx_5xx/ao_ir_cn.h/ 
subtitle: ""
title: "ao_ir_cn.h"
toc: true
---

# Overview

...

# Includes

```c
#include <stdbool.h>
#include <sys/attribs.h>
#include <xc.h>

#ifndef AO_IR_CN_ATTRIBUTE

#define AO_IR_CN_ATTRIBUTE      __ISR(_CHANGE_NOTICE_VECTOR, IPL4SOFT)

#endif

#ifndef AO_IR_CN_PRIO

#define AO_IR_CN_PRIO           (4)

#endif

#ifndef AO_IR_CN_SUBPRIO

#define AO_IR_CN_SUBPRIO        (0)

#endif

#ifndef ao_ir_cn_disable

#define ao_ir_cn_disable()      { IEC1CLR = _IEC1_CNIE_MASK; }

#endif

#ifndef ao_ir_cn_enable

#define ao_ir_cn_enable()       { IEC1SET = _IEC1_CNIE_MASK; }

#endif

#ifndef ao_ir_cn_is_enabled

#define ao_ir_cn_is_enabled()   ((IEC1 & _IEC1_CNIE_MASK) ? true : false)

#endif

#ifndef ao_ir_cn_is_pending

#define ao_ir_cn_is_pending()   ((IFS1 & _IFS1_CNIF_MASK) ? true : false)

#endif

#ifndef ao_ir_cn_reply

#define ao_ir_cn_reply()        { IFS1CLR = _IFS1_CNIF_MASK; }

#endif

#ifndef ao_ir_cn_request

#define ao_ir_cn_request()      { IFS1SET = _IFS1_CNIF_MASK; }

#endif

```

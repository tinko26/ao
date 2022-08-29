---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The ao_sys_xc32_pic32mx_1xx/ao_ir_cn.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys_xc32_pic32mx_1xx/ao_ir_cn.h/ 
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

#ifndef ao_ir_cna_disable

#define ao_ir_cna_disable()     { IEC1CLR = _IEC1_CNAIE_MASK; }

#endif

#ifndef ao_ir_cna_enable

#define ao_ir_cna_enable()      { IEC1SET = _IEC1_CNAIE_MASK; }

#endif

#ifndef ao_ir_cna_is_enabled

#define ao_ir_cna_is_enabled()  ((IEC1 & _IEC1_CNAIE_MASK) ? true : false)

#endif

#ifndef ao_ir_cna_is_pending

#define ao_ir_cna_is_pending()  ((IFS1 & _IFS1_CNAIF_MASK) ? true : false)

#endif

#ifndef ao_ir_cna_reply

#define ao_ir_cna_reply()       { IFS1CLR = _IFS1_CNAIF_MASK; }

#endif

#ifndef ao_ir_cna_request

#define ao_ir_cna_request()     { IFS1SET = _IFS1_CNAIF_MASK; }

#endif

#ifndef ao_ir_cnb_disable

#define ao_ir_cnb_disable()     { IEC1CLR = _IEC1_CNBIE_MASK; }

#endif

#ifndef ao_ir_cnb_enable

#define ao_ir_cnb_enable()      { IEC1SET = _IEC1_CNBIE_MASK; }

#endif

#ifndef ao_ir_cnb_is_enabled

#define ao_ir_cnb_is_enabled()  ((IEC1 & _IEC1_CNBIE_MASK) ? true : false)

#endif

#ifndef ao_ir_cnb_is_pending

#define ao_ir_cnb_is_pending()  ((IFS1 & _IFS1_CNBIF_MASK) ? true : false)

#endif

#ifndef ao_ir_cnb_reply

#define ao_ir_cnb_reply()       { IFS1CLR = _IFS1_CNBIF_MASK; }

#endif

#ifndef ao_ir_cnb_request

#define ao_ir_cnb_request()     { IFS1SET = _IFS1_CNBIF_MASK; }

#endif

#ifndef ao_ir_cnc_disable

#define ao_ir_cnc_disable()     { IEC1CLR = _IEC1_CNCIE_MASK; }

#endif

#ifndef ao_ir_cnc_enable

#define ao_ir_cnc_enable()      { IEC1SET = _IEC1_CNCIE_MASK; }

#endif

#ifndef ao_ir_cnc_is_enabled

#define ao_ir_cnc_is_enabled()  ((IEC1 & _IEC1_CNCIE_MASK) ? true : false)

#endif

#ifndef ao_ir_cnc_is_pending

#define ao_ir_cnc_is_pending()  ((IFS1 & _IFS1_CNCIF_MASK) ? true : false)

#endif

#ifndef ao_ir_cnc_reply

#define ao_ir_cnc_reply()       { IFS1CLR = _IFS1_CNCIF_MASK; }

#endif

#ifndef ao_ir_cnc_request

#define ao_ir_cnc_request()     { IFS1SET = _IFS1_CNCIF_MASK; }

#endif

```

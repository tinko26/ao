---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The ao_sys_xc32_pic32mk_gpg/ao_ir_cs.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys_xc32_pic32mk_gpg/ao_ir_cs.h/ 
subtitle: ""
title: "ao_ir_cs.h"
toc: true
---

```c
#include <stdbool.h>
#include <sys/attribs.h>
#include <xc.h>

#ifndef AO_IR_CS0_ATTRIBUTE

#define AO_IR_CS0_ATTRIBUTE     __ISR(_CORE_SOFTWARE_0_VECTOR, IPL2SRS)

#endif

#ifndef AO_IR_CS0_PRIO

#define AO_IR_CS0_PRIO          (2)

#endif

#ifndef AO_IR_CS0_SUBPRIO

#define AO_IR_CS0_SUBPRIO       (0)

#endif

#ifndef ao_ir_cs0_disable

#define ao_ir_cs0_disable()     { IEC0CLR = _IEC0_CS0IE_MASK; }

#endif

#ifndef ao_ir_cs0_enable

#define ao_ir_cs0_enable()      { IEC0SET = _IEC0_CS0IE_MASK; }

#endif

#ifndef ao_ir_cs0_is_enabled

#define ao_ir_cs0_is_enabled()  ((IEC0 & _IEC0_CS0IE_MASK) ? true : false)

#endif

#ifndef ao_ir_cs0_is_pending

#define ao_ir_cs0_is_pending()  ((IFS0 & _IFS0_CS0IF_MASK) ? true : false)

#endif

#ifndef ao_ir_cs0_reply

#define ao_ir_cs0_reply()       { IFS0CLR = _IFS0_CS0IF_MASK; }

#endif

#ifndef ao_ir_cs0_request

#define ao_ir_cs0_request()     { IFS0SET = _IFS0_CS0IF_MASK; }

#endif

#ifndef AO_IR_CS1_ATTRIBUTE

#define AO_IR_CS1_ATTRIBUTE     __attribute__ ((naked, vector(_CORE_SOFTWARE_1_VECTOR)))

#endif

#ifndef AO_IR_CS1_PRIO

#define AO_IR_CS1_PRIO          (1)

#endif

#ifndef AO_IR_CS1_SUBPRIO

#define AO_IR_CS1_SUBPRIO       (0)

#endif

#ifndef ao_ir_cs1_disable

#define ao_ir_cs1_disable()     { IEC0CLR = _IEC0_CS1IE_MASK; }

#endif

#ifndef ao_ir_cs1_enable

#define ao_ir_cs1_enable()      { IEC0SET = _IEC0_CS1IE_MASK; }

#endif

#ifndef ao_ir_cs1_is_enabled

#define ao_ir_cs1_is_enabled()  ((IEC0 & _IEC0_CS1IE_MASK) ? true : false)

#endif

#ifndef ao_ir_cs1_is_pending

#define ao_ir_cs1_is_pending()  ((IFS0 & _IFS0_CS1IF_MASK) ? true : false)

#endif

#ifndef ao_ir_cs1_reply

#define ao_ir_cs1_reply()       { IFS0CLR = _IFS0_CS1IF_MASK; }

#endif

#ifndef ao_ir_cs1_request

#define ao_ir_cs1_request()     { IFS0SET = _IFS0_CS1IF_MASK; }

#endif

```

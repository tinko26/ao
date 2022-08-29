---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The /src/ao_sys_xc32_pic32mk_gpg/ao_ir_rtcc.h file of the ao real-time operating system."
draft: true
permalink: /src/ao_sys_xc32_pic32mk_gpg/ao_ir_rtcc.h/ 
subtitle: ""
title: "ao_ir_rtcc.h"
toc: true
---

# Overview

...

# Includes

```c
#include <stdbool.h>
#include <sys/attribs.h>
#include <xc.h>

#ifndef AO_IR_RTCC_ATTRIBUTE

#define AO_IR_RTCC_ATTRIBUTE        __ISR(_RTCC_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_RTCC_PRIO

#define AO_IR_RTCC_PRIO             (4)

#endif

#ifndef AO_IR_RTCC_SUBPRIO

#define AO_IR_RTCC_SUBPRIO          (0)

#endif

#ifndef ao_ir_rtcc_disable

#define ao_ir_rtcc_disable()        { IEC0CLR = _IEC0_RTCCIE_MASK; }

#endif

#ifndef ao_ir_rtcc_enable

#define ao_ir_rtcc_enable()         { IEC0SET = _IEC0_RTCCIE_MASK; }

#endif

#ifndef ao_ir_rtcc_is_enabled

#define ao_ir_rtcc_is_enabled()     ((IEC0 & _IEC0_RTCCIE_MASK) ? true : false)

#endif

#ifndef ao_ir_rtcc_is_pending

#define ao_ir_rtcc_is_pending()     ((IFS0 & _IFS0_RTCCIF_MASK) ? true : false)

#endif

#ifndef ao_ir_rtcc_reply

#define ao_ir_rtcc_reply()          { IFS0CLR = _IFS0_RTCCIF_MASK; }

#endif

#ifndef ao_ir_rtcc_request

#define ao_ir_rtcc_request()        { IFS0SET = _IFS0_RTCCIF_MASK; }

#endif

```

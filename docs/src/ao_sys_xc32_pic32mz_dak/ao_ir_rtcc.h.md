---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The /src/ao_sys_xc32_pic32mz_dak/ao_ir_rtcc.h file of the ao real-time operating system."
draft: true
permalink: /src/ao_sys_xc32_pic32mz_dak/ao_ir_rtcc.h/ 
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

#define ao_ir_rtcc_disable()        { IEC5CLR = _IEC5_RTCCIE_MASK; }

#endif

#ifndef ao_ir_rtcc_enable

#define ao_ir_rtcc_enable()         { IEC5SET = _IEC5_RTCCIE_MASK; }

#endif

#ifndef ao_ir_rtcc_is_enabled

#define ao_ir_rtcc_is_enabled()     ((IEC5 & _IEC5_RTCCIE_MASK) ? true : false)

#endif

#ifndef ao_ir_rtcc_is_pending

#define ao_ir_rtcc_is_pending()     ((IFS5 & _IFS5_RTCCIF_MASK) ? true : false)

#endif

#ifndef ao_ir_rtcc_reply

#define ao_ir_rtcc_reply()          { IFS5CLR = _IFS5_RTCCIF_MASK; }

#endif

#ifndef ao_ir_rtcc_request

#define ao_ir_rtcc_request()        { IFS5SET = _IFS5_RTCCIF_MASK; }

#endif

```

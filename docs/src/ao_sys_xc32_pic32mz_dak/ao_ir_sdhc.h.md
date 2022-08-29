---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The /src/ao_sys_xc32_pic32mz_dak/ao_ir_sdhc.h file of the ao real-time operating system."
draft: true
permalink: /src/ao_sys_xc32_pic32mz_dak/ao_ir_sdhc.h/ 
subtitle: ""
title: "ao_ir_sdhc.h"
toc: true
---

# Overview

...

# Includes

```c
#include <stdbool.h>
#include <sys/attribs.h>
#include <xc.h>

#ifndef AO_IR_SDHC_ATTRIBUTE

#define AO_IR_SDHC_ATTRIBUTE        __ISR(_SDHC_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_SDHC_PRIO

#define AO_IR_SDHC_PRIO             (4)

#endif

#ifndef AO_IR_SDHC_SUBPRIO

#define AO_IR_SDHC_SUBPRIO          (0)

#endif

#ifndef ao_ir_sdhc_disable

#define ao_ir_sdhc_disable()        { IEC5CLR = _IEC5_SDHCIE_MASK; }

#endif

#ifndef ao_ir_sdhc_enable

#define ao_ir_sdhc_enable()         { IEC5SET = _IEC5_SDHCIE_MASK; }

#endif

#ifndef ao_ir_sdhc_is_enabled

#define ao_ir_sdhc_is_enabled()     ((IEC5 & _IEC5_SDHCIE_MASK) ? true : false)

#endif

#ifndef ao_ir_sdhc_is_pending

#define ao_ir_sdhc_is_pending()     ((IFS5 & _IFS5_SDHCIF_MASK) ? true : false)

#endif

#ifndef ao_ir_sdhc_reply

#define ao_ir_sdhc_reply()          { IFS5CLR = _IFS5_SDHCIF_MASK; }

#endif

#ifndef ao_ir_sdhc_request

#define ao_ir_sdhc_request()        { IFS5SET = _IFS5_SDHCIF_MASK; }

#endif

```

---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The /src/ao_sys_xc32_pic32mk_gpg/ao_ir_pcache.h file of the ao real-time operating system."
draft: true
permalink: /src/ao_sys_xc32_pic32mk_gpg/ao_ir_pcache.h/ 
subtitle: ""
title: "ao_ir_pcache.h"
toc: true
---

# Overview

...

# Includes

```c
#include <stdbool.h>
#include <sys/attribs.h>
#include <xc.h>

#ifndef AO_IR_PCACHE_ATTRIBUTE

#define AO_IR_PCACHE_ATTRIBUTE      __ISR(_PCACHE_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_PCACHE_PRIO

#define AO_IR_PCACHE_PRIO           (4)

#endif

#ifndef AO_IR_PCACHE_SUBPRIO

#define AO_IR_PCACHE_SUBPRIO        (0)

#endif

#ifndef ao_ir_pcache_disable

#define ao_ir_pcache_disable()      { IEC7CLR = _IEC7_PCACHEIE_MASK; }

#endif

#ifndef ao_ir_pcache_enable

#define ao_ir_pcache_enable()       { IEC7SET = _IEC7_PCACHEIE_MASK; }

#endif

#ifndef ao_ir_pcache_is_enabled

#define ao_ir_pcache_is_enabled()   ((IEC7 & _IEC7_PCACHEIE_MASK) ? true : false)

#endif

#ifndef ao_ir_pcache_is_pending

#define ao_ir_pcache_is_pending()   ((IFS7 & _IFS7_PCACHEIF_MASK) ? true : false)

#endif

#ifndef ao_ir_pcache_reply

#define ao_ir_pcache_reply()        { IFS7CLR = _IFS7_PCACHEIF_MASK; }

#endif

#ifndef ao_ir_pcache_request

#define ao_ir_pcache_request()      { IFS7SET = _IFS7_PCACHEIF_MASK; }

#endif

```

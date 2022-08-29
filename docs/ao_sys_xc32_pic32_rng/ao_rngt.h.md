---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The ao_sys_xc32_pic32_rng/ao_rngt.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys_xc32_pic32_rng/ao_rngt.h/ 
subtitle: "ao_sys_xc32_pic32_rng"
title: "ao_rngt.h"
toc: true
---

```c
#include <stdint.h>
#include <xc.h>

#ifndef ao_rngt_disable

#define ao_rngt_disable()   { RNGCONbits.TRNGEN = 0; }

#endif

#ifndef ao_rngt_enable

#define ao_rngt_enable()    { RNGCONbits.TRNGEN = 1; }

#endif

#ifndef ao_rngt_bits

#define ao_rngt_bits()      (RNGCNT)

#endif

#ifndef ao_rngt_value

#define ao_rngt_value()     (((uint64_t) RNGSEED2 << 32) | (uint64_t) RNGSEED1)

#endif

#ifndef ao_rngt_value_hi

#define ao_rngt_value_hi()  (RNGSEED2)

#endif

#ifndef ao_rngt_value_lo

#define ao_rngt_value_lo()  (RNGSEED1)

#endif

```

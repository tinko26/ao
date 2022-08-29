---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The ao_sys_xc32_pic32/ao_count.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys_xc32_pic32/ao_count.h/ 
subtitle: ""
title: "ao_count.h"
toc: true
---

```c
#include <ao_sys.h>
#include <stdint.h>
#include <xc.h>

typedef uint32_t                    ao_count_t;

#ifndef AO_COUNT_MAX

#define AO_COUNT_MAX                (UINT32_MAX)

#endif

#ifndef AO_COUNT_MIN

#define AO_COUNT_MIN                (0)

#endif

#ifndef AO_COUNT_FREQUENCY

#define AO_COUNT_FREQUENCY          ((AO_SYS_SYSCLK) / 2)

#endif

#ifndef ao_count

#define ao_count()                  _CP0_GET_COUNT()

#endif

#ifndef ao_count_debug_continue

#define ao_count_debug_continue()   _CP0_BIS_DEBUG(_CP0_DEBUG_COUNTDM_MASK)

#endif

#ifndef ao_count_debug_stop

#define ao_count_debug_stop()       _CP0_BIC_DEBUG(_CP0_DEBUG_COUNTDM_MASK)

#endif

```

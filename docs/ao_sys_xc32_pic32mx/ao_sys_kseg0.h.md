---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The ao_sys_xc32_pic32mx/ao_sys_kseg0.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys_xc32_pic32mx/ao_sys_kseg0.h/ 
subtitle: ""
title: "ao_sys_kseg0.h"
toc: true
---

```c
#include <xc.h>

#ifndef ao_sys_kseg0_cacheable

#define ao_sys_kseg0_cacheable()    _bcsc0(_CP0_CONFIG, _CP0_CONFIG_SELECT, 4, 3)

#endif

#ifndef ao_sys_kseg0_uncached

#define ao_sys_kseg0_uncached()     _bcsc0(_CP0_CONFIG, _CP0_CONFIG_SELECT, 5, 2)

#endif

```

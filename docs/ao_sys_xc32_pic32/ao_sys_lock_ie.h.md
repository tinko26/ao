---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The ao_sys_xc32_pic32/ao_sys_lock_ie.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys_xc32_pic32/ao_sys_lock_ie.h/ 
subtitle: ""
title: "ao_sys_lock_ie.h"
toc: true
---

```c
#include <xc.h>

#ifndef ao_sys_lock_ie

#define ao_sys_lock_ie()        __builtin_disable_interrupts()

#endif

#ifndef ao_sys_unlock_ie

#define ao_sys_unlock_ie(x)     _CP0_SET_STATUS(x)

#endif

```

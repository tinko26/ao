---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The ao_sys_xc32_pic32/ao_break.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys_xc32_pic32/ao_break.h/ 
subtitle: ""
title: "ao_break.h"
toc: true
---

```c
#include <ao_debug.h>

#if     AO_DEBUG

#ifndef ao_break

#define ao_break()  __builtin_software_breakpoint()

#endif

#else

#ifndef ao_break

#define ao_break()

#endif

#endif

```

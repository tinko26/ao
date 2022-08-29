---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The ao_sys_xc32_pic32/ao_mem.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys_xc32_pic32/ao_mem.h/ 
subtitle: "ao_sys_xc32_pic32"
title: "ao_mem.h"
toc: true
---

```c
#include <string.h>

#ifndef ao_memcpy

#define ao_memcpy(d, s, n)      memcpy(d, s, n)

#endif

#ifndef ao_memmove

#define ao_memmove(d, s, n)     memmove(d, s, n)

#endif

#ifndef ao_memset

#define ao_memset(p, v, n)      memset(p, (int) (v), n)

#endif

```

---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The ao_sys_xc32_pic32/ao_float.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys_xc32_pic32/ao_float.h/ 
subtitle: "ao_sys_xc32_pic32"
title: "ao_float.h"
toc: true
---

```c
#ifndef AO_FLOAT

#define AO_FLOAT    (32)

#endif

#if     AO_FLOAT == (32)

#include <ao_floatf.h>

#elif   AO_FLOAT == (64)

#include <ao_floatl.h>

#endif

```

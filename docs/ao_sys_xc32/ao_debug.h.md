---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The ao_sys_xc32/ao_debug.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys_xc32/ao_debug.h/ 
subtitle: "ao_sys_xc32"
title: "ao_debug.h"
toc: true
---

```c
#include <stdbool.h>

#ifndef AO_DEBUG

#ifndef NDEBUG

#ifndef __DEBUG

#define AO_DEBUG    (false)

#else

#define AO_DEBUG    (true)

#endif

#else

#define AO_DEBUG    (false)

#endif

#endif

```

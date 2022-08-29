---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The ao_sys/ao_core.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys/ao_core.h/ 
subtitle: "ao_sys"
title: "ao_core.h"
toc: true
---

```c
#include <stdint.h>

typedef     uint32_t        ao_core_t;

#ifndef     AO_CORE_COUNT

#define     AO_CORE_COUNT   (1)

#endif

ao_core_t   ao_core();

```

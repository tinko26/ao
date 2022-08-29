---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The ao_sys/ao_yield.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys/ao_yield.h/ 
subtitle: ""
title: "ao_yield.h"
toc: true
---

```c
#include <ao_task.h>

#ifndef AO_YIELD

#define AO_YIELD

#endif

void    ao_yield();

void    ao_yield_to(ao_task_t * t);

```

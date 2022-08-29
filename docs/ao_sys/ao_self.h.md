---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The ao_sys/ao_self.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys/ao_self.h/ 
subtitle: "ao_sys"
title: "ao_self.h"
toc: true
---

```c
#include <ao_task.h>

#ifndef     AO_SELF

#define     AO_SELF

#endif

ao_task_t * ao_self();

void        ao_stop();

void        ao_suspend();

```

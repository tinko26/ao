---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The ao_sys/ao_task_sched.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys/ao_task_sched.h/ 
subtitle: "ao_sys"
title: "ao_task_sched.h"
toc: true
---

```c
#ifndef AO_TASK_SCHED

#define AO_TASK_SCHED       (2)

#endif

#if     AO_TASK_SCHED ==    (0)

#include <ao_task_sched_0.h>

#elif   AO_TASK_SCHED ==    (1)

#include <ao_task_sched_1.h>

#elif   AO_TASK_SCHED ==    (2)

#include <ao_task_sched_2.h>

#endif

```

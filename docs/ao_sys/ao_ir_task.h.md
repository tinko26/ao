---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The ao_sys/ao_ir_task.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys/ao_ir_task.h/ 
subtitle: "ao_sys"
title: "ao_ir_task.h"
toc: true
---

```c
#include <ao_core.h>
#include <stdbool.h>

void    ao_task_switch();

void    ao_task_switch_disable(     ao_core_t c);

void    ao_task_switch_enable(      ao_core_t c);

bool    ao_task_switch_is_pending(  ao_core_t c);

void    ao_task_switch_reply(       ao_core_t c);

void    ao_task_switch_request(     ao_core_t c);

```

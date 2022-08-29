---
author: "Stefan Wagner"
breadcrumbs: 2
date: 2022-08-29
description: "The ao_sys_xc32_pic32mx/ao_task_stack.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys_xc32_pic32mx/ao_task_stack.h/ 
subtitle: "<code>ao_sys_xc32_pic32mx</code>"
title: "<code>ao_task_stack.h</code>"
toc: true
---

```c
typedef struct  ao_task_t           ao_task_t;

#ifndef AO_TASK_STACK_CHECK

#define AO_TASK_STACK_CHECK         (false)

#endif

#ifndef AO_TASK_STACK_THRESHOLD

#define AO_TASK_STACK_THRESHOLD     (70)

#endif

void    ao_task_stack_null(         ao_task_t const * t);

void    ao_task_stack_overflow(     ao_task_t const * t);

void    ao_task_stack_threshold(    ao_task_t const * t, size_t quota);

void    ao_task_stack_underflow(    ao_task_t const * t);

```

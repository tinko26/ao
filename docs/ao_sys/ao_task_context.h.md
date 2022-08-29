---
author: "Stefan Wagner"
breadcrumbs: 2
date: 2022-08-29
description: "The ao_sys/ao_task_context.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys/ao_task_context.h/ 
subtitle: "<code>ao_sys</code>"
title: "<code>ao_task_context.h</code>"
toc: true
---

```c
typedef struct  ao_task_t           ao_task_t;

typedef struct  ao_task_context_t   ao_task_context_t;

#ifndef AO_TASK_CONTEXT

#define AO_TASK_CONTEXT

struct  ao_task_context_t           { };

#endif

void    ao_task_start_context(      ao_task_t * t);

void    ao_task_stop_context(       ao_task_t * t);

```

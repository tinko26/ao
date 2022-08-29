---
author: "Stefan Wagner"
breadcrumbs: 2
date: 2022-08-29
description: "The ao_sys/ao_task_stack_0.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys/ao_task_stack_0.h/ 
subtitle: "<code>ao_sys</code>"
title: "<code>ao_task_stack_0.h</code>"
toc: true
---

typedef struct  ao_task_t                   ao_task_t;

typedef struct  ao_task_stack_t             ao_task_stack_t;

#ifndef AO_TASK_STACK_0

#define AO_TASK_STACK_0

#endif

#ifndef AO_TASK_STACK_T

#define AO_TASK_STACK_T

struct  ao_task_stack_t                     { };

#endif

void *  ao_task_get_stack_beginning(        ao_task_t const * t);

void *  ao_task_get_stack_beginning_locked( ao_task_t const * t);

size_t  ao_task_get_stack_size(             ao_task_t const * t);

size_t  ao_task_get_stack_size_locked(      ao_task_t const * t);


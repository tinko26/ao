---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The ao_sys/ao_task_stack_1.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys/ao_task_stack_1.h/ 
subtitle: "ao_sys"
title: "ao_task_stack_1.h"
toc: true
---

```c
#include <stdbool.h>
#include <stddef.h>

typedef struct  ao_task_t                           ao_task_t;

typedef struct  ao_task_stack_t                     ao_task_stack_t;

#ifndef AO_TASK_STACK_1

#define AO_TASK_STACK_1

#endif

#ifndef AO_TASK_STACK_HIGH_WATER_MARK

#define AO_TASK_STACK_HIGH_WATER_MARK               (false)

#endif

#ifndef AO_TASK_STACK_T

#define AO_TASK_STACK_T

struct  ao_task_stack_t
{
        void *                                      beginning;

        size_t                                      size;

#if     AO_TASK_STACK_HIGH_WATER_MARK

        size_t                                      high_water_mark;

#endif

};

#endif

void *  ao_task_get_stack_beginning(                ao_task_t const * t);

void *  ao_task_get_stack_beginning_locked(         ao_task_t const * t);

size_t  ao_task_get_stack_high_water_mark(          ao_task_t const * t);

size_t  ao_task_get_stack_high_water_mark_locked(   ao_task_t const * t);

size_t  ao_task_get_stack_size(                     ao_task_t const * t);

size_t  ao_task_get_stack_size_locked(              ao_task_t const * t);

void    ao_task_set_stack(                          ao_task_t       * t, void * beginning, size_t size);

void    ao_task_stack_high_water_mark(              ao_task_t       * t);

```

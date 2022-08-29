---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The ao/ao_buffer4obj.h module of the ao real-time operating system."
draft: true
permalink: /ao/ao_buffer4obj.h/ 
subtitle: "ao"
title: "ao_buffer4obj.h"
toc: true
---

```c
#include <stdbool.h>
#include <stddef.h>

typedef struct  ao_buffer4obj_t                 ao_buffer4obj_t;

#ifndef AO_BUFFER4OBJ_COUNT_MAX

#define AO_BUFFER4OBJ_COUNT_MAX                 (false)

#endif

#ifndef AO_BUFFER4OBJ

#define AO_BUFFER4OBJ

struct  ao_buffer4obj_t
{
        size_t                                  capacity;

        size_t                                  count;

#if     AO_BUFFER4OBJ_COUNT_MAX

        size_t                                  count_max;

#endif

        size_t                                  front;

        size_t                                  size;

        void *                                  store;
};

#endif

#ifndef ao_buffer4obj_is_empty

#define ao_buffer4obj_is_empty(x)               ((x)->count == 0 ? true : false)

#endif

#ifndef ao_buffer4obj_is_full

#define ao_buffer4obj_is_full(x)                ((x)->count == (x)->capacity ? true : false)

#endif

bool    ao_buffer4obj_peek_back(                ao_buffer4obj_t const * x, void * p);

bool    ao_buffer4obj_peek_front(               ao_buffer4obj_t const * x, void * p);

size_t  ao_buffer4obj_peek_range_back(          ao_buffer4obj_t const * x, void * p, size_t n_min, size_t n_max);

size_t  ao_buffer4obj_peek_range_front(         ao_buffer4obj_t const * x, void * p, size_t n_min, size_t n_max);

bool    ao_buffer4obj_pop_back(                 ao_buffer4obj_t * x, void * p);

bool    ao_buffer4obj_pop_front(                ao_buffer4obj_t * x, void * p);

size_t  ao_buffer4obj_pop_range_back(           ao_buffer4obj_t * x, void * p, size_t n_min, size_t n_max);

size_t  ao_buffer4obj_pop_range_front(          ao_buffer4obj_t * x, void * p, size_t n_min, size_t n_max);

bool    ao_buffer4obj_push_back(                ao_buffer4obj_t * x, void const * p);

bool    ao_buffer4obj_push_back_override(       ao_buffer4obj_t * x, void const * p);

bool    ao_buffer4obj_push_front(               ao_buffer4obj_t * x, void const * p);

bool    ao_buffer4obj_push_front_override(      ao_buffer4obj_t * x, void const * p);

size_t  ao_buffer4obj_push_range_back(          ao_buffer4obj_t * x, void const * p, size_t n_min, size_t n_max);

size_t  ao_buffer4obj_push_range_back_override( ao_buffer4obj_t * x, void const * p, size_t n_min, size_t n_max);

size_t  ao_buffer4obj_push_range_front(         ao_buffer4obj_t * x, void const * p, size_t n_min, size_t n_max);

size_t  ao_buffer4obj_push_range_front_override(ao_buffer4obj_t * x, void const * p, size_t n_min, size_t n_max);

```

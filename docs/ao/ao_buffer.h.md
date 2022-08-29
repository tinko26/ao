---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The ao/ao_buffer.h module of the ao real-time operating system."
draft: true
permalink: /ao/ao_buffer.h/ 
subtitle: ""
title: "ao_buffer.h"
toc: true
---

```c
#include <stdbool.h>
#include <stddef.h>

typedef struct  ao_buffer_t                 ao_buffer_t;

#ifndef AO_BUFFER_COUNT_MAX

#define AO_BUFFER_COUNT_MAX                 (false)

#endif

#ifndef AO_BUFFER

#define AO_BUFFER

struct  ao_buffer_t
{
        size_t                              capacity;

        size_t                              count;

#if     AO_BUFFER_COUNT_MAX

        size_t                              count_max;

#endif

        size_t                              front;

        void *                              store;
};

#endif

#ifndef ao_buffer_is_empty

#define ao_buffer_is_empty(x)               ((x)->count == 0 ? true : false)

#endif

#ifndef ao_buffer_is_full

#define ao_buffer_is_full(x)                ((x)->count == (x)->capacity ? true : false)

#endif

bool    ao_buffer_peek_back(                ao_buffer_t const * x, void * p);

bool    ao_buffer_peek_front(               ao_buffer_t const * x, void * p);

size_t  ao_buffer_peek_range_back(          ao_buffer_t const * x, void * p, size_t n_min, size_t n_max);

size_t  ao_buffer_peek_range_front(         ao_buffer_t const * x, void * p, size_t n_min, size_t n_max);

bool    ao_buffer_pop_back(                 ao_buffer_t * x, void * p);

bool    ao_buffer_pop_front(                ao_buffer_t * x, void * p);

size_t  ao_buffer_pop_range_back(           ao_buffer_t * x, void * p, size_t n_min, size_t n_max);

size_t  ao_buffer_pop_range_front(          ao_buffer_t * x, void * p, size_t n_min, size_t n_max);

bool    ao_buffer_push_back(                ao_buffer_t * x, void const * p);

bool    ao_buffer_push_back_override(       ao_buffer_t * x, void const * p);

bool    ao_buffer_push_front(               ao_buffer_t * x, void const * p);

bool    ao_buffer_push_front_override(      ao_buffer_t * x, void const * p);

size_t  ao_buffer_push_range_back(          ao_buffer_t * x, void const * p, size_t n_min, size_t n_max);

size_t  ao_buffer_push_range_back_override( ao_buffer_t * x, void const * p, size_t n_min, size_t n_max);

size_t  ao_buffer_push_range_front(         ao_buffer_t * x, void const * p, size_t n_min, size_t n_max);

size_t  ao_buffer_push_range_front_override(ao_buffer_t * x, void const * p, size_t n_min, size_t n_max);

```

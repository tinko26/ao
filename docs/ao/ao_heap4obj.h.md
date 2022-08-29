---
author: "Stefan Wagner"
breadcrumbs: 2
date: 2022-08-29
description: "The ao/ao_heap4obj.h module of the ao real-time operating system."
draft: true
permalink: /ao/ao_heap4obj.h/ 
subtitle: "<code>ao</code>"
title: "<code>ao_heap4obj.h</code>"
toc: true
---

```c
typedef struct  ao_heap4obj_t       ao_heap4obj_t;

typedef bool (*                     ao_heap4obj_less_t)
(
        void *                      p1,

        void *                      p2,

        void *                      parameter
);

#ifndef AO_HEAP4OBJ_COUNT_MAX

#define AO_HEAP4OBJ_COUNT_MAX       (false)

#endif

#ifndef AO_HEAP4OBJ

#define AO_HEAP4OBJ

struct  ao_heap4obj_t
{
        size_t                      capacity;

        size_t                      count;

#if     AO_HEAP4OBJ_COUNT_MAX

        size_t                      count_max;

#endif

        size_t *                    heap1;

        size_t *                    heap2;

        ao_heap4obj_less_t          less;

        void *                      less_parameter;

        size_t                      size;

        void *                      store;
};

#endif

#ifndef ao_heap4obj_is_empty

#define ao_heap4obj_is_empty(x)     ((x)->count == 0 ? true : false)

#endif

#ifndef ao_heap4obj_is_full

#define ao_heap4obj_is_full(x)      ((x)->count == (x)->capacity ? true : false)

#endif

void    ao_heap4obj_assert(         ao_heap4obj_t * x);

bool    ao_heap4obj_insert(         ao_heap4obj_t * x, void const * p);

bool    ao_heap4obj_peek(           ao_heap4obj_t const * x, void * p);

bool    ao_heap4obj_pop(            ao_heap4obj_t * x, void * p);

```

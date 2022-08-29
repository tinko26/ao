---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The /src/ao/ao_heap4ptr.h file of the ao real-time operating system."
draft: true
permalink: /src/ao/ao_heap4ptr.h/ 
subtitle: ""
title: "ao_heap4ptr.h"
toc: true
---

# Overview

...

# Includes

```c
#include <stdbool.h>
#include <stddef.h>

typedef struct  ao_heap4ptr_t       ao_heap4ptr_t;

typedef bool (*                     ao_heap4ptr_less_t)
(
        void *                      p1,

        void *                      p2,

        void *                      parameter
);

#ifndef AO_HEAP4PTR_COUNT_MAX

#define AO_HEAP4PTR_COUNT_MAX       (false)

#endif

#ifndef AO_HEAP4PTR

#define AO_HEAP4PTR

struct  ao_heap4ptr_t
{
        size_t                      capacity;

        size_t                      count;

#if     AO_HEAP4PTR_COUNT_MAX

        size_t                      count_max;

#endif

        size_t *                    heap1;

        size_t *                    heap2;

        ao_heap4ptr_less_t          less;

        void *                      less_parameter;

        void **                     store;
};

#endif

#ifndef ao_heap4ptr_is_empty

#define ao_heap4ptr_is_empty(x)     ((x)->count == 0 ? true : false)

#endif

#ifndef ao_heap4ptr_is_full

#define ao_heap4ptr_is_full(x)      ((x)->count == (x)->capacity ? true : false)

#endif

void    ao_heap4ptr_assert(         ao_heap4ptr_t * x);

bool    ao_heap4ptr_insert(         ao_heap4ptr_t * x, void * p);

bool    ao_heap4ptr_peek(           ao_heap4ptr_t const * x, void ** p);

bool    ao_heap4ptr_pop(            ao_heap4ptr_t * x, void ** p);

```

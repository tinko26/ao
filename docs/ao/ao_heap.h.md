---
author: "Stefan Wagner"
breadcrumbs: 2
date: 2022-08-29
description: "The ao/ao_heap.h module of the ao real-time operating system."
draft: true
permalink: /ao/ao_heap.h/ 
subtitle: "<code>ao</code>"
title: "<code>ao_heap.h</code>"
toc: true
---

```c
typedef struct  ao_heap_t       ao_heap_t;

typedef struct  ao_heap_node_t  ao_heap_node_t;

typedef bool (*                 ao_heap_less_t)
(
        ao_heap_node_t *        n1,

        ao_heap_node_t *        n2,

        void *                  parameter
);

#ifndef AO_HEAP_COUNT_MAX

#define AO_HEAP_COUNT_MAX       (false)

#endif

#ifndef AO_HEAP

#define AO_HEAP

struct  ao_heap_t
{
        ao_uint_t               count;

#if AO_HEAP_COUNT_MAX

        ao_uint_t               count_max;

#endif

        ao_heap_less_t          less;

        void *                  less_parameter;

        ao_heap_node_t *        root;
};

#endif

#ifndef AO_HEAP_NODE

#define AO_HEAP_NODE

struct  ao_heap_node_t
{
        ao_heap_node_t *        left;

        ao_heap_node_t *        parent;

        ao_heap_node_t *        right;
};

#endif

#ifndef ao_heap_is_empty

#define ao_heap_is_empty(x)     ((x)->root == NULL ? true : false)

#endif

#ifndef ao_heap_peek

#define ao_heap_peek(x)         ((x)->root)

#endif

void    ao_heap_assert(         ao_heap_t * x);

void    ao_heap_insert(         ao_heap_t * x, ao_heap_node_t * n);

ao_heap_node_t *

        ao_heap_pop(            ao_heap_t * x);

void    ao_heap_remove(         ao_heap_t * x, ao_heap_node_t * n);

```

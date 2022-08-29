---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The ao/ao_slist.h module of the ao real-time operating system."
draft: true
permalink: /ao/ao_slist.h/ 
subtitle: ""
title: "ao_slist.h"
toc: true
---

```c
#include <stdbool.h>
#include <stddef.h>

typedef struct  ao_slist_t      ao_slist_t;

typedef struct  ao_slist_node_t ao_slist_node_t;

typedef bool (*                 ao_slist_less_t)
(
        ao_slist_node_t *       n1,

        ao_slist_node_t *       n2,

        void *                  parameter
);

#ifndef AO_SLIST

#define AO_SLIST

struct  ao_slist_t
{
        ao_slist_node_t *       back;

        ao_slist_node_t *       front;

        ao_slist_less_t         less;

        void *                  less_parameter;
};

#endif

#ifndef AO_SLIST_NODE

#define AO_SLIST_NODE

struct  ao_slist_node_t
{
        ao_slist_node_t *       next;

        ao_slist_node_t *       prev;
};

#endif

#ifndef ao_slist_is_empty

#define ao_slist_is_empty(x)    ((x)->front == NULL ? true : false)

#endif

void    ao_slist_assert(        ao_slist_t * x);

void    ao_slist_insert(        ao_slist_t * x, ao_slist_node_t * n);

ao_slist_node_t *

        ao_slist_pop_back(      ao_slist_t * x);

ao_slist_node_t *

        ao_slist_pop_front(     ao_slist_t * x);

void    ao_slist_remove(        ao_slist_t * x, ao_slist_node_t * n);

void    ao_slist_remove_all(    ao_slist_t * x);

void    ao_slist_remove_back(   ao_slist_t * x);

void    ao_slist_remove_front(  ao_slist_t * x);

void    ao_slist_update(        ao_slist_t * x, ao_slist_node_t * n);

```

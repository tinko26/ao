---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The ao/ao_list.h module of the ao real-time operating system."
draft: true
permalink: /ao/ao_list.h/ 
subtitle: ""
title: "ao_list.h"
toc: true
---

# Overview

...

# Includes

```c
#include <stdbool.h>
#include <stddef.h>

typedef struct  ao_list_t       ao_list_t;

typedef struct  ao_list_node_t  ao_list_node_t;

#ifndef AO_LIST

#define AO_LIST

struct  ao_list_t
{
        ao_list_node_t *        back;

        ao_list_node_t *        front;
};

#endif

#ifndef AO_LIST_NODE

#define AO_LIST_NODE

struct  ao_list_node_t
{
        ao_list_node_t *        next;

        ao_list_node_t *        prev;
};

#endif

#ifndef ao_list_is_empty

#define ao_list_is_empty(x)     ((x)->front == NULL ? true : false)

#endif

void    ao_list_insert_after(   ao_list_t * x, ao_list_node_t * n1, ao_list_node_t * n2);

void    ao_list_insert_before(  ao_list_t * x, ao_list_node_t * n1, ao_list_node_t * n2);

ao_list_node_t *

        ao_list_pop_back(       ao_list_t * x);

ao_list_node_t *

        ao_list_pop_front(      ao_list_t * x);

void    ao_list_push_back(      ao_list_t * x, ao_list_node_t * n);

void    ao_list_push_front(     ao_list_t * x, ao_list_node_t * n);

void    ao_list_remove(         ao_list_t * x, ao_list_node_t * n);

void    ao_list_remove_all(     ao_list_t * x);

void    ao_list_remove_back(    ao_list_t * x);

void    ao_list_remove_front(   ao_list_t * x);

void    ao_list_reverse(        ao_list_t * x);

```

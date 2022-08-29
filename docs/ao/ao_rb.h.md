---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The ao/ao_rb.h module of the ao real-time operating system."
draft: true
permalink: /ao/ao_rb.h/ 
subtitle: ""
title: "ao_rb.h"
toc: true
---

```c
#include <stdbool.h>
#include <stddef.h>

typedef struct  ao_rb_t         ao_rb_t;

typedef struct  ao_rb_node_t    ao_rb_node_t;

typedef bool (*                 ao_rb_less_t)
(
        ao_rb_node_t *          n1,

        ao_rb_node_t *          n2,

        void *                  parameter
);

#ifndef AO_RB

#define AO_RB

struct  ao_rb_t
{
        ao_rb_less_t            less;

        void *                  less_parameter;

        ao_rb_node_t *          root;
};

#endif

#ifndef AO_RB_NODE

#define AO_RB_NODE

struct  ao_rb_node_t
{
        bool                    black;

        ao_rb_node_t *          left;

        ao_rb_node_t *          parent;

        ao_rb_node_t *          right;
};

#endif

#ifndef ao_rb_is_empty

#define ao_rb_is_empty(x)       ((x)->root == NULL ? true : false)

#endif

void    ao_rb_assert(           ao_rb_t * x);

void    ao_rb_insert(           ao_rb_t * x, ao_rb_node_t * n);

ao_rb_node_t *

        ao_rb_max(              ao_rb_t * x);

ao_rb_node_t *

        ao_rb_min(              ao_rb_t * x);

void    ao_rb_remove(           ao_rb_t * x, ao_rb_node_t * n);

```

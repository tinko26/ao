---
author: "Stefan Wagner"
date: 2022-08-29
description: "The ao/ao_avl.h module of the ao real-time operating system."
draft: true
permalink: /ao/ao_avl.h/ 
subtitle: "<code>ao</code>"
title: "<code>ao_avl.h</code>"
toc: true
---

typedef struct  ao_avl_t        ao_avl_t;

typedef struct  ao_avl_node_t   ao_avl_node_t;

typedef bool (*                 ao_avl_less_t)
(
        ao_avl_node_t *         n1,

        ao_avl_node_t *         n2,

        void *                  parameter
);

#ifndef AO_AVL

#define AO_AVL

struct  ao_avl_t
{
        ao_avl_less_t           less;

        void *                  less_parameter;

        ao_avl_node_t *         root;
};

#endif

#ifndef AO_AVL_NODE

#define AO_AVL_NODE

struct  ao_avl_node_t
{
        ao_int_t                height;

        ao_avl_node_t *         left;

        ao_avl_node_t *         parent;

        ao_avl_node_t *         right;
};

#endif

#ifndef ao_avl_is_empty

#define ao_avl_is_empty(x)      ((x)->root == NULL ? true : false)

#endif

void    ao_avl_assert(          ao_avl_t * x);

void    ao_avl_insert(          ao_avl_t * x, ao_avl_node_t * n);

ao_avl_node_t *

        ao_avl_max(             ao_avl_t * x);

ao_avl_node_t *

        ao_avl_min(             ao_avl_t * x);

void    ao_avl_remove(          ao_avl_t * x, ao_avl_node_t * n);


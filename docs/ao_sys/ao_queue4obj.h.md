---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The ao_sys/ao_queue4obj.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys/ao_queue4obj.h/ 
subtitle: ""
title: "ao_queue4obj.h"
toc: true
---

# Overview

...

# Includes

```c
#include <ao_async.h>
#include <ao_heap4obj.h>
#include <ao_list.h>
#include <ao_time.h>
#include <stdbool.h>

typedef struct  ao_queue4obj_t      ao_queue4obj_t;

typedef struct  ao_qinsert_obj_t    ao_qinsert_obj_t;

typedef struct  ao_qpop_obj_t       ao_qpop_obj_t;

#ifndef AO_QUEUE4OBJ

#define AO_QUEUE4OBJ

struct  ao_queue4obj_t
{
        ao_heap4obj_t               heap;

        ao_list_t                   insert;

        ao_list_t                   pop;
};

#endif

#ifndef AO_QINSERT_OBJ

#define AO_QINSERT_OBJ

struct  ao_qinsert_obj_t
{
        ao_async_t                  async;

        ao_list_node_t              node;

        void *                      ptr;

        ao_queue4obj_t *            queue;

        bool            volatile    result;
};

#endif

#ifndef AO_QPOP_OBJ

#define AO_QPOP_OBJ

struct  ao_qpop_obj_t
{
        ao_async_t                  async;

        ao_list_node_t              node;

        void *                      ptr;

        ao_queue4obj_t *            queue;

        bool            volatile    result;
};

#endif

void    ao_qinsert_obj(             ao_qinsert_obj_t * x, ao_time_t timeout);

void    ao_qinsert_obj_from(        ao_qinsert_obj_t * x, ao_time_t timeout, ao_time_t beginning);

void    ao_qinsert_obj_forever(     ao_qinsert_obj_t * x);

void    ao_qinsert_obj_try(         ao_qinsert_obj_t * x);

void    ao_qinsert_obj_begin(       ao_qinsert_obj_t * x);

void    ao_qinsert_obj_end(         ao_qinsert_obj_t * x);

void    ao_qpop_obj(                ao_qpop_obj_t * x, ao_time_t timeout);

void    ao_qpop_obj_from(           ao_qpop_obj_t * x, ao_time_t timeout, ao_time_t beginning);

void    ao_qpop_obj_forever(        ao_qpop_obj_t * x);

void    ao_qpop_obj_try(            ao_qpop_obj_t * x);

void    ao_qpop_obj_begin(          ao_qpop_obj_t * x);

void    ao_qpop_obj_end(            ao_qpop_obj_t * x);

```

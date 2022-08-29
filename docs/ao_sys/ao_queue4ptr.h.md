---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The ao_sys/ao_queue4ptr.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys/ao_queue4ptr.h/ 
subtitle: ""
title: "ao_queue4ptr.h"
toc: true
---

# Overview

...

# Includes

```c
#include <ao_async.h>
#include <ao_heap4ptr.h>
#include <ao_list.h>
#include <ao_time.h>
#include <stdbool.h>

typedef struct  ao_queue4ptr_t      ao_queue4ptr_t;

typedef struct  ao_qinsert_ptr_t    ao_qinsert_ptr_t;

typedef struct  ao_qpop_ptr_t       ao_qpop_ptr_t;

#ifndef AO_QUEUE4PTR

#define AO_QUEUE4PTR

struct  ao_queue4ptr_t
{
        ao_heap4ptr_t               heap;

        ao_list_t                   insert;

        ao_list_t                   pop;
};

#endif

#ifndef AO_QINSERT_PTR

#define AO_QINSERT_PTR

struct  ao_qinsert_ptr_t
{
        ao_async_t                  async;

        ao_list_node_t              node;

        void *                      ptr;

        ao_queue4ptr_t *            queue;

        bool            volatile    result;
};

#endif

#ifndef AO_QPOP_PTR

#define AO_QPOP_PTR

struct  ao_qpop_ptr_t
{
        ao_async_t                  async;

        ao_list_node_t              node;

        void *          volatile    ptr;

        ao_queue4ptr_t *            queue;

        bool            volatile    result;
};

#endif

void    ao_qinsert_acq(             ao_qinsert_ptr_t * x, ao_time_t timeout);

void    ao_qinsert_acq_from(        ao_qinsert_ptr_t * x, ao_time_t timeout, ao_time_t beginning);

void    ao_qinsert_acq_forever(     ao_qinsert_ptr_t * x);

void    ao_qinsert_acq_try(         ao_qinsert_ptr_t * x);

void    ao_qinsert_acq_begin(       ao_qinsert_ptr_t * x);

void    ao_qinsert_acq_end(         ao_qinsert_ptr_t * x);

void    ao_qinsert_ptr(             ao_qinsert_ptr_t * x, ao_time_t timeout);

void    ao_qinsert_ptr_from(        ao_qinsert_ptr_t * x, ao_time_t timeout, ao_time_t beginning);

void    ao_qinsert_ptr_forever(     ao_qinsert_ptr_t * x);

void    ao_qinsert_ptr_try(         ao_qinsert_ptr_t * x);

void    ao_qinsert_ptr_begin(       ao_qinsert_ptr_t * x);

void    ao_qinsert_ptr_end(         ao_qinsert_ptr_t * x);

void    ao_qpop_ptr(                ao_qpop_ptr_t * x, ao_time_t timeout);

void    ao_qpop_ptr_from(           ao_qpop_ptr_t * x, ao_time_t timeout, ao_time_t beginning);

void    ao_qpop_ptr_forever(        ao_qpop_ptr_t * x);

void    ao_qpop_ptr_try(            ao_qpop_ptr_t * x);

void    ao_qpop_ptr_begin(          ao_qpop_ptr_t * x);

void    ao_qpop_ptr_end(            ao_qpop_ptr_t * x);

```

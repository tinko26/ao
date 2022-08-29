---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The ao_sys/ao_stream4ptr.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys/ao_stream4ptr.h/ 
subtitle: "ao_sys"
title: "ao_stream4ptr.h"
toc: true
---

```c
#include <ao_async.h>
#include <ao_buffer4ptr.h>
#include <ao_list.h>
#include <ao_time.h>
#include <stdbool.h>

typedef struct  ao_stream4ptr_t ao_stream4ptr_t;

typedef struct  ao_spop_ptr_t   ao_spop_ptr_t;

typedef struct  ao_spush_ptr_t  ao_spush_ptr_t;

#ifndef AO_STREAM4PTR

#define AO_STREAM4PTR

struct  ao_stream4ptr_t
{
        ao_buffer4ptr_t         buffer;

        ao_list_t               pop;

        ao_list_t               push;
};

#endif

#ifndef AO_SPOP_PTR

#define AO_SPOP_PTR

struct  ao_spop_ptr_t
{
        ao_async_t              async;

        ao_list_node_t          node;

        void *      volatile    ptr;

        bool        volatile    result;

        ao_stream4ptr_t *       stream;
};

#endif

#ifndef AO_SPUSH_PTR

#define AO_SPUSH_PTR

struct  ao_spush_ptr_t
{
        ao_async_t              async;

        ao_list_node_t          node;

        void *                  ptr;

        void *      volatile    ptr_override;

        bool        volatile    result;

        bool        volatile    result_override;

        ao_stream4ptr_t *       stream;
};

#endif

void    ao_spop_ptr(            ao_spop_ptr_t * x, ao_time_t timeout);

void    ao_spop_ptr_from(       ao_spop_ptr_t * x, ao_time_t timeout, ao_time_t beginning);

void    ao_spop_ptr_forever(    ao_spop_ptr_t * x);

void    ao_spop_ptr_try(        ao_spop_ptr_t * x);

void    ao_spop_ptr_begin(      ao_spop_ptr_t * x);

void    ao_spop_ptr_end(        ao_spop_ptr_t * x);

void    ao_spush_acq(           ao_spush_ptr_t * x, ao_time_t timeout);

void    ao_spush_acq_from(      ao_spush_ptr_t * x, ao_time_t timeout, ao_time_t beginning);

void    ao_spush_acq_forever(   ao_spush_ptr_t * x);

void    ao_spush_acq_try(       ao_spush_ptr_t * x);

void    ao_spush_acq_begin(     ao_spush_ptr_t * x);

void    ao_spush_acq_end(       ao_spush_ptr_t * x);

void    ao_spush_acq_override(  ao_spush_ptr_t * x);

void    ao_spush_ptr(           ao_spush_ptr_t * x, ao_time_t timeout);

void    ao_spush_ptr_from(      ao_spush_ptr_t * x, ao_time_t timeout, ao_time_t beginning);

void    ao_spush_ptr_forever(   ao_spush_ptr_t * x);

void    ao_spush_ptr_try(       ao_spush_ptr_t * x);

void    ao_spush_ptr_begin(     ao_spush_ptr_t * x);

void    ao_spush_ptr_end(       ao_spush_ptr_t * x);

void    ao_spush_ptr_override(  ao_spush_ptr_t * x);

```

---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The ao_sys/ao_stream4obj.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys/ao_stream4obj.h/ 
subtitle: "ao_sys"
title: "ao_stream4obj.h"
toc: true
---

```c
#include <ao_async.h>
#include <ao_buffer4obj.h>
#include <ao_list.h>
#include <ao_time.h>
#include <stdbool.h>

typedef struct  ao_stream4obj_t ao_stream4obj_t;

typedef struct  ao_spop_obj_t   ao_spop_obj_t;

typedef struct  ao_spush_obj_t  ao_spush_obj_t;

#ifndef AO_STREAM4OBJ

#define AO_STREAM4OBJ

struct  ao_stream4obj_t
{
        ao_buffer4obj_t         buffer;

        ao_list_t               pop;

        ao_list_t               push;
};

#endif

#ifndef AO_SPOP_OBJ

#define AO_SPOP_OBJ

struct  ao_spop_obj_t
{
        ao_async_t              async;

        ao_list_node_t          node;

        void *                  ptr;

        bool        volatile    result;

        ao_stream4obj_t *       stream;
};

#endif

#ifndef AO_SPUSH_OBJ

#define AO_SPUSH_OBJ

struct  ao_spush_obj_t
{
        ao_async_t              async;

        ao_list_node_t          node;

        void *                  ptr;

        void *                  ptr_override;

        bool        volatile    result;

        bool        volatile    result_override;

        ao_stream4obj_t *       stream;
};

#endif

void    ao_spop_obj(            ao_spop_obj_t * x, ao_time_t timeout);

void    ao_spop_obj_from(       ao_spop_obj_t * x, ao_time_t timeout, ao_time_t beginning);

void    ao_spop_obj_forever(    ao_spop_obj_t * x);

void    ao_spop_obj_try(        ao_spop_obj_t * x);

void    ao_spop_obj_begin(      ao_spop_obj_t * x);

void    ao_spop_obj_end(        ao_spop_obj_t * x);

void    ao_spush_obj(           ao_spush_obj_t * x, ao_time_t timeout);

void    ao_spush_obj_from(      ao_spush_obj_t * x, ao_time_t timeout, ao_time_t beginning);

void    ao_spush_obj_forever(   ao_spush_obj_t * x);

void    ao_spush_obj_try(       ao_spush_obj_t * x);

void    ao_spush_obj_begin(     ao_spush_obj_t * x);

void    ao_spush_obj_end(       ao_spush_obj_t * x);

void    ao_spush_obj_override(  ao_spush_obj_t * x);

```

---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The ao_sys/ao_recv_obj.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys/ao_recv_obj.h/ 
subtitle: ""
title: "ao_recv_obj.h"
toc: true
---

# Overview

...

# Includes

```c
#include <ao_async.h>
#include <ao_time.h>
#include <stdbool.h>

typedef struct  ao_recv_obj_t   ao_recv_obj_t;

typedef void (*                 ao_recv_obj_proc_t) (ao_recv_obj_t * x);

#ifndef AO_RECV_OBJ

#define AO_RECV_OBJ

struct  ao_recv_obj_t
{
        ao_async_t              async;

        ao_recv_obj_proc_t      begin;

        ao_recv_obj_proc_t      end;

        void *                  parameter;

        void *                  ptr;

        bool        volatile    result;
};

#endif

void    ao_recv_obj(            ao_recv_obj_t * x, ao_time_t timeout);

void    ao_recv_obj_from(       ao_recv_obj_t * x, ao_time_t timeout, ao_time_t beginning);

void    ao_recv_obj_forever(    ao_recv_obj_t * x);

void    ao_recv_obj_try(        ao_recv_obj_t * x);

void    ao_recv_obj_begin(      ao_recv_obj_t * x);

void    ao_recv_obj_end(        ao_recv_obj_t * x);

```

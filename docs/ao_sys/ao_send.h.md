---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The ao_sys/ao_send.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys/ao_send.h/ 
subtitle: ""
title: "ao_send.h"
toc: true
---

```c
#include <ao_async.h>
#include <ao_func.h>
#include <ao_time.h>
#include <stdbool.h>
#include <stddef.h>

typedef struct  ao_send_t   ao_send_t;

typedef void (*             ao_send_proc_t) (ao_send_t * x);

#ifndef AO_SEND

#define AO_SEND

struct  ao_send_t
{
        ao_async_t          async;

        ao_send_proc_t      begin;

        size_t  volatile    count;

        size_t              count_max;

        size_t              count_min;

        ao_send_proc_t      end;

        void *              parameter;

        void *              ptr;

        bool    volatile    result;
};

#endif

void    ao_send(            ao_send_t * x, ao_time_t timeout);

void    ao_send_from(       ao_send_t * x, ao_time_t timeout, ao_time_t beginning);

void    ao_send_forever(    ao_send_t * x);

void    ao_send_try(        ao_send_t * x);

void    ao_send_begin(      ao_send_t * x);

void    ao_send_end(        ao_send_t * x);

```

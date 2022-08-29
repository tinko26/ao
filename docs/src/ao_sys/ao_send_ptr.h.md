---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The /src/ao_sys/ao_send_ptr.h file of the ao real-time operating system."
draft: true
permalink: /src/ao_sys/ao_send_ptr.h/ 
subtitle: ""
title: "ao_send_ptr.h"
toc: true
---

# Overview

...

# Includes

```c
#include <ao_async.h>
#include <ao_time.h>
#include <stdbool.h>

typedef struct  ao_send_ptr_t   ao_send_ptr_t;

typedef void (*                 ao_send_ptr_proc_t) (ao_send_ptr_t * x);

#ifndef AO_SEND_PTR

#define AO_SEND_PTR

struct  ao_send_ptr_t
{
        ao_async_t              async;

        ao_send_ptr_proc_t      begin;

        ao_send_ptr_proc_t      end;

        void *                  parameter;

        void *                  ptr;

        bool        volatile    result;
};

#endif

void    ao_send_ptr(            ao_send_ptr_t * x, ao_time_t timeout);

void    ao_send_ptr_from(       ao_send_ptr_t * x, ao_time_t timeout, ao_time_t beginning);

void    ao_send_ptr_forever(    ao_send_ptr_t * x);

void    ao_send_ptr_try(        ao_send_ptr_t * x);

void    ao_send_ptr_begin(      ao_send_ptr_t * x);

void    ao_send_ptr_end(        ao_send_ptr_t * x);

```

---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The ao_sys/ao_async.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys/ao_async.h/ 
subtitle: "ao_sys"
title: "ao_async.h"
toc: true
---

```c
#include <ao_func.h>
#include <stdbool.h>
#include <stddef.h>

typedef struct  ao_async_t      ao_async_t;

typedef struct  ao_async_all_t  ao_async_all_t;

typedef struct  ao_async_any_t  ao_async_any_t;

#ifndef AO_ASYNC

#define AO_ASYNC

struct  ao_async_t
{
        ao_proc_t               callback;

        void *                  callback_parameter;

        bool        volatile    checked;
};

#endif

#ifndef AO_ASYNC_ALL

#define AO_ASYNC_ALL

struct  ao_async_all_t
{
        ao_async_t              async;

        size_t                  count;

        size_t      volatile    count_checked;

        bool        volatile    result;

        ao_async_t **           store;
};

#endif

#ifndef AO_ASYNC_ANY

#define AO_ASYNC_ANY

struct  ao_async_any_t
{
        ao_async_t              async;

        size_t                  count;

        bool        volatile    result;

        ao_async_t **           store;
};

#endif

void    ao_async_all_begin(     ao_async_all_t * x);

void    ao_async_all_end(       ao_async_all_t * x);

void    ao_async_all_try(       ao_async_all_t * x);

void    ao_async_any_begin(     ao_async_any_t * x);

void    ao_async_any_end(       ao_async_any_t * x);

void    ao_async_any_try(       ao_async_any_t * x);

```

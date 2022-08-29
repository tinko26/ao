---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The ao_sys/ao_cond.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys/ao_cond.h/ 
subtitle: ""
title: "ao_cond.h"
toc: true
---

```c
#include <ao_async.h>
#include <ao_list.h>
#include <ao_time.h>
#include <stdbool.h>

typedef struct  ao_cond_t       ao_cond_t;

typedef struct  ao_cond_wait_t  ao_cond_wait_t;

#ifndef AO_COND

#define AO_COND

struct  ao_cond_t
{
        ao_list_t               list;

        bool                    state;
};

#endif

#ifndef AO_COND_WAIT

#define AO_COND_WAIT

struct  ao_cond_wait_t
{
        ao_async_t              async;

        ao_cond_t *             cond;

        ao_list_node_t          node;

        bool        volatile    result;
};

#endif

void    ao_cond_clear(          ao_cond_t * x);

void    ao_cond_set(            ao_cond_t * x);

bool    ao_cond_wait(           ao_cond_t * x, ao_time_t timeout);

bool    ao_cond_wait_from(      ao_cond_t * x, ao_time_t timeout, ao_time_t beginning);

bool    ao_cond_wait_forever(   ao_cond_t * x);

bool    ao_cond_wait_try(       ao_cond_t * x);

void    ao_cond_wait_begin(     ao_cond_wait_t * x);

void    ao_cond_wait_end(       ao_cond_wait_t * x);

```

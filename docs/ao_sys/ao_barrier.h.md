---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The ao_sys/ao_barrier.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys/ao_barrier.h/ 
subtitle: ""
title: "ao_barrier.h"
toc: true
---

# Overview

...

# Includes

```c
#include <ao_async.h>
#include <ao_list.h>
#include <ao_time.h>
#include <ao_uint.h>
#include <stdbool.h>

typedef struct  ao_barrier_t        ao_barrier_t;

typedef struct  ao_barrier_wait_t   ao_barrier_wait_t;

#ifndef AO_BARRIER

#define AO_BARRIER

struct  ao_barrier_t
{
        ao_uint_t                   count;

        ao_uint_t                   count_threshold;

        ao_list_t                   list;
};

#endif

#ifndef AO_BARRIER_WAIT

#define AO_BARRIER_WAIT

struct  ao_barrier_wait_t
{
        ao_async_t                  async;

        ao_barrier_t *              barrier;

        ao_list_node_t              node;

        bool            volatile    result;
};

#endif

bool    ao_barrier_wait(            ao_barrier_t * x, ao_time_t timeout);

bool    ao_barrier_wait_from(       ao_barrier_t * x, ao_time_t timeout, ao_time_t beginning);

bool    ao_barrier_wait_forever(    ao_barrier_t * x);

bool    ao_barrier_wait_try(        ao_barrier_t * x);

void    ao_barrier_wait_begin(      ao_barrier_wait_t * x);

void    ao_barrier_wait_end(        ao_barrier_wait_t * x);

```

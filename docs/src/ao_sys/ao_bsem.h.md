---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The /src/ao_sys/ao_bsem.h file of the ao real-time operating system."
draft: true
permalink: /src/ao_sys/ao_bsem.h/ 
subtitle: ""
title: "ao_bsem.h"
toc: true
---

# Overview

...

# Includes

```c
#include <ao_async.h>
#include <ao_list.h>
#include <ao_time.h>
#include <stdbool.h>

typedef struct  ao_bsem_t       ao_bsem_t;

typedef struct  ao_bsem_take_t  ao_bsem_take_t;

#ifndef AO_BSEM

#define AO_BSEM

struct  ao_bsem_t
{
        ao_list_t               list;

        bool                    taken;
};

#endif

#ifndef AO_BSEM_TAKE

#define AO_BSEM_TAKE

struct  ao_bsem_take_t
{
        ao_async_t              async;

        ao_list_node_t          node;

        bool        volatile    result;

        ao_bsem_t *             sem;
};

#endif

void    ao_bsem_give(           ao_bsem_t * x);

bool    ao_bsem_take(           ao_bsem_t * x, ao_time_t timeout);

bool    ao_bsem_take_from(      ao_bsem_t * x, ao_time_t timeout, ao_time_t beginning);

bool    ao_bsem_take_forever(   ao_bsem_t * x);

bool    ao_bsem_take_try(       ao_bsem_t * x);

void    ao_bsem_take_begin(     ao_bsem_take_t * x);

void    ao_bsem_take_end(       ao_bsem_take_t * x);

```

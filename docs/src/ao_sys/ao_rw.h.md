---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The /src/ao_sys/ao_rw.h file of the ao real-time operating system."
draft: true
permalink: /src/ao_sys/ao_rw.h/ 
subtitle: ""
title: "ao_rw.h"
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

typedef struct  ao_rw_t             ao_rw_t;

typedef struct  ao_rw_lock_t        ao_rw_lock_t;

#ifndef AO_RW

#define AO_RW

struct  ao_rw_t
{
        ao_uint_t                   r_active;

        ao_list_t                   r_waiting;

        bool                        w_active;

        ao_list_t                   w_waiting;
};

#endif

#ifndef AO_RW_LOCK

#define AO_RW_LOCK

struct  ao_rw_lock_t
{
        ao_async_t                  async;

        ao_list_node_t              node;

        bool            volatile    result;

        ao_rw_t *                   rw;
};

#endif

bool    ao_rw_lock_read(            ao_rw_t * x, ao_time_t timeout);

bool    ao_rw_lock_read_forever(    ao_rw_t * x);

bool    ao_rw_lock_read_from(       ao_rw_t * x, ao_time_t timeout, ao_time_t beginning);

bool    ao_rw_lock_read_try(        ao_rw_t * x);

void    ao_rw_lock_read_begin(      ao_rw_lock_t * x);

void    ao_rw_lock_read_end(        ao_rw_lock_t * x);

bool    ao_rw_lock_write(           ao_rw_t * x, ao_time_t timeout);

bool    ao_rw_lock_write_forever(   ao_rw_t * x);

bool    ao_rw_lock_write_from(      ao_rw_t * x, ao_time_t timeout, ao_time_t beginning);

bool    ao_rw_lock_write_try(       ao_rw_t * x);

void    ao_rw_lock_write_begin(     ao_rw_lock_t * x);

void    ao_rw_lock_write_end(       ao_rw_lock_t * x);

void    ao_rw_unlock_read(          ao_rw_t * x);

void    ao_rw_unlock_write(         ao_rw_t * x);

```

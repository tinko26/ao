---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The /src/ao_sys/ao_wr.h file of the ao real-time operating system."
draft: true
permalink: /src/ao_sys/ao_wr.h/ 
subtitle: ""
title: "ao_wr.h"
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

typedef struct  ao_wr_t             ao_wr_t;

typedef struct  ao_wr_lock_t        ao_wr_lock_t;

#ifndef AO_WR

#define AO_WR

struct  ao_wr_t
{
        ao_uint_t                   r_active;

        ao_list_t                   r_waiting;

        bool                        w_active;

        ao_list_t                   w_waiting;
};

#endif

#ifndef AO_WR_LOCK

#define AO_WR_LOCK

struct  ao_wr_lock_t
{
        ao_async_t                  async;

        ao_list_node_t              node;

        bool            volatile    result;

        ao_wr_t *                   wr;
};

#endif

bool    ao_wr_lock_read(            ao_wr_t * x, ao_time_t timeout);

bool    ao_wr_lock_read_forever(    ao_wr_t * x);

bool    ao_wr_lock_read_from(       ao_wr_t * x, ao_time_t timeout, ao_time_t beginning);

bool    ao_wr_lock_read_try(        ao_wr_t * x);

void    ao_wr_lock_read_begin(      ao_wr_lock_t * x);

void    ao_wr_lock_read_end(        ao_wr_lock_t * x);

bool    ao_wr_lock_write(           ao_wr_t * x, ao_time_t timeout);

bool    ao_wr_lock_write_forever(   ao_wr_t * x);

bool    ao_wr_lock_write_from(      ao_wr_t * x, ao_time_t timeout, ao_time_t beginning);

bool    ao_wr_lock_write_try(       ao_wr_t * x);

void    ao_wr_lock_write_begin(     ao_wr_lock_t * x);

void    ao_wr_lock_write_end(       ao_wr_lock_t * x);

void    ao_wr_unlock_read(          ao_wr_t * x);

void    ao_wr_unlock_write(         ao_wr_t * x);

```

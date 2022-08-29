---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The /src/ao_sys/ao_signal.h file of the ao real-time operating system."
draft: true
permalink: /src/ao_sys/ao_signal.h/ 
subtitle: ""
title: "ao_signal.h"
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

typedef struct  ao_signal_t         ao_signal_t;

typedef struct  ao_signal_wait_t    ao_signal_wait_t;

#ifndef AO_SIGNAL

#define AO_SIGNAL

struct  ao_signal_t
{
        ao_list_t                   list;
};

#endif

#ifndef AO_SIGNAL_WAIT

#define AO_SIGNAL_WAIT

struct  ao_signal_wait_t
{
        ao_async_t                  async;

        ao_list_node_t              node;

        bool            volatile    result;

        ao_signal_t *               signal;
};

#endif

void    ao_signal_notify(           ao_signal_t * x);

void    ao_signal_notify_all(       ao_signal_t * x);

bool    ao_signal_wait(             ao_signal_t * x, ao_time_t timeout);

bool    ao_signal_wait_from(        ao_signal_t * x, ao_time_t timeout, ao_time_t beginning);

bool    ao_signal_wait_forever(     ao_signal_t * x);

void    ao_signal_wait_begin(       ao_signal_wait_t * x);

void    ao_signal_wait_end(         ao_signal_wait_t * x);

```

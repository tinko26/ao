---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The ao_sys/ao_rendezvous.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys/ao_rendezvous.h/ 
subtitle: "ao_sys"
title: "ao_rendezvous.h"
toc: true
---

```c
#include <ao_async.h>
#include <ao_time.h>
#include <stdbool.h>

typedef struct  ao_rendezvous_t         ao_rendezvous_t;

typedef struct  ao_rendezvous_wait_t    ao_rendezvous_wait_t;

typedef void (*                         ao_rendezvous_exchange_t)
(
        void *                          ptr_in_other,

        void *                          ptr_out_self,

        void *                          parameter
);

#ifndef AO_RENDEZVOUS

#define AO_RENDEZVOUS

struct  ao_rendezvous_t
{
        ao_rendezvous_wait_t *          wait;
};

#endif

#ifndef AO_RENDEZVOUS_WAIT

#define AO_RENDEZVOUS_WAIT

struct  ao_rendezvous_wait_t
{
        ao_async_t                      async;

        ao_rendezvous_exchange_t        exchange;

        void *                          exchange_parameter;

        void *                          ptr_in;

        void *                          ptr_out;

        ao_rendezvous_t *               rendezvous;

        bool                volatile    result;
};

#endif

void    ao_rendezvous(                  ao_rendezvous_wait_t * x, ao_time_t timeout);

void    ao_rendezvous_from(             ao_rendezvous_wait_t * x, ao_time_t timeout, ao_time_t beginning);

void    ao_rendezvous_forever(          ao_rendezvous_wait_t * x);

void    ao_rendezvous_try(              ao_rendezvous_wait_t * x);

void    ao_rendezvous_begin(            ao_rendezvous_wait_t * x);

void    ao_rendezvous_end(              ao_rendezvous_wait_t * x);

```

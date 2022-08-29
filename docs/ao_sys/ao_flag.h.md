---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The ao_sys/ao_flag.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys/ao_flag.h/ 
subtitle: ""
title: "ao_flag.h"
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

typedef struct  ao_flag_t       ao_flag_t;

typedef struct  ao_flag_wait_t  ao_flag_wait_t;

typedef bool (*                 ao_flag_match_t)
(
        ao_uint_t               mask,

        ao_uint_t               mask_wait,

        void *                  parameter
);

#ifndef AO_FLAG

#define AO_FLAG

struct  ao_flag_t
{
        ao_list_t               list;

        ao_uint_t               mask;
};

#endif

#ifndef AO_FLAG_WAIT

#define AO_FLAG_WAIT

struct  ao_flag_wait_t
{
        ao_async_t              async;

        ao_flag_t *             flag;

        ao_uint_t               mask;

        ao_flag_match_t         match;

        void *                  match_parameter;

        ao_list_node_t          node;

        bool        volatile    result;
};

#endif

void    ao_flag_mask_clear(     ao_flag_t * x, ao_uint_t bits);

void    ao_flag_mask_set(       ao_flag_t * x, ao_uint_t bits);

void    ao_flag_mask_toggle(    ao_flag_t * x, ao_uint_t bits);

bool    ao_flag_wait(           ao_flag_t * x, ao_uint_t mask, ao_flag_match_t match, void * match_parameter, ao_time_t timeout);

bool    ao_flag_wait_from(      ao_flag_t * x, ao_uint_t mask, ao_flag_match_t match, void * match_parameter, ao_time_t timeout, ao_time_t beginning);

bool    ao_flag_wait_forever(   ao_flag_t * x, ao_uint_t mask, ao_flag_match_t match, void * match_parameter);

bool    ao_flag_wait_try(       ao_flag_t * x, ao_uint_t mask, ao_flag_match_t match, void * match_parameter);

void    ao_flag_wait_begin(     ao_flag_wait_t * x);

void    ao_flag_wait_end(       ao_flag_wait_t * x);

```

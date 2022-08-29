---
author: "Stefan Wagner"
date: 2022-08-29
description: "The ao_sys/ao_counter.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys/ao_counter.h/ 
subtitle: "<code>ao_sys</code>"
title: "<code>ao_counter.h</code>"
toc: true
---

typedef struct  ao_counter_t        ao_counter_t;

typedef struct  ao_counter_wait_t   ao_counter_wait_t;

typedef ao_uint_t (*                ao_counter_adjust_t)
(
        ao_uint_t                   value,

        void *                      parameter
);

typedef bool (*                     ao_counter_match_t)
(
        ao_uint_t                   value,

        ao_uint_t                   value_wait,

        void *                      parameter
);

#ifndef AO_COUNTER

#define AO_COUNTER

struct  ao_counter_t
{
        ao_list_t                   list;

        ao_uint_t                   value;
};

#endif

#ifndef AO_COUNTER_WAIT

#define AO_COUNTER_WAIT

struct  ao_counter_wait_t
{
        ao_async_t                  async;

        ao_counter_t *              counter;

        ao_counter_match_t          match;

        void *                      match_parameter;

        ao_list_node_t              node;

        bool            volatile    result;

        ao_uint_t                   value;
};

#endif

void    ao_counter_adjust(          ao_counter_t * x, ao_counter_adjust_t adjust, void * adjust_parameter);

void    ao_counter_add(             ao_counter_t * x, ao_uint_t value);

void    ao_counter_decrement(       ao_counter_t * x);

void    ao_counter_divide(          ao_counter_t * x, ao_uint_t value);

void    ao_counter_increment(       ao_counter_t * x);

void    ao_counter_modulo(          ao_counter_t * x, ao_uint_t value);

void    ao_counter_multiply(        ao_counter_t * x, ao_uint_t value);

void    ao_counter_set(             ao_counter_t * x, ao_uint_t value);

void    ao_counter_subtract(        ao_counter_t * x, ao_uint_t value);

void    ao_counter_subtract_from(   ao_counter_t * x, ao_uint_t value);

bool    ao_counter_wait(            ao_counter_t * x, ao_uint_t value, ao_counter_match_t match, void * match_parameter, ao_time_t timeout);

bool    ao_counter_wait_from(       ao_counter_t * x, ao_uint_t value, ao_counter_match_t match, void * match_parameter, ao_time_t timeout, ao_time_t beginning);

bool    ao_counter_wait_forever(    ao_counter_t * x, ao_uint_t value, ao_counter_match_t match, void * match_parameter);

bool    ao_counter_wait_try(        ao_counter_t * x, ao_uint_t value, ao_counter_match_t match, void * match_parameter);

void    ao_counter_wait_begin(      ao_counter_wait_t * x);

void    ao_counter_wait_end(        ao_counter_wait_t * x);


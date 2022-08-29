---
author: "Stefan Wagner"
date: 2022-08-29
description: "The ao_sys/ao_threshold.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys/ao_threshold.h/ 
subtitle: "<code>ao_sys</code>"
title: "<code>ao_threshold.h</code>"
toc: true
---

typedef struct  ao_threshold_t      ao_threshold_t;

typedef struct  ao_threshold_wait_t ao_threshold_wait_t;

typedef ao_uint_t (*                ao_threshold_adjust_t)
(
        ao_uint_t                   value,

        void *                      parameter
);

typedef bool (*                     ao_threshold_match_t)
(
        ao_uint_t                   value,

        void *                      parameter
);

#ifndef AO_THRESHOLD

#define AO_THRESHOLD

struct  ao_threshold_t
{
        ao_threshold_adjust_t       adjust;

        void *                      adjust_parameter;

        ao_list_t                   list;

        ao_threshold_match_t        match;

        void *                      match_parameter;

        ao_uint_t                   value;
};

#endif

#ifndef AO_THRESHOLD_WAIT

#define AO_THRESHOLD_WAIT

struct  ao_threshold_wait_t
{
        ao_async_t                  async;

        ao_list_node_t              node;

        bool            volatile    result;

        ao_threshold_t *            threshold;

};

#endif

void    ao_threshold_adjust(        ao_threshold_t * x, ao_threshold_adjust_t adjust, void * adjust_parameter);

void    ao_threshold_add(           ao_threshold_t * x, ao_uint_t value);

void    ao_threshold_decrement(     ao_threshold_t * x);

void    ao_threshold_divide(        ao_threshold_t * x, ao_uint_t value);

void    ao_threshold_increment(     ao_threshold_t * x);

void    ao_threshold_modulo(        ao_threshold_t * x, ao_uint_t value);

void    ao_threshold_multiply(      ao_threshold_t * x, ao_uint_t value);

void    ao_threshold_set(           ao_threshold_t * x, ao_uint_t value);

void    ao_threshold_subtract(      ao_threshold_t * x, ao_uint_t value);

void    ao_threshold_subtract_from( ao_threshold_t * x, ao_uint_t value);

bool    ao_threshold_wait(          ao_threshold_t * x, ao_time_t timeout);

bool    ao_threshold_wait_from(     ao_threshold_t * x, ao_time_t timeout, ao_time_t beginning);

bool    ao_threshold_wait_forever(  ao_threshold_t * x);

bool    ao_threshold_wait_try(      ao_threshold_t * x);

void    ao_threshold_wait_begin(    ao_threshold_wait_t * x);

void    ao_threshold_wait_end(      ao_threshold_wait_t * x);


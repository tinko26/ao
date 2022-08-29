---
author: "Stefan Wagner"
date: 2022-08-29
description: "The ao_sys/ao_bsem.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys/ao_bsem.h/ 
subtitle: "<code>ao_sys</code>"
title: "<code>ao_bsem.h</code>"
toc: true
---

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


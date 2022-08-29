---
author: "Stefan Wagner"
breadcrumbs: 2
date: 2022-08-29
description: "The ao_sys/ao_sem.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys/ao_sem.h/ 
subtitle: "<code>ao_sys</code>"
title: "<code>ao_sem.h</code>"
toc: true
---

typedef struct  ao_sem_t        ao_sem_t;

typedef struct  ao_sem_take_t   ao_sem_take_t;

#ifndef AO_SEM

#define AO_SEM

struct  ao_sem_t
{
        ao_uint_t               count;

        ao_list_t               list;
};

#endif

#ifndef AO_SEM_TAKE

#define AO_SEM_TAKE

struct  ao_sem_take_t
{
        ao_async_t              async;

        ao_uint_t               count;

        ao_list_node_t          node;

        bool        volatile    result;

        ao_sem_t *              sem;
};

#endif

void    ao_sem_give(            ao_sem_t * x, ao_uint_t count);

bool    ao_sem_take(            ao_sem_t * x, ao_uint_t count, ao_time_t timeout);

bool    ao_sem_take_from(       ao_sem_t * x, ao_uint_t count, ao_time_t timeout, ao_time_t beginning);

bool    ao_sem_take_forever(    ao_sem_t * x, ao_uint_t count);

bool    ao_sem_take_try(        ao_sem_t * x, ao_uint_t count);

void    ao_sem_take_begin(      ao_sem_take_t * x);

void    ao_sem_take_end(        ao_sem_take_t * x);


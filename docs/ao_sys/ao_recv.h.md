---
author: "Stefan Wagner"
date: 2022-08-29
description: "The ao_sys/ao_recv.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys/ao_recv.h/ 
subtitle: "<code>ao_sys</code>"
title: "<code>ao_recv.h</code>"
toc: true
---

typedef struct  ao_recv_t   ao_recv_t;

typedef void (*             ao_recv_proc_t) (ao_recv_t * x);

#ifndef AO_RECV

#define AO_RECV

struct  ao_recv_t
{
        ao_async_t          async;

        ao_recv_proc_t      begin;

        size_t  volatile    count;

        size_t              count_max;

        size_t              count_min;

        ao_recv_proc_t      end;

        void *              parameter;

        void *              ptr;

        bool    volatile    result;
};

#endif

void    ao_recv(            ao_recv_t * x, ao_time_t timeout);

void    ao_recv_from(       ao_recv_t * x, ao_time_t timeout, ao_time_t beginning);

void    ao_recv_forever(    ao_recv_t * x);

void    ao_recv_try(        ao_recv_t * x);

void    ao_recv_begin(      ao_recv_t * x);

void    ao_recv_end(        ao_recv_t * x);


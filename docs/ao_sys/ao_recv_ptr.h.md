---
author: "Stefan Wagner"
breadcrumbs: 2
date: 2022-08-29
description: "The ao_sys/ao_recv_ptr.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys/ao_recv_ptr.h/ 
subtitle: "<code>ao_sys</code>"
title: "<code>ao_recv_ptr.h</code>"
toc: true
---

typedef struct  ao_recv_ptr_t   ao_recv_ptr_t;

typedef void (*                 ao_recv_ptr_proc_t) (ao_recv_ptr_t * x);

#ifndef AO_RECV_PTR

#define AO_RECV_PTR

struct  ao_recv_ptr_t
{
        ao_async_t              async;

        ao_recv_ptr_proc_t      begin;

        ao_recv_ptr_proc_t      end;

        void *                  parameter;

        void *      volatile    ptr;

        bool        volatile    result;
};

#endif

void    ao_recv_ptr(            ao_recv_ptr_t * x, ao_time_t timeout);

void    ao_recv_ptr_from(       ao_recv_ptr_t * x, ao_time_t timeout, ao_time_t beginning);

void    ao_recv_ptr_forever(    ao_recv_ptr_t * x);

void    ao_recv_ptr_try(        ao_recv_ptr_t * x);

void    ao_recv_ptr_begin(      ao_recv_ptr_t * x);

void    ao_recv_ptr_end(        ao_recv_ptr_t * x);


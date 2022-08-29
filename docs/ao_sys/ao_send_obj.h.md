---
author: "Stefan Wagner"
breadcrumbs: 2
date: 2022-08-29
description: "The ao_sys/ao_send_obj.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys/ao_send_obj.h/ 
subtitle: "<code>ao_sys</code>"
title: "<code>ao_send_obj.h</code>"
toc: true
---

typedef struct  ao_send_obj_t   ao_send_obj_t;

typedef void (*                 ao_send_obj_proc_t) (ao_send_obj_t * x);

#ifndef AO_SEND_OBJ

#define AO_SEND_OBJ

struct  ao_send_obj_t
{
        ao_async_t              async;

        ao_send_obj_proc_t      begin;

        ao_send_obj_proc_t      end;

        void *                  parameter;

        void *                  ptr;

        bool        volatile    result;
};

#endif

void    ao_send_obj(            ao_send_obj_t * x, ao_time_t timeout);

void    ao_send_obj_from(       ao_send_obj_t * x, ao_time_t timeout, ao_time_t beginning);

void    ao_send_obj_forever(    ao_send_obj_t * x);

void    ao_send_obj_try(        ao_send_obj_t * x);

void    ao_send_obj_begin(      ao_send_obj_t * x);

void    ao_send_obj_end(        ao_send_obj_t * x);


---
author: "Stefan Wagner"
breadcrumbs: 2
date: 2022-08-29
description: "The ao_sys/ao_monitor.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys/ao_monitor.h/ 
subtitle: "<code>ao_sys</code>"
title: "<code>ao_monitor.h</code>"
toc: true
---

typedef struct  ao_monitor_t        ao_monitor_t;

typedef struct  ao_monitor_enter_t  ao_monitor_enter_t;

typedef struct  ao_monitor_wait_t   ao_monitor_wait_t;

#ifndef AO_MONITOR

#define AO_MONITOR

struct  ao_monitor_t
{
        ao_list_t                   list;

        ao_mutex_t *                mutex;
};

#endif

#ifndef AO_MONITOR_ENTER

#define AO_MONITOR_ENTER

struct  ao_monitor_enter_t
{
        ao_async_t                  async;

        ao_monitor_t *              monitor;

        ao_mutex_lock_t             mutex_lock;

        bool            volatile    result;
};

#endif

#ifndef AO_MONITOR_WAIT

#define AO_MONITOR_WAIT

struct  ao_monitor_wait_t
{
        ao_async_t                  async;

        ao_monitor_t *              monitor;

        union
        {
            ao_mutex_lock_t         mutex_lock;

            ao_list_node_t          node;
        };

        bool            volatile    result;

        bool            volatile    waiting;
};

#endif

bool    ao_monitor_enter(           ao_monitor_t * x, ao_time_t timeout);

bool    ao_monitor_enter_from(      ao_monitor_t * x, ao_time_t timeout, ao_time_t beginning);

bool    ao_monitor_enter_forever(   ao_monitor_t * x);

bool    ao_monitor_enter_try(       ao_monitor_t * x);

void    ao_monitor_enter_begin(     ao_monitor_enter_t * x);

void    ao_monitor_enter_end(       ao_monitor_enter_t * x);

void    ao_monitor_exit(            ao_monitor_t * x);

void    ao_monitor_notify(          ao_monitor_t * x);

void    ao_monitor_notify_all(      ao_monitor_t * x);

bool    ao_monitor_wait(            ao_monitor_t * x, ao_time_t timeout);

bool    ao_monitor_wait_from(       ao_monitor_t * x, ao_time_t timeout, ao_time_t beginning);

bool    ao_monitor_wait_forever(    ao_monitor_t * x);

bool    ao_monitor_wait_try(        ao_monitor_t * x);

void    ao_monitor_wait_begin(      ao_monitor_wait_t * x);

void    ao_monitor_wait_end(        ao_monitor_wait_t * x);


---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The ao_sys/ao_mutex.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys/ao_mutex.h/ 
subtitle: "ao_sys"
title: "ao_mutex.h"
toc: true
---

```c
#include <ao_async.h>
#include <ao_list.h>
#include <ao_task.h>
#include <ao_time.h>
#include <ao_uint.h>
#include <stdbool.h>

typedef struct  ao_mutex_t      ao_mutex_t;

typedef struct  ao_mutex_lock_t ao_mutex_lock_t;

#ifndef AO_MUTEX

#define AO_MUTEX

struct  ao_mutex_t
{

#if     AO_TASK_CEILING

        ao_task_ceiling_t       ceiling_immediate;

        ao_task_ceiling_t       ceiling_original;

#endif

        ao_list_t               list;

        ao_task_t *             owner;

        ao_uint_t               owner_count;

#if     AO_TASK_SUBMISSION

        ao_task_slave_t         slave;

#endif

};

#endif

#ifndef AO_MUTEX_LOCK

#define AO_MUTEX_LOCK

struct  ao_mutex_lock_t
{
        ao_async_t              async;

#if     AO_TASK_INHERITANCE

        ao_task_master_t        master;

#endif

        ao_mutex_t *            mutex;

        ao_list_node_t          node;

        bool        volatile    result;

        ao_task_t *             task;
};

#endif

bool    ao_mutex_lock(          ao_mutex_t * x, ao_time_t timeout);

bool    ao_mutex_lock_from(     ao_mutex_t * x, ao_time_t timeout, ao_time_t beginning);

bool    ao_mutex_lock_forever(  ao_mutex_t * x);

bool    ao_mutex_lock_try(      ao_mutex_t * x);

void    ao_mutex_lock_begin(    ao_mutex_lock_t * x);

void    ao_mutex_lock_end(      ao_mutex_lock_t * x);

void    ao_mutex_unlock(        ao_mutex_t * x);

```

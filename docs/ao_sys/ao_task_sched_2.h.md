---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The ao_sys/ao_task_sched_2.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys/ao_task_sched_2.h/ 
subtitle: ""
title: "ao_task_sched_2.h"
toc: true
---

# Overview

...

# Includes

```c
#include <ao_list.h>
#include <ao_rb.h>
#include <ao_time.h>
#include <ao_uint.h>
#include <stdbool.h>

typedef     struct  ao_task_t           ao_task_t;

typedef     struct  ao_task_sched_t     ao_task_sched_t;

typedef     struct  ao_task_ceiling_t   ao_task_ceiling_t;

typedef     struct  ao_task_master_t    ao_task_master_t;

typedef     struct  ao_task_slave_t     ao_task_slave_t;

#ifndef     AO_TASK_SCHED_2

#define     AO_TASK_SCHED_2

#endif

#ifndef     AO_TASK_CEILING

#define     AO_TASK_CEILING             (true)

#endif

#ifndef     AO_TASK_INHERITANCE

#define     AO_TASK_INHERITANCE         (true)

#endif

#ifndef     AO_TASK_SUBMISSION

#define     AO_TASK_SUBMISSION                                              \
(                                                                           \
            AO_TASK_CEILING             ||                                  \
            AO_TASK_INHERITANCE                                             \
)

#endif

#ifndef     AO_TASK_PRIO_MIN

#define     AO_TASK_PRIO_MIN            (0)

#endif

#ifndef     AO_TASK_PRIO_MAX

#define     AO_TASK_PRIO_MAX            (AO_UINT_BITS - 1)

#endif

#ifndef     AO_TASK_QUANTUM

#define     AO_TASK_QUANTUM             (AO_MILLISECONDS(10))

#endif

#ifndef     AO_TASK_SCHED_T

#define     AO_TASK_SCHED_T

struct      ao_task_sched_t
{
            ao_list_node_t              node;

#if         AO_TASK_INHERITANCE

            ao_list_t                   masters;

#endif

            ao_uint_t                   prio;

#if         AO_TASK_SUBMISSION

            ao_uint_t                   prio_backup;

            ao_rb_t                     slaves;

#endif

};

#endif

#ifndef     AO_TASK_CEILING_T

#define     AO_TASK_CEILING_T

struct      ao_task_ceiling_t
{
            ao_uint_t                   prio;

            ao_task_slave_t *           slave;

            ao_rb_node_t                slave_ceilings_node;
};

#endif

#ifndef     AO_TASK_MASTER_T

#define     AO_TASK_MASTER_T

struct      ao_task_master_t
{
            ao_uint_t                   prio;

            ao_task_slave_t *           slave;

            ao_rb_node_t                slave_masters_node;

            ao_task_t *                 task;

            ao_list_node_t              task_masters_node;
};

#endif

#ifndef     AO_TASK_SLAVE_T

#define     AO_TASK_SLAVE_T

struct      ao_task_slave_t
{

#if         AO_TASK_CEILING

            ao_rb_t                     ceilings;

#endif

#if         AO_TASK_INHERITANCE

            ao_rb_t                     masters;

#endif

            ao_uint_t                   prio_keep;

            ao_task_t *                 task;

            ao_rb_node_t                task_slaves_node;
};

#endif

ao_uint_t   ao_task_ceiling_get_prio(   ao_task_ceiling_t const * c);

void        ao_task_ceiling_set_prio(   ao_task_ceiling_t       * c, ao_uint_t x);

ao_uint_t   ao_task_get_prio(           ao_task_t         const * t);

void        ao_task_set_prio(           ao_task_t               * t, ao_uint_t x);

```

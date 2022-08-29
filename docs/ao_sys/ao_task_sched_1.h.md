---
author: "Stefan Wagner"
date: 2022-08-29
description: "The ao_sys/ao_task_sched_1.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys/ao_task_sched_1.h/ 
subtitle: "<code>ao_sys</code>"
title: "<code>ao_task_sched_1.h</code>"
toc: true
---

typedef struct  ao_task_sched_t     ao_task_sched_t;

typedef struct  ao_task_ceiling_t   ao_task_ceiling_t;

typedef struct  ao_task_master_t    ao_task_master_t;

typedef struct  ao_task_slave_t     ao_task_slave_t;

#ifndef AO_TASK_SCHED_1

#define AO_TASK_SCHED_1

#endif

#ifndef AO_TASK_CEILING

#define AO_TASK_CEILING             (false)

#endif

#ifndef AO_TASK_INHERITANCE

#define AO_TASK_INHERITANCE         (false)

#endif

#ifndef AO_TASK_SUBMISSION

#define AO_TASK_SUBMISSION          (false)

#endif

#ifndef AO_TASK_QUANTUM

#define AO_TASK_QUANTUM             (AO_MILLISECONDS(10))

#endif

#ifndef AO_TASK_SCHED_T

#define AO_TASK_SCHED_T

struct  ao_task_sched_t
{
        ao_list_node_t              node;
};

#endif

#ifndef AO_TASK_CEILING_T

#define AO_TASK_CEILING_T

struct  ao_task_ceiling_t           { };

#endif

#ifndef AO_TASK_MASTER_T

#define AO_TASK_MASTER_T

struct  ao_task_master_t            { };

#endif

#ifndef AO_TASK_SLAVE_T

#define AO_TASK_SLAVE_T

struct  ao_task_slave_t             { };

#endif


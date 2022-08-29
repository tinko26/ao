---
author: "Stefan Wagner"
breadcrumbs: 2
date: 2022-08-29
description: "The ao_sys/ao_task_sched_0.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys/ao_task_sched_0.h/ 
subtitle: "<code>ao_sys</code>"
title: "<code>ao_task_sched_0.h</code>"
toc: true
---

```c
typedef struct  ao_task_sched_t     ao_task_sched_t;

typedef struct  ao_task_ceiling_t   ao_task_ceiling_t;

typedef struct  ao_task_master_t    ao_task_master_t;

typedef struct  ao_task_slave_t     ao_task_slave_t;

#ifndef AO_TASK_SCHED_0

#define AO_TASK_SCHED_0

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

#ifndef AO_TASK_SCHED_T

#define AO_TASK_SCHED_T

struct  ao_task_sched_t             { };

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

```

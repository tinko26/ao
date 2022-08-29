---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The /src/ao_sys_xc32_pic32mx/ao_task_context.h file of the ao real-time operating system."
draft: true
permalink: /src/ao_sys_xc32_pic32mx/ao_task_context.h/ 
subtitle: ""
title: "ao_task_context.h"
toc: true
---

# Overview

...

# Includes

```c
#include <stdint.h>
#include <xc.h>

typedef struct  ao_task_t               ao_task_t;

typedef struct  ao_task_context_t       ao_task_context_t;

typedef struct  ao_task_context_data_t  ao_task_context_data_t;

#ifndef AO_TASK_CONTEXT

#define AO_TASK_CONTEXT

struct  ao_task_context_t
{
        ao_task_context_data_t *        ptr;
};

#endif

#ifndef AO_TASK_CONTEXT_DATA

#define AO_TASK_CONTEXT_DATA

struct  ao_task_context_data_t
{
        uint32_t                        a0;

        uint32_t                        a1;

        uint32_t                        a2;

        uint32_t                        a3;

        uint32_t                        at;

        uint32_t                        epc;

        uint32_t                        hi;

        uint32_t                        lo;

        uint32_t                        ra;

        uint32_t                        s0;

        uint32_t                        s1;

        uint32_t                        s2;

        uint32_t                        s3;

        uint32_t                        s4;

        uint32_t                        s5;

        uint32_t                        s6;

        uint32_t                        s7;

        uint32_t                        s8;

        uint32_t                        status;

        uint32_t                        t0;

        uint32_t                        t1;

        uint32_t                        t2;

        uint32_t                        t3;

        uint32_t                        t4;

        uint32_t                        t5;

        uint32_t                        t6;

        uint32_t                        t7;

        uint32_t                        t8;

        uint32_t                        t9;

        uint32_t                        v0;

        uint32_t                        v1;

        uint32_t                        pad1;
};

#endif

void    ao_task_start_context(          ao_task_t * t);

#ifndef ao_task_stop_context

#define ao_task_stop_context(           t)

#endif

```

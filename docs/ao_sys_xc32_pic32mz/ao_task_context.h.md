---
author: "Stefan Wagner"
breadcrumbs: 2
date: 2022-08-29
description: "The ao_sys_xc32_pic32mz/ao_task_context.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys_xc32_pic32mz/ao_task_context.h/ 
subtitle: "<code>ao_sys_xc32_pic32mz</code>"
title: "<code>ao_task_context.h</code>"
toc: true
---

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

        uint32_t                        ra;

        uint32_t                        s4;

        uint32_t                        s5;

        uint32_t                        s6;

        uint32_t                        s7;

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

        uint32_t                        hi;

        uint32_t                        lo;

        uint32_t                        hi1;

        uint32_t                        lo1;

        uint32_t                        hi2;

        uint32_t                        lo2;

        uint32_t                        hi3;

        uint32_t                        lo3;

        uint32_t                        dsp_control;

        uint32_t                        fcsr;

        uint64_t                        f0;

        uint64_t                        f1;

        uint64_t                        f2;

        uint64_t                        f3;

        uint64_t                        f4;

        uint64_t                        f5;

        uint64_t                        f6;

        uint64_t                        f7;

        uint64_t                        f8;

        uint64_t                        f9;

        uint64_t                        f10;

        uint64_t                        f11;

        uint64_t                        f12;

        uint64_t                        f13;

        uint64_t                        f14;

        uint64_t                        f15;

        uint64_t                        f16;

        uint64_t                        f17;

        uint64_t                        f18;

        uint64_t                        f19;

        uint64_t                        f20;

        uint64_t                        f21;

        uint64_t                        f22;

        uint64_t                        f23;

        uint64_t                        f24;

        uint64_t                        f25;

        uint64_t                        f26;

        uint64_t                        f27;

        uint64_t                        f28;

        uint64_t                        f29;

        uint64_t                        f30;

        uint64_t                        f31;

        uint32_t                        epc;

        uint32_t                        status;

        uint32_t                        s0;

        uint32_t                        s1;

        uint32_t                        s2;

        uint32_t                        s3;

        uint32_t                        s8;

        uint32_t                        padding;
};

#endif

void    ao_task_start_context(          ao_task_t * t);

#ifndef ao_task_stop_context

#define ao_task_stop_context(t)

#endif


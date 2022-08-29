---
author: "Stefan Wagner"
breadcrumbs: 2
date: 2022-08-29
description: "The ao_sys_xc32_pic32/ao_ir_task.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys_xc32_pic32/ao_ir_task.h/ 
subtitle: "<code>ao_sys_xc32_pic32</code>"
title: "<code>ao_ir_task.h</code>"
toc: true
---

void    ao_task_switch();

#ifndef AO_IR_TASK

#define AO_IR_TASK

static void ao_task_switch_disable(ao_core_t c)
{
    (void) c;

    ao_ir_cs1_disable();
}

static void ao_task_switch_enable(ao_core_t c)
{
    (void) c;

    ao_ir_cs1_enable();
}

static bool ao_task_switch_is_pending(ao_core_t c)
{
    (void) c;

    return ao_ir_cs1_is_pending();
}

static void ao_task_switch_reply(ao_core_t c)
{
    (void) c;

    ao_ir_cs1_reply();
}

static void ao_task_switch_request(ao_core_t c)
{
    (void) c;

    ao_ir_cs1_request();
}

#endif


---
author: "Stefan Wagner"
breadcrumbs: 2
date: 2022-08-29
description: "The ao_sys/ao_timer.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys/ao_timer.h/ 
subtitle: "<code>ao_sys</code>"
title: "<code>ao_timer.h</code>"
toc: true
---

```c
typedef struct  ao_timer_t      ao_timer_t;

#ifndef AO_TIMER

#define AO_TIMER

struct  ao_timer_t
{
        ao_alarm_t              alarm;

        ao_proc_t               callback;

        void *                  callback_parameter;

        ao_time_t               end;

        ao_time_t               period;
};

#endif

void    ao_timer_start(         ao_timer_t * t, ao_time_t phase, ao_time_t period);

void    ao_timer_start_from(    ao_timer_t * t, ao_time_t phase, ao_time_t period, ao_time_t beginning);

void    ao_timer_stop(          ao_timer_t * t);

```

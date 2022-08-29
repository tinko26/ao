---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The ao_sys/ao_timer.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys/ao_timer.h/ 
subtitle: ""
title: "ao_timer.h"
toc: true
---

# Overview

...

# Includes

```c
#include <ao_alarm.h>
#include <ao_func.h>
#include <ao_time.h>

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

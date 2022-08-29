---
author: "Stefan Wagner"
date: 2022-08-29
description: "The ao_sys/ao_alarm.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys/ao_alarm.h/ 
subtitle: "<code>ao_sys</code>"
title: "<code>ao_alarm.h</code>"
toc: true
---

typedef struct  ao_alarm_t      ao_alarm_t;

#ifndef AO_ALARM_DELAY

#define AO_ALARM_DELAY          (AO_MILLISECONDS(100))

#endif

#ifndef AO_ALARM_UPDATE

#define AO_ALARM_UPDATE         (AO_TIME_MAX - AO_ALARM_DELAY + 1)

#endif

#ifndef AO_ALARM

#define AO_ALARM

struct  ao_alarm_t
{
        ao_proc_t               callback;

        void *                  callback_parameter;

        ao_time_t               end;

        ao_alarm_queue_node_t   node;

        bool                    running;
};

#endif

void    ao_alarm_start(         ao_alarm_t * x, ao_time_t t);

void    ao_alarm_start_from(    ao_alarm_t * x, ao_time_t t, ao_time_t b);

void    ao_alarm_stop(          ao_alarm_t * x);


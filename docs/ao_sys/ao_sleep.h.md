---
author: "Stefan Wagner"
date: 2022-08-29
description: "The ao_sys/ao_sleep.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys/ao_sleep.h/ 
subtitle: "<code>ao_sys</code>"
title: "<code>ao_sleep.h</code>"
toc: true
---

typedef struct  ao_sleep_t  ao_sleep_t;

#ifndef AO_SLEEP

#define AO_SLEEP

struct  ao_sleep_t
{
        ao_alarm_t          alarm;

        ao_async_t          async;

        ao_time_t           beginning;

        bool    volatile    result;

        ao_time_t           timeout;
};

#endif

bool    ao_sleep(           ao_time_t timeout);

bool    ao_sleep_from(      ao_time_t timeout, ao_time_t beginning);

bool    ao_sleep_forever();

void    ao_sleep_begin(     ao_sleep_t * x);

void    ao_sleep_end(       ao_sleep_t * x);


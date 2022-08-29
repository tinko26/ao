---
author: "Stefan Wagner"
date: 2022-08-29
description: "The ao_sys/ao_yield.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys/ao_yield.h/ 
subtitle: "<code>ao_sys</code>"
title: "<code>ao_yield.h</code>"
toc: true
---

#ifndef AO_YIELD

#define AO_YIELD

#endif

void    ao_yield();

void    ao_yield_to(ao_task_t * t);


---
author: "Stefan Wagner"
breadcrumbs: 2
date: 2022-08-29
description: "The ao_sys/ao_spin.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys/ao_spin.h/ 
subtitle: "<code>ao_sys</code>"
title: "<code>ao_spin.h</code>"
toc: true
---

```c
#ifndef AO_SPIN

#define AO_SPIN

#endif

void    ao_spin(        ao_time_t timeout);

void    ao_spin_from(   ao_time_t timeout, ao_time_t beginning);

void    ao_spin_forever();

```

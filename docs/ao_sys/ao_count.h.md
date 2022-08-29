---
author: "Stefan Wagner"
breadcrumbs: 2
date: 2022-08-29
description: "The ao_sys/ao_count.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys/ao_count.h/ 
subtitle: "<code>ao_sys</code>"
title: "<code>ao_count.h</code>"
toc: true
---

typedef     uint32_t            ao_count_t;

#ifndef     AO_COUNT_MAX

#define     AO_COUNT_MAX        (UINT32_MAX)

#endif

#ifndef     AO_COUNT_MIN

#define     AO_COUNT_MIN        (0)

#endif

#ifndef     AO_COUNT_FREQUENCY

#define     AO_COUNT_FREQUENCY  (0)

#endif

ao_count_t  ao_count();


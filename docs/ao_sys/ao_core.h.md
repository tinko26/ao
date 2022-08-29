---
author: "Stefan Wagner"
breadcrumbs: 2
date: 2022-08-29
description: "The ao_sys/ao_core.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys/ao_core.h/ 
subtitle: "<code>ao_sys</code>"
title: "<code>ao_core.h</code>"
toc: true
---

typedef     uint32_t        ao_core_t;

#ifndef     AO_CORE_COUNT

#define     AO_CORE_COUNT   (1)

#endif

ao_core_t   ao_core();


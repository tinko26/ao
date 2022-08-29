---
author: "Stefan Wagner"
breadcrumbs: 2
date: 2022-08-29
description: "The ao_sys_xc32_pic32/ao_core.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys_xc32_pic32/ao_core.h/ 
subtitle: "<code>ao_sys_xc32_pic32</code>"
title: "<code>ao_core.h</code>"
toc: true
---

typedef uint32_t        ao_core_t;

#ifndef AO_CORE_COUNT

#define AO_CORE_COUNT   (1)

#endif

#ifndef ao_core

#define ao_core()       (0)

#endif


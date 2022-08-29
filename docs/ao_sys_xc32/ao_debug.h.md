---
author: "Stefan Wagner"
breadcrumbs: 2
date: 2022-08-29
description: "The ao_sys_xc32/ao_debug.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys_xc32/ao_debug.h/ 
subtitle: "<code>ao_sys_xc32</code>"
title: "<code>ao_debug.h</code>"
toc: true
---

#ifndef AO_DEBUG

#ifndef NDEBUG

#ifndef __DEBUG

#define AO_DEBUG    (false)

#else

#define AO_DEBUG    (true)

#endif

#else

#define AO_DEBUG    (false)

#endif

#endif


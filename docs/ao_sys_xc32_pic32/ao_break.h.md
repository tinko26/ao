---
author: "Stefan Wagner"
breadcrumbs: 2
date: 2022-08-29
description: "The ao_sys_xc32_pic32/ao_break.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys_xc32_pic32/ao_break.h/ 
subtitle: "<code>ao_sys_xc32_pic32</code>"
title: "<code>ao_break.h</code>"
toc: true
---

#if     AO_DEBUG

#ifndef ao_break

#define ao_break()  __builtin_software_breakpoint()

#endif

#else

#ifndef ao_break

#define ao_break()

#endif

#endif


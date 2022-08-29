---
author: "Stefan Wagner"
date: 2022-08-29
description: "The ao_sys_xc32_pic32/ao_int.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys_xc32_pic32/ao_int.h/ 
subtitle: "<code>ao_sys_xc32_pic32</code>"
title: "<code>ao_int.h</code>"
toc: true
---

typedef int32_t         ao_int_t;

#ifndef AO_INT_MAX

#define AO_INT_MAX      (INT32_MAX)

#endif

#ifndef AO_INT_MIN

#define AO_INT_MIN      (INT32_MIN)

#endif

#ifndef AO_INT_SIZE

#define AO_INT_SIZE     (4)

#endif


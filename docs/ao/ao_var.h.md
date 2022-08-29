---
author: "Stefan Wagner"
breadcrumbs: 2
date: 2022-08-29
description: "The ao/ao_var.h module of the ao real-time operating system."
draft: true
permalink: /ao/ao_var.h/ 
subtitle: "<code>ao</code>"
title: "<code>ao_var.h</code>"
toc: true
---

#ifndef ao_clear

#define ao_clear(p, t)      ao_memset(p, 0, sizeof(t));

#endif

#ifndef ao_copy

#define ao_copy(d, s, t)    ao_memcpy(d, s, sizeof(t));

#endif


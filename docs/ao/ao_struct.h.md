---
author: "Stefan Wagner"
breadcrumbs: 2
date: 2022-08-29
description: "The ao/ao_struct.h module of the ao real-time operating system."
draft: true
permalink: /ao/ao_struct.h/ 
subtitle: "<code>ao</code>"
title: "<code>ao_struct.h</code>"
toc: true
---

#ifndef ao_containerof

#define ao_containerof(p, t, m)     ((t *) ((uint8_t *) (p) - offsetof(t, m)))

#endif


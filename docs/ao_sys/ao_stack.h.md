---
author: "Stefan Wagner"
breadcrumbs: 2
date: 2022-08-29
description: "The ao_sys/ao_stack.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys/ao_stack.h/ 
subtitle: "<code>ao_sys</code>"
title: "<code>ao_stack.h</code>"
toc: true
---

```c
void    ao_stack_fill(                  void * beginning, size_t size);

size_t  ao_stack_get_high_water_mark(   void const * beginning, size_t size);

```

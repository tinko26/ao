---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The ao_sys/ao_stack.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys/ao_stack.h/ 
subtitle: ""
title: "ao_stack.h"
toc: true
---

```c
#include <stddef.h>

void    ao_stack_fill(                  void * beginning, size_t size);

size_t  ao_stack_get_high_water_mark(   void const * beginning, size_t size);

```

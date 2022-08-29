---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The ao_sys_xc32_pic32/ao_stack.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys_xc32_pic32/ao_stack.h/ 
subtitle: ""
title: "ao_stack.h"
toc: true
---

# Overview

...

# Includes

```c
#include <stddef.h>

#ifndef AO_STACK

#define AO_STACK

#endif

#ifndef AO_STACK_ALIGN

#define AO_STACK_ALIGN                  (8)

#endif

#ifndef AO_STACK_FILL

#define AO_STACK_FILL                   (0xDEADBEEF)

#endif

void    ao_stack_fill(                  void * beginning, size_t size);

size_t  ao_stack_get_high_water_mark(   void const * beginning, size_t size);

```

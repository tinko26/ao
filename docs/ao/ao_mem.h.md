---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The ao/ao_mem.h module of the ao real-time operating system."
draft: true
permalink: /ao/ao_mem.h/ 
subtitle: "ao"
title: "ao_mem.h"
toc: true
---

```c
#include <stddef.h>
#include <stdint.h>

void *  ao_memcpy(void * d, void const * s, size_t n);

void *  ao_memmove(void * d, void const * s, size_t n);

void *  ao_memset(void * p, uint8_t v, size_t n);

```

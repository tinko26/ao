---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The ao/ao_struct.h module of the ao real-time operating system."
draft: true
permalink: /ao/ao_struct.h/ 
subtitle: ""
title: "ao_struct.h"
toc: true
---

```c
#include <stddef.h>
#include <stdint.h>

#ifndef ao_containerof

#define ao_containerof(p, t, m)     ((t *) ((uint8_t *) (p) - offsetof(t, m)))

#endif

```

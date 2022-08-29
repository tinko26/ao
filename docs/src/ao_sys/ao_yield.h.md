---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The /src/ao_sys/ao_yield.h file of the ao real-time operating system."
draft: true
permalink: /src/ao_sys/ao_yield.h/ 
subtitle: ""
title: "ao_yield.h"
toc: true
---

# Overview

...

# Includes

```c
#include <ao_task.h>

#ifndef AO_YIELD

#define AO_YIELD

#endif

void    ao_yield();

void    ao_yield_to(ao_task_t * t);

```

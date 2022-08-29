---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The /src/ao_sys/ao_self.h file of the ao real-time operating system."
draft: true
permalink: /src/ao_sys/ao_self.h/ 
subtitle: ""
title: "ao_self.h"
toc: true
---

# Overview

...

# Includes

```c
#include <ao_task.h>

#ifndef     AO_SELF

#define     AO_SELF

#endif

ao_task_t * ao_self();

void        ao_stop();

void        ao_suspend();

```

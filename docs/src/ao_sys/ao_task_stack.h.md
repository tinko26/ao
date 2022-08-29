---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The /src/ao_sys/ao_task_stack.h file of the ao real-time operating system."
draft: true
permalink: /src/ao_sys/ao_task_stack.h/ 
subtitle: ""
title: "ao_task_stack.h"
toc: true
---

# Overview

...

# Includes

```c
#ifndef AO_TASK_STACK

#define AO_TASK_STACK       (2)

#endif

#if     AO_TASK_STACK ==    (0)

#include <ao_task_stack_0.h>

#elif   AO_TASK_STACK ==    (1)

#include <ao_task_stack_1.h>

#elif   AO_TASK_STACK ==    (2)

#include <ao_task_stack_2.h>

#endif

```

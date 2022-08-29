---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The ao_sys/ao_alarm_queue_2.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys/ao_alarm_queue_2.h/ 
subtitle: ""
title: "ao_alarm_queue_2.h"
toc: true
---

# Overview

...

# Includes

```c
#include <stdbool.h>
#include <stddef.h>

typedef size_t                      ao_alarm_queue_node_t;

#ifndef AO_ALARM_QUEUE_2

#define AO_ALARM_QUEUE_2

#endif

#ifndef AO_ALARM_QUEUE_ASSERT

#define AO_ALARM_QUEUE_ASSERT       (false)

#endif

#ifndef AO_ALARM_QUEUE_CAPACITY

#define AO_ALARM_QUEUE_CAPACITY     (128)

#endif

#ifndef AO_ALARM_QUEUE_COUNT_MAX

#define AO_ALARM_QUEUE_COUNT_MAX    (false)

#endif

extern  size_t          volatile    ao_alarm_queue_count;

extern  size_t          volatile    ao_alarm_queue_count_max;

```

---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The ao_sys/ao_alarm_queue_3.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys/ao_alarm_queue_3.h/ 
subtitle: "ao_sys"
title: "ao_alarm_queue_3.h"
toc: true
---

```c
#include <ao_heap.h>
#include <stdbool.h>

typedef ao_heap_t               ao_alarm_queue_t;

typedef ao_heap_node_t          ao_alarm_queue_node_t;

#ifndef AO_ALARM_QUEUE_3

#define AO_ALARM_QUEUE_3

#endif

#ifndef AO_ALARM_QUEUE_ASSERT

#define AO_ALARM_QUEUE_ASSERT   (false)

#endif

```

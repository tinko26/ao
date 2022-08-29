---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The ao_sys/ao_alarm_queue_5.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys/ao_alarm_queue_5.h/ 
subtitle: ""
title: "ao_alarm_queue_5.h"
toc: true
---

```c
#include <ao_rb.h>
#include <stdbool.h>

typedef ao_rb_t                 ao_alarm_queue_t;

typedef ao_rb_node_t            ao_alarm_queue_node_t;

#ifndef AO_ALARM_QUEUE_5

#define AO_ALARM_QUEUE_5

#endif

#ifndef AO_ALARM_QUEUE_ASSERT

#define AO_ALARM_QUEUE_ASSERT   (false)

#endif

#ifndef AO_ALARM_QUEUE_CACHE

#define AO_ALARM_QUEUE_CACHE    (false)

#endif

```

---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The ao_sys/ao_alarm_queue_1.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys/ao_alarm_queue_1.h/ 
subtitle: "ao_sys"
title: "ao_alarm_queue_1.h"
toc: true
---

```c
#include <ao_slist.h>
#include <stdbool.h>

typedef ao_slist_t              ao_alarm_queue_t;

typedef ao_slist_node_t         ao_alarm_queue_node_t;

#ifndef AO_ALARM_QUEUE_1

#define AO_ALARM_QUEUE_1

#endif

#ifndef AO_ALARM_QUEUE_ASSERT

#define AO_ALARM_QUEUE_ASSERT   (false)

#endif

```

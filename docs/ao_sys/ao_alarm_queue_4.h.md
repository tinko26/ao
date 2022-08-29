---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The ao_sys/ao_alarm_queue_4.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys/ao_alarm_queue_4.h/ 
subtitle: ""
title: "ao_alarm_queue_4.h"
toc: true
---

# Overview

...

# Includes

```c
#include <ao_avl.h>
#include <stdbool.h>

typedef ao_avl_t                ao_alarm_queue_t;

typedef ao_avl_node_t           ao_alarm_queue_node_t;

#ifndef AO_ALARM_QUEUE_4

#define AO_ALARM_QUEUE_4

#endif

#ifndef AO_ALARM_QUEUE_ASSERT

#define AO_ALARM_QUEUE_ASSERT   (false)

#endif

#ifndef AO_ALARM_QUEUE_CACHE

#define AO_ALARM_QUEUE_CACHE    (false)

#endif

```

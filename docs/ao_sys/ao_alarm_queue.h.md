---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The ao_sys/ao_alarm_queue.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys/ao_alarm_queue.h/ 
subtitle: ""
title: "ao_alarm_queue.h"
toc: true
---

# Overview

...

# Includes

```c
#ifndef AO_ALARM_QUEUE

#define AO_ALARM_QUEUE      (5)

#endif

#if     AO_ALARM_QUEUE ==   (0)

#include <ao_alarm_queue_0.h>

#elif   AO_ALARM_QUEUE ==   (1)

#include <ao_alarm_queue_1.h>

#elif   AO_ALARM_QUEUE ==   (2)

#include <ao_alarm_queue_2.h>

#elif   AO_ALARM_QUEUE ==   (3)

#include <ao_alarm_queue_3.h>

#elif   AO_ALARM_QUEUE ==   (4)

#include <ao_alarm_queue_4.h>

#elif   AO_ALARM_QUEUE ==   (5)

#include <ao_alarm_queue_5.h>

#endif

```

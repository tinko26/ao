---
author: "Stefan Wagner"
date: 2022-08-15
description: "The ao_alarm_queue_1.h module of the ao real-time operating system."
draft: false
permalink: /modules/alarm-queue-1/
subtitle: "Alarm queue based on a sorted list"
title: "<code>ao_alarm_queue_1.h</code>"
toc: true
---

# Overview

This module implements the [alarm queue](../alarm-queue.md) based on a [sorted list](../sorted-lists.md). Therefore, the alarm queue can contain an unlimited number of alarms. The following table exhibits the time complexities of the individual operations.

| Operation | |
|-----------|-|
| Insert | $$O(n)$$ |
| Peek | $$O(1)$$ |
| Remove | $$O(1)$$ |
| Remove peek | $$O(1)$$ |

# Configuration

The alarm queue can be configured to check its correctness upon each insertion and removal, which takes linear time. If that is not the case, a runtime [assertion](../assertions.md) failure is triggered. This can aid in a debugging scenario. By default, this option is disabled.

```c
#define AO_ALARM_QUEUE_ASSERT
```

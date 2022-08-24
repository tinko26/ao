---
author: "Stefan Wagner"
date: 2022-08-15
description: "The ao_alarm_queue_3.h module of the ao real-time operating system."
draft: false
permalink: /modules/alarm-queue-3/
title: "ao_alarm_queue_3.h"
---

# Overview

This module implements the [alarm queue](../alarm-queue.md) using a pointer-based [binary heap](../binary-heaps.md). Therefore, the alarm queue can contain an unlimited number of alarms. The following table exhibits the time complexities of the individual operations.

| Operation | |
|-----------|-|
| Insert | $$O(\log n)$$ |
| Peek | $$O(1)$$ |
| Remove | $$O(\log n)$$ |
| Remove peek | $$O(\log n)$$ |

# Configuration

The alarm queue can be configured to check its correctness upon each insertion and removal, which takes linear time. If that is not the case, a runtime [assertion](../assertions.md) failure is triggered. This can aid in a debugging scenario. By default, this option is disabled.

```c
#define AO_ALARM_QUEUE_ASSERT
```

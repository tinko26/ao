---
api: true
author: "Stefan Wagner"
date: 2022-08-31
description: "The /src/ao_sys/ao_alarm_queue.h file of the ao real-time operating system."
draft: true
permalink: /api/src/ao_sys/ao_alarm_queue.h/
seealso:
- title: "<code>ao_alarm.h</code>"
  url: /api/src/ao_sys/ao_alarm.h/
subtitle: "Alarm queue"
title: "ao_alarm_queue.h"
toc: true
---

# Configuration

Select the alarm queue implementation.

```c
#define AO_ALARM_QUEUE (5)
```

The following options are available.

| `0` | [`ao_alarm_queue_0`](ao_alarm_queue_0.h.md) | Stub |
| `1` | [`ao_alarm_queue_1`](ao_alarm_queue_1.h.md) | Based on a sorted list |
| `2` | [`ao_alarm_queue_2`](ao_alarm_queue_2.h.md) | Based on an array-based binary heap |
| `3` | [`ao_alarm_queue_3`](ao_alarm_queue_3.h.md) | Based on a pointer-based binary heap |
| `4` | [`ao_alarm_queue_4`](ao_alarm_queue_4.h.md) | Based on an AVL tree |
| `5` | [`ao_alarm_queue_5`](ao_alarm_queue_5.h.md) | Based on a red-black tree |

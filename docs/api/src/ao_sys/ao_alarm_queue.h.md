---
author: "Stefan Wagner"
date: 2022-08-31
draft: true
permalink: /api/src/ao_sys/ao_alarm_queue.h/
seealso:
- /api/src/ao_sys/ao_alarm.h/
toc: true
---

# Configuration

## `AO_ALARM_QUEUE`

Select the alarm queue implementation.

```c
#define AO_ALARM_QUEUE (5)
```

The following options are available.

| [`ao_alarm_queue_0`](ao_alarm_queue_0.h.md) | Stub |
| [`ao_alarm_queue_1`](ao_alarm_queue_1.h.md) | Based on a sorted list |
| [`ao_alarm_queue_2`](ao_alarm_queue_2.h.md) | Based on an array-based binary heap |
| [`ao_alarm_queue_3`](ao_alarm_queue_3.h.md) | Based on a pointer-based binary heap |
| [`ao_alarm_queue_4`](ao_alarm_queue_4.h.md) | Based on an AVL tree |
| [`ao_alarm_queue_5`](ao_alarm_queue_5.h.md) | Based on a red-black tree |

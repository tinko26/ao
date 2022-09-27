---
author: "Stefan Wagner"
date: 2022-09-27
draft: true
permalink: /api/src/ao_sys/ao_alarm_queue_1.h/
toc: true
---

# Notes

This module provides an implementation for the alarm queue based on a sorted list. Therefore, the alarm queue can contain an unlimited number of alarms. The following table exhibits the time complexities of the individual operations.

| Insert | $$O(n)$$ |
| Peek | $$O(1)$$ |
| Remove | $$O(1)$$ |
| Remove peek | $$O(1)$$ |

# Include

| [`ao_slist.h`](../ao/ao_slist.h.md) |
| `stdbool.h` |

# Configuration

## `AO_ALARM_QUEUE_ASSERT`

```c
#define AO_ALARM_QUEUE_ASSERT (false)
```

Defines whether to assert the correctness of the alarm queue upon each insertion and removal, in linear time. If that is not the case, a runtime assertion failure is triggered. This can aid in a debugging scenario.

# Types

## `ao_alarm_queue_t`

```c
typedef ao_slist_t ao_alarm_queue_t;
```

Represents the alarm queue.

## `ao_alarm_queue_node_t`

```c
typedef ao_slist_node_t ao_alarm_queue_node_t;
```

Represents an alarm queue node.

---
author: "Stefan Wagner"
date: 2022-09-27
draft: true
permalink: /api/src/ao_sys/ao_alarm_queue_4.h/
toc: true
---

# Notes

This module provides an implementation for the alarm queue based on an AVL tree. Therefore, the alarm queue can contain an unlimited number of alarms. The following table exhibits the time complexities of the individual operations.

| Insert | $$O(\log n)$$ |
| Peek | $$O(\log n)$$ |
| Remove | $$O(\log n)$$ |
| Remove peek | $$O(\log n)$$ |

# Include

| [`ao_avl.h`](../ao/ao_avl.h.md) |
| `stdbool.h` |

# Configuration

## `AO_ALARM_QUEUE_ASSERT`

```c
#define AO_ALARM_QUEUE_ASSERT (false)
```

Defines whether to assert the correctness of the alarm queue upon each insertion and removal, in linear time. If that is not the case, a runtime assertion failure is triggered. This can aid in a debugging scenario.

## `AO_ALARM_QUEUE_CACHE`

```c
#define AO_ALARM_QUEUE_CACHE (false)
```

Peeking the alarm queue is a quite frequent operation. However, with this implementation, it is not a constant-time operation, but takes logarithmic time. In order to speed things up a little bit, the alarm queue can be configured to cache the current front element after each insertion and removal.

# Types

## `ao_alarm_queue_t`

```c
typedef ao_avl_t ao_alarm_queue_t;
```

Represents the alarm queue.

## `ao_alarm_queue_node_t`

```c
typedef ao_avl_node_t ao_alarm_queue_node_t;
```

Represents an alarm queue node.

---
author: "Stefan Wagner"
date: 2022-08-31
draft: true
permalink: /api/src/ao_sys/ao_alarm_queue_2.h/
toc: true
---

# Notes

This module provides an implementation for the alarm queue based on an array-based binary heap. Since the array is allocated statically, the capacity of the alarm queue is both fixed and limited, which can pose a challenge on a proper configuration. The following table exhibits the time complexities of the individual operations.

| Insert | $$O(\log n)$$ |
| Peek | $$O(1)$$ |
| Remove | $$O(\log n)$$ |
| Remove peek | $$O(\log n)$$ |

# Include

| `stdbool.h` |
| `stddef.h` |

# Identifier

```c
#define AO_ALARM_QUEUE_2
```

# Configuration

## `AO_ALARM_QUEUE_ASSERT`

```c
#define AO_ALARM_QUEUE_ASSERT (false)
```

Defines whether to assert the correctness of the alarm queue upon each insertion and removal, in linear time. If that is not the case, a runtime assertion failure is triggered. This can aid in a debugging scenario.

## `AO_ALARM_QUEUE_CAPACITY`

```c
#define AO_ALARM_QUEUE_CAPACITY (128)
```

The capacity of the alarm queue.

## `AO_ALARM_QUEUE_COUNT_MAX`

```c
#define AO_ALARM_QUEUE_COUNT_MAX (false)
```

Defines whether to keep track of the maximum number of nodes.

# Types

## `ao_alarm_queue_node_t`

```c
typedef size_t ao_alarm_queue_node_t;
```

This type represents an alarm queue node.

# Variables

## `ao_alarm_queue_count`
## `ao_alarm_queue_count_max`

```c
extern size_t volatile ao_alarm_queue_count;
extern size_t volatile ao_alarm_queue_count_max;
```

The current and maximum numbers of nodes, respectively, in the alarm queue.

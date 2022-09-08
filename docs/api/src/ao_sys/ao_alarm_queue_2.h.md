---
author: "Stefan Wagner"
date: 2022-08-31
draft: true
permalink: /api/src/ao_sys/ao_alarm_queue_2.h/
seealso:
- /api/src/ao_sys/ao_alarm_queue.h/
toc: true
---

# Overview

This module provides an implementation for the alarm queue based on an array-based binary heap. Since the array is allocated statically, the capacity of the alarm queue is both fixed and limited, which can pose a challenge on a proper configuration. The following table exhibits the time complexities of the individual operations.

| Insert | $$O(\log n)$$ |
| Peek | $$O(1)$$ |
| Remove | $$O(\log n)$$ |
| Remove peek | $$O(\log n)$$ |

# Include

```c
#include <stdbool.h>
#include <stddef.h>
```

# Configuration

## `AO_ALARM_QUEUE_ASSERT`

Assert the correctness of the alarm queue upon each insertion and removal in linear time. If that is not the case, a runtime assertion failure is triggered. This can aid in a debugging scenario.

```c
#define AO_ALARM_QUEUE_ASSERT    (false)
```

## `AO_ALARM_QUEUE_CAPACITY`

The capacity of the alarm queue.

```c
#define AO_ALARM_QUEUE_CAPACITY  (128)
```

## `AO_ALARM_QUEUE_COUNT_MAX`

Keep track of the maximum number of nodes.

```c
#define AO_ALARM_QUEUE_COUNT_MAX (false)
```

# Typedefs

```c
typedef size_t ao_alarm_queue_node_t;
```

# Types

## `ao_alarm_queue_node_t`

This type represents an alarm queue node.

# Variables

## `ao_alarm_queue_count`
## `ao_alarm_queue_count_max`

The current and maximum numbers of nodes, respectively, in the alarm queue.

```c
extern size_t volatile ao_alarm_queue_count;
extern size_t volatile ao_alarm_queue_count_max;
```

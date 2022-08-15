---
author: "Stefan Wagner"
date: 2022-08-15
description: "The ao_alarm_queue_2.h module of the ao real-time operating system."
draft: false
permalink: /modules/alarm-queue-2/
title: "ao_alarm_queue_2.h"
---

# ao_alarm_queue_2.h

This module implements the [alarm queue](../alarm-queue.md) using an array-based [binary heap](../binary-heaps.md). Since the array is allocated statically, the capacity of the alarm queue is both fixed and limited, which can pose a challenge on a proper configuration. The following table exhibits the time complexities of the individual operations.

| Operation | |
|-----------|-|
| Insert | $$O(\log n)$$ |
| Peek | $$O(1)$$ |
| Remove | $$O(\log n)$$ |
| Remove peek | $$O(\log n)$$ |

## Configuration

The capacity of the alarm queue must be configured properly. The default value is `128`.

```c
#define AO_ALARM_QUEUE_CAPACITY
```

The alarm queue keeps track of the current number of elements. Additionally, it can be configured to keep track of the maximum number. By default, this option is disabled.

```c
#define AO_ALARM_QUEUE_COUNT_MAX
```

The alarm queue can be configured to check its correctness upon each insertion and removal, which takes linear time. If that is not the case, a runtime [assertion](../assertions.md) failure is triggered. This can aid in a debugging scenario. By default, this option is disabled.

```c
#define AO_ALARM_QUEUE_ASSERT
```

## Variables

The module exposes the following global variables.

| Variable | |
|----------|-|
| `ao_alloc_queue_count` | The current number of elements. |
| `ao_alloc_queue_count_max` | The maximum number of elements. This variable is absent, if the `AO_ALARM_QUEUE_COUNT_MAX` configuration option is disabled. |

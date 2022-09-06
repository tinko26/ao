---
api: true
author: "Stefan Wagner"
date: 2022-08-31
description: "The /src/ao_sys/ao_alarm_queue_5.h file of the ao real-time operating system."
draft: true
permalink: /api/src/ao_sys/ao_alarm_queue_5.h/
seealso:
- /api/src/ao_sys/ao_alarm_queue.h/
- /api/src/ao/ao_rb.h/
subtitle: "Alarm queue based on a red-black tree"
title: "ao_alarm_queue_5.h"
toc: true
---

# Overview

This module provides an implementation for the alarm queue based on a red-black tree. Therefore, the alarm queue can contain an unlimited number of alarms. The following table exhibits the time complexities of the individual operations.

| Insert | $$O(\log n)$$ |
| Peek | $$O(\log n)$$ |
| Remove | $$O(\log n)$$ |
| Remove peek | $$O(\log n)$$ |

# Include

```c
#include <ao_rb.h>
#include <stdbool.h>
```

# Typedefs

```c
typedef ao_rb_t      ao_alarm_queue_t;
```

```c
typedef ao_rb_node_t ao_alarm_queue_node_t;
```

# Configuration

Assert the correctness of the alarm queue upon each insertion and removal in linear time. If that is not the case, a runtime assertion failure is triggered. This can aid in a debugging scenario.

```c
#define AO_ALARM_QUEUE_ASSERT (false)
```

Peeking the alarm queue is a quite frequent operation. However, with this implementation, it is not a constant-time operation, but takes logarithmic time. In order to speed things up a little bit, the alarm queue can be configured to cache the current front element after each insertion and removal.

```c
#define AO_ALARM_QUEUE_CACHE  (false)
```

# Types

## `ao_alarm_queue_t`

This type represents the alarm queue.

## `ao_alarm_queue_node_t`

This type represents an alarm queue node.

---
author: "Stefan Wagner"
date: 2022-08-15
description: "The ao_alarm_queue_4.h module of the ao real-time operating system."
draft: false
permalink: /modules/alarm-queue-4/
title: "ao_alarm_queue_4.h"
---

# ao_alarm_queue_4.h

This module implements the [alarm queue](../alarm-queue.md) using an [AVL tree](../avl-trees.md). Therefore, the alarm queue can contain an unlimited number of alarms. The following table exhibits the time complexities of the individual operations.

| Operation | |
|-----------|-|
| Insert | $$O(\log n)$$ |
| Peek | $$O(\log n)$$ |
| Remove | $$O(\log n)$$ |
| Remove peek | $$O(\log n)$$ |

## Configuration

The alarm queue can be configured to check its correctness upon each insertion and removal, which takes linear time. If that is not the case, a runtime [assertion](../assertions.md) failure is triggered. This can aid in a debugging scenario. By default, this option is disabled.

```c
#define AO_ALARM_QUEUE_ASSERT
```

Peeking the alarm queue is a quite frequent operation. However, with this implementation, it is not a constant-time operation, but takes logarithmic time. In order to speed things up a little bit, the alarm queue can be configured to cache the current front element after each insertion and removal. By default, this option is disabled, too.

```c
#define AO_ALARM_QUEUE_CACHE
```

## External Links

[https://en.wikipedia.org/wiki/AVL_tree](https://en.wikipedia.org/wiki/AVL_tree)

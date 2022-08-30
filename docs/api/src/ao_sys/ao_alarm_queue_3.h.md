---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The /src/ao_sys/ao_alarm_queue_3.h file of the ao real-time operating system."
draft: true
permalink: /api/src/ao_sys/ao_alarm_queue_3.h/
subtitle: ""
title: "ao_alarm_queue_3.h"
toc: true
---

# Include

```c
#include <ao_heap.h>
#include <stdbool.h>
```

# Typedefs

```c
typedef ao_heap_t ao_alarm_queue_t;
```

```c
typedef ao_heap_node_t ao_alarm_queue_node_t;
```

# Constants

```c
#define AO_ALARM_QUEUE_ASSERT (false)
```


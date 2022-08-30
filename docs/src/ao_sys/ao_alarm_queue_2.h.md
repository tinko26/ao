---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The /src/ao_sys/ao_alarm_queue_2.h file of the ao real-time operating system."
draft: true
permalink: /src/ao_sys/ao_alarm_queue_2.h/
subtitle: ""
title: "ao_alarm_queue_2.h"
toc: true
---

# Include

```c
#include <stdbool.h>
#include <stddef.h>
```

# Typedefs

```c
typedef size_t ao_alarm_queue_node_t;
```

# Constants

```c
#define AO_ALARM_QUEUE_ASSERT (false)
```

```c
#define AO_ALARM_QUEUE_CAPACITY (128)
```

```c
#define AO_ALARM_QUEUE_COUNT_MAX (false)
```

# Variables

```c
extern size_t volatile ao_alarm_queue_count;
```

```c
extern size_t volatile ao_alarm_queue_count_max;
```


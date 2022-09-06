---
api: true
author: "Stefan Wagner"
date: 2022-08-31
description: "The /src/ao_sys/ao_yield.h file of the ao real-time operating system."
draft: true
permalink: /api/src/ao_sys/ao_yield.h/
subtitle: "Yielding"
title: "ao_yield.h"
toc: true
wiki:
- coroutine
- producer-consumer-problem
---

# Include

```c
#include <ao_task.h>
```

# Functions

```c
void ao_yield();
```

```c
void ao_yield_to(ao_task_t * t);
```

---
author: "Stefan Wagner"
date: 2022-08-31
draft: true
external:
- https://en.wikipedia.org/wiki/Coroutine : "Coroutine"
- https://en.wikipedia.org/wiki/Producer-consumer_problem : "Producer-consumer problem"
permalink: /api/src/ao_sys/ao_yield.h/
toc: true
---

# Include

```c
#include <ao_task.h>
```

# Functions

## `ao_yield`

```c
void ao_yield();
```

## `ao_yield_to`

```c
void ao_yield_to(ao_task_t * t);
```

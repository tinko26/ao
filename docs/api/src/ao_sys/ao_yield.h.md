---
author: "Stefan Wagner"
date: 2022-09-13
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

# Identifier

```c
#define AO_YIELD
```

# Functions

## `ao_yield`

```c
void ao_yield();
```

Yields execution to another task.

## `ao_yield_to`

```c
void ao_yield_to(ao_task_t * t);
```

Yields execution to the specified task. Thereby, this function blocks the calling task indefinitely and unblocks the specified task.

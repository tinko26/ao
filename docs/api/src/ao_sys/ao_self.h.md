---
author: "Stefan Wagner"
date: 2022-08-31
draft: true
permalink: /api/src/ao_sys/ao_self.h/
toc: true
---

# Include

```c
#include <ao_task.h>
```

# Identifier

```c
#define AO_SELF
```

# Functions

## `ao_self`

```c
ao_task_t * ao_self();
```

Gets the running task.

## `ao_stop`
## `ao_suspend`

```c
void ao_stop();
void ao_suspend();
```

Stops or suspends the running task, respectively.

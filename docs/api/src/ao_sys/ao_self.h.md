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

# Functions

Get the running task.

```c
ao_task_t * ao_self();
```

Stop or suspend the running task, respectively.

```c
void ao_stop();
void ao_suspend();
```

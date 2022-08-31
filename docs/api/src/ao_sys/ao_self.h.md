---
api: true
author: "Stefan Wagner"
date: 2022-08-31
description: "The /src/ao_sys/ao_self.h file of the ao real-time operating system."
draft: true
permalink: /api/src/ao_sys/ao_self.h/
subtitle: "Running task"
title: "ao_self.h"
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

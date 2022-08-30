---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The /src/ao_sys/ao_ir_task.h file of the ao real-time operating system."
draft: true
permalink: /api/src/ao_sys/ao_ir_task.h/
subtitle: ""
title: "ao_ir_task.h"
toc: true
---

# Include

```c
#include <ao_core.h>
#include <stdbool.h>
```

# Functions

```c
void ao_task_switch();
```

```c
void ao_task_switch_disable( ao_core_t c);
```

```c
void ao_task_switch_enable( ao_core_t c);
```

```c
bool ao_task_switch_is_pending( ao_core_t c);
```

```c
void ao_task_switch_reply( ao_core_t c);
```

```c
void ao_task_switch_request( ao_core_t c);
```


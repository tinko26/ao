---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The /src/ao_sys/ao_task_sched_1.h file of the ao real-time operating system."
draft: true
permalink: /src/ao_sys/ao_task_sched_1.h/
subtitle: ""
title: "ao_task_sched_1.h"
toc: true
---

# Include

```c
#include <ao_list.h>
#include <ao_time.h>
#include <stdbool.h>
```

# Typedefs

```c
typedef struct ao_task_sched_t ao_task_sched_t;
```

```c
typedef struct ao_task_ceiling_t ao_task_ceiling_t;
```

```c
typedef struct ao_task_master_t ao_task_master_t;
```

```c
typedef struct ao_task_slave_t ao_task_slave_t;
```

# Constants

```c
#define AO_TASK_CEILING (false)
```

```c
#define AO_TASK_INHERITANCE (false)
```

```c
#define AO_TASK_QUANTUM (AO_MILLISECONDS(10))
```

```c
#define AO_TASK_SUBMISSION (false)
```

# Types

## `ao_task_sched_t`

```c
struct ao_task_sched_t
{
    ao_list_node_t node;
};
```

Members:

| `node` | |

## `ao_task_ceiling_t`

```c
struct ao_task_ceiling_t { };
```

## `ao_task_master_t`

```c
struct ao_task_master_t { };
```

## `ao_task_slave_t`

```c
struct ao_task_slave_t { };
```


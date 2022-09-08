---
author: "Stefan Wagner"
date: 2022-08-31
draft: true
permalink: /api/src/ao_sys/ao_task_sched_1.h/
toc: true
---

# Include

```c
#include <ao_list.h>
#include <ao_time.h>
#include <stdbool.h>
```

# Configuration

## `AO_TASK_QUANTUM`

The quantum or time slice.

```c
#define AO_TASK_QUANTUM (AO_MILLISECONDS(10))
```

# Constants

## `AO_TASK_CEILING`
## `AO_TASK_INHERITANCE`
## `AO_TASK_SUBMISSION`

This scheduler supports neither task ceiling nor task inheritance.

```c
#define AO_TASK_CEILING     (false)
#define AO_TASK_INHERITANCE (false)
#define AO_TASK_SUBMISSION  (false)
```

# Typedefs

```c
typedef struct ao_task_sched_t   ao_task_sched_t;
typedef struct ao_task_ceiling_t ao_task_ceiling_t;
typedef struct ao_task_master_t  ao_task_master_t;
typedef struct ao_task_slave_t   ao_task_slave_t;
```

# Types

## `ao_task_sched_t`

```c
struct ao_task_sched_t
{
    ao_list_node_t node;
};
```

It consists of the following members.

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

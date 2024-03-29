---
author: "Stefan Wagner"
date: 2022-09-13
draft: true
permalink: /api/src/ao_sys/ao_task_sched_1.h/
toc: true
---

# Include

| [`ao_list.h`](../ao/ao_list.h.md) |
| [`ao_time.h`](ao_time.h.md) |
| `stdbool.h` |

# Configuration

## `AO_TASK_QUANTUM`

```c
#define AO_TASK_QUANTUM (AO_MILLISECONDS(10))
```

The quantum or time slice.

# Constants

## `AO_TASK_CEILING`
## `AO_TASK_INHERITANCE`
## `AO_TASK_SUBMISSION`

```c
#define AO_TASK_CEILING     (false)
#define AO_TASK_INHERITANCE (false)
#define AO_TASK_SUBMISSION  (false)
```

This scheduler supports neither task ceiling nor task inheritance.

# Types

## `ao_task_sched_t`

```c
typedef struct ao_task_sched_t ao_task_sched_t;
```

Represents scheduler-related data of a task.

## `ao_task_ceiling_t`

```c
typedef struct ao_task_ceiling_t ao_task_ceiling_t;
```

Represents a task ceiling.

## `ao_task_master_t`

```c
typedef struct ao_task_master_t ao_task_master_t;
```

Represents a task master.

## `ao_task_slave_t`

```c
typedef struct ao_task_slave_t ao_task_slave_t;
```

Represents a task slave.

# Structs

## `ao_task_sched_t`

```c
struct ao_task_sched_t
{
    ao_list_node_t node;
};
```

| `node` | The node for the scheduler's list of ready tasks. |

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

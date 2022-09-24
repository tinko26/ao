---
author: "Stefan Wagner"
date: 2022-09-13
draft: true
permalink: /api/src/ao_sys/ao_task_sched_2.h/
toc: true
---

# Include

[`ao_list.h`](../ao/ao_list.h.md) <br/>
[`ao_rb.h`](../ao/ao_rb.h.md) <br/>
[`ao_time.h`](ao_time.h.md) <br/>
[`ao_uint.h`](../ao/ao_uint.h.md) <br/>
`stdbool.h`

# Identifier

```c
#define AO_TASK_SCHED_2
```

# Configuration

## `AO_TASK_CEILING`

```c
#define AO_TASK_CEILING (true)
```

Defines whether to support task ceiling.

## `AO_TASK_INHERITANCE`

```c
#define AO_TASK_INHERITANCE (true)
```

Defines whether to support task inheritance.

## `AO_TASK_QUANTUM`

```c
#define AO_TASK_QUANTUM (AO_MILLISECONDS(10))
```

The quantum or time slice.

# Constants

## `AO_TASK_PRIO_MAX`
## `AO_TASK_PRIO_MIN`

```c
#define AO_TASK_PRIO_MAX (AO_UINT_BITS - 1)
#define AO_TASK_PRIO_MIN (0)
```

The maximum and minimum task priority.

## `AO_TASK_SUBMISSION`

```c
#define AO_TASK_SUBMISSION  \
(                           \
    AO_TASK_CEILING ||      \
    AO_TASK_INHERITANCE     \
)
```

Indicates whether task submission is supported.

# Types

## `ao_task_sched_t`

```c
typedef struct ao_task_sched_t ao_task_sched_t;
```

```c
struct ao_task_sched_t
{
    ao_list_node_t node;

#if AO_TASK_INHERITANCE

    ao_list_t      masters;

#endif

    ao_uint_t      prio;

#if AO_TASK_SUBMISSION

    ao_uint_t      prio_backup;
    ao_rb_t        slaves;

#endif

};
```

This type represents scheduler-related data of a task. It consists of the following members.

| `masters` | The list of masters that the task currently embodies. |
| `node` | The node for the scheduler's lists of ready tasks. |
| `prio` | The priority. |
| `prio_backup` | The priority backup. |
| `slaves` | The priority queue of slaves that the task currently embodies. |

## `ao_task_ceiling_t`

```c
typedef struct ao_task_ceiling_t ao_task_ceiling_t;
```

```c
struct ao_task_ceiling_t
{
    ao_uint_t         prio;
    ao_task_slave_t * slave;
    ao_rb_node_t      slave_ceilings_node;
};
```

This type represents a task ceiling. It consists of the following members.

| `prio` | The priority. |
| `slave` | The slave that is currently submissive to this ceiling. |
| `slave_ceilings_node` | The node for the slave's priority queue of ceilings. |

## `ao_task_master_t`

```c
typedef struct ao_task_master_t ao_task_master_t;
```

```c
struct ao_task_master_t
{
    ao_uint_t         prio;
    ao_task_slave_t * slave;
    ao_rb_node_t      slave_masters_node;
    ao_task_t       * task;
    ao_list_node_t    task_masters_node;
};
```

This type represents a task master. It consists of the following members.

| `prio` | The priority. |
| `slave` | The slave that is currently submissive to this master. |
| `slave_masters_node` | The node for the slave's priority queue of masters. |
| `task` | The task that currently embodies this master. |
| `task_masters_node` | The node for the task's list of masters. |

## `ao_task_slave_t`

```c
typedef struct ao_task_slave_t ao_task_slave_t;
```

```c
struct ao_task_slave_t
{

#if AO_TASK_CEILING

    ao_rb_t      ceilings;

#endif

#if AO_TASK_INHERITANCE

    ao_rb_t      masters;

#endif

    ao_uint_t    prio_keep;
    ao_task_t *  task;
    ao_rb_node_t task_slaves_node;
};
```

This type represents a task slave. It consists of the following members.

| `ceilings` | The priority queue of ceilings that this slave is currently submissive to. |
| `masters` | The priority queue of masters that this slave is currently submissive to. |
| `prio_keep` | The priority to keep. |
| `task` | The task that currently embodies this slave. |
| `task_slaves_node` | The node for the task's priority queue of slaves. |

# Functions

## `ao_task_ceiling_get_prio`
## `ao_task_ceiling_set_prio`

```c
ao_uint_t ao_task_ceiling_get_prio(ao_task_ceiling_t const * c);
void      ao_task_ceiling_set_prio(ao_task_ceiling_t       * c, ao_uint_t x);
```

Gets or sets, respectively, the priority of a task ceiling.

## `ao_task_get_prio`
## `ao_task_set_prio`

```c
ao_uint_t ao_task_get_prio(ao_task_t const * t);
void      ao_task_set_prio(ao_task_t       * t, ao_uint_t x);
```

Gets or sets, respectively, the priority of a task.

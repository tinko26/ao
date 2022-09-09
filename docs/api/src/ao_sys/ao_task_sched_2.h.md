---
author: "Stefan Wagner"
date: 2022-08-31
draft: true
permalink: /api/src/ao_sys/ao_task_sched_2.h/
toc: true
---

# Include

```c
#include <ao_list.h>
#include <ao_rb.h>
#include <ao_time.h>
#include <ao_uint.h>
#include <stdbool.h>
```

# Identifiers

## `AO_TASK_SCHED_2`

```c
#define AO_TASK_SCHED_2
```

# Configuration

## `AO_TASK_CEILING`

Support task ceiling.

```c
#define AO_TASK_CEILING (true)
```

## `AO_TASK_INHERITANCE`

Support task inheritance.

```c
#define AO_TASK_INHERITANCE (true)
```

## `AO_TASK_QUANTUM`

The quantum or time slice.

```c
#define AO_TASK_QUANTUM (AO_MILLISECONDS(10))
```

# Constants

## `AO_TASK_PRIO_MAX`
## `AO_TASK_PRIO_MIN`

The maximum and minimum task priority.

```c
#define AO_TASK_PRIO_MAX (AO_UINT_BITS - 1)
#define AO_TASK_PRIO_MIN (0)
```

## `AO_TASK_SUBMISSION`

Indicates whether task submission is supported.

```c
#define AO_TASK_SUBMISSION  \
(                           \
    AO_TASK_CEILING ||      \
    AO_TASK_INHERITANCE     \
)
```

# Typedefs

```c
typedef struct ao_task_t         ao_task_t;
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

It consists of the following members.

| `masters` | |
| `node` | |
| `prio` | |
| `prio_backup` | |
| `slaves` | |

## `ao_task_ceiling_t`

```c
struct ao_task_ceiling_t
{
    ao_uint_t         prio;
    ao_task_slave_t * slave;
    ao_rb_node_t      slave_ceilings_node;
};
```

It consists of the following members.

| `prio` | |
| `slave` | |
| `slave_ceilings_node` | |

## `ao_task_master_t`

```c
struct ao_task_master_t
{
    ao_uint_t         prio;
    ao_task_slave_t * slave;
    ao_rb_node_t      slave_masters_node;
    ao_task_t *       task;
    ao_list_node_t    task_masters_node;
};
```

It consists of the following members.

| `prio` | |
| `slave` | |
| `slave_masters_node` | |
| `task` | |
| `task_masters_node` | |

## `ao_task_slave_t`

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

It consists of the following members.

| `ceilings` | |
| `masters` | |
| `prio_keep` | |
| `task` | |
| `task_slaves_node` | |

# Functions

## `ao_task_ceiling_get_prio`

```c
ao_uint_t ao_task_ceiling_get_prio(ao_task_ceiling_t const * c);
```

## `ao_task_ceiling_set_prio`

```c
void ao_task_ceiling_set_prio(ao_task_ceiling_t * c, ao_uint_t x);
```

## `ao_task_get_prio`

```c
ao_uint_t ao_task_get_prio(ao_task_t const * t);
```

## `ao_task_set_prio`

```c
void ao_task_set_prio(ao_task_t * t, ao_uint_t x);
```

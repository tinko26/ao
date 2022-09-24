---
author: "Stefan Wagner"
date: 2022-09-13
draft: true
permalink: /api/src/ao_sys/ao_task_sched_0.h/
toc: true
---

# Include

`stdbool.h`

# Identifier

```c
#define AO_TASK_SCHED_0
```

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

```c
struct ao_task_sched_t { };
```

This type represents scheduler-related data of a task.

## `ao_task_ceiling_t`

```c
typedef struct ao_task_ceiling_t ao_task_ceiling_t;
```

```c
struct ao_task_ceiling_t { };
```

This type represents a task ceiling.

## `ao_task_master_t`

```c
typedef struct ao_task_master_t ao_task_master_t;
```

```c
struct ao_task_master_t { };
```

This type represents a task master.

## `ao_task_slave_t`

```c
typedef struct ao_task_slave_t ao_task_slave_t;
```

```c
struct ao_task_slave_t { };
```

This type represents a task slave.

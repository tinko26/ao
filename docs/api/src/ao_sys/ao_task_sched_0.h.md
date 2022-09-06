---
author: "Stefan Wagner"
date: 2022-08-31
draft: true
permalink: /api/src/ao_sys/ao_task_sched_0.h/
toc: true
---

# Include

```c
#include <stdbool.h>
```

# Typedefs

```c
typedef struct ao_task_sched_t   ao_task_sched_t;
```

```c
typedef struct ao_task_ceiling_t ao_task_ceiling_t;
```

```c
typedef struct ao_task_master_t  ao_task_master_t;
```

```c
typedef struct ao_task_slave_t   ao_task_slave_t;
```

# Constants

```c
#define AO_TASK_CEILING     (false)
```

```c
#define AO_TASK_INHERITANCE (false)
```

```c
#define AO_TASK_SUBMISSION  (false)
```

# Types

## `ao_task_sched_t`

```c
struct ao_task_sched_t { };
```

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

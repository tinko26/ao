---
author: "Stefan Wagner"
date: 2022-08-29
draft: true
permalink: /api/src/ao_sys_xc32_pic32mx/ao_task_context.h/
toc: true
---

# Include

```c
#include <stdint.h>
#include <xc.h>
```

# Types

## `ao_task_context_t`

```c
typedef struct ao_task_context_t ao_task_context_t;
```

```c
struct ao_task_context_t
{
    ao_task_context_data_t * ptr;
};
```

It consists of the following members.

| `ptr` | |

## `ao_task_context_data_t`

```c
typedef struct ao_task_context_data_t ao_task_context_data_t;
```

```c
struct ao_task_context_data_t
{
    uint32_t a0;
    uint32_t a1;
    uint32_t a2;
    uint32_t a3;
    uint32_t at;
    uint32_t epc;
    uint32_t hi;
    uint32_t lo;
    uint32_t ra;
    uint32_t s0;
    uint32_t s1;
    uint32_t s2;
    uint32_t s3;
    uint32_t s4;
    uint32_t s5;
    uint32_t s6;
    uint32_t s7;
    uint32_t s8;
    uint32_t status;
    uint32_t t0;
    uint32_t t1;
    uint32_t t2;
    uint32_t t3;
    uint32_t t4;
    uint32_t t5;
    uint32_t t6;
    uint32_t t7;
    uint32_t t8;
    uint32_t t9;
    uint32_t v0;
    uint32_t v1;
    uint32_t pad1;
};
```

It consists of the following members.

| `a0` | |
| `a1` | |
| `a2` | |
| `a3` | |
| `at` | |
| `epc` | |
| `hi` | |
| `lo` | |
| `pad1` | |
| `ra` | |
| `s0` | |
| `s1` | |
| `s2` | |
| `s3` | |
| `s4` | |
| `s5` | |
| `s6` | |
| `s7` | |
| `s8` | |
| `status` | |
| `t0` | |
| `t1` | |
| `t2` | |
| `t3` | |
| `t4` | |
| `t5` | |
| `t6` | |
| `t7` | |
| `t8` | |
| `t9` | |
| `v0` | |
| `v1` | |

# Functions

## `ao_task_start_context`

```c
void ao_task_start_context(ao_task_t * t);
```

## `ao_task_stop_context`

```c
#define ao_task_stop_context(t)
```

---
author: "Stefan Wagner"
date: 2022-09-20
draft: true
permalink: /api/src/ao_sys_xc32_pic32mx/ao_task_context.h/
toc: true
---

# Include

`stdint.h` <br/>
`xc.h`

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

This type represents the task context. It consists of the following members.

| `ptr` | The pointer to the task context data, that is stored on the task stack. |

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

This type represents the task context data that is stored on the task stack. It consists of the following members.

| `a0` | A0. |
| `a1` | A1. |
| `a2` | A2. |
| `a3` | A3. |
| `at` | AT. |
| `epc` | EPC. |
| `hi` | HI. |
| `lo` | LO. |
| `ra` | RA. |
| `s0` | S0. |
| `s1` | S1. |
| `s2` | S2. |
| `s3` | S3. |
| `s4` | S4. |
| `s5` | S5. |
| `s6` | S6. |
| `s7` | S7. |
| `s8` | S8. |
| `status` | Status. |
| `t0` | T0. |
| `t1` | T1. |
| `t2` | T2. |
| `t3` | T3. |
| `t4` | T4. |
| `t5` | T5. |
| `t6` | T6. |
| `t7` | T7. |
| `t8` | T8. |
| `t9` | T9. |
| `v0` | V0. |
| `v1` | V1. |
| `pad1` | Padding. |

# Functions

## `ao_task_start_context`

```c
void ao_task_start_context(ao_task_t * t);
```

Starts a task. This function is called by the kernel when a task is being started in order to prepare its context.

## `ao_task_stop_context`

```c
#define ao_task_stop_context(t)
```

Stops a task. This function is called by the kernel when a task is being stopped in order to clean up its context.

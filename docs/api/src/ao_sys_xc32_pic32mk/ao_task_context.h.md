---
author: "Stefan Wagner"
date: 2022-08-29
draft: true
permalink: /api/src/ao_sys_xc32_pic32mk/ao_task_context.h/
toc: true
---

# Include

```c
#include <stdint.h>
```

# Typedefs

```c
typedef struct ao_task_t              ao_task_t;
typedef struct ao_task_context_t      ao_task_context_t;
typedef struct ao_task_context_data_t ao_task_context_data_t;
```

# Types

## `ao_task_context_t`

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
struct ao_task_context_data_t
{
    uint32_t a0;
    uint32_t a1;
    uint32_t a2;
    uint32_t a3;
    uint32_t at;
    uint32_t ra;
    uint32_t s4;
    uint32_t s5;
    uint32_t s6;
    uint32_t s7;
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
    uint32_t hi;
    uint32_t lo;
    uint32_t hi1;
    uint32_t lo1;
    uint32_t hi2;
    uint32_t lo2;
    uint32_t hi3;
    uint32_t lo3;
    uint32_t dsp_control;
    uint32_t fcsr;
    uint64_t f0;
    uint64_t f1;
    uint64_t f2;
    uint64_t f3;
    uint64_t f4;
    uint64_t f5;
    uint64_t f6;
    uint64_t f7;
    uint64_t f8;
    uint64_t f9;
    uint64_t f10;
    uint64_t f11;
    uint64_t f12;
    uint64_t f13;
    uint64_t f14;
    uint64_t f15;
    uint64_t f16;
    uint64_t f17;
    uint64_t f18;
    uint64_t f19;
    uint64_t f20;
    uint64_t f21;
    uint64_t f22;
    uint64_t f23;
    uint64_t f24;
    uint64_t f25;
    uint64_t f26;
    uint64_t f27;
    uint64_t f28;
    uint64_t f29;
    uint64_t f30;
    uint64_t f31;
    uint32_t epc;
    uint32_t status;
    uint32_t s0;
    uint32_t s1;
    uint32_t s2;
    uint32_t s3;
    uint32_t s8;
    uint32_t padding;
};
```

It consists of the following members.

| `a0` | |
| `a1` | |
| `a2` | |
| `a3` | |
| `at` | |
| `dsp_control` | |
| `epc` | |
| `f0` | |
| `f1` | |
| `f10` | |
| `f11` | |
| `f12` | |
| `f13` | |
| `f14` | |
| `f15` | |
| `f16` | |
| `f17` | |
| `f18` | |
| `f19` | |
| `f2` | |
| `f20` | |
| `f21` | |
| `f22` | |
| `f23` | |
| `f24` | |
| `f25` | |
| `f26` | |
| `f27` | |
| `f28` | |
| `f29` | |
| `f3` | |
| `f30` | |
| `f31` | |
| `f4` | |
| `f5` | |
| `f6` | |
| `f7` | |
| `f8` | |
| `f9` | |
| `fcsr` | |
| `hi` | |
| `hi1` | |
| `hi2` | |
| `hi3` | |
| `lo` | |
| `lo1` | |
| `lo2` | |
| `lo3` | |
| `padding` | |
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

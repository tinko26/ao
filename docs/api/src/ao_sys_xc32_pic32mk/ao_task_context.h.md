---
author: "Stefan Wagner"
date: 2022-09-20
draft: true
permalink: /api/src/ao_sys_xc32_pic32mk/ao_task_context.h/
toc: true
---

# Include

| `stdint.h` |

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

This type represents the task context data that is stored on the task stack. It consists of the following members.

| `a0` | A0. |
| `a1` | A1. |
| `a2` | A2. |
| `a3` | A3. |
| `at` | AT. |
| `ra` | RA. |
| `s4` | S4. |
| `s5` | S5. |
| `s6` | S6. |
| `s7` | S7. |
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
| `hi` | HI. |
| `lo` | LO. |
| `hi1` | HI1. |
| `lo1` | LO1. |
| `hi2` | HI2. |
| `lo2` | LO2. |
| `hi3` | HI3. |
| `lo3` | LO3. |
| `dsp_control` | DSPControl. |
| `fcsr` | FCSR. |
| `f0` | F0. |
| `f1` | F1. |
| `f2` | F2. |
| `f3` | F3. |
| `f4` | F4. |
| `f5` | F5. |
| `f6` | F6. |
| `f7` | F7. |
| `f8` | F8. |
| `f9` | F9. |
| `f10` | F10. |
| `f11` | F11. |
| `f12` | F12. |
| `f13` | F13. |
| `f14` | F14. |
| `f15` | F15. |
| `f16` | F16. |
| `f17` | F17. |
| `f18` | F18. |
| `f19` | F19. |
| `f20` | F20. |
| `f21` | F21. |
| `f22` | F22. |
| `f23` | F23. |
| `f24` | F24. |
| `f25` | F25. |
| `f26` | F26. |
| `f27` | F27. |
| `f28` | F28. |
| `f29` | F29. |
| `f30` | F30. |
| `f31` | F31. |
| `epc` | EPC. |
| `status` | Status. |
| `s0` | S0. |
| `s1` | S1. |
| `s2` | S2. |
| `s3` | S3. |
| `s8` | S8. |
| `padding` | Padding. |

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

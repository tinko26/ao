---
author: "Stefan Wagner"
date: 2022-09-25
draft: true
permalink: /api/demos/ao_mikroe_2340/ao_mikroe_2935.h/
toc: true
---

# Include

| [`ao_task.h`](../../src/ao_sys_xc32_pic32mz/ao_task.h.md) |
| [`ao_time.h`](../../src/ao_sys/ao_time.h.md) |
| `stdbool.h` |

# Configuration

## `AO_MIKROE_2935_*`

```c
#define AO_MIKROE_2935_A (false)
#define AO_MIKROE_2935_B (false)
#define AO_MIKROE_2935_C (false)
#define AO_MIKROE_2935_D (false)
```

## `AO_MIKROE_2935_BAUD_*`

```c
#define AO_MIKROE_2935_BAUD_A (10000000UL)
#define AO_MIKROE_2935_BAUD_B (10000000UL)
#define AO_MIKROE_2935_BAUD_C (10000000UL)
#define AO_MIKROE_2935_BAUD_D (10000000UL)
```

## `AO_MIKROE_2935_PERIOD_*`

```c
#define AO_MIKROE_2935_PERIOD_A (AO_MILLISECONDS(100))
#define AO_MIKROE_2935_PERIOD_B (AO_MILLISECONDS(100))
#define AO_MIKROE_2935_PERIOD_C (AO_MILLISECONDS(100))
#define AO_MIKROE_2935_PERIOD_D (AO_MILLISECONDS(100))
```

## `AO_MIKROE_2935_REPETITIONS_XY_*`

```c
#define AO_MIKROE_2935_REPETITIONS_XY_A (9)
#define AO_MIKROE_2935_REPETITIONS_XY_B (9)
#define AO_MIKROE_2935_REPETITIONS_XY_C (9)
#define AO_MIKROE_2935_REPETITIONS_XY_D (9)
```

## `AO_MIKROE_2935_REPETITIONS_Z_*`

```c
#define AO_MIKROE_2935_REPETITIONS_Z_A (15)
#define AO_MIKROE_2935_REPETITIONS_Z_B (15)
#define AO_MIKROE_2935_REPETITIONS_Z_C (15)
#define AO_MIKROE_2935_REPETITIONS_Z_D (15)
```

# Constants

## `AO_MIKROE_2935`

```c
#define AO_MIKROE_2935  \
(                       \
    AO_MIKROE_2935_A || \
    AO_MIKROE_2935_B || \
    AO_MIKROE_2935_C || \
    AO_MIKROE_2935_D    \
)
```

Indicates whether the clickboard is used.

# Variables

## `ao_mikroe_2935_task_*`

```c
extern ao_task_t ao_mikroe_2935_task_a;
extern ao_task_t ao_mikroe_2935_task_b;
extern ao_task_t ao_mikroe_2935_task_c;
extern ao_task_t ao_mikroe_2935_task_d;
```

# Include Next

| [`ao_mikroe_2935.h`](../ao_mikroe/ao_mikroe_2935.h.md) |

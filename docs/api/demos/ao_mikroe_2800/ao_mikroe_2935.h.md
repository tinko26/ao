---
author: "Stefan Wagner"
date: 2022-09-25
draft: true
permalink: /api/demos/ao_mikroe_2800/ao_mikroe_2935.h/
toc: true
---

# Include

| [`ao_task.h`](../../src/ao_sys_xc32_pic32mz/ao_task.h.md) |
| [`ao_time.h`](../../src/ao_sys/ao_time.h.md) |
| `stdbool.h` |

# Configuration

## `AO_MIKROE_2935_*`

```c
#define AO_MIKROE_2935_1 (false)
#define AO_MIKROE_2935_2 (false)
```

## `AO_MIKROE_2935_BAUD_*`

```c
#define AO_MIKROE_2935_BAUD_1 (10000000UL)
#define AO_MIKROE_2935_BAUD_2 (10000000UL)
```

## `AO_MIKROE_2935_PERIOD_*`

```c
#define AO_MIKROE_2935_PERIOD_1 (AO_MILLISECONDS(100))
#define AO_MIKROE_2935_PERIOD_2 (AO_MILLISECONDS(100))
```

## `AO_MIKROE_2935_REPETITIONS_XY_*`

```c
#define AO_MIKROE_2935_REPETITIONS_XY_1 (9)
#define AO_MIKROE_2935_REPETITIONS_XY_2 (9)
```

## `AO_MIKROE_2935_REPETITIONS_Z_*`

```c
#define AO_MIKROE_2935_REPETITIONS_Z_1 (15)
#define AO_MIKROE_2935_REPETITIONS_Z_2 (15)
```

# Constants

## `AO_MIKROE_2935`

```c
#define AO_MIKROE_2935  \
(                       \
    AO_MIKROE_2935_1 || \
    AO_MIKROE_2935_2    \
)
```

Indicates whether the clickboard is used.

# Variables

## `ao_mikroe_2935_task_*`

```c
extern ao_task_t ao_mikroe_2935_task_1;
extern ao_task_t ao_mikroe_2935_task_2;
```

# Include Next

| [`ao_mikroe_2935.h`](../ao_mikroe/ao_mikroe_2935.h.md) |

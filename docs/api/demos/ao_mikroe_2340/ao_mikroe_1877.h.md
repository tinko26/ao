---
author: "Stefan Wagner"
date: 2022-09-22
draft: true
permalink: /api/demos/ao_mikroe_2340/ao_mikroe_1877.h/
toc: true
---

# Include

[`ao_task.h`](../../src/ao_sys_xc32_pic32mz/ao_task.h.md) <br/>
[`ao_time.h`](../../src/ao_sys/ao_time.h.md) <br/>
`stdbool.h`

# Configuration

## `AO_MIKROE_1877`

```c
#define AO_MIKROE_1877_A (false)
#define AO_MIKROE_1877_B (false)
#define AO_MIKROE_1877_C (false)
#define AO_MIKROE_1877_D (false)
```

## `AO_MIKROE_1877_BAUD`

```c
#define AO_MIKROE_1877_BAUD_A (400000UL)
#define AO_MIKROE_1877_BAUD_B (400000UL)
#define AO_MIKROE_1877_BAUD_C (400000UL)
#define AO_MIKROE_1877_BAUD_D (400000UL)
```

## `AO_MIKROE_1877_TIMEOUT`

```c
#define AO_MIKROE_1877_TIMEOUT_A (AO_MILLISECONDS(100))
#define AO_MIKROE_1877_TIMEOUT_B (AO_MILLISECONDS(100))
#define AO_MIKROE_1877_TIMEOUT_C (AO_MILLISECONDS(100))
#define AO_MIKROE_1877_TIMEOUT_D (AO_MILLISECONDS(100))
```

# Constants

```c
#define AO_MIKROE_1877  \
(                       \
    AO_MIKROE_1877_A || \
    AO_MIKROE_1877_B || \
    AO_MIKROE_1877_C || \
    AO_MIKROE_1877_D    \
)
```

Indicates whether the clickboard is used.

# Variables

## `ao_mikroe_1877_task`

```c
extern ao_task_t ao_mikroe_1877_task_a;
extern ao_task_t ao_mikroe_1877_task_b;
extern ao_task_t ao_mikroe_1877_task_c;
extern ao_task_t ao_mikroe_1877_task_d;
```

# Include Next

[`ao_mikroe_1877.h`](../ao_mikroe/ao_mikroe_1877.h.md)

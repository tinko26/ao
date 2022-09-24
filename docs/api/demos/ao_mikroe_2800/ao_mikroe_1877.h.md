---
author: "Stefan Wagner"
date: 2022-09-22
draft: true
permalink: /api/demos/ao_mikroe_2800/ao_mikroe_1877.h/
toc: true
---

# Include

| [`ao_task.h`](../../src/ao_sys_xc32_pic32mz/ao_task.h.md) |
| [`ao_time.h`](../../src/ao_sys/ao_time.h.md) |
| `stdbool.h` |

# Configuration

## `AO_MIKROE_1877`

```c
#define AO_MIKROE_1877_1 (false)
#define AO_MIKROE_1877_2 (false)
```

## `AO_MIKROE_1877_BAUD`

```c
#define AO_MIKROE_1877_BAUD_1 (400000UL)
#define AO_MIKROE_1877_BAUD_2 (400000UL)
```

## `AO_MIKROE_1877_TIMEOUT`

```c
#define AO_MIKROE_1877_TIMEOUT_1 (AO_MILLISECONDS(100))
#define AO_MIKROE_1877_TIMEOUT_2 (AO_MILLISECONDS(100))
```

# Constants

```c
#define AO_MIKROE_1877  \
(                       \
    AO_MIKROE_1877_1 || \
    AO_MIKROE_1877_2    \
)
```

Indicates whether the clickboard is used.

# Variables

## `ao_mikroe_1877_task`

```c
extern ao_task_t ao_mikroe_1877_task_1;
extern ao_task_t ao_mikroe_1877_task_2;
```

# Include Next

| [`ao_mikroe_1877.h`](../ao_mikroe/ao_mikroe_1877.h.md) |

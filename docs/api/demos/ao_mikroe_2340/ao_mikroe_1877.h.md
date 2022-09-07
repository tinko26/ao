---
author: "Stefan Wagner"
date: 2022-08-30
draft: true
permalink: /api/demos/ao_mikroe_2340/ao_mikroe_1877.h/
toc: true
---

# Include

```c
#include <ao_task.h>
#include <ao_time.h>
#include <stdbool.h>
```

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

# Variables

```c
extern ao_task_t ao_mikroe_1877_task_a;
extern ao_task_t ao_mikroe_1877_task_b;
extern ao_task_t ao_mikroe_1877_task_c;
extern ao_task_t ao_mikroe_1877_task_d;
```

# Include Next

```c
#include_next <ao_mikroe_1877.h>
```

---
author: "Stefan Wagner"
date: 2022-08-30
draft: true
permalink: /api/demos/ao_mikroe_2800/ao_mikroe_2935.h/
toc: true
---

# Include

```c
#include <ao_task.h>
#include <ao_time.h>
#include <stdbool.h>
```

# Configuration

## `AO_MIKROE_2935`

```c
#define AO_MIKROE_2935_1 (false)
#define AO_MIKROE_2935_2 (false)
```

## `AO_MIKROE_2935_BAUD`

```c
#define AO_MIKROE_2935_BAUD_1 (10000000UL)
#define AO_MIKROE_2935_BAUD_2 (10000000UL)
```

## `AO_MIKROE_2935_PERIOD`

```c
#define AO_MIKROE_2935_PERIOD_1 (AO_MILLISECONDS(100))
#define AO_MIKROE_2935_PERIOD_2 (AO_MILLISECONDS(100))
```

## `AO_MIKROE_2935_REPETITIONS_XY`

```c
#define AO_MIKROE_2935_REPETITIONS_XY_1 (9)
#define AO_MIKROE_2935_REPETITIONS_XY_2 (9)
```

## `AO_MIKROE_2935_REPETITIONS_Z`

```c
#define AO_MIKROE_2935_REPETITIONS_Z_1 (15)
#define AO_MIKROE_2935_REPETITIONS_Z_2 (15)
```

# Variables

## `ao_mikroe_2935_task`

```c
extern ao_task_t ao_mikroe_2935_task_1;
extern ao_task_t ao_mikroe_2935_task_2;
```

# Include Next

```c
#include_next <ao_mikroe_2935.h>
```

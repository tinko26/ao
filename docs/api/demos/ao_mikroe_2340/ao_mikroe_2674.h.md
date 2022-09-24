---
author: "Stefan Wagner"
date: 2022-09-22
draft: true
permalink: /api/demos/ao_mikroe_2340/ao_mikroe_2674.h/
toc: true
---

# Include

| `stdbool.h` |

# Configuration

## `AO_MIKROE_2674`

```c
#define AO_MIKROE_2674_A (false)
#define AO_MIKROE_2674_B (false)
#define AO_MIKROE_2674_C (false)
#define AO_MIKROE_2674_D (false)
```

# Constants

```c
#define AO_MIKROE_2674  \
(                       \
    AO_MIKROE_2674_A || \
    AO_MIKROE_2674_B || \
    AO_MIKROE_2674_C || \
    AO_MIKROE_2674_D    \
)
```

Indicates whether the clickboard is used.

# Include Next

| [`ao_mikroe_2674.h`](../ao_mikroe/ao_mikroe_2674.h.md) |

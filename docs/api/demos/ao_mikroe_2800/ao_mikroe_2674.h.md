---
author: "Stefan Wagner"
date: 2022-09-25
draft: true
permalink: /api/demos/ao_mikroe_2800/ao_mikroe_2674.h/
toc: true
---

# Include

| `stdbool.h` |

# Configuration

## `AO_MIKROE_2674_*`

```c
#define AO_MIKROE_2674_1 (false)
#define AO_MIKROE_2674_2 (false)
```

# Constants

## `AO_MIKROE_2674`

```c
#define AO_MIKROE_2674  \
(                       \
    AO_MIKROE_2674_1 || \
    AO_MIKROE_2674_2    \
)
```

Indicates whether the clickboard is used.

# Include Next

| [`ao_mikroe_2674.h`](../ao_mikroe/ao_mikroe_2674.h.md) |

---
author: "Stefan Wagner"
date: 2022-09-25
draft: true
permalink: /api/demos/ao_mikroe_2340/ao_mikroe_2334.h/
toc: true
---

# Include

| `stdbool.h` |

# Configuration

## `AO_MIKROE_2334_*`

```c
#define AO_MIKROE_2334_B (false)
#define AO_MIKROE_2334_D (false)
```

# Constants

## `AO_MIKROE_2334`

```c
#define AO_MIKROE_2334  \
(                       \
    AO_MIKROE_2334_B || \
    AO_MIKROE_2334_D    \
)
```

Indicates whether the clickboard is used.

# Include Next

| [`ao_mikroe_2334.h`](../ao_mikroe/ao_mikroe_2334.h.md) |

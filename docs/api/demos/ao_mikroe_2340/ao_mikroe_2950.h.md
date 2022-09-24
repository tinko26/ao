---
author: "Stefan Wagner"
date: 2022-09-22
draft: true
permalink: /api/demos/ao_mikroe_2340/ao_mikroe_2950.h/
toc: true
---

# Include

`stdbool.h`

# Configuration

## `AO_MIKROE_2950`

```c
#define AO_MIKROE_2950_A (false)
#define AO_MIKROE_2950_B (false)
#define AO_MIKROE_2950_C (false)
#define AO_MIKROE_2950_D (false)
```

## `AO_MIKROE_2950_BAUD`

```c
#define AO_MIKROE_2950_BAUD_A (400000UL)
#define AO_MIKROE_2950_BAUD_B (400000UL)
#define AO_MIKROE_2950_BAUD_C (400000UL)
#define AO_MIKROE_2950_BAUD_D (400000UL)
```

# Constants

```c
#define AO_MIKROE_2950  \
(                       \
    AO_MIKROE_2950_A || \
    AO_MIKROE_2950_B || \
    AO_MIKROE_2950_C || \
    AO_MIKROE_2950_D    \
)
```

Indicates whether the clickboard is used.

# Include Next

[`ao_mikroe_2950.h`](../ao_mikroe/ao_mikroe_2950.h.md)

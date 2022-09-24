---
author: "Stefan Wagner"
date: 2022-09-22
draft: true
permalink: /api/demos/ao_mikroe_2340/ao_mikroe_3063.h/
toc: true
---

# Include

`stdbool.h`

# Configuration

## `AO_MIKROE_3063`

```c
#define AO_MIKROE_3063_A (false)
#define AO_MIKROE_3063_B (false)
#define AO_MIKROE_3063_C (false)
#define AO_MIKROE_3063_D (false)
```

# Constants

```c
#define AO_MIKROE_3063  \
(                       \
    AO_MIKROE_3063_A || \
    AO_MIKROE_3063_B || \
    AO_MIKROE_3063_C || \
    AO_MIKROE_3063_D    \
)
```

Indicates whether the clickboard is used.

# Include Next

[`ao_mikroe_3063.h`](../ao_mikroe/ao_mikroe_3063.h.md)

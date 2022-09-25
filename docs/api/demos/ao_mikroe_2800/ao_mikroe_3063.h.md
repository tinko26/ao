---
author: "Stefan Wagner"
date: 2022-09-25
draft: true
permalink: /api/demos/ao_mikroe_2800/ao_mikroe_3063.h/
toc: true
---

# Include

| `stdbool.h` |

# Configuration

## `AO_MIKROE_3063_*`

```c
#define AO_MIKROE_3063_1 (false)
#define AO_MIKROE_3063_2 (false)
```

# Constants

## `AO_MIKROE_3063`

```c
#define AO_MIKROE_3063  \
(                       \
    AO_MIKROE_3063_1 || \
    AO_MIKROE_3063_2    \
)
```

Indicates whether the clickboard is used.

# Include Next

| [`ao_mikroe_3063.h`](../ao_mikroe/ao_mikroe_3063.h.md) |

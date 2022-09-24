---
author: "Stefan Wagner"
date: 2022-09-22
draft: true
permalink: /api/demos/ao_mikroe_2800/ao_mikroe_2950.h/
toc: true
---

# Include

| `stdbool.h` |

# Configuration

## `AO_MIKROE_2950`

```c
#define AO_MIKROE_2950_1 (false)
#define AO_MIKROE_2950_2 (false)
```

## `AO_MIKROE_2950_BAUD`

```c
#define AO_MIKROE_2950_BAUD_1 (400000UL)
#define AO_MIKROE_2950_BAUD_2 (400000UL)
```

# Constants

```c
#define AO_MIKROE_2950  \
(                       \
    AO_MIKROE_2950_1 || \
    AO_MIKROE_2950_2    \
)
```

Indicates whether the clickboard is used.

# Include Next

| [`ao_mikroe_2950.h`](../ao_mikroe/ao_mikroe_2950.h.md) |

---
author: "Stefan Wagner"
date: 2022-09-22
draft: true
permalink: /api/demos/ao_mikroe_2340/ao_mikroe_4186.h/
toc: true
---

# Include

| [`ao_time.h`](../../src/ao_sys/ao_time.h.md) |
| `stdbool.h` |

# Configuration

## `AO_MIKROE_4186`

```c
#define AO_MIKROE_4186_A (false)
#define AO_MIKROE_4186_B (false)
#define AO_MIKROE_4186_C (false)
#define AO_MIKROE_4186_D (false)
```

## `AO_MIKROE_4186_BAUD`

```c
#define AO_MIKROE_4186_BAUD_A (400000UL)
#define AO_MIKROE_4186_BAUD_B (400000UL)
#define AO_MIKROE_4186_BAUD_C (400000UL)
#define AO_MIKROE_4186_BAUD_D (400000UL)
```

## `AO_MIKROE_4186_TIMEOUT`

```c
#define AO_MIKROE_4186_TIMEOUT_A (AO_MILLISECONDS(100))
#define AO_MIKROE_4186_TIMEOUT_B (AO_MILLISECONDS(100))
#define AO_MIKROE_4186_TIMEOUT_C (AO_MILLISECONDS(100))
#define AO_MIKROE_4186_TIMEOUT_D (AO_MILLISECONDS(100))
```

# Constants

```c
#define AO_MIKROE_4186  \
(                       \
    AO_MIKROE_4186_A || \
    AO_MIKROE_4186_B || \
    AO_MIKROE_4186_C || \
    AO_MIKROE_4186_D    \
)
```

Indicates whether the clickboard is used.

# Include Next

| [`ao_mikroe_4186.h`](../ao_mikroe/ao_mikroe_4186.h.md) |

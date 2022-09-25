---
author: "Stefan Wagner"
date: 2022-09-25
draft: true
permalink: /api/demos/ao_mikroe_2800/ao_mikroe_4186.h/
toc: true
---

# Include

| [`ao_time.h`](../../src/ao_sys/ao_time.h.md) |
| `stdbool.h` |

# Configuration

## `AO_MIKROE_4186_*`

```c
#define AO_MIKROE_4186_1 (false)
#define AO_MIKROE_4186_2 (false)
```

## `AO_MIKROE_4186_BAUD_*`

```c
#define AO_MIKROE_4186_BAUD_1 (400000UL)
#define AO_MIKROE_4186_BAUD_2 (400000UL)
```

## `AO_MIKROE_4186_TIMEOUT_*`

```c
#define AO_MIKROE_4186_TIMEOUT_1 (AO_MILLISECONDS(100))
#define AO_MIKROE_4186_TIMEOUT_2 (AO_MILLISECONDS(100))
```

# Constants

## `AO_MIKROE_4186`

```c
#define AO_MIKROE_4186  \
(                       \
    AO_MIKROE_4186_1 || \
    AO_MIKROE_4186_2    \
)
```

Indicates whether the clickboard is used.

# Include Next

| [`ao_mikroe_4186.h`](../ao_mikroe/ao_mikroe_4186.h.md) |

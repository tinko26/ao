---
author: "Stefan Wagner"
date: 2022-09-22
draft: true
permalink: /api/demos/ao_mikroe_2800/ao_mikroe_2334.h/
toc: true
---

# Include

```c
#include <stdbool.h>
```

# Configuration

## `AO_MIKROE_2334`

```c
#define AO_MIKROE_2334_1 (false)
#define AO_MIKROE_2334_2 (false)
```

# Constants

```c
#define AO_MIKROE_2334  \
(                       \
    AO_MIKROE_2334_1 || \
    AO_MIKROE_2334_2    \
)
```

Indicates whether the clickboard is used.

# Include Next

```c
#include_next <ao_mikroe_2334.h>
```

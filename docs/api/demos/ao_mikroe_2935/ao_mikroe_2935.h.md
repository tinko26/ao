---
api: true
author: "Stefan Wagner"
date: 2022-08-30
description: "The /demos/ao_mikroe_2935/ao_mikroe_2935.h file of the ao real-time operating system."
draft: true
permalink: /api/demos/ao_mikroe_2935/ao_mikroe_2935.h/
subtitle: "GeoMagnetic Click"
title: "ao_mikroe_2935.h"
toc: true
---

# Include

```c
#include <ao_float.h>
#include <stdbool.h>
#include <stddef.h>
```

# Typedefs

```c
typedef struct ao_mikroe_2935_t ao_mikroe_2935_t;
```

# Types

## `ao_mikroe_2935_t`

```c
struct ao_mikroe_2935_t
{
    bool ready;
    ao_float_t x;
    ao_float_t y;
    ao_float_t z;
};
```

It consists of the following members.

| `ready` | |
| `x` | |
| `y` | |
| `z` | |

# Functions

```c
void ao_mikroe_2935( size_t i, ao_mikroe_2935_t const * x);
```

```c
void ao_mikroe_2935_start( size_t i);
```

```c
void ao_mikroe_2935_stop( size_t i);
```


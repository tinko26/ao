---
author: "Stefan Wagner"
date: 2022-08-30
draft: true
permalink: /api/demos/ao_mikroe_2935/ao_mikroe_2935.h/
toc: true
---

# Include

```c
#include <ao_float.h>
#include <stdbool.h>
#include <stddef.h>
```

# Identifiers

## `AO_MIKROE_2935`

```c
#define AO_MIKROE_2935
```

# Types

## `ao_mikroe_2935_t`

```c
typedef struct ao_mikroe_2935_t ao_mikroe_2935_t;
```

```c
struct ao_mikroe_2935_t
{
    bool       ready;
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

## `ao_mikroe_2935`

```c
void ao_mikroe_2935(size_t i, ao_mikroe_2935_t const * x);
```

## `ao_mikroe_2935_start`

```c
void ao_mikroe_2935_start(size_t i);
```

## `ao_mikroe_2935_stop`

```c
void ao_mikroe_2935_stop(size_t i);
```

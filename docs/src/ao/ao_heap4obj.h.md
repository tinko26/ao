---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The /src/ao/ao_heap4obj.h file of the ao real-time operating system."
draft: true
permalink: /src/ao/ao_heap4obj.h/
subtitle: ""
title: "ao_heap4obj.h"
toc: true
---

# Include

```c
#include <stdbool.h>
#include <stddef.h>
```

# Typedefs

```c
typedef struct ao_heap4obj_t ao_heap4obj_t;
```

```c
typedef bool (* ao_heap4obj_less_t)
(
void * p1,
void * p2,
void * parameter
);
```

# Constants

```c
#define AO_HEAP4OBJ_COUNT_MAX (false)
```

# Types

## `ao_heap4obj_t`

```c
struct ao_heap4obj_t
{
    size_t capacity;
    size_t count;
#if AO_HEAP4OBJ_COUNT_MAX
    size_t count_max;
#endif
    size_t * heap1;
    size_t * heap2;
    ao_heap4obj_less_t less;
    void * less_parameter;
    size_t size;
    void * store;
};
```

Members:

| `capacity` | |
| `count` | |
| `count_max` | |
| `heap1` | |
| `heap2` | |
| `less` | |
| `less_parameter` | |
| `size` | |
| `store` | |

# Functions

```c
#define ao_heap4obj_is_empty(x)
```

```c
#define ao_heap4obj_is_full(x)
```

```c
void ao_heap4obj_assert( ao_heap4obj_t * x);
```

```c
bool ao_heap4obj_insert( ao_heap4obj_t * x, void const * p);
```

```c
bool ao_heap4obj_peek( ao_heap4obj_t const * x, void * p);
```

```c
bool ao_heap4obj_pop( ao_heap4obj_t * x, void * p);
```


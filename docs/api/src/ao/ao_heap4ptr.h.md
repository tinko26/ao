---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The /src/ao/ao_heap4ptr.h file of the ao real-time operating system."
draft: true
permalink: /api/src/ao/ao_heap4ptr.h/
subtitle: ""
title: "ao_heap4ptr.h"
toc: true
---

# Include

```c
#include <stdbool.h>
#include <stddef.h>
```

# Typedefs

```c
typedef struct ao_heap4ptr_t ao_heap4ptr_t;
```

```c
typedef bool (* ao_heap4ptr_less_t)
(
void * p1,
void * p2,
void * parameter
);
```

# Constants

```c
#define AO_HEAP4PTR_COUNT_MAX (false)
```

# Types

## `ao_heap4ptr_t`

```c
struct ao_heap4ptr_t
{
    size_t capacity;
    size_t count;
#if AO_HEAP4PTR_COUNT_MAX
    size_t count_max;
#endif
    size_t * heap1;
    size_t * heap2;
    ao_heap4ptr_less_t less;
    void * less_parameter;
    void ** store;
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
| `store` | |

# Functions

```c
#define ao_heap4ptr_is_empty(x)
```

```c
#define ao_heap4ptr_is_full(x)
```

```c
void ao_heap4ptr_assert( ao_heap4ptr_t * x);
```

```c
bool ao_heap4ptr_insert( ao_heap4ptr_t * x, void * p);
```

```c
bool ao_heap4ptr_peek( ao_heap4ptr_t const * x, void ** p);
```

```c
bool ao_heap4ptr_pop( ao_heap4ptr_t * x, void ** p);
```


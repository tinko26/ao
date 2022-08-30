---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The /src/ao/ao_buffer.h file of the ao real-time operating system."
draft: true
permalink: /api/src/ao/ao_buffer.h/
subtitle: ""
title: "ao_buffer.h"
toc: true
---

# Include

```c
#include <stdbool.h>
#include <stddef.h>
```

# Typedefs

```c
typedef struct ao_buffer_t ao_buffer_t;
```

# Constants

```c
#define AO_BUFFER_COUNT_MAX (false)
```

# Types

## `ao_buffer_t`

```c
struct ao_buffer_t
{
    size_t capacity;
    size_t count;
#if AO_BUFFER_COUNT_MAX
    size_t count_max;
#endif
    size_t front;
    void * store;
};
```

Members:

| `capacity` | |
| `count` | |
| `count_max` | |
| `front` | |
| `store` | |

# Functions

```c
#define ao_buffer_is_empty(x)
```

```c
#define ao_buffer_is_full(x)
```

```c
bool ao_buffer_peek_back( ao_buffer_t const * x, void * p);
```

```c
bool ao_buffer_peek_front( ao_buffer_t const * x, void * p);
```

```c
size_t ao_buffer_peek_range_back( ao_buffer_t const * x, void * p, size_t n_min, size_t n_max);
```

```c
size_t ao_buffer_peek_range_front( ao_buffer_t const * x, void * p, size_t n_min, size_t n_max);
```

```c
bool ao_buffer_pop_back( ao_buffer_t * x, void * p);
```

```c
bool ao_buffer_pop_front( ao_buffer_t * x, void * p);
```

```c
size_t ao_buffer_pop_range_back( ao_buffer_t * x, void * p, size_t n_min, size_t n_max);
```

```c
size_t ao_buffer_pop_range_front( ao_buffer_t * x, void * p, size_t n_min, size_t n_max);
```

```c
bool ao_buffer_push_back( ao_buffer_t * x, void const * p);
```

```c
bool ao_buffer_push_back_override( ao_buffer_t * x, void const * p);
```

```c
bool ao_buffer_push_front( ao_buffer_t * x, void const * p);
```

```c
bool ao_buffer_push_front_override( ao_buffer_t * x, void const * p);
```

```c
size_t ao_buffer_push_range_back( ao_buffer_t * x, void const * p, size_t n_min, size_t n_max);
```

```c
size_t ao_buffer_push_range_back_override( ao_buffer_t * x, void const * p, size_t n_min, size_t n_max);
```

```c
size_t ao_buffer_push_range_front( ao_buffer_t * x, void const * p, size_t n_min, size_t n_max);
```

```c
size_t ao_buffer_push_range_front_override(ao_buffer_t * x, void const * p, size_t n_min, size_t n_max);
```

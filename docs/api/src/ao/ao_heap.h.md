---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The /src/ao/ao_heap.h file of the ao real-time operating system."
draft: true
permalink: /api/src/ao/ao_heap.h/
subtitle: ""
title: "ao_heap.h"
toc: true
---

# Include

```c
#include <ao_uint.h>
#include <stdbool.h>
#include <stddef.h>
```

# Typedefs

```c
typedef struct ao_heap_t ao_heap_t;
```

```c
typedef struct ao_heap_node_t ao_heap_node_t;
```

```c
typedef bool (* ao_heap_less_t)
(
ao_heap_node_t * n1,
ao_heap_node_t * n2,
void * parameter
);
```

# Constants

```c
#define AO_HEAP_COUNT_MAX (false)
```

# Types

## `ao_heap_t`

```c
struct ao_heap_t
{
    ao_uint_t count;
#if AO_HEAP_COUNT_MAX
    ao_uint_t count_max;
#endif
    ao_heap_less_t less;
    void * less_parameter;
    ao_heap_node_t * root;
};
```

Members:

| `count` | |
| `count_max` | |
| `less` | |
| `less_parameter` | |
| `root` | |

## `ao_heap_node_t`

```c
struct ao_heap_node_t
{
    ao_heap_node_t * left;
    ao_heap_node_t * parent;
    ao_heap_node_t * right;
};
```

Members:

| `left` | |
| `parent` | |
| `right` | |

# Functions

```c
#define ao_heap_is_empty(x)
```

```c
#define ao_heap_peek(x)
```

```c
void ao_heap_assert( ao_heap_t * x);
```

```c
void ao_heap_insert( ao_heap_t * x, ao_heap_node_t * n);
```

```c
ao_heap_node_t * ao_heap_pop( ao_heap_t * x);
```

```c
void ao_heap_remove( ao_heap_t * x, ao_heap_node_t * n);
```


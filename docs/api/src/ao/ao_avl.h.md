---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The /src/ao/ao_avl.h file of the ao real-time operating system."
draft: true
permalink: /api/src/ao/ao_avl.h/
subtitle: ""
title: "ao_avl.h"
toc: true
---

# Include

```c
#include <ao_int.h>
#include <stdbool.h>
#include <stddef.h>
```

# Typedefs

```c
typedef struct ao_avl_t ao_avl_t;
```

```c
typedef struct ao_avl_node_t ao_avl_node_t;
```

```c
typedef bool (* ao_avl_less_t)
(
ao_avl_node_t * n1,
ao_avl_node_t * n2,
void * parameter
);
```

# Types

## `ao_avl_t`

```c
struct ao_avl_t
{
    ao_avl_less_t less;
    void * less_parameter;
    ao_avl_node_t * root;
};
```

Members:

| `less` | |
| `less_parameter` | |
| `root` | |

## `ao_avl_node_t`

```c
struct ao_avl_node_t
{
    ao_int_t height;
    ao_avl_node_t * left;
    ao_avl_node_t * parent;
    ao_avl_node_t * right;
};
```

Members:

| `height` | |
| `left` | |
| `parent` | |
| `right` | |

# Functions

```c
#define ao_avl_is_empty(x)
```

```c
void ao_avl_assert( ao_avl_t * x);
```

```c
void ao_avl_insert( ao_avl_t * x, ao_avl_node_t * n);
```

```c
ao_avl_node_t * ao_avl_max( ao_avl_t * x);
```

```c
ao_avl_node_t * ao_avl_min( ao_avl_t * x);
```

```c
void ao_avl_remove( ao_avl_t * x, ao_avl_node_t * n);
```


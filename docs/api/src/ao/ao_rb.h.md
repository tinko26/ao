---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The /src/ao/ao_rb.h file of the ao real-time operating system."
draft: true
permalink: /api/src/ao/ao_rb.h/
subtitle: ""
title: "ao_rb.h"
toc: true
---

# Include

```c
#include <stdbool.h>
#include <stddef.h>
```

# Typedefs

```c
typedef struct ao_rb_t ao_rb_t;
```

```c
typedef struct ao_rb_node_t ao_rb_node_t;
```

```c
typedef bool (* ao_rb_less_t)
(
ao_rb_node_t * n1,
ao_rb_node_t * n2,
void * parameter
);
```

# Types

## `ao_rb_t`

```c
struct ao_rb_t
{
    ao_rb_less_t less;
    void * less_parameter;
    ao_rb_node_t * root;
};
```

Members:

| `less` | |
| `less_parameter` | |
| `root` | |

## `ao_rb_node_t`

```c
struct ao_rb_node_t
{
    bool black;
    ao_rb_node_t * left;
    ao_rb_node_t * parent;
    ao_rb_node_t * right;
};
```

Members:

| `black` | |
| `left` | |
| `parent` | |
| `right` | |

# Functions

```c
#define ao_rb_is_empty(x)
```

```c
void ao_rb_assert( ao_rb_t * x);
```

```c
void ao_rb_insert( ao_rb_t * x, ao_rb_node_t * n);
```

```c
ao_rb_node_t * ao_rb_max( ao_rb_t * x);
```

```c
ao_rb_node_t * ao_rb_min( ao_rb_t * x);
```

```c
void ao_rb_remove( ao_rb_t * x, ao_rb_node_t * n);
```


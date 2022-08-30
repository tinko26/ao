---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The /src/ao/ao_slist.h file of the ao real-time operating system."
draft: true
permalink: /src/ao/ao_slist.h/
subtitle: ""
title: "ao_slist.h"
toc: true
---

# Include

```c
#include <stdbool.h>
#include <stddef.h>
```

# Typedefs

```c
typedef struct ao_slist_t ao_slist_t;
```

```c
typedef struct ao_slist_node_t ao_slist_node_t;
```

```c
typedef bool (* ao_slist_less_t)
(
ao_slist_node_t * n1,
ao_slist_node_t * n2,
void * parameter
);
```

# Types

## `ao_slist_t`

```c
struct ao_slist_t
{
    ao_slist_node_t * back;
    ao_slist_node_t * front;
    ao_slist_less_t less;
    void * less_parameter;
};
```

Members:

| `back` | |
| `front` | |
| `less` | |
| `less_parameter` | |

## `ao_slist_node_t`

```c
struct ao_slist_node_t
{
    ao_slist_node_t * next;
    ao_slist_node_t * prev;
};
```

Members:

| `next` | |
| `prev` | |

# Functions

```c
#define ao_slist_is_empty(x)
```

```c
void ao_slist_assert( ao_slist_t * x);
```

```c
void ao_slist_insert( ao_slist_t * x, ao_slist_node_t * n);
```

```c
ao_slist_node_t * ao_slist_pop_back( ao_slist_t * x);
```

```c
ao_slist_node_t * ao_slist_pop_front( ao_slist_t * x);
```

```c
void ao_slist_remove( ao_slist_t * x, ao_slist_node_t * n);
```

```c
void ao_slist_remove_all( ao_slist_t * x);
```

```c
void ao_slist_remove_back( ao_slist_t * x);
```

```c
void ao_slist_remove_front( ao_slist_t * x);
```

```c
void ao_slist_update( ao_slist_t * x, ao_slist_node_t * n);
```


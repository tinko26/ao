---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The /src/ao/ao_list.h file of the ao real-time operating system."
draft: true
permalink: /api/src/ao/ao_list.h/
subtitle: ""
title: "ao_list.h"
toc: true
---

# Include

```c
#include <stdbool.h>
#include <stddef.h>
```

# Typedefs

```c
typedef struct ao_list_t ao_list_t;
```

```c
typedef struct ao_list_node_t ao_list_node_t;
```

# Types

## `ao_list_t`

```c
struct ao_list_t
{
    ao_list_node_t * back;
    ao_list_node_t * front;
};
```

Members:

| `back` | |
| `front` | |

## `ao_list_node_t`

```c
struct ao_list_node_t
{
    ao_list_node_t * next;
    ao_list_node_t * prev;
};
```

Members:

| `next` | |
| `prev` | |

# Functions

```c
#define ao_list_is_empty(x)
```

```c
void ao_list_insert_after( ao_list_t * x, ao_list_node_t * n1, ao_list_node_t * n2);
```

```c
void ao_list_insert_before( ao_list_t * x, ao_list_node_t * n1, ao_list_node_t * n2);
```

```c
ao_list_node_t * ao_list_pop_back( ao_list_t * x);
```

```c
ao_list_node_t * ao_list_pop_front( ao_list_t * x);
```

```c
void ao_list_push_back( ao_list_t * x, ao_list_node_t * n);
```

```c
void ao_list_push_front( ao_list_t * x, ao_list_node_t * n);
```

```c
void ao_list_remove( ao_list_t * x, ao_list_node_t * n);
```

```c
void ao_list_remove_all( ao_list_t * x);
```

```c
void ao_list_remove_back( ao_list_t * x);
```

```c
void ao_list_remove_front( ao_list_t * x);
```

```c
void ao_list_reverse( ao_list_t * x);
```


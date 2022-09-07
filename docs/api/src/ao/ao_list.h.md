---
author: "Stefan Wagner"
date: 2022-08-31
draft: false
external-wiki:
- double-ended-queue
- doubly-linked-list
- fifo
- lifo
permalink: /api/src/ao/ao_list.h/
toc: true
---

# Overview

This module defines doubly linked lists. Most commonly, lists are used as double-ended queues, that support insertion and removal of elements at either end. Therefore, they can be used to implement FIFOs or LIFOs.

# Include

```c
#include <stdbool.h>
#include <stddef.h>
```

# Typedefs

```c
typedef struct ao_list_t      ao_list_t;
```

```c
typedef struct ao_list_node_t ao_list_node_t;
```

# Types

## `ao_list_t`

This type represents a list.

```c
struct ao_list_t
{
ao_list_node_t * back;
ao_list_node_t * front;
};
```

It consists of the following members.

| `back` | The back node. |
| `front` | The front node. |

## `ao_list_node_t`

This type represents a list node.

```c
struct ao_list_node_t
{
ao_list_node_t * next;
ao_list_node_t * prev;
};
```

It consists of the following members.

| `next` | The next node. |
| `prev` | The previous node. |

# Functions

Insert `n2` after `n1` into a list in constant time.

```c
void ao_list_insert_after(ao_list_t * x, ao_list_node_t * n1, ao_list_node_t * n2);
```

Insert `n1` before `n2` into a list in constant time.

```c
void ao_list_insert_before(ao_list_t * x, ao_list_node_t * n1, ao_list_node_t * n2);
```

Check whether a list is empty in constant time.

```c
#define ao_list_is_empty(x)
```

Remove and return the back or front node, respectively, in constant time.

```c
ao_list_node_t * ao_list_pop_back( ao_list_t * x);
ao_list_node_t * ao_list_pop_front(ao_list_t * x);
```

Push a node to the back or front, respectively, in constant time.

```c
void ao_list_push_back( ao_list_t * x, ao_list_node_t * n);
void ao_list_push_front(ao_list_t * x, ao_list_node_t * n);
```

Remove a node from a list in constant time.

```c
void ao_list_remove(ao_list_t * x, ao_list_node_t * n);
```

Remove all nodes from a list in linear time.

```c
void ao_list_remove_all(ao_list_t * x);
```

Remove the back or front node, respectively, in constant time.

```c
void ao_list_remove_back( ao_list_t * x);
void ao_list_remove_front(ao_list_t * x);
```

Reverse a list in linear time.

```c
void ao_list_reverse(ao_list_t * x);
```

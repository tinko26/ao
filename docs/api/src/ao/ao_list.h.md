---
author: "Stefan Wagner"
date: 2022-08-31
draft: true
external:
- https://en.wikipedia.org/wiki/Double-ended_queue : "Double-ended queue"
- https://en.wikipedia.org/wiki/Doubly_linked_list : "Doubly-linked list"
- https://en.wikipedia.org/wiki/FIFO : "FIFO"
- https://en.wikipedia.org/wiki/LIFO : "LIFO"
permalink: /api/src/ao/ao_list.h/
toc: true
---

# Notes

This module defines doubly linked lists. Most commonly, lists are used as double-ended queues, that support insertion and removal of elements at either end. Therefore, they can be used to implement FIFOs or LIFOs.

# Include

```c
#include <stdbool.h>
#include <stddef.h>
```

# Identifiers

## `AO_LIST`

```c
#define AO_LIST
```

# Types

## `ao_list_t`

```c
typedef struct ao_list_t ao_list_t;
```

```c
struct ao_list_t
{
    ao_list_node_t * back;
    ao_list_node_t * front;
};
```

This type represents a list. It consists of the following members.

| `back` | The back node. |
| `front` | The front node. |

## `ao_list_node_t`

```c
typedef struct ao_list_node_t ao_list_node_t;
```

```c
struct ao_list_node_t
{
    ao_list_node_t * next;
    ao_list_node_t * prev;
};
```

This type represents a list node. It consists of the following members.

| `next` | The next node. |
| `prev` | The previous node. |

# Functions

## `ao_list_insert_after`

```c
void ao_list_insert_after(ao_list_t * x, ao_list_node_t * n1, ao_list_node_t * n2);
```

Inserts `n2` after `n1` into a list in constant time.

## `ao_list_insert_before`

```c
void ao_list_insert_before(ao_list_t * x, ao_list_node_t * n1, ao_list_node_t * n2);
```

Inserts `n1` before `n2` into a list in constant time.

## `ao_list_is_empty`

```c
#define ao_list_is_empty(x)
```

Checks whether a list is empty in constant time.

## `ao_list_pop_back`
## `ao_list_pop_front`

```c
ao_list_node_t * ao_list_pop_back( ao_list_t * x);
ao_list_node_t * ao_list_pop_front(ao_list_t * x);
```

Pops the back or front node, respectively, in constant time.

## `ao_list_push_back`
## `ao_list_push_front`

```c
void ao_list_push_back( ao_list_t * x, ao_list_node_t * n);
void ao_list_push_front(ao_list_t * x, ao_list_node_t * n);
```

Pushes a node to the back or front, respectively, in constant time.

## `ao_list_remove`

```c
void ao_list_remove(ao_list_t * x, ao_list_node_t * n);
```

Removes a node from a list in constant time.

## `ao_list_remove_all`

```c
void ao_list_remove_all(ao_list_t * x);
```

Removes all nodes from a list in linear time.

## `ao_list_remove_back`
## `ao_list_remove_front`

```c
void ao_list_remove_back( ao_list_t * x);
void ao_list_remove_front(ao_list_t * x);
```

Removes the back or front node, respectively, in constant time.

## `ao_list_reverse`

```c
void ao_list_reverse(ao_list_t * x);
```

Reverses a list in linear time.

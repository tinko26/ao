---
author: "Stefan Wagner"
date: 2022-09-24
draft: true
external:
- https://en.wikipedia.org/wiki/Doubly_linked_list : "Doubly-linked list"
- https://en.wikipedia.org/wiki/Total_order : "Total order"
permalink: /api/src/ao/ao_slist.h/
toc: true
---

# Notes

This module defines doubly linked lists, whose elements are sorted by a strict total order.

# Include

| `stdbool.h` |
| `stddef.h` |

# Types

## `ao_slist_t`

```c
typedef struct ao_slist_t ao_slist_t;
```

Represents a sorted list.

## `ao_slist_node_t`

```c
typedef struct ao_slist_node_t ao_slist_node_t;
```

Represents a node of a sorted list.

## `ao_slist_less_t`

```c
typedef bool (* ao_slist_less_t)
(
    ao_slist_node_t * n1,
    ao_slist_node_t * n2,
    void            * parameter
);
```

Represents a compare function, that implements a strict total order on the list nodes.

# Structs

## `ao_slist_t`

```c
struct ao_slist_t
{
    ao_slist_node_t * back;
    ao_slist_node_t * front;
    ao_slist_less_t   less;
    void            * less_parameter;
};
```

| `back` | The back node. |
| `front` | The front node. |
| `less` | The compare function. |
| `less_parameter` | The compare function parameter. |

## `ao_slist_node_t`

```c
struct ao_slist_node_t
{
    ao_slist_node_t * next;
    ao_slist_node_t * prev;
};
```

| `next` | The next node. |
| `prev` | The previous node. |

# Functions

## `ao_slist_assert`

```c
void ao_slist_assert(ao_slist_t * x);
```

Checks whether a list is valid, in linear time. This function traverses the list from front to back and, for each node, checks, whether it is less than its successor. If that is not the case, the function triggers a runtime assertion failure. It is therefore useful in debugging scenarios.

## `ao_slist_insert`

```c
void ao_slist_insert(ao_slist_t * x, ao_slist_node_t * n);
```

Inserts a node into a list, in linear time.

## `ao_slist_is_empty`

```c
#define ao_slist_is_empty(x) \
(                            \
    (x)->front == NULL       \
    ? true                   \
    : false                  \
)
```

Checks whether a list is empty, in constant time.

## `ao_slist_pop_*`

```c
ao_slist_node_t * ao_slist_pop_back (ao_slist_t * x);
ao_slist_node_t * ao_slist_pop_front(ao_slist_t * x);
```

Pops the back or front node, respectively, in constant time.

## `ao_slist_remove`

```c
void ao_slist_remove(ao_slist_t * x, ao_slist_node_t * n);
```

Removes a node from a list, in constant time.

## `ao_slist_remove_all`

```c
void ao_slist_remove_all(ao_slist_t * x);
```

Removes all nodes from a list, in linear time.

## `ao_slist_remove_back`
## `ao_slist_remove_front`

```c
void ao_slist_remove_back (ao_slist_t * x);
void ao_slist_remove_front(ao_slist_t * x);
```

Removes the back or front node, respectively, in constant time.

## `ao_slist_update`

```c
void ao_slist_update(ao_slist_t * x, ao_slist_node_t * n);
```

A change in a single element can render the internal ordering of a list invalid. One way to deal with this, is to remove the element before the change and re-insert it afterwards. Another option is to update the list, after the change has taken place. This function will move the specified node forwards or backwards, respectively, until the ordering is restored, which takes linear time.

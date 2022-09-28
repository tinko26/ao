---
author: "Stefan Wagner"
date: 2022-09-28
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
    ao_slist_node_t const * node1,
    ao_slist_node_t const * node2,
    void *                  parameter
);
```

| `node1` | The first node. |
| `node2` | The second node. |
| `parameter` | An additional parameter. |

Represents a compare function for sorted list nodes, that implements a strict total order. The function returns `true`, if the first node is strictly less than the second node, otherwise `false`.

# Structs

## `ao_slist_t`

```c
struct ao_slist_t
{
    ao_slist_node_t * back;
    ao_slist_node_t * front;
    ao_slist_less_t   less;
    void *            less_parameter;
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
void ao_slist_assert(ao_slist_t const * slist);
```

Checks whether a list is valid, in linear time. This function traverses the list from front to back and, for each node, checks, whether it is less than its successor. If that is not the case, the function triggers a runtime assertion failure. It is therefore useful in debugging scenarios.

## `ao_slist_insert`

```c
void ao_slist_insert(ao_slist_t * slist, ao_slist_node_t * node);
```

Inserts a node into a list, in linear time.

## `ao_slist_is_empty`

```c
bool ao_slist_is_empty(ao_slist_t const * slist);
```

Checks whether a list is empty, in constant time.

## `ao_slist_pop_*`

```c
ao_slist_node_t * ao_slist_pop_back (ao_slist_t * slist);
ao_slist_node_t * ao_slist_pop_front(ao_slist_t * slist);
```

Pops the back or front node, respectively, in constant time.

## `ao_slist_remove`

```c
void ao_slist_remove(ao_slist_t * slist, ao_slist_node_t * node);
```

Removes a node from a list, in constant time.

## `ao_slist_remove_all`

```c
void ao_slist_remove_all(ao_slist_t * slist);
```

Removes all nodes from a list, in linear time.

## `ao_slist_remove_back`
## `ao_slist_remove_front`

```c
void ao_slist_remove_back (ao_slist_t * slist);
void ao_slist_remove_front(ao_slist_t * slist);
```

Removes the back or front node, respectively, in constant time.

## `ao_slist_update`

```c
void ao_slist_update(ao_slist_t * slist, ao_slist_node_t * node);
```

A change in a single element can render the internal ordering of a list invalid. One way to deal with this, is to remove the element before the change and re-insert it afterwards. Another option is to update the list, after the change has taken place. This function will move the specified node forwards or backwards, respectively, until the ordering is restored, which takes linear time.

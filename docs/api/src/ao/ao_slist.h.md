---
author: "Stefan Wagner"
date: 2022-08-31
draft: false
permalink: /api/src/ao/ao_slist.h/
toc: true
wiki:
- doubly-linked-list
- total-order
---

# Overview

This module defines doubly linked lists, whose elements are sorted by a strict total order.

# Include

```c
#include <stdbool.h>
#include <stddef.h>
```

# Typedefs

```c
typedef struct ao_slist_t      ao_slist_t;
```

```c
typedef struct ao_slist_node_t ao_slist_node_t;
```

```c
typedef bool (* ao_slist_less_t)
(
ao_slist_node_t * n1,
ao_slist_node_t * n2,
void            * parameter
);
```

# Types

## `ao_slist_t`

This type represents a sorted list.

```c
struct ao_slist_t
{
ao_slist_node_t * back;
ao_slist_node_t * front;
ao_slist_less_t   less;
void            * less_parameter;
};
```

It consists of the following members.

| `back` | The back node. |
| `front` | The front node. |
| `less` | The compare function. |
| `less_parameter` | The compare function parameter. |

## `ao_slist_node_t`

This type represents a node of a sorted list.

```c
struct ao_slist_node_t
{
ao_slist_node_t * next;
ao_slist_node_t * prev;
};
```

It consists of the following members.

| `next` | The next node. |
| `prev` | The previous node. |

## `ao_slist_less_t`

This type represents a compare function, that implements a strict total order on the list nodes.

# Functions

Check whether a list is valid in linear time. This function traverses the list from front to back and, for each node, checks, whether it is less than its successor. If that is not the case, the function triggers a runtime assertion failure. It is therefore useful in debugging scenarios.

```c
void ao_slist_assert(ao_slist_t * x);
```

Insert a node into a list in linear time.

```c
void ao_slist_insert(ao_slist_t * x, ao_slist_node_t * n);
```

Check whether a list is empty in constant time.

```c
#define ao_slist_is_empty(x)
```

Remove and return the back or front node, respectively, in constant time.

```c
ao_slist_node_t * ao_slist_pop_back( ao_slist_t * x);
ao_slist_node_t * ao_slist_pop_front(ao_slist_t * x);
```

Remove a node from a list in constant time.

```c
void ao_slist_remove(ao_slist_t * x, ao_slist_node_t * n);
```

Remove all nodes from a list in linear time.

```c
void ao_slist_remove_all(ao_slist_t * x);
```

Remove the back or front node, respectively, in constant time.

```c
void ao_slist_remove_back( ao_slist_t * x);
void ao_slist_remove_front(ao_slist_t * x);
```

A change in a single element can render the internal ordering of a list invalid. One way to deal with this, is to remove the element before the change and re-insert it afterwards. Another option is to update the list, after the change has taken place. This function will move the specified node forwards or backwards, respectively, until the ordering is restored, which takes linear time.

```c
void ao_slist_update( ao_slist_t * x, ao_slist_node_t * n);
```

# Usage

Both lists and list nodes can be initialized by clearing their respective members.

```c
ao_slist_t * l;
```

```c
l->back = NULL;
l->front = NULL;
l->less = NULL;
l->less_parameter = NULL;
```

```c
ao_slist_node_t * n;
```

```c
n->next = NULL;
n->prev = NULL;
```

However, prior to inserting elements, a compare function must be set.

```c
bool compare(ao_slist_node_t * n1, ao_slist_node_t * n2, void * p)
{
if (/* n1 is less than n2 */)
{
return true;
}
else
{
return false;
}
}
```

```c
l->less = compare;
```

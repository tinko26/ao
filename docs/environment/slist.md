---
author: "Stefan Wagner"
date: 2022-08-03
description: ""
draft: false
permalink: /environment/slist/
title: "Sorted Lists"
---

# Sorted Lists

The `ao_slist.h` module defines [doubly linked lists](https://en.wikipedia.org/wiki/Doubly_linked_list), whose elements are sorted by a [strict total order](https://en.wikipedia.org/wiki/Total_order).

## Types

### List

The `ao_slist_t` type represents a sorted list. It holds pointers to the first and last element, respectively, as well as a pointer to a compare function and a compare function parameter. 

```c
struct ao_slist_t
{
    ao_slist_node_t * back;
    ao_slist_node_t * front;
    ao_slist_less_t   less;
    void *            less_parameter;
}
```

### Node

The `ao_slist_node_t` type represents an element of a sorted list. It holds pointers to its predecessor and successor, respectively.

```c
struct ao_slist_node_t
{
    ao_slist_node_t * next;
    ao_slist_node_t * prev;
}
```

### Compare Function

The `ao_slist_less_t` type represents a compare function, that implements a strict total order on the list nodes.

```c
typedef bool (* ao_slist_less_t)
(
    ao_slist_node_t * n1,
    ao_slist_node_t * n2,
    void * parameter
);
```

## Initialization

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

## Functions

If both the front and back pointers of a list are clear, then the list is empty. This can be checked with a macro function.

```c
if (ao_slist_is_empty(l))
{
    // List is empty.
}
```

Inserting an element into a list is straightforward and takes linear time.

```c
ao_slist_insert(l, n);
```

A change in a single element can render the internal ordering of a list invalid. One way to deal with this, is to remove the element before the change and re-insert it afterwards.

```c
ao_slist_remove(l, n);
ao_slist_insert(l, n);
```

Another option is to update the list, after the change has taken place. This function will move the specified node forwards or backwards, respectively, until the ordering is restored, which takes linear time.

```c
ao_slist_update(l, n);
```

Removing an individual element is a constant time operation.

```c
ao_slist_remove(l, n);
```

```c
ao_slist_remove_back(l);
ao_slist_remove_front(l);
```

```c
n = ao_slist_pop_back(l);
n = ao_slist_pop_front(l);
```

Removing all nodes at once, however, takes linear time.

```c
ao_slist_remove_all(l);
```

The correct ordering of a list can be asserted in linear time, too. The function traverses the list from front to back and, for each node, checks, whether it is less than its successor. If that is not the case, the function triggers a runtime [assertion](assert.md) failure.

```c
ao_slist_assert(l);
```

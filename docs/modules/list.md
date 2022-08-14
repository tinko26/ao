---
author: "Stefan Wagner"
date: 2022-08-03
description: "The ao_list.h module of the ao real-time operating system."
draft: false
permalink: /modules/list/
title: "ao_list.h"
---

# ao_list.h

This module defines doubly linked lists.

## Types

### List

The `ao_list_t` type represents a list. It holds pointers to the first and last element, respectively.

```c
struct ao_list_t
{
    ao_list_node_t * back;
    ao_list_node_t * front;
}
```

### Node

The `ao_list_node_t` type represents an element of a list. It holds pointers to its predecessor and successor, respectively.

```c
struct ao_list_node_t
{
    ao_list_node_t * next;
    ao_list_node_t * prev;
}
```

## Initialization

Both lists and list nodes can be initialized by clearing their respective members.

```c
ao_list_t * l;
```

```c
l->back = NULL;
l->front = NULL;
```

```c
ao_list_node_t * n;
```

```c
n->next = NULL;
n->prev = NULL;
```

## Functions

If both pointers of a list are clear, then the list is empty. This can be checked with a macro function.

```c
if (ao_list_is_empty(l))
{
    // List is empty.
}
```

Most commonly, lists are used as double-ended queues, that support insertion and removal of elements at either end. Therefore, they can be used to implement FIFOs or LIFOs.

```c
ao_list_node_t * n1;
ao_list_node_t * n2;
ao_list_node_t * n3;
```

```c
ao_list_push_front(l, n1);
ao_list_push_back(l, n2);
ao_list_push_back(l, n3);
```

```c
ao_list_pop_front(l);
ao_list_pop_back(l);
```

Because of the pointer-based linkage, a node can also be inserted into a list at an arbitrary position.

```c
ao_list_insert_before(l, n1, n2);
ao_list_insert_after(l, n2, n3);
```

Inserting and removing single nodes are constant time operations. However, there are two additional functions that take linear time. These functions reverse a list or remove all elements, respectively.

```c
ao_list_reverse(l);
```

```c
ao_list_remove_all(l);
```

## External Links

[https://en.wikipedia.org/wiki/Double-ended_queue](https://en.wikipedia.org/wiki/Double-ended_queue)

[https://en.wikipedia.org/wiki/Doubly_linked_list](https://en.wikipedia.org/wiki/Doubly_linked_list)

[https://en.wikipedia.org/wiki/FIFO](https://en.wikipedia.org/wiki/FIFO)

[https://en.wikipedia.org/wiki/LIFO](https://en.wikipedia.org/wiki/LIFO)

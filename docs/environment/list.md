---
author: "Stefan Wagner"
date: 2022-08-03
description: "Lists in the ao Real-Time Operating System (RTOS)."
draft: false
permalink: /environment/list/
title: "Lists"
---

# Lists

The `ao_list.h` module defines [doubly-linked lists](https://en.wikipedia.org/wiki/Doubly_linked_list).

## Types

The `ao_list_t` type represents a list. It holds pointers to the first and last element, respectively.

```c
struct ao_list_t
{
    ao_list_node_t * back;
    ao_list_node_t * front;
}
```

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

Most commonly, lists are used as [double-ended queues](https://en.wikipedia.org/wiki/Double-ended_queue), that support insertion and removal of elements at either end. Therefore, they can be used to implement [FIFOs](https://en.wikipedia.org/wiki/FIFO_(computing_and_electronics)) or [LIFOs](https://en.wikipedia.org/wiki/LIFO_(computing)).

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

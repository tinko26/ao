---
author: "Stefan Wagner"
date: 2022-08-03
description: "Lists in the ao Real-Time Operating System (RTOS)."
draft: false
permalink: /environment/list/
title: "Lists"
---

# Lists

The `ao_list.h` module defines [doubly-linked lists](https://en.wikipedia.org/wiki/Doubly_linked_list) and corresponding operations.

## Types

The `ao_list_t` type represents a linked list. It holds a pointer to the first and last element, respectively.

The `ao_list_node_t` type represents an element of a linked list. It holds a pointer to its predecessor and successor, respectively.

Both lists and list nodes can be initialized by clearing their respective members.

```c
ao_list_t * l;

l->back = NULL;
l->front = NULL;
```

## Functions

### ao_list_is_empty()

This macro function checks whether a list is empty by examining its front pointer.

### ao_list_insert_after()
### ao_list_insert_before()

These functions insert a node after or before another node, respectively, that is already contained in a list.

```c
ao_list_t * l;
ao_list_node_t * n1;
ao_list_node_t * n2;
ao_list_node_t * n3;

ao_list_push_back(l, n1);
ao_list_insert_after(l, n1, n3);
ao_list_insert_before(l, n2, n3);

ao_assert(n1->next == n2);
ao_assert(n2->next == n3);
ao_assert(n3->prev == n2);
ao_assert(n2->prev == n1);
```

### ao_list_pop_back()
### ao_list_pop_front()

These functions remove and return the first or last node of a list, respectively.

```c
ao_list_t * l;
ao_list_node_t * nb;
ao_list_node_t * nf;

nb = ao_list_pop_back(l);
nf = ao_list_pop_front(l);
```

### ao_list_push_back()
### ao_list_push_front()

These functions insert a node at the beginning or end of a list, respectively.

```c
ao_list_t * l;
ao_list_node_t * nb;
ao_list_node_t * nf;

ao_list_push_back(l, nb);
ao_list_push_front(l, nf);

ao_assert(l->back  == nb);
ao_assert(l->front == nf);
```

### ao_list_remove()

This function removes a node from a list.

```c
ao_list_t * l;
ao_list_node_t * n;

ao_list_remove(l, n);

ao_assert(n->next == NULL);
ao_assert(n->prev == NULL);
```

### ao_list_remove_back()
### ao_list_remove_front()

These functions remove the first or last node of a list, respectively.

```c
ao_list_t * l;

ao_list_remove_back(l);
ao_list_remove_front(l);
```

### ao_list_remove_all()

This function removes all nodes from a list.

```c
ao_list_t * l;

ao_list_remove_all(l);
```

### ao_list_reverse()

This function reverses the order of the nodes contained in a list.

```c
ao_list_t * l;

ao_list_reverse(l);
```

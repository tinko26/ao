---
author: "Stefan Wagner"
date: 2022-08-03
description: "Lists in the ao Real-Time Operating System (RTOS)."
draft: true
permalink: /environment/list/
title: "Lists"
---

# Lists

The **list** module defines [doubly-linked lists](https://en.wikipedia.org/wiki/Doubly_linked_list) and corresponding operations.

## Types

The `ao_list_t` type represents a linked list. It holds a pointer to the first and last element, respectively.

The `ao_list_node_t` type represents an element of a linked list. It holds apointer to its predecessor and successor, respectively.

Both lists and list nodes can be initialized by clearing their respective members.

```c
ao_list_t l;

l.back = NULL;
l.front = NULL;
```

## Functions

The **list** module defines the following functions.

### ao_list_is_empty()

This macro function checks whether a list is empty by examining its front pointer.

### ao_list_insert_after()

This function inserts a node after another node, that is already contained in a list.

```c
ao_list_t * l;

ao_list_node_t * n1;
ao_list_node_t * n2;

ao_list_push_back(l, n1);

ao_list_insert_after(l, n1, n2);

ao_assert(n1->next == n2);
ao_assert(n2->prev == n1);
```

### ao_list_insert_before()

This function inserts a node before another node, that is already contained in a list.

```c
ao_list_t * l;

ao_list_node_t * n1;
ao_list_node_t * n2;

ao_list_push_back(l, n2);

ao_list_insert_before(l, n1, n2);

ao_assert(n1->next == n2);
ao_assert(n2->prev == n1);
```

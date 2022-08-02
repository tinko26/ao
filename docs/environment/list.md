---
author: "Stefan Wagner"
description: "Lists in the ao Real-Time Operating System (RTOS)."
permalink: /environment/list/
title: "Lists"
---

# Lists

The `ao_list.h` module defines [doubly-linked lists](https://en.wikipedia.org/wiki/Doubly_linked_list) and corresponding operations.

## Types

The `ao_list_t` type represents a linked list. It holds a pointer to the first and last element, respectively.

The `ao_list_node_t` type represents an element of a linked list. It holds apointer to its predecessor and successor, respectively.

## Functions

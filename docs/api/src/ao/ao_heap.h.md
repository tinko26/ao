---
api: true
author: "Stefan Wagner"
date: 2022-08-31
description: "The /src/ao/ao_heap.h file of the ao real-time operating system."
draft: false
permalink: /api/src/ao/ao_heap.h/
subtitle: "Pointer-based binary heaps"
title: "ao_heap.h"
toc: true
wiki:
- title: "Binary heap"
  url: https://en.wikipedia.org/wiki/Binary_heap
- title: "Binary tree"
  url: https://en.wikipedia.org/wiki/Binary_tree
- title: "Priority queue"
  url: https://en.wikipedia.org/wiki/Priority_queue
- title: "Total order"
  url: https://en.wikipedia.org/wiki/Total_order
---

# Overview

This module defines binary heaps. 

A binary heap is a special kind of binary tree that maintains both the shape of a complete binary tree and the heap property. The latter implies, that a node is always less than its children, with respect to a strict total order.

Both insertion into and removal from heaps take logarithmic time. This makes them a perfect choice for implementing priority queues.

Commonly, heaps are implemented based on an array that stores all the nodes. However, this module provides a pointer-based implementation, that is, each node holds pointers to its parent and children. Therefore, the capacity of a heap is virtually unbounded. This is useful, for example, if the maximum number of nodes cannot be estimated well.

# Include

```c
#include <ao_uint.h>
#include <stdbool.h>
#include <stddef.h>
```

# Typedefs

```c
typedef struct ao_heap_t ao_heap_t;
```

```c
typedef struct ao_heap_node_t ao_heap_node_t;
```

```c
typedef bool (* ao_heap_less_t)
(
    ao_heap_node_t * n1,
    ao_heap_node_t * n2,
    void           * parameter
);
```

# Configuration

Keep track of the maximum number of nodes.

```c
#define AO_HEAP_COUNT_MAX (false)
```

# Types

## `ao_heap_t`

This type represents a heap.

```c
struct ao_heap_t
{
    ao_uint_t        count;

#if AO_HEAP_COUNT_MAX

    ao_uint_t        count_max;

#endif

    ao_heap_less_t   less;
    void           * less_parameter;
    ao_heap_node_t * root;
};
```

It consists of the following members.

| `count` | The current number of nodes. |
| `count_max` | The maximum number of nodes. |
| `less` | The compare function. |
| `less_parameter` | The compare function parameter. |
| `root` | The root node. |

## `ao_heap_node_t`

This type represents a node.

```c
struct ao_heap_node_t
{
    ao_heap_node_t * left;
    ao_heap_node_t * parent;
    ao_heap_node_t * right;
};
```

It consists of the following members.

| `left` | The left child node. |
| `parent` | The parent node. |
| `right` | The right child node. |

## `ao_heap_less_t`

This type represents a compare function, that implements a strict total order on the nodes.

# Functions

Assert the correctness of a heap in linear time. This function traverses the heap top-down and checks, whether both the heap condition and the shape of a complete binary tree are maintained. If that is not the case, the function triggers a runtime assertion failure.

It is therefore useful in debugging scenarios. However, the function is implemented recursively, which violates a common rule in embedded software engineering.

```c
void ao_heap_assert(ao_heap_t * x);
```

Insert a node into a heap in logarithmic time.

```c
void ao_heap_insert(ao_heap_t * x, ao_heap_node_t * n);
```

Check whether a heap is empty in constant time.

```c
#define ao_heap_is_empty(x)
```

Get the root node of a heap without removing it in constant time.

```c
#define ao_heap_peek(x)
```

Remove the root node from a heap in logarithmic time.

```c
ao_heap_node_t * ao_heap_pop(ao_heap_t * x);
```

Remove an arbitrary node from a heap in logarithmic time.

```c
void ao_heap_remove(ao_heap_t * x, ao_heap_node_t * n);
```

# Usage

A heap node can be initialized by clearing all of its members.

```c
ao_heap_node_t * n;
```

```c
n->left = NULL;
n->parent = NULL;
n->right = NULL;
```

A heap can be initialized by clearing all of its members, too.

```c
ao_heap_t * h;
```

```c
h->count = 0;
h->count_max = 0;
h->less = NULL;
h->less_parameter = NULL;
h->root = NULL;
```

However, prior to inserting nodes, a compare function must be set.

```c
bool compare(ao_heap_node_t * n1, ao_heap_node_t * n2, void * p)
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
h->less = compare;
```

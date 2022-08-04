---
author: "Stefan Wagner"
date: 2022-08-04
description: "Heaps in the ao Real-Time Operating System (RTOS)."
draft: false
permalink: /environment/heap/
title: "Heaps"
---

# Heaps

The `ao_heap.h` module defines [binary heaps](https://en.wikipedia.org/wiki/Binary_heap). 

A binary heap is a special kind of [binary tree](https://en.wikipedia.org/wiki/Binary_tree) that maintains both the shape of complete binary tree and the heap property. The latter implies, that a node is always less than its children, with respect to a [strict total order](https://en.wikipedia.org/wiki/Total_order). 

Both insertion into and removal from heaps take logarithmic time. This makes them a perfect choice for implementing [priority queues](https://en.wikipedia.org/wiki/Priority_queue).

Commonly, heaps are implemented based on an array that stores all the nodes. However, this module provides a pointer-based implementation, that is, each node holds pointers to its parent and children. Therefore, the capacity of a heap is virtually unbounded. This is useful, for example, if the maximum number of nodes cannot be estimated well.

## Configuration

Heaps keep track of their current number of nodes. Additionally, they can be configured to keep track of the maximum number of nodes ever contained within them. By default, this option is disabled.

```c
#define AO_HEAP_COUNT_MAX (true)
```

## Types

### Heap

The `ao_heap_t` type represents a heap.

```c
struct ao_heap_t
{
    ao_uint_t count;
    ao_uint_t count_max;
    ao_heap_less_t less;
    void * less_parameter;
    ao_heap_node_t * root;
};
```

It consists of the following members.

| Member | |
|--------|-|
| `count` | The current number of nodes contained in the heap. |
| `count_max` | The maximum-ever number of nodes contained in the heap. This member is absent, if the `AO_HEAP_COUNT_MAX` configuration option is disabled. |
| `less` | The compare function for nodes. |
| `less_parameter` | An additional parameter for the compare function. |
| `root` | The pointer to the current root of the heap. |

### Node

The `ao_heap_node_t` type represents a node. It holds pointers to its parent and child nodes.

```c
struct ao_heap_node_t
{
    ao_heap_node_t * left;
    ao_heap_node_t * parent;
    ao_heap_node_t * right;
};
```

### Compare Function

The `ao_heap_less_t` type represents a compare function, that implements a strict total order on the nodes.

```c
typedef bool (* ao_heap_less_t)
(
    ao_heap_node_t * n1,
    ao_heap_node_t * n2,
    void * parameter
);
```

## Initialization

A heap node can be initialized by clearing all its members.

```c
ao_heap_node_t * n;
```

```c
n->left = NULL;
n->parent = NULL;
n->right = NULL;
```

A heap can be initialized by clearing all its members.

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

## Functions

The current root of a heap can be accessed directly via the `root` member or using a macro function.

```c
n = ao_heap_peek(h);
```

If the root is clear, then the heap is empty. This can be checked with a macro function, too.

```c
if (ao_heap_is_empty(h))
{
    // Heap is empty.
}
```

Inserting a node takes logarithmic time.

```c
ao_heap_insert(h, n);
```

Removing a node takes logarithmic time, too. Thereby, one can remove an arbitrary node ...

```c
ao_heap_remove(h, n);
```

... or the root node.

```c
n = ao_heap_pop(h);
```

The correctness of a heap can be asserted in linear time. The function traverses the heap top-down and checks, whether both the heap condition and the shape of a complete binary tree are maintained. If that is not the case, the function triggers a [runtime assertion](assert.md) failure.

It is therefore useful in debugging scenarios. However, the function is implemented recursively, which violates a common rule in embedded software engineering.

```c
ao_heap_assert(h);
```

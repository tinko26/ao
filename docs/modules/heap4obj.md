---
author: "Stefan Wagner"
date: 2022-08-04
description: "The ao_heap4obj.h module of the ao real-time operating system."
draft: false
permalink: /modules/heap4obj/
title: "ao_heap4obj.h"
---

# Overview

This module defines binary heaps for objects.

A binary heap is a special kind of binary tree that maintains both the shape of a complete binary tree and the heap property. The latter implies, that a node is always less than its children, with respect to a strict total order. 

Both insertion into and removal from heaps take logarithmic time. This makes them a perfect choice for implementing priority queues.

This module provides an array-based implementation.

## Configuration

Object heaps keep track of their current number of nodes. Additionally, they can be configured to keep track of the maximum number of nodes ever contained within them. By default, this option is disabled.

```c
#define AO_HEAP4OBJ_COUNT_MAX
```

## Types

### Heap

The `ao_heap4obj_t` type represents an object heap.

```c
struct ao_heap4obj_t
{
    size_t             capacity;
    size_t             count;
    size_t             count_max;
    size_t *           heap1;
    size_t *           heap2;
    ao_heap4obj_less_t less;
    void *             less_parameter;
    size_t             size;
    void *             store;
};
```

It consists of the following members.

| Member | |
|--------|-|
| `capacity` | The maximum number of nodes that the heap can contain. If this value is greater than zero, then the `store` value must not be clear. |
| `count` | The current number of nodes contained in the heap. |
| `count_max` | The maximum-ever number of nodes contained in the heap. This member is absent, if the `AO_HEAP4OBJ_COUNT_MAX` configuration option is disabled. |
| `heap1` | The pointer to the first index buffer with the specified `capacity`. |
| `heap2` | The pointer to the second index buffer with the specified `capacity`. |
| `less` | The compare function for nodes. |
| `less_parameter` | An additional parameter for the compare function. |
| `size` | The size of a node, in bytes. |
| `store` | The pointer to the store with the specified `capacity`. |

### Compare Function

The `ao_heap4obj_less_t` type represents a compare function, that implements a strict total order on the nodes.

```c
typedef bool (* ao_heap4obj_less_t)
(
    void * p1,
    void * p2,
    void * parameter
);
```

## Initialization

A heap can be initialized by clearing all of its members.

```c
ao_heap4obj_t * h;
```

```c
h->capacity = 0;
h->count = 0;
h->count_max = 0;
h->heap1 = NULL;
h->heap2 = NULL;
h->less = NULL;
h->less_parameter = NULL;
h->size = 0;
h->store = NULL;
```

However, such a heap is not very useful, since it cannot contain a single node. Therefore, it should be equipped with a store and two index buffers.

```c
size_t heap1[128];
size_t heap2[128];
double store[128];
```

```c
h->capacity = 128;
h->heap1 = heap1;
h->heap2 = heap2;
h->store = store;
```

 Also, the node size must be set appropriately.

 ```c
 h->size = sizeof(double);
 ```

Finally, prior to inserting nodes, a compare function must be set.

```c
bool compare(void * p1, void * p2, void * p)
{
    double d1 = *((double *) p1);
    double d2 = *((double *) p2);

    return d1 < d2 ? true : false;
}
```

```c
h->less = compare;
```

## Functions

If a heap's count is zero, then the heap is empty. Accordingly, if the heap's count matches its capacity, then the heap is full. Both cases can be checked with a respective macro function.

```c
if (ao_heap4obj_is_empty(h))
{
    // Heap is empty.
}
```

```c
if (ao_heap4obj_is_full(h))
{
    // Heap is full.
}
```

The current root can be retrieved in constant time.

```c
double n;
```

```c
ao_heap4obj_peek(h, &n);
```

Inserting a node takes logarithmic time.

```c
ao_heap4obj_insert(h, &n);
```

Removing the root node takes logarithmic time, too.

```c
ao_heap4obj_pop(h, &n);
```

All three functions return a boolean value indicating whether the respective operation was successful. Therefore, one can safely try to insert a node into a full heap or retrieve or remove the root node from an empty heap.

The correctness of a heap can be asserted in linear time. The function traverses the heap top-down and checks, whether both the heap condition and the shape of a complete binary tree are maintained. If that is not the case, the function triggers a runtime [assertion](../assertions.md) failure.

```c
ao_heap4obj_assert(h);
```

## External Links

[https://en.wikipedia.org/wiki/Binary_heap](https://en.wikipedia.org/wiki/Binary_heap)

[https://en.wikipedia.org/wiki/Binary_tree](https://en.wikipedia.org/wiki/Binary_tree)

[https://en.wikipedia.org/wiki/Priority_queue](https://en.wikipedia.org/wiki/Priority_queue)

[https://en.wikipedia.org/wiki/Total_order](https://en.wikipedia.org/wiki/Total_order)

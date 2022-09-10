---
author: "Stefan Wagner"
date: 2022-08-31
draft: true
external:
- https://en.wikipedia.org/wiki/Binary_heap : "Binary heap"
- https://en.wikipedia.org/wiki/Binary_tree : "Binary tree"
- https://en.wikipedia.org/wiki/Priority_queue : "Priority queue"
- https://en.wikipedia.org/wiki/Total_order : "Total order"
permalink: /api/src/ao/ao_heap4obj.h/
toc: true
---

# Notes

This module defines binary heaps for objects.

A binary heap is a special kind of binary tree that maintains both the shape of a complete binary tree and the heap property. The latter implies, that a node is always less than its children, with respect to a strict total order.

Both insertion into and removal from heaps take logarithmic time. This makes them a perfect choice for implementing priority queues.

This module provides an array-based implementation.

# Include

```c
#include <stdbool.h>
#include <stddef.h>
```

# Identifiers

## `AO_HEAP4OBJ`

```c
#define AO_HEAP4OBJ
```

# Configuration

## `AO_HEAP4OBJ_COUNT_MAX`

```c
#define AO_HEAP4OBJ_COUNT_MAX (false)
```

Defines whether to keep track of the maximum number of objects.

# Types

## `ao_heap4obj_t`

```c
typedef struct ao_heap4obj_t ao_heap4obj_t;
```

```c
struct ao_heap4obj_t
{
    size_t             capacity;
    size_t             count;

#if AO_HEAP4OBJ_COUNT_MAX

    size_t             count_max;

#endif

    size_t *           heap1;
    size_t *           heap2;
    ao_heap4obj_less_t less;
    void   *           less_parameter;
    size_t             size;
    void   *           store;
};
```

This type represents a heap for objects. It consists of the following members.

| `capacity` | The maximum number of objects that can be stored in the heap. |
| `count` | The current number of objects stored in the heap. |
| `count_max` | The maximum number of objects stored in the heap. |
| `heap1` | The first index buffer. |
| `heap2` | The second index buffer. |
| `less` | The compare function. |
| `less_parameter` | The compare function parameter. |
| `size` | The size of an object, in bytes. |
| `store` | The store. |

## `ao_heap4obj_less_t`

```c
typedef bool (* ao_heap4obj_less_t)
(
    void * p1,
    void * p2,
    void * parameter
);
```

This type represents a compare function, that implements a strict total order on objects.

# Functions

## `ao_heap4obj_assert`

```c
void ao_heap4obj_assert(ao_heap4obj_t * x);
```

Asserts the correctness of a heap in linear time. This function traverses the heap top-down and checks, whether both the heap condition and the shape of a complete binary tree are maintained. If that is not the case, the function triggers a runtime assertion failure.

## `ao_heap4obj_insert`

```c
bool ao_heap4obj_insert(ao_heap4obj_t * x, void const * p);
```

Inserts an object into a heap in logarithmic time. The return value indicates, whether the operation was successful. Therefore, it is safe to call this function, if the heap is full.

## `ao_heap4obj_is_empty`
## `ao_heap4obj_is_full`

```c
#define ao_heap4obj_is_empty(x)
#define ao_heap4obj_is_full(x)
```

Checks whether a heap is empty or full, respectively, in constant time.

## `ao_heap4obj_peek`

```c
bool ao_heap4obj_peek(ao_heap4obj_t const * x, void * p);
```

Gets the root object of a heap without removing it in constant time. The return value indicates, whether the operation was successful. Therefore, it is safe to call this function, if the heap is empty.

## `ao_heap4obj_pop`

```c
bool ao_heap4obj_pop(ao_heap4obj_t * x, void * p);
```

Removes the root object from a heap in logarithmic time. The return value indicates, whether the operation was successful. Therefore, it is safe to call this function, if the heap is empty.

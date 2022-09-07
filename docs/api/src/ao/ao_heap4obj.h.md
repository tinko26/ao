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

# Overview

This module defines binary heaps for objects.

A binary heap is a special kind of binary tree that maintains both the shape of a complete binary tree and the heap property. The latter implies, that a node is always less than its children, with respect to a strict total order.

Both insertion into and removal from heaps take logarithmic time. This makes them a perfect choice for implementing priority queues.

This module provides an array-based implementation.

# Include

```c
#include <stdbool.h>
#include <stddef.h>
```

# Typedefs

```c
typedef struct ao_heap4obj_t ao_heap4obj_t;
```

```c
typedef bool (* ao_heap4obj_less_t)
(
    void * p1,
    void * p2,
    void * parameter
);
```

# Configuration

Keep track of the maximum number of objects.

```c
#define AO_HEAP4OBJ_COUNT_MAX (false)
```

# Types

## `ao_heap4obj_t`

This type represents a heap for objects.

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

It consists of the following members.

| `capacity` | The maximum number of objects that can be stored in the heap. |
| `count` | The current number of objects stored in the heap. |
| `count_max` | The maximum number of objects stored in the heap. |
| `heap1` | The first index buffer. |
| `heap2` | The second index buffer. |
| `less` | The compare function. |
| `less_parameter` | The compare function parameter. |
| `size` | The size of an object in bytes. |
| `store` | The store. |

## `ao_heap4obj_less_t`

This type represents a compare function, that implements a strict total order on objects.

# Functions

Assert the correctness of a heap in linear time. This function traverses the heap top-down and checks, whether both the heap condition and the shape of a complete binary tree are maintained. If that is not the case, the function triggers a runtime assertion failure.

```c
void ao_heap4obj_assert(ao_heap4obj_t * x);
```

Insert an object into a heap in logarithmic time. The return value indicates, whether the operation was successful. Therefore, it is safe to call this function, if the heap is full.

```c
bool ao_heap4obj_insert(ao_heap4obj_t * x, void const * p);
```

Check whether a heap is empty or full, respectively, in constant time.

```c
#define ao_heap4obj_is_empty(x)
#define ao_heap4obj_is_full(x)
```

Get the root object of a heap without removing it in constant time. The return value indicates, whether the operation was successful. Therefore, it is safe to call this function, if the heap is empty.

```c
bool ao_heap4obj_peek(ao_heap4obj_t const * x, void * p);
```

Remove the root object from a heap in logarithmic time. The return value indicates, whether the operation was successful. Therefore, it is safe to call this function, if the heap is empty.

```c
bool ao_heap4obj_pop(ao_heap4obj_t * x, void * p);
```

# Usage

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

However, such a heap is not very useful, since it cannot contain a single object. Therefore, it should be equipped with a store and two index buffers.

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

Also, the object size must be set appropriately.

```c
h->size = sizeof(double);
```

Finally, prior to inserting objects, a compare function must be set.

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

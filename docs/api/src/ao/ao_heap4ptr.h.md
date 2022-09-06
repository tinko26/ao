---
api: true
author: "Stefan Wagner"
date: 2022-08-31
description: "The /src/ao/ao_heap4ptr.h file of the ao real-time operating system."
draft: false
permalink: /api/src/ao/ao_heap4ptr.h/
subtitle: "Array-based binary heaps for pointers"
title: "ao_heap4ptr.h"
toc: true
wiki:
- binary-heap
- binary-tree
- priority-queue
- total-order
---

# Overview

This module defines binary heaps for pointers.

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
typedef struct ao_heap4ptr_t ao_heap4ptr_t;
```

```c
typedef bool (* ao_heap4ptr_less_t)
(
    void * p1,
    void * p2,
    void * parameter
);
```

# Configuration

Keep track of the maximum number of pointers.

```c
#define AO_HEAP4PTR_COUNT_MAX (false)
```

# Types

## `ao_heap4ptr_t`

This type represents a heap for pointers.

```c
struct ao_heap4ptr_t
{
    size_t             capacity;
    size_t             count;

#if AO_HEAP4PTR_COUNT_MAX

    size_t             count_max;

#endif

    size_t *           heap1;
    size_t *           heap2;
    ao_heap4ptr_less_t less;
    void *             less_parameter;
    void **            store;
};
```

It consists of the following members.

| `capacity` | The maximum number of pointers that can be stored in the heap. |
| `count` | The current number of pointers stored in the heap. |
| `count_max` | The maximum number of pointers stored in the heap. |
| `heap1` | The first index buffer. |
| `heap2` | The second index buffer. |
| `less` | The compare function. |
| `less_parameter` | The compare function parameter. |
| `store` | The store. |

## `ao_heap4ptr_less_t`

This type represents a compare function, that implements a strict total order on pointers.

# Functions

Assert the correctness of a heap in linear time. This function traverses the heap top-down and checks, whether both the heap condition and the shape of a complete binary tree are maintained. If that is not the case, the function triggers a runtime assertion failure.

```c
void ao_heap4ptr_assert(ao_heap4ptr_t * x);
```

Insert a pointer into a heap in logarithmic time. The return value indicates, whether the operation was successful. Therefore, it is safe to call this function, if the heap is full.

```c
bool ao_heap4ptr_insert(ao_heap4ptr_t * x, void * p);
```

Check whether a heap is empty or full, respectively, in constant time.

```c
#define ao_heap4ptr_is_empty(x)
#define ao_heap4ptr_is_full(x)
```

Get the root pointer of a heap without removing it in constant time. The return value indicates, whether the operation was successful. Therefore, it is safe to call this function, if the heap is empty.

```c
bool ao_heap4ptr_peek(ao_heap4ptr_t const * x, void ** p);
```

Remove the root pointer from a heap in logarithmic time. The return value indicates, whether the operation was successful. Therefore, it is safe to call this function, if the heap is empty.

```c
bool ao_heap4ptr_pop(ao_heap4ptr_t * x, void ** p);
```

# Usage

A heap can be initialized by clearing all of its members.

```c
ao_heap4ptr_t * h;
```

```c
h->capacity = 0;
h->count = 0;
h->count_max = 0;
h->heap1 = NULL;
h->heap2 = NULL;
h->less = NULL;
h->less_parameter = NULL;
h->store = NULL;
```

However, such a heap is not very useful, since it cannot contain a single pointer. Therefore, it should be equipped with a store and two index buffers.

```c
size_t heap1[128];
size_t heap2[128];
void * store[128];
```

```c
h->capacity = 128;
h->heap1 = heap1;
h->heap2 = heap2;
h->store = store;
```

Also, prior to inserting pointers, a compare function must be set.

```c
bool compare(void * p1, void * p2, void * p)
{
    if (/* p1 is less than p2 */)
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

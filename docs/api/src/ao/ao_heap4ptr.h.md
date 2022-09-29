---
author: "Stefan Wagner"
date: 2022-09-28
draft: true
external:
- https://en.wikipedia.org/wiki/Binary_heap : "Binary heap"
- https://en.wikipedia.org/wiki/Binary_tree : "Binary tree"
- https://en.wikipedia.org/wiki/Priority_queue : "Priority queue"
- https://en.wikipedia.org/wiki/Total_order : "Total order"
permalink: /api/src/ao/ao_heap4ptr.h/
toc: true
---

# Notes

This module defines binary heaps for pointers. A binary heap is a special kind of binary tree that maintains both the shape of a complete binary tree and the heap property. The latter implies, that a node is always less than its children, with respect to a strict total order. Both insertion into and removal from heaps take logarithmic time. This makes them a perfect choice for implementing priority queues.

This module provides an array-based implementation.

# Include

| `stdbool.h` |
| `stddef.h` |

# Configuration

## `AO_HEAP4PTR_COUNT_MAX`

```c
#define AO_HEAP4PTR_COUNT_MAX (false)
```

Defines whether to keep track of the maximum number of pointers.

# Types

## `ao_heap4ptr_t`

```c
typedef struct ao_heap4ptr_t ao_heap4ptr_t;
```

Represents a heap for pointers.

## `ao_heap4ptr_less_t`

```c
typedef bool (* ao_heap4ptr_less_t)
(
    void * pointer1,
    void * pointer2,
    void * parameter
);
```

| `pointer1` | The first pointer. |
| `pointer2` | The second pointer. |
| `parameter` | An additional parameter. |

Represents a compare function for pointers, that implements a strict total order. The function returns `true`, if the first pointer is strictly less than the second pointer, otherwise `false`.

# Structs

## `ao_heap4ptr_t`

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

| `capacity` | The maximum number of pointers that can be stored in the heap. |
| `count` | The current number of pointers stored in the heap. |
| `count_max` | The maximum number of pointers stored in the heap. |
| `heap1` | The first index buffer. |
| `heap2` | The second index buffer. |
| `less` | The compare function. |
| `less_parameter` | The compare function parameter. |
| `store` | The store. |

# Functions

## `ao_heap4ptr_assert`

```c
void ao_heap4ptr_assert(ao_heap4ptr_t const * h);
```

Asserts the correctness of a heap,s in linear time. This function traverses the heap top-down and checks, whether both the heap condition and the shape of a complete binary tree are maintained. If that is not the case, the function triggers a runtime assertion failure.

## `ao_heap4ptr_insert`

```c
bool ao_heap4ptr_insert(ao_heap4ptr_t * h, void * p);
```

Inserts a pointer into a heap, in logarithmic time. The return value indicates, whether the operation was successful. Therefore, it is safe to call this function, if the heap is full.

## `ao_heap4ptr_is_empty`
## `ao_heap4ptr_is_full`

```c
bool ao_heap4ptr_is_empty(ao_heap4ptr_t const * h);
bool ao_heap4ptr_is_full (ao_heap4ptr_t const * h);
```

Checks whether a heap is empty or full, respectively, in constant time.

## `ao_heap4ptr_peek`

```c
bool ao_heap4ptr_peek(ao_heap4ptr_t const * h, void ** p);
```

Gets the root pointer of a heap without removing it, in constant time. The return value indicates, whether the operation was successful. Therefore, it is safe to call this function, if the heap is empty.

## `ao_heap4ptr_pop`

```c
bool ao_heap4ptr_pop(ao_heap4ptr_t * h, void ** p);
```

Removes the root pointer from a heap, in logarithmic time. The return value indicates, whether the operation was successful. Therefore, it is safe to call this function, if the heap is empty.

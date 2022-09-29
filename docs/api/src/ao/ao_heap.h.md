---
author: "Stefan Wagner"
date: 2022-09-28
draft: true
external:
- https://en.wikipedia.org/wiki/Binary_heap : "Binary heap"
- https://en.wikipedia.org/wiki/Binary_tree : "Binary tree"
- https://en.wikipedia.org/wiki/Priority_queue : "Priority queue"
- https://en.wikipedia.org/wiki/Total_order : "Total order"
permalink: /api/src/ao/ao_heap.h/
toc: true
---

# Notes

This module defines binary heaps. A binary heap is a special kind of binary tree that maintains both the shape of a complete binary tree and the heap property. The latter implies, that a node is always less than its children, with respect to a strict total order. Both insertion into and removal from heaps take logarithmic time. This makes them a perfect choice for implementing priority queues.

Commonly, heaps are implemented based on an array that stores all the nodes. However, this module provides a pointer-based implementation, that is, each node holds pointers to its parent and children. Therefore, the capacity of a heap is virtually unbounded. This is useful, for example, if the maximum number of nodes cannot be estimated well.

# Include

| [`ao_uint.h`](ao_uint.h.md) |
| `stdbool.h` |
| `stddef.h` |

# Configuration

## `AO_HEAP_COUNT_MAX`

```c
#define AO_HEAP_COUNT_MAX (false)
```

Defines whether to keep track of the maximum number of nodes.

# Types

## `ao_heap_t`

```c
typedef struct ao_heap_t ao_heap_t;
```

Represents a heap.

## `ao_heap_node_t`

```c
typedef struct ao_heap_node_t ao_heap_node_t;
```

Represents a heap node.

## `ao_heap_less_t`

```c
typedef bool (* ao_heap_less_t)
(
    ao_heap_node_t const * node1,
    ao_heap_node_t const * node2,
    void *                 parameter
);
```

| `node1` | The first node. |
| `node2` | The second node. |
| `parameter` | An additional parameter. |

Represents a compare function for heap nodes, that implements a strict total order. The function returns `true`, if the first node is strictly less than the second node, otherwise `false`.

# Structs

## `ao_heap_t`

```c
struct ao_heap_t
{
    ao_uint_t        count;

#if AO_HEAP_COUNT_MAX

    ao_uint_t        count_max;

#endif

    ao_heap_less_t   less;
    void *           less_parameter;
    ao_heap_node_t * root;
};
```

| `count` | The current number of nodes. |
| `count_max` | The maximum number of nodes. |
| `less` | The compare function. |
| `less_parameter` | The compare function parameter. |
| `root` | The root node. |

## `ao_heap_node_t`

```c
struct ao_heap_node_t
{
    ao_heap_node_t * left;
    ao_heap_node_t * parent;
    ao_heap_node_t * right;
};
```

| `left` | The left child node. |
| `parent` | The parent node. |
| `right` | The right child node. |

# Functions

## `ao_heap_assert`

```c
void ao_heap_assert(ao_heap_t const * h);
```

Asserts the correctness of a heap, in linear time. This function traverses the heap top-down and checks, whether both the heap condition and the shape of a complete binary tree are maintained. If that is not the case, the function triggers a runtime assertion failure. It is therefore useful in debugging scenarios. However, the function is implemented recursively, which violates a common rule in embedded software engineering.

## `ao_heap_insert`

```c
void ao_heap_insert(ao_heap_t * h, ao_heap_node_t * n);
```

Inserts a node into a heap, in logarithmic time.

## `ao_heap_is_empty`

```c
bool ao_heap_is_empty(ao_heap_t const * h);
```

Checks whether a heap is empty, in constant time.

## `ao_heap_peek`

```c
ao_heap_node_t * ao_heap_peek(ao_heap_t const * h);
```

Gets the root node of a heap without removing it, in constant time.

## `ao_heap_pop`

```c
ao_heap_node_t * ao_heap_pop(ao_heap_t * h);
```

Removes the root node from a heap, in logarithmic time.

## `ao_heap_remove`

```c
void ao_heap_remove(ao_heap_t * h, ao_heap_node_t * n);
```

Removes an arbitrary node from a heap, in logarithmic time.

---
author: "Stefan Wagner"
date: 2022-09-27
draft: true
external:
- https://en.wikipedia.org/wiki/AVL_tree : "AVL tree"
- https://en.wikipedia.org/wiki/Binary_search_tree : "Binary search tree"
- https://en.wikipedia.org/wiki/Priority_queue : "Priority queue"
- https://en.wikipedia.org/wiki/Self-balancing_binary_search_tree : "Self-balancing binary search tree"
- https://en.wikipedia.org/wiki/Total_order : "Total order"
permalink: /api/src/ao/ao_avl.h/
toc: true
---

# Notes

This module defines AVL trees. An AVL tree is a special kind of binary search tree, that keeps itself balanced, which guarantees that insertion, removal, and search always take logarithmic time. It is therefore a perfect choice when implementing a priority queue.

# Include

| [`ao_int.h`](ao_int.h.md) |
| `stdbool.h` |
| `stddef.h` |

# Types

## `ao_avl_t`

```c
typedef struct ao_avl_t ao_avl_t;
```

Represents an AVL tree.

## `ao_avl_node_t`

```c
typedef struct ao_avl_node_t ao_avl_node_t;
```

Represents an AVL tree node.

## `ao_avl_less_t`

```c
typedef bool (* ao_avl_less_t)
(
    ao_avl_node_t const * node1,
    ao_avl_node_t const * node2,
    void                * parameter
);
```

| `node1` | The first node. |
| `node2` | The second node. |
| `parameter` | An additional parameter. |

Represents a compare function for AVL tree nodes, that implements a strict total order. The function returns `true`, if the first node is strictly less than the second node, otherwise `false`.

# Structs

## `ao_avl_t`

```c
struct ao_avl_t
{
    ao_avl_less_t   less;
    void          * less_parameter;
    ao_avl_node_t * root;
};
```

| `less` | The compare function. |
| `less_parameter` | The compare function parameter. |
| `root` | The root. |

## `ao_avl_node_t`

```c
struct ao_avl_node_t
{
    ao_int_t        height;
    ao_avl_node_t * left;
    ao_avl_node_t * parent;
    ao_avl_node_t * right;
};
```

| `height` | The height of the node, that is, the length of the longest path from the node downwards to a leaf. Although a node's height is always positive, this member is a signed integer. This is, because the heights of a node's children are used to calculate its balance factor, which can be negative. |
| `left` | The left child. |
| `parent` | The parent. |
| `right` | The right child. |

# Functions

## `ao_avl_assert`

```c
void ao_avl_assert(ao_avl_t const * avl);
```

Checks whether a tree is valid, in linear time. This function traverses the tree top-down and checks, whether the relevant properties are maintained. If that is not the case, the function triggers a runtime assertion failure. It is therefore useful in debugging scenarios. However, the function is implemented recursively, which violates a common rule in embedded software engineering.

## `ao_avl_insert`

```c
void ao_avl_insert(ao_avl_t * avl, ao_avl_node_t * node);
```

Inserts a node into a tree, in logarithmic time.

## `ao_avl_is_empty`

```c
bool ao_avl_is_empty(ao_avl_t const * x);
```

Checks whether a tree is empty, in constant time.

## `ao_avl_max`
## `ao_avl_min`

```c
ao_avl_node_t * ao_avl_max(ao_avl_t const * avl);
ao_avl_node_t * ao_avl_min(ao_avl_t const * avl);
```

Gets the maximum or minimum node, respectively, of a tree, in logarithmic time. Thereby, the maximum node is the rightmost node and the minimum node is the leftmost node in the tree. Both functions return `NULL`, if the tree is empty.

## `ao_avl_remove`

```c
void ao_avl_remove(ao_avl_t * avl, ao_avl_node_t * node);
```

Removes a node from a tree, in logarithmic time.

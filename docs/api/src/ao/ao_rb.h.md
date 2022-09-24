---
author: "Stefan Wagner"
date: 2022-09-24
draft: true
external:
- https://en.wikipedia.org/wiki/Binary_search_tree : "Binary search tree"
- https://en.wikipedia.org/wiki/Priority_queue : "Priority queue"
- https://en.wikipedia.org/wiki/Red–black_tree : "Red-black tree"
- https://en.wikipedia.org/wiki/Self-balancing_binary_search_tree : "Self-balancing binary search tree"
- https://en.wikipedia.org/wiki/Total_order : "Total order"
permalink: /api/src/ao/ao_rb.h/
toc: true
---

# Notes

This module defines red-black trees.

A red-black tree is a special kind of binary search tree, that keeps itself balanced, which guarantees that insertion, removal, and search always take logarithmic time. It is therefore a perfect choice when implementing a priority queue.

# Include

```c
#include <stdbool.h>
#include <stddef.h>
```

# Identifier

```c
#define AO_RB
```

# Types

## `ao_rb_t`

```c
typedef struct ao_rb_t ao_rb_t;
```

This type represents a red-black tree.

## `ao_rb_node_t`

```c
typedef struct ao_rb_node_t ao_rb_node_t;
```

This type represents a red-black tree node.

## `ao_rb_less_t`

```c
typedef bool (* ao_rb_less_t)
(
    ao_rb_node_t * n1,
    ao_rb_node_t * n2,
    void         * parameter
);
```

This type represents a compare function, that implements a strict total order on the nodes.

# Structs

## `ao_rb_t`

```c
struct ao_rb_t
{
    ao_rb_less_t   less;
    void         * less_parameter;
    ao_rb_node_t * root;
};
```

| `less` | The compare function. |
| `less_parameter` | The compare function parameter. |
| `root` | The root. |

## `ao_rb_node_t`

```c
struct ao_rb_node_t
{
    bool           black;
    ao_rb_node_t * left;
    ao_rb_node_t * parent;
    ao_rb_node_t * right;
};
```

| `black` | Indicates whether the node is black (`true`) or red (`false`). |
| `left` | The left child. |
| `parent` | The parent. |
| `right` | The right child. |

# Functions

## `ao_rb_assert`

```c
void ao_rb_assert(ao_rb_t * x);
```

Checks whether a tree is valid, in linear time. This function traverses the tree top-down and checks, whether the relevant properties are maintained. If that is not the case, the function triggers a runtime assertion failure.

It is therefore useful in debugging scenarios. However, the function is implemented recursively, which violates a common rule in embedded software engineering.

## `ao_rb_insert`

```c
void ao_rb_insert(ao_rb_t * x, ao_rb_node_t * n);
```

Inserts a node into a tree, in logarithmic time.

## `ao_rb_is_empty`

```c
#define ao_rb_is_empty(x) \
(                         \
    (x)->root == NULL     \
    ? true                \
    : false               \
)
```

Checks whether a tree is empty, in constant time.

## `ao_rb_max`
## `ao_rb_min`

```c
ao_rb_node_t * ao_rb_max(ao_rb_t * x);
ao_rb_node_t * ao_rb_min(ao_rb_t * x);
```

Gets the maximum or minimum node, respectively, of a tree, in logarithmic time. Thereby, the maximum node is the rightmost node and the minimum node is the leftmost node in the tree. Both functions return `NULL`, if the tree is empty.

## `ao_rb_remove`

```c
void ao_rb_remove(ao_rb_t * x, ao_rb_node_t * n);
```

Removes a node from a tree, in logarithmic time.

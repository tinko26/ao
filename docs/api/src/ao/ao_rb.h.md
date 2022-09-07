---
author: "Stefan Wagner"
date: 2022-08-31
draft: false
external:
- https://en.wikipedia.org/wiki/Binary_search_tree : "Binary search tree"
- https://en.wikipedia.org/wiki/Priority_queue : "Priority queue"
- https://en.wikipedia.org/wiki/Red–black_tree : "Red-black tree"
- https://en.wikipedia.org/wiki/Self-balancing_binary_search_tree : "Self-balancing binary search tree"
- https://en.wikipedia.org/wiki/Total_order : "Total order"
permalink: /api/src/ao/ao_rb.h/
toc: true
---

# Overview

This module defines red-black trees.

A red-black tree is a special kind of binary search tree, that keeps itself balanced, which guarantees that insertion, removal, and search always take logarithmic time. It is therefore a perfect choice when implementing a priority queue.

# Include

```c
#include <stdbool.h>
#include <stddef.h>
```

# Typedefs

```c
typedef struct ao_rb_t      ao_rb_t;
```

```c
typedef struct ao_rb_node_t ao_rb_node_t;
```

```c
typedef bool (* ao_rb_less_t)
(
ao_rb_node_t * n1,
ao_rb_node_t * n2,
void         * parameter
);
```

# Types

## `ao_rb_t`

This type represents a red-black tree.

```c
struct ao_rb_t
{
ao_rb_less_t   less;
void         * less_parameter;
ao_rb_node_t * root;
};
```

It consists of the following members.

| `less` | The compare function. |
| `less_parameter` | The compare function parameter. |
| `root` | The root. |

## `ao_rb_node_t`

This type represents a red-black tree node.

```c
struct ao_rb_node_t
{
bool           black;
ao_rb_node_t * left;
ao_rb_node_t * parent;
ao_rb_node_t * right;
};
```

It consists of the following members.

| `black` | Indicates whether the node is black (`true`) or red (`false`). |
| `left` | The left child. |
| `parent` | The parent. |
| `right` | The right child. |

## `ao_rb_less_t`

This type represents a compare function, that implements a strict total order on the nodes.

# Functions

Check whether a tree is valid in linear time. This function traverses the tree top-down and checks, whether the relevant properties are maintained. If that is not the case, the function triggers a runtime assertion failure.

It is therefore useful in debugging scenarios. However, the function is implemented recursively, which violates a common rule in embedded software engineering.

```c
void ao_rb_assert(ao_rb_t * x);
```

Insert a node into a tree in logarithmic time.

```c
void ao_rb_insert(ao_rb_t * x, ao_rb_node_t * n);
```

Check whether a tree is empty in constant time.

```c
#define ao_rb_is_empty(x)
```

Get the maximum or minimum node, respectively, of a tree in logarithmic time. Thereby, the maximum node is the rightmost node and the minimum node is the leftmost node in the tree. Both functions return `NULL`, if the tree is empty.

```c
ao_rb_node_t * ao_rb_max(ao_rb_t * x);
ao_rb_node_t * ao_rb_min(ao_rb_t * x);
```

Remove a node from a tree in logarithmic time.

```c
void ao_rb_remove(ao_rb_t * x, ao_rb_node_t * n);
```

# Usage

Trees and nodes must be initialized prior to being used. A node can be initialized by clearing all of its members.

```c
ao_rb_node_t * n;
```

```c
n->black = false;
n->left = NULL;
n->parent = NULL;
n->right = NULL;
```

A tree can be initialized by clearing all of its members, too.

```c
ao_rb_t * r;
```

```c
r->less = NULL;
r->less_parameter = NULL;
r->root = NULL;
```

However, prior to inserting nodes, a compare function must be set.

```c
bool compare(ao_rb_node_t * n1, ao_rb_node_t * n2, void * p)
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
r->less = compare;
```

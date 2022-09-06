---
author: "Stefan Wagner"
date: 2022-08-31
draft: false
permalink: /api/src/ao/ao_avl.h/
toc: true
wiki:
- avl-tree
- binary-search-tree
- priority-queue
- self-balancing-binary-search-tree
- total-order
---

# Overview

This module defines AVL trees.

An AVL tree is a special kind of binary search tree, that keeps itself balanced, which guarantees that insertion, removal, and search always take logarithmic time. It is therefore a perfect choice when implementing a priority queue.

# Include

```c
#include <ao_int.h>
#include <stdbool.h>
#include <stddef.h>
```

# Typedefs

```c
typedef struct ao_avl_t      ao_avl_t;
```

```c
typedef struct ao_avl_node_t ao_avl_node_t;
```

```c
typedef bool (* ao_avl_less_t)
(
    ao_avl_node_t * n1,
    ao_avl_node_t * n2,
    void          * parameter
);
```

# Types

## `ao_avl_t`

This type represents an AVL tree.

```c
struct ao_avl_t
{
    ao_avl_less_t   less;
    void          * less_parameter;
    ao_avl_node_t * root;
};
```

It consists of the following members.

| `less` | The compare function. |
| `less_parameter` | The compare function parameter. |
| `root` | The root. |

## `ao_avl_node_t`

This type represents an AVL tree node.

```c
struct ao_avl_node_t
{
    ao_int_t        height;
    ao_avl_node_t * left;
    ao_avl_node_t * parent;
    ao_avl_node_t * right;
};
```

It consists of the following members.

| `height` | The height of the node, that is, the length of the longest path from the node downwards to a leaf. |
| `left` | The left child. |
| `parent` | The parent. |
| `right` | The right child. |

Although a node's height is always positive, the `height` member is a signed integer. This is, because the heights of a node's children are used to calculate its balance factor, which can be negative.

## `ao_avl_less_t`

This type represents a compare function, that implements a strict total order on the nodes.

# Functions

Check whether a tree is valid in linear time. This function traverses the tree top-down and checks, whether the relevant properties are maintained. If that is not the case, the function triggers a runtime assertion failure.

It is therefore useful in debugging scenarios. However, the function is implemented recursively, which violates a common rule in embedded software engineering.

```c
void ao_avl_assert(ao_avl_t * x);
```

Insert a node into a tree in logarithmic time.

```c
void ao_avl_insert(ao_avl_t * x, ao_avl_node_t * n);
```

Check whether a tree is empty in constant time.

```c
#define ao_avl_is_empty(x)
```

Get the maximum or minimum node, respectively, of a tree in logarithmic time. Thereby, the maximum node is the rightmost node and the minimum node is the leftmost node in the tree. Both functions return `NULL`, if the tree is empty.

```c
ao_avl_node_t * ao_avl_max(ao_avl_t * x);
ao_avl_node_t * ao_avl_min(ao_avl_t * x);
```

Remove a node from a tree in logarithmic time.

```c
void ao_avl_remove(ao_avl_t * x, ao_avl_node_t * n);
```

# Usage

Trees and nodes must be initialized prior to being used. A node can be initialized by clearing all of its members.

```c
ao_avl_node_t * n;
```

```c
n->height = 0;
n->left = NULL;
n->parent = NULL;
n->right = NULL;
```

A tree can be initialized by clearing all of its members, too.

```c
ao_avl_t * a;
```

```c
a->less = NULL;
a->less_parameter = NULL;
a->root = NULL;
```

However, prior to inserting nodes, a compare function must be set.

```c
bool compare(ao_avl_node_t * n1, ao_avl_node_t * n2, void * p)
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
a->less = compare;
```

---
author: "Stefan Wagner"
date: 2022-08-04
description: "The ao_avl.h module of the ao real-time operating system."
draft: false
permalink: /modules/avl/
title: "ao_avl.h"
---

# Overview

This module defines AVL trees. 

An AVL tree is a special kind of binary search tree, that keeps itself balanced, which guarantees that insertion, removal, and search always take logarithmic time. It is therefore a perfect choice when implementing a priority queue.

## Types

### Tree

The `ao_avl_t` type represents an AVL tree.

```c
struct ao_avl_t
{
    ao_avl_less_t   less;
    void *          less_parameter;
    ao_avl_node_t * root;
};
```

It consists of the following members.

| Member | |
|--------|-|
| `less` | The compare function. |
| `less_parameter` | The compare function parameter. |
| `root` | The root. |

### Node

The `ao_avl_node_t` type represents an AVL tree node.

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

| Member | |
|--------|-|
| `height` | The height of the node, that is, the length of the longest path from the node downwards to a leaf. |
| `left` | The left child. |
| `parent` | The parent. |
| `right` | The right child. |

Although a node's height is always positive, the `height` member is a signed integer. This is, because the heights of a node's children are used to calculate its balance factor, which can be negative.

### Compare Function

The `ao_avl_less_t` type represents a compare function, that implements a strict total order on the nodes.

```c
typedef bool (* ao_avl_less_t)
(
    ao_avl_node_t * n1,
    ao_avl_node_t * n2,
    void *          parameter
);
```

## Initialization

A node can be initialized by clearing all of its members.

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

## Functions

If the root is clear, then the tree is empty. This can be checked with a macro function.

```c
if (ao_avl_is_empty(a))
{
    // Tree is empty.
}
```

The minimum or maximum node, respectively, can be retrieved in logarithmic time. Both functions return `NULL`, if the tree is empty.

```c
n = ao_avl_min(a);
n = ao_avl_max(a);
```

Inserting a node takes logarithmic time.

```c
ao_avl_insert(a, n);
```

Removing a node takes logarithmic time, too.

```c
ao_avl_remove(a, n);
```

The correctness of a tree can be asserted in linear time. The function traverses the tree top-down and checks, whether the relevant properties are maintained. If that is not the case, the function triggers a runtime [assertion](../assertions.md) failure.

It is therefore useful in debugging scenarios. However, the function is implemented recursively, which violates a common rule in embedded software engineering.

```c
ao_avl_assert(a);
```

## External Links

[https://en.wikipedia.org/wiki/AVL_tree](https://en.wikipedia.org/wiki/AVL_tree)

[https://en.wikipedia.org/wiki/Binary_search_tree](https://en.wikipedia.org/wiki/Binary_search_tree)

[https://en.wikipedia.org/wiki/Priority_queue](https://en.wikipedia.org/wiki/Priority_queue)

[https://en.wikipedia.org/wiki/Self-balancing_binary_search_tree](https://en.wikipedia.org/wiki/Self-balancing_binary_search_tree)

[https://en.wikipedia.org/wiki/Total_order](https://en.wikipedia.org/wiki/Total_order)

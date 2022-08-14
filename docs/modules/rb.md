---
author: "Stefan Wagner"
date: 2022-08-14
description: ""
draft: true
permalink: /modules/rb/
title: "ao_rb.h"
---

# ao_rb.h

This module defines [red-black trees](https://en.wikipedia.org/wiki/Red%E2%80%93black_tree).

A red-black tree is a special kind of [binary search tree](https://en.wikipedia.org/wiki/Self-balancing_binary_search_tree), that keeps itself balanced, which guarantees that insertion, removal, and search always take logarithmic time. It is therefore a perfect choice when implementing a [priority queue](https://en.wikipedia.org/wiki/Priority_queue).

## Types

### Tree

The `ao_rb_t` type represents a red-black tree.

```c
struct ao_rb_t
{
    ao_rb_less_t   less;
    void *         less_parameter;
    ao_rb_node_t * root;
};
```

It consists of the following members.

| Member | |
|--------|-|
| `less` | The compare function. |
| `less_parameter` | The compare function parameter. |
| `root` | The root. |

### Node

The `ao_rb_node_t` type represents a red-black tree node.

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

| Member | |
|--------|-|
| `black` | Indicates whether the node is black (`true`) or red (`false`). |
| `left` | The left child. |
| `parent` | The parent. |
| `right` | The right child. |

### Compare Function

The `ao_rb_less_t` type represents a compare function, that implements a [strict total order](https://en.wikipedia.org/wiki/Total_order) on the nodes.

```c
typedef bool (* ao_rb_less_t)
(
    ao_rb_node_t * n1,
    ao_rb_node_t * n2,
    void *         parameter
);
```

## Initialization

A node can be initialized by clearing all of its members.

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

## Functions

If the root is clear, then the tree is empty. This can be checked with a macro function.

```c
if (ao_rb_is_empty(r))
{
    // Tree is empty.
}
```

The minimum or maximum node, respectively, can be retrieved in logarithmic time. Both functions return `NULL`, if the tree is empty.

```c
n = ao_rb_min(r);
n = ao_rb_max(r);
```

Inserting a node takes logarithmic time.

```c
ao_rb_insert(r, n);
```

Removing a node takes logarithmic time, too.

```c
ao_rb_remove(r, n);
```

The correctness of a tree can be asserted in linear time. The function traverses the tree top-down and checks, whether the relevant properties are maintained. If that is not the case, the function triggers a runtime [assertion](assert.md) failure.

It is therefore useful in debugging scenarios. However, the function is implemented recursively, which violates a common rule in embedded software engineering.

```c
ao_rb_assert(r);
```

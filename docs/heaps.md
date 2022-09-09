---
author: "Stefan Wagner"
date: 2022-09-09
draft: true
external:
- https://en.wikipedia.org/wiki/Binary_heap : "Binary heap"
- https://en.wikipedia.org/wiki/Binary_tree : "Binary tree"
- https://en.wikipedia.org/wiki/Priority_queue : "Priority queue"
- https://en.wikipedia.org/wiki/Total_order : "Total order"
groups:
- priority-queues
permalink: /heaps/
seealso:
- /api/src/ao/ao_heap.h/
toc: true
---

# Overview

A binary heap is a special kind of binary tree that maintains both the shape of a complete binary tree and the heap property. The latter implies, that a node is always less than its children, with respect to a strict total order.

Both insertion into and removal from heaps take logarithmic time. This makes them a perfect choice for implementing priority queues.

# Usage

A heap node can be initialized by clearing all of its members.

```c
ao_heap_node_t * n;
```

```c
n->left = NULL;
n->parent = NULL;
n->right = NULL;
```

A heap can be initialized by clearing all of its members, too.

```c
ao_heap_t * h;
```

```c
h->count = 0;
h->count_max = 0;
h->less = NULL;
h->less_parameter = NULL;
h->root = NULL;
```

However, prior to inserting nodes, a compare function must be set.

```c
bool compare(ao_heap_node_t * n1, ao_heap_node_t * n2, void * p)
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
h->less = compare;
```

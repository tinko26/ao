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
permalink: /heaps-for-objects/
seealso:
- /api/src/ao/ao_heap4obj.h/
toc: true
---

# Overview

A binary heap is a special kind of binary tree that maintains both the shape of a complete binary tree and the heap property. The latter implies, that a node is always less than its children, with respect to a strict total order.

Both insertion into and removal from heaps take logarithmic time. This makes them a perfect choice for implementing priority queues.

# Usage

A heap can be initialized by clearing all of its members.

```c
ao_heap4obj_t * h;
```

```c
h->capacity = 0;
h->count = 0;
h->count_max = 0;
h->heap1 = NULL;
h->heap2 = NULL;
h->less = NULL;
h->less_parameter = NULL;
h->size = 0;
h->store = NULL;
```

However, such a heap is not very useful, since it cannot contain a single object. Therefore, it should be equipped with a store and two index buffers.

```c
size_t heap1[128];
size_t heap2[128];
double store[128];
```

```c
h->capacity = 128;
h->heap1 = heap1;
h->heap2 = heap2;
h->store = store;
```

Also, the object size must be set appropriately.

```c
h->size = sizeof(double);
```

Finally, prior to inserting objects, a compare function must be set.

```c
bool compare(void * p1, void * p2, void * p)
{
    double d1 = *((double *) p1);
    double d2 = *((double *) p2);

    return d1 < d2 ? true : false;
}
```

```c
h->less = compare;
```

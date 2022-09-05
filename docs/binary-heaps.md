---
author: "Stefan Wagner"
date: 2022-08-15
description: "Binary heaps in the ao real-time operating system."
draft: false
groups:
- "priority_queues"
permalink: /binary-heaps/
toc: false
wiki:
- title: "Binary heap"
  url: https://en.wikipedia.org/wiki/Binary_heap
- title: "Binary tree"
  url: https://en.wikipedia.org/wiki/Binary_tree
- title: "Priority queue"
  url: https://en.wikipedia.org/wiki/Priority_queue
- title: "Total order"
  url: https://en.wikipedia.org/wiki/Total_order
---

A binary heap is a special kind of binary tree that maintains both the shape of a complete binary tree and the heap property. The latter implies, that a node is always less than its children, with respect to a strict total order.

Both insertion into and removal from heaps take logarithmic time. This makes them a perfect choice for implementing priority queues.

The following modules implement binary heaps.

| [`ao_heap.h`](api/src/ao/ao_heap.h.md) | Pointer-based binary heaps |
| [`ao_heap4obj.h`](api/src/ao/ao_heap4obj.h.md) | Array-based binary heaps for fixed-size objects |
| [`ao_heap4ptr.h`](api/src/ao/ao_heap4ptr.h.md) | Array-based binary heaps for pointers |

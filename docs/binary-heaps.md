---
author: "Stefan Wagner"
date: 2022-08-15
description: "Binary heaps in the ao real-time operating system."
draft: false
permalink: /binary-heaps/
title: "Binary Heaps"
---

# Binary Heaps

A binary heap is a special kind of binary tree that maintains both the shape of a complete binary tree and the heap property. The latter implies, that a node is always less than its children, with respect to a strict total order.

Both insertion into and removal from heaps take logarithmic time. This makes them a perfect choice for implementing priority queues.

The following modules implement binary heaps.

| Module | |
|--------|-|
| [`ao_heap.h`](modules/heap.md) | Pointer-based binary heaps. |
| [`ao_heap4obj.h`](modules/heap4obj.md) | Array-based binary heaps for fixed-size objects. |
| [`ao_heap4ptr.h`](modules/heap4ptr.md) | Array-based binary heaps for pointers. |

# External Links

[https://en.wikipedia.org/wiki/Binary_heap](https://en.wikipedia.org/wiki/Binary_heap)

[https://en.wikipedia.org/wiki/Binary_tree](https://en.wikipedia.org/wiki/Binary_tree)

[https://en.wikipedia.org/wiki/Priority_queue](https://en.wikipedia.org/wiki/Priority_queue)

[https://en.wikipedia.org/wiki/Total_order](https://en.wikipedia.org/wiki/Total_order)

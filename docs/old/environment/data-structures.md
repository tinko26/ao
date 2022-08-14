---
author: "Stefan Wagner"
date: 2022-08-13
description: ""
draft: false
permalink: /environment/data-structures/
title: "Data Structures"
---

# Data Structures

The following modules define data structures, that are required by a lot of kernel functions, such as the [alarm queue](../kernel/alarm-queue.md) or the [task scheduler](../kernel/task-sched.md).

| Module | |
|--------|-|
| [`ao_avl.h`](avl.md) | AVL trees. |
| [`ao_buffer.h`](buffer.md) | Buffers for arbitrary data. |
| [`ao_buffer4obj.h`](buffer4obj.md) | Buffers for fixed-size objects. |
| [`ao_buffer4ptr.h`](buffer4ptr.md) | Buffers for pointers. |
| [`ao_heap.h`](heap.md) | Pointer-based binary heaps. |
| [`ao_heap4obj.h`](heap4obj.md) | Array-based binary heaps for fixed-size objects. |
| [`ao_heap4ptr.h`](heap4ptr.md) | Array-based binary heaps for pointers. |
| [`ao_list.h`](list.md) | Doubly linked lists. |
| [`ao_rb.h`](rb.md) | Red-black trees. |
| [`ao_slist.h`](slist.md) | Doubly linked sorted lists. |

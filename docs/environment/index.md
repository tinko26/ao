---
author: "Stefan Wagner"
date: 2022-08-10
description: "The Environment Package of the ao Real-Time Operating System (RTOS)."
draft: false
permalink: /environment/
title: "Environment"
---

# Environment

The environment [package](../code/index.md#packages) is an extension to a freestanding runtime environment. It contains miscellaneous essential modules that are to support both the [kernel](../kernel/index.md) and [port](../port/index.md) packages as well as embedded applications in their entirety.

| Module | |
|--------|-|
| [`ao_align.h`](align.md) | Memory alignment. |
| [`ao_assert.h`](assert.md) | Defines a macro function, that executes a runtime assertion. |
| [`ao_avl.h`](avl.md) | Defines AVL trees. |
| [`ao_break.h`](break.md) | Defines a function, that executes a breakpoint. |
| [`ao_buffer.h`](buffer.md) | Defines buffers. |
| [`ao_buffer4obj.h`](buffer4obj.md) | Defines buffers for fixed-size objects. |
| [`ao_buffer4ptr.h`](buffer4ptr.md) | Defines buffers for pointers. |
| [`ao_char.h`](char.md) | Contains functions to classify characters. |
| [`ao_debug.h`](debug.md) | Defines a macro constant, that indicates, whether an application is running in debug mode. |
| [`ao_float.h`](float.md) | Defines the fastest floating-point type of the target platform and a couple of mathematical operations for that type. |
| [`ao_func.h`](func.md) | Defines general-purpose function types. |
| [`ao_heap.h`](heap.md) | Defines pointer-based binary heaps. |
| [`ao_heap4obj.h`](heap4obj.md) | Defines array-based binary heaps for fixed-size objects. |
| [`ao_heap4ptr.h`](heap4ptr.md) | Defines array-based binary heaps for pointers. |
| [`ao_int.h`](int.md) | Defines the fastest signed integer type of the target platform. |
| [`ao_lfsr.h`](lfsr.md) | Defines linear-feedback shift registers, that can be used to generate pseudo-random numbers. |
| [`ao_list.h`](list.md) | Defines doubly-linked lists. |
| [`ao_math.h`](math.md) | Defines mathematical functions for all arithmetic types. |
| [`ao_mathf.h`](mathf.md) | Defines mathematical functions for floating-point types. |
| [`ao_mem.h`](mem.md) | Defines operations on memory blocks, such as copying or filling. |
| [`ao_print.h`](print.md) | Defines functions to convert a number to a string. |
| [`ao_rand.h`](rand.md) | Defines random value generator types. |
| [`ao_rb.h`](rb.md) | Defines red-black trees. |
| [`ao_scan.h`](scan.md) | Defines functions to convert a string to a number. |
| [`ao_size.h`](size.md) | Defines useful operations for the standard library's `size_t` type. |
| [`ao_slist.h`](slist.md) | Defines doubly-linked sorted lists. |
| [`ao_struct.h`](struct.md) | Defines a macro function supporting compound types such as structs. |
| [`ao_uint.h`](uint.md) | Defines the fastest unsigned integer type of the target platform and a couple of operations for that type. |
| [`ao_var.h`](var.md) | Defines convenience macro functions for working with variables. |

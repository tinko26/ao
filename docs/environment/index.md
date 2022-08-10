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
| [`ao_align.h`](align.md) | Memory [alignment](align.md). |
| `ao_assert.h` | Defines a macro function, that executes a runtime [assertion](assert.md). |
| `ao_avl.h` | Defines [AVL trees](avl.md). |
| `ao_break.h` | Defines a function, that executes a [breakpoint](break.md). |
| `ao_buffer.h` | Defines [buffers](buffer.md). |
| `ao_buffer4obj.h` | Defines [buffers for fixed-size objects](buffer4obj.md). |
| `ao_buffer4ptr.h` | Defines [buffers for pointers](buffer4ptr.md). |
| `ao_char.h` | Contains functions to classify [characters](char.md). |
| `ao_debug.h` | Defines a macro constant, that indicates, whether an application is running in [debug](debug.md) mode. |
| `ao_float.h` | Defines the fastest [floating-point](float.md) type of the target platform and a couple of mathematical operations for that type. |
| `ao_func.h` | Defines general-purpose [function](func.md) types. |
| `ao_heap.h` | Defines pointer-based [binary heaps](heap.md). |
| `ao_heap4obj.h` | Defines array-based [binary heaps for fixed-size objects](heap4obj.md). |
| `ao_heap4ptr.h` | Defines array-based [binary heaps for pointers](heap4ptr.md). |
| `ao_lfsr.h` | Defines [linear-feedback shift registers](lfsr.md), that can be used to generate pseudo-random numbers. |
| `ao_list.h` | Defines doubly-linked [lists](list.md). |
| `ao_math.h` | Defines [mathematical functions](math.md) for all arithmetic types. |
| `ao_mathf.h` | Defines [mathematical functions](mathf.md) for floating-point types. |
| `ao_mem.h` | Defines operations on [memory blocks](mem.md), such as copying or filling. |
| `ao_print.h` | Defines functions to [convert a number to a string](print.md). |
| `ao_rand.h` | Defines [random value generator](rand.md) types. |
| `ao_int.h` | Defines the fastest [signed integer](int.md) type of the target platform. |
| `ao_rb.h` | Defines [red-black trees](rb.md). |
| `ao_scan.h` | Defines functions to [convert a string to a number](scan.md). |
| `ao_size.h` | Defines useful operations for the standard library's [size](size.md) type. |
| `ao_slist.h` | Defines doubly-linked [sorted lists](slist.md). |
| `ao_struct.h` | Defines a macro function supporting compound types such as [structs](struct.md). |
| `ao_uint.h` | Defines the fastest [unsigned integer](uint.md) type of the target platform and a couple of operations for that type. |
| `ao_var.h` | Defines convenience macro functions for working with [variables](var.md). |

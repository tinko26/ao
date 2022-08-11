---
author: "Stefan Wagner"
date: 2022-08-11
description: "The Environment Package of the ao Real-Time Operating System (RTOS)."
draft: false
permalink: /environment/
title: "Environment"
---

# Environment

The environment [package](../code/index.md#packages) is an extension to a freestanding runtime environment. It contains essential modules that are to support both the [kernel](../kernel/index.md) and [port](../port/index.md) packages as well as embedded applications in general.

## Debugging

The following modules support the debugging of an application. Especially, runtime assertions are extensively used throughout the framework.

| Module | |
|--------|-|
| [`ao_assert.h`](assert.md) | Defines a single macro function, that executes a runtime assertion. |
| [`ao_break.h`](break.md) | Defines a single function, that executes a breakpoint. |
| [`ao_debug.h`](debug.md) | Defines a single macro constant, that indicates, whether an application is running in debug mode. |

## Arithmetic Types

Based on the language-defined types, the standard library defines plenty of arithmetic types for specific purposes. The use of these types in embedded applications is strongly encouraged by several industrial coding standards, especially fixed-width integer types. 

Yet, in order to improve platform independency and portability, the environment package defines its own types for floating-point numbers as well as signed and unsigned integers.

| Module | |
|--------|-|
| [`ao_float.h`](float.md) | Defines the fastest floating-point type of the target platform and mathematical operations for that type. |
| [`ao_int.h`](int.md) | Defines the fastest signed integer type of the target platform, along with a couple of properties thereof. |
| [`ao_size.h`](size.md) | Defines properties of and useful operations for the standard library's `size_t` type. Especially, these definitions are required by the allocators. |
| [`ao_uint.h`](uint.md) | Defines the fastest unsigned integer type of the target platform, along with a couple of properties thereof. Additionally, it defines useful operations, such as calculating the base-2 logarithm. |

## Function Pointer Types

Function pointers enable the selection of a thread of execution or callback to be executed at runtime, which is essential for implementing operating system services. The following modules define commonplace function pointer types.

| Module | |
|--------|-|
| [`ao_func.h`](func.md) | Defines general-purpose function types. |
| [`ao_rand.h`](rand.md) | Defines random value generator types. |

## Memory Blocks and Strings

In a hosted runtime environment, the standard library offers a wide range of functions dealing with memory blocks or strings, respectively. However, these functions are not available in a freestanding runtime environment. Therefore, the environment package provides a subset thereof.

| Module | |
|--------|-|
| [`ao_char.h`](char.md) | Provides functions to classify characters. |
| [`ao_mem.h`](mem.md) | Provides functions to copy, move, or fill memory blocks, respectively. |
| [`ao_print.h`](print.md) | Provides functions to convert a number to a string. |
| [`ao_scan.h`](scan.md) | Provides functions to convert a string to a number. |

## Mathematics

Mathematical functions, too, are not part of a freestanding runtime environment and therefore provided by the environment package.

| Module | |
|--------|-|
| [`ao_math.h`](math.md) | Provides mathematical macro functions, that can be used for all scalar types. |
| [`ao_mathf.h`](mathf.md) | Provides mathematical constants and functions for floating-point types. |

## Data Structures

The following modules define data structures, that are required by a lot of kernel functions, such as the alarm queue or the task scheduler.

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

## Miscellaneous

| Module | |
|--------|-|
| [`ao_align.h`](align.md) | Defines macro functions that support the correct alignment of pointers and data. |
| [`ao_lfsr.h`](lfsr.md) | Defines linear-feedback shift registers, that can be used to generate pseudo-random numbers. |
| [`ao_struct.h`](struct.md) | Defines a macro function supporting compound types such as structs. |
| [`ao_var.h`](var.md) | Defines convenience macro functions for working with variables. |

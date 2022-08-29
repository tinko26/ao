---
author: "Stefan Wagner"
date: 2022-08-11
description: "The environment of the ao real-time operating system."
draft: true
permalink: /environment/
title: "Environment"
toc: true
---

# Overview

The environment package is an extension to a freestanding runtime environment. It contains essential modules that are to support both the kernel and port packages as well as embedded applications in general.

# Modules

The environment package contains the following modules.

| [`ao_align.h`](modules/align.md) | Memory alignment |
| [`ao_assert.h`](modules/assert.md) | Runtime assertions |
| [`ao_avl.h`](modules/avl.md) | AVL trees |
| [`ao_break.h`](modules/break.md) | Breakpoints |
| [`ao_buffer.h`](modules/buffer.md) | Buffers |
| [`ao_buffer4obj.h`](modules/buffer4obj.md) | Buffers for objects |
| [`ao_buffer4ptr.h`](modules/buffer4ptr.md) | Buffers for pointers |
| [`ao_char.h`](modules/char.md) | Characters |
| [`ao_debug.h`](modules/debug.md) | Debug mode |
| [`ao_float.h`](modules/float.md) | Floating-point numbers |
| [`ao_func.h`](modules/func.md) | Function pointer types |
| [`ao_heap.h`](modules/heap.md) | Pointer-based heaps |
| [`ao_heap4obj.h`](modules/heap4obj.md) | Array-based heaps for objects |
| [`ao_heap4ptr.h`](modules/heap4ptr.md) | Array-based heaps for pointers |
| [`ao_int.h`](modules/int.md) | Signed integers |
| [`ao_lfsr.h`](modules/lfsr.md) | Linear-feedback shift registers |
| [`ao_list.h`](modules/list.md) | Doubly linked lists |
| [`ao_math.h`](modules/math.md) | Mathematics |
| [`ao_mathf.h`](modules/mathf.md) | Mathematics for floating-point numbers |
| [`ao_mem.h`](modules/mem.md) | Memory blocks |
| [`ao_print.h`](modules/print.md) | Converting numbers to string |
| [`ao_rand.h`](modules/rand.md) | Random value generators |
| [`ao_rb.h`](modules/rb.md) | Red-black trees |
| [`ao_scan.h`](modules/scan.md) | Converting numbers from string |
| [`ao_size.h`](modules/size.md) | Sizes |
| [`ao_slist.h`](modules/slist.md) | Sorted doubly linked lists |
| [`ao_struct.h`](modules/struct.md) | Structs |
| [`ao_uint.h`](modules/uint.md) | Unsigned integers |
| [`ao_var.h`](modules/var.md) | Variables |

# Debugging

The following modules support the debugging of an application. Especially, runtime assertions are extensively used throughout the framework.

| [`ao_assert.h`](modules/assert.md) | Defines a single macro function, that executes a runtime assertion. |
| [`ao_break.h`](modules/break.md) | Defines a single function, that executes a breakpoint. |
| [`ao_debug.h`](modules/debug.md) | Defines a single macro constant, that indicates, whether an application is running in debug mode. |

# Arithmetic Types

Based on the language-defined types, the standard library defines plenty of arithmetic types for specific purposes. The use of these types in embedded applications is strongly encouraged by several industrial coding standards, especially fixed-width integer types. 

Yet, in order to improve platform independency and portability, the environment package defines its own types for floating-point numbers as well as signed and unsigned integers.

| [`ao_float.h`](modules/float.md) | Defines the fastest floating-point type of the target platform and mathematical operations for that type. |
| [`ao_int.h`](modules/int.md) | Defines the fastest signed integer type of the target platform, along with a couple of properties thereof. |
| [`ao_size.h`](modules/size.md) | Defines properties of and useful operations for the standard library's `size_t` type. Especially, these definitions are required by the allocators. |
| [`ao_uint.h`](modules/uint.md) | Defines the fastest unsigned integer type of the target platform, along with a couple of properties thereof. Additionally, it defines useful operations, such as calculating the base-2 logarithm. |

# Function Pointer Types

Using function pointers, a function to be executed can be chosen at runtime rather than compile time. In general, this supports abstraction. The following modules define commonplace function pointer types.

| [`ao_func.h`](modules/func.md) | Defines general-purpose function types. |
| [`ao_rand.h`](modules/rand.md) | Defines random value generator types. |

# Memory Blocks and Strings

In a hosted runtime environment, the standard library offers a wide range of functions dealing with memory blocks and strings. However, these functions are not available in a freestanding runtime environment. Therefore, the environment package provides a subset thereof.

| [`ao_char.h`](modules/char.md) | Provides functions to classify characters. |
| [`ao_mem.h`](modules/mem.md) | Provides functions to copy, move, or fill memory blocks, respectively. |
| [`ao_print.h`](modules/print.md) | Provides functions to convert a number to a string. |
| [`ao_scan.h`](modules/scan.md) | Provides functions to convert a string to a number. |

# Mathematics

Mathematical functions, too, are not part of a freestanding runtime environment and therefore provided by the environment package.

| [`ao_math.h`](modules/math.md) | Provides mathematical macro functions, that can be used for all scalar types. |
| [`ao_mathf.h`](modules/mathf.md) | Provides mathematical constants and functions for floating-point types. |

# Data Structures

The following modules define data structures, that are required by a lot of kernel functions, such as the alarm queue or the task scheduler.

| [`ao_avl.h`](modules/avl.md) | AVL trees. |
| [`ao_buffer.h`](modules/buffer.md) | Buffers for arbitrary data. |
| [`ao_buffer4obj.h`](modules/buffer4obj.md) | Buffers for fixed-size objects. |
| [`ao_buffer4ptr.h`](modules/buffer4ptr.md) | Buffers for pointers. |
| [`ao_heap.h`](modules/heap.md) | Pointer-based binary heaps. |
| [`ao_heap4obj.h`](modules/heap4obj.md) | Array-based binary heaps for fixed-size objects. |
| [`ao_heap4ptr.h`](modules/heap4ptr.md) | Array-based binary heaps for pointers. |
| [`ao_list.h`](modules/list.md) | Doubly linked lists. |
| [`ao_rb.h`](modules/rb.md) | Red-black trees. |
| [`ao_slist.h`](modules/slist.md) | Doubly linked sorted lists. |

# Miscellaneous

| [`ao_align.h`](modules/align.md) | Defines macro functions that support the correct alignment of pointers and data. |
| [`ao_lfsr.h`](modules/lfsr.md) | Defines linear-feedback shift registers, that can be used to generate pseudo-random numbers. |
| [`ao_struct.h`](modules/struct.md) | Defines a macro function supporting compound types such as structs. |
| [`ao_var.h`](modules/var.md) | Defines convenience macro functions for working with variables. |

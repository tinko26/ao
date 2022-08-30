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

| [`ao_align.h`](api/src/ao/ao_align.h.md) | Memory alignment |
| [`ao_assert.h`](api/src/ao/ao_assert.h.md) | Runtime assertions |
| [`ao_avl.h`](api/src/ao/ao_avl.h.md) | AVL trees |
| [`ao_break.h`](api/src/ao/ao_break.h.md) | Breakpoints |
| [`ao_buffer.h`](api/src/ao/ao_buffer.h.md) | Buffers |
| [`ao_buffer4obj.h`](api/src/ao/ao_buffer4obj.h.md) | Buffers for objects |
| [`ao_buffer4ptr.h`](api/src/ao/ao_buffer4ptr.h.md) | Buffers for pointers |
| [`ao_char.h`](api/src/ao/ao_char.h.md) | Characters |
| [`ao_debug.h`](api/src/ao/ao_debug.h.md) | Debug mode |
| [`ao_float.h`](api/src/ao/ao_float.h.md) | Floating-point numbers |
| [`ao_func.h`](api/src/ao/ao_func.h.md) | Function pointer types |
| [`ao_heap.h`](api/src/ao/ao_heap.h.md) | Pointer-based heaps |
| [`ao_heap4obj.h`](api/src/ao/ao_heap4obj.h.md) | Array-based heaps for objects |
| [`ao_heap4ptr.h`](api/src/ao/ao_heap4ptr.h.md) | Array-based heaps for pointers |
| [`ao_int.h`](api/src/ao/ao_int.h.md) | Signed integers |
| [`ao_lfsr.h`](api/src/ao/ao_lfsr.h.md) | Linear-feedback shift registers |
| [`ao_list.h`](api/src/ao/ao_list.h.md) | Doubly linked lists |
| [`ao_math.h`](api/src/ao/ao_math.h.md) | Mathematics |
| [`ao_mathf.h`](api/src/ao/ao_mathf.h.md) | Mathematics for floating-point numbers |
| [`ao_mem.h`](api/src/ao/ao_mem.h.md) | Memory blocks |
| [`ao_print.h`](api/src/ao/ao_print.h.md) | Converting numbers to string |
| [`ao_rand.h`](api/src/ao/ao_rand.h.md) | Random value generators |
| [`ao_rb.h`](api/src/ao/ao_rb.h.md) | Red-black trees |
| [`ao_scan.h`](api/src/ao/ao_scan.h.md) | Converting numbers from string |
| [`ao_size.h`](api/src/ao/ao_size.h.md) | Sizes |
| [`ao_slist.h`](api/src/ao/ao_slist.h.md) | Sorted doubly linked lists |
| [`ao_struct.h`](api/src/ao/ao_struct.h.md) | Structs |
| [`ao_uint.h`](api/src/ao/ao_uint.h.md) | Unsigned integers |
| [`ao_var.h`](api/src/ao/ao_var.h.md) | Variables |

# Debugging

The following modules support the debugging of an application. Especially, runtime assertions are extensively used throughout the framework.

| [`ao_assert.h`](api/src/ao/ao_assert.h.md) | Defines a single macro function, that executes a runtime assertion. |
| [`ao_break.h`](api/src/ao/ao_break.h.md) | Defines a single function, that executes a breakpoint. |
| [`ao_debug.h`](api/src/ao/ao_debug.h.md) | Defines a single macro constant, that indicates, whether an application is running in debug mode. |

# Arithmetic Types

Based on the language-defined types, the standard library defines plenty of arithmetic types for specific purposes. The use of these types in embedded applications is strongly encouraged by several industrial coding standards, especially fixed-width integer types. 

Yet, in order to improve platform independency and portability, the environment package defines its own types for floating-point numbers as well as signed and unsigned integers.

| [`ao_float.h`](api/src/ao/ao_float.h.md) | Defines the fastest floating-point type of the target platform and mathematical operations for that type. |
| [`ao_int.h`](api/src/ao/ao_int.h.md) | Defines the fastest signed integer type of the target platform, along with a couple of properties thereof. |
| [`ao_size.h`](api/src/ao/ao_size.h.md) | Defines properties of and useful operations for the standard library's `size_t` type. Especially, these definitions are required by the allocators. |
| [`ao_uint.h`](api/src/ao/ao_uint.h.md) | Defines the fastest unsigned integer type of the target platform, along with a couple of properties thereof. Additionally, it defines useful operations, such as calculating the base-2 logarithm. |

# Function Pointer Types

Using function pointers, a function to be executed can be chosen at runtime rather than compile time. In general, this supports abstraction. The following modules define commonplace function pointer types.

| [`ao_func.h`](api/src/ao/ao_func.h.md) | Defines general-purpose function types. |
| [`ao_rand.h`](api/src/ao/ao_rand.h.md) | Defines random value generator types. |

# Memory Blocks and Strings

In a hosted runtime environment, the standard library offers a wide range of functions dealing with memory blocks and strings. However, these functions are not available in a freestanding runtime environment. Therefore, the environment package provides a subset thereof.

| [`ao_char.h`](api/src/ao/ao_char.h.md) | Provides functions to classify characters. |
| [`ao_mem.h`](api/src/ao/ao_mem.h.md) | Provides functions to copy, move, or fill memory blocks, respectively. |
| [`ao_print.h`](api/src/ao/ao_print.h.md) | Provides functions to convert a number to a string. |
| [`ao_scan.h`](api/src/ao/ao_scan.h.md) | Provides functions to convert a string to a number. |

# Mathematics

Mathematical functions, too, are not part of a freestanding runtime environment and therefore provided by the environment package.

| [`ao_math.h`](api/src/ao/ao_math.h.md) | Provides mathematical macro functions, that can be used for all scalar types. |
| [`ao_mathf.h`](api/src/ao/ao_mathf.h.md) | Provides mathematical constants and functions for floating-point types. |

# Data Structures

The following modules define data structures, that are required by a lot of kernel functions, such as the alarm queue or the task scheduler.

| [`ao_avl.h`](api/src/ao/ao_avl.h.md) | AVL trees. |
| [`ao_buffer.h`](api/src/ao/ao_buffer.h.md) | Buffers for arbitrary data. |
| [`ao_buffer4obj.h`](api/src/ao/ao_buffer4obj.h.md) | Buffers for fixed-size objects. |
| [`ao_buffer4ptr.h`](api/src/ao/ao_buffer4ptr.h.md) | Buffers for pointers. |
| [`ao_heap.h`](api/src/ao/ao_heap.h.md) | Pointer-based binary heaps. |
| [`ao_heap4obj.h`](api/src/ao/ao_heap4obj.h.md) | Array-based binary heaps for fixed-size objects. |
| [`ao_heap4ptr.h`](api/src/ao/ao_heap4ptr.h.md) | Array-based binary heaps for pointers. |
| [`ao_list.h`](api/src/ao/ao_list.h.md) | Doubly linked lists. |
| [`ao_rb.h`](api/src/ao/ao_rb.h.md) | Red-black trees. |
| [`ao_slist.h`](api/src/ao/ao_slist.h.md) | Doubly linked sorted lists. |

# Miscellaneous

| [`ao_align.h`](api/src/ao/ao_align.h.md) | Defines macro functions that support the correct alignment of pointers and data. |
| [`ao_lfsr.h`](api/src/ao/ao_lfsr.h.md) | Defines linear-feedback shift registers, that can be used to generate pseudo-random numbers. |
| [`ao_struct.h`](api/src/ao/ao_struct.h.md) | Defines a macro function supporting compound types such as structs. |
| [`ao_var.h`](api/src/ao/ao_var.h.md) | Defines convenience macro functions for working with variables. |

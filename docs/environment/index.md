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

## Debugging

The following modules support the debugging of an application. Especially, runtime assertions are being used extensively through the entire framework.

| Module | |
|--------|-|
| [`ao_assert`](assert.md) | Defines a macro function, that executes a runtime assertion. |
| [`ao_break`](break.md) | Defines a function, that executes a breakpoint. |
| [`ao_debug`](debug.md) | Defines a macro constant, that indicates, whether an application is running in debug mode. |

## Types

- [characters](char.md)
- [floating-point numbers](float.md)
- [functions](func.md)
- [random value generators](rand.md)
- [signed integers](int.md)
- [sizes](size.md)
- [unsigned integers](uint.md)

## Utilities

- [alignment](align.md)
- [linear-feedback shift registers](lfsr.md)
- [mathematics](math.md)
- [mathematics for floating-point numbers](mathf.md)
- [memory blocks](mem.md)
- [printing](print.md)
- [scanning](scan.md)
- [structs](struct.md)
- [variables](var.md)

## Data structures

- [AVL trees](avl.md)
- [buffers](buffer.md)
- [heaps](heap.md)
- [lists](list.md)
- [object buffers](buffer4obj.md)
- [object heaps](heap4obj.md)
- [pointer buffers](buffer4ptr.md)
- [pointer heaps](heap4ptr.md)
- [red-black trees](rb.md)
- [sorted lists](slist.md)

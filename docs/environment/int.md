---
author: "Stefan Wagner"
date: 2022-08-07
description: "Signed Integers in the ao Real-Time Operating System (RTOS)."
draft: false
permalink: /environment/int/
title: "Signed Integers"
---

# Signed Integers

The `stdint.h` header file of the standard library defines exact-width integer types. Using these types instead of built-in types is strongly encouraged by several standards, such as [MISRA C](https://en.wikipedia.org/wiki/MISRA_C), not least to make code more portable.










However, when implementing functions of a real-time operating system efficiently and in a hardware-agnostic way, it is sometimes desirable to use a fast integer type without knowing its exact width and without assuming a minimum width. In such a case, the (minimum) width of the integer is sort of too much information.

For example, an [AVL tree](avl.md) node stores its height in a signed integer. The width of that integer determines the maximum height that an AVL tree can have.

| Integer width | Maximum height |
|---------------|----------------|
| 8 bits | 127 |
| 16 bits | 32,767 |

A maximum height of 127 is most likely sufficient for most embedded systems. Nevertheless, choosing an 8-bit integer explicitly imposes a clear restriction on the maximum height. In contrast, a maximum height of 32,767 is dead certain sufficient for every conceivable embedded system. But, choosing a 16-bit integer explicitly could slow down the AVL functions on, say, 8-bit microcontrollers. Therefore, it is best to not specify the integer width explicitly, but simply use a fast type. Unfortunately, `stdint.h` does not define such a type.

The `ao_int.h` module defines ...


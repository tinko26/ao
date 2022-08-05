---
author: "Stefan Wagner"
date: 2022-08-05
description: "Mathematics for Integers in the ao Real-Time Operating System (RTOS)."
draft: false
permalink: /environment/mathi/
title: "Mathematics for Integers"
---

# Mathematics for Integers

The `ao_mathi.h` module provides an operation that determines the base-2 logarithm of an unsigned integer. It is implemented as a macro function for two reasons. First, when called with a constant, the result can be evaluated at compile time. 

```c
uint32_t x = ao_log2u(5242);
```

Second, and most important, it can be used in the definition of a macro constant, which some modules make use of.

```c
#define DSIZE     sizeof(double)
#define DSIZE_LOG ao_log2u(DSIZE)
```

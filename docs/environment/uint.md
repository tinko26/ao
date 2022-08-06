---
author: "Stefan Wagner"
date: 2022-08-06
description: "Unsigned Integers in the ao Real-Time Operating System (RTOS)."
draft: true
permalink: /environment/uint/
title: "Unsigned Integers"
---

# Unsigned Integers

The `uint.h` module provides an operation that determines the base-2 logarithm of an unsigned integer. It is implemented as a macro function. This is for two reasons. First, when called with a constant parameter value, the result can be evaluated at compile time. Second, it can be used in the definition of macro constants, which some kernel functions make use of. However, care must be taken for side effects, as the parameter value gets evaluated more than once.

```c
uint32_t x = ao_log2u(5242);
```

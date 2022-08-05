---
author: "Stefan Wagner"
date: 2022-08-05
description: "Mathematics for Integers in the ao Real-Time Operating System (RTOS)."
draft: false
permalink: /environment/mathi/
title: "Mathematics for Integers"
---

# Mathematics for Integers

The `ao_mathi.h` module provides an operation that determines the base-2 logarithm of an unsigned integer. 

```c
uint32_t x = ao_log2u(5242);
```

```c
```




These are implemented as macro functions for two reasons. First, when called with a constant 

```c
```

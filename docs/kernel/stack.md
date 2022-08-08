---
author: "Stefan Wagner"
date: 2022-08-08
description: "Stacks in the ao Real-Time Operating System (RTOS)."
draft: false
permalink: /kernel/stack/
title: "Stacks"
---

# Stacks

The `ao_stack.h` module contains two functions for measuring the high water mark of a stack, which can be used for optimizing the memory usage in an embedded system.

## Functions

Before using the stack for a thread of execution, it must be filled with a pattern.

```c
uint8_t stack[1024];
```

```c
ao_stack_fill(stack, 1024);
```

Then, after the respective thread of execution has been running for a while, the size that actually been used can be measured.

```c
size_t h = ao_stack_get_high_water_mark(stack, 1024);
```

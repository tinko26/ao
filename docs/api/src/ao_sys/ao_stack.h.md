---
author: "Stefan Wagner"
date: 2022-08-31
draft: true
permalink: /api/src/ao_sys/ao_stack.h/
toc: true
wiki:
- call-stack
---

# Overview

This module contains two functions for measuring the high water mark of a stack, which can be used for optimizing the memory usage in an embedded system.

# Include

```c
#include <stddef.h>
```

# Functions

```c
void ao_stack_fill(void * beginning, size_t size);
```

```c
size_t ao_stack_get_high_water_mark(void const * beginning, size_t size);
```

# Usage

Before using the stack for a thread of execution, it must be filled with a pattern.

```c
uint8_t stack[1024];
```

```c
ao_stack_fill(stack, 1024);
```

Then, after the respective thread of execution has been running for a while, the size that has actually been used can be measured.

```c
size_t h = ao_stack_get_high_water_mark(stack, 1024);
```

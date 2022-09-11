---
author: "Stefan Wagner"
date: 2022-08-31
draft: true
external:
- https://en.wikipedia.org/wiki/Call_stack : "Call stack"
permalink: /api/src/ao_sys/ao_stack.h/
toc: true
---

# Notes

This module contains two functions for measuring the high water mark of a stack, which can be used for optimizing the memory usage in an embedded system.

# Include

```c
#include <stddef.h>
```

# Identifier

```c
#define AO_STACK
```

# Functions

## `ao_stack_fill`

```c
void ao_stack_fill(void * beginning, size_t size);
```

Fills a stack with a pattern, which allows for measuring the high water mark of the stack, later on.

## `ao_stack_high_water_mark`

```c
size_t ao_stack_get_high_water_mark(void const * beginning, size_t size);
```

Measures the high water mark of a stack.

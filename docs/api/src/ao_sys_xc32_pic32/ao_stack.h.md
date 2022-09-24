---
author: "Stefan Wagner"
date: 2022-09-05
draft: true
permalink: /api/src/ao_sys_xc32_pic32/ao_stack.h/
toc: true
---

# Include

`stddef.h`

# Identifier

```c
#define AO_STACK
```

# Constants

## `AO_STACK_ALIGN`

```c
#define AO_STACK_ALIGN (8)
```

The stack pointer alignment, in bytes.

## `AO_STACK_FILL`

```c
#define AO_STACK_FILL (0xDEADBEEF)
```

The stack fill pattern.

# Functions

## `ao_stack_fill`

```c
void ao_stack_fill(void * beginning, size_t size);
```

Fills a stack with a pattern, which allows for measuring the high water mark of the stack, later on.

## `ao_stack_get_high_water_mark`

```c
size_t ao_stack_get_high_water_mark(void const * beginning, size_t size);
```

Measures the high water mark of a stack.

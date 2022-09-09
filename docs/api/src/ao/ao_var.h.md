---
author: "Stefan Wagner"
date: 2022-08-30
draft: true
permalink: /api/src/ao/ao_var.h/
toc: true
---

# Notes

This module defines two convenience macro functions for variables.

# Include

```c
#include <ao_mem.h>
#include <stddef.h>
```

# Functions

## `ao_clear`

Clear a variable of type `t` pointed to by `p`. This is especially useful when initializing objects that have been allocated on the stack.

```c
#define ao_clear(p, t)
```

## `ao_copy`

Copy a variable of `t` from the location pointed to by `s` to the location pointed to by `d`.

```c
#define ao_copy(d, s, t)
```

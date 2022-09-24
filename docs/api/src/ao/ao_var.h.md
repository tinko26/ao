---
author: "Stefan Wagner"
date: 2022-09-24
draft: true
permalink: /api/src/ao/ao_var.h/
seealso:
- /api/src/ao/ao_mem.h/
toc: true
---

# Notes

This module defines two convenience macro functions for variables.

# Include

```c
#include <ao_mem.h>
#include <stddef.h>
```

# Identifier

```c
#define AO_VAR
```

# Functions

## `ao_clear`

```c
#define ao_clear(p, t)         \
(                              \
    ao_memset(p, 0, sizeof(t)) \
)
```

Clears a variable of type `t` pointed to by `p`. This is especially useful when initializing objects that have been allocated on the stack.

## `ao_copy`

```c
#define ao_copy(d, s, t)       \
(                              \
    ao_memcpy(d, s, sizeof(t)) \
)
```

Copies a variable of `t` from the location pointed to by `s` to the location pointed to by `d`.

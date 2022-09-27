---
author: "Stefan Wagner"
date: 2022-09-27
draft: true
permalink: /api/src/ao/ao_var.h/
toc: true
---

# Notes

This module defines two convenience macro functions for variables.

# Include

| [`ao_mem.h`](ao_mem.h.md) |
| `stddef.h` |

# Functions

## `ao_clear`

```c
#define ao_clear(p, t)          \
(                               \
    ao_mem_set(p, 0, sizeof(t)) \
)
```

Clears a variable of type `t` pointed to by `p`. This is especially useful when initializing objects that have been allocated on the stack.

## `ao_copy`

```c
#define ao_copy(d, s, t)         \
(                                \
    ao_mem_copy(d, s, sizeof(t)) \
)
```

Copies a variable of type `t` from the location pointed to by `s` to the location pointed to by `d`.

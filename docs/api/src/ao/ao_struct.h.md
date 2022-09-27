---
author: "Stefan Wagner"
date: 2022-09-24
draft: true
permalink: /api/src/ao/ao_struct.h/
toc: true
---

# Notes

This module defines a single macro function that returns a pointer to the head of a compound when given a pointer to a member of that compound.

# Include

| `stddef.h` |
| `stdint.h` |

# Functions

## `ao_containerof`

```c
#define ao_containerof(p, t, m)          \
(                                        \
    (t *)                                \
    (                                    \
        (uint8_t *) (p) - offsetof(t, m) \
    )                                    \
)
```

Given a pointer `p` to a member `m` of a compound type `t`, this function returns a pointer of type `t *` to the head of the compound.

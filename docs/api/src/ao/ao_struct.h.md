---
author: "Stefan Wagner"
date: 2022-08-30
draft: true
permalink: /api/src/ao/ao_struct.h/
toc: true
---

# Notes

This module defines a single macro function that returns a pointer to the head of a compound when given a pointer to a member of that compound.

# Include

```c
#include <stddef.h>
#include <stdint.h>
```

# Functions

## `ao_containerof`

Given a pointer `p` to a member `m` of a compound type `t`, return a pointer to the head of the compound.

```c
#define ao_containerof(p, t, m)
```

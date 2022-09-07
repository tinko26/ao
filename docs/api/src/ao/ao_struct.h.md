---
author: "Stefan Wagner"
date: 2022-08-30
draft: true
permalink: /api/src/ao/ao_struct.h/
toc: true
---

# Overview

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

# Example

Given the definition of a compound type (that is, a struct or union) ...

```c
typedef struct struct_t struct_t;
```

```c
struct struct_t
{
    uint32_t member1;
    uint16_t member2;
    char     member3;
    uint64_t member4;
};
```

... and an object of that compound type, ...

```c
struct_t s;
```

... then given a pointer to a member ...

```c
char * p3 = &s.member3;
```

... one can retrieve a pointer to the object.

```c
struct_t * ps = ao_containerof(p3, struct_t, member3);
```

```c
ao_assert(ps == &s);
```

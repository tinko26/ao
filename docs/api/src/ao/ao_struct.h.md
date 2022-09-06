---
author: "Stefan Wagner"
date: 2022-08-30
draft: false
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

Given a pointer `p` to a member `m` of a compound type `t`, return a pointer to the head of the compound.

```c
#define ao_containerof(p, t, m)
```

# Example

Given the definition of a compound type (that is, a struct or union) ...

```c
typedef struct compound_t compound_t;
```

```c
struct compound_t
{
uint32_t member_a;
uint16_t member_b;
char     member_c;
uint64_t member_d;
};
```

... and an object of that compound type, ...

```c
compound_t x;
```

... then given a pointer to a member ...

```c
char * pc = &x.member_c;
```

... one can retrieve a pointer to the object.

```c
compound_t * px = ao_containerof(pc, compound_t, member_c);
```

```c
ao_assert(px == &x);
```

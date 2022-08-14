---
author: "Stefan Wagner"
date: 2022-08-14
description: "The ao_struct.h module of the ao real-time operating system."
draft: true
permalink: /modules/struct/
title: "ao_struct.h"
---

# ao_struct.h

This module defines a single macro function that returns a pointer to the head of a compound when given a pointer to a member of that compound.

For example, if there is a definition of a compound type (that is, a struct or union) ...

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

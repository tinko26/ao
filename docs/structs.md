---
author: "Stefan Wagner"
date: 2022-09-09
draft: true
permalink: /structs/
seealso:
- /api/src/ao/ao_struct.h/
toc: true
---

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

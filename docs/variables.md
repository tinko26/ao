---
author: "Stefan Wagner"
date: 2022-09-09
draft: true
permalink: /variables/
seealso:
- /api/src/ao/ao_var.h/
toc: true
---

# Example

Copy `a` to `b`.

```c
uint32_t a = 0xDEADBEEFU;
uint32_t b;
```

```c
ao_copy(&b, &a, uint32_t);
```

```c
ao_assert(a == b);
```

Clear list `l`.

```c
ao_list_t l;
```

```c
ao_clear(&l, ao_list_t);
```

```c
ao_assert(l.back  == NULL);
ao_assert(l.front == NULL);
```

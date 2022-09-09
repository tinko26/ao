---
author: "Stefan Wagner"
date: 2022-09-09
draft: true
permalink: /memory-alignment/
seealso:
- /api/src/ao/ao_align.h/
toc: true
---

# Example

```c
uint32_t x = 7;
```

Align `x` down and up, respectively, to a 4-byte boundary.

```c
uint32_t xd = AO_ALIGN_DOWN(x, 4);
uint32_t xu = AO_ALIGN_UP(  x, 4);
```

```c
ao_assert(xd == 4);
ao_assert(xu == 8);
```

Check whether `xu` is aligned to an 8-byte boundary.

```c
if (AO_IS_ALIGNED(xu, 8))
{
    // yes.
}
else
{
    // no.
}
```

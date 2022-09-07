---
author: "Stefan Wagner"
date: 2022-08-30
draft: false
external-wiki:
- memory-alignment
permalink: /api/src/ao/ao_align.h/
toc: true
---

# Overview

Reading from or writing to memory usually requires scalar data, such as an integer or a pointer, to be aligned, that is, its address must be a multiple of its size. This is, because such reads and writes are implemented efficiently on most CPUs, while unaligned accesses impose a penalty on the execution speed.

Normally, the compiler takes care of the correct alignment of variables automatically. However, there are situations, when this is not the case, for example, when dealing with dynamic memory management functions or stack pointers.

# Include

```c
#include <stdbool.h>
```

# Functions

Align value `x` up or down, respectively, to boundary `b`.

```c
#define AO_ALIGN_DOWN(x, b)
#define AO_ALIGN_UP(x, b)
```

Check whether value `x` is aligned to boundary `b`.

```c
#define AO_IS_ALIGNED(x, b)
```

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

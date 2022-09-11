---
author: "Stefan Wagner"
date: 2022-08-30
draft: true
external:
- https://en.wikipedia.org/wiki/Memory_alignment : "Memory alignment"
permalink: /api/src/ao/ao_align.h/
toc: true
---

# Notes

Reading from or writing to memory usually requires scalar data, such as an integer or a pointer, to be aligned, that is, its address must be a multiple of its size. This is, because such reads and writes are implemented efficiently on most CPUs, while unaligned accesses impose a penalty on the execution speed.

Normally, the compiler takes care of the correct alignment of variables automatically. However, there are situations, when this is not the case, for example, when dealing with dynamic memory management functions or stack pointers.

# Include

```c
#include <stdbool.h>
```

# Functions

## `AO_ALIGN_DOWN`

```c
#define AO_ALIGN_DOWN(x, b) \
(                           \
    ((x) / (b)) * (b)       \
)
```

Aligns value `x` down to boundary `b`.

## `AO_ALIGN_UP`

```c
#define AO_ALIGN_UP(x, b)           \
(                                   \
    (((x) + ((b) - 1)) / (b)) * (b) \
)
```

Aligns value `x` up to boundary `b`.

## `AO_IS_ALIGNED`

```c
#define AO_IS_ALIGNED(x, b)  \
(                            \
    (x) % (b) ? false : true \
)
```

Checks whether value `x` is aligned to boundary `b`.

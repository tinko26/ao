---
author: "Stefan Wagner"
date: 2022-08-10
description: "The ao_align.h module of the ao real-time operating system."
draft: false
permalink: /modules/align/
title: "ao_align.h"
---

# Overview

Reading from or writing to memory usually requires scalar data, such as an integer or a pointer, to be aligned, that is, its address must be a multiple of its size. This is, because such reads and writes are implemented efficiently on most CPUs, while unaligned accesses impose a penalty on the execution speed.

Normally, the compiler takes care of the correct alignment of variables automatically. However, there are situations, when this is not the case, for example, when dealing with dynamic memory management functions or stack pointers.

This module defines two macro functions that align a given value up or down, respectively, to a given boundary.

```c
uint32_t x = 7;
```

```c
uint32_t xd = AO_ALIGN_DOWN(x, 4);
uint32_t xu = AO_ALIGN_UP(  x, 4);
```

```c
ao_assert(xd == 4);
ao_assert(xu == 8);
```

Additionally, the alignment of a value can be checked.

```c
if (AO_IS_ALIGNED(xu, 8))
{
    // xu is aligned to an 8-byte boundary.
}
```

# External Links

[https://en.wikipedia.org/wiki/Data_structure_alignment](https://en.wikipedia.org/wiki/Data_structure_alignment)

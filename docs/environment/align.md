---
author: "Stefan Wagner"
date: 2022-08-06
description: "Alignment in the ao Real-Time Operating System (RTOS)."
draft: false
permalink: /environment/align/
title: "Alignment"
---

# Alignment

Reading from or writing to memory usually requires scalar data, such as an integer or a pointer, to be [aligned](https://en.wikipedia.org/wiki/Data_structure_alignment), that is, its address must be a multiple of its size. This is, because such reads and writes are implemented efficiently on most CPUs, while unaligned accesses impose a penalty on the execution speed.

Normally, the compiler takes care of the correct alignment of variables automatically. However, there are situations, when this is not the case, especially when implementing dynamic memory management functions.

The `ao_align.h` module defines two macro functions that align a given value up or down, respectively, to a given boundary.

```c
uint32_t x = 7;
```

```c
uint32_t xd = ao_align_down(x, 4);
uint32_t xu = ao_align_up(  x, 4);
```

```c
ao_assert(xd == 4);
ao_assert(xu == 8);
```

Additionally, the alignment of a value can be checked.

```c
if (ao_is_aligned(xu, 8))
{
    // xu is aligned to an 8-byte boundary.
}
```

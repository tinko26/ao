---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The ao/ao_align.h module of the ao real-time operating system."
draft: true
permalink: /ao/ao_align.h/ 
subtitle: "Memory alignment"
title: "ao_align.h"
toc: true
wiki:
- title: Memory alignment
  url: https://en.wikipedia.org/wiki/Memory_alignment
---

# Overview

Reading from or writing to memory usually requires scalar data, such as an integer or a pointer, to be aligned, that is, its address must be a multiple of its size. This is, because such reads and writes are implemented efficiently on most CPUs, while unaligned accesses impose a penalty on the execution speed.

Normally, the compiler takes care of the correct alignment of variables automatically. However, there are situations, when this is not the case, for example, when dealing with dynamic memory management functions or stack pointers.

# Includes

```c
#include <stdbool.h>
```

# Macro Functions

Align value `x` up or down, respectively, to boundary `b`.

```c
#define AO_ALIGN_DOWN(x, b)
```

```c
#define AO_ALIGN_UP(x, b)
```

Check whether value `x` is aligned to boundary `b`.

```c
#define AO_IS_ALIGNED(x, b)
```

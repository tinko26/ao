---
author: "Stefan Wagner"
date: 2022-08-05
description: "Alignment in the ao Real-Time Operating System (RTOS)."
draft: true
permalink: /environment/align/
title: "Alignment"
---

# Alignment

Reading from or writing to memory usually requires scalar data, such as an integer or a pointer, to be [aligned](https://en.wikipedia.org/wiki/Data_structure_alignment), that is, its address must be a multiple of its size. This is, because such reads and writes are implemented efficiently on most CPUs, while unaligned accesses impose a penalty on the execution speed.

Normally, the compiler takes care of the correct alignment of variables automatically. However, there are situations, when this is not the case, especially when implementing kernel functions.

An allocator, for example, needs to know the maximum alignment of all scalar types, because an allocated block of memory must be suitable to contain any kind of data. 

The `ao_align_max.h` module defines a type, whose alignment is the largets among all scalar types.

```c
typedef uint32_t ao_align_max_t;
```

Additionally, the module defines macro constants that determine that type's size in bits and bytes, as well as the logarithms thereof.

```c
#define AO_ALIGN_MAX_BITS     (32)
#define AO_ALIGN_MAX_BITS_LOG (5)
```

```c
#define AO_ALIGN_MAX_SIZE     (4)
#define AO_ALIGN_MAX_SIZE_LOG (2)
```

The purpose of these definitions is to have a hardware-agnostic abstraction that is primarily used to write allocators. However, since the alignment requirements of scalar types are platform-dependent, this module should be overridden by a hardware-specific package.


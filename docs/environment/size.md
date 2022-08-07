---
author: "Stefan Wagner"
date: 2022-08-07
description: "Sizes in the ao Real-Time Operating System (RTOS)."
draft: false
permalink: /environment/size/
title: "Sizes"
---

# Sizes

The standard library's `size_t` type is an unsigned integer type, at least 16 bits wide, that can store the size of any kind of object, from single numbers to huge arrays. It is intended to be used for loop counters and array indexes. 

The `ao_size.h` module specifies properties of the type and contains a couple of useful functions, that are, for example, required by the [allocators](../kernel/alloc.md).

## Constants

The module defines both the size of `size_t` in bytes ...

```c
#define AO_SIZE_SIZE (4)
```

... and bits, as well as the base-2 logarithm thereof.

```c
#define AO_SIZE_BITS     (32)
#define AO_SIZE_BITS_LOG (5)
```

Additionally, the module defines both the minimum and maximum value.

```c
#define AO_SIZE_MIN (0)
#define AO_SIZE_MAX (SIZE_MAX)
```

## Functions

Count the number of leading or trailing ones or zeros, respectively.

```c
size_t ao_cloz(size_t x);
size_t ao_clzz(size_t x);
size_t ao_ctoz(size_t x);
size_t ao_ctzz(size_t x);
```

Find the first or last set bit, respectively.

```c
size_t ao_ffsz(size_t x);
size_t ao_flsz(size_t x);
```

Calculate the base-2 logarithm.

```c
size_t ao_log2z(size_t x);
```

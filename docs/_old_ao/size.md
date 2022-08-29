---
author: "Stefan Wagner"
date: 2022-08-12
description: "The ao_size.h module of the ao real-time operating system."
draft: false
permalink: /modules/size/
title: "<code>ao_size.h</code>"
toc: true
---

# Overview

The standard library's `size_t` type is an unsigned integer type, at least 16 bits wide, that can store the size of any kind of object, from single numbers to huge arrays. It is intended to be used for loop counters and array indexes. This module specifies properties of the type and provides a couple of useful functions. This module is considered abstract and should be overridden by a port package.

## Constants

The size in bits and the base-2 logarithm thereof.

```c
#define AO_SIZE_BITS
#define AO_SIZE_BITS_LOG
```

The maximum and minimum value.

```c
#define AO_SIZE_MAX
#define AO_SIZE_MIN
```

The size in bytes.

```c
#define AO_SIZE_SIZE
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
#define AO_LOG2Z(x)
```

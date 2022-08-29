---
author: "Stefan Wagner"
date: 2022-08-12
description: "The ao_uint.h module of the ao real-time operating system."
draft: false
permalink: /modules/uint/
title: "<code>ao_uint.h</code>"
toc: true
---

# Overview

This module defines the fastest unsigned integer type available on the target platform. Additionally, it provides a couple of useful functions. This module is considered abstract and should be overridden by a port package.

## Type

The `ao_uint_t` type represents the fastest unsigned integer type of the target platform. It is an alias for one of the fixed-width unsigned integer types defined by the standard library.

## Constants

The size in bits and the base-2 logarithm thereof.

```c
#define AO_UINT_BITS
#define AO_UINT_BITS_LOG
```

The maximum and minimum value.

```c
#define AO_UINT_MAX
#define AO_UINT_MIN
```

The size in bytes.

```c
#define AO_UINT_SIZE
```

## Functions

Count the number of leading or trailing ones or zeros, respectively.

```c
ao_uint_t ao_clou(ao_uint_t x);
ao_uint_t ao_clzu(ao_uint_t x);
ao_uint_t ao_ctou(ao_uint_t x);
ao_uint_t ao_ctzu(ao_uint_t x);
```

Find the first or last set bit, respectively.

```c
ao_uint_t ao_ffsu(ao_uint_t x);
ao_uint_t ao_flsu(ao_uint_t x);
```

Calculate the base-2 logarithm.

```c
#define AO_LOG2U(x)
```

Calculate the base-2 logarithm for a fixed-width unsigned integer.

```c
#define AO_LOG2U2(x)
#define AO_LOG2U4(x)
#define AO_LOG2U8(x)
#define AO_LOG2U16(x)
#define AO_LOG2U32(x)
#define AO_LOG2U64(x)
```

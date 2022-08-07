---
author: "Stefan Wagner"
date: 2022-08-07
description: "Unsigned Integers in the ao Real-Time Operating System (RTOS)."
draft: false
permalink: /environment/uint/
title: "Unsigned Integers"
---

# Unsigned Integers

The `ao_uint.h` module defines an abstraction for unsigned integers. It defines the `ao_uint.h` type, which represents the fastest unsigned integer type available on the target platform. Additionally, it contains a couple of useful functions.

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

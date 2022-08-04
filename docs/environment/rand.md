---
author: "Stefan Wagner"
date: 2022-08-04
description: "Random Value Generators in the ao Real-Time Operating System (RTOS)."
draft: false
permalink: /environment/rand/
title: "Random Value Generators"
---

# Random Value Generators

The `ao_rand.h` module defines function pointer types for a variety of random value generators.

```c
typedef bool (* ao_rand_b_t) ();
```

```c
typedef double (* ao_rand_d_t) ();
```

```c
typedef float (* ao_rand_f_t) ();
```

```c
typedef int8_t  (* ao_rand_i8_t ) ();
typedef int16_t (* ao_rand_i16_t) ();
typedef int32_t (* ao_rand_i32_t) ();
typedef int64_t (* ao_rand_i64_t) ();
```

```c
typedef long double (* ao_rand_l_t) ();
```

```c
typedef uint8_t  (* ao_rand_u8_t ) ();
typedef uint16_t (* ao_rand_u16_t) ();
typedef uint32_t (* ao_rand_u32_t) ();
typedef uint64_t (* ao_rand_u64_t) ();
```

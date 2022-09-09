---
author: "Stefan Wagner"
date: 2022-08-30
draft: true
permalink: /api/src/ao/ao_rand.h/
toc: true
---

# Notes

This module defines function pointer types for a variety of random value generators.

# Include

```c
#include <stdbool.h>
#include <stdint.h>
```

# Typedefs

Generate a random Boolean value.

```c
typedef bool        (* ao_randb_t)   ();
```

Generate a random floating-point number.

```c
typedef double      (* ao_randd_t)   ();
typedef float       (* ao_randf_t)   ();
typedef long double (* ao_randl_t)   ();
```

Generate a random signed integer.

```c
typedef int8_t      (* ao_randi8_t ) ();
typedef int16_t     (* ao_randi16_t) ();
typedef int32_t     (* ao_randi32_t) ();
typedef int64_t     (* ao_randi64_t) ();
```

Generate a random unsigned integer.

```c
typedef uint8_t     (* ao_randu8_t ) ();
typedef uint16_t    (* ao_randu16_t) ();
typedef uint32_t    (* ao_randu32_t) ();
typedef uint64_t    (* ao_randu64_t) ();
```

---
author: "Stefan Wagner"
date: 2022-08-08
description: "The ao_rand.h module of the ao real-time operating system."
draft: false
permalink: /modules/rand/
title: "<code>ao_rand.h</code>"
toc: true
---

# Overview

This module defines function pointer types for a variety of random value generators.

```c
typedef bool        (* ao_randb_t)   ();
```

```c
typedef double      (* ao_randd_t)   ();
```

```c
typedef float       (* ao_randf_t)   ();
```

```c
typedef int8_t      (* ao_randi8_t ) ();
typedef int16_t     (* ao_randi16_t) ();
typedef int32_t     (* ao_randi32_t) ();
typedef int64_t     (* ao_randi64_t) ();
```

```c
typedef long double (* ao_randl_t)   ();
```

```c
typedef uint8_t     (* ao_randu8_t ) ();
typedef uint16_t    (* ao_randu16_t) ();
typedef uint32_t    (* ao_randu32_t) ();
typedef uint64_t    (* ao_randu64_t) ();
```
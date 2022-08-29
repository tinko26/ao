---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The ao/ao_rand.h module of the ao real-time operating system."
draft: true
permalink: /ao/ao_rand.h/ 
subtitle: ""
title: "ao_rand.h"
toc: true
---

```c
#include <stdbool.h>
#include <stdint.h>

typedef bool        (*  ao_randb_t)    ();

typedef double      (*  ao_randd_t)    ();

typedef float       (*  ao_randf_t)    ();

typedef int8_t      (*  ao_randi8_t)   ();

typedef int16_t     (*  ao_randi16_t)  ();

typedef int32_t     (*  ao_randi32_t)  ();

typedef int64_t     (*  ao_randi64_t)  ();

typedef long double (*  ao_randl_t)    ();

typedef uint8_t     (*  ao_randu8_t)   ();

typedef uint16_t    (*  ao_randu16_t)  ();

typedef uint32_t    (*  ao_randu32_t)  ();

typedef uint64_t    (*  ao_randu64_t)  ();

```

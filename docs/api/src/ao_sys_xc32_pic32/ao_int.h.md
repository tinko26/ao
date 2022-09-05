---
api: true
author: "Stefan Wagner"
date: 2022-09-05
description: "The /src/ao_sys_xc32_pic32/ao_int.h file of the ao real-time operating system."
draft: true
permalink: /api/src/ao_sys_xc32_pic32/ao_int.h/
subtitle: "Signed integers"
title: "ao_int.h"
toc: true
---

# Overview

This module defines the fastest signed integer type available on the target platform.

# Include

```c
#include <stdint.h>
```

# Typedefs

The `ao_int_t` type represents the fastest signed integer type of the target platform. It is an alias the `int32_t` fixed-width signed integer type defined by the standard library.

```c
typedef int32_t ao_int_t;
```

# Constants

The maximum and minimum value.

```c
#define AO_INT_MAX  (INT32_MAX)
#define AO_INT_MIN  (INT32_MIN)
```

The size in bytes.

```c
#define AO_INT_SIZE (4)
```

---
api: true
author: "Stefan Wagner"
date: 2022-08-30
description: "The /src/ao/ao_int.h file of the ao real-time operating system."
draft: false
permalink: /api/src/ao/ao_int.h/
subtitle: "Signed integers"
title: "ao_int.h"
toc: true
---

# Overview

This module defines the fastest signed integer type available on the target platform. This module is considered abstract and should be overridden by a port package.

# Include

```c
#include <stdint.h>
```

# Typedefs

The `ao_int_t` type represents the fastest signed integer type of the target platform. It is an alias for one of the fixed-width signed integer types defined by the standard library.

```c
typedef int32_t ao_int_t;
```

# Constants

The maximum and minimum value.

```c
#define AO_INT_MAX (INT32_MAX)
```

```c
#define AO_INT_MIN (INT32_MIN)
```

The size in bytes.

```c
#define AO_INT_SIZE (4)
```

---
api: true
author: "Stefan Wagner"
date: 2022-09-05
description: "The /src/ao_sys_xc32_pic32/ao_float.h file of the ao real-time operating system."
draft: true
permalink: /api/src/ao_sys_xc32_pic32/ao_float.h/
subtitle: "Floating-point numbers"
title: "ao_float.h"
toc: true
---

# Overview

This module defines the fastest floating-point type available on the target platform. Additionally, it provides a couple of mathematical functions for that type.

# Configuration

The size of a floating-point number in bits.

```c
#define AO_FLOAT (32)
```

# Include

```c
#if AO_FLOAT == (32)

#include <ao_floatf.h>

#elif AO_FLOAT == (64)

#include <ao_floatl.h>

#endif
```

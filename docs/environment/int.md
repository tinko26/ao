---
author: "Stefan Wagner"
date: 2022-08-07
description: "Signed Integers in the ao Real-Time Operating System (RTOS)."
draft: false
permalink: /environment/int/
title: "Signed Integers"
---

# Signed Integers

The `ao_int.h` module defines an abstraction for signed integers. It defines the `ao_int.h` type, which represents the fastest signed integer type available on the target platform.

## Constants

The maximum and minimum value.

```c
#define AO_INT_MAX
#define AO_INT_MIN
```

The size in bytes.

```c
#define AO_INT_SIZE
```

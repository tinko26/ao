---
author: "Stefan Wagner"
date: 2022-08-12
description: "The ao_int.h module of the ao real-time operating system."
draft: false
permalink: /modules/int/
title: "<code>ao_int.h</code>"
---

# Overview

This module defines the fastest signed integer type available on the target platform. This module is considered abstract and should be overridden by a port package.

## Type

The `ao_int_t` type represents the fastest signed integer type of the target platform. It is an alias for one of the fixed-width signed integer types defined by the standard library.

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

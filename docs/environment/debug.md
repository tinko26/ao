---
author: "Stefan Wagner"
date: 2022-08-12
description: ""
draft: false
permalink: /environment/debug/
title: "Debug Mode"
---

# Debug Mode

The `ao_debug.h` module defines a single macro constant indicating whether an application is running in debug mode. By default, its value is `false`. Since debug mode is a toolchain feature, this module is expected to be overridden in a port package.

```c
#define AO_DEBUG
```

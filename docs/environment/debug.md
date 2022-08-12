---
author: "Stefan Wagner"
date: 2022-08-07
description: "Debugging in the ao Real-Time Operating System (RTOS)."
draft: false
permalink: /environment/debug/
title: "Debugging"
---

# Debugging

The `ao_debug.h` module defines a single macro constant indicating whether an application is running in debug mode.

```c
#define AO_DEBUG
```

By default, its value is `false`. Since debug mode is a toolchain feature, this module is expected to be overridden in a port package.

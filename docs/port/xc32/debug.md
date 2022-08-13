---
author: "Stefan Wagner"
date: 2022-08-13
description: ""
draft: false
permalink: /port/xc32/debug/
title: "Debugging"
---

# Debugging

The `ao_debug.h` module defines a single macro constant indicating whether an application is running in debug mode. It overrides the [corresponding module](../../environment/debug.md) of the environment package.

```c
#define AO_DEBUG
```

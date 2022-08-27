---
author: "Stefan Wagner"
date: 2022-08-12
description: "The ao_debug.h module of the ao real-time operating system."
draft: false
permalink: /modules/debug/
title: "<code>ao_debug.h</code>"
---

# Overview

This module defines a single macro constant indicating whether an application is running in debug mode. By default, its value is `false`. Since debug mode is a toolchain feature, this module is expected to be overridden in a port package.

```c
#define AO_DEBUG
```

## See Also

[Debugging](../debugging.md)

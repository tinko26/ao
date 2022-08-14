---
author: "Stefan Wagner"
date: 2022-08-14
description: "The ao_debug.h module of the ao real-time operating system."
draft: true
permalink: /modules/debug/
title: "ao_debug.h"
---

# ao_debug.h

This module defines a single macro constant indicating whether an application is running in debug mode. By default, its value is `false`. Since debug mode is a toolchain feature, this module is expected to be overridden in a port package.

```c
#define AO_DEBUG
```

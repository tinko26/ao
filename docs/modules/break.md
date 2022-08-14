---
author: "Stefan Wagner"
date: 2022-08-14
description: "The ao_break.h module of the ao real-time operating system."
draft: true
permalink: /modules/break/
title: "ao_break.h"
---

# ao_break.h

This module contains a single function that executes a [breakpoint](https://en.wikipedia.org/wiki/Breakpoint). Since breakpoints are hardware-specific, this module is abstract. Therefore, an implementation must be provided by a port package.

```c
void ao_break();
```

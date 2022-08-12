---
author: "Stefan Wagner"
date: 2022-08-12
description: "Breakpoints in the ao Real-Time Operating System (RTOS)."
draft: false
permalink: /environment/break/
title: "Breakpoints"
---

# Breakpoints

The `ao_break.h` module contains a single function that executes a [breakpoint](https://en.wikipedia.org/wiki/Breakpoint). Since breakpoints are hardware-specific, this module is abstract. Therefore, an implementation must be provided by a port package.

```c
void ao_break();
```

---
author: "Stefan Wagner"
date: 2022-08-30
draft: true
external:
- https://en.wikipedia.org/wiki/Breakpoint : "Breakpoint"
permalink: /api/src/ao/ao_break.h/
toc: true
---

# Notes

This module contains a single function that executes a breakpoint. Since breakpoints are hardware-specific, this module is abstract. Therefore, an implementation must be provided by a port package.

# Functions

## `ao_break`

Execute a breakpoint.

```c
void ao_break();
```

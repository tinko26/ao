---
author: "Stefan Wagner"
date: 2022-09-27
draft: true
external:
- https://en.wikipedia.org/wiki/Breakpoint : "Breakpoint"
permalink: /api/src/ao/ao_break.h/
toc: true
---

# Notes

This module contains a single function that executes a breakpoint. Since breakpoints are hardware-specific, this module is abstract. Therefore, an implementation must be provided by a port.

# Functions

## `ao_break`

```c
void ao_break();
```

Executes a breakpoint.

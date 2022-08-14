---
author: "Stefan Wagner"
date: 2022-08-12
description: "The ao_break.h module of the ao real-time operating system."
draft: false
permalink: /modules/break/
title: "ao_break.h"
---

# ao_break.h

This module contains a single function that executes a breakpoint. Since breakpoints are hardware-specific, this module is abstract. Therefore, an implementation must be provided by a port package.

```c
void ao_break();
```

## See Also

[Debugging](../debugging.md)

🌎 [https://en.wikipedia.org/wiki/Breakpoint](https://en.wikipedia.org/wiki/Breakpoint)

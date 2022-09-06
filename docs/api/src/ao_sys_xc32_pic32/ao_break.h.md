---
api: true
author: "Stefan Wagner"
date: 2022-09-05
description: "The /src/ao_sys_xc32_pic32/ao_break.h file of the ao real-time operating system."
draft: true
permalink: /api/src/ao_sys_xc32_pic32/ao_break.h/
seealso:
- /api/src/ao_sys_xc32/ao_debug.h/
subtitle: "Breakpoints"
title: "ao_break.h"
toc: true
---

# Overview

This module contains a single function that executes a breakpoint, if the application is running in debug mode.

# Include

```c
#include <ao_debug.h>
```

# Functions

```c
#define ao_break()
```

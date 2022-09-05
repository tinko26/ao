---
api: true
author: "Stefan Wagner"
date: 2022-09-05
description: "The /src/ao_sys_xc32/ao_debug.h file of the ao real-time operating system."
draft: true
permalink: /api/src/ao_sys_xc32/ao_debug.h/
subtitle: "Debug mode"
title: "ao_debug.h"
toc: true
---

# Overview

This module defines a single macro constant indicating whether an application is running in debug mode.

# Include

```c
#include <stdbool.h>
```

# Constants

```c
#ifndef AO_DEBUG

#ifndef NDEBUG

#ifndef __DEBUG

#define AO_DEBUG (false)

#else

#define AO_DEBUG (true)

#endif

#else

#define AO_DEBUG (false)

#endif

#endif
```

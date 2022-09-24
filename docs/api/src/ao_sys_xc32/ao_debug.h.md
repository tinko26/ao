---
author: "Stefan Wagner"
date: 2022-09-24
draft: true
permalink: /api/src/ao_sys_xc32/ao_debug.h/
toc: true
---

# Notes

This module defines a single macro constant indicating whether an application is running in debug mode.

# Include

| `stdbool.h` |

# Identifier

```c
#define AO_DEBUG
```

# Constants

## `AO_DEBUG`

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

Indicates whether the application is running in debug mode.

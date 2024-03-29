---
author: "Stefan Wagner"
date: 2022-09-27
draft: true
permalink: /api/src/ao/ao_debug.h/
toc: true
---

# Notes

This module defines a single macro constant indicating whether an application is running in debug mode. Since debug mode is a toolchain feature, this module is expected to be overridden by a port.

# Include

| `stdbool.h` |

# Constants

## `AO_DEBUG`

```c
#define AO_DEBUG (false)
```

Indicates whether the application is running in debug mode.

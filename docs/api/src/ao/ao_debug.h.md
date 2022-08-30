---
api: true
author: "Stefan Wagner"
date: 2022-08-30
description: "The /src/ao/ao_debug.h file of the ao real-time operating system."
draft: false
permalink: /api/src/ao/ao_debug.h/
subtitle: "Debug mode"
title: "ao_debug.h"
toc: true
---

# Overview

This module defines a single macro constant indicating whether an application is running in debug mode. Since debug mode is a toolchain feature, this module is expected to be overridden in a port package.

# Include

```c
#include <stdbool.h>
```

# Constants

Indicates whether the application is running in debug mode.

```c
#define AO_DEBUG (false)
```

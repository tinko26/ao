---
api: true
author: "Stefan Wagner"
date: 2022-08-31
description: "The /src/ao/ao_float.h file of the ao real-time operating system."
draft: false
permalink: /api/src/ao/ao_float.h/
subtitle: "Floating-point numbers"
title: "ao_float.h"
toc: true
---

# Overview

This module defines the fastest floating-point type available on the target platform. Additionally, it provides a couple of mathematical functions for that type. This module is considered abstract and should be overridden by a port package.

# Include

```c
#include <ao_floatf.h>
```

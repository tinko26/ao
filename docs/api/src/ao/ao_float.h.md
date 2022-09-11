---
author: "Stefan Wagner"
date: 2022-08-31
draft: true
permalink: /api/src/ao/ao_float.h/
seealso:
- /api/src/ao/ao_floatd.h/
- /api/src/ao/ao_floatf.h/
- /api/src/ao/ao_floatl.h/
toc: true
---

# Notes

This module defines the fastest floating-point type available on the target platform. Additionally, it provides a couple of mathematical functions for that type. This module is considered abstract and should be overridden by a port package.

# Include

```c
#include <ao_floatf.h>
```

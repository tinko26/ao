---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The /src/ao_sys_xc32_pic32mz_dak/ao_ir_glcd.h file of the ao real-time operating system."
draft: true
permalink: /api/src/ao_sys_xc32_pic32mz_dak/ao_ir_glcd.h/
subtitle: ""
title: "ao_ir_glcd.h"
toc: true
---

# Include

```c
#include <stdbool.h>
#include <sys/attribs.h>
#include <xc.h>
```

# Constants

```c
#define AO_IR_GLCD_ATTRIBUTE __ISR(_GLCD_VECTOR, IPL4SRS)
```

```c
#define AO_IR_GLCD_PRIO (4)
```

```c
#define AO_IR_GLCD_SUBPRIO (0)
```

# Functions

```c
#define ao_ir_glcd_disable()
```

```c
#define ao_ir_glcd_enable()
```

```c
#define ao_ir_glcd_is_enabled()
```

```c
#define ao_ir_glcd_is_pending()
```

```c
#define ao_ir_glcd_reply()
```

```c
#define ao_ir_glcd_request()
```


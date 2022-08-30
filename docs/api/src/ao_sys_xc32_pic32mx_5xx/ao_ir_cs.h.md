---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The /src/ao_sys_xc32_pic32mx_5xx/ao_ir_cs.h file of the ao real-time operating system."
draft: true
permalink: /api/src/ao_sys_xc32_pic32mx_5xx/ao_ir_cs.h/
subtitle: ""
title: "ao_ir_cs.h"
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
#define AO_IR_CS0_ATTRIBUTE __ISR(_CORE_SOFTWARE_0_VECTOR, IPL2SOFT)
```

```c
#define AO_IR_CS0_PRIO (2)
```

```c
#define AO_IR_CS0_SUBPRIO (0)
```

```c
#define AO_IR_CS1_ATTRIBUTE __attribute__ ((naked, vector(_CORE_SOFTWARE_1_VECTOR)))
```

```c
#define AO_IR_CS1_PRIO (1)
```

```c
#define AO_IR_CS1_SUBPRIO (0)
```

# Functions

```c
#define ao_ir_cs0_disable()
```

```c
#define ao_ir_cs0_enable()
```

```c
#define ao_ir_cs0_is_enabled()
```

```c
#define ao_ir_cs0_is_pending()
```

```c
#define ao_ir_cs0_reply()
```

```c
#define ao_ir_cs0_request()
```

```c
#define ao_ir_cs1_disable()
```

```c
#define ao_ir_cs1_enable()
```

```c
#define ao_ir_cs1_is_enabled()
```

```c
#define ao_ir_cs1_is_pending()
```

```c
#define ao_ir_cs1_reply()
```

```c
#define ao_ir_cs1_request()
```


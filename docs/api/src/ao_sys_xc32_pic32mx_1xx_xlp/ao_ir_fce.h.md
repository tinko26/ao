---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The /src/ao_sys_xc32_pic32mx_1xx_xlp/ao_ir_fce.h file of the ao real-time operating system."
draft: true
permalink: /api/src/ao_sys_xc32_pic32mx_1xx_xlp/ao_ir_fce.h/
subtitle: ""
title: "ao_ir_fce.h"
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
#define AO_IR_FCE_ATTRIBUTE __ISR(_FCE_VECTOR, IPL4SOFT)
```

```c
#define AO_IR_FCE_PRIO (4)
```

```c
#define AO_IR_FCE_SUBPRIO (0)
```

# Functions

```c
#define ao_ir_fce_disable()
```

```c
#define ao_ir_fce_enable()
```

```c
#define ao_ir_fce_is_enabled()
```

```c
#define ao_ir_fce_is_pending()
```

```c
#define ao_ir_fce_reply()
```

```c
#define ao_ir_fce_request()
```


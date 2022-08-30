---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The /src/ao_sys_xc32_pic32mz_ef/ao_ir_rtcc.h file of the ao real-time operating system."
draft: true
permalink: /api/src/ao_sys_xc32_pic32mz_ef/ao_ir_rtcc.h/
subtitle: ""
title: "ao_ir_rtcc.h"
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
#define AO_IR_RTCC_ATTRIBUTE __ISR(_RTCC_VECTOR, IPL4SRS)
```

```c
#define AO_IR_RTCC_PRIO (4)
```

```c
#define AO_IR_RTCC_SUBPRIO (0)
```

# Functions

```c
#define ao_ir_rtcc_disable()
```

```c
#define ao_ir_rtcc_enable()
```

```c
#define ao_ir_rtcc_is_enabled()
```

```c
#define ao_ir_rtcc_is_pending()
```

```c
#define ao_ir_rtcc_reply()
```

```c
#define ao_ir_rtcc_request()
```


---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The /src/ao_sys_xc32_pic32mx_3xx/ao_ir_fscm.h file of the ao real-time operating system."
draft: true
permalink: /api/src/ao_sys_xc32_pic32mx_3xx/ao_ir_fscm.h/
subtitle: ""
title: "ao_ir_fscm.h"
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
#define AO_IR_FSCM_ATTRIBUTE __ISR(_FAIL_SAFE_MONITOR_VECTOR, IPL4SOFT)
```

```c
#define AO_IR_FSCM_PRIO (4)
```

```c
#define AO_IR_FSCM_SUBPRIO (0)
```

# Functions

```c
#define ao_ir_fscm_disable()
```

```c
#define ao_ir_fscm_enable()
```

```c
#define ao_ir_fscm_is_enabled()
```

```c
#define ao_ir_fscm_is_pending()
```

```c
#define ao_ir_fscm_reply()
```

```c
#define ao_ir_fscm_request()
```


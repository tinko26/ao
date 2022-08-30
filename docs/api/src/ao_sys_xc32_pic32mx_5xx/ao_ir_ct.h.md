---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The /src/ao_sys_xc32_pic32mx_5xx/ao_ir_ct.h file of the ao real-time operating system."
draft: true
permalink: /api/src/ao_sys_xc32_pic32mx_5xx/ao_ir_ct.h/
subtitle: ""
title: "ao_ir_ct.h"
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
#define AO_IR_CT_ATTRIBUTE __ISR(_CORE_TIMER_VECTOR, IPL3SOFT)
```

```c
#define AO_IR_CT_PRIO (3)
```

```c
#define AO_IR_CT_SUBPRIO (0)
```

# Functions

```c
#define ao_ir_ct_disable()
```

```c
#define ao_ir_ct_enable()
```

```c
#define ao_ir_ct_is_enabled()
```

```c
#define ao_ir_ct_is_pending()
```

```c
#define ao_ir_ct_reply()
```

```c
#define ao_ir_ct_request()
```


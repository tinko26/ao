---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The /src/ao_sys_xc32_pic32mk_gp/ao_ir_dataee.h file of the ao real-time operating system."
draft: true
permalink: /api/src/ao_sys_xc32_pic32mk_gp/ao_ir_dataee.h/
subtitle: ""
title: "ao_ir_dataee.h"
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
#define AO_IR_DATAEE_ATTRIBUTE __ISR(_DATA_EE_VECTOR, IPL4SOFT)
```

```c
#define AO_IR_DATAEE_PRIO (4)
```

```c
#define AO_IR_DATAEE_SUBPRIO (0)
```

# Functions

```c
#define ao_ir_dataee_disable()
```

```c
#define ao_ir_dataee_enable()
```

```c
#define ao_ir_dataee_is_enabled()
```

```c
#define ao_ir_dataee_is_pending()
```

```c
#define ao_ir_dataee_reply()
```

```c
#define ao_ir_dataee_request()
```


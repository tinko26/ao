---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The /src/ao_sys_xc32_pic32mx_1xx_64_100/ao_ir_can.h file of the ao real-time operating system."
draft: true
permalink: /api/src/ao_sys_xc32_pic32mx_1xx_64_100/ao_ir_can.h/
subtitle: ""
title: "ao_ir_can.h"
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
#define AO_IR_CAN1_ATTRIBUTE __ISR(_CAN_1_VECTOR, IPL4SOFT)
```

```c
#define AO_IR_CAN1_PRIO (4)
```

```c
#define AO_IR_CAN1_SUBPRIO (0)
```

# Functions

```c
#define ao_ir_can1_disable()
```

```c
#define ao_ir_can1_enable()
```

```c
#define ao_ir_can1_is_enabled()
```

```c
#define ao_ir_can1_is_pending()
```

```c
#define ao_ir_can1_reply()
```

```c
#define ao_ir_can1_request()
```

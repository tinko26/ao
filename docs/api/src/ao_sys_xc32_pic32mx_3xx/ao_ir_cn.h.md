---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The /src/ao_sys_xc32_pic32mx_3xx/ao_ir_cn.h file of the ao real-time operating system."
draft: true
permalink: /api/src/ao_sys_xc32_pic32mx_3xx/ao_ir_cn.h/
subtitle: "Change notification interrupt"
title: "ao_ir_cn.h"
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
#define AO_IR_CN_ATTRIBUTE __ISR(_CHANGE_NOTICE_VECTOR, IPL4SOFT)
```

```c
#define AO_IR_CN_PRIO (4)
```

```c
#define AO_IR_CN_SUBPRIO (0)
```

# Functions

```c
#define ao_ir_cn_disable()
```

```c
#define ao_ir_cn_enable()
```

```c
#define ao_ir_cn_is_enabled()
```

```c
#define ao_ir_cn_is_pending()
```

```c
#define ao_ir_cn_reply()
```

```c
#define ao_ir_cn_request()
```

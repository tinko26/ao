---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The /src/ao_sys_xc32_pic32mx_1xx_xlp/ao_ir_cn.h file of the ao real-time operating system."
draft: true
permalink: /api/src/ao_sys_xc32_pic32mx_1xx_xlp/ao_ir_cn.h/
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
#define ao_ir_cna_disable()
```

```c
#define ao_ir_cna_enable()
```

```c
#define ao_ir_cna_is_enabled()
```

```c
#define ao_ir_cna_is_pending()
```

```c
#define ao_ir_cna_reply()
```

```c
#define ao_ir_cna_request()
```

```c
#define ao_ir_cnb_disable()
```

```c
#define ao_ir_cnb_enable()
```

```c
#define ao_ir_cnb_is_enabled()
```

```c
#define ao_ir_cnb_is_pending()
```

```c
#define ao_ir_cnb_reply()
```

```c
#define ao_ir_cnb_request()
```

```c
#define ao_ir_cnc_disable()
```

```c
#define ao_ir_cnc_enable()
```

```c
#define ao_ir_cnc_is_enabled()
```

```c
#define ao_ir_cnc_is_pending()
```

```c
#define ao_ir_cnc_reply()
```

```c
#define ao_ir_cnc_request()
```

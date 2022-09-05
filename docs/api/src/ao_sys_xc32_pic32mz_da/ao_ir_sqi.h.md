---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The /src/ao_sys_xc32_pic32mz_da/ao_ir_sqi.h file of the ao real-time operating system."
draft: true
permalink: /api/src/ao_sys_xc32_pic32mz_da/ao_ir_sqi.h/
subtitle: "SQI interrupt"
title: "ao_ir_sqi.h"
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
#define AO_IR_SQI1_ATTRIBUTE __ISR(_SQI1_VECTOR, IPL4SRS)
```

```c
#define AO_IR_SQI1_PRIO (4)
```

```c
#define AO_IR_SQI1_SUBPRIO (0)
```

# Functions

```c
#define ao_ir_sqi1_disable()
```

```c
#define ao_ir_sqi1_enable()
```

```c
#define ao_ir_sqi1_is_enabled()
```

```c
#define ao_ir_sqi1_is_pending()
```

```c
#define ao_ir_sqi1_reply()
```

```c
#define ao_ir_sqi1_request()
```

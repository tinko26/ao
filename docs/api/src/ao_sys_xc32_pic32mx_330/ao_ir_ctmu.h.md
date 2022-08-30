---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The /src/ao_sys_xc32_pic32mx_330/ao_ir_ctmu.h file of the ao real-time operating system."
draft: true
permalink: /api/src/ao_sys_xc32_pic32mx_330/ao_ir_ctmu.h/
subtitle: ""
title: "ao_ir_ctmu.h"
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
#define AO_IR_CTMU_ATTRIBUTE __ISR(_CTMU_VECTOR, IPL4SOFT)
```

```c
#define AO_IR_CTMU_PRIO (4)
```

```c
#define AO_IR_CTMU_SUBPRIO (0)
```

# Functions

```c
#define ao_ir_ctmu_disable()
```

```c
#define ao_ir_ctmu_enable()
```

```c
#define ao_ir_ctmu_is_enabled()
```

```c
#define ao_ir_ctmu_is_pending()
```

```c
#define ao_ir_ctmu_reply()
```

```c
#define ao_ir_ctmu_request()
```


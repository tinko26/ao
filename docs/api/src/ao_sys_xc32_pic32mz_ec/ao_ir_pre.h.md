---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The /src/ao_sys_xc32_pic32mz_ec/ao_ir_pre.h file of the ao real-time operating system."
draft: true
permalink: /api/src/ao_sys_xc32_pic32mz_ec/ao_ir_pre.h/
subtitle: "Prefetch module interrupt"
title: "ao_ir_pre.h"
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
#define AO_IR_PRE_ATTRIBUTE __ISR(_PREFETCH_VECTOR, IPL4SRS)
```

```c
#define AO_IR_PRE_PRIO (4)
```

```c
#define AO_IR_PRE_SUBPRIO (0)
```

# Functions

```c
#define ao_ir_pre_disable()
```

```c
#define ao_ir_pre_enable()
```

```c
#define ao_ir_pre_is_enabled()
```

```c
#define ao_ir_pre_is_pending()
```

```c
#define ao_ir_pre_reply()
```

```c
#define ao_ir_pre_request()
```

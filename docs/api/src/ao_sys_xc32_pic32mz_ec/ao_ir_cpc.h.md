---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The /src/ao_sys_xc32_pic32mz_ec/ao_ir_cpc.h file of the ao real-time operating system."
draft: true
permalink: /api/src/ao_sys_xc32_pic32mz_ec/ao_ir_cpc.h/
subtitle: "Core performance counter interrupt"
title: "ao_ir_cpc.h"
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
#define AO_IR_CPC_ATTRIBUTE __ISR(_CORE_PERF_COUNT_VECTOR, IPL4SRS)
```

```c
#define AO_IR_CPC_PRIO (4)
```

```c
#define AO_IR_CPC_SUBPRIO (0)
```

# Functions

```c
#define ao_ir_cpc_disable()
```

```c
#define ao_ir_cpc_enable()
```

```c
#define ao_ir_cpc_is_enabled()
```

```c
#define ao_ir_cpc_is_pending()
```

```c
#define ao_ir_cpc_reply()
```

```c
#define ao_ir_cpc_request()
```

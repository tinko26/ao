---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The /src/ao_sys_xc32_pic32mz_da/ao_ir_gpu.h file of the ao real-time operating system."
draft: true
permalink: /api/src/ao_sys_xc32_pic32mz_da/ao_ir_gpu.h/
subtitle: ""
title: "ao_ir_gpu.h"
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
#define AO_IR_GPU_ATTRIBUTE __ISR(_GPU_VECTOR, IPL4SRS)
```

```c
#define AO_IR_GPU_PRIO (4)
```

```c
#define AO_IR_GPU_SUBPRIO (0)
```

# Functions

```c
#define ao_ir_gpu_disable()
```

```c
#define ao_ir_gpu_enable()
```

```c
#define ao_ir_gpu_is_enabled()
```

```c
#define ao_ir_gpu_is_pending()
```

```c
#define ao_ir_gpu_reply()
```

```c
#define ao_ir_gpu_request()
```


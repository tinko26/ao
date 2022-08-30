---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The /src/ao_sys_xc32_pic32mz_dak/ao_ir_cfdc.h file of the ao real-time operating system."
draft: true
permalink: /src/ao_sys_xc32_pic32mz_dak/ao_ir_cfdc.h/
subtitle: ""
title: "ao_ir_cfdc.h"
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
#define AO_IR_CFDC_ATTRIBUTE __ISR(_CORE_FAST_DEBUG_CHAN_VECTOR, IPL4SRS)
```

```c
#define AO_IR_CFDC_PRIO (4)
```

```c
#define AO_IR_CFDC_SUBPRIO (0)
```

# Functions

```c
#define ao_ir_cfdc_disable()
```

```c
#define ao_ir_cfdc_enable()
```

```c
#define ao_ir_cfdc_is_enabled()
```

```c
#define ao_ir_cfdc_is_pending()
```

```c
#define ao_ir_cfdc_reply()
```

```c
#define ao_ir_cfdc_request()
```


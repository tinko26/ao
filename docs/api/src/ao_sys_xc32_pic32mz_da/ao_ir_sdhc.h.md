---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The /src/ao_sys_xc32_pic32mz_da/ao_ir_sdhc.h file of the ao real-time operating system."
draft: true
permalink: /api/src/ao_sys_xc32_pic32mz_da/ao_ir_sdhc.h/
subtitle: ""
title: "ao_ir_sdhc.h"
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
#define AO_IR_SDHC_ATTRIBUTE __ISR(_SDHC_VECTOR, IPL4SRS)
```

```c
#define AO_IR_SDHC_PRIO (4)
```

```c
#define AO_IR_SDHC_SUBPRIO (0)
```

# Functions

```c
#define ao_ir_sdhc_disable()
```

```c
#define ao_ir_sdhc_enable()
```

```c
#define ao_ir_sdhc_is_enabled()
```

```c
#define ao_ir_sdhc_is_pending()
```

```c
#define ao_ir_sdhc_reply()
```

```c
#define ao_ir_sdhc_request()
```

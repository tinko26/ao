---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The /src/ao_sys_xc32_pic32mk_gpk/ao_ir_sb.h file of the ao real-time operating system."
draft: true
permalink: /api/src/ao_sys_xc32_pic32mk_gpk/ao_ir_sb.h/
subtitle: "System bus protection violation interrupt"
title: "ao_ir_sb.h"
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
#define AO_IR_SB_ATTRIBUTE __ISR(_SYSTEM_BUS_PROTECTION_VECTOR, IPL4SRS)
```

```c
#define AO_IR_SB_PRIO (4)
```

```c
#define AO_IR_SB_SUBPRIO (0)
```

# Functions

```c
#define ao_ir_sb_disable()
```

```c
#define ao_ir_sb_enable()
```

```c
#define ao_ir_sb_is_enabled()
```

```c
#define ao_ir_sb_is_pending()
```

```c
#define ao_ir_sb_reply()
```

```c
#define ao_ir_sb_request()
```

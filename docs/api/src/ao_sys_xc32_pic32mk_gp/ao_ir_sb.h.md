---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The ao_sys_xc32_pic32mk_gp/ao_ir_sb.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys_xc32_pic32mk_gp/ao_ir_sb.h/
subtitle: ""
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
#define AO_IR_SB_ATTRIBUTE __ISR(_SYSTEM_BUS_PROTECTION_VECTOR, IPL4SOFT)
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

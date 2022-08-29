---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The /src/ao_sys_xc32_pic32mk_gp/ao_ir_fce.h file of the ao real-time operating system."
draft: true
permalink: /src/ao_sys_xc32_pic32mk_gp/ao_ir_fce.h/ 
subtitle: ""
title: "ao_ir_fce.h"
toc: true
---

# Includes

```c
#include <stdbool.h>
#include <sys/attribs.h>
#include <xc.h>
```

```c
#define AO_IR_FCE_ATTRIBUTE     __ISR(_FLASH_CONTROL_VECTOR, IPL4SOFT)
```

```c
#define AO_IR_FCE_PRIO          (4)
```

```c
#define AO_IR_FCE_SUBPRIO       (0)
```

```c
#define ao_ir_fce_disable()
```

```c
#define ao_ir_fce_enable()
```

```c
#define ao_ir_fce_is_enabled()
```

```c
#define ao_ir_fce_is_pending()
```

```c
#define ao_ir_fce_reply()
```

```c
#define ao_ir_fce_request()
```


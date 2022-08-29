---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The ao_sys_xc32_pic32mk_gp/ao_ir_rtcc.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys_xc32_pic32mk_gp/ao_ir_rtcc.h/ 
subtitle: ""
title: "ao_ir_rtcc.h"
toc: true
---

# Includes

```c
#include <stdbool.h>
#include <sys/attribs.h>
#include <xc.h>
```

```c
#define AO_IR_RTCC_ATTRIBUTE        __ISR(_RTCC_VECTOR, IPL4SOFT)
```

```c
#define AO_IR_RTCC_PRIO             (4)
```

```c
#define AO_IR_RTCC_SUBPRIO          (0)
```

```c
#define ao_ir_rtcc_disable()
```

```c
#define ao_ir_rtcc_enable()
```

```c
#define ao_ir_rtcc_is_enabled()
```

```c
#define ao_ir_rtcc_is_pending()
```

```c
#define ao_ir_rtcc_reply()
```

```c
#define ao_ir_rtcc_request()
```


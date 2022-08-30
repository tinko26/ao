---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The /src/ao_sys_xc32_pic32mz_ef/ao_ir_crpt.h file of the ao real-time operating system."
draft: true
permalink: /api/src/ao_sys_xc32_pic32mz_ef/ao_ir_crpt.h/
subtitle: ""
title: "ao_ir_crpt.h"
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
#define AO_IR_CRPT_ATTRIBUTE __ISR(_CRYPTO_VECTOR, IPL4SRS)
```

```c
#define AO_IR_CRPT_PRIO (4)
```

```c
#define AO_IR_CRPT_SUBPRIO (0)
```

# Functions

```c
#define ao_ir_crpt_disable()
```

```c
#define ao_ir_crpt_enable()
```

```c
#define ao_ir_crpt_is_enabled()
```

```c
#define ao_ir_crpt_is_pending()
```

```c
#define ao_ir_crpt_reply()
```

```c
#define ao_ir_crpt_request()
```


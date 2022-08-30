---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The /src/ao_sys_xc32_pic32mk_gpg/ao_ir_pcache.h file of the ao real-time operating system."
draft: true
permalink: /api/src/ao_sys_xc32_pic32mk_gpg/ao_ir_pcache.h/
subtitle: ""
title: "ao_ir_pcache.h"
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
#define AO_IR_PCACHE_ATTRIBUTE __ISR(_PCACHE_VECTOR, IPL4SRS)
```

```c
#define AO_IR_PCACHE_PRIO (4)
```

```c
#define AO_IR_PCACHE_SUBPRIO (0)
```

# Functions

```c
#define ao_ir_pcache_disable()
```

```c
#define ao_ir_pcache_enable()
```

```c
#define ao_ir_pcache_is_enabled()
```

```c
#define ao_ir_pcache_is_pending()
```

```c
#define ao_ir_pcache_reply()
```

```c
#define ao_ir_pcache_request()
```


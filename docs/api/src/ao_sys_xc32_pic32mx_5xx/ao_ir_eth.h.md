---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The /src/ao_sys_xc32_pic32mx_5xx/ao_ir_eth.h file of the ao real-time operating system."
draft: true
permalink: /api/src/ao_sys_xc32_pic32mx_5xx/ao_ir_eth.h/
subtitle: "Ethernet interrupt"
title: "ao_ir_eth.h"
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
#define AO_IR_ETH_ATTRIBUTE __ISR(_ETH_VECTOR, IPL4SOFT)
```

```c
#define AO_IR_ETH_PRIO (4)
```

```c
#define AO_IR_ETH_SUBPRIO (0)
```

# Functions

```c
#define ao_ir_eth_disable()
```

```c
#define ao_ir_eth_enable()
```

```c
#define ao_ir_eth_is_enabled()
```

```c
#define ao_ir_eth_is_pending()
```

```c
#define ao_ir_eth_reply()
```

```c
#define ao_ir_eth_request()
```

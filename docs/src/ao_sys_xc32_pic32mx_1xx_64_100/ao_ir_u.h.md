---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The /src/ao_sys_xc32_pic32mx_1xx_64_100/ao_ir_u.h file of the ao real-time operating system."
draft: true
permalink: /src/ao_sys_xc32_pic32mx_1xx_64_100/ao_ir_u.h/
subtitle: ""
title: "ao_ir_u.h"
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
#define AO_IR_U1_ATTRIBUTE __ISR(_UART_1_VECTOR, IPL4SOFT)
```

```c
#define AO_IR_U1_PRIO (4)
```

```c
#define AO_IR_U1_SUBPRIO (0)
```

```c
#define AO_IR_U2_ATTRIBUTE __ISR(_UART_2_VECTOR, IPL4SOFT)
```

```c
#define AO_IR_U2_PRIO (4)
```

```c
#define AO_IR_U2_SUBPRIO (0)
```

```c
#define AO_IR_U3_ATTRIBUTE __ISR(_UART_3_VECTOR, IPL4SOFT)
```

```c
#define AO_IR_U3_PRIO (4)
```

```c
#define AO_IR_U3_SUBPRIO (0)
```

```c
#define AO_IR_U4_ATTRIBUTE __ISR(_UART_4_VECTOR, IPL4SOFT)
```

```c
#define AO_IR_U4_PRIO (4)
```

```c
#define AO_IR_U4_SUBPRIO (0)
```

```c
#define AO_IR_U5_ATTRIBUTE __ISR(_UART_5_VECTOR, IPL4SOFT)
```

```c
#define AO_IR_U5_PRIO (4)
```

```c
#define AO_IR_U5_SUBPRIO (0)
```

# Functions

```c
#define ao_ir_u1e_disable()
```

```c
#define ao_ir_u1e_enable()
```

```c
#define ao_ir_u1e_is_enabled()
```

```c
#define ao_ir_u1e_is_pending()
```

```c
#define ao_ir_u1e_reply()
```

```c
#define ao_ir_u1e_request()
```

```c
#define ao_ir_u1rx_disable()
```

```c
#define ao_ir_u1rx_enable()
```

```c
#define ao_ir_u1rx_is_enabled()
```

```c
#define ao_ir_u1rx_is_pending()
```

```c
#define ao_ir_u1rx_reply()
```

```c
#define ao_ir_u1rx_request()
```

```c
#define ao_ir_u1tx_disable()
```

```c
#define ao_ir_u1tx_enable()
```

```c
#define ao_ir_u1tx_is_enabled()
```

```c
#define ao_ir_u1tx_is_pending()
```

```c
#define ao_ir_u1tx_reply()
```

```c
#define ao_ir_u1tx_request()
```

```c
#define ao_ir_u2e_disable()
```

```c
#define ao_ir_u2e_enable()
```

```c
#define ao_ir_u2e_is_enabled()
```

```c
#define ao_ir_u2e_is_pending()
```

```c
#define ao_ir_u2e_reply()
```

```c
#define ao_ir_u2e_request()
```

```c
#define ao_ir_u2rx_disable()
```

```c
#define ao_ir_u2rx_enable()
```

```c
#define ao_ir_u2rx_is_enabled()
```

```c
#define ao_ir_u2rx_is_pending()
```

```c
#define ao_ir_u2rx_reply()
```

```c
#define ao_ir_u2rx_request()
```

```c
#define ao_ir_u2tx_disable()
```

```c
#define ao_ir_u2tx_enable()
```

```c
#define ao_ir_u2tx_is_enabled()
```

```c
#define ao_ir_u2tx_is_pending()
```

```c
#define ao_ir_u2tx_reply()
```

```c
#define ao_ir_u2tx_request()
```

```c
#define ao_ir_u3e_disable()
```

```c
#define ao_ir_u3e_enable()
```

```c
#define ao_ir_u3e_is_enabled()
```

```c
#define ao_ir_u3e_is_pending()
```

```c
#define ao_ir_u3e_reply()
```

```c
#define ao_ir_u3e_request()
```

```c
#define ao_ir_u3rx_disable()
```

```c
#define ao_ir_u3rx_enable()
```

```c
#define ao_ir_u3rx_is_enabled()
```

```c
#define ao_ir_u3rx_is_pending()
```

```c
#define ao_ir_u3rx_reply()
```

```c
#define ao_ir_u3rx_request()
```

```c
#define ao_ir_u3tx_disable()
```

```c
#define ao_ir_u3tx_enable()
```

```c
#define ao_ir_u3tx_is_enabled()
```

```c
#define ao_ir_u3tx_is_pending()
```

```c
#define ao_ir_u3tx_reply()
```

```c
#define ao_ir_u3tx_request()
```

```c
#define ao_ir_u4e_disable()
```

```c
#define ao_ir_u4e_enable()
```

```c
#define ao_ir_u4e_is_enabled()
```

```c
#define ao_ir_u4e_is_pending()
```

```c
#define ao_ir_u4e_reply()
```

```c
#define ao_ir_u4e_request()
```

```c
#define ao_ir_u4rx_disable()
```

```c
#define ao_ir_u4rx_enable()
```

```c
#define ao_ir_u4rx_is_enabled()
```

```c
#define ao_ir_u4rx_is_pending()
```

```c
#define ao_ir_u4rx_reply()
```

```c
#define ao_ir_u4rx_request()
```

```c
#define ao_ir_u4tx_disable()
```

```c
#define ao_ir_u4tx_enable()
```

```c
#define ao_ir_u4tx_is_enabled()
```

```c
#define ao_ir_u4tx_is_pending()
```

```c
#define ao_ir_u4tx_reply()
```

```c
#define ao_ir_u4tx_request()
```

```c
#define ao_ir_u5e_disable()
```

```c
#define ao_ir_u5e_enable()
```

```c
#define ao_ir_u5e_is_enabled()
```

```c
#define ao_ir_u5e_is_pending()
```

```c
#define ao_ir_u5e_reply()
```

```c
#define ao_ir_u5e_request()
```

```c
#define ao_ir_u5rx_disable()
```

```c
#define ao_ir_u5rx_enable()
```

```c
#define ao_ir_u5rx_is_enabled()
```

```c
#define ao_ir_u5rx_is_pending()
```

```c
#define ao_ir_u5rx_reply()
```

```c
#define ao_ir_u5rx_request()
```

```c
#define ao_ir_u5tx_disable()
```

```c
#define ao_ir_u5tx_enable()
```

```c
#define ao_ir_u5tx_is_enabled()
```

```c
#define ao_ir_u5tx_is_pending()
```

```c
#define ao_ir_u5tx_reply()
```

```c
#define ao_ir_u5tx_request()
```


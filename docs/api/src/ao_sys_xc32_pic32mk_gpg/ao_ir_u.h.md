---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The /src/ao_sys_xc32_pic32mk_gpg/ao_ir_u.h file of the ao real-time operating system."
draft: true
permalink: /api/src/ao_sys_xc32_pic32mk_gpg/ao_ir_u.h/
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
#define AO_IR_U1E_ATTRIBUTE __ISR(_UART1_FAULT_VECTOR, IPL4SRS)
```

```c
#define AO_IR_U1E_PRIO (4)
```

```c
#define AO_IR_U1E_SUBPRIO (0)
```

```c
#define AO_IR_U1RX_ATTRIBUTE __ISR(_UART1_RX_VECTOR, IPL4SRS)
```

```c
#define AO_IR_U1RX_PRIO (4)
```

```c
#define AO_IR_U1RX_SUBPRIO (0)
```

```c
#define AO_IR_U1TX_ATTRIBUTE __ISR(_UART1_TX_VECTOR, IPL4SRS)
```

```c
#define AO_IR_U1TX_PRIO (4)
```

```c
#define AO_IR_U1TX_SUBPRIO (0)
```

```c
#define AO_IR_U2E_ATTRIBUTE __ISR(_UART2_FAULT_VECTOR, IPL4SRS)
```

```c
#define AO_IR_U2E_PRIO (4)
```

```c
#define AO_IR_U2E_SUBPRIO (0)
```

```c
#define AO_IR_U2RX_ATTRIBUTE __ISR(_UART2_RX_VECTOR, IPL4SRS)
```

```c
#define AO_IR_U2RX_PRIO (4)
```

```c
#define AO_IR_U2RX_SUBPRIO (0)
```

```c
#define AO_IR_U2TX_ATTRIBUTE __ISR(_UART2_TX_VECTOR, IPL4SRS)
```

```c
#define AO_IR_U2TX_PRIO (4)
```

```c
#define AO_IR_U2TX_SUBPRIO (0)
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


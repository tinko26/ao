---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The /src/ao_sys_xc32_pic32mk_gp/ao_ir_u.h file of the ao real-time operating system."
draft: true
permalink: /src/ao_sys_xc32_pic32mk_gp/ao_ir_u.h/ 
subtitle: ""
title: "ao_ir_u.h"
toc: true
---

# Includes

```c
#include <stdbool.h>
#include <sys/attribs.h>
#include <xc.h>
```

```c
#define AO_IR_U1E_ATTRIBUTE         __ISR(_UART1_FAULT_VECTOR, IPL4SOFT)
```

```c
#define AO_IR_U1E_PRIO              (4)
```

```c
#define AO_IR_U1E_SUBPRIO           (0)
```

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
#define AO_IR_U1RX_ATTRIBUTE        __ISR(_UART1_RX_VECTOR, IPL4SOFT)
```

```c
#define AO_IR_U1RX_PRIO             (4)
```

```c
#define AO_IR_U1RX_SUBPRIO          (0)
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
#define AO_IR_U1TX_ATTRIBUTE        __ISR(_UART1_TX_VECTOR, IPL4SOFT)
```

```c
#define AO_IR_U1TX_PRIO             (4)
```

```c
#define AO_IR_U1TX_SUBPRIO          (0)
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
#define AO_IR_U2E_ATTRIBUTE         __ISR(_UART2_FAULT_VECTOR, IPL4SOFT)
```

```c
#define AO_IR_U2E_PRIO              (4)
```

```c
#define AO_IR_U2E_SUBPRIO           (0)
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
#define AO_IR_U2RX_ATTRIBUTE        __ISR(_UART2_RX_VECTOR, IPL4SOFT)
```

```c
#define AO_IR_U2RX_PRIO             (4)
```

```c
#define AO_IR_U2RX_SUBPRIO          (0)
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
#define AO_IR_U2TX_ATTRIBUTE        __ISR(_UART2_TX_VECTOR, IPL4SOFT)
```

```c
#define AO_IR_U2TX_PRIO             (4)
```

```c
#define AO_IR_U2TX_SUBPRIO          (0)
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
#define AO_IR_U3E_ATTRIBUTE         __ISR(_UART3_FAULT_VECTOR, IPL4SOFT)
```

```c
#define AO_IR_U3E_PRIO              (4)
```

```c
#define AO_IR_U3E_SUBPRIO           (0)
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
#define AO_IR_U3RX_ATTRIBUTE        __ISR(_UART3_RX_VECTOR, IPL4SOFT)
```

```c
#define AO_IR_U3RX_PRIO             (4)
```

```c
#define AO_IR_U3RX_SUBPRIO          (0)
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
#define AO_IR_U3TX_ATTRIBUTE        __ISR(_UART3_TX_VECTOR, IPL4SOFT)
```

```c
#define AO_IR_U3TX_PRIO             (4)
```

```c
#define AO_IR_U3TX_SUBPRIO          (0)
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
#define AO_IR_U4E_ATTRIBUTE         __ISR(_UART4_FAULT_VECTOR, IPL4SOFT)
```

```c
#define AO_IR_U4E_PRIO              (4)
```

```c
#define AO_IR_U4E_SUBPRIO           (0)
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
#define AO_IR_U4RX_ATTRIBUTE        __ISR(_UART4_RX_VECTOR, IPL4SOFT)
```

```c
#define AO_IR_U4RX_PRIO             (4)
```

```c
#define AO_IR_U4RX_SUBPRIO          (0)
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
#define AO_IR_U4TX_ATTRIBUTE        __ISR(_UART4_TX_VECTOR, IPL4SOFT)
```

```c
#define AO_IR_U4TX_PRIO             (4)
```

```c
#define AO_IR_U4TX_SUBPRIO          (0)
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
#define AO_IR_U5E_ATTRIBUTE         __ISR(_UART5_FAULT_VECTOR, IPL4SOFT)
```

```c
#define AO_IR_U5E_PRIO              (4)
```

```c
#define AO_IR_U5E_SUBPRIO           (0)
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
#define AO_IR_U5RX_ATTRIBUTE        __ISR(_UART5_RX_VECTOR, IPL4SOFT)
```

```c
#define AO_IR_U5RX_PRIO             (4)
```

```c
#define AO_IR_U5RX_SUBPRIO          (0)
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
#define AO_IR_U5TX_ATTRIBUTE        __ISR(_UART5_TX_VECTOR, IPL4SOFT)
```

```c
#define AO_IR_U5TX_PRIO             (4)
```

```c
#define AO_IR_U5TX_SUBPRIO          (0)
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

```c
#define AO_IR_U6E_ATTRIBUTE         __ISR(_UART6_FAULT_VECTOR, IPL4SOFT)
```

```c
#define AO_IR_U6E_PRIO              (4)
```

```c
#define AO_IR_U6E_SUBPRIO           (0)
```

```c
#define ao_ir_u6e_disable()
```

```c
#define ao_ir_u6e_enable()
```

```c
#define ao_ir_u6e_is_enabled()
```

```c
#define ao_ir_u6e_is_pending()
```

```c
#define ao_ir_u6e_reply()
```

```c
#define ao_ir_u6e_request()
```

```c
#define AO_IR_U6RX_ATTRIBUTE        __ISR(_UART6_RX_VECTOR, IPL4SOFT)
```

```c
#define AO_IR_U6RX_PRIO             (4)
```

```c
#define AO_IR_U6RX_SUBPRIO          (0)
```

```c
#define ao_ir_u6rx_disable()
```

```c
#define ao_ir_u6rx_enable()
```

```c
#define ao_ir_u6rx_is_enabled()
```

```c
#define ao_ir_u6rx_is_pending()
```

```c
#define ao_ir_u6rx_reply()
```

```c
#define ao_ir_u6rx_request()
```

```c
#define AO_IR_U6TX_ATTRIBUTE        __ISR(_UART6_TX_VECTOR, IPL4SOFT)
```

```c
#define AO_IR_U6TX_PRIO             (4)
```

```c
#define AO_IR_U6TX_SUBPRIO          (0)
```

```c
#define ao_ir_u6tx_disable()
```

```c
#define ao_ir_u6tx_enable()
```

```c
#define ao_ir_u6tx_is_enabled()
```

```c
#define ao_ir_u6tx_is_pending()
```

```c
#define ao_ir_u6tx_reply()
```

```c
#define ao_ir_u6tx_request()
```


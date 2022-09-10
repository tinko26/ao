---
author: "Stefan Wagner"
date: 2022-09-05
draft: true
permalink: /api/src/ao_sys_xc32_pic32mz_ef/ao_ir_eth.h/
toc: true
---

# Include

```c
#include <stdbool.h>
#include <sys/attribs.h>
#include <xc.h>
```

# Configuration

## `AO_IR_ETH`

```c
#define AO_IR_ETH_ATTRIBUTE __ISR(_ETHERNET_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_ETH_PRIO    (4)
#define AO_IR_ETH_SUBPRIO (0)
```

The interrupt priority and subpriority.

# Functions

## `ao_ir_eth`

```c
#define ao_ir_eth_enable()
#define ao_ir_eth_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_eth_request()
#define ao_ir_eth_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_eth_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_eth_is_pending()
```

Checks whether the interrupt is pending.

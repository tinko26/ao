---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The /src/ao_sys_xc32_pic32mz_ef/ao_ir_i2c.h file of the ao real-time operating system."
draft: true
permalink: /src/ao_sys_xc32_pic32mz_ef/ao_ir_i2c.h/
subtitle: ""
title: "ao_ir_i2c.h"
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
#define AO_IR_I2C1B_ATTRIBUTE __ISR(_I2C1_BUS_VECTOR, IPL4SRS)
```

```c
#define AO_IR_I2C1B_PRIO (4)
```

```c
#define AO_IR_I2C1B_SUBPRIO (0)
```

```c
#define AO_IR_I2C1M_ATTRIBUTE __ISR(_I2C1_MASTER_VECTOR, IPL4SRS)
```

```c
#define AO_IR_I2C1M_PRIO (4)
```

```c
#define AO_IR_I2C1M_SUBPRIO (0)
```

```c
#define AO_IR_I2C1S_ATTRIBUTE __ISR(_I2C1_SLAVE_VECTOR, IPL4SRS)
```

```c
#define AO_IR_I2C1S_PRIO (4)
```

```c
#define AO_IR_I2C1S_SUBPRIO (0)
```

```c
#define AO_IR_I2C2B_ATTRIBUTE __ISR(_I2C2_BUS_VECTOR, IPL4SRS)
```

```c
#define AO_IR_I2C2B_PRIO (4)
```

```c
#define AO_IR_I2C2B_SUBPRIO (0)
```

```c
#define AO_IR_I2C2M_ATTRIBUTE __ISR(_I2C2_MASTER_VECTOR, IPL4SRS)
```

```c
#define AO_IR_I2C2M_PRIO (4)
```

```c
#define AO_IR_I2C2M_SUBPRIO (0)
```

```c
#define AO_IR_I2C2S_ATTRIBUTE __ISR(_I2C2_SLAVE_VECTOR, IPL4SRS)
```

```c
#define AO_IR_I2C2S_PRIO (4)
```

```c
#define AO_IR_I2C2S_SUBPRIO (0)
```

```c
#define AO_IR_I2C3B_ATTRIBUTE __ISR(_I2C3_BUS_VECTOR, IPL4SRS)
```

```c
#define AO_IR_I2C3B_PRIO (4)
```

```c
#define AO_IR_I2C3B_SUBPRIO (0)
```

```c
#define AO_IR_I2C3M_ATTRIBUTE __ISR(_I2C3_MASTER_VECTOR, IPL4SRS)
```

```c
#define AO_IR_I2C3M_PRIO (4)
```

```c
#define AO_IR_I2C3M_SUBPRIO (0)
```

```c
#define AO_IR_I2C3S_ATTRIBUTE __ISR(_I2C3_SLAVE_VECTOR, IPL4SRS)
```

```c
#define AO_IR_I2C3S_PRIO (4)
```

```c
#define AO_IR_I2C3S_SUBPRIO (0)
```

```c
#define AO_IR_I2C4B_ATTRIBUTE __ISR(_I2C4_BUS_VECTOR, IPL4SRS)
```

```c
#define AO_IR_I2C4B_PRIO (4)
```

```c
#define AO_IR_I2C4B_SUBPRIO (0)
```

```c
#define AO_IR_I2C4M_ATTRIBUTE __ISR(_I2C4_MASTER_VECTOR, IPL4SRS)
```

```c
#define AO_IR_I2C4M_PRIO (4)
```

```c
#define AO_IR_I2C4M_SUBPRIO (0)
```

```c
#define AO_IR_I2C4S_ATTRIBUTE __ISR(_I2C4_SLAVE_VECTOR, IPL4SRS)
```

```c
#define AO_IR_I2C4S_PRIO (4)
```

```c
#define AO_IR_I2C4S_SUBPRIO (0)
```

```c
#define AO_IR_I2C5B_ATTRIBUTE __ISR(_I2C5_BUS_VECTOR, IPL4SRS)
```

```c
#define AO_IR_I2C5B_PRIO (4)
```

```c
#define AO_IR_I2C5B_SUBPRIO (0)
```

```c
#define AO_IR_I2C5M_ATTRIBUTE __ISR(_I2C5_MASTER_VECTOR, IPL4SRS)
```

```c
#define AO_IR_I2C5M_PRIO (4)
```

```c
#define AO_IR_I2C5M_SUBPRIO (0)
```

```c
#define AO_IR_I2C5S_ATTRIBUTE __ISR(_I2C5_SLAVE_VECTOR, IPL4SRS)
```

```c
#define AO_IR_I2C5S_PRIO (4)
```

```c
#define AO_IR_I2C5S_SUBPRIO (0)
```

# Functions

```c
#define ao_ir_i2c1b_disable()
```

```c
#define ao_ir_i2c1b_enable()
```

```c
#define ao_ir_i2c1b_is_enabled()
```

```c
#define ao_ir_i2c1b_is_pending()
```

```c
#define ao_ir_i2c1b_reply()
```

```c
#define ao_ir_i2c1b_request()
```

```c
#define ao_ir_i2c1m_disable()
```

```c
#define ao_ir_i2c1m_enable()
```

```c
#define ao_ir_i2c1m_is_enabled()
```

```c
#define ao_ir_i2c1m_is_pending()
```

```c
#define ao_ir_i2c1m_reply()
```

```c
#define ao_ir_i2c1m_request()
```

```c
#define ao_ir_i2c1s_disable()
```

```c
#define ao_ir_i2c1s_enable()
```

```c
#define ao_ir_i2c1s_is_enabled()
```

```c
#define ao_ir_i2c1s_is_pending()
```

```c
#define ao_ir_i2c1s_reply()
```

```c
#define ao_ir_i2c1s_request()
```

```c
#define ao_ir_i2c2b_disable()
```

```c
#define ao_ir_i2c2b_enable()
```

```c
#define ao_ir_i2c2b_is_enabled()
```

```c
#define ao_ir_i2c2b_is_pending()
```

```c
#define ao_ir_i2c2b_reply()
```

```c
#define ao_ir_i2c2b_request()
```

```c
#define ao_ir_i2c2m_disable()
```

```c
#define ao_ir_i2c2m_enable()
```

```c
#define ao_ir_i2c2m_is_enabled()
```

```c
#define ao_ir_i2c2m_is_pending()
```

```c
#define ao_ir_i2c2m_reply()
```

```c
#define ao_ir_i2c2m_request()
```

```c
#define ao_ir_i2c2s_disable()
```

```c
#define ao_ir_i2c2s_enable()
```

```c
#define ao_ir_i2c2s_is_enabled()
```

```c
#define ao_ir_i2c2s_is_pending()
```

```c
#define ao_ir_i2c2s_reply()
```

```c
#define ao_ir_i2c2s_request()
```

```c
#define ao_ir_i2c3b_disable()
```

```c
#define ao_ir_i2c3b_enable()
```

```c
#define ao_ir_i2c3b_is_enabled()
```

```c
#define ao_ir_i2c3b_is_pending()
```

```c
#define ao_ir_i2c3b_reply()
```

```c
#define ao_ir_i2c3b_request()
```

```c
#define ao_ir_i2c3m_disable()
```

```c
#define ao_ir_i2c3m_enable()
```

```c
#define ao_ir_i2c3m_is_enabled()
```

```c
#define ao_ir_i2c3m_is_pending()
```

```c
#define ao_ir_i2c3m_reply()
```

```c
#define ao_ir_i2c3m_request()
```

```c
#define ao_ir_i2c3s_disable()
```

```c
#define ao_ir_i2c3s_enable()
```

```c
#define ao_ir_i2c3s_is_enabled()
```

```c
#define ao_ir_i2c3s_is_pending()
```

```c
#define ao_ir_i2c3s_reply()
```

```c
#define ao_ir_i2c3s_request()
```

```c
#define ao_ir_i2c4b_disable()
```

```c
#define ao_ir_i2c4b_enable()
```

```c
#define ao_ir_i2c4b_is_enabled()
```

```c
#define ao_ir_i2c4b_is_pending()
```

```c
#define ao_ir_i2c4b_reply()
```

```c
#define ao_ir_i2c4b_request()
```

```c
#define ao_ir_i2c4m_disable()
```

```c
#define ao_ir_i2c4m_enable()
```

```c
#define ao_ir_i2c4m_is_enabled()
```

```c
#define ao_ir_i2c4m_is_pending()
```

```c
#define ao_ir_i2c4m_reply()
```

```c
#define ao_ir_i2c4m_request()
```

```c
#define ao_ir_i2c4s_disable()
```

```c
#define ao_ir_i2c4s_enable()
```

```c
#define ao_ir_i2c4s_is_enabled()
```

```c
#define ao_ir_i2c4s_is_pending()
```

```c
#define ao_ir_i2c4s_reply()
```

```c
#define ao_ir_i2c4s_request()
```

```c
#define ao_ir_i2c5b_disable()
```

```c
#define ao_ir_i2c5b_enable()
```

```c
#define ao_ir_i2c5b_is_enabled()
```

```c
#define ao_ir_i2c5b_is_pending()
```

```c
#define ao_ir_i2c5b_reply()
```

```c
#define ao_ir_i2c5b_request()
```

```c
#define ao_ir_i2c5m_disable()
```

```c
#define ao_ir_i2c5m_enable()
```

```c
#define ao_ir_i2c5m_is_enabled()
```

```c
#define ao_ir_i2c5m_is_pending()
```

```c
#define ao_ir_i2c5m_reply()
```

```c
#define ao_ir_i2c5m_request()
```

```c
#define ao_ir_i2c5s_disable()
```

```c
#define ao_ir_i2c5s_enable()
```

```c
#define ao_ir_i2c5s_is_enabled()
```

```c
#define ao_ir_i2c5s_is_pending()
```

```c
#define ao_ir_i2c5s_reply()
```

```c
#define ao_ir_i2c5s_request()
```


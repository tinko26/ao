---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The /src/ao_sys_xc32_pic32mk_gpg/ao_ir_i2c.h file of the ao real-time operating system."
draft: true
permalink: /api/src/ao_sys_xc32_pic32mk_gpg/ao_ir_i2c.h/
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


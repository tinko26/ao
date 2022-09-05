---
api: true
author: "Stefan Wagner"
date: 2022-09-05
description: "The /src/ao_sys_xc32_pic32mx_3xx/ao_ir_i2c.h file of the ao real-time operating system."
draft: true
permalink: /api/src/ao_sys_xc32_pic32mx_3xx/ao_ir_i2c.h/
subtitle: "I²C interrupts"
title: "ao_ir_i2c.h"
toc: true
---

# Include

```c
#include <stdbool.h>
#include <sys/attribs.h>
#include <xc.h>
```

# Configuration

## `AO_IR_I2C1`

The interrupt handler attribute.

```c
#define AO_IR_I2C1_ATTRIBUTE __ISR(_I2C_1_VECTOR, IPL4SOFT)
```

The interrupt priority and subpriority.

```c
#define AO_IR_I2C1_PRIO      (4)
#define AO_IR_I2C1_SUBPRIO   (0)
```

## `AO_IR_I2C2`

The interrupt handler attribute.

```c
#define AO_IR_I2C2_ATTRIBUTE __ISR(_I2C_2_VECTOR, IPL4SOFT)
```

The interrupt priority and subpriority.

```c
#define AO_IR_I2C2_PRIO      (4)
#define AO_IR_I2C2_SUBPRIO   (0)
```

# Functions

## `ao_ir_i2c1b`

Enable or disable the interrupt.

```c
#define ao_ir_i2c1b_enable()
#define ao_ir_i2c1b_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_i2c1b_request()
#define ao_ir_i2c1b_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_i2c1b_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_i2c1b_is_pending()
```

## `ao_ir_i2c1m`

Enable or disable the interrupt.

```c
#define ao_ir_i2c1m_enable()
#define ao_ir_i2c1m_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_i2c1m_request()
#define ao_ir_i2c1m_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_i2c1m_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_i2c1m_is_pending()
```

## `ao_ir_i2c1s`

Enable or disable the interrupt.

```c
#define ao_ir_i2c1s_enable()
#define ao_ir_i2c1s_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_i2c1s_request()
#define ao_ir_i2c1s_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_i2c1s_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_i2c1s_is_pending()
```

## `ao_ir_i2c2b`

Enable or disable the interrupt.

```c
#define ao_ir_i2c2b_enable()
#define ao_ir_i2c2b_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_i2c2b_request()
#define ao_ir_i2c2b_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_i2c2b_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_i2c2b_is_pending()
```

## `ao_ir_i2c2m`

Enable or disable the interrupt.

```c
#define ao_ir_i2c2m_enable()
#define ao_ir_i2c2m_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_i2c2m_request()
#define ao_ir_i2c2m_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_i2c2m_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_i2c2m_is_pending()
```

## `ao_ir_i2c2s`

Enable or disable the interrupt.

```c
#define ao_ir_i2c2s_enable()
#define ao_ir_i2c2s_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_i2c2s_request()
#define ao_ir_i2c2s_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_i2c2s_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_i2c2s_is_pending()
```

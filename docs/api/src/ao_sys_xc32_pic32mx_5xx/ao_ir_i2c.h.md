---
author: "Stefan Wagner"
date: 2022-09-05
draft: true
permalink: /api/src/ao_sys_xc32_pic32mx_5xx/ao_ir_i2c.h/
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

## `AO_IR_I2C3`

The interrupt handler attribute.

```c
#define AO_IR_I2C3_ATTRIBUTE __ISR(_I2C_3_VECTOR, IPL4SOFT)
```

The interrupt priority and subpriority.

```c
#define AO_IR_I2C3_PRIO      (4)
#define AO_IR_I2C3_SUBPRIO   (0)
```

## `AO_IR_I2C4`

The interrupt handler attribute.

```c
#define AO_IR_I2C4_ATTRIBUTE __ISR(_I2C_4_VECTOR, IPL4SOFT)
```

The interrupt priority and subpriority.

```c
#define AO_IR_I2C4_PRIO      (4)
#define AO_IR_I2C4_SUBPRIO   (0)
```

## `AO_IR_I2C5`

The interrupt handler attribute.

```c
#define AO_IR_I2C5_ATTRIBUTE __ISR(_I2C_5_VECTOR, IPL4SOFT)
```

The interrupt priority and subpriority.

```c
#define AO_IR_I2C5_PRIO      (4)
#define AO_IR_I2C5_SUBPRIO   (0)
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

## `ao_ir_i2c3b`

Enable or disable the interrupt.

```c
#define ao_ir_i2c3b_enable()
#define ao_ir_i2c3b_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_i2c3b_request()
#define ao_ir_i2c3b_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_i2c3b_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_i2c3b_is_pending()
```

## `ao_ir_i2c3m`

Enable or disable the interrupt.

```c
#define ao_ir_i2c3m_enable()
#define ao_ir_i2c3m_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_i2c3m_request()
#define ao_ir_i2c3m_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_i2c3m_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_i2c3m_is_pending()
```

## `ao_ir_i2c3s`

Enable or disable the interrupt.

```c
#define ao_ir_i2c3s_enable()
#define ao_ir_i2c3s_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_i2c3s_request()
#define ao_ir_i2c3s_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_i2c3s_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_i2c3s_is_pending()
```

## `ao_ir_i2c4b`

Enable or disable the interrupt.

```c
#define ao_ir_i2c4b_enable()
#define ao_ir_i2c4b_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_i2c4b_request()
#define ao_ir_i2c4b_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_i2c4b_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_i2c4b_is_pending()
```

## `ao_ir_i2c4m`

Enable or disable the interrupt.

```c
#define ao_ir_i2c4m_enable()
#define ao_ir_i2c4m_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_i2c4m_request()
#define ao_ir_i2c4m_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_i2c4m_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_i2c4m_is_pending()
```

## `ao_ir_i2c4s`

Enable or disable the interrupt.

```c
#define ao_ir_i2c4s_enable()
#define ao_ir_i2c4s_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_i2c4s_request()
#define ao_ir_i2c4s_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_i2c4s_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_i2c4s_is_pending()
```

## `ao_ir_i2c5b`

Enable or disable the interrupt.

```c
#define ao_ir_i2c5b_enable()
#define ao_ir_i2c5b_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_i2c5b_request()
#define ao_ir_i2c5b_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_i2c5b_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_i2c5b_is_pending()
```

## `ao_ir_i2c5m`

Enable or disable the interrupt.

```c
#define ao_ir_i2c5m_enable()
#define ao_ir_i2c5m_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_i2c5m_request()
#define ao_ir_i2c5m_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_i2c5m_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_i2c5m_is_pending()
```

## `ao_ir_i2c5s`

Enable or disable the interrupt.

```c
#define ao_ir_i2c5s_enable()
#define ao_ir_i2c5s_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_i2c5s_request()
#define ao_ir_i2c5s_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_i2c5s_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_i2c5s_is_pending()
```

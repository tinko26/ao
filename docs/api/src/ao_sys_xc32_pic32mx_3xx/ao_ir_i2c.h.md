---
author: "Stefan Wagner"
date: 2022-09-05
draft: true
permalink: /api/src/ao_sys_xc32_pic32mx_3xx/ao_ir_i2c.h/
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

```c
#define AO_IR_I2C1_ATTRIBUTE __ISR(_I2C_1_VECTOR, IPL4SOFT)
```

The interrupt handler attribute.

```c
#define AO_IR_I2C1_PRIO    (4)
#define AO_IR_I2C1_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_I2C2`

```c
#define AO_IR_I2C2_ATTRIBUTE __ISR(_I2C_2_VECTOR, IPL4SOFT)
```

The interrupt handler attribute.

```c
#define AO_IR_I2C2_PRIO    (4)
#define AO_IR_I2C2_SUBPRIO (0)
```

The interrupt priority and subpriority.

# Functions

## `ao_ir_i2c1b`

```c
#define ao_ir_i2c1b_enable()
#define ao_ir_i2c1b_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_i2c1b_request()
#define ao_ir_i2c1b_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_i2c1b_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_i2c1b_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_i2c1m`

```c
#define ao_ir_i2c1m_enable()
#define ao_ir_i2c1m_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_i2c1m_request()
#define ao_ir_i2c1m_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_i2c1m_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_i2c1m_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_i2c1s`

```c
#define ao_ir_i2c1s_enable()
#define ao_ir_i2c1s_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_i2c1s_request()
#define ao_ir_i2c1s_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_i2c1s_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_i2c1s_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_i2c2b`

```c
#define ao_ir_i2c2b_enable()
#define ao_ir_i2c2b_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_i2c2b_request()
#define ao_ir_i2c2b_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_i2c2b_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_i2c2b_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_i2c2m`

```c
#define ao_ir_i2c2m_enable()
#define ao_ir_i2c2m_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_i2c2m_request()
#define ao_ir_i2c2m_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_i2c2m_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_i2c2m_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_i2c2s`

```c
#define ao_ir_i2c2s_enable()
#define ao_ir_i2c2s_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_i2c2s_request()
#define ao_ir_i2c2s_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_i2c2s_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_i2c2s_is_pending()
```

Checks whether the interrupt is pending.

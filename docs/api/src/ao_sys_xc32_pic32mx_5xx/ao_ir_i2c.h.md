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

## `AO_IR_I2C3`

```c
#define AO_IR_I2C3_ATTRIBUTE __ISR(_I2C_3_VECTOR, IPL4SOFT)
```

The interrupt handler attribute.

```c
#define AO_IR_I2C3_PRIO    (4)
#define AO_IR_I2C3_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_I2C4`

```c
#define AO_IR_I2C4_ATTRIBUTE __ISR(_I2C_4_VECTOR, IPL4SOFT)
```

The interrupt handler attribute.

```c
#define AO_IR_I2C4_PRIO    (4)
#define AO_IR_I2C4_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_I2C5`

```c
#define AO_IR_I2C5_ATTRIBUTE __ISR(_I2C_5_VECTOR, IPL4SOFT)
```

The interrupt handler attribute.

```c
#define AO_IR_I2C5_PRIO    (4)
#define AO_IR_I2C5_SUBPRIO (0)
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

## `ao_ir_i2c3b`

```c
#define ao_ir_i2c3b_enable()
#define ao_ir_i2c3b_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_i2c3b_request()
#define ao_ir_i2c3b_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_i2c3b_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_i2c3b_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_i2c3m`

```c
#define ao_ir_i2c3m_enable()
#define ao_ir_i2c3m_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_i2c3m_request()
#define ao_ir_i2c3m_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_i2c3m_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_i2c3m_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_i2c3s`

```c
#define ao_ir_i2c3s_enable()
#define ao_ir_i2c3s_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_i2c3s_request()
#define ao_ir_i2c3s_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_i2c3s_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_i2c3s_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_i2c4b`

```c
#define ao_ir_i2c4b_enable()
#define ao_ir_i2c4b_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_i2c4b_request()
#define ao_ir_i2c4b_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_i2c4b_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_i2c4b_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_i2c4m`

```c
#define ao_ir_i2c4m_enable()
#define ao_ir_i2c4m_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_i2c4m_request()
#define ao_ir_i2c4m_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_i2c4m_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_i2c4m_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_i2c4s`

```c
#define ao_ir_i2c4s_enable()
#define ao_ir_i2c4s_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_i2c4s_request()
#define ao_ir_i2c4s_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_i2c4s_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_i2c4s_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_i2c5b`

```c
#define ao_ir_i2c5b_enable()
#define ao_ir_i2c5b_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_i2c5b_request()
#define ao_ir_i2c5b_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_i2c5b_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_i2c5b_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_i2c5m`

```c
#define ao_ir_i2c5m_enable()
#define ao_ir_i2c5m_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_i2c5m_request()
#define ao_ir_i2c5m_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_i2c5m_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_i2c5m_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_i2c5s`

```c
#define ao_ir_i2c5s_enable()
#define ao_ir_i2c5s_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_i2c5s_request()
#define ao_ir_i2c5s_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_i2c5s_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_i2c5s_is_pending()
```

Checks whether the interrupt is pending.

---
author: "Stefan Wagner"
date: 2022-09-05
draft: true
permalink: /api/src/ao_sys_xc32_pic32mk_gpk/ao_ir_i2c.h/
toc: true
---

# Include

```c
#include <stdbool.h>
#include <sys/attribs.h>
#include <xc.h>
```

# Configuration

## `AO_IR_I2C1B`

```c
#define AO_IR_I2C1B_ATTRIBUTE __ISR(_I2C1_BUS_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_I2C1B_PRIO    (4)
#define AO_IR_I2C1B_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_I2C1M`

```c
#define AO_IR_I2C1M_ATTRIBUTE __ISR(_I2C1_MASTER_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_I2C1M_PRIO    (4)
#define AO_IR_I2C1M_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_I2C1S`

```c
#define AO_IR_I2C1S_ATTRIBUTE __ISR(_I2C1_SLAVE_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_I2C1S_PRIO    (4)
#define AO_IR_I2C1S_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_I2C2B`

```c
#define AO_IR_I2C2B_ATTRIBUTE __ISR(_I2C2_BUS_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_I2C2B_PRIO    (4)
#define AO_IR_I2C2B_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_I2C2M`

```c
#define AO_IR_I2C2M_ATTRIBUTE __ISR(_I2C2_MASTER_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_I2C2M_PRIO    (4)
#define AO_IR_I2C2M_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_I2C2S`

```c
#define AO_IR_I2C2S_ATTRIBUTE __ISR(_I2C2_SLAVE_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_I2C2S_PRIO    (4)
#define AO_IR_I2C2S_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_I2C3B`

```c
#define AO_IR_I2C3B_ATTRIBUTE __ISR(_I2C3_BUS_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_I2C3B_PRIO    (4)
#define AO_IR_I2C3B_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_I2C3M`

```c
#define AO_IR_I2C3M_ATTRIBUTE __ISR(_I2C3_MASTER_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_I2C3M_PRIO    (4)
#define AO_IR_I2C3M_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_I2C3S`

```c
#define AO_IR_I2C3S_ATTRIBUTE __ISR(_I2C3_SLAVE_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_I2C3S_PRIO    (4)
#define AO_IR_I2C3S_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_I2C4B`

```c
#define AO_IR_I2C4B_ATTRIBUTE __ISR(_I2C4_BUS_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_I2C4B_PRIO    (4)
#define AO_IR_I2C4B_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_I2C4M`

```c
#define AO_IR_I2C4M_ATTRIBUTE __ISR(_I2C4_MASTER_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_I2C4M_PRIO    (4)
#define AO_IR_I2C4M_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_I2C4S`

```c
#define AO_IR_I2C4S_ATTRIBUTE __ISR(_I2C4_SLAVE_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_I2C4S_PRIO    (4)
#define AO_IR_I2C4S_SUBPRIO (0)
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

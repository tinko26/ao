---
api: true
author: "Stefan Wagner"
date: 2022-09-05
description: "The /src/ao_sys_xc32_pic32_i2c/ao_ir_i2c.h file of the ao real-time operating system."
draft: true
permalink: /api/src/ao_sys_xc32_pic32_i2c/ao_ir_i2c.h/
subtitle: "I²C interrupts"
title: "ao_ir_i2c.h"
toc: true
---

# Include

```c
#include <stdbool.h>
```

# Functions

## I²C 1 Bus Collision Interrupt

Enable or disable the interrupt.

```c
void ao_ir_i2c1b_enable();
void ao_ir_i2c1b_disable();
```

Request the interrupt or reply thereto.

```c
void ao_ir_i2c1b_request();
void ao_ir_i2c1b_reply();
```

Check whether the interrupt is enabled.

```c
bool ao_ir_i2c1b_is_enabled();
```

Check whether the interrupt is pending.

```c
bool ao_ir_i2c1b_is_pending();
```

## I²C 1 Master Interrupt

Enable or disable the interrupt.

```c
void ao_ir_i2c1m_enable();
void ao_ir_i2c1m_disable();
```

Request the interrupt or reply thereto.

```c
void ao_ir_i2c1m_request();
void ao_ir_i2c1m_reply();
```

Check whether the interrupt is enabled.

```c
bool ao_ir_i2c1m_is_enabled();
```

Check whether the interrupt is pending.

```c
bool ao_ir_i2c1m_is_pending();
```

## I²C 1 Slave Interrupt

Enable or disable the interrupt.

```c
void ao_ir_i2c1s_enable();
void ao_ir_i2c1s_disable();
```

Request the interrupt or reply thereto.

```c
void ao_ir_i2c1s_request();
void ao_ir_i2c1s_reply();
```

Check whether the interrupt is enabled.

```c
bool ao_ir_i2c1s_is_enabled();
```

Check whether the interrupt is pending.

```c
bool ao_ir_i2c1s_is_pending();
```

## I²C 2 Bus Collision Interrupt

Enable or disable the interrupt.

```c
void ao_ir_i2c2b_enable();
void ao_ir_i2c2b_disable();
```

Request the interrupt or reply thereto.

```c
void ao_ir_i2c2b_request();
void ao_ir_i2c2b_reply();
```

Check whether the interrupt is enabled.

```c
bool ao_ir_i2c2b_is_enabled();
```

Check whether the interrupt is pending.

```c
bool ao_ir_i2c2b_is_pending();
```

## I²C 2 Master Interrupt

Enable or disable the interrupt.

```c
void ao_ir_i2c2m_enable();
void ao_ir_i2c2m_disable();
```

Request the interrupt or reply thereto.

```c
void ao_ir_i2c2m_request();
void ao_ir_i2c2m_reply();
```

Check whether the interrupt is enabled.

```c
bool ao_ir_i2c2m_is_enabled();
```

Check whether the interrupt is pending.

```c
bool ao_ir_i2c2m_is_pending();
```

## I²C 2 Slave Interrupt

Enable or disable the interrupt.

```c
void ao_ir_i2c2s_enable();
void ao_ir_i2c2s_disable();
```

Request the interrupt or reply thereto.

```c
void ao_ir_i2c2s_request();
void ao_ir_i2c2s_reply();
```

Check whether the interrupt is enabled.

```c
bool ao_ir_i2c2s_is_enabled();
```

Check whether the interrupt is pending.

```c
bool ao_ir_i2c2s_is_pending();
```

## I²C 3 Bus Collision Interrupt

Enable or disable the interrupt.

```c
void ao_ir_i2c3b_enable();
void ao_ir_i2c3b_disable();
```

Request the interrupt or reply thereto.

```c
void ao_ir_i2c3b_request();
void ao_ir_i2c3b_reply();
```

Check whether the interrupt is enabled.

```c
bool ao_ir_i2c3b_is_enabled();
```

Check whether the interrupt is pending.

```c
bool ao_ir_i2c3b_is_pending();
```

## I²C 3 Master Interrupt

Enable or disable the interrupt.

```c
void ao_ir_i2c3m_enable();
void ao_ir_i2c3m_disable();
```

Request the interrupt or reply thereto.

```c
void ao_ir_i2c3m_request();
void ao_ir_i2c3m_reply();
```

Check whether the interrupt is enabled.

```c
bool ao_ir_i2c3m_is_enabled();
```

Check whether the interrupt is pending.

```c
bool ao_ir_i2c3m_is_pending();
```

## I²C 3 Slave Interrupt

Enable or disable the interrupt.

```c
void ao_ir_i2c3s_enable();
void ao_ir_i2c3s_disable();
```

Request the interrupt or reply thereto.

```c
void ao_ir_i2c3s_request();
void ao_ir_i2c3s_reply();
```

Check whether the interrupt is enabled.

```c
bool ao_ir_i2c3s_is_enabled();
```

Check whether the interrupt is pending.

```c
bool ao_ir_i2c3s_is_pending();
```

## I²C 4 Bus Collision Interrupt

Enable or disable the interrupt.

```c
void ao_ir_i2c4b_enable();
void ao_ir_i2c4b_disable();
```

Request the interrupt or reply thereto.

```c
void ao_ir_i2c4b_request();
void ao_ir_i2c4b_reply();
```

Check whether the interrupt is enabled.

```c
bool ao_ir_i2c4b_is_enabled();
```

Check whether the interrupt is pending.

```c
bool ao_ir_i2c4b_is_pending();
```

## I²C 4 Master Interrupt

Enable or disable the interrupt.

```c
void ao_ir_i2c4m_enable();
void ao_ir_i2c4m_disable();
```

Request the interrupt or reply thereto.

```c
void ao_ir_i2c4m_request();
void ao_ir_i2c4m_reply();
```

Check whether the interrupt is enabled.

```c
bool ao_ir_i2c4m_is_enabled();
```

Check whether the interrupt is pending.

```c
bool ao_ir_i2c4m_is_pending();
```

## I²C 4 Slave Interrupt

Enable or disable the interrupt.

```c
void ao_ir_i2c4s_enable();
void ao_ir_i2c4s_disable();
```

Request the interrupt or reply thereto.

```c
void ao_ir_i2c4s_request();
void ao_ir_i2c4s_reply();
```

Check whether the interrupt is enabled.

```c
bool ao_ir_i2c4s_is_enabled();
```

Check whether the interrupt is pending.

```c
bool ao_ir_i2c4s_is_pending();
```

## I²C 5 Bus Collision Interrupt

Enable or disable the interrupt.

```c
void ao_ir_i2c5b_enable();
void ao_ir_i2c5b_disable();
```

Request the interrupt or reply thereto.

```c
void ao_ir_i2c5b_request();
void ao_ir_i2c5b_reply();
```

Check whether the interrupt is enabled.

```c
bool ao_ir_i2c5b_is_enabled();
```

Check whether the interrupt is pending.

```c
bool ao_ir_i2c5b_is_pending();
```

## I²C 5 Master Interrupt

Enable or disable the interrupt.

```c
void ao_ir_i2c5m_enable();
void ao_ir_i2c5m_disable();
```

Request the interrupt or reply thereto.

```c
void ao_ir_i2c5m_request();
void ao_ir_i2c5m_reply();
```

Check whether the interrupt is enabled.

```c
bool ao_ir_i2c5m_is_enabled();
```

Check whether the interrupt is pending.

```c
bool ao_ir_i2c5m_is_pending();
```

## I²C 5 Slave Interrupt

Enable or disable the interrupt.

```c
void ao_ir_i2c5s_enable();
void ao_ir_i2c5s_disable();
```

Request the interrupt or reply thereto.

```c
void ao_ir_i2c5s_request();
void ao_ir_i2c5s_reply();
```

Check whether the interrupt is enabled.

```c
bool ao_ir_i2c5s_is_enabled();
```

Check whether the interrupt is pending.

```c
bool ao_ir_i2c5s_is_pending();
```

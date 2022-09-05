---
api: true
author: "Stefan Wagner"
date: 2022-09-05
description: "The /src/ao_sys_xc32_pic32_can/ao_ir_can.h file of the ao real-time operating system."
draft: true
permalink: /api/src/ao_sys_xc32_pic32_can/ao_ir_can.h/
subtitle: "CAN interrupts"
title: "ao_ir_can.h"
toc: true
---

# Include

```c
#include <stdbool.h>
```

# Functions

## CAN 1 Interrupt

Enable or disable the interrupt.

```c
void ao_ir_can1_enable();
void ao_ir_can1_disable();
```

Request the interrupt or reply thereto.

```c
void ao_ir_can1_request();
void ao_ir_can1_reply();
```

Check whether the interrupt is enabled.

```c
bool ao_ir_can1_is_enabled();
```

Check whether the interrupt is pending.

```c
bool ao_ir_can1_is_pending();
```

## CAN 2 Interrupt

Enable or disable the interrupt.

```c
void ao_ir_can2_enable();
void ao_ir_can2_disable();
```

Request the interrupt or reply thereto.

```c
void ao_ir_can2_request();
void ao_ir_can2_reply();
```

Check whether the interrupt is enabled.

```c
bool ao_ir_can2_is_enabled();
```

Check whether the interrupt is pending.

```c
bool ao_ir_can2_is_pending();
```

## CAN 3 Interrupt

Enable or disable the interrupt.

```c
void ao_ir_can3_enable();
void ao_ir_can3_disable();
```

Request the interrupt or reply thereto.

```c
void ao_ir_can3_request();
void ao_ir_can3_reply();
```

Check whether the interrupt is enabled.

```c
bool ao_ir_can3_is_enabled();
```

Check whether the interrupt is pending.

```c
bool ao_ir_can3_is_pending();
```

## CAN 4 Interrupt

Enable or disable the interrupt.

```c
void ao_ir_can4_enable();
void ao_ir_can4_disable();
```

Request the interrupt or reply thereto.

```c
void ao_ir_can4_request();
void ao_ir_can4_reply();
```

Check whether the interrupt is enabled.

```c
bool ao_ir_can4_is_enabled();
```

Check whether the interrupt is pending.

```c
bool ao_ir_can4_is_pending();
```

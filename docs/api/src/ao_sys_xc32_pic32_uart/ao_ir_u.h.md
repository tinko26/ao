---
api: true
author: "Stefan Wagner"
date: 2022-09-05
description: "The /src/ao_sys_xc32_pic32_uart/ao_ir_u.h file of the ao real-time operating system."
draft: true
permalink: /api/src/ao_sys_xc32_pic32_uart/ao_ir_u.h/
subtitle: "UART interrupts"
title: "ao_ir_u.h"
toc: true
---

# Include

```c
#include <stdbool.h>
```

# Functions

## `ao_ir_u1e`

Enable or disable the interrupt.

```c
void ao_ir_u1e_enable();
void ao_ir_u1e_disable();
```

Request the interrupt or reply thereto.

```c
void ao_ir_u1e_request();
void ao_ir_u1e_reply();
```

Check whether the interrupt is enabled.

```c
bool ao_ir_u1e_is_enabled();
```

Check whether the interrupt is pending.

```c
bool ao_ir_u1e_is_pending();
```

## `ao_ir_u1rx`

Enable or disable the interrupt.

```c
void ao_ir_u1rx_enable();
void ao_ir_u1rx_disable();
```

Request the interrupt or reply thereto.

```c
void ao_ir_u1rx_request();
void ao_ir_u1rx_reply();
```

Check whether the interrupt is enabled.

```c
bool ao_ir_u1rx_is_enabled();
```

Check whether the interrupt is pending.

```c
bool ao_ir_u1rx_is_pending();
```

## `ao_ir_u1tx`

Enable or disable the interrupt.

```c
void ao_ir_u1tx_enable();
void ao_ir_u1tx_disable();
```

Request the interrupt or reply thereto.

```c
void ao_ir_u1tx_request();
void ao_ir_u1tx_reply();
```

Check whether the interrupt is enabled.

```c
bool ao_ir_u1tx_is_enabled();
```

Check whether the interrupt is pending.

```c
bool ao_ir_u1tx_is_pending();
```

## `ao_ir_u2e`

Enable or disable the interrupt.

```c
void ao_ir_u2e_enable();
void ao_ir_u2e_disable();
```

Request the interrupt or reply thereto.

```c
void ao_ir_u2e_request();
void ao_ir_u2e_reply();
```

Check whether the interrupt is enabled.

```c
bool ao_ir_u2e_is_enabled();
```

Check whether the interrupt is pending.

```c
bool ao_ir_u2e_is_pending();
```

## `ao_ir_u2rx`

Enable or disable the interrupt.

```c
void ao_ir_u2rx_enable();
void ao_ir_u2rx_disable();
```

Request the interrupt or reply thereto.

```c
void ao_ir_u2rx_request();
void ao_ir_u2rx_reply();
```

Check whether the interrupt is enabled.

```c
bool ao_ir_u2rx_is_enabled();
```

Check whether the interrupt is pending.

```c
bool ao_ir_u2rx_is_pending();
```

## `ao_ir_u2tx`

Enable or disable the interrupt.

```c
void ao_ir_u2tx_enable();
void ao_ir_u2tx_disable();
```

Request the interrupt or reply thereto.

```c
void ao_ir_u2tx_request();
void ao_ir_u2tx_reply();
```

Check whether the interrupt is enabled.

```c
bool ao_ir_u2tx_is_enabled();
```

Check whether the interrupt is pending.

```c
bool ao_ir_u2tx_is_pending();
```

## `ao_ir_u3e`

Enable or disable the interrupt.

```c
void ao_ir_u3e_enable();
void ao_ir_u3e_disable();
```

Request the interrupt or reply thereto.

```c
void ao_ir_u3e_request();
void ao_ir_u3e_reply();
```

Check whether the interrupt is enabled.

```c
bool ao_ir_u3e_is_enabled();
```

Check whether the interrupt is pending.

```c
bool ao_ir_u3e_is_pending();
```

## `ao_ir_u3rx`

Enable or disable the interrupt.

```c
void ao_ir_u3rx_enable();
void ao_ir_u3rx_disable();
```

Request the interrupt or reply thereto.

```c
void ao_ir_u3rx_request();
void ao_ir_u3rx_reply();
```

Check whether the interrupt is enabled.

```c
bool ao_ir_u3rx_is_enabled();
```

Check whether the interrupt is pending.

```c
bool ao_ir_u3rx_is_pending();
```

## `ao_ir_u3tx`

Enable or disable the interrupt.

```c
void ao_ir_u3tx_enable();
void ao_ir_u3tx_disable();
```

Request the interrupt or reply thereto.

```c
void ao_ir_u3tx_request();
void ao_ir_u3tx_reply();
```

Check whether the interrupt is enabled.

```c
bool ao_ir_u3tx_is_enabled();
```

Check whether the interrupt is pending.

```c
bool ao_ir_u3tx_is_pending();
```

## `ao_ir_u4e`

Enable or disable the interrupt.

```c
void ao_ir_u4e_enable();
void ao_ir_u4e_disable();
```

Request the interrupt or reply thereto.

```c
void ao_ir_u4e_request();
void ao_ir_u4e_reply();
```

Check whether the interrupt is enabled.

```c
bool ao_ir_u4e_is_enabled();
```

Check whether the interrupt is pending.

```c
bool ao_ir_u4e_is_pending();
```

## `ao_ir_u4rx`

Enable or disable the interrupt.

```c
void ao_ir_u4rx_enable();
void ao_ir_u4rx_disable();
```

Request the interrupt or reply thereto.

```c
void ao_ir_u4rx_request();
void ao_ir_u4rx_reply();
```

Check whether the interrupt is enabled.

```c
bool ao_ir_u4rx_is_enabled();
```

Check whether the interrupt is pending.

```c
bool ao_ir_u4rx_is_pending();
```

## `ao_ir_u4tx`

Enable or disable the interrupt.

```c
void ao_ir_u4tx_enable();
void ao_ir_u4tx_disable();
```

Request the interrupt or reply thereto.

```c
void ao_ir_u4tx_request();
void ao_ir_u4tx_reply();
```

Check whether the interrupt is enabled.

```c
bool ao_ir_u4tx_is_enabled();
```

Check whether the interrupt is pending.

```c
bool ao_ir_u4tx_is_pending();
```

## `ao_ir_u5e`

Enable or disable the interrupt.

```c
void ao_ir_u5e_enable();
void ao_ir_u5e_disable();
```

Request the interrupt or reply thereto.

```c
void ao_ir_u5e_request();
void ao_ir_u5e_reply();
```

Check whether the interrupt is enabled.

```c
bool ao_ir_u5e_is_enabled();
```

Check whether the interrupt is pending.

```c
bool ao_ir_u5e_is_pending();
```

## `ao_ir_u5rx`

Enable or disable the interrupt.

```c
void ao_ir_u5rx_enable();
void ao_ir_u5rx_disable();
```

Request the interrupt or reply thereto.

```c
void ao_ir_u5rx_request();
void ao_ir_u5rx_reply();
```

Check whether the interrupt is enabled.

```c
bool ao_ir_u5rx_is_enabled();
```

Check whether the interrupt is pending.

```c
bool ao_ir_u5rx_is_pending();
```

## `ao_ir_u5tx`

Enable or disable the interrupt.

```c
void ao_ir_u5tx_enable();
void ao_ir_u5tx_disable();
```

Request the interrupt or reply thereto.

```c
void ao_ir_u5tx_request();
void ao_ir_u5tx_reply();
```

Check whether the interrupt is enabled.

```c
bool ao_ir_u5tx_is_enabled();
```

Check whether the interrupt is pending.

```c
bool ao_ir_u5tx_is_pending();
```

## `ao_ir_u6e`

Enable or disable the interrupt.

```c
void ao_ir_u6e_enable();
void ao_ir_u6e_disable();
```

Request the interrupt or reply thereto.

```c
void ao_ir_u6e_request();
void ao_ir_u6e_reply();
```

Check whether the interrupt is enabled.

```c
bool ao_ir_u6e_is_enabled();
```

Check whether the interrupt is pending.

```c
bool ao_ir_u6e_is_pending();
```

## `ao_ir_u6rx`

Enable or disable the interrupt.

```c
void ao_ir_u6rx_enable();
void ao_ir_u6rx_disable();
```

Request the interrupt or reply thereto.

```c
void ao_ir_u6rx_request();
void ao_ir_u6rx_reply();
```

Check whether the interrupt is enabled.

```c
bool ao_ir_u6rx_is_enabled();
```

Check whether the interrupt is pending.

```c
bool ao_ir_u6rx_is_pending();
```

## `ao_ir_u6tx`

Enable or disable the interrupt.

```c
void ao_ir_u6tx_enable();
void ao_ir_u6tx_disable();
```

Request the interrupt or reply thereto.

```c
void ao_ir_u6tx_request();
void ao_ir_u6tx_reply();
```

Check whether the interrupt is enabled.

```c
bool ao_ir_u6tx_is_enabled();
```

Check whether the interrupt is pending.

```c
bool ao_ir_u6tx_is_pending();
```

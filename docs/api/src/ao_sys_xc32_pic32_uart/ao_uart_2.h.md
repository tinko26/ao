---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The /src/ao_sys_xc32_pic32_uart/ao_uart_2.h file of the ao real-time operating system."
draft: true
permalink: /api/src/ao_sys_xc32_pic32_uart/ao_uart_2.h/
subtitle: "UART 2"
title: "ao_uart_2.h"
toc: true
---

# Include

```c
#include <ao_recv.h>
#include <ao_send.h>
#include <ao_sys.h>
#include <ao_task.h>
#include <ao_uart.h>
#include <stdbool.h>
#include <xc.h>
```

# Constants

```c
#define AO_UART_2 (false)
```

```c
#define AO_UART_2 (true)
```

```c
#define AO_UART_BAUD_2 (9600)
```

```c
#define AO_UART_BAUD_HIGH_MAX_2 AO_UART_BAUD_HIGH_MAX(AO_SYS_CLOCK_U2)
```

```c
#define AO_UART_BAUD_HIGH_MIN_2 AO_UART_BAUD_HIGH_MIN(AO_SYS_CLOCK_U2)
```

```c
#define AO_UART_BAUD_LOW_MAX_2 AO_UART_BAUD_LOW_MAX(AO_SYS_CLOCK_U2)
```

```c
#define AO_UART_BAUD_LOW_MIN_2 AO_UART_BAUD_LOW_MIN(AO_SYS_CLOCK_U2)
```

```c
#define AO_UART_BAUD_MAX_2 AO_UART_BAUD_MAX(AO_SYS_CLOCK_U2)
```

```c
#define AO_UART_BAUD_MIN_2 AO_UART_BAUD_MIN(AO_SYS_CLOCK_U2)
```

```c
#define AO_UART_DATA_BITS_PARITY_2 (AO_UART_DATA_BITS_8_PARITY_NONE)
```

```c
#define AO_UART_ERROR_2 (false)
```

```c
#define AO_UART_LOOPBACK_2 (false)
```

```c
#define AO_UART_RX_2 (false)
```

```c
#define AO_UART_STOP_BITS_2 (AO_UART_STOP_BITS_ONE)
```

```c
#define AO_UART_TX_2 (false)
```

# Functions

```c
#define ao_uart_baud_2(f)
```

```c
#define ao_uart_baud_high_2(f)
```

```c
#define ao_uart_baud_low_2(f)
```

```c
#define ao_uart_loopback_disable_2()
```

```c
#define ao_uart_loopback_enable_2()
```

```c
#define ao_uart_reg_2()
```

```c
void ao_uart_config_2();
```

```c
void ao_uart_config_baud_2();
```

```c
void ao_uart_config_frame_2();
```

```c
void ao_uart_config_loopback_2();
```

```c
void ao_uart_error_2( ao_uart_error_info_t const * info);
```

```c
void ao_uart_start_2();
```

```c
void ao_uart_stop_2();
```

# Variables

```c
extern ao_send_t ao_uart_in_2;
```

```c
extern ao_recv_t ao_uart_out_2;
```

```c
extern ao_task_t ao_uart_task_2;
```

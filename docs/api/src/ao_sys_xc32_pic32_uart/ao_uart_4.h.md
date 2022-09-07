---
author: "Stefan Wagner"
date: 2022-08-29
draft: true
permalink: /api/src/ao_sys_xc32_pic32_uart/ao_uart_4.h/
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

## `AO_UART`

Indicates whether the UART module is available.

```c
#define AO_UART_4
```

## `AO_UART_BAUD`

The maximum and minimum baud rate.

```c
#define AO_UART_BAUD_MAX_4
#define AO_UART_BAUD_MIN_4
```

## `AO_UART_BAUD_HIGH`

```c
#define AO_UART_BAUD_HIGH_MAX_4
#define AO_UART_BAUD_HIGH_MIN_4
```

## `AO_UART_BAUD_LOW`

```c
#define AO_UART_BAUD_LOW_MAX_4
#define AO_UART_BAUD_LOW_MIN_4
```

# Configuration

## `AO_UART_BAUD`

```c
#define AO_UART_BAUD_4 (9600)
```

## `AO_UART_DATA_BITS_PARITY`

```c
#define AO_UART_DATA_BITS_PARITY_4 (AO_UART_DATA_BITS_8_PARITY_NONE)
```

## `AO_UART_ERROR`

```c
#define AO_UART_ERROR_4 (false)
```

## `AO_UART_LOOPBACK`

```c
#define AO_UART_LOOPBACK_4 (false)
```

## `AO_UART_RX`

```c
#define AO_UART_RX_4 (false)
```

## `AO_UART_STOP_BITS`

```c
#define AO_UART_STOP_BITS_4 (AO_UART_STOP_BITS_ONE)
```

## `AO_UART_TX`

```c
#define AO_UART_TX_4 (false)
```

# Functions

```c
#define ao_uart_baud_4(f)
```

```c
#define ao_uart_baud_high_4(f)
```

```c
#define ao_uart_baud_low_4(f)
```

```c
#define ao_uart_loopback_disable_4()
```

```c
#define ao_uart_loopback_enable_4()
```

```c
#define ao_uart_reg_4()
```

```c
void ao_uart_config_4();
```

```c
void ao_uart_config_baud_4();
```

```c
void ao_uart_config_frame_4();
```

```c
void ao_uart_config_loopback_4();
```

```c
void ao_uart_error_4(ao_uart_error_info_t const * info);
```

```c
void ao_uart_start_4();
```

```c
void ao_uart_stop_4();
```

# Variables

```c
extern ao_send_t ao_uart_in_4;
```

```c
extern ao_recv_t ao_uart_out_4;
```

```c
extern ao_task_t ao_uart_task_4;
```

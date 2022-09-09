---
author: "Stefan Wagner"
date: 2022-08-29
draft: true
permalink: /api/src/ao_sys_xc32_pic32_uart/ao_uart_5.h/
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

# Identifiers

## `AO_UART_5`

```c
#define AO_UART_5
```

# Configuration

## `AO_UART_BAUD_5`

```c
#define AO_UART_BAUD_5 (9600)
```

## `AO_UART_DATA_BITS_PARITY_5`

```c
#define AO_UART_DATA_BITS_PARITY_5 (AO_UART_DATA_BITS_8_PARITY_NONE)
```

## `AO_UART_ERROR_5`

```c
#define AO_UART_ERROR_5 (false)
```

## `AO_UART_LOOPBACK_5`

```c
#define AO_UART_LOOPBACK_5 (false)
```

## `AO_UART_RX_5`

```c
#define AO_UART_RX_5 (false)
```

## `AO_UART_STOP_BITS_5`

```c
#define AO_UART_STOP_BITS_5 (AO_UART_STOP_BITS_ONE)
```

## `AO_UART_TX_5`

```c
#define AO_UART_TX_5 (false)
```

# Constants

## `AO_UART_5`

Indicates whether the UART module is available.

```c
#define AO_UART_5
```

## `AO_UART_BAUD_MAX_5`
## `AO_UART_BAUD_MIN_5`

The maximum and minimum baud rate.

```c
#define AO_UART_BAUD_MAX_5
#define AO_UART_BAUD_MIN_5
```

## `AO_UART_BAUD_HIGH_MAX_5`
## `AO_UART_BAUD_HIGH_MIN_5`

```c
#define AO_UART_BAUD_HIGH_MAX_5
#define AO_UART_BAUD_HIGH_MIN_5
```

## `AO_UART_BAUD_LOW_MAX_5`
## `AO_UART_BAUD_LOW_MIN_5`

```c
#define AO_UART_BAUD_LOW_MAX_5
#define AO_UART_BAUD_LOW_MIN_5
```

# Functions

## `ao_uart_baud_5`

```c
#define ao_uart_baud_5(f)
```

## `ao_uart_baud_high_5`

```c
#define ao_uart_baud_high_5(f)
```

## `ao_uart_baud_low_5`

```c
#define ao_uart_baud_low_5(f)
```

## `ao_uart_config_5`

```c
void ao_uart_config_5();
```

## `ao_uart_config_baud_5`

```c
void ao_uart_config_baud_5();
```

## `ao_uart_config_frame_5`

```c
void ao_uart_config_frame_5();
```

## `ao_uart_config_loopback_5`

```c
void ao_uart_config_loopback_5();
```

## `ao_uart_error_5`

```c
void ao_uart_error_5(ao_uart_error_info_t const * info);
```

## `ao_uart_loopback_enable_5`
## `ao_uart_loopback_disable_5`

```c
#define ao_uart_loopback_enable_5()
#define ao_uart_loopback_disable_5()
```

## `ao_uart_reg_5`

```c
#define ao_uart_reg_5()
```

## `ao_uart_start_5`

```c
void ao_uart_start_5();
```

## `ao_uart_stop_5`

```c
void ao_uart_stop_5();
```

# Variables

## `ao_uart_in_5`

```c
extern ao_send_t ao_uart_in_5;
```

## `ao_uart_out_5`

```c
extern ao_recv_t ao_uart_out_5;
```

## `ao_uart_task_5`

```c
extern ao_task_t ao_uart_task_5;
```

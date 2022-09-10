---
author: "Stefan Wagner"
date: 2022-08-29
draft: true
permalink: /api/src/ao_sys_xc32_pic32_uart/ao_uart_2.h/
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

## `AO_UART_2`

```c
#define AO_UART_2
```

# Configuration

## `AO_UART_BAUD_2`

```c
#define AO_UART_BAUD_2 (9600)
```

## `AO_UART_DATA_BITS_PARITY_2`

```c
#define AO_UART_DATA_BITS_PARITY_2 (AO_UART_DATA_BITS_8_PARITY_NONE)
```

## `AO_UART_ERROR_2`

```c
#define AO_UART_ERROR_2 (false)
```

## `AO_UART_LOOPBACK_2`

```c
#define AO_UART_LOOPBACK_2 (false)
```

## `AO_UART_RX_2`

```c
#define AO_UART_RX_2 (false)
```

## `AO_UART_STOP_BITS_2`

```c
#define AO_UART_STOP_BITS_2 (AO_UART_STOP_BITS_ONE)
```

## `AO_UART_TX_2`

```c
#define AO_UART_TX_2 (false)
```

# Constants

## `AO_UART_2`

```c
#define AO_UART_2
```

Indicates whether the UART module is available.

## `AO_UART_BAUD_MAX_2`
## `AO_UART_BAUD_MIN_2`

```c
#define AO_UART_BAUD_MAX_2
#define AO_UART_BAUD_MIN_2
```

The maximum and minimum baud rate.

## `AO_UART_BAUD_HIGH_MAX_2`
## `AO_UART_BAUD_HIGH_MIN_2`

```c
#define AO_UART_BAUD_HIGH_MAX_2
#define AO_UART_BAUD_HIGH_MIN_2
```

## `AO_UART_BAUD_LOW_MAX_2`
## `AO_UART_BAUD_LOW_MIN_2`

```c
#define AO_UART_BAUD_LOW_MAX_2
#define AO_UART_BAUD_LOW_MIN_2
```

# Functions

## `ao_uart_baud_2`

```c
#define ao_uart_baud_2(f)
```

## `ao_uart_baud_high_2`

```c
#define ao_uart_baud_high_2(f)
```

## `ao_uart_baud_low_2`

```c
#define ao_uart_baud_low_2(f)
```

## `ao_uart_config_2`

```c
void ao_uart_config_2();
```

## `ao_uart_config_baud_2`

```c
void ao_uart_config_baud_2();
```

## `ao_uart_config_frame_2`

```c
void ao_uart_config_frame_2();
```

## `ao_uart_config_loopback_2`

```c
void ao_uart_config_loopback_2();
```

## `ao_uart_error_2`

```c
void ao_uart_error_2(ao_uart_error_info_t const * info);
```

## `ao_uart_loopback_enable_2`
## `ao_uart_loopback_disable_2`

```c
#define ao_uart_loopback_enable_2()
#define ao_uart_loopback_disable_2()
```

## `ao_uart_reg_2`

```c
#define ao_uart_reg_2()
```

## `ao_uart_start_2`

```c
void ao_uart_start_2();
```

## `ao_uart_stop_2`

```c
void ao_uart_stop_2();
```

# Variables

## `ao_uart_in_2`

```c
extern ao_send_t ao_uart_in_2;
```

## `ao_uart_out_2`

```c
extern ao_recv_t ao_uart_out_2;
```

## `ao_uart_task_2`

```c
extern ao_task_t ao_uart_task_2;
```

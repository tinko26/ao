---
author: "Stefan Wagner"
date: 2022-09-23
draft: true
permalink: /api/demos/ao_mikroe_2340/ao_uart_5.h/
toc: true
---

# Notes

This module supports baud rates up to 921600 bps.

# Include

```c
#include <ao_mikroe_2674.h>
#include <ao_mikroe_3063.h>
#include <ao_uart.h>
#include <stdbool.h>
```

# Configuration

## `AO_UART_5`

```c
#define AO_UART_5 (false)
```

Defines whether to use the module.

## `AO_UART_BAUD_5`

```c
#define AO_UART_BAUD_5 (921600)
```

Defines the baud rate, in bits per second.

## `AO_UART_DATA_BITS_PARITY_5`

```c
#define AO_UART_DATA_BITS_PARITY_5 (AO_UART_DATA_BITS_8_PARITY_NONE)
```

| Options                           |                          |
|-----------------------------------|--------------------------|
| `AO_UART_DATA_BITS_8_PARITY_NONE` | 8-bit data, no parity.   |
| `AO_UART_DATA_BITS_8_PARITY_EVEN` | 8-bit data, even parity. |
| `AO_UART_DATA_BITS_8_PARITY_ODD`  | 8-bit data, odd parity.  |
| `AO_UART_DATA_BITS_9_PARITY_NONE` | 9-bit data, no parity.   |

Defines the number of data bits and the parity.

## `AO_UART_ERROR_5`

```c
#define AO_UART_ERROR_5 (false)
```

Defines whether to notify the application of errors.

## `AO_UART_LOOPBACK_5`

```c
#define AO_UART_LOOPBACK_5 (false)
```

Defines whether to operate in loopback mode.

## `AO_UART_RX_5`

```c
#define AO_UART_RX_5 (false)
```

Defines whether to receive data.

## `AO_UART_STOP_BITS_5`

```c
#define AO_UART_STOP_BITS_5 (AO_UART_STOP_BITS_ONE)
```

| Options                 |              |
|-------------------------|--------------|
| `AO_UART_STOP_BITS_ONE` | 1 stop bit.  |
| `AO_UART_STOP_BITS_TWO` | 2 stop bits. |

Defines the number of stop bits.

## `AO_UART_TX_5`

```c
#define AO_UART_TX_5 (false)
```

Defines whether to transmit data.

# Include Next

```c
#include_next <ao_uart_5.h>
```

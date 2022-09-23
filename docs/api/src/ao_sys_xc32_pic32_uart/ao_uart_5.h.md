---
author: "Stefan Wagner"
date: 2022-09-23
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

# Identifier

```c
#define AO_UART_5
```

# Configuration

## `AO_UART_5`

```c
#define AO_UART_5 (false)
```

Defines whether to use the module.

## `AO_UART_BAUD_5`

```c
#define AO_UART_BAUD_5 (9600)
```

Defines the baud rate, in bits per second.

## `AO_UART_DATA_BITS_PARITY_5`

```c
#define AO_UART_DATA_BITS_PARITY_5 (AO_UART_DATA_BITS_8_PARITY_NONE)
```

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

| `AO_UART_STOP_BITS_ONE` | 1 stop bit.  |
| `AO_UART_STOP_BITS_TWO` | 2 stop bits. |

Defines the number of stop bits.

## `AO_UART_TX_5`

```c
#define AO_UART_TX_5 (false)
```

Defines whether to transmit data.

# Constants

## `AO_UART_BAUD_MAX_5`

```c
#define AO_UART_BAUD_MAX_5               \
(                                        \
    AO_UART_BAUD_MAX(AO_SYS_CLOCK_UART5) \
)
```

The maximum possible baud rate, in bits per second.

## `AO_UART_BAUD_MAX_HI_5`

```c
#define AO_UART_BAUD_MAX_HI_5               \
(                                           \
    AO_UART_BAUD_MAX_HI(AO_SYS_CLOCK_UART5) \
)
```

The maximum possible baud rate in high-speed mode, in bits per second.

## `AO_UART_BAUD_MAX_LO_5`

```c
#define AO_UART_BAUD_MAX_LO_5               \
(                                           \
    AO_UART_BAUD_MAX_LO(AO_SYS_CLOCK_UART5) \
)
```

The maximum possible baud rate in standard-speed mode, in bits per second.

## `AO_UART_BAUD_MIN_5`

```c
#define AO_UART_BAUD_MIN_5               \
(                                        \
    AO_UART_BAUD_MIN(AO_SYS_CLOCK_UART5) \
)
```

The minimum possible baud rate, in bits per second.

## `AO_UART_BAUD_MIN_HI_5`

```c
#define AO_UART_BAUD_MIN_HI_5               \
(                                           \
    AO_UART_BAUD_MIN_HI(AO_SYS_CLOCK_UART5) \
)
```

The minimum possible baud rate in high-speed mode, in bits per second.

## `AO_UART_BAUD_MIN_LO_5`

```c
#define AO_UART_BAUD_MIN_LO_5               \
(                                           \
    AO_UART_BAUD_MIN_LO(AO_SYS_CLOCK_UART5) \
)
```

The minimum possible baud rate in standard-speed mode, in bits per second.

# Functions

## `ao_uart_error_5`

```c
void ao_uart_error_5(ao_uart_error_t e);
```

Notifies the application of one or more detected errors.

## `ao_uart_reg_5`

```c
#define ao_uart_reg_5()     \
(                           \
    (ao_uart_reg_t *)       \
    (                       \
        _UART5_BASE_ADDRESS \
    )                       \
)
```

Gets the control registers.

## `ao_uart_start_5`
## `ao_uart_stop_5`

```c
void ao_uart_start_5();
void ao_uart_stop_5();
```

Starts or stops the driver, respectively.

# Variables

## `ao_uart_in_5`

```c
extern ao_send_t ao_uart_in_5;
```

The object used to send inbound data to the application.

## `ao_uart_out_5`

```c
extern ao_recv_t ao_uart_out_5;
```

The object used to receive outbound data from the application.

## `ao_uart_task_5`

```c
extern ao_task_t ao_uart_task_5;
```

The task sending outbound data.

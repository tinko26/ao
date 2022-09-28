---
author: "Stefan Wagner"
date: 2022-09-23
draft: true
permalink: /api/src/ao_sys_xc32_pic32_uart/ao_uart_1.h/
toc: true
---

# Include

| [`ao_recv.h`](../ao_sys/ao_recv.h.md) |
| [`ao_send.h`](../ao_sys/ao_send.h.md) |
| [`ao_sys.h`](ao_sys.h.md) |
| [`ao_task.h`](../ao_sys/ao_task.h.md) |
| [`ao_uart.h`](ao_uart.h.md) |
| `stdbool.h` |
| `xc.h` |

# Configuration

## `AO_UART_1`

```c
#define AO_UART_1 (false)
```

Defines whether to use the module.

## `AO_UART_BAUD_1`

```c
#define AO_UART_BAUD_1 (9600)
```

Defines the baud rate, in bits per second.

## `AO_UART_DATA_BITS_PARITY_1`

```c
#define AO_UART_DATA_BITS_PARITY_1 (AO_UART_DATA_BITS_8_PARITY_NONE)
```

| `AO_UART_DATA_BITS_8_PARITY_NONE` | 8-bit data, no parity.   |
| `AO_UART_DATA_BITS_8_PARITY_EVEN` | 8-bit data, even parity. |
| `AO_UART_DATA_BITS_8_PARITY_ODD`  | 8-bit data, odd parity.  |
| `AO_UART_DATA_BITS_9_PARITY_NONE` | 9-bit data, no parity.   |

Defines the number of data bits and the parity.

## `AO_UART_ERROR_1`

```c
#define AO_UART_ERROR_1 (false)
```

Defines whether to notify the application of errors.

## `AO_UART_LOOPBACK_1`

```c
#define AO_UART_LOOPBACK_1 (false)
```

Defines whether to operate in loopback mode.

## `AO_UART_RX_1`

```c
#define AO_UART_RX_1 (false)
```

Defines whether to receive data.

## `AO_UART_STOP_BITS_1`

```c
#define AO_UART_STOP_BITS_1 (AO_UART_STOP_BITS_ONE)
```

| `AO_UART_STOP_BITS_ONE` | 1 stop bit.  |
| `AO_UART_STOP_BITS_TWO` | 2 stop bits. |

Defines the number of stop bits.

## `AO_UART_TX_1`

```c
#define AO_UART_TX_1 (false)
```

Defines whether to transmit data.

# Constants

## `AO_UART_BAUD_MAX_1`

```c
#define AO_UART_BAUD_MAX_1               \
(                                        \
    AO_UART_BAUD_MAX(AO_SYS_CLOCK_UART1) \
)
```

The maximum possible baud rate, in bits per second.

## `AO_UART_BAUD_MAX_HI_1`

```c
#define AO_UART_BAUD_MAX_HI_1               \
(                                           \
    AO_UART_BAUD_MAX_HI(AO_SYS_CLOCK_UART1) \
)
```

The maximum possible baud rate in high-speed mode, in bits per second.

## `AO_UART_BAUD_MAX_LO_1`

```c
#define AO_UART_BAUD_MAX_LO_1               \
(                                           \
    AO_UART_BAUD_MAX_LO(AO_SYS_CLOCK_UART1) \
)
```

The maximum possible baud rate in standard-speed mode, in bits per second.

## `AO_UART_BAUD_MIN_1`

```c
#define AO_UART_BAUD_MIN_1               \
(                                        \
    AO_UART_BAUD_MIN(AO_SYS_CLOCK_UART1) \
)
```

The minimum possible baud rate, in bits per second.

## `AO_UART_BAUD_MIN_HI_1`

```c
#define AO_UART_BAUD_MIN_HI_1               \
(                                           \
    AO_UART_BAUD_MIN_HI(AO_SYS_CLOCK_UART1) \
)
```

The minimum possible baud rate in high-speed mode, in bits per second.

## `AO_UART_BAUD_MIN_LO_1`

```c
#define AO_UART_BAUD_MIN_LO_1               \
(                                           \
    AO_UART_BAUD_MIN_LO(AO_SYS_CLOCK_UART1) \
)
```

The minimum possible baud rate in standard-speed mode, in bits per second.

# Functions

## `ao_uart_error_1`

```c
void ao_uart_error_1(ao_uart_error_t e);
```

Notifies the application of one or more detected errors.

## `ao_uart_reg_1`

```c
#define ao_uart_reg_1()     \
(                           \
    (ao_uart_reg_t *)       \
    (                       \
        _UART1_BASE_ADDRESS \
    )                       \
)
```

Gets the control registers.

## `ao_uart_start_1`
## `ao_uart_stop_1`

```c
void ao_uart_start_1();
void ao_uart_stop_1();
```

Starts or stops the driver, respectively.

# Variables

## `ao_uart_in_1`

```c
extern ao_send_t ao_uart_in_1;
```

The object used to send inbound data to the application.

## `ao_uart_out_1`

```c
extern ao_recv_t ao_uart_out_1;
```

The object used to receive outbound data from the application.

## `ao_uart_task_1`

```c
extern ao_task_t ao_uart_task_1;
```

The task sending outbound data.

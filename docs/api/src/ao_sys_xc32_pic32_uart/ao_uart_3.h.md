---
author: "Stefan Wagner"
date: 2022-09-23
draft: true
permalink: /api/src/ao_sys_xc32_pic32_uart/ao_uart_3.h/
toc: true
---

# Include

[`ao_recv.h`](../ao_sys/ao_recv.h.md) <br/>
[`ao_send.h`](../ao_sys/ao_send.h.md) <br/>
[`ao_sys.h`](ao_sys.h.md) <br/>
[`ao_task.h`](../ao_sys/ao_task.h.md) <br/>
[`ao_uart.h`](ao_uart.h.md) <br/>
`stdbool.h` <br/>
`xc.h`

# Identifier

```c
#define AO_UART_3
```

# Configuration

## `AO_UART_3`

```c
#define AO_UART_3 (false)
```

Defines whether to use the module.

## `AO_UART_BAUD_3`

```c
#define AO_UART_BAUD_3 (9600)
```

Defines the baud rate, in bits per second.

## `AO_UART_DATA_BITS_PARITY_3`

```c
#define AO_UART_DATA_BITS_PARITY_3 (AO_UART_DATA_BITS_8_PARITY_NONE)
```

| `AO_UART_DATA_BITS_8_PARITY_NONE` | 8-bit data, no parity.   |
| `AO_UART_DATA_BITS_8_PARITY_EVEN` | 8-bit data, even parity. |
| `AO_UART_DATA_BITS_8_PARITY_ODD`  | 8-bit data, odd parity.  |
| `AO_UART_DATA_BITS_9_PARITY_NONE` | 9-bit data, no parity.   |

Defines the number of data bits and the parity.

## `AO_UART_ERROR_3`

```c
#define AO_UART_ERROR_3 (false)
```

Defines whether to notify the application of errors.

## `AO_UART_LOOPBACK_3`

```c
#define AO_UART_LOOPBACK_3 (false)
```

Defines whether to operate in loopback mode.

## `AO_UART_RX_3`

```c
#define AO_UART_RX_3 (false)
```

Defines whether to receive data.

## `AO_UART_STOP_BITS_3`

```c
#define AO_UART_STOP_BITS_3 (AO_UART_STOP_BITS_ONE)
```

| `AO_UART_STOP_BITS_ONE` | 1 stop bit.  |
| `AO_UART_STOP_BITS_TWO` | 2 stop bits. |

Defines the number of stop bits.

## `AO_UART_TX_3`

```c
#define AO_UART_TX_3 (false)
```

Defines whether to transmit data.

# Constants

## `AO_UART_BAUD_MAX_3`

```c
#define AO_UART_BAUD_MAX_3               \
(                                        \
    AO_UART_BAUD_MAX(AO_SYS_CLOCK_UART3) \
)
```

The maximum possible baud rate, in bits per second.

## `AO_UART_BAUD_MAX_HI_3`

```c
#define AO_UART_BAUD_MAX_HI_3               \
(                                           \
    AO_UART_BAUD_MAX_HI(AO_SYS_CLOCK_UART3) \
)
```

The maximum possible baud rate in high-speed mode, in bits per second.

## `AO_UART_BAUD_MAX_LO_3`

```c
#define AO_UART_BAUD_MAX_LO_3               \
(                                           \
    AO_UART_BAUD_MAX_LO(AO_SYS_CLOCK_UART3) \
)
```

The maximum possible baud rate in standard-speed mode, in bits per second.

## `AO_UART_BAUD_MIN_3`

```c
#define AO_UART_BAUD_MIN_3               \
(                                        \
    AO_UART_BAUD_MIN(AO_SYS_CLOCK_UART3) \
)
```

The minimum possible baud rate, in bits per second.

## `AO_UART_BAUD_MIN_HI_3`

```c
#define AO_UART_BAUD_MIN_HI_3               \
(                                           \
    AO_UART_BAUD_MIN_HI(AO_SYS_CLOCK_UART3) \
)
```

The minimum possible baud rate in high-speed mode, in bits per second.

## `AO_UART_BAUD_MIN_LO_3`

```c
#define AO_UART_BAUD_MIN_LO_3               \
(                                           \
    AO_UART_BAUD_MIN_LO(AO_SYS_CLOCK_UART3) \
)
```

The minimum possible baud rate in standard-speed mode, in bits per second.

# Functions

## `ao_uart_error_3`

```c
void ao_uart_error_3(ao_uart_error_t e);
```

Notifies the application of one or more detected errors.

## `ao_uart_reg_3`

```c
#define ao_uart_reg_3()     \
(                           \
    (ao_uart_reg_t *)       \
    (                       \
        _UART3_BASE_ADDRESS \
    )                       \
)
```

Gets the control registers.

## `ao_uart_start_3`
## `ao_uart_stop_3`

```c
void ao_uart_start_3();
void ao_uart_stop_3();
```

Starts or stops the driver, respectively.

# Variables

## `ao_uart_in_3`

```c
extern ao_send_t ao_uart_in_3;
```

The object used to send inbound data to the application.

## `ao_uart_out_3`

```c
extern ao_recv_t ao_uart_out_3;
```

The object used to receive outbound data from the application.

## `ao_uart_task_3`

```c
extern ao_task_t ao_uart_task_3;
```

The task sending outbound data.

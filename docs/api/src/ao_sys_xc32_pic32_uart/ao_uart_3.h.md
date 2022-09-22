---
author: "Stefan Wagner"
date: 2022-09-22
draft: true
permalink: /api/src/ao_sys_xc32_pic32_uart/ao_uart_3.h/
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
#define AO_UART_3
```

# Configuration

## `AO_UART_BAUD_3`

```c
#define AO_UART_BAUD_3 (9600)
```

The baud rate, in bits per second.

## `AO_UART_DATA_BITS_PARITY_3`

```c
#define AO_UART_DATA_BITS_PARITY_3 (AO_UART_DATA_BITS_8_PARITY_NONE)
```

The number of data bits and the parity. The following options are available.

| `AO_UART_DATA_BITS_8_PARITY_NONE` | 8-bit data, no parity. |
| `AO_UART_DATA_BITS_8_PARITY_EVEN` | 8-bit data, even parity. |
| `AO_UART_DATA_BITS_8_PARITY_ODD`  | 8-bit data, odd parity. |
| `AO_UART_DATA_BITS_9_PARITY_NONE` | 9-bit data, no parity. |

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

Defines whether to enable the reception of data.

## `AO_UART_STOP_BITS_3`

```c
#define AO_UART_STOP_BITS_3 (AO_UART_STOP_BITS_ONE)
```

The number of stop bits. The following options are available.

| `AO_UART_STOP_BITS_ONE` | 1 stop bit. |
| `AO_UART_STOP_BITS_TWO` | 2 stop bits. |


## `AO_UART_TX_3`

```c
#define AO_UART_TX_3 (false)
```

Defines whether to enable the transmission of data.

# Constants

## `AO_UART_3`

```c
#define AO_UART_3 (false)
```

Indicates whether the module is available.

## `AO_UART_BAUD_MAX_3`
## `AO_UART_BAUD_MIN_3`

```c
#define AO_UART_BAUD_MAX_3 AO_UART_BAUD_MAX(AO_SYS_CLOCK_UART3)
#define AO_UART_BAUD_MIN_3 AO_UART_BAUD_MIN(AO_SYS_CLOCK_UART3)
```

The maximum and minimum baud rate, in bits per second.

## `AO_UART_BAUD_HIGH_MAX_3`
## `AO_UART_BAUD_HIGH_MIN_3`

```c
#define AO_UART_BAUD_HIGH_MAX_3 AO_UART_BAUD_HIGH_MAX(AO_SYS_CLOCK_UART3)
#define AO_UART_BAUD_HIGH_MIN_3 AO_UART_BAUD_HIGH_MIN(AO_SYS_CLOCK_UART3)
```

The maximum and minimum baud rate in high-speed mode, in bits per second.

## `AO_UART_BAUD_LOW_MAX_3`
## `AO_UART_BAUD_LOW_MIN_3`

```c
#define AO_UART_BAUD_LOW_MAX_3 AO_UART_BAUD_LOW_MAX(AO_SYS_CLOCK_UART3)
#define AO_UART_BAUD_LOW_MIN_3 AO_UART_BAUD_LOW_MIN(AO_SYS_CLOCK_UART3)
```

The maximum and minimum baud rate in standard-speed mode, in bits per second.

# Functions

## `ao_uart_baud_3`

```c
#define ao_uart_baud_3(f)   \
{                           \
    ao_uart_baud            \
    (                       \
        ao_uart_reg_3(),    \
        AO_SYS_CLOCK_UART3, \
        f                   \
    );                      \
}
```

Sets up the baud rate, in bits per second. This function enables or disables high-speed mode, depending on the specified baud rate.

## `ao_uart_baud_high_3`

```c
#define ao_uart_baud_high_3(f) \
{                              \
    ao_uart_baud_high          \
    (                          \
        ao_uart_reg_3(),       \
        AO_SYS_CLOCK_UART3,    \
        f                      \
    );                         \
}
```

Enables high-speed mode and sets up the baud rate, in bits per second.

## `ao_uart_baud_low_3`

```c
#define ao_uart_baud_low_3(f) \
{                             \
    ao_uart_baud_low          \
    (                         \
        ao_uart_reg_3(),      \
        AO_SYS_CLOCK_UART3,   \
        f                     \
    );                        \
}
```

Disables high-speed mode and sets up the baud rate, in bits per second.

## `ao_uart_config_3`

```c
void ao_uart_config_3();
```

Configurates the module. This function simply calls the following three configuration functions. This function is attributed as weak. Hence, the application can provide another implementation.

## `ao_uart_config_baud_3`

```c
void ao_uart_config_baud_3();
```

Configurates the baud rate. This function sets up the baud rate, that has been configured by `AO_UART_BAUD_3`, and enables or disables high-speed mode, depending on the specific value. This function is attributed as weak. Hence, the application can provide another implementation.

## `ao_uart_config_frame_3`

```c
void ao_uart_config_frame_3();
```

Configurates the frame characteristics. This function sets up the numbers of data bits and stop bits as well as the parity, that have been configured in by `AO_UART_DATA_BITS_PARITY_3` and `AO_UART_STOP_BITS_3`. This function is attributed as weak. Hence, the application can provide another implementation.

## `ao_uart_config_loopback_3`

```c
void ao_uart_config_loopback_3();
```

Configurates the loopback mode. This function enables or disable loopback mode, depending on the configuration by `AO_UART_LOOPBACK_3`. This function is attributed as weak. Hence, the application can provide another implementation.

## `ao_uart_error_3`

```c
void ao_uart_error_3(ao_uart_error_info_t const * info);
```

Notifies the application of one or more detected errors.

## `ao_uart_loopback_enable_3`
## `ao_uart_loopback_disable_3`

```c
#define ao_uart_loopback_enable_3()  ao_uart_loopback_enable (ao_uart_reg_3())
#define ao_uart_loopback_disable_3() ao_uart_loopback_disable(ao_uart_reg_3())
```

Enables or disables, respectively, loopback mode.

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

```c
void ao_uart_start_3();
```

Starts the driver.

## `ao_uart_stop_3`

```c
void ao_uart_stop_3();
```

Stops the driver.

# Variables

## `ao_uart_in_3`

```c
extern ao_send_t ao_uart_in_3;
```

The object used by the driver to send inbound data to the application.

## `ao_uart_out_3`

```c
extern ao_recv_t ao_uart_out_3;
```

The object used by the driver to receive outbound data from the application.

## `ao_uart_task_3`

```c
extern ao_task_t ao_uart_task_3;
```

The task run by the driver to send outbound data.

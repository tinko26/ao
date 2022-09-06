---
author: "Stefan Wagner"
date: 2022-08-29
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

# Constants

```c
#define AO_UART_3 (false)
```

```c
#define AO_UART_3 (true)
```

```c
#define AO_UART_BAUD_3 (9600)
```

```c
#define AO_UART_BAUD_HIGH_MAX_3 AO_UART_BAUD_HIGH_MAX(AO_SYS_CLOCK_U3)
```

```c
#define AO_UART_BAUD_HIGH_MIN_3 AO_UART_BAUD_HIGH_MIN(AO_SYS_CLOCK_U3)
```

```c
#define AO_UART_BAUD_LOW_MAX_3 AO_UART_BAUD_LOW_MAX(AO_SYS_CLOCK_U3)
```

```c
#define AO_UART_BAUD_LOW_MIN_3 AO_UART_BAUD_LOW_MIN(AO_SYS_CLOCK_U3)
```

```c
#define AO_UART_BAUD_MAX_3 AO_UART_BAUD_MAX(AO_SYS_CLOCK_U3)
```

```c
#define AO_UART_BAUD_MIN_3 AO_UART_BAUD_MIN(AO_SYS_CLOCK_U3)
```

```c
#define AO_UART_DATA_BITS_PARITY_3 (AO_UART_DATA_BITS_8_PARITY_NONE)
```

```c
#define AO_UART_ERROR_3 (false)
```

```c
#define AO_UART_LOOPBACK_3 (false)
```

```c
#define AO_UART_RX_3 (false)
```

```c
#define AO_UART_STOP_BITS_3 (AO_UART_STOP_BITS_ONE)
```

```c
#define AO_UART_TX_3 (false)
```

# Functions

```c
#define ao_uart_baud_3(f)
```

```c
#define ao_uart_baud_high_3(f)
```

```c
#define ao_uart_baud_low_3(f)
```

```c
#define ao_uart_loopback_disable_3()
```

```c
#define ao_uart_loopback_enable_3()
```

```c
#define ao_uart_reg_3()
```

```c
void ao_uart_config_3();
```

```c
void ao_uart_config_baud_3();
```

```c
void ao_uart_config_frame_3();
```

```c
void ao_uart_config_loopback_3();
```

```c
void ao_uart_error_3( ao_uart_error_info_t const * info);
```

```c
void ao_uart_start_3();
```

```c
void ao_uart_stop_3();
```

# Variables

```c
extern ao_send_t ao_uart_in_3;
```

```c
extern ao_recv_t ao_uart_out_3;
```

```c
extern ao_task_t ao_uart_task_3;
```

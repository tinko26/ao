---
author: "Stefan Wagner"
date: 2022-09-23
draft: true
permalink: /api/src/ao_sys_xc32_pic32_can/ao_can_4.h/
toc: true
---

# Include

| [`ao_can.h`](ao_can.h.md) |
| [`ao_recv_obj.h`](../ao_sys/ao_recv_obj.h.md) |
| [`ao_send_obj.h`](../ao_sys/ao_send_obj.h.md) |
| [`ao_sys.h`](ao_sys.h.md) |
| [`ao_task.h`](../ao_sys/ao_task.h.md) |
| `stdbool.h` |
| `stdint.h` |
| `xc.h` |

# Configuration

## `AO_CAN_4`

```c
#define AO_CAN_4 (false)
```

Defines whether to use the module.

## `AO_CAN_BAUD_4`

```c
#define AO_CAN_BAUD_4 (100000)
```

Defines the baud rate, in bits per second.

## `AO_CAN_BAUD_SAMPLE_4`

```c
#define AO_CAN_BAUD_SAMPLE_4 (85)
```

Defines the sample point, in per cent.

## `AO_CAN_BAUD_SAMPLE_THRICE_4`

```c
#define AO_CAN_BAUD_SAMPLE_THRICE_4 (true)
```

Defines whether to sample the bus line three times at the sample point.

## `AO_CAN_BAUD_SJW_4`

```c
#define AO_CAN_BAUD_SJW_4 (1)
```

Defines the synchronization jump width.

## `AO_CAN_BAUD_WAKE_UP_FILTER_4`

```c
#define AO_CAN_BAUD_WAKE_UP_FILTER_4 (false)
```

Defines whether to enable the bus line filter for wake-up.

## `AO_CAN_BUFFERS_4_*`

```c
#define AO_CAN_BUFFERS_4_0  (0)
#define AO_CAN_BUFFERS_4_1  (0)
#define AO_CAN_BUFFERS_4_2  (0)
#define AO_CAN_BUFFERS_4_3  (0)
#define AO_CAN_BUFFERS_4_4  (0)
#define AO_CAN_BUFFERS_4_5  (0)
#define AO_CAN_BUFFERS_4_6  (0)
#define AO_CAN_BUFFERS_4_7  (0)
#define AO_CAN_BUFFERS_4_8  (0)
#define AO_CAN_BUFFERS_4_9  (0)
#define AO_CAN_BUFFERS_4_10 (0)
#define AO_CAN_BUFFERS_4_11 (0)
#define AO_CAN_BUFFERS_4_12 (0)
#define AO_CAN_BUFFERS_4_13 (0)
#define AO_CAN_BUFFERS_4_14 (0)
#define AO_CAN_BUFFERS_4_15 (0)
#define AO_CAN_BUFFERS_4_16 (0)
#define AO_CAN_BUFFERS_4_17 (0)
#define AO_CAN_BUFFERS_4_18 (0)
#define AO_CAN_BUFFERS_4_19 (0)
#define AO_CAN_BUFFERS_4_20 (0)
#define AO_CAN_BUFFERS_4_21 (0)
#define AO_CAN_BUFFERS_4_22 (0)
#define AO_CAN_BUFFERS_4_23 (0)
#define AO_CAN_BUFFERS_4_24 (0)
#define AO_CAN_BUFFERS_4_25 (0)
#define AO_CAN_BUFFERS_4_26 (0)
#define AO_CAN_BUFFERS_4_27 (0)
#define AO_CAN_BUFFERS_4_28 (0)
#define AO_CAN_BUFFERS_4_29 (0)
#define AO_CAN_BUFFERS_4_30 (0)
#define AO_CAN_BUFFERS_4_31 (0)
```

Defines the number of buffers in each FIFO.

## `AO_CAN_BUS_4`

```c
#define AO_CAN_BUS_4 (false)
```

Defines whether to notify the application of bus errors.

## `AO_CAN_FIFOS_RX_4`
## `AO_CAN_FIFOS_TX_4`

```c
#define AO_CAN_FIFOS_RX_4 (0)
#define AO_CAN_FIFOS_TX_4 (0)
```

Defines the number of receive and transmit FIFOs.

## `AO_CAN_FILTER_EID_4_*`

```c
#define AO_CAN_FILTER_EID_4_0  (0)
#define AO_CAN_FILTER_EID_4_1  (0)
#define AO_CAN_FILTER_EID_4_2  (0)
#define AO_CAN_FILTER_EID_4_3  (0)
#define AO_CAN_FILTER_EID_4_4  (0)
#define AO_CAN_FILTER_EID_4_5  (0)
#define AO_CAN_FILTER_EID_4_6  (0)
#define AO_CAN_FILTER_EID_4_7  (0)
#define AO_CAN_FILTER_EID_4_8  (0)
#define AO_CAN_FILTER_EID_4_9  (0)
#define AO_CAN_FILTER_EID_4_10 (0)
#define AO_CAN_FILTER_EID_4_11 (0)
#define AO_CAN_FILTER_EID_4_12 (0)
#define AO_CAN_FILTER_EID_4_13 (0)
#define AO_CAN_FILTER_EID_4_14 (0)
#define AO_CAN_FILTER_EID_4_15 (0)
#define AO_CAN_FILTER_EID_4_16 (0)
#define AO_CAN_FILTER_EID_4_17 (0)
#define AO_CAN_FILTER_EID_4_18 (0)
#define AO_CAN_FILTER_EID_4_19 (0)
#define AO_CAN_FILTER_EID_4_20 (0)
#define AO_CAN_FILTER_EID_4_21 (0)
#define AO_CAN_FILTER_EID_4_22 (0)
#define AO_CAN_FILTER_EID_4_23 (0)
#define AO_CAN_FILTER_EID_4_24 (0)
#define AO_CAN_FILTER_EID_4_25 (0)
#define AO_CAN_FILTER_EID_4_26 (0)
#define AO_CAN_FILTER_EID_4_27 (0)
#define AO_CAN_FILTER_EID_4_28 (0)
#define AO_CAN_FILTER_EID_4_29 (0)
#define AO_CAN_FILTER_EID_4_30 (0)
#define AO_CAN_FILTER_EID_4_31 (0)
```

Defines the EID for each filter.

## `AO_CAN_FILTER_ENABLE_4_*`

```c
#define AO_CAN_FILTER_ENABLE_4_0  (0)
#define AO_CAN_FILTER_ENABLE_4_1  (0)
#define AO_CAN_FILTER_ENABLE_4_2  (0)
#define AO_CAN_FILTER_ENABLE_4_3  (0)
#define AO_CAN_FILTER_ENABLE_4_4  (0)
#define AO_CAN_FILTER_ENABLE_4_5  (0)
#define AO_CAN_FILTER_ENABLE_4_6  (0)
#define AO_CAN_FILTER_ENABLE_4_7  (0)
#define AO_CAN_FILTER_ENABLE_4_8  (0)
#define AO_CAN_FILTER_ENABLE_4_9  (0)
#define AO_CAN_FILTER_ENABLE_4_10 (0)
#define AO_CAN_FILTER_ENABLE_4_11 (0)
#define AO_CAN_FILTER_ENABLE_4_12 (0)
#define AO_CAN_FILTER_ENABLE_4_13 (0)
#define AO_CAN_FILTER_ENABLE_4_14 (0)
#define AO_CAN_FILTER_ENABLE_4_15 (0)
#define AO_CAN_FILTER_ENABLE_4_16 (0)
#define AO_CAN_FILTER_ENABLE_4_17 (0)
#define AO_CAN_FILTER_ENABLE_4_18 (0)
#define AO_CAN_FILTER_ENABLE_4_19 (0)
#define AO_CAN_FILTER_ENABLE_4_20 (0)
#define AO_CAN_FILTER_ENABLE_4_21 (0)
#define AO_CAN_FILTER_ENABLE_4_22 (0)
#define AO_CAN_FILTER_ENABLE_4_23 (0)
#define AO_CAN_FILTER_ENABLE_4_24 (0)
#define AO_CAN_FILTER_ENABLE_4_25 (0)
#define AO_CAN_FILTER_ENABLE_4_26 (0)
#define AO_CAN_FILTER_ENABLE_4_27 (0)
#define AO_CAN_FILTER_ENABLE_4_28 (0)
#define AO_CAN_FILTER_ENABLE_4_29 (0)
#define AO_CAN_FILTER_ENABLE_4_30 (0)
#define AO_CAN_FILTER_ENABLE_4_31 (0)
```

Defines the filters to enable.

## `AO_CAN_FILTER_FIFO_4_*`

```c
#define AO_CAN_FILTER_FIFO_4_0  (0)
#define AO_CAN_FILTER_FIFO_4_1  (0)
#define AO_CAN_FILTER_FIFO_4_2  (0)
#define AO_CAN_FILTER_FIFO_4_3  (0)
#define AO_CAN_FILTER_FIFO_4_4  (0)
#define AO_CAN_FILTER_FIFO_4_5  (0)
#define AO_CAN_FILTER_FIFO_4_6  (0)
#define AO_CAN_FILTER_FIFO_4_7  (0)
#define AO_CAN_FILTER_FIFO_4_8  (0)
#define AO_CAN_FILTER_FIFO_4_9  (0)
#define AO_CAN_FILTER_FIFO_4_10 (0)
#define AO_CAN_FILTER_FIFO_4_11 (0)
#define AO_CAN_FILTER_FIFO_4_12 (0)
#define AO_CAN_FILTER_FIFO_4_13 (0)
#define AO_CAN_FILTER_FIFO_4_14 (0)
#define AO_CAN_FILTER_FIFO_4_15 (0)
#define AO_CAN_FILTER_FIFO_4_16 (0)
#define AO_CAN_FILTER_FIFO_4_17 (0)
#define AO_CAN_FILTER_FIFO_4_18 (0)
#define AO_CAN_FILTER_FIFO_4_19 (0)
#define AO_CAN_FILTER_FIFO_4_20 (0)
#define AO_CAN_FILTER_FIFO_4_21 (0)
#define AO_CAN_FILTER_FIFO_4_22 (0)
#define AO_CAN_FILTER_FIFO_4_23 (0)
#define AO_CAN_FILTER_FIFO_4_24 (0)
#define AO_CAN_FILTER_FIFO_4_25 (0)
#define AO_CAN_FILTER_FIFO_4_26 (0)
#define AO_CAN_FILTER_FIFO_4_27 (0)
#define AO_CAN_FILTER_FIFO_4_28 (0)
#define AO_CAN_FILTER_FIFO_4_29 (0)
#define AO_CAN_FILTER_FIFO_4_30 (0)
#define AO_CAN_FILTER_FIFO_4_31 (0)
```

Defines the FIFO for each filter.

## `AO_CAN_FILTER_IDE_4_*`

```c
#define AO_CAN_FILTER_IDE_4_0  (0)
#define AO_CAN_FILTER_IDE_4_1  (0)
#define AO_CAN_FILTER_IDE_4_2  (0)
#define AO_CAN_FILTER_IDE_4_3  (0)
#define AO_CAN_FILTER_IDE_4_4  (0)
#define AO_CAN_FILTER_IDE_4_5  (0)
#define AO_CAN_FILTER_IDE_4_6  (0)
#define AO_CAN_FILTER_IDE_4_7  (0)
#define AO_CAN_FILTER_IDE_4_8  (0)
#define AO_CAN_FILTER_IDE_4_9  (0)
#define AO_CAN_FILTER_IDE_4_10 (0)
#define AO_CAN_FILTER_IDE_4_11 (0)
#define AO_CAN_FILTER_IDE_4_12 (0)
#define AO_CAN_FILTER_IDE_4_13 (0)
#define AO_CAN_FILTER_IDE_4_14 (0)
#define AO_CAN_FILTER_IDE_4_15 (0)
#define AO_CAN_FILTER_IDE_4_16 (0)
#define AO_CAN_FILTER_IDE_4_17 (0)
#define AO_CAN_FILTER_IDE_4_18 (0)
#define AO_CAN_FILTER_IDE_4_19 (0)
#define AO_CAN_FILTER_IDE_4_20 (0)
#define AO_CAN_FILTER_IDE_4_21 (0)
#define AO_CAN_FILTER_IDE_4_22 (0)
#define AO_CAN_FILTER_IDE_4_23 (0)
#define AO_CAN_FILTER_IDE_4_24 (0)
#define AO_CAN_FILTER_IDE_4_25 (0)
#define AO_CAN_FILTER_IDE_4_26 (0)
#define AO_CAN_FILTER_IDE_4_27 (0)
#define AO_CAN_FILTER_IDE_4_28 (0)
#define AO_CAN_FILTER_IDE_4_29 (0)
#define AO_CAN_FILTER_IDE_4_30 (0)
#define AO_CAN_FILTER_IDE_4_31 (0)
```

Defines the IDE for each filter.

## `AO_CAN_FILTER_MASK_4_*`

```c
#define AO_CAN_FILTER_MASK_4_0  (0)
#define AO_CAN_FILTER_MASK_4_1  (0)
#define AO_CAN_FILTER_MASK_4_2  (0)
#define AO_CAN_FILTER_MASK_4_3  (0)
#define AO_CAN_FILTER_MASK_4_4  (0)
#define AO_CAN_FILTER_MASK_4_5  (0)
#define AO_CAN_FILTER_MASK_4_6  (0)
#define AO_CAN_FILTER_MASK_4_7  (0)
#define AO_CAN_FILTER_MASK_4_8  (0)
#define AO_CAN_FILTER_MASK_4_9  (0)
#define AO_CAN_FILTER_MASK_4_10 (0)
#define AO_CAN_FILTER_MASK_4_11 (0)
#define AO_CAN_FILTER_MASK_4_12 (0)
#define AO_CAN_FILTER_MASK_4_13 (0)
#define AO_CAN_FILTER_MASK_4_14 (0)
#define AO_CAN_FILTER_MASK_4_15 (0)
#define AO_CAN_FILTER_MASK_4_16 (0)
#define AO_CAN_FILTER_MASK_4_17 (0)
#define AO_CAN_FILTER_MASK_4_18 (0)
#define AO_CAN_FILTER_MASK_4_19 (0)
#define AO_CAN_FILTER_MASK_4_20 (0)
#define AO_CAN_FILTER_MASK_4_21 (0)
#define AO_CAN_FILTER_MASK_4_22 (0)
#define AO_CAN_FILTER_MASK_4_23 (0)
#define AO_CAN_FILTER_MASK_4_24 (0)
#define AO_CAN_FILTER_MASK_4_25 (0)
#define AO_CAN_FILTER_MASK_4_26 (0)
#define AO_CAN_FILTER_MASK_4_27 (0)
#define AO_CAN_FILTER_MASK_4_28 (0)
#define AO_CAN_FILTER_MASK_4_29 (0)
#define AO_CAN_FILTER_MASK_4_30 (0)
#define AO_CAN_FILTER_MASK_4_31 (0)
```

Defines the filter mask for each filter.

## `AO_CAN_FILTER_MASK_EID_4_*`

```c
#define AO_CAN_FILTER_MASK_EID_4_0 (0)
#define AO_CAN_FILTER_MASK_EID_4_1 (0)
#define AO_CAN_FILTER_MASK_EID_4_2 (0)
#define AO_CAN_FILTER_MASK_EID_4_3 (0)
```

Defines the EID for each filter mask.

## `AO_CAN_FILTER_MASK_IDE_4_*`

```c
#define AO_CAN_FILTER_MASK_IDE_4_0 (0)
#define AO_CAN_FILTER_MASK_IDE_4_1 (0)
#define AO_CAN_FILTER_MASK_IDE_4_2 (0)
#define AO_CAN_FILTER_MASK_IDE_4_3 (0)
```

Defines the IDE for each filter mask.

## `AO_CAN_FILTER_MASK_SID_4_*`

```c
#define AO_CAN_FILTER_MASK_SID_4_0 (0)
#define AO_CAN_FILTER_MASK_SID_4_1 (0)
#define AO_CAN_FILTER_MASK_SID_4_2 (0)
#define AO_CAN_FILTER_MASK_SID_4_3 (0)
```

Defines the SID for each filter mask.

## `AO_CAN_FILTER_SID_4_*`

```c
#define AO_CAN_FILTER_SID_4_0  (0)
#define AO_CAN_FILTER_SID_4_1  (0)
#define AO_CAN_FILTER_SID_4_2  (0)
#define AO_CAN_FILTER_SID_4_3  (0)
#define AO_CAN_FILTER_SID_4_4  (0)
#define AO_CAN_FILTER_SID_4_5  (0)
#define AO_CAN_FILTER_SID_4_6  (0)
#define AO_CAN_FILTER_SID_4_7  (0)
#define AO_CAN_FILTER_SID_4_8  (0)
#define AO_CAN_FILTER_SID_4_9  (0)
#define AO_CAN_FILTER_SID_4_10 (0)
#define AO_CAN_FILTER_SID_4_11 (0)
#define AO_CAN_FILTER_SID_4_12 (0)
#define AO_CAN_FILTER_SID_4_13 (0)
#define AO_CAN_FILTER_SID_4_14 (0)
#define AO_CAN_FILTER_SID_4_15 (0)
#define AO_CAN_FILTER_SID_4_16 (0)
#define AO_CAN_FILTER_SID_4_17 (0)
#define AO_CAN_FILTER_SID_4_18 (0)
#define AO_CAN_FILTER_SID_4_19 (0)
#define AO_CAN_FILTER_SID_4_20 (0)
#define AO_CAN_FILTER_SID_4_21 (0)
#define AO_CAN_FILTER_SID_4_22 (0)
#define AO_CAN_FILTER_SID_4_23 (0)
#define AO_CAN_FILTER_SID_4_24 (0)
#define AO_CAN_FILTER_SID_4_25 (0)
#define AO_CAN_FILTER_SID_4_26 (0)
#define AO_CAN_FILTER_SID_4_27 (0)
#define AO_CAN_FILTER_SID_4_28 (0)
#define AO_CAN_FILTER_SID_4_29 (0)
#define AO_CAN_FILTER_SID_4_30 (0)
#define AO_CAN_FILTER_SID_4_31 (0)
```

Defines the SID for each filter.

## `AO_CAN_INVALID_4`

```c
#define AO_CAN_INVALID_4 (false)
```

Defines whether to notify the application of the reception or transmission of invalid messages.

## `AO_CAN_MODE_4`

```c
#define AO_CAN_MODE_4 (false)
```

Defines whether to notify the application of mode changes.

## `AO_CAN_OVERFLOW_4`

```c
#define AO_CAN_OVERFLOW_4 (false)
```

Defines whether to notify the application of receive buffer overflows.

## `AO_CAN_SENT_4`

```c
#define AO_CAN_SENT_4 (false)
```

Defines whether to notify the application, when messages have been sent.

## `AO_CAN_SYSTEM_4`

```c
#define AO_CAN_SYSTEM_4 (false)
```

Defines whether to notify the application of system errors.

## `AO_CAN_TIMER_4`

```c
#define AO_CAN_TIMER_4 (false)
```

Defines whether to notify the application of timestamp timer overflows.

## `AO_CAN_UNDERFLOW_4`

```c
#define AO_CAN_UNDERFLOW_4 (false)
```

Defines whether to notify the application of transmit buffer underflows.

## `AO_CAN_WAKE_UP_4`

```c
#define AO_CAN_WAKE_UP_4 (false)
```

Defines whether to notify the application of wake-up events.

# Constants

## `AO_CAN_BAUD_MAX_4`
## `AO_CAN_BAUD_MIN_4`

```c
#define AO_CAN_BAUD_MAX_4 AO_CAN_BAUD_MAX(AO_SYS_CLOCK_CAN4)
#define AO_CAN_BAUD_MIN_4 AO_CAN_BAUD_MIN(AO_SYS_CLOCK_CAN4)
```

The maximum and minimum baud rate.

## `AO_CAN_BUFFERS_4`

```c
#define AO_CAN_BUFFERS_4  \
(                         \
    AO_CAN_BUFFERS_4_0  + \
    AO_CAN_BUFFERS_4_1  + \
    AO_CAN_BUFFERS_4_2  + \
    AO_CAN_BUFFERS_4_3  + \
    AO_CAN_BUFFERS_4_4  + \
    AO_CAN_BUFFERS_4_5  + \
    AO_CAN_BUFFERS_4_6  + \
    AO_CAN_BUFFERS_4_7  + \
    AO_CAN_BUFFERS_4_8  + \
    AO_CAN_BUFFERS_4_9  + \
    AO_CAN_BUFFERS_4_10 + \
    AO_CAN_BUFFERS_4_11 + \
    AO_CAN_BUFFERS_4_12 + \
    AO_CAN_BUFFERS_4_13 + \
    AO_CAN_BUFFERS_4_14 + \
    AO_CAN_BUFFERS_4_15 + \
    AO_CAN_BUFFERS_4_16 + \
    AO_CAN_BUFFERS_4_17 + \
    AO_CAN_BUFFERS_4_18 + \
    AO_CAN_BUFFERS_4_19 + \
    AO_CAN_BUFFERS_4_20 + \
    AO_CAN_BUFFERS_4_21 + \
    AO_CAN_BUFFERS_4_22 + \
    AO_CAN_BUFFERS_4_23 + \
    AO_CAN_BUFFERS_4_24 + \
    AO_CAN_BUFFERS_4_25 + \
    AO_CAN_BUFFERS_4_26 + \
    AO_CAN_BUFFERS_4_27 + \
    AO_CAN_BUFFERS_4_28 + \
    AO_CAN_BUFFERS_4_29 + \
    AO_CAN_BUFFERS_4_30 + \
    AO_CAN_BUFFERS_4_31   \
)
```

The total number of buffers.

## `AO_CAN_FIFOS_4`

```c
#define AO_CAN_FIFOS_4    \
(                         \
    (AO_CAN_FIFOS_RX_4) + \
    (AO_CAN_FIFOS_TX_4)   \
)
```

The total number of FIFOs.

## `AO_CAN_RX_4`

```c
#define AO_CAN_RX_4         \
(                           \
    (AO_CAN_FIFOS_RX_4) > 0 \
    ? true                  \
    : false                 \
)
```

Indicates whether the module is configured to receive.

## `AO_CAN_TX_4`

```c
#define AO_CAN_TX_4         \
(                           \
    (AO_CAN_FIFOS_TX_4) > 0 \
    ? true                  \
    : false                 \
)
```

Indicates whether the module is configured to transmit.

# Functions

## `ao_can_bus_4`

```c
void ao_can_bus_4(ao_can_bus_t const * x);
```

Notifies the application of bus errors. This function is called every time there is a change in the current error state of the CAN module with respect to the CAN network. The error states are tracked by the C4TREC register.

## `ao_can_invalid_4`

```c
void ao_can_invalid_4();
```

Notifies the application, that an invalid message has been received or transmitted. However, the specific error is not available to the user application.

## `ao_can_listen_all_4`

```c
void ao_can_listen_all_4();
```

Sets the operation mode to listen all.

## `ao_can_listen_only_4`

```c
void ao_can_listen_only_4();
```

Sets the operation mode to listen only.

## `ao_can_loopback_4`

```c
void ao_can_loopback_4();
```

Sets the operation mode to loopback.

## `ao_can_mode_4`

```c
void ao_can_mode_4();
```

Notifies the application of a mode change.

## `ao_can_normal_4`

```c
void ao_can_normal_4();
```

Sets the operation mode to normal.

## `ao_can_overflow_4`

```c
void ao_can_overflow_4(uint32_t fifos);
```

| `fifos` | The bitmask indicating the affected FIFOs. |

Notifies the application of a receive buffer overflow. This function is called, when a message has been received, but the designated fifo is full.

## `ao_can_reg_4`

```c
#define ao_can_reg_4()     \
(                          \
    (ao_can_reg_t *)       \
    (                      \
        _CAN4_BASE_ADDRESS \
    )                      \
)
```

Gets the control registers.

## `ao_can_sent_4`

```c
void ao_can_sent_4(uint32_t fifos);
```

| `fifos` | The bitmask indicating the affected FIFOs. |

Notifies the application, that messages have been sent. This function is called, when all messages in a FIFO have been sent.

## `ao_can_start_4`
## `ao_can_stop_4`

```c
void ao_can_start_4();
void ao_can_stop_4();
```

Starts or stops the driver, respectively.

## `ao_can_system_4`

```c
void ao_can_system_4(ao_can_system_t x);
```

Notifies the application of a system error. This function is called due to two types of errors, addressing errors and bandwidth errors. Both of these errors are fatal. After the event was raised, the CAN module will be stopped and started over again.

An addressing error will occur, if the CAN module attempts to access a restricted memory location. Most likely, this results from

- an invalid FIFO base address, or
- an invalid configuration of the FIFO sizes in the C4FIFOCONi registers.

A bandwidth error will occur, when the CAN module is unable to write a received message to memory before the next message arrives. Most likely, this results from the CAN interrupt being delayed for a too long period of time.

## `ao_can_timer_4`

```c
void ao_can_timer_4();
```

Notifies the application of a timestamp timer overflow.

## `ao_can_underflow_4`

```c
void ao_can_underflow_4(uint32_t fifos);
```

| `fifos` | The bitmask indicating the affected FIFOs. |

Notifies the application of a transmit buffer underflow. This function is called, when a remote transmission request (RTR) has been received, but the designated FIFO to respond automatically is empty.

## `ao_can_wake_up_4`

```c
void ao_can_wake_up_4();
```

Notifies the application of a wake-up event. This function is called, when activity is detected on the CAN bus while the CAN module is in sleep mode.

# Variables

## `ao_can_in_4`

```c
extern ao_send_obj_t ao_can_in_4 [AO_CAN_FIFOS_RX_4];
```

The objects used to send inbound messages to the application.

## `ao_can_out_4`

```c
extern ao_recv_obj_t ao_can_out_4 [AO_CAN_FIFOS_TX_4];
```

The objects used to receive outbound messages from the application.

## `ao_can_task_4`

```c
extern ao_task_t ao_can_task_4;
```

The task.

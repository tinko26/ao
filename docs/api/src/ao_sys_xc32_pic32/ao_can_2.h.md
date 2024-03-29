---
author: "Stefan Wagner"
date: 2022-10-13
draft: true
permalink: /api/src/ao_sys_xc32_pic32/ao_can_2.h/
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

## `AO_CAN_2`

```c
#define AO_CAN_2 (false)
```

Defines whether to use the module.

## `AO_CAN_BAUD_2`

```c
#define AO_CAN_BAUD_2 (100000)
```

Defines the baud rate, in bits per second.

## `AO_CAN_BAUD_SAMPLE_2`

```c
#define AO_CAN_BAUD_SAMPLE_2 (85)
```

Defines the sample point, in per cent.

## `AO_CAN_BAUD_SAMPLE_THRICE_2`

```c
#define AO_CAN_BAUD_SAMPLE_THRICE_2 (true)
```

Defines whether to sample the bus line three times at the sample point.

## `AO_CAN_BAUD_SJW_2`

```c
#define AO_CAN_BAUD_SJW_2 (1)
```

Defines the synchronization jump width.

## `AO_CAN_BAUD_WAKE_UP_FILTER_2`

```c
#define AO_CAN_BAUD_WAKE_UP_FILTER_2 (false)
```

Defines whether to enable the bus line filter for wake-up.

## `AO_CAN_BUFFERS_2_*`

```c
#define AO_CAN_BUFFERS_2_0  (0)
#define AO_CAN_BUFFERS_2_1  (0)
#define AO_CAN_BUFFERS_2_2  (0)
#define AO_CAN_BUFFERS_2_3  (0)
#define AO_CAN_BUFFERS_2_4  (0)
#define AO_CAN_BUFFERS_2_5  (0)
#define AO_CAN_BUFFERS_2_6  (0)
#define AO_CAN_BUFFERS_2_7  (0)
#define AO_CAN_BUFFERS_2_8  (0)
#define AO_CAN_BUFFERS_2_9  (0)
#define AO_CAN_BUFFERS_2_10 (0)
#define AO_CAN_BUFFERS_2_11 (0)
#define AO_CAN_BUFFERS_2_12 (0)
#define AO_CAN_BUFFERS_2_13 (0)
#define AO_CAN_BUFFERS_2_14 (0)
#define AO_CAN_BUFFERS_2_15 (0)
#define AO_CAN_BUFFERS_2_16 (0)
#define AO_CAN_BUFFERS_2_17 (0)
#define AO_CAN_BUFFERS_2_18 (0)
#define AO_CAN_BUFFERS_2_19 (0)
#define AO_CAN_BUFFERS_2_20 (0)
#define AO_CAN_BUFFERS_2_21 (0)
#define AO_CAN_BUFFERS_2_22 (0)
#define AO_CAN_BUFFERS_2_23 (0)
#define AO_CAN_BUFFERS_2_24 (0)
#define AO_CAN_BUFFERS_2_25 (0)
#define AO_CAN_BUFFERS_2_26 (0)
#define AO_CAN_BUFFERS_2_27 (0)
#define AO_CAN_BUFFERS_2_28 (0)
#define AO_CAN_BUFFERS_2_29 (0)
#define AO_CAN_BUFFERS_2_30 (0)
#define AO_CAN_BUFFERS_2_31 (0)
```

Defines the number of buffers in each FIFO.

## `AO_CAN_BUS_2`

```c
#define AO_CAN_BUS_2 (false)
```

Defines whether to notify the application of bus errors.

## `AO_CAN_FIFOS_RX_2`
## `AO_CAN_FIFOS_TX_2`

```c
#define AO_CAN_FIFOS_RX_2 (0)
#define AO_CAN_FIFOS_TX_2 (0)
```

Defines the number of receive and transmit FIFOs.

## `AO_CAN_FILTER_EID_2_*`

```c
#define AO_CAN_FILTER_EID_2_0  (0)
#define AO_CAN_FILTER_EID_2_1  (0)
#define AO_CAN_FILTER_EID_2_2  (0)
#define AO_CAN_FILTER_EID_2_3  (0)
#define AO_CAN_FILTER_EID_2_4  (0)
#define AO_CAN_FILTER_EID_2_5  (0)
#define AO_CAN_FILTER_EID_2_6  (0)
#define AO_CAN_FILTER_EID_2_7  (0)
#define AO_CAN_FILTER_EID_2_8  (0)
#define AO_CAN_FILTER_EID_2_9  (0)
#define AO_CAN_FILTER_EID_2_10 (0)
#define AO_CAN_FILTER_EID_2_11 (0)
#define AO_CAN_FILTER_EID_2_12 (0)
#define AO_CAN_FILTER_EID_2_13 (0)
#define AO_CAN_FILTER_EID_2_14 (0)
#define AO_CAN_FILTER_EID_2_15 (0)
#define AO_CAN_FILTER_EID_2_16 (0)
#define AO_CAN_FILTER_EID_2_17 (0)
#define AO_CAN_FILTER_EID_2_18 (0)
#define AO_CAN_FILTER_EID_2_19 (0)
#define AO_CAN_FILTER_EID_2_20 (0)
#define AO_CAN_FILTER_EID_2_21 (0)
#define AO_CAN_FILTER_EID_2_22 (0)
#define AO_CAN_FILTER_EID_2_23 (0)
#define AO_CAN_FILTER_EID_2_24 (0)
#define AO_CAN_FILTER_EID_2_25 (0)
#define AO_CAN_FILTER_EID_2_26 (0)
#define AO_CAN_FILTER_EID_2_27 (0)
#define AO_CAN_FILTER_EID_2_28 (0)
#define AO_CAN_FILTER_EID_2_29 (0)
#define AO_CAN_FILTER_EID_2_30 (0)
#define AO_CAN_FILTER_EID_2_31 (0)
```

Defines the EID for each filter.

## `AO_CAN_FILTER_ENABLE_2_*`

```c
#define AO_CAN_FILTER_ENABLE_2_0  (0)
#define AO_CAN_FILTER_ENABLE_2_1  (0)
#define AO_CAN_FILTER_ENABLE_2_2  (0)
#define AO_CAN_FILTER_ENABLE_2_3  (0)
#define AO_CAN_FILTER_ENABLE_2_4  (0)
#define AO_CAN_FILTER_ENABLE_2_5  (0)
#define AO_CAN_FILTER_ENABLE_2_6  (0)
#define AO_CAN_FILTER_ENABLE_2_7  (0)
#define AO_CAN_FILTER_ENABLE_2_8  (0)
#define AO_CAN_FILTER_ENABLE_2_9  (0)
#define AO_CAN_FILTER_ENABLE_2_10 (0)
#define AO_CAN_FILTER_ENABLE_2_11 (0)
#define AO_CAN_FILTER_ENABLE_2_12 (0)
#define AO_CAN_FILTER_ENABLE_2_13 (0)
#define AO_CAN_FILTER_ENABLE_2_14 (0)
#define AO_CAN_FILTER_ENABLE_2_15 (0)
#define AO_CAN_FILTER_ENABLE_2_16 (0)
#define AO_CAN_FILTER_ENABLE_2_17 (0)
#define AO_CAN_FILTER_ENABLE_2_18 (0)
#define AO_CAN_FILTER_ENABLE_2_19 (0)
#define AO_CAN_FILTER_ENABLE_2_20 (0)
#define AO_CAN_FILTER_ENABLE_2_21 (0)
#define AO_CAN_FILTER_ENABLE_2_22 (0)
#define AO_CAN_FILTER_ENABLE_2_23 (0)
#define AO_CAN_FILTER_ENABLE_2_24 (0)
#define AO_CAN_FILTER_ENABLE_2_25 (0)
#define AO_CAN_FILTER_ENABLE_2_26 (0)
#define AO_CAN_FILTER_ENABLE_2_27 (0)
#define AO_CAN_FILTER_ENABLE_2_28 (0)
#define AO_CAN_FILTER_ENABLE_2_29 (0)
#define AO_CAN_FILTER_ENABLE_2_30 (0)
#define AO_CAN_FILTER_ENABLE_2_31 (0)
```

Defines the filters to enable.

## `AO_CAN_FILTER_FIFO_2_*`

```c
#define AO_CAN_FILTER_FIFO_2_0  (0)
#define AO_CAN_FILTER_FIFO_2_1  (0)
#define AO_CAN_FILTER_FIFO_2_2  (0)
#define AO_CAN_FILTER_FIFO_2_3  (0)
#define AO_CAN_FILTER_FIFO_2_4  (0)
#define AO_CAN_FILTER_FIFO_2_5  (0)
#define AO_CAN_FILTER_FIFO_2_6  (0)
#define AO_CAN_FILTER_FIFO_2_7  (0)
#define AO_CAN_FILTER_FIFO_2_8  (0)
#define AO_CAN_FILTER_FIFO_2_9  (0)
#define AO_CAN_FILTER_FIFO_2_10 (0)
#define AO_CAN_FILTER_FIFO_2_11 (0)
#define AO_CAN_FILTER_FIFO_2_12 (0)
#define AO_CAN_FILTER_FIFO_2_13 (0)
#define AO_CAN_FILTER_FIFO_2_14 (0)
#define AO_CAN_FILTER_FIFO_2_15 (0)
#define AO_CAN_FILTER_FIFO_2_16 (0)
#define AO_CAN_FILTER_FIFO_2_17 (0)
#define AO_CAN_FILTER_FIFO_2_18 (0)
#define AO_CAN_FILTER_FIFO_2_19 (0)
#define AO_CAN_FILTER_FIFO_2_20 (0)
#define AO_CAN_FILTER_FIFO_2_21 (0)
#define AO_CAN_FILTER_FIFO_2_22 (0)
#define AO_CAN_FILTER_FIFO_2_23 (0)
#define AO_CAN_FILTER_FIFO_2_24 (0)
#define AO_CAN_FILTER_FIFO_2_25 (0)
#define AO_CAN_FILTER_FIFO_2_26 (0)
#define AO_CAN_FILTER_FIFO_2_27 (0)
#define AO_CAN_FILTER_FIFO_2_28 (0)
#define AO_CAN_FILTER_FIFO_2_29 (0)
#define AO_CAN_FILTER_FIFO_2_30 (0)
#define AO_CAN_FILTER_FIFO_2_31 (0)
```

Defines the FIFO for each filter.

## `AO_CAN_FILTER_IDE_2_*`

```c
#define AO_CAN_FILTER_IDE_2_0  (0)
#define AO_CAN_FILTER_IDE_2_1  (0)
#define AO_CAN_FILTER_IDE_2_2  (0)
#define AO_CAN_FILTER_IDE_2_3  (0)
#define AO_CAN_FILTER_IDE_2_4  (0)
#define AO_CAN_FILTER_IDE_2_5  (0)
#define AO_CAN_FILTER_IDE_2_6  (0)
#define AO_CAN_FILTER_IDE_2_7  (0)
#define AO_CAN_FILTER_IDE_2_8  (0)
#define AO_CAN_FILTER_IDE_2_9  (0)
#define AO_CAN_FILTER_IDE_2_10 (0)
#define AO_CAN_FILTER_IDE_2_11 (0)
#define AO_CAN_FILTER_IDE_2_12 (0)
#define AO_CAN_FILTER_IDE_2_13 (0)
#define AO_CAN_FILTER_IDE_2_14 (0)
#define AO_CAN_FILTER_IDE_2_15 (0)
#define AO_CAN_FILTER_IDE_2_16 (0)
#define AO_CAN_FILTER_IDE_2_17 (0)
#define AO_CAN_FILTER_IDE_2_18 (0)
#define AO_CAN_FILTER_IDE_2_19 (0)
#define AO_CAN_FILTER_IDE_2_20 (0)
#define AO_CAN_FILTER_IDE_2_21 (0)
#define AO_CAN_FILTER_IDE_2_22 (0)
#define AO_CAN_FILTER_IDE_2_23 (0)
#define AO_CAN_FILTER_IDE_2_24 (0)
#define AO_CAN_FILTER_IDE_2_25 (0)
#define AO_CAN_FILTER_IDE_2_26 (0)
#define AO_CAN_FILTER_IDE_2_27 (0)
#define AO_CAN_FILTER_IDE_2_28 (0)
#define AO_CAN_FILTER_IDE_2_29 (0)
#define AO_CAN_FILTER_IDE_2_30 (0)
#define AO_CAN_FILTER_IDE_2_31 (0)
```

Defines the IDE for each filter.

## `AO_CAN_FILTER_MASK_2_*`

```c
#define AO_CAN_FILTER_MASK_2_0  (0)
#define AO_CAN_FILTER_MASK_2_1  (0)
#define AO_CAN_FILTER_MASK_2_2  (0)
#define AO_CAN_FILTER_MASK_2_3  (0)
#define AO_CAN_FILTER_MASK_2_4  (0)
#define AO_CAN_FILTER_MASK_2_5  (0)
#define AO_CAN_FILTER_MASK_2_6  (0)
#define AO_CAN_FILTER_MASK_2_7  (0)
#define AO_CAN_FILTER_MASK_2_8  (0)
#define AO_CAN_FILTER_MASK_2_9  (0)
#define AO_CAN_FILTER_MASK_2_10 (0)
#define AO_CAN_FILTER_MASK_2_11 (0)
#define AO_CAN_FILTER_MASK_2_12 (0)
#define AO_CAN_FILTER_MASK_2_13 (0)
#define AO_CAN_FILTER_MASK_2_14 (0)
#define AO_CAN_FILTER_MASK_2_15 (0)
#define AO_CAN_FILTER_MASK_2_16 (0)
#define AO_CAN_FILTER_MASK_2_17 (0)
#define AO_CAN_FILTER_MASK_2_18 (0)
#define AO_CAN_FILTER_MASK_2_19 (0)
#define AO_CAN_FILTER_MASK_2_20 (0)
#define AO_CAN_FILTER_MASK_2_21 (0)
#define AO_CAN_FILTER_MASK_2_22 (0)
#define AO_CAN_FILTER_MASK_2_23 (0)
#define AO_CAN_FILTER_MASK_2_24 (0)
#define AO_CAN_FILTER_MASK_2_25 (0)
#define AO_CAN_FILTER_MASK_2_26 (0)
#define AO_CAN_FILTER_MASK_2_27 (0)
#define AO_CAN_FILTER_MASK_2_28 (0)
#define AO_CAN_FILTER_MASK_2_29 (0)
#define AO_CAN_FILTER_MASK_2_30 (0)
#define AO_CAN_FILTER_MASK_2_31 (0)
```

Defines the filter mask for each filter.

## `AO_CAN_FILTER_MASK_EID_2_*`

```c
#define AO_CAN_FILTER_MASK_EID_2_0 (0)
#define AO_CAN_FILTER_MASK_EID_2_1 (0)
#define AO_CAN_FILTER_MASK_EID_2_2 (0)
#define AO_CAN_FILTER_MASK_EID_2_3 (0)
```

Defines the EID for each filter mask.

## `AO_CAN_FILTER_MASK_IDE_2_*`

```c
#define AO_CAN_FILTER_MASK_IDE_2_0 (0)
#define AO_CAN_FILTER_MASK_IDE_2_1 (0)
#define AO_CAN_FILTER_MASK_IDE_2_2 (0)
#define AO_CAN_FILTER_MASK_IDE_2_3 (0)
```

Defines the IDE for each filter mask.

## `AO_CAN_FILTER_MASK_SID_2_*`

```c
#define AO_CAN_FILTER_MASK_SID_2_0 (0)
#define AO_CAN_FILTER_MASK_SID_2_1 (0)
#define AO_CAN_FILTER_MASK_SID_2_2 (0)
#define AO_CAN_FILTER_MASK_SID_2_3 (0)
```

Defines the SID for each filter mask.

## `AO_CAN_FILTER_SID_2_*`

```c
#define AO_CAN_FILTER_SID_2_0  (0)
#define AO_CAN_FILTER_SID_2_1  (0)
#define AO_CAN_FILTER_SID_2_2  (0)
#define AO_CAN_FILTER_SID_2_3  (0)
#define AO_CAN_FILTER_SID_2_4  (0)
#define AO_CAN_FILTER_SID_2_5  (0)
#define AO_CAN_FILTER_SID_2_6  (0)
#define AO_CAN_FILTER_SID_2_7  (0)
#define AO_CAN_FILTER_SID_2_8  (0)
#define AO_CAN_FILTER_SID_2_9  (0)
#define AO_CAN_FILTER_SID_2_10 (0)
#define AO_CAN_FILTER_SID_2_11 (0)
#define AO_CAN_FILTER_SID_2_12 (0)
#define AO_CAN_FILTER_SID_2_13 (0)
#define AO_CAN_FILTER_SID_2_14 (0)
#define AO_CAN_FILTER_SID_2_15 (0)
#define AO_CAN_FILTER_SID_2_16 (0)
#define AO_CAN_FILTER_SID_2_17 (0)
#define AO_CAN_FILTER_SID_2_18 (0)
#define AO_CAN_FILTER_SID_2_19 (0)
#define AO_CAN_FILTER_SID_2_20 (0)
#define AO_CAN_FILTER_SID_2_21 (0)
#define AO_CAN_FILTER_SID_2_22 (0)
#define AO_CAN_FILTER_SID_2_23 (0)
#define AO_CAN_FILTER_SID_2_24 (0)
#define AO_CAN_FILTER_SID_2_25 (0)
#define AO_CAN_FILTER_SID_2_26 (0)
#define AO_CAN_FILTER_SID_2_27 (0)
#define AO_CAN_FILTER_SID_2_28 (0)
#define AO_CAN_FILTER_SID_2_29 (0)
#define AO_CAN_FILTER_SID_2_30 (0)
#define AO_CAN_FILTER_SID_2_31 (0)
```

Defines the SID for each filter.

## `AO_CAN_INVALID_2`

```c
#define AO_CAN_INVALID_2 (false)
```

Defines whether to notify the application of the reception or transmission of invalid messages.

## `AO_CAN_MODE_2`

```c
#define AO_CAN_MODE_2 (false)
```

Defines whether to notify the application of mode changes.

## `AO_CAN_OVERFLOW_2`

```c
#define AO_CAN_OVERFLOW_2 (false)
```

Defines whether to notify the application of receive buffer overflows.

## `AO_CAN_SENT_2`

```c
#define AO_CAN_SENT_2 (false)
```

Defines whether to notify the application, when messages have been sent.

## `AO_CAN_SYSTEM_2`

```c
#define AO_CAN_SYSTEM_2 (false)
```

Defines whether to notify the application of system errors.

## `AO_CAN_TIMER_2`

```c
#define AO_CAN_TIMER_2 (false)
```

Defines whether to notify the application of timestamp timer overflows.

## `AO_CAN_UNDERFLOW_2`

```c
#define AO_CAN_UNDERFLOW_2 (false)
```

Defines whether to notify the application of transmit buffer underflows.

## `AO_CAN_WAKE_UP_2`

```c
#define AO_CAN_WAKE_UP_2 (false)
```

Defines whether to notify the application of wake-up events.

# Constants

## `AO_CAN_BAUD_MAX_2`
## `AO_CAN_BAUD_MIN_2`

```c
#define AO_CAN_BAUD_MAX_2 AO_CAN_BAUD_MAX(AO_SYS_CLOCK_CAN2)
#define AO_CAN_BAUD_MIN_2 AO_CAN_BAUD_MIN(AO_SYS_CLOCK_CAN2)
```

The maximum and minimum baud rate.

## `AO_CAN_BUFFERS_2`

```c
#define AO_CAN_BUFFERS_2  \
(                         \
    AO_CAN_BUFFERS_2_0  + \
    AO_CAN_BUFFERS_2_1  + \
    AO_CAN_BUFFERS_2_2  + \
    AO_CAN_BUFFERS_2_3  + \
    AO_CAN_BUFFERS_2_4  + \
    AO_CAN_BUFFERS_2_5  + \
    AO_CAN_BUFFERS_2_6  + \
    AO_CAN_BUFFERS_2_7  + \
    AO_CAN_BUFFERS_2_8  + \
    AO_CAN_BUFFERS_2_9  + \
    AO_CAN_BUFFERS_2_10 + \
    AO_CAN_BUFFERS_2_11 + \
    AO_CAN_BUFFERS_2_12 + \
    AO_CAN_BUFFERS_2_13 + \
    AO_CAN_BUFFERS_2_14 + \
    AO_CAN_BUFFERS_2_15 + \
    AO_CAN_BUFFERS_2_16 + \
    AO_CAN_BUFFERS_2_17 + \
    AO_CAN_BUFFERS_2_18 + \
    AO_CAN_BUFFERS_2_19 + \
    AO_CAN_BUFFERS_2_20 + \
    AO_CAN_BUFFERS_2_21 + \
    AO_CAN_BUFFERS_2_22 + \
    AO_CAN_BUFFERS_2_23 + \
    AO_CAN_BUFFERS_2_24 + \
    AO_CAN_BUFFERS_2_25 + \
    AO_CAN_BUFFERS_2_26 + \
    AO_CAN_BUFFERS_2_27 + \
    AO_CAN_BUFFERS_2_28 + \
    AO_CAN_BUFFERS_2_29 + \
    AO_CAN_BUFFERS_2_30 + \
    AO_CAN_BUFFERS_2_31   \
)
```

The total number of buffers.

## `AO_CAN_FIFOS_2`

```c
#define AO_CAN_FIFOS_2    \
(                         \
    (AO_CAN_FIFOS_RX_2) + \
    (AO_CAN_FIFOS_TX_2)   \
)
```

The total number of FIFOs.

## `AO_CAN_RX_2`

```c
#define AO_CAN_RX_2         \
(                           \
    (AO_CAN_FIFOS_RX_2) > 0 \
    ? true                  \
    : false                 \
)
```

Indicates whether the module is configured to receive.

## `AO_CAN_TX_2`

```c
#define AO_CAN_TX_2         \
(                           \
    (AO_CAN_FIFOS_TX_2) > 0 \
    ? true                  \
    : false                 \
)
```

Indicates whether the module is configured to transmit.

# Functions

## `ao_can_bus_2`

```c
void ao_can_bus_2(ao_can_bus_t const * x);
```

Notifies the application of bus errors. This function is called every time there is a change in the current error state of the CAN module with respect to the CAN network. The error states are tracked by the C2TREC register.

## `ao_can_invalid_2`

```c
void ao_can_invalid_2();
```

Notifies the application, that an invalid message has been received or transmitted. However, the specific error is not available to the user application.

## `ao_can_listen_all_2`

```c
void ao_can_listen_all_2();
```

Sets the operation mode to listen all.

## `ao_can_listen_only_2`

```c
void ao_can_listen_only_2();
```

Sets the operation mode to listen only.

## `ao_can_loopback_2`

```c
void ao_can_loopback_2();
```

Sets the operation mode to loopback.

## `ao_can_mode_2`

```c
void ao_can_mode_2();
```

Notifies the application of a mode change.

## `ao_can_normal_2`

```c
void ao_can_normal_2();
```

Sets the operation mode to normal.

## `ao_can_overflow_2`

```c
void ao_can_overflow_2(uint32_t fifos);
```

| `fifos` | The bitmask indicating the affected FIFOs. |

Notifies the application of a receive buffer overflow. This function is called, when a message has been received, but the designated fifo is full.

## `ao_can_reg_2`

```c
#define ao_can_reg_2()     \
(                          \
    (ao_can_reg_t *)       \
    (                      \
        _CAN2_BASE_ADDRESS \
    )                      \
)
```

Gets the control registers.

## `ao_can_sent_2`

```c
void ao_can_sent_2(uint32_t fifos);
```

| `fifos` | The bitmask indicating the affected FIFOs. |

Notifies the application, that messages have been sent. This function is called, when all messages in a FIFO have been sent.

## `ao_can_start_2`
## `ao_can_stop_2`

```c
void ao_can_start_2();
void ao_can_stop_2();
```

Starts or stops the driver, respectively.

## `ao_can_system_2`

```c
void ao_can_system_2(ao_can_system_t x);
```

Notifies the application of a system error. This function is called due to two types of errors, addressing errors and bandwidth errors. Both of these errors are fatal. After the event was raised, the CAN module will be stopped and started over again.

An addressing error will occur, if the CAN module attempts to access a restricted memory location. Most likely, this results from

- an invalid FIFO base address, or
- an invalid configuration of the FIFO sizes in the C2FIFOCONi registers.

A bandwidth error will occur, when the CAN module is unable to write a received message to memory before the next message arrives. Most likely, this results from the CAN interrupt being delayed for a too long period of time.

## `ao_can_timer_2`

```c
void ao_can_timer_2();
```

Notifies the application of a timestamp timer overflow.

## `ao_can_underflow_2`

```c
void ao_can_underflow_2(uint32_t fifos);
```

| `fifos` | The bitmask indicating the affected FIFOs. |

Notifies the application of a transmit buffer underflow. This function is called, when a remote transmission request (RTR) has been received, but the designated FIFO to respond automatically is empty.

## `ao_can_wake_up_2`

```c
void ao_can_wake_up_2();
```

Notifies the application of a wake-up event. This function is called, when activity is detected on the CAN bus while the CAN module is in sleep mode.

# Variables

## `ao_can_in_2`

```c
extern ao_send_obj_t ao_can_in_2 [AO_CAN_FIFOS_RX_2];
```

The objects used to send inbound messages to the application.

## `ao_can_out_2`

```c
extern ao_recv_obj_t ao_can_out_2 [AO_CAN_FIFOS_TX_2];
```

The objects used to receive outbound messages from the application.

## `ao_can_task_2`

```c
extern ao_task_t ao_can_task_2;
```

The task.

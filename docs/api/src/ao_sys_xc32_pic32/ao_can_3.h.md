---
author: "Stefan Wagner"
date: 2022-10-13
draft: true
permalink: /api/src/ao_sys_xc32_pic32/ao_can_3.h/
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

## `AO_CAN_3`

```c
#define AO_CAN_3 (false)
```

Defines whether to use the module.

## `AO_CAN_BAUD_3`

```c
#define AO_CAN_BAUD_3 (100000)
```

Defines the baud rate, in bits per second.

## `AO_CAN_BAUD_SAMPLE_3`

```c
#define AO_CAN_BAUD_SAMPLE_3 (85)
```

Defines the sample point, in per cent.

## `AO_CAN_BAUD_SAMPLE_THRICE_3`

```c
#define AO_CAN_BAUD_SAMPLE_THRICE_3 (true)
```

Defines whether to sample the bus line three times at the sample point.

## `AO_CAN_BAUD_SJW_3`

```c
#define AO_CAN_BAUD_SJW_3 (1)
```

Defines the synchronization jump width.

## `AO_CAN_BAUD_WAKE_UP_FILTER_3`

```c
#define AO_CAN_BAUD_WAKE_UP_FILTER_3 (false)
```

Defines whether to enable the bus line filter for wake-up.

## `AO_CAN_BUFFERS_3_*`

```c
#define AO_CAN_BUFFERS_3_0  (0)
#define AO_CAN_BUFFERS_3_1  (0)
#define AO_CAN_BUFFERS_3_2  (0)
#define AO_CAN_BUFFERS_3_3  (0)
#define AO_CAN_BUFFERS_3_4  (0)
#define AO_CAN_BUFFERS_3_5  (0)
#define AO_CAN_BUFFERS_3_6  (0)
#define AO_CAN_BUFFERS_3_7  (0)
#define AO_CAN_BUFFERS_3_8  (0)
#define AO_CAN_BUFFERS_3_9  (0)
#define AO_CAN_BUFFERS_3_10 (0)
#define AO_CAN_BUFFERS_3_11 (0)
#define AO_CAN_BUFFERS_3_12 (0)
#define AO_CAN_BUFFERS_3_13 (0)
#define AO_CAN_BUFFERS_3_14 (0)
#define AO_CAN_BUFFERS_3_15 (0)
#define AO_CAN_BUFFERS_3_16 (0)
#define AO_CAN_BUFFERS_3_17 (0)
#define AO_CAN_BUFFERS_3_18 (0)
#define AO_CAN_BUFFERS_3_19 (0)
#define AO_CAN_BUFFERS_3_20 (0)
#define AO_CAN_BUFFERS_3_21 (0)
#define AO_CAN_BUFFERS_3_22 (0)
#define AO_CAN_BUFFERS_3_23 (0)
#define AO_CAN_BUFFERS_3_24 (0)
#define AO_CAN_BUFFERS_3_25 (0)
#define AO_CAN_BUFFERS_3_26 (0)
#define AO_CAN_BUFFERS_3_27 (0)
#define AO_CAN_BUFFERS_3_28 (0)
#define AO_CAN_BUFFERS_3_29 (0)
#define AO_CAN_BUFFERS_3_30 (0)
#define AO_CAN_BUFFERS_3_31 (0)
```

Defines the number of buffers in each FIFO.

## `AO_CAN_BUS_3`

```c
#define AO_CAN_BUS_3 (false)
```

Defines whether to notify the application of bus errors.

## `AO_CAN_FIFOS_RX_3`
## `AO_CAN_FIFOS_TX_3`

```c
#define AO_CAN_FIFOS_RX_3 (0)
#define AO_CAN_FIFOS_TX_3 (0)
```

Defines the number of receive and transmit FIFOs.

## `AO_CAN_FILTER_EID_3_*`

```c
#define AO_CAN_FILTER_EID_3_0  (0)
#define AO_CAN_FILTER_EID_3_1  (0)
#define AO_CAN_FILTER_EID_3_2  (0)
#define AO_CAN_FILTER_EID_3_3  (0)
#define AO_CAN_FILTER_EID_3_4  (0)
#define AO_CAN_FILTER_EID_3_5  (0)
#define AO_CAN_FILTER_EID_3_6  (0)
#define AO_CAN_FILTER_EID_3_7  (0)
#define AO_CAN_FILTER_EID_3_8  (0)
#define AO_CAN_FILTER_EID_3_9  (0)
#define AO_CAN_FILTER_EID_3_10 (0)
#define AO_CAN_FILTER_EID_3_11 (0)
#define AO_CAN_FILTER_EID_3_12 (0)
#define AO_CAN_FILTER_EID_3_13 (0)
#define AO_CAN_FILTER_EID_3_14 (0)
#define AO_CAN_FILTER_EID_3_15 (0)
#define AO_CAN_FILTER_EID_3_16 (0)
#define AO_CAN_FILTER_EID_3_17 (0)
#define AO_CAN_FILTER_EID_3_18 (0)
#define AO_CAN_FILTER_EID_3_19 (0)
#define AO_CAN_FILTER_EID_3_20 (0)
#define AO_CAN_FILTER_EID_3_21 (0)
#define AO_CAN_FILTER_EID_3_22 (0)
#define AO_CAN_FILTER_EID_3_23 (0)
#define AO_CAN_FILTER_EID_3_24 (0)
#define AO_CAN_FILTER_EID_3_25 (0)
#define AO_CAN_FILTER_EID_3_26 (0)
#define AO_CAN_FILTER_EID_3_27 (0)
#define AO_CAN_FILTER_EID_3_28 (0)
#define AO_CAN_FILTER_EID_3_29 (0)
#define AO_CAN_FILTER_EID_3_30 (0)
#define AO_CAN_FILTER_EID_3_31 (0)
```

Defines the EID for each filter.

## `AO_CAN_FILTER_ENABLE_3_*`

```c
#define AO_CAN_FILTER_ENABLE_3_0  (0)
#define AO_CAN_FILTER_ENABLE_3_1  (0)
#define AO_CAN_FILTER_ENABLE_3_2  (0)
#define AO_CAN_FILTER_ENABLE_3_3  (0)
#define AO_CAN_FILTER_ENABLE_3_4  (0)
#define AO_CAN_FILTER_ENABLE_3_5  (0)
#define AO_CAN_FILTER_ENABLE_3_6  (0)
#define AO_CAN_FILTER_ENABLE_3_7  (0)
#define AO_CAN_FILTER_ENABLE_3_8  (0)
#define AO_CAN_FILTER_ENABLE_3_9  (0)
#define AO_CAN_FILTER_ENABLE_3_10 (0)
#define AO_CAN_FILTER_ENABLE_3_11 (0)
#define AO_CAN_FILTER_ENABLE_3_12 (0)
#define AO_CAN_FILTER_ENABLE_3_13 (0)
#define AO_CAN_FILTER_ENABLE_3_14 (0)
#define AO_CAN_FILTER_ENABLE_3_15 (0)
#define AO_CAN_FILTER_ENABLE_3_16 (0)
#define AO_CAN_FILTER_ENABLE_3_17 (0)
#define AO_CAN_FILTER_ENABLE_3_18 (0)
#define AO_CAN_FILTER_ENABLE_3_19 (0)
#define AO_CAN_FILTER_ENABLE_3_20 (0)
#define AO_CAN_FILTER_ENABLE_3_21 (0)
#define AO_CAN_FILTER_ENABLE_3_22 (0)
#define AO_CAN_FILTER_ENABLE_3_23 (0)
#define AO_CAN_FILTER_ENABLE_3_24 (0)
#define AO_CAN_FILTER_ENABLE_3_25 (0)
#define AO_CAN_FILTER_ENABLE_3_26 (0)
#define AO_CAN_FILTER_ENABLE_3_27 (0)
#define AO_CAN_FILTER_ENABLE_3_28 (0)
#define AO_CAN_FILTER_ENABLE_3_29 (0)
#define AO_CAN_FILTER_ENABLE_3_30 (0)
#define AO_CAN_FILTER_ENABLE_3_31 (0)
```

Defines the filters to enable.

## `AO_CAN_FILTER_FIFO_3_*`

```c
#define AO_CAN_FILTER_FIFO_3_0  (0)
#define AO_CAN_FILTER_FIFO_3_1  (0)
#define AO_CAN_FILTER_FIFO_3_2  (0)
#define AO_CAN_FILTER_FIFO_3_3  (0)
#define AO_CAN_FILTER_FIFO_3_4  (0)
#define AO_CAN_FILTER_FIFO_3_5  (0)
#define AO_CAN_FILTER_FIFO_3_6  (0)
#define AO_CAN_FILTER_FIFO_3_7  (0)
#define AO_CAN_FILTER_FIFO_3_8  (0)
#define AO_CAN_FILTER_FIFO_3_9  (0)
#define AO_CAN_FILTER_FIFO_3_10 (0)
#define AO_CAN_FILTER_FIFO_3_11 (0)
#define AO_CAN_FILTER_FIFO_3_12 (0)
#define AO_CAN_FILTER_FIFO_3_13 (0)
#define AO_CAN_FILTER_FIFO_3_14 (0)
#define AO_CAN_FILTER_FIFO_3_15 (0)
#define AO_CAN_FILTER_FIFO_3_16 (0)
#define AO_CAN_FILTER_FIFO_3_17 (0)
#define AO_CAN_FILTER_FIFO_3_18 (0)
#define AO_CAN_FILTER_FIFO_3_19 (0)
#define AO_CAN_FILTER_FIFO_3_20 (0)
#define AO_CAN_FILTER_FIFO_3_21 (0)
#define AO_CAN_FILTER_FIFO_3_22 (0)
#define AO_CAN_FILTER_FIFO_3_23 (0)
#define AO_CAN_FILTER_FIFO_3_24 (0)
#define AO_CAN_FILTER_FIFO_3_25 (0)
#define AO_CAN_FILTER_FIFO_3_26 (0)
#define AO_CAN_FILTER_FIFO_3_27 (0)
#define AO_CAN_FILTER_FIFO_3_28 (0)
#define AO_CAN_FILTER_FIFO_3_29 (0)
#define AO_CAN_FILTER_FIFO_3_30 (0)
#define AO_CAN_FILTER_FIFO_3_31 (0)
```

Defines the FIFO for each filter.

## `AO_CAN_FILTER_IDE_3_*`

```c
#define AO_CAN_FILTER_IDE_3_0  (0)
#define AO_CAN_FILTER_IDE_3_1  (0)
#define AO_CAN_FILTER_IDE_3_2  (0)
#define AO_CAN_FILTER_IDE_3_3  (0)
#define AO_CAN_FILTER_IDE_3_4  (0)
#define AO_CAN_FILTER_IDE_3_5  (0)
#define AO_CAN_FILTER_IDE_3_6  (0)
#define AO_CAN_FILTER_IDE_3_7  (0)
#define AO_CAN_FILTER_IDE_3_8  (0)
#define AO_CAN_FILTER_IDE_3_9  (0)
#define AO_CAN_FILTER_IDE_3_10 (0)
#define AO_CAN_FILTER_IDE_3_11 (0)
#define AO_CAN_FILTER_IDE_3_12 (0)
#define AO_CAN_FILTER_IDE_3_13 (0)
#define AO_CAN_FILTER_IDE_3_14 (0)
#define AO_CAN_FILTER_IDE_3_15 (0)
#define AO_CAN_FILTER_IDE_3_16 (0)
#define AO_CAN_FILTER_IDE_3_17 (0)
#define AO_CAN_FILTER_IDE_3_18 (0)
#define AO_CAN_FILTER_IDE_3_19 (0)
#define AO_CAN_FILTER_IDE_3_20 (0)
#define AO_CAN_FILTER_IDE_3_21 (0)
#define AO_CAN_FILTER_IDE_3_22 (0)
#define AO_CAN_FILTER_IDE_3_23 (0)
#define AO_CAN_FILTER_IDE_3_24 (0)
#define AO_CAN_FILTER_IDE_3_25 (0)
#define AO_CAN_FILTER_IDE_3_26 (0)
#define AO_CAN_FILTER_IDE_3_27 (0)
#define AO_CAN_FILTER_IDE_3_28 (0)
#define AO_CAN_FILTER_IDE_3_29 (0)
#define AO_CAN_FILTER_IDE_3_30 (0)
#define AO_CAN_FILTER_IDE_3_31 (0)
```

Defines the IDE for each filter.

## `AO_CAN_FILTER_MASK_3_*`

```c
#define AO_CAN_FILTER_MASK_3_0  (0)
#define AO_CAN_FILTER_MASK_3_1  (0)
#define AO_CAN_FILTER_MASK_3_2  (0)
#define AO_CAN_FILTER_MASK_3_3  (0)
#define AO_CAN_FILTER_MASK_3_4  (0)
#define AO_CAN_FILTER_MASK_3_5  (0)
#define AO_CAN_FILTER_MASK_3_6  (0)
#define AO_CAN_FILTER_MASK_3_7  (0)
#define AO_CAN_FILTER_MASK_3_8  (0)
#define AO_CAN_FILTER_MASK_3_9  (0)
#define AO_CAN_FILTER_MASK_3_10 (0)
#define AO_CAN_FILTER_MASK_3_11 (0)
#define AO_CAN_FILTER_MASK_3_12 (0)
#define AO_CAN_FILTER_MASK_3_13 (0)
#define AO_CAN_FILTER_MASK_3_14 (0)
#define AO_CAN_FILTER_MASK_3_15 (0)
#define AO_CAN_FILTER_MASK_3_16 (0)
#define AO_CAN_FILTER_MASK_3_17 (0)
#define AO_CAN_FILTER_MASK_3_18 (0)
#define AO_CAN_FILTER_MASK_3_19 (0)
#define AO_CAN_FILTER_MASK_3_20 (0)
#define AO_CAN_FILTER_MASK_3_21 (0)
#define AO_CAN_FILTER_MASK_3_22 (0)
#define AO_CAN_FILTER_MASK_3_23 (0)
#define AO_CAN_FILTER_MASK_3_24 (0)
#define AO_CAN_FILTER_MASK_3_25 (0)
#define AO_CAN_FILTER_MASK_3_26 (0)
#define AO_CAN_FILTER_MASK_3_27 (0)
#define AO_CAN_FILTER_MASK_3_28 (0)
#define AO_CAN_FILTER_MASK_3_29 (0)
#define AO_CAN_FILTER_MASK_3_30 (0)
#define AO_CAN_FILTER_MASK_3_31 (0)
```

Defines the filter mask for each filter.

## `AO_CAN_FILTER_MASK_EID_3_*`

```c
#define AO_CAN_FILTER_MASK_EID_3_0 (0)
#define AO_CAN_FILTER_MASK_EID_3_1 (0)
#define AO_CAN_FILTER_MASK_EID_3_2 (0)
#define AO_CAN_FILTER_MASK_EID_3_3 (0)
```

Defines the EID for each filter mask.

## `AO_CAN_FILTER_MASK_IDE_3_*`

```c
#define AO_CAN_FILTER_MASK_IDE_3_0 (0)
#define AO_CAN_FILTER_MASK_IDE_3_1 (0)
#define AO_CAN_FILTER_MASK_IDE_3_2 (0)
#define AO_CAN_FILTER_MASK_IDE_3_3 (0)
```

Defines the IDE for each filter mask.

## `AO_CAN_FILTER_MASK_SID_3_*`

```c
#define AO_CAN_FILTER_MASK_SID_3_0 (0)
#define AO_CAN_FILTER_MASK_SID_3_1 (0)
#define AO_CAN_FILTER_MASK_SID_3_2 (0)
#define AO_CAN_FILTER_MASK_SID_3_3 (0)
```

Defines the SID for each filter mask.

## `AO_CAN_FILTER_SID_3_*`

```c
#define AO_CAN_FILTER_SID_3_0  (0)
#define AO_CAN_FILTER_SID_3_1  (0)
#define AO_CAN_FILTER_SID_3_2  (0)
#define AO_CAN_FILTER_SID_3_3  (0)
#define AO_CAN_FILTER_SID_3_4  (0)
#define AO_CAN_FILTER_SID_3_5  (0)
#define AO_CAN_FILTER_SID_3_6  (0)
#define AO_CAN_FILTER_SID_3_7  (0)
#define AO_CAN_FILTER_SID_3_8  (0)
#define AO_CAN_FILTER_SID_3_9  (0)
#define AO_CAN_FILTER_SID_3_10 (0)
#define AO_CAN_FILTER_SID_3_11 (0)
#define AO_CAN_FILTER_SID_3_12 (0)
#define AO_CAN_FILTER_SID_3_13 (0)
#define AO_CAN_FILTER_SID_3_14 (0)
#define AO_CAN_FILTER_SID_3_15 (0)
#define AO_CAN_FILTER_SID_3_16 (0)
#define AO_CAN_FILTER_SID_3_17 (0)
#define AO_CAN_FILTER_SID_3_18 (0)
#define AO_CAN_FILTER_SID_3_19 (0)
#define AO_CAN_FILTER_SID_3_20 (0)
#define AO_CAN_FILTER_SID_3_21 (0)
#define AO_CAN_FILTER_SID_3_22 (0)
#define AO_CAN_FILTER_SID_3_23 (0)
#define AO_CAN_FILTER_SID_3_24 (0)
#define AO_CAN_FILTER_SID_3_25 (0)
#define AO_CAN_FILTER_SID_3_26 (0)
#define AO_CAN_FILTER_SID_3_27 (0)
#define AO_CAN_FILTER_SID_3_28 (0)
#define AO_CAN_FILTER_SID_3_29 (0)
#define AO_CAN_FILTER_SID_3_30 (0)
#define AO_CAN_FILTER_SID_3_31 (0)
```

Defines the SID for each filter.

## `AO_CAN_INVALID_3`

```c
#define AO_CAN_INVALID_3 (false)
```

Defines whether to notify the application of the reception or transmission of invalid messages.

## `AO_CAN_MODE_3`

```c
#define AO_CAN_MODE_3 (false)
```

Defines whether to notify the application of mode changes.

## `AO_CAN_OVERFLOW_3`

```c
#define AO_CAN_OVERFLOW_3 (false)
```

Defines whether to notify the application of receive buffer overflows.

## `AO_CAN_SENT_3`

```c
#define AO_CAN_SENT_3 (false)
```

Defines whether to notify the application, when messages have been sent.

## `AO_CAN_SYSTEM_3`

```c
#define AO_CAN_SYSTEM_3 (false)
```

Defines whether to notify the application of system errors.

## `AO_CAN_TIMER_3`

```c
#define AO_CAN_TIMER_3 (false)
```

Defines whether to notify the application of timestamp timer overflows.

## `AO_CAN_UNDERFLOW_3`

```c
#define AO_CAN_UNDERFLOW_3 (false)
```

Defines whether to notify the application of transmit buffer underflows.

## `AO_CAN_WAKE_UP_3`

```c
#define AO_CAN_WAKE_UP_3 (false)
```

Defines whether to notify the application of wake-up events.

# Constants

## `AO_CAN_BAUD_MAX_3`
## `AO_CAN_BAUD_MIN_3`

```c
#define AO_CAN_BAUD_MAX_3 AO_CAN_BAUD_MAX(AO_SYS_CLOCK_CAN3)
#define AO_CAN_BAUD_MIN_3 AO_CAN_BAUD_MIN(AO_SYS_CLOCK_CAN3)
```

The maximum and minimum baud rate.

## `AO_CAN_BUFFERS_3`

```c
#define AO_CAN_BUFFERS_3  \
(                         \
    AO_CAN_BUFFERS_3_0  + \
    AO_CAN_BUFFERS_3_1  + \
    AO_CAN_BUFFERS_3_2  + \
    AO_CAN_BUFFERS_3_3  + \
    AO_CAN_BUFFERS_3_4  + \
    AO_CAN_BUFFERS_3_5  + \
    AO_CAN_BUFFERS_3_6  + \
    AO_CAN_BUFFERS_3_7  + \
    AO_CAN_BUFFERS_3_8  + \
    AO_CAN_BUFFERS_3_9  + \
    AO_CAN_BUFFERS_3_10 + \
    AO_CAN_BUFFERS_3_11 + \
    AO_CAN_BUFFERS_3_12 + \
    AO_CAN_BUFFERS_3_13 + \
    AO_CAN_BUFFERS_3_14 + \
    AO_CAN_BUFFERS_3_15 + \
    AO_CAN_BUFFERS_3_16 + \
    AO_CAN_BUFFERS_3_17 + \
    AO_CAN_BUFFERS_3_18 + \
    AO_CAN_BUFFERS_3_19 + \
    AO_CAN_BUFFERS_3_20 + \
    AO_CAN_BUFFERS_3_21 + \
    AO_CAN_BUFFERS_3_22 + \
    AO_CAN_BUFFERS_3_23 + \
    AO_CAN_BUFFERS_3_24 + \
    AO_CAN_BUFFERS_3_25 + \
    AO_CAN_BUFFERS_3_26 + \
    AO_CAN_BUFFERS_3_27 + \
    AO_CAN_BUFFERS_3_28 + \
    AO_CAN_BUFFERS_3_29 + \
    AO_CAN_BUFFERS_3_30 + \
    AO_CAN_BUFFERS_3_31   \
)
```

The total number of buffers.

## `AO_CAN_FIFOS_3`

```c
#define AO_CAN_FIFOS_3    \
(                         \
    (AO_CAN_FIFOS_RX_3) + \
    (AO_CAN_FIFOS_TX_3)   \
)
```

The total number of FIFOs.

## `AO_CAN_RX_3`

```c
#define AO_CAN_RX_3         \
(                           \
    (AO_CAN_FIFOS_RX_3) > 0 \
    ? true                  \
    : false                 \
)
```

Indicates whether the module is configured to receive.

## `AO_CAN_TX_3`

```c
#define AO_CAN_TX_3         \
(                           \
    (AO_CAN_FIFOS_TX_3) > 0 \
    ? true                  \
    : false                 \
)
```

Indicates whether the module is configured to transmit.

# Functions

## `ao_can_bus_3`

```c
void ao_can_bus_3(ao_can_bus_t const * x);
```

Notifies the application of bus errors. This function is called every time there is a change in the current error state of the CAN module with respect to the CAN network. The error states are tracked by the C3TREC register.

## `ao_can_invalid_3`

```c
void ao_can_invalid_3();
```

Notifies the application, that an invalid message has been received or transmitted. However, the specific error is not available to the user application.

## `ao_can_listen_all_3`

```c
void ao_can_listen_all_3();
```

Sets the operation mode to listen all.

## `ao_can_listen_only_3`

```c
void ao_can_listen_only_3();
```

Sets the operation mode to listen only.

## `ao_can_loopback_3`

```c
void ao_can_loopback_3();
```

Sets the operation mode to loopback.

## `ao_can_mode_3`

```c
void ao_can_mode_3();
```

Notifies the application of a mode change.

## `ao_can_normal_3`

```c
void ao_can_normal_3();
```

Sets the operation mode to normal.

## `ao_can_overflow_3`

```c
void ao_can_overflow_3(uint32_t fifos);
```

| `fifos` | The bitmask indicating the affected FIFOs. |

Notifies the application of a receive buffer overflow. This function is called, when a message has been received, but the designated fifo is full.

## `ao_can_reg_3`

```c
#define ao_can_reg_3()     \
(                          \
    (ao_can_reg_t *)       \
    (                      \
        _CAN3_BASE_ADDRESS \
    )                      \
)
```

Gets the control registers.

## `ao_can_sent_3`

```c
void ao_can_sent_3(uint32_t fifos);
```

| `fifos` | The bitmask indicating the affected FIFOs. |

Notifies the application, that messages have been sent. This function is called, when all messages in a FIFO have been sent.

## `ao_can_start_3`
## `ao_can_stop_3`

```c
void ao_can_start_3();
void ao_can_stop_3();
```

Starts or stops the driver, respectively.

## `ao_can_system_3`

```c
void ao_can_system_3(ao_can_system_t x);
```

Notifies the application of a system error. This function is called due to two types of errors, addressing errors and bandwidth errors. Both of these errors are fatal. After the event was raised, the CAN module will be stopped and started over again.

An addressing error will occur, if the CAN module attempts to access a restricted memory location. Most likely, this results from

- an invalid FIFO base address, or
- an invalid configuration of the FIFO sizes in the C3FIFOCONi registers.

A bandwidth error will occur, when the CAN module is unable to write a received message to memory before the next message arrives. Most likely, this results from the CAN interrupt being delayed for a too long period of time.

## `ao_can_timer_3`

```c
void ao_can_timer_3();
```

Notifies the application of a timestamp timer overflow.

## `ao_can_underflow_3`

```c
void ao_can_underflow_3(uint32_t fifos);
```

| `fifos` | The bitmask indicating the affected FIFOs. |

Notifies the application of a transmit buffer underflow. This function is called, when a remote transmission request (RTR) has been received, but the designated FIFO to respond automatically is empty.

## `ao_can_wake_up_3`

```c
void ao_can_wake_up_3();
```

Notifies the application of a wake-up event. This function is called, when activity is detected on the CAN bus while the CAN module is in sleep mode.

# Variables

## `ao_can_in_3`

```c
extern ao_send_obj_t ao_can_in_3 [AO_CAN_FIFOS_RX_3];
```

The objects used to send inbound messages to the application.

## `ao_can_out_3`

```c
extern ao_recv_obj_t ao_can_out_3 [AO_CAN_FIFOS_TX_3];
```

The objects used to receive outbound messages from the application.

## `ao_can_task_3`

```c
extern ao_task_t ao_can_task_3;
```

The task.

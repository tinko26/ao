---
author: "Stefan Wagner"
date: 2022-09-23
draft: true
permalink: /api/src/ao_sys_xc32_pic32_can/ao_can_1.h/
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

# Identifier

```c
#define AO_CAN_1
```

# Configuration

## `AO_CAN_1`

```c
#define AO_CAN_1 (false)
```

Defines whether to use the module.

## `AO_CAN_BAUD_1`

```c
#define AO_CAN_BAUD_1 (100000)
```

Defines the baud rate, in bits per second.

## `AO_CAN_BAUD_SAMPLE_1`

```c
#define AO_CAN_BAUD_SAMPLE_1 (85)
```

Defines the sample point, in per cent.

## `AO_CAN_BAUD_SAMPLE_THRICE_1`

```c
#define AO_CAN_BAUD_SAMPLE_THRICE_1 (true)
```

Defines whether to sample the bus line three times at the sample point.

## `AO_CAN_BAUD_SJW_1`

```c
#define AO_CAN_BAUD_SJW_1 (1)
```

Defines the synchronization jump width.

## `AO_CAN_BAUD_WAKE_UP_FILTER_1`

```c
#define AO_CAN_BAUD_WAKE_UP_FILTER_1 (false)
```

Defines whether to enable the bus line filter for wake-up.

## `AO_CAN_BUFFERS_1_*`

```c
#define AO_CAN_BUFFERS_1_0  (0)
#define AO_CAN_BUFFERS_1_1  (0)
#define AO_CAN_BUFFERS_1_2  (0)
#define AO_CAN_BUFFERS_1_3  (0)
#define AO_CAN_BUFFERS_1_4  (0)
#define AO_CAN_BUFFERS_1_5  (0)
#define AO_CAN_BUFFERS_1_6  (0)
#define AO_CAN_BUFFERS_1_7  (0)
#define AO_CAN_BUFFERS_1_8  (0)
#define AO_CAN_BUFFERS_1_9  (0)
#define AO_CAN_BUFFERS_1_10 (0)
#define AO_CAN_BUFFERS_1_11 (0)
#define AO_CAN_BUFFERS_1_12 (0)
#define AO_CAN_BUFFERS_1_13 (0)
#define AO_CAN_BUFFERS_1_14 (0)
#define AO_CAN_BUFFERS_1_15 (0)
#define AO_CAN_BUFFERS_1_16 (0)
#define AO_CAN_BUFFERS_1_17 (0)
#define AO_CAN_BUFFERS_1_18 (0)
#define AO_CAN_BUFFERS_1_19 (0)
#define AO_CAN_BUFFERS_1_20 (0)
#define AO_CAN_BUFFERS_1_21 (0)
#define AO_CAN_BUFFERS_1_22 (0)
#define AO_CAN_BUFFERS_1_23 (0)
#define AO_CAN_BUFFERS_1_24 (0)
#define AO_CAN_BUFFERS_1_25 (0)
#define AO_CAN_BUFFERS_1_26 (0)
#define AO_CAN_BUFFERS_1_27 (0)
#define AO_CAN_BUFFERS_1_28 (0)
#define AO_CAN_BUFFERS_1_29 (0)
#define AO_CAN_BUFFERS_1_30 (0)
#define AO_CAN_BUFFERS_1_31 (0)
```

Defines the number of buffers in each FIFO.

## `AO_CAN_BUS_1`

```c
#define AO_CAN_BUS_1 (false)
```

Defines whether to notify the application of bus errors.

## `AO_CAN_FIFOS_RX_1`
## `AO_CAN_FIFOS_TX_1`

```c
#define AO_CAN_FIFOS_RX_1 (0)
#define AO_CAN_FIFOS_TX_1 (0)
```

Defines the number of receive and transmit FIFOs.

## `AO_CAN_FILTER_EID_1_*`

```c
#define AO_CAN_FILTER_EID_1_0  (0)
#define AO_CAN_FILTER_EID_1_1  (0)
#define AO_CAN_FILTER_EID_1_2  (0)
#define AO_CAN_FILTER_EID_1_3  (0)
#define AO_CAN_FILTER_EID_1_4  (0)
#define AO_CAN_FILTER_EID_1_5  (0)
#define AO_CAN_FILTER_EID_1_6  (0)
#define AO_CAN_FILTER_EID_1_7  (0)
#define AO_CAN_FILTER_EID_1_8  (0)
#define AO_CAN_FILTER_EID_1_9  (0)
#define AO_CAN_FILTER_EID_1_10 (0)
#define AO_CAN_FILTER_EID_1_11 (0)
#define AO_CAN_FILTER_EID_1_12 (0)
#define AO_CAN_FILTER_EID_1_13 (0)
#define AO_CAN_FILTER_EID_1_14 (0)
#define AO_CAN_FILTER_EID_1_15 (0)
#define AO_CAN_FILTER_EID_1_16 (0)
#define AO_CAN_FILTER_EID_1_17 (0)
#define AO_CAN_FILTER_EID_1_18 (0)
#define AO_CAN_FILTER_EID_1_19 (0)
#define AO_CAN_FILTER_EID_1_20 (0)
#define AO_CAN_FILTER_EID_1_21 (0)
#define AO_CAN_FILTER_EID_1_22 (0)
#define AO_CAN_FILTER_EID_1_23 (0)
#define AO_CAN_FILTER_EID_1_24 (0)
#define AO_CAN_FILTER_EID_1_25 (0)
#define AO_CAN_FILTER_EID_1_26 (0)
#define AO_CAN_FILTER_EID_1_27 (0)
#define AO_CAN_FILTER_EID_1_28 (0)
#define AO_CAN_FILTER_EID_1_29 (0)
#define AO_CAN_FILTER_EID_1_30 (0)
#define AO_CAN_FILTER_EID_1_31 (0)
```

Defines the EID for each filter.

## `AO_CAN_FILTER_ENABLE_1_*`

```c
#define AO_CAN_FILTER_ENABLE_1_0  (0)
#define AO_CAN_FILTER_ENABLE_1_1  (0)
#define AO_CAN_FILTER_ENABLE_1_2  (0)
#define AO_CAN_FILTER_ENABLE_1_3  (0)
#define AO_CAN_FILTER_ENABLE_1_4  (0)
#define AO_CAN_FILTER_ENABLE_1_5  (0)
#define AO_CAN_FILTER_ENABLE_1_6  (0)
#define AO_CAN_FILTER_ENABLE_1_7  (0)
#define AO_CAN_FILTER_ENABLE_1_8  (0)
#define AO_CAN_FILTER_ENABLE_1_9  (0)
#define AO_CAN_FILTER_ENABLE_1_10 (0)
#define AO_CAN_FILTER_ENABLE_1_11 (0)
#define AO_CAN_FILTER_ENABLE_1_12 (0)
#define AO_CAN_FILTER_ENABLE_1_13 (0)
#define AO_CAN_FILTER_ENABLE_1_14 (0)
#define AO_CAN_FILTER_ENABLE_1_15 (0)
#define AO_CAN_FILTER_ENABLE_1_16 (0)
#define AO_CAN_FILTER_ENABLE_1_17 (0)
#define AO_CAN_FILTER_ENABLE_1_18 (0)
#define AO_CAN_FILTER_ENABLE_1_19 (0)
#define AO_CAN_FILTER_ENABLE_1_20 (0)
#define AO_CAN_FILTER_ENABLE_1_21 (0)
#define AO_CAN_FILTER_ENABLE_1_22 (0)
#define AO_CAN_FILTER_ENABLE_1_23 (0)
#define AO_CAN_FILTER_ENABLE_1_24 (0)
#define AO_CAN_FILTER_ENABLE_1_25 (0)
#define AO_CAN_FILTER_ENABLE_1_26 (0)
#define AO_CAN_FILTER_ENABLE_1_27 (0)
#define AO_CAN_FILTER_ENABLE_1_28 (0)
#define AO_CAN_FILTER_ENABLE_1_29 (0)
#define AO_CAN_FILTER_ENABLE_1_30 (0)
#define AO_CAN_FILTER_ENABLE_1_31 (0)
```

Defines the filters to enable.

## `AO_CAN_FILTER_FIFO_1_*`

```c
#define AO_CAN_FILTER_FIFO_1_0  (0)
#define AO_CAN_FILTER_FIFO_1_1  (0)
#define AO_CAN_FILTER_FIFO_1_2  (0)
#define AO_CAN_FILTER_FIFO_1_3  (0)
#define AO_CAN_FILTER_FIFO_1_4  (0)
#define AO_CAN_FILTER_FIFO_1_5  (0)
#define AO_CAN_FILTER_FIFO_1_6  (0)
#define AO_CAN_FILTER_FIFO_1_7  (0)
#define AO_CAN_FILTER_FIFO_1_8  (0)
#define AO_CAN_FILTER_FIFO_1_9  (0)
#define AO_CAN_FILTER_FIFO_1_10 (0)
#define AO_CAN_FILTER_FIFO_1_11 (0)
#define AO_CAN_FILTER_FIFO_1_12 (0)
#define AO_CAN_FILTER_FIFO_1_13 (0)
#define AO_CAN_FILTER_FIFO_1_14 (0)
#define AO_CAN_FILTER_FIFO_1_15 (0)
#define AO_CAN_FILTER_FIFO_1_16 (0)
#define AO_CAN_FILTER_FIFO_1_17 (0)
#define AO_CAN_FILTER_FIFO_1_18 (0)
#define AO_CAN_FILTER_FIFO_1_19 (0)
#define AO_CAN_FILTER_FIFO_1_20 (0)
#define AO_CAN_FILTER_FIFO_1_21 (0)
#define AO_CAN_FILTER_FIFO_1_22 (0)
#define AO_CAN_FILTER_FIFO_1_23 (0)
#define AO_CAN_FILTER_FIFO_1_24 (0)
#define AO_CAN_FILTER_FIFO_1_25 (0)
#define AO_CAN_FILTER_FIFO_1_26 (0)
#define AO_CAN_FILTER_FIFO_1_27 (0)
#define AO_CAN_FILTER_FIFO_1_28 (0)
#define AO_CAN_FILTER_FIFO_1_29 (0)
#define AO_CAN_FILTER_FIFO_1_30 (0)
#define AO_CAN_FILTER_FIFO_1_31 (0)
```

Defines the FIFO for each filter.

## `AO_CAN_FILTER_IDE_1_*`

```c
#define AO_CAN_FILTER_IDE_1_0  (0)
#define AO_CAN_FILTER_IDE_1_1  (0)
#define AO_CAN_FILTER_IDE_1_2  (0)
#define AO_CAN_FILTER_IDE_1_3  (0)
#define AO_CAN_FILTER_IDE_1_4  (0)
#define AO_CAN_FILTER_IDE_1_5  (0)
#define AO_CAN_FILTER_IDE_1_6  (0)
#define AO_CAN_FILTER_IDE_1_7  (0)
#define AO_CAN_FILTER_IDE_1_8  (0)
#define AO_CAN_FILTER_IDE_1_9  (0)
#define AO_CAN_FILTER_IDE_1_10 (0)
#define AO_CAN_FILTER_IDE_1_11 (0)
#define AO_CAN_FILTER_IDE_1_12 (0)
#define AO_CAN_FILTER_IDE_1_13 (0)
#define AO_CAN_FILTER_IDE_1_14 (0)
#define AO_CAN_FILTER_IDE_1_15 (0)
#define AO_CAN_FILTER_IDE_1_16 (0)
#define AO_CAN_FILTER_IDE_1_17 (0)
#define AO_CAN_FILTER_IDE_1_18 (0)
#define AO_CAN_FILTER_IDE_1_19 (0)
#define AO_CAN_FILTER_IDE_1_20 (0)
#define AO_CAN_FILTER_IDE_1_21 (0)
#define AO_CAN_FILTER_IDE_1_22 (0)
#define AO_CAN_FILTER_IDE_1_23 (0)
#define AO_CAN_FILTER_IDE_1_24 (0)
#define AO_CAN_FILTER_IDE_1_25 (0)
#define AO_CAN_FILTER_IDE_1_26 (0)
#define AO_CAN_FILTER_IDE_1_27 (0)
#define AO_CAN_FILTER_IDE_1_28 (0)
#define AO_CAN_FILTER_IDE_1_29 (0)
#define AO_CAN_FILTER_IDE_1_30 (0)
#define AO_CAN_FILTER_IDE_1_31 (0)
```

Defines the IDE for each filter.

## `AO_CAN_FILTER_MASK_1_*`

```c
#define AO_CAN_FILTER_MASK_1_0  (0)
#define AO_CAN_FILTER_MASK_1_1  (0)
#define AO_CAN_FILTER_MASK_1_2  (0)
#define AO_CAN_FILTER_MASK_1_3  (0)
#define AO_CAN_FILTER_MASK_1_4  (0)
#define AO_CAN_FILTER_MASK_1_5  (0)
#define AO_CAN_FILTER_MASK_1_6  (0)
#define AO_CAN_FILTER_MASK_1_7  (0)
#define AO_CAN_FILTER_MASK_1_8  (0)
#define AO_CAN_FILTER_MASK_1_9  (0)
#define AO_CAN_FILTER_MASK_1_10 (0)
#define AO_CAN_FILTER_MASK_1_11 (0)
#define AO_CAN_FILTER_MASK_1_12 (0)
#define AO_CAN_FILTER_MASK_1_13 (0)
#define AO_CAN_FILTER_MASK_1_14 (0)
#define AO_CAN_FILTER_MASK_1_15 (0)
#define AO_CAN_FILTER_MASK_1_16 (0)
#define AO_CAN_FILTER_MASK_1_17 (0)
#define AO_CAN_FILTER_MASK_1_18 (0)
#define AO_CAN_FILTER_MASK_1_19 (0)
#define AO_CAN_FILTER_MASK_1_20 (0)
#define AO_CAN_FILTER_MASK_1_21 (0)
#define AO_CAN_FILTER_MASK_1_22 (0)
#define AO_CAN_FILTER_MASK_1_23 (0)
#define AO_CAN_FILTER_MASK_1_24 (0)
#define AO_CAN_FILTER_MASK_1_25 (0)
#define AO_CAN_FILTER_MASK_1_26 (0)
#define AO_CAN_FILTER_MASK_1_27 (0)
#define AO_CAN_FILTER_MASK_1_28 (0)
#define AO_CAN_FILTER_MASK_1_29 (0)
#define AO_CAN_FILTER_MASK_1_30 (0)
#define AO_CAN_FILTER_MASK_1_31 (0)
```

Defines the filter mask for each filter.

## `AO_CAN_FILTER_MASK_EID_1_*`

```c
#define AO_CAN_FILTER_MASK_EID_1_0 (0)
#define AO_CAN_FILTER_MASK_EID_1_1 (0)
#define AO_CAN_FILTER_MASK_EID_1_2 (0)
#define AO_CAN_FILTER_MASK_EID_1_3 (0)
```

Defines the EID for each filter mask.

## `AO_CAN_FILTER_MASK_IDE_1_*`

```c
#define AO_CAN_FILTER_MASK_IDE_1_0 (0)
#define AO_CAN_FILTER_MASK_IDE_1_1 (0)
#define AO_CAN_FILTER_MASK_IDE_1_2 (0)
#define AO_CAN_FILTER_MASK_IDE_1_3 (0)
```

Defines the IDE for each filter mask.

## `AO_CAN_FILTER_MASK_SID_1_*`

```c
#define AO_CAN_FILTER_MASK_SID_1_0 (0)
#define AO_CAN_FILTER_MASK_SID_1_1 (0)
#define AO_CAN_FILTER_MASK_SID_1_2 (0)
#define AO_CAN_FILTER_MASK_SID_1_3 (0)
```

Defines the SID for each filter mask.

## `AO_CAN_FILTER_SID_1_*`

```c
#define AO_CAN_FILTER_SID_1_0  (0)
#define AO_CAN_FILTER_SID_1_1  (0)
#define AO_CAN_FILTER_SID_1_2  (0)
#define AO_CAN_FILTER_SID_1_3  (0)
#define AO_CAN_FILTER_SID_1_4  (0)
#define AO_CAN_FILTER_SID_1_5  (0)
#define AO_CAN_FILTER_SID_1_6  (0)
#define AO_CAN_FILTER_SID_1_7  (0)
#define AO_CAN_FILTER_SID_1_8  (0)
#define AO_CAN_FILTER_SID_1_9  (0)
#define AO_CAN_FILTER_SID_1_10 (0)
#define AO_CAN_FILTER_SID_1_11 (0)
#define AO_CAN_FILTER_SID_1_12 (0)
#define AO_CAN_FILTER_SID_1_13 (0)
#define AO_CAN_FILTER_SID_1_14 (0)
#define AO_CAN_FILTER_SID_1_15 (0)
#define AO_CAN_FILTER_SID_1_16 (0)
#define AO_CAN_FILTER_SID_1_17 (0)
#define AO_CAN_FILTER_SID_1_18 (0)
#define AO_CAN_FILTER_SID_1_19 (0)
#define AO_CAN_FILTER_SID_1_20 (0)
#define AO_CAN_FILTER_SID_1_21 (0)
#define AO_CAN_FILTER_SID_1_22 (0)
#define AO_CAN_FILTER_SID_1_23 (0)
#define AO_CAN_FILTER_SID_1_24 (0)
#define AO_CAN_FILTER_SID_1_25 (0)
#define AO_CAN_FILTER_SID_1_26 (0)
#define AO_CAN_FILTER_SID_1_27 (0)
#define AO_CAN_FILTER_SID_1_28 (0)
#define AO_CAN_FILTER_SID_1_29 (0)
#define AO_CAN_FILTER_SID_1_30 (0)
#define AO_CAN_FILTER_SID_1_31 (0)
```

Defines the SID for each filter.

## `AO_CAN_INVALID_1`

```c
#define AO_CAN_INVALID_1 (false)
```

Defines whether to notify the application of the reception or transmission of invalid messages.

## `AO_CAN_MODE_1`

```c
#define AO_CAN_MODE_1 (false)
```

Defines whether to notify the application of mode changes.

## `AO_CAN_OVERFLOW_1`

```c
#define AO_CAN_OVERFLOW_1 (false)
```

Defines whether to notify the application of receive buffer overflows.

## `AO_CAN_SENT_1`

```c
#define AO_CAN_SENT_1 (false)
```

Defines whether to notify the application, when messages have been sent.

## `AO_CAN_SYSTEM_1`

```c
#define AO_CAN_SYSTEM_1 (false)
```

Defines whether to notify the application of system errors.

## `AO_CAN_TIMER_1`

```c
#define AO_CAN_TIMER_1 (false)
```

Defines whether to notify the application of timestamp timer overflows.

## `AO_CAN_UNDERFLOW_1`

```c
#define AO_CAN_UNDERFLOW_1 (false)
```

Defines whether to notify the application of transmit buffer underflows.

## `AO_CAN_WAKE_UP_1`

```c
#define AO_CAN_WAKE_UP_1 (false)
```

Defines whether to notify the application of wake-up events.

# Constants

## `AO_CAN_BAUD_MAX_1`
## `AO_CAN_BAUD_MIN_1`

```c
#define AO_CAN_BAUD_MAX_1 AO_CAN_BAUD_MAX(AO_SYS_CLOCK_CAN1)
#define AO_CAN_BAUD_MIN_1 AO_CAN_BAUD_MIN(AO_SYS_CLOCK_CAN1)
```

The maximum and minimum baud rate.

## `AO_CAN_BUFFERS_1`

```c
#define AO_CAN_BUFFERS_1  \
(                         \
    AO_CAN_BUFFERS_1_0  + \
    AO_CAN_BUFFERS_1_1  + \
    AO_CAN_BUFFERS_1_2  + \
    AO_CAN_BUFFERS_1_3  + \
    AO_CAN_BUFFERS_1_4  + \
    AO_CAN_BUFFERS_1_5  + \
    AO_CAN_BUFFERS_1_6  + \
    AO_CAN_BUFFERS_1_7  + \
    AO_CAN_BUFFERS_1_8  + \
    AO_CAN_BUFFERS_1_9  + \
    AO_CAN_BUFFERS_1_10 + \
    AO_CAN_BUFFERS_1_11 + \
    AO_CAN_BUFFERS_1_12 + \
    AO_CAN_BUFFERS_1_13 + \
    AO_CAN_BUFFERS_1_14 + \
    AO_CAN_BUFFERS_1_15 + \
    AO_CAN_BUFFERS_1_16 + \
    AO_CAN_BUFFERS_1_17 + \
    AO_CAN_BUFFERS_1_18 + \
    AO_CAN_BUFFERS_1_19 + \
    AO_CAN_BUFFERS_1_20 + \
    AO_CAN_BUFFERS_1_21 + \
    AO_CAN_BUFFERS_1_22 + \
    AO_CAN_BUFFERS_1_23 + \
    AO_CAN_BUFFERS_1_24 + \
    AO_CAN_BUFFERS_1_25 + \
    AO_CAN_BUFFERS_1_26 + \
    AO_CAN_BUFFERS_1_27 + \
    AO_CAN_BUFFERS_1_28 + \
    AO_CAN_BUFFERS_1_29 + \
    AO_CAN_BUFFERS_1_30 + \
    AO_CAN_BUFFERS_1_31   \
)
```

The total number of buffers.

## `AO_CAN_FIFOS_1`

```c
#define AO_CAN_FIFOS_1    \
(                         \
    (AO_CAN_FIFOS_RX_1) + \
    (AO_CAN_FIFOS_TX_1)   \
)
```

The total number of FIFOs.

## `AO_CAN_RX_1`

```c
#define AO_CAN_RX_1         \
(                           \
    (AO_CAN_FIFOS_RX_1) > 0 \
    ? true                  \
    : false                 \
)
```

Indicates whether the module is configured to receive.

## `AO_CAN_TX_1`

```c
#define AO_CAN_TX_1         \
(                           \
    (AO_CAN_FIFOS_TX_1) > 0 \
    ? true                  \
    : false                 \
)
```

Indicates whether the module is configured to transmit.

# Functions

## `ao_can_bus_1`

```c
void ao_can_bus_1(ao_can_bus_t const * x);
```

Notifies the application of bus errors. This function is called every time there is a change in the current error state of the CAN module with respect to the CAN network. The error states are tracked by the C1TREC register.

## `ao_can_invalid_1`

```c
void ao_can_invalid_1();
```

Notifies the application, that an invalid message has been received or transmitted. However, the specific error is not available to the user application.

## `ao_can_listen_all_1`

```c
void ao_can_listen_all_1();
```

Sets the operation mode to listen all.

## `ao_can_listen_only_1`

```c
void ao_can_listen_only_1();
```

Sets the operation mode to listen only.

## `ao_can_loopback_1`

```c
void ao_can_loopback_1();
```

Sets the operation mode to loopback.

## `ao_can_mode_1`

```c
void ao_can_mode_1();
```

Notifies the application of a mode change.

## `ao_can_normal_1`

```c
void ao_can_normal_1();
```

Sets the operation mode to normal.

## `ao_can_overflow_1`

```c
void ao_can_overflow_1(uint32_t fifos);
```

| `fifos` | The bitmask indicating the affected FIFOs. |

Notifies the application of a receive buffer overflow. This function is called, when a message has been received, but the designated fifo is full.

## `ao_can_reg_1`

```c
#define ao_can_reg_1()     \
(                          \
    (ao_can_reg_t *)       \
    (                      \
        _CAN1_BASE_ADDRESS \
    )                      \
)
```

Gets the control registers.

## `ao_can_sent_1`

```c
void ao_can_sent_1(uint32_t fifos);
```

| `fifos` | The bitmask indicating the affected FIFOs. |

Notifies the application, that messages have been sent. This function is called, when all messages in a FIFO have been sent.

## `ao_can_start_1`
## `ao_can_stop_1`

```c
void ao_can_start_1();
void ao_can_stop_1();
```

Starts or stops the driver, respectively.

## `ao_can_system_1`

```c
void ao_can_system_1(ao_can_system_t x);
```

Notifies the application of a system error. This function is called due to two types of errors, addressing errors and bandwidth errors. Both of these errors are fatal. After the event was raised, the CAN module will be stopped and started over again.

An addressing error will occur, if the CAN module attempts to access a restricted memory location. Most likely, this results from

- an invalid FIFO base address, or
- an invalid configuration of the FIFO sizes in the C1FIFOCONi registers.

A bandwidth error will occur, when the CAN module is unable to write a received message to memory before the next message arrives. Most likely, this results from the CAN interrupt being delayed for a too long period of time.

## `ao_can_timer_1`

```c
void ao_can_timer_1();
```

Notifies the application of a timestamp timer overflow.

## `ao_can_underflow_1`

```c
void ao_can_underflow_1(uint32_t fifos);
```

| `fifos` | The bitmask indicating the affected FIFOs. |

Notifies the application of a transmit buffer underflow. This function is called, when a remote transmission request (RTR) has been received, but the designated FIFO to respond automatically is empty.

## `ao_can_wake_up_1`

```c
void ao_can_wake_up_1();
```

Notifies the application of a wake-up event. This function is called, when activity is detected on the CAN bus while the CAN module is in sleep mode.

# Variables

## `ao_can_in_1`

```c
extern ao_send_obj_t ao_can_in_1 [AO_CAN_FIFOS_RX_1];
```

The objects used to send inbound messages to the application.

## `ao_can_out_1`

```c
extern ao_recv_obj_t ao_can_out_1 [AO_CAN_FIFOS_TX_1];
```

The objects used to receive outbound messages from the application.

## `ao_can_task_1`

```c
extern ao_task_t ao_can_task_1;
```

The task.

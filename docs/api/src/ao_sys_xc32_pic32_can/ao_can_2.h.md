---
author: "Stefan Wagner"
date: 2022-08-29
draft: true
permalink: /api/src/ao_sys_xc32_pic32_can/ao_can_2.h/
toc: true
---

# Include

```c
#include <ao_can.h>
#include <ao_recv_obj.h>
#include <ao_send_obj.h>
#include <ao_task.h>
#include <stdbool.h>
#include <xc.h>
```

# Identifier

```c
#define AO_CAN_2
```

# Configuration

## `AO_CAN_BAUD_2`

```c
#define AO_CAN_BAUD_2 (100000)
```

The baud rate.

## `AO_CAN_BAUD_SAMPLE_2`

```c
#define AO_CAN_BAUD_SAMPLE_2 (85)
```

The sample point, in per cent.

## `AO_CAN_BAUD_SAMPLE_THRICE_2`

```c
#define AO_CAN_BAUD_SAMPLE_THRICE_2 (true)
```

Defines whether to sample each bit thrice.

## `AO_CAN_BAUD_SJW_2`

```c
#define AO_CAN_BAUD_SJW_2 (1)
```

The synchronization jump width.

## `AO_CAN_BAUD_WAKE_UP_FILTER_2`

```c
#define AO_CAN_BAUD_WAKE_UP_FILTER_2 (false)
```

## `AO_CAN_BUFFERS_2`

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

The number of buffers in each FIFO.

## `AO_CAN_BUS_2`

```c
#define AO_CAN_BUS_2 (false)
```

## `AO_CAN_FIFOS_RX_2`
## `AO_CAN_FIFOS_TX_2`

```c
#define AO_CAN_FIFOS_RX_2 (0)
#define AO_CAN_FIFOS_TX_2 (0)
```

The number of receive and transmit FIFOs.

## `AO_CAN_FILTER_EID_2`

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

## `AO_CAN_FILTER_ENABLE_2`

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

## `AO_CAN_FILTER_FIFO_2`

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

## `AO_CAN_FILTER_IDE_2`

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

## `AO_CAN_FILTER_MASK_2`

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

## `AO_CAN_FILTER_MASK_EID_2`

```c
#define AO_CAN_FILTER_MASK_EID_2_0 (0)
#define AO_CAN_FILTER_MASK_EID_2_1 (0)
#define AO_CAN_FILTER_MASK_EID_2_2 (0)
#define AO_CAN_FILTER_MASK_EID_2_3 (0)
```

## `AO_CAN_FILTER_MASK_IDE_2`

```c
#define AO_CAN_FILTER_MASK_IDE_2_0 (0)
#define AO_CAN_FILTER_MASK_IDE_2_1 (0)
#define AO_CAN_FILTER_MASK_IDE_2_2 (0)
#define AO_CAN_FILTER_MASK_IDE_2_3 (0)
```

## `AO_CAN_FILTER_MASK_SID_2`

```c
#define AO_CAN_FILTER_MASK_SID_2_0 (0)
#define AO_CAN_FILTER_MASK_SID_2_1 (0)
#define AO_CAN_FILTER_MASK_SID_2_2 (0)
#define AO_CAN_FILTER_MASK_SID_2_3 (0)
```

## `AO_CAN_FILTER_SID_2`

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

## `AO_CAN_INVALID_2`

```c
#define AO_CAN_INVALID_2 (false)
```

## `AO_CAN_MODE_2`

```c
#define AO_CAN_MODE_2 (false)
```

## `AO_CAN_OVERFLOW_2`

```c
#define AO_CAN_OVERFLOW_2 (false)
```

## `AO_CAN_SENT_2`

```c
#define AO_CAN_SENT_2 (false)
```

## `AO_CAN_SYSTEM_2`

```c
#define AO_CAN_SYSTEM_2 (false)
```

## `AO_CAN_TIMER_2`

```c
#define AO_CAN_TIMER_2 (false)
```

## `AO_CAN_UNDERFLOW_2`

```c
#define AO_CAN_UNDERFLOW_2 (false)
```

## `AO_CAN_WAKE_UP_2`

```c
#define AO_CAN_WAKE_UP_2 (false)
```

# Constants

## `AO_CAN_2`

```c
#define AO_CAN_2
```

Indicates whether the CAN module is available.

## `AO_CAN_BAUD_MAX_2`
## `AO_CAN_BAUD_MIN_2`

```c
#define AO_CAN_BAUD_MAX_2
#define AO_CAN_BAUD_MIN_2
```

The maximum and minimum baud rate.

## `AO_CAN_BUFFERS_2`

```c
#define AO_CAN_BUFFERS_2
```

The total number of buffers.

## `AO_CAN_FIFOS_2`

```c
#define AO_CAN_FIFOS_2
```

The total number of FIFOs.

## `AO_CAN_RX_2`

```c
#define AO_CAN_RX_2
```

Indicates whether the module is configured to receive.

## `AO_CAN_TX_2`

```c
#define AO_CAN_TX_2
```

Indicates whether the module is configured to transmit.

# Functions

## `ao_can_bus_2`

```c
void ao_can_bus_2(ao_can_bus_info_t const * info);
```

## `ao_can_config_2`

```c
void ao_can_config_2();
```

## `ao_can_config_baud_2`

```c
void ao_can_config_baud_2();
```

## `ao_can_config_fifos_2`

```c
void ao_can_config_fifos_2();
```

## `ao_can_config_filter_masks_2`

```c
void ao_can_config_filter_masks_2();
```

## `ao_can_config_filters_2`

```c
void ao_can_config_filters_2();
```

## `ao_can_invalid_2`

```c
void ao_can_invalid_2(ao_can_invalid_info_t const * info);
```

## `ao_can_listen_all_2`

```c
void ao_can_listen_all_2();
```

## `ao_can_listen_only_2`

```c
void ao_can_listen_only_2();
```

## `ao_can_loopback_2`

```c
void ao_can_loopback_2();
```

## `ao_can_mode_2`

```c
void ao_can_mode_2(ao_can_mode_info_t const * info);
```

## `ao_can_normal_2`

```c
void ao_can_normal_2();
```

## `ao_can_overflow_2`

```c
void ao_can_overflow_2(ao_can_overflow_info_t const * info);
```

## `ao_can_reg_2`

```c
#define ao_can_reg_2()                    \
(                                         \
    (ao_can_reg_t *) (_CAN2_BASE_ADDRESS) \
)
```

## `ao_can_sent_2`

```c
void ao_can_sent_2(ao_can_sent_info_t const * info);
```

## `ao_can_start_2`

```c
void ao_can_start_2();
```

## `ao_can_stop_2`

```c
void ao_can_stop_2();
```

## `ao_can_system_2`

```c
void ao_can_system_2(ao_can_system_info_t const * info);
```

## `ao_can_timer_2`

```c
void ao_can_timer_2(ao_can_timer_info_t const * info);
```

## `ao_can_underflow_2`

```c
void ao_can_underflow_2(ao_can_underflow_info_t const * info);
```

## `ao_can_wake_up_2`

```c
void ao_can_wake_up_2(ao_can_wake_up_info_t const * info);
```

# Variables

## `ao_can_buffers_2`

```c
extern ao_can_t ao_can_buffers_2 [AO_CAN_BUFFERS_2];
```

## `ao_can_in_2`

```c
extern ao_send_obj_t ao_can_in_2 [AO_CAN_FIFOS_RX_2];
```

## `ao_can_out_2`

```c
extern ao_recv_obj_t ao_can_out_2 [AO_CAN_FIFOS_TX_2];
```

## `ao_can_task_2`

```c
extern ao_task_t ao_can_task_2;
```

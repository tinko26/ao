---
author: "Stefan Wagner"
date: 2022-08-29
draft: true
permalink: /api/src/ao_sys_xc32_pic32_can/ao_can_4.h/
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
#define AO_CAN_4
```

# Configuration

## `AO_CAN_BAUD_4`

```c
#define AO_CAN_BAUD_4 (100000)
```

The baud rate.

## `AO_CAN_BAUD_SAMPLE_4`

```c
#define AO_CAN_BAUD_SAMPLE_4 (85)
```

The sample point, in per cent.

## `AO_CAN_BAUD_SAMPLE_THRICE_4`

```c
#define AO_CAN_BAUD_SAMPLE_THRICE_4 (true)
```

Defines whether to sample each bit thrice.

## `AO_CAN_BAUD_SJW_4`

```c
#define AO_CAN_BAUD_SJW_4 (1)
```

The synchronization jump width.

## `AO_CAN_BAUD_WAKE_UP_FILTER_4`

```c
#define AO_CAN_BAUD_WAKE_UP_FILTER_4 (false)
```

## `AO_CAN_BUFFERS_4`

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

The number of buffers in each FIFO.

## `AO_CAN_BUS_4`

```c
#define AO_CAN_BUS_4 (false)
```

## `AO_CAN_FIFOS_RX_4`
## `AO_CAN_FIFOS_TX_4`

```c
#define AO_CAN_FIFOS_RX_4 (0)
#define AO_CAN_FIFOS_TX_4 (0)
```

The number of receive and transmit FIFOs.

## `AO_CAN_FILTER_EID_4`

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

## `AO_CAN_FILTER_ENABLE_4`

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

## `AO_CAN_FILTER_FIFO_4`

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

## `AO_CAN_FILTER_IDE_4`

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

## `AO_CAN_FILTER_MASK_4`

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

## `AO_CAN_FILTER_MASK_EID_4`

```c
#define AO_CAN_FILTER_MASK_EID_4_0 (0)
#define AO_CAN_FILTER_MASK_EID_4_1 (0)
#define AO_CAN_FILTER_MASK_EID_4_2 (0)
#define AO_CAN_FILTER_MASK_EID_4_3 (0)
```

## `AO_CAN_FILTER_MASK_IDE_4`

```c
#define AO_CAN_FILTER_MASK_IDE_4_0 (0)
#define AO_CAN_FILTER_MASK_IDE_4_1 (0)
#define AO_CAN_FILTER_MASK_IDE_4_2 (0)
#define AO_CAN_FILTER_MASK_IDE_4_3 (0)
```

## `AO_CAN_FILTER_MASK_SID_4`

```c
#define AO_CAN_FILTER_MASK_SID_4_0 (0)
#define AO_CAN_FILTER_MASK_SID_4_1 (0)
#define AO_CAN_FILTER_MASK_SID_4_2 (0)
#define AO_CAN_FILTER_MASK_SID_4_3 (0)
```

## `AO_CAN_FILTER_SID_4`

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

## `AO_CAN_INVALID_4`

```c
#define AO_CAN_INVALID_4 (false)
```

## `AO_CAN_MODE_4`

```c
#define AO_CAN_MODE_4 (false)
```

## `AO_CAN_OVERFLOW_4`

```c
#define AO_CAN_OVERFLOW_4 (false)
```

## `AO_CAN_SENT_4`

```c
#define AO_CAN_SENT_4 (false)
```

## `AO_CAN_SYSTEM_4`

```c
#define AO_CAN_SYSTEM_4 (false)
```

## `AO_CAN_TIMER_4`

```c
#define AO_CAN_TIMER_4 (false)
```

## `AO_CAN_UNDERFLOW_4`

```c
#define AO_CAN_UNDERFLOW_4 (false)
```

## `AO_CAN_WAKE_UP_4`

```c
#define AO_CAN_WAKE_UP_4 (false)
```

# Constants

## `AO_CAN_4`

```c
#define AO_CAN_4
```

Indicates whether the CAN module is available.

## `AO_CAN_BAUD_MAX_4`
## `AO_CAN_BAUD_MIN_4`

```c
#define AO_CAN_BAUD_MAX_4
#define AO_CAN_BAUD_MIN_4
```

The maximum and minimum baud rate.

## `AO_CAN_BUFFERS_4`

```c
#define AO_CAN_BUFFERS_4
```

The total number of buffers.

## `AO_CAN_FIFOS_4`

```c
#define AO_CAN_FIFOS_4
```

The total number of FIFOs.

## `AO_CAN_RX_4`

```c
#define AO_CAN_RX_4
```

Indicates whether the module is configured to receive.

## `AO_CAN_TX_4`

```c
#define AO_CAN_TX_4
```

Indicates whether the module is configured to transmit.

# Functions

## `ao_can_bus_4`

```c
void ao_can_bus_4(ao_can_bus_info_t const * info);
```

## `ao_can_config_4`

```c
void ao_can_config_4();
```

## `ao_can_config_baud_4`

```c
void ao_can_config_baud_4();
```

## `ao_can_config_fifos_4`

```c
void ao_can_config_fifos_4();
```

## `ao_can_config_filter_masks_4`

```c
void ao_can_config_filter_masks_4();
```

## `ao_can_config_filters_4`

```c
void ao_can_config_filters_4();
```

## `ao_can_invalid_4`

```c
void ao_can_invalid_4(ao_can_invalid_info_t const * info);
```

## `ao_can_listen_all_4`

```c
void ao_can_listen_all_4();
```

## `ao_can_listen_only_4`

```c
void ao_can_listen_only_4();
```

## `ao_can_loopback_4`

```c
void ao_can_loopback_4();
```

## `ao_can_mode_4`

```c
void ao_can_mode_4(ao_can_mode_info_t const * info);
```

## `ao_can_normal_4`

```c
void ao_can_normal_4();
```

## `ao_can_overflow_4`

```c
void ao_can_overflow_4(ao_can_overflow_info_t const * info);
```

## `ao_can_reg_4`

```c
#define ao_can_reg_4()
```

## `ao_can_sent_4`

```c
void ao_can_sent_4(ao_can_sent_info_t const * info);
```

## `ao_can_start_4`

```c
void ao_can_start_4();
```

## `ao_can_stop_4`

```c
void ao_can_stop_4();
```

## `ao_can_system_4`

```c
void ao_can_system_4(ao_can_system_info_t const * info);
```

## `ao_can_timer_4`

```c
void ao_can_timer_4(ao_can_timer_info_t const * info);
```

## `ao_can_underflow_4`

```c
void ao_can_underflow_4(ao_can_underflow_info_t const * info);
```

## `ao_can_wake_up_4`

```c
void ao_can_wake_up_4(ao_can_wake_up_info_t const * info);
```

# Variables

## `ao_can_buffers_4`

```c
extern ao_can_t ao_can_buffers_4 [AO_CAN_BUFFERS_4];
```

## `ao_can_in_4`

```c
extern ao_send_obj_t ao_can_in_4 [AO_CAN_FIFOS_RX_4];
```

## `ao_can_out_4`

```c
extern ao_recv_obj_t ao_can_out_4 [AO_CAN_FIFOS_TX_4];
```

## `ao_can_task_4`

```c
extern ao_task_t ao_can_task_4;
```

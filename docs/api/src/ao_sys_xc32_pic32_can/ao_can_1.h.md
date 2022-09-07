---
author: "Stefan Wagner"
date: 2022-08-29
draft: true
permalink: /api/src/ao_sys_xc32_pic32_can/ao_can_1.h/
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

# Constants

## AO_CAN_1

Indicates whether the CAN module is available.

```c
#ifndef AO_CAN_1
#ifdef  _CAN1

#define AO_CAN_1 (true)

#else

#define AO_CAN_1 (false)

#endif
#endif
```

## AO_CAN_BAUD_MAX_1
## AO_CAN_BAUD_MIN_1

The maximum and minimum baud rate.

```c
#define AO_CAN_BAUD_MAX_1 AO_CAN_BAUD_MAX(AO_SYS_CLOCK_CAN1)
#define AO_CAN_BAUD_MIN_1 AO_CAN_BAUD_MIN(AO_SYS_CLOCK_CAN1)
```

## AO_CAN_BUFFERS_1

The total number of buffers.

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

## AO_CAN_FIFOS_1

The total number of FIFOs.

```c
#define AO_CAN_FIFOS_1 ((AO_CAN_FIFOS_RX_1) + (AO_CAN_FIFOS_TX_1))
```

## AO_CAN_RX_1
## AO_CAN_TX_1

```c
#define AO_CAN_RX_1 ((AO_CAN_FIFOS_RX_1) > 0 ? true : false)
#define AO_CAN_TX_1 ((AO_CAN_FIFOS_TX_1) > 0 ? true : false)
```

# Configuration

## AO_CAN_BAUD_1

```c
#define AO_CAN_BAUD_1 (100000)
```

```c
#define AO_CAN_BAUD_SAMPLE_1 (85)
```

```c
#define AO_CAN_BAUD_SAMPLE_THRICE_1 (true)
```

```c
#define AO_CAN_BAUD_SJW_1 (1)
```

```c
#define AO_CAN_BAUD_WAKE_UP_FILTER_1 (false)
```

## AO_CAN_BUFFERS_1

The number of buffers in each FIFO.

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

## AO_CAN_BUS_1

```c
#define AO_CAN_BUS_1 (false)
```

## AO_CAN_FIFOS_RX_1
## AO_CAN_FIFOS_TX_1

The number of receive and transmit FIFOs.

```c
#define AO_CAN_FIFOS_RX_1 (0)
#define AO_CAN_FIFOS_TX_1 (0)
```

## AO_CAN_FILTER_EID_1

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

## AO_CAN_FILTER_ENABLE_1

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

## AO_CAN_FILTER_FIFO_1

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

## AO_CAN_FILTER_IDE_1

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

## AO_CAN_FILTER_MASK_1

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

## AO_CAN_FILTER_MASK_EID_1

```c
#define AO_CAN_FILTER_MASK_EID_1_0 (0)
#define AO_CAN_FILTER_MASK_EID_1_1 (0)
#define AO_CAN_FILTER_MASK_EID_1_2 (0)
#define AO_CAN_FILTER_MASK_EID_1_3 (0)
```

## AO_CAN_FILTER_MASK_IDE_1

```c
#define AO_CAN_FILTER_MASK_IDE_1_0 (0)
#define AO_CAN_FILTER_MASK_IDE_1_1 (0)
#define AO_CAN_FILTER_MASK_IDE_1_2 (0)
#define AO_CAN_FILTER_MASK_IDE_1_3 (0)
```

## AO_CAN_FILTER_MASK_SID_1

```c
#define AO_CAN_FILTER_MASK_SID_1_0 (0)
#define AO_CAN_FILTER_MASK_SID_1_1 (0)
#define AO_CAN_FILTER_MASK_SID_1_2 (0)
#define AO_CAN_FILTER_MASK_SID_1_3 (0)
```

## AO_CAN_FILTER_SID_1

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

## AO_CAN_INVALID_1

```c
#define AO_CAN_INVALID_1 (false)
```

## AO_CAN_MODE_1

```c
#define AO_CAN_MODE_1 (false)
```

## AO_CAN_OVERFLOW_1

```c
#define AO_CAN_OVERFLOW_1 (false)
```

## AO_CAN_SENT_1

```c
#define AO_CAN_SENT_1 (false)
```

## AO_CAN_SYSTEM_1

```c
#define AO_CAN_SYSTEM_1 (false)
```

## AO_CAN_TIMER_1

```c
#define AO_CAN_TIMER_1 (false)
```

## AO_CAN_UNDERFLOW_1

```c
#define AO_CAN_UNDERFLOW_1 (false)
```

## AO_CAN_WAKE_UP_1

```c
#define AO_CAN_WAKE_UP_1 (false)
```

# Functions

```c
#define ao_can_reg_1()
```

```c
void ao_can_bus_1(ao_can_bus_info_t const * info);
```

```c
void ao_can_config_1();
```

```c
void ao_can_config_baud_1();
```

```c
void ao_can_config_fifos_1();
```

```c
void ao_can_config_filter_masks_1();
```

```c
void ao_can_config_filters_1();
```

```c
void ao_can_invalid_1(ao_can_invalid_info_t const * info);
```

```c
void ao_can_listen_all_1();
```

```c
void ao_can_listen_only_1();
```

```c
void ao_can_loopback_1();
```

```c
void ao_can_mode_1(ao_can_mode_info_t const * info);
```

```c
void ao_can_normal_1();
```

```c
void ao_can_overflow_1(ao_can_overflow_info_t const * info);
```

```c
void ao_can_sent_1(ao_can_sent_info_t const * info);
```

```c
void ao_can_start_1();
```

```c
void ao_can_stop_1();
```

```c
void ao_can_system_1(ao_can_system_info_t const * info);
```

```c
void ao_can_timer_1(ao_can_timer_info_t const * info);
```

```c
void ao_can_underflow_1(ao_can_underflow_info_t const * info);
```

```c
void ao_can_wake_up_1(ao_can_wake_up_info_t const * info);
```

# Variables

```c
extern ao_can_t      ao_can_buffers_1[AO_CAN_BUFFERS_1];
```

```c
extern ao_send_obj_t ao_can_in_1     [AO_CAN_FIFOS_RX_1];
```

```c
extern ao_recv_obj_t ao_can_out_1    [AO_CAN_FIFOS_TX_1];
```

```c
extern ao_task_t     ao_can_task_1;
```

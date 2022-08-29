---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The ao_sys_xc32_pic32_can/ao_can_1.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys_xc32_pic32_can/ao_can_1.h/ 
subtitle: ""
title: "ao_can_1.h"
toc: true
---

```c
#include <ao_can.h>
#include <ao_recv_obj.h>
#include <ao_send_obj.h>
#include <ao_task.h>
#include <stdbool.h>
#include <xc.h>

#ifndef AO_CAN_1

#ifdef  _CAN1

#define AO_CAN_1                        (true)

#else

#define AO_CAN_1                        (false)

#endif

#endif

#ifndef AO_CAN_BAUD_1

#define AO_CAN_BAUD_1                   (100000)

#endif

#ifndef AO_CAN_BAUD_SAMPLE_1

#define AO_CAN_BAUD_SAMPLE_1            (85)

#endif

#ifndef AO_CAN_BAUD_SAMPLE_THRICE_1

#define AO_CAN_BAUD_SAMPLE_THRICE_1     (true)

#endif

#ifndef AO_CAN_BAUD_SJW_1

#define AO_CAN_BAUD_SJW_1               (1)

#endif

#ifndef AO_CAN_BAUD_WAKE_UP_FILTER_1

#define AO_CAN_BAUD_WAKE_UP_FILTER_1    (false)

#endif

#ifndef AO_CAN_BAUD_MAX_1

#define AO_CAN_BAUD_MAX_1               AO_CAN_BAUD_MAX(AO_SYS_CLOCK_CAN1)

#endif

#ifndef AO_CAN_BAUD_MIN_1

#define AO_CAN_BAUD_MIN_1               AO_CAN_BAUD_MIN(AO_SYS_CLOCK_CAN1)

#endif

#ifndef AO_CAN_BUFFERS_1_0

#define AO_CAN_BUFFERS_1_0              (0)

#endif

#ifndef AO_CAN_BUFFERS_1_1

#define AO_CAN_BUFFERS_1_1              (0)

#endif

#ifndef AO_CAN_BUFFERS_1_2

#define AO_CAN_BUFFERS_1_2              (0)

#endif

#ifndef AO_CAN_BUFFERS_1_3

#define AO_CAN_BUFFERS_1_3              (0)

#endif

#ifndef AO_CAN_BUFFERS_1_4

#define AO_CAN_BUFFERS_1_4              (0)

#endif

#ifndef AO_CAN_BUFFERS_1_5

#define AO_CAN_BUFFERS_1_5              (0)

#endif

#ifndef AO_CAN_BUFFERS_1_6

#define AO_CAN_BUFFERS_1_6              (0)

#endif

#ifndef AO_CAN_BUFFERS_1_7

#define AO_CAN_BUFFERS_1_7              (0)

#endif

#ifndef AO_CAN_BUFFERS_1_8

#define AO_CAN_BUFFERS_1_8              (0)

#endif

#ifndef AO_CAN_BUFFERS_1_9

#define AO_CAN_BUFFERS_1_9              (0)

#endif

#ifndef AO_CAN_BUFFERS_1_10

#define AO_CAN_BUFFERS_1_10             (0)

#endif

#ifndef AO_CAN_BUFFERS_1_11

#define AO_CAN_BUFFERS_1_11             (0)

#endif

#ifndef AO_CAN_BUFFERS_1_12

#define AO_CAN_BUFFERS_1_12             (0)

#endif

#ifndef AO_CAN_BUFFERS_1_13

#define AO_CAN_BUFFERS_1_13             (0)

#endif

#ifndef AO_CAN_BUFFERS_1_14

#define AO_CAN_BUFFERS_1_14             (0)

#endif

#ifndef AO_CAN_BUFFERS_1_15

#define AO_CAN_BUFFERS_1_15             (0)

#endif

#ifndef AO_CAN_BUFFERS_1_16

#define AO_CAN_BUFFERS_1_16             (0)

#endif

#ifndef AO_CAN_BUFFERS_1_17

#define AO_CAN_BUFFERS_1_17             (0)

#endif

#ifndef AO_CAN_BUFFERS_1_18

#define AO_CAN_BUFFERS_1_18             (0)

#endif

#ifndef AO_CAN_BUFFERS_1_19

#define AO_CAN_BUFFERS_1_19             (0)

#endif

#ifndef AO_CAN_BUFFERS_1_20

#define AO_CAN_BUFFERS_1_20             (0)

#endif

#ifndef AO_CAN_BUFFERS_1_21

#define AO_CAN_BUFFERS_1_21             (0)

#endif

#ifndef AO_CAN_BUFFERS_1_22

#define AO_CAN_BUFFERS_1_22             (0)

#endif

#ifndef AO_CAN_BUFFERS_1_23

#define AO_CAN_BUFFERS_1_23             (0)

#endif

#ifndef AO_CAN_BUFFERS_1_24

#define AO_CAN_BUFFERS_1_24             (0)

#endif

#ifndef AO_CAN_BUFFERS_1_25

#define AO_CAN_BUFFERS_1_25             (0)

#endif

#ifndef AO_CAN_BUFFERS_1_26

#define AO_CAN_BUFFERS_1_26             (0)

#endif

#ifndef AO_CAN_BUFFERS_1_27

#define AO_CAN_BUFFERS_1_27             (0)

#endif

#ifndef AO_CAN_BUFFERS_1_28

#define AO_CAN_BUFFERS_1_28             (0)

#endif

#ifndef AO_CAN_BUFFERS_1_29

#define AO_CAN_BUFFERS_1_29             (0)

#endif

#ifndef AO_CAN_BUFFERS_1_30

#define AO_CAN_BUFFERS_1_30             (0)

#endif

#ifndef AO_CAN_BUFFERS_1_31

#define AO_CAN_BUFFERS_1_31             (0)

#endif

#ifndef AO_CAN_BUFFERS_1

#define AO_CAN_BUFFERS_1                                                    \
(                                                                           \
        AO_CAN_BUFFERS_1_0  +                                               \
        AO_CAN_BUFFERS_1_1  +                                               \
        AO_CAN_BUFFERS_1_2  +                                               \
        AO_CAN_BUFFERS_1_3  +                                               \
        AO_CAN_BUFFERS_1_4  +                                               \
        AO_CAN_BUFFERS_1_5  +                                               \
        AO_CAN_BUFFERS_1_6  +                                               \
        AO_CAN_BUFFERS_1_7  +                                               \
        AO_CAN_BUFFERS_1_8  +                                               \
        AO_CAN_BUFFERS_1_9  +                                               \
        AO_CAN_BUFFERS_1_10 +                                               \
        AO_CAN_BUFFERS_1_11 +                                               \
        AO_CAN_BUFFERS_1_12 +                                               \
        AO_CAN_BUFFERS_1_13 +                                               \
        AO_CAN_BUFFERS_1_14 +                                               \
        AO_CAN_BUFFERS_1_15 +                                               \
        AO_CAN_BUFFERS_1_16 +                                               \
        AO_CAN_BUFFERS_1_17 +                                               \
        AO_CAN_BUFFERS_1_18 +                                               \
        AO_CAN_BUFFERS_1_19 +                                               \
        AO_CAN_BUFFERS_1_20 +                                               \
        AO_CAN_BUFFERS_1_21 +                                               \
        AO_CAN_BUFFERS_1_22 +                                               \
        AO_CAN_BUFFERS_1_23 +                                               \
        AO_CAN_BUFFERS_1_24 +                                               \
        AO_CAN_BUFFERS_1_25 +                                               \
        AO_CAN_BUFFERS_1_26 +                                               \
        AO_CAN_BUFFERS_1_27 +                                               \
        AO_CAN_BUFFERS_1_28 +                                               \
        AO_CAN_BUFFERS_1_29 +                                               \
        AO_CAN_BUFFERS_1_30 +                                               \
        AO_CAN_BUFFERS_1_31                                                 \
)

#endif

#ifndef AO_CAN_BUS_1

#define AO_CAN_BUS_1                    (false)

#endif

#ifndef AO_CAN_FIFOS_RX_1

#define AO_CAN_FIFOS_RX_1               (0)

#endif

#ifndef AO_CAN_FIFOS_TX_1

#define AO_CAN_FIFOS_TX_1               (0)

#endif

#ifndef AO_CAN_FIFOS_1

#define AO_CAN_FIFOS_1                  ((AO_CAN_FIFOS_RX_1) + (AO_CAN_FIFOS_TX_1))

#endif

#ifndef AO_CAN_FILTER_EID_1_0

#define AO_CAN_FILTER_EID_1_0           (0)

#endif

#ifndef AO_CAN_FILTER_ENABLE_1_0

#define AO_CAN_FILTER_ENABLE_1_0        (false)

#endif

#ifndef AO_CAN_FILTER_FIFO_1_0

#define AO_CAN_FILTER_FIFO_1_0          (0)

#endif

#ifndef AO_CAN_FILTER_IDE_1_0

#define AO_CAN_FILTER_IDE_1_0           (0)

#endif

#ifndef AO_CAN_FILTER_MASK_1_0

#define AO_CAN_FILTER_MASK_1_0          (0)

#endif

#ifndef AO_CAN_FILTER_SID_1_0

#define AO_CAN_FILTER_SID_1_0           (0)

#endif

#ifndef AO_CAN_FILTER_EID_1_1

#define AO_CAN_FILTER_EID_1_1           (0)

#endif

#ifndef AO_CAN_FILTER_ENABLE_1_1

#define AO_CAN_FILTER_ENABLE_1_1        (false)

#endif

#ifndef AO_CAN_FILTER_FIFO_1_1

#define AO_CAN_FILTER_FIFO_1_1          (0)

#endif

#ifndef AO_CAN_FILTER_IDE_1_1

#define AO_CAN_FILTER_IDE_1_1           (0)

#endif

#ifndef AO_CAN_FILTER_MASK_1_1

#define AO_CAN_FILTER_MASK_1_1          (0)

#endif

#ifndef AO_CAN_FILTER_SID_1_1

#define AO_CAN_FILTER_SID_1_1           (0)

#endif

#ifndef AO_CAN_FILTER_EID_1_2

#define AO_CAN_FILTER_EID_1_2           (0)

#endif

#ifndef AO_CAN_FILTER_ENABLE_1_2

#define AO_CAN_FILTER_ENABLE_1_2        (false)

#endif

#ifndef AO_CAN_FILTER_FIFO_1_2

#define AO_CAN_FILTER_FIFO_1_2          (0)

#endif

#ifndef AO_CAN_FILTER_IDE_1_2

#define AO_CAN_FILTER_IDE_1_2           (0)

#endif

#ifndef AO_CAN_FILTER_MASK_1_2

#define AO_CAN_FILTER_MASK_1_2          (0)

#endif

#ifndef AO_CAN_FILTER_SID_1_2

#define AO_CAN_FILTER_SID_1_2           (0)

#endif

#ifndef AO_CAN_FILTER_EID_1_3

#define AO_CAN_FILTER_EID_1_3           (0)

#endif

#ifndef AO_CAN_FILTER_ENABLE_1_3

#define AO_CAN_FILTER_ENABLE_1_3        (false)

#endif

#ifndef AO_CAN_FILTER_FIFO_1_3

#define AO_CAN_FILTER_FIFO_1_3          (0)

#endif

#ifndef AO_CAN_FILTER_IDE_1_3

#define AO_CAN_FILTER_IDE_1_3           (0)

#endif

#ifndef AO_CAN_FILTER_MASK_1_3

#define AO_CAN_FILTER_MASK_1_3          (0)

#endif

#ifndef AO_CAN_FILTER_SID_1_3

#define AO_CAN_FILTER_SID_1_3           (0)

#endif

#ifndef AO_CAN_FILTER_EID_1_4

#define AO_CAN_FILTER_EID_1_4           (0)

#endif

#ifndef AO_CAN_FILTER_ENABLE_1_4

#define AO_CAN_FILTER_ENABLE_1_4        (false)

#endif

#ifndef AO_CAN_FILTER_FIFO_1_4

#define AO_CAN_FILTER_FIFO_1_4          (0)

#endif

#ifndef AO_CAN_FILTER_IDE_1_4

#define AO_CAN_FILTER_IDE_1_4           (0)

#endif

#ifndef AO_CAN_FILTER_MASK_1_4

#define AO_CAN_FILTER_MASK_1_4          (0)

#endif

#ifndef AO_CAN_FILTER_SID_1_4

#define AO_CAN_FILTER_SID_1_4           (0)

#endif

#ifndef AO_CAN_FILTER_EID_1_5

#define AO_CAN_FILTER_EID_1_5           (0)

#endif

#ifndef AO_CAN_FILTER_ENABLE_1_5

#define AO_CAN_FILTER_ENABLE_1_5        (false)

#endif

#ifndef AO_CAN_FILTER_FIFO_1_5

#define AO_CAN_FILTER_FIFO_1_5          (0)

#endif

#ifndef AO_CAN_FILTER_IDE_1_5

#define AO_CAN_FILTER_IDE_1_5           (0)

#endif

#ifndef AO_CAN_FILTER_MASK_1_5

#define AO_CAN_FILTER_MASK_1_5          (0)

#endif

#ifndef AO_CAN_FILTER_SID_1_5

#define AO_CAN_FILTER_SID_1_5           (0)

#endif

#ifndef AO_CAN_FILTER_EID_1_6

#define AO_CAN_FILTER_EID_1_6           (0)

#endif

#ifndef AO_CAN_FILTER_ENABLE_1_6

#define AO_CAN_FILTER_ENABLE_1_6        (false)

#endif

#ifndef AO_CAN_FILTER_FIFO_1_6

#define AO_CAN_FILTER_FIFO_1_6          (0)

#endif

#ifndef AO_CAN_FILTER_IDE_1_6

#define AO_CAN_FILTER_IDE_1_6           (0)

#endif

#ifndef AO_CAN_FILTER_MASK_1_6

#define AO_CAN_FILTER_MASK_1_6          (0)

#endif

#ifndef AO_CAN_FILTER_SID_1_6

#define AO_CAN_FILTER_SID_1_6           (0)

#endif

#ifndef AO_CAN_FILTER_EID_1_7

#define AO_CAN_FILTER_EID_1_7           (0)

#endif

#ifndef AO_CAN_FILTER_ENABLE_1_7

#define AO_CAN_FILTER_ENABLE_1_7        (false)

#endif

#ifndef AO_CAN_FILTER_FIFO_1_7

#define AO_CAN_FILTER_FIFO_1_7          (0)

#endif

#ifndef AO_CAN_FILTER_IDE_1_7

#define AO_CAN_FILTER_IDE_1_7           (0)

#endif

#ifndef AO_CAN_FILTER_MASK_1_7

#define AO_CAN_FILTER_MASK_1_7          (0)

#endif

#ifndef AO_CAN_FILTER_SID_1_7

#define AO_CAN_FILTER_SID_1_7           (0)

#endif

#ifndef AO_CAN_FILTER_EID_1_8

#define AO_CAN_FILTER_EID_1_8           (0)

#endif

#ifndef AO_CAN_FILTER_ENABLE_1_8

#define AO_CAN_FILTER_ENABLE_1_8        (false)

#endif

#ifndef AO_CAN_FILTER_FIFO_1_8

#define AO_CAN_FILTER_FIFO_1_8          (0)

#endif

#ifndef AO_CAN_FILTER_IDE_1_8

#define AO_CAN_FILTER_IDE_1_8           (0)

#endif

#ifndef AO_CAN_FILTER_MASK_1_8

#define AO_CAN_FILTER_MASK_1_8          (0)

#endif

#ifndef AO_CAN_FILTER_SID_1_8

#define AO_CAN_FILTER_SID_1_8           (0)

#endif

#ifndef AO_CAN_FILTER_EID_1_9

#define AO_CAN_FILTER_EID_1_9           (0)

#endif

#ifndef AO_CAN_FILTER_ENABLE_1_9

#define AO_CAN_FILTER_ENABLE_1_9        (false)

#endif

#ifndef AO_CAN_FILTER_FIFO_1_9

#define AO_CAN_FILTER_FIFO_1_9          (0)

#endif

#ifndef AO_CAN_FILTER_IDE_1_9

#define AO_CAN_FILTER_IDE_1_9           (0)

#endif

#ifndef AO_CAN_FILTER_MASK_1_9

#define AO_CAN_FILTER_MASK_1_9          (0)

#endif

#ifndef AO_CAN_FILTER_SID_1_9

#define AO_CAN_FILTER_SID_1_9           (0)

#endif

#ifndef AO_CAN_FILTER_EID_1_10

#define AO_CAN_FILTER_EID_1_10          (0)

#endif

#ifndef AO_CAN_FILTER_ENABLE_1_10

#define AO_CAN_FILTER_ENABLE_1_10       (false)

#endif

#ifndef AO_CAN_FILTER_FIFO_1_10

#define AO_CAN_FILTER_FIFO_1_10         (0)

#endif

#ifndef AO_CAN_FILTER_IDE_1_10

#define AO_CAN_FILTER_IDE_1_10          (0)

#endif

#ifndef AO_CAN_FILTER_MASK_1_10

#define AO_CAN_FILTER_MASK_1_10         (0)

#endif

#ifndef AO_CAN_FILTER_SID_1_10

#define AO_CAN_FILTER_SID_1_10          (0)

#endif

#ifndef AO_CAN_FILTER_EID_1_11

#define AO_CAN_FILTER_EID_1_11          (0)

#endif

#ifndef AO_CAN_FILTER_ENABLE_1_11

#define AO_CAN_FILTER_ENABLE_1_11       (false)

#endif

#ifndef AO_CAN_FILTER_FIFO_1_11

#define AO_CAN_FILTER_FIFO_1_11         (0)

#endif

#ifndef AO_CAN_FILTER_IDE_1_11

#define AO_CAN_FILTER_IDE_1_11          (0)

#endif

#ifndef AO_CAN_FILTER_MASK_1_11

#define AO_CAN_FILTER_MASK_1_11         (0)

#endif

#ifndef AO_CAN_FILTER_SID_1_11

#define AO_CAN_FILTER_SID_1_11          (0)

#endif

#ifndef AO_CAN_FILTER_EID_1_12

#define AO_CAN_FILTER_EID_1_12          (0)

#endif

#ifndef AO_CAN_FILTER_ENABLE_1_12

#define AO_CAN_FILTER_ENABLE_1_12       (false)

#endif

#ifndef AO_CAN_FILTER_FIFO_1_12

#define AO_CAN_FILTER_FIFO_1_12         (0)

#endif

#ifndef AO_CAN_FILTER_IDE_1_12

#define AO_CAN_FILTER_IDE_1_12          (0)

#endif

#ifndef AO_CAN_FILTER_MASK_1_12

#define AO_CAN_FILTER_MASK_1_12         (0)

#endif

#ifndef AO_CAN_FILTER_SID_1_12

#define AO_CAN_FILTER_SID_1_12          (0)

#endif

#ifndef AO_CAN_FILTER_EID_1_13

#define AO_CAN_FILTER_EID_1_13          (0)

#endif

#ifndef AO_CAN_FILTER_ENABLE_1_13

#define AO_CAN_FILTER_ENABLE_1_13       (false)

#endif

#ifndef AO_CAN_FILTER_FIFO_1_13

#define AO_CAN_FILTER_FIFO_1_13         (0)

#endif

#ifndef AO_CAN_FILTER_IDE_1_13

#define AO_CAN_FILTER_IDE_1_13          (0)

#endif

#ifndef AO_CAN_FILTER_MASK_1_13

#define AO_CAN_FILTER_MASK_1_13         (0)

#endif

#ifndef AO_CAN_FILTER_SID_1_13

#define AO_CAN_FILTER_SID_1_13          (0)

#endif

#ifndef AO_CAN_FILTER_EID_1_14

#define AO_CAN_FILTER_EID_1_14          (0)

#endif

#ifndef AO_CAN_FILTER_ENABLE_1_14

#define AO_CAN_FILTER_ENABLE_1_14       (false)

#endif

#ifndef AO_CAN_FILTER_FIFO_1_14

#define AO_CAN_FILTER_FIFO_1_14         (0)

#endif

#ifndef AO_CAN_FILTER_IDE_1_14

#define AO_CAN_FILTER_IDE_1_14          (0)

#endif

#ifndef AO_CAN_FILTER_MASK_1_14

#define AO_CAN_FILTER_MASK_1_14         (0)

#endif

#ifndef AO_CAN_FILTER_SID_1_14

#define AO_CAN_FILTER_SID_1_14          (0)

#endif

#ifndef AO_CAN_FILTER_EID_1_15

#define AO_CAN_FILTER_EID_1_15          (0)

#endif

#ifndef AO_CAN_FILTER_ENABLE_1_15

#define AO_CAN_FILTER_ENABLE_1_15       (false)

#endif

#ifndef AO_CAN_FILTER_FIFO_1_15

#define AO_CAN_FILTER_FIFO_1_15         (0)

#endif

#ifndef AO_CAN_FILTER_IDE_1_15

#define AO_CAN_FILTER_IDE_1_15          (0)

#endif

#ifndef AO_CAN_FILTER_MASK_1_15

#define AO_CAN_FILTER_MASK_1_15         (0)

#endif

#ifndef AO_CAN_FILTER_SID_1_15

#define AO_CAN_FILTER_SID_1_15          (0)

#endif

#ifndef AO_CAN_FILTER_EID_1_16

#define AO_CAN_FILTER_EID_1_16          (0)

#endif

#ifndef AO_CAN_FILTER_ENABLE_1_16

#define AO_CAN_FILTER_ENABLE_1_16       (false)

#endif

#ifndef AO_CAN_FILTER_FIFO_1_16

#define AO_CAN_FILTER_FIFO_1_16         (0)

#endif

#ifndef AO_CAN_FILTER_IDE_1_16

#define AO_CAN_FILTER_IDE_1_16          (0)

#endif

#ifndef AO_CAN_FILTER_MASK_1_16

#define AO_CAN_FILTER_MASK_1_16         (0)

#endif

#ifndef AO_CAN_FILTER_SID_1_16

#define AO_CAN_FILTER_SID_1_16          (0)

#endif

#ifndef AO_CAN_FILTER_EID_1_17

#define AO_CAN_FILTER_EID_1_17          (0)

#endif

#ifndef AO_CAN_FILTER_ENABLE_1_17

#define AO_CAN_FILTER_ENABLE_1_17       (false)

#endif

#ifndef AO_CAN_FILTER_FIFO_1_17

#define AO_CAN_FILTER_FIFO_1_17         (0)

#endif

#ifndef AO_CAN_FILTER_IDE_1_17

#define AO_CAN_FILTER_IDE_1_17          (0)

#endif

#ifndef AO_CAN_FILTER_MASK_1_17

#define AO_CAN_FILTER_MASK_1_17         (0)

#endif

#ifndef AO_CAN_FILTER_SID_1_17

#define AO_CAN_FILTER_SID_1_17          (0)

#endif

#ifndef AO_CAN_FILTER_EID_1_18

#define AO_CAN_FILTER_EID_1_18          (0)

#endif

#ifndef AO_CAN_FILTER_ENABLE_1_18

#define AO_CAN_FILTER_ENABLE_1_18       (false)

#endif

#ifndef AO_CAN_FILTER_FIFO_1_18

#define AO_CAN_FILTER_FIFO_1_18         (0)

#endif

#ifndef AO_CAN_FILTER_IDE_1_18

#define AO_CAN_FILTER_IDE_1_18          (0)

#endif

#ifndef AO_CAN_FILTER_MASK_1_18

#define AO_CAN_FILTER_MASK_1_18         (0)

#endif

#ifndef AO_CAN_FILTER_SID_1_18

#define AO_CAN_FILTER_SID_1_18          (0)

#endif

#ifndef AO_CAN_FILTER_EID_1_19

#define AO_CAN_FILTER_EID_1_19          (0)

#endif

#ifndef AO_CAN_FILTER_ENABLE_1_19

#define AO_CAN_FILTER_ENABLE_1_19       (false)

#endif

#ifndef AO_CAN_FILTER_FIFO_1_19

#define AO_CAN_FILTER_FIFO_1_19         (0)

#endif

#ifndef AO_CAN_FILTER_IDE_1_19

#define AO_CAN_FILTER_IDE_1_19          (0)

#endif

#ifndef AO_CAN_FILTER_MASK_1_19

#define AO_CAN_FILTER_MASK_1_19         (0)

#endif

#ifndef AO_CAN_FILTER_SID_1_19

#define AO_CAN_FILTER_SID_1_19          (0)

#endif

#ifndef AO_CAN_FILTER_EID_1_20

#define AO_CAN_FILTER_EID_1_20          (0)

#endif

#ifndef AO_CAN_FILTER_ENABLE_1_20

#define AO_CAN_FILTER_ENABLE_1_20       (false)

#endif

#ifndef AO_CAN_FILTER_FIFO_1_20

#define AO_CAN_FILTER_FIFO_1_20         (0)

#endif

#ifndef AO_CAN_FILTER_IDE_1_20

#define AO_CAN_FILTER_IDE_1_20          (0)

#endif

#ifndef AO_CAN_FILTER_MASK_1_20

#define AO_CAN_FILTER_MASK_1_20         (0)

#endif

#ifndef AO_CAN_FILTER_SID_1_20

#define AO_CAN_FILTER_SID_1_20          (0)

#endif

#ifndef AO_CAN_FILTER_EID_1_21

#define AO_CAN_FILTER_EID_1_21          (0)

#endif

#ifndef AO_CAN_FILTER_ENABLE_1_21

#define AO_CAN_FILTER_ENABLE_1_21       (false)

#endif

#ifndef AO_CAN_FILTER_FIFO_1_21

#define AO_CAN_FILTER_FIFO_1_21         (0)

#endif

#ifndef AO_CAN_FILTER_IDE_1_21

#define AO_CAN_FILTER_IDE_1_21          (0)

#endif

#ifndef AO_CAN_FILTER_MASK_1_21

#define AO_CAN_FILTER_MASK_1_21         (0)

#endif

#ifndef AO_CAN_FILTER_SID_1_21

#define AO_CAN_FILTER_SID_1_21          (0)

#endif

#ifndef AO_CAN_FILTER_EID_1_22

#define AO_CAN_FILTER_EID_1_22          (0)

#endif

#ifndef AO_CAN_FILTER_ENABLE_1_22

#define AO_CAN_FILTER_ENABLE_1_22       (false)

#endif

#ifndef AO_CAN_FILTER_FIFO_1_22

#define AO_CAN_FILTER_FIFO_1_22         (0)

#endif

#ifndef AO_CAN_FILTER_IDE_1_22

#define AO_CAN_FILTER_IDE_1_22          (0)

#endif

#ifndef AO_CAN_FILTER_MASK_1_22

#define AO_CAN_FILTER_MASK_1_22         (0)

#endif

#ifndef AO_CAN_FILTER_SID_1_22

#define AO_CAN_FILTER_SID_1_22          (0)

#endif

#ifndef AO_CAN_FILTER_EID_1_23

#define AO_CAN_FILTER_EID_1_23          (0)

#endif

#ifndef AO_CAN_FILTER_ENABLE_1_23

#define AO_CAN_FILTER_ENABLE_1_23       (false)

#endif

#ifndef AO_CAN_FILTER_FIFO_1_23

#define AO_CAN_FILTER_FIFO_1_23         (0)

#endif

#ifndef AO_CAN_FILTER_IDE_1_23

#define AO_CAN_FILTER_IDE_1_23          (0)

#endif

#ifndef AO_CAN_FILTER_MASK_1_23

#define AO_CAN_FILTER_MASK_1_23         (0)

#endif

#ifndef AO_CAN_FILTER_SID_1_23

#define AO_CAN_FILTER_SID_1_23          (0)

#endif

#ifndef AO_CAN_FILTER_EID_1_24

#define AO_CAN_FILTER_EID_1_24          (0)

#endif

#ifndef AO_CAN_FILTER_ENABLE_1_24

#define AO_CAN_FILTER_ENABLE_1_24       (false)

#endif

#ifndef AO_CAN_FILTER_FIFO_1_24

#define AO_CAN_FILTER_FIFO_1_24         (0)

#endif

#ifndef AO_CAN_FILTER_IDE_1_24

#define AO_CAN_FILTER_IDE_1_24          (0)

#endif

#ifndef AO_CAN_FILTER_MASK_1_24

#define AO_CAN_FILTER_MASK_1_24         (0)

#endif

#ifndef AO_CAN_FILTER_SID_1_24

#define AO_CAN_FILTER_SID_1_24          (0)

#endif

#ifndef AO_CAN_FILTER_EID_1_25

#define AO_CAN_FILTER_EID_1_25          (0)

#endif

#ifndef AO_CAN_FILTER_ENABLE_1_25

#define AO_CAN_FILTER_ENABLE_1_25       (false)

#endif

#ifndef AO_CAN_FILTER_FIFO_1_25

#define AO_CAN_FILTER_FIFO_1_25         (0)

#endif

#ifndef AO_CAN_FILTER_IDE_1_25

#define AO_CAN_FILTER_IDE_1_25          (0)

#endif

#ifndef AO_CAN_FILTER_MASK_1_25

#define AO_CAN_FILTER_MASK_1_25         (0)

#endif

#ifndef AO_CAN_FILTER_SID_1_25

#define AO_CAN_FILTER_SID_1_25          (0)

#endif

#ifndef AO_CAN_FILTER_EID_1_26

#define AO_CAN_FILTER_EID_1_26          (0)

#endif

#ifndef AO_CAN_FILTER_ENABLE_1_26

#define AO_CAN_FILTER_ENABLE_1_26       (false)

#endif

#ifndef AO_CAN_FILTER_FIFO_1_26

#define AO_CAN_FILTER_FIFO_1_26         (0)

#endif

#ifndef AO_CAN_FILTER_IDE_1_26

#define AO_CAN_FILTER_IDE_1_26          (0)

#endif

#ifndef AO_CAN_FILTER_MASK_1_26

#define AO_CAN_FILTER_MASK_1_26         (0)

#endif

#ifndef AO_CAN_FILTER_SID_1_26

#define AO_CAN_FILTER_SID_1_26          (0)

#endif

#ifndef AO_CAN_FILTER_EID_1_27

#define AO_CAN_FILTER_EID_1_27          (0)

#endif

#ifndef AO_CAN_FILTER_ENABLE_1_27

#define AO_CAN_FILTER_ENABLE_1_27       (false)

#endif

#ifndef AO_CAN_FILTER_FIFO_1_27

#define AO_CAN_FILTER_FIFO_1_27         (0)

#endif

#ifndef AO_CAN_FILTER_IDE_1_27

#define AO_CAN_FILTER_IDE_1_27          (0)

#endif

#ifndef AO_CAN_FILTER_MASK_1_27

#define AO_CAN_FILTER_MASK_1_27         (0)

#endif

#ifndef AO_CAN_FILTER_SID_1_27

#define AO_CAN_FILTER_SID_1_27          (0)

#endif

#ifndef AO_CAN_FILTER_EID_1_28

#define AO_CAN_FILTER_EID_1_28          (0)

#endif

#ifndef AO_CAN_FILTER_ENABLE_1_28

#define AO_CAN_FILTER_ENABLE_1_28       (false)

#endif

#ifndef AO_CAN_FILTER_FIFO_1_28

#define AO_CAN_FILTER_FIFO_1_28         (0)

#endif

#ifndef AO_CAN_FILTER_IDE_1_28

#define AO_CAN_FILTER_IDE_1_28          (0)

#endif

#ifndef AO_CAN_FILTER_MASK_1_28

#define AO_CAN_FILTER_MASK_1_28         (0)

#endif

#ifndef AO_CAN_FILTER_SID_1_28

#define AO_CAN_FILTER_SID_1_28          (0)

#endif

#ifndef AO_CAN_FILTER_EID_1_29

#define AO_CAN_FILTER_EID_1_29          (0)

#endif

#ifndef AO_CAN_FILTER_ENABLE_1_29

#define AO_CAN_FILTER_ENABLE_1_29       (false)

#endif

#ifndef AO_CAN_FILTER_FIFO_1_29

#define AO_CAN_FILTER_FIFO_1_29         (0)

#endif

#ifndef AO_CAN_FILTER_IDE_1_29

#define AO_CAN_FILTER_IDE_1_29          (0)

#endif

#ifndef AO_CAN_FILTER_MASK_1_29

#define AO_CAN_FILTER_MASK_1_29         (0)

#endif

#ifndef AO_CAN_FILTER_SID_1_29

#define AO_CAN_FILTER_SID_1_29          (0)

#endif

#ifndef AO_CAN_FILTER_EID_1_30

#define AO_CAN_FILTER_EID_1_30          (0)

#endif

#ifndef AO_CAN_FILTER_ENABLE_1_30

#define AO_CAN_FILTER_ENABLE_1_30       (false)

#endif

#ifndef AO_CAN_FILTER_FIFO_1_30

#define AO_CAN_FILTER_FIFO_1_30         (0)

#endif

#ifndef AO_CAN_FILTER_IDE_1_30

#define AO_CAN_FILTER_IDE_1_30          (0)

#endif

#ifndef AO_CAN_FILTER_MASK_1_30

#define AO_CAN_FILTER_MASK_1_30         (0)

#endif

#ifndef AO_CAN_FILTER_SID_1_30

#define AO_CAN_FILTER_SID_1_30          (0)

#endif

#ifndef AO_CAN_FILTER_EID_1_31

#define AO_CAN_FILTER_EID_1_31          (0)

#endif

#ifndef AO_CAN_FILTER_ENABLE_1_31

#define AO_CAN_FILTER_ENABLE_1_31       (false)

#endif

#ifndef AO_CAN_FILTER_FIFO_1_31

#define AO_CAN_FILTER_FIFO_1_31         (0)

#endif

#ifndef AO_CAN_FILTER_IDE_1_31

#define AO_CAN_FILTER_IDE_1_31          (0)

#endif

#ifndef AO_CAN_FILTER_MASK_1_31

#define AO_CAN_FILTER_MASK_1_31         (0)

#endif

#ifndef AO_CAN_FILTER_SID_1_31

#define AO_CAN_FILTER_SID_1_31          (0)

#endif

#ifndef AO_CAN_FILTER_MASK_EID_1_0

#define AO_CAN_FILTER_MASK_EID_1_0      (0)

#endif

#ifndef AO_CAN_FILTER_MASK_IDE_1_0

#define AO_CAN_FILTER_MASK_IDE_1_0      (0)

#endif

#ifndef AO_CAN_FILTER_MASK_SID_1_0

#define AO_CAN_FILTER_MASK_SID_1_0      (0)

#endif

#ifndef AO_CAN_FILTER_MASK_EID_1_1

#define AO_CAN_FILTER_MASK_EID_1_1      (0)

#endif

#ifndef AO_CAN_FILTER_MASK_IDE_1_1

#define AO_CAN_FILTER_MASK_IDE_1_1      (0)

#endif

#ifndef AO_CAN_FILTER_MASK_SID_1_1

#define AO_CAN_FILTER_MASK_SID_1_1      (0)

#endif

#ifndef AO_CAN_FILTER_MASK_EID_1_2

#define AO_CAN_FILTER_MASK_EID_1_2      (0)

#endif

#ifndef AO_CAN_FILTER_MASK_IDE_1_2

#define AO_CAN_FILTER_MASK_IDE_1_2      (0)

#endif

#ifndef AO_CAN_FILTER_MASK_SID_1_2

#define AO_CAN_FILTER_MASK_SID_1_2      (0)

#endif

#ifndef AO_CAN_FILTER_MASK_EID_1_3

#define AO_CAN_FILTER_MASK_EID_1_3      (0)

#endif

#ifndef AO_CAN_FILTER_MASK_IDE_1_3

#define AO_CAN_FILTER_MASK_IDE_1_3      (0)

#endif

#ifndef AO_CAN_FILTER_MASK_SID_1_3

#define AO_CAN_FILTER_MASK_SID_1_3      (0)

#endif

#ifndef AO_CAN_INVALID_1

#define AO_CAN_INVALID_1                (false)

#endif

#ifndef AO_CAN_MODE_1

#define AO_CAN_MODE_1                   (false)

#endif

#ifndef AO_CAN_OVERFLOW_1

#define AO_CAN_OVERFLOW_1               (false)

#endif

#ifndef AO_CAN_RX_1

#define AO_CAN_RX_1                     ((AO_CAN_FIFOS_RX_1) > 0 ? true : false)

#endif

#ifndef AO_CAN_SENT_1

#define AO_CAN_SENT_1                   (false)

#endif

#ifndef AO_CAN_SYSTEM_1

#define AO_CAN_SYSTEM_1                 (false)

#endif

#ifndef AO_CAN_TIMER_1

#define AO_CAN_TIMER_1                  (false)

#endif

#ifndef AO_CAN_TX_1

#define AO_CAN_TX_1                     ((AO_CAN_FIFOS_TX_1) > 0 ? true : false)

#endif

#ifndef AO_CAN_UNDERFLOW_1

#define AO_CAN_UNDERFLOW_1              (false)

#endif

#ifndef AO_CAN_WAKE_UP_1

#define AO_CAN_WAKE_UP_1                (false)

#endif

extern  ao_can_t                        ao_can_buffers_1[AO_CAN_BUFFERS_1];

extern  ao_send_obj_t                   ao_can_in_1     [AO_CAN_FIFOS_RX_1];

extern  ao_recv_obj_t                   ao_can_out_1    [AO_CAN_FIFOS_TX_1];

extern  ao_task_t                       ao_can_task_1;

void    ao_can_bus_1(                   ao_can_bus_info_t const * info);

void    ao_can_config_1();

void    ao_can_config_baud_1();

void    ao_can_config_fifos_1();

void    ao_can_config_filter_masks_1();

void    ao_can_config_filters_1();

void    ao_can_invalid_1(               ao_can_invalid_info_t const * info);

void    ao_can_listen_all_1();

void    ao_can_listen_only_1();

void    ao_can_loopback_1();

void    ao_can_mode_1(                  ao_can_mode_info_t const * info);

void    ao_can_normal_1();

void    ao_can_overflow_1(              ao_can_overflow_info_t const * info);

#ifndef ao_can_reg_1

#define ao_can_reg_1()                  ((ao_can_reg_t *) (_CAN1_BASE_ADDRESS))

#endif

void    ao_can_sent_1(                  ao_can_sent_info_t const * info);

void    ao_can_start_1();

void    ao_can_stop_1();

void    ao_can_system_1(                ao_can_system_info_t const * info);

void    ao_can_timer_1(                 ao_can_timer_info_t const * info);

void    ao_can_underflow_1(             ao_can_underflow_info_t const * info);

void    ao_can_wake_up_1(               ao_can_wake_up_info_t const * info);

```

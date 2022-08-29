---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The ao_sys_xc32_pic32_can/ao_can_2.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys_xc32_pic32_can/ao_can_2.h/ 
subtitle: ""
title: "ao_can_2.h"
toc: true
---

# Overview

...

# Includes

```c
#include <ao_can.h>
#include <ao_recv_obj.h>
#include <ao_send_obj.h>
#include <ao_task.h>
#include <stdbool.h>
#include <xc.h>

#ifndef AO_CAN_2

#ifdef  _CAN2

#define AO_CAN_2                        (true)

#else

#define AO_CAN_2                        (false)

#endif

#endif

#ifndef AO_CAN_BAUD_2

#define AO_CAN_BAUD_2                   (100000)

#endif

#ifndef AO_CAN_BAUD_SAMPLE_2

#define AO_CAN_BAUD_SAMPLE_2            (85)

#endif

#ifndef AO_CAN_BAUD_SAMPLE_THRICE_2

#define AO_CAN_BAUD_SAMPLE_THRICE_2     (true)

#endif

#ifndef AO_CAN_BAUD_SJW_2

#define AO_CAN_BAUD_SJW_2               (1)

#endif

#ifndef AO_CAN_BAUD_WAKE_UP_FILTER_2

#define AO_CAN_BAUD_WAKE_UP_FILTER_2    (false)

#endif

#ifndef AO_CAN_BAUD_MAX_2

#define AO_CAN_BAUD_MAX_2               AO_CAN_BAUD_MAX(AO_SYS_CLOCK_CAN2)

#endif

#ifndef AO_CAN_BAUD_MIN_2

#define AO_CAN_BAUD_MIN_2               AO_CAN_BAUD_MIN(AO_SYS_CLOCK_CAN2)

#endif

#ifndef AO_CAN_BUFFERS_2_0

#define AO_CAN_BUFFERS_2_0              (0)

#endif

#ifndef AO_CAN_BUFFERS_2_1

#define AO_CAN_BUFFERS_2_1              (0)

#endif

#ifndef AO_CAN_BUFFERS_2_2

#define AO_CAN_BUFFERS_2_2              (0)

#endif

#ifndef AO_CAN_BUFFERS_2_3

#define AO_CAN_BUFFERS_2_3              (0)

#endif

#ifndef AO_CAN_BUFFERS_2_4

#define AO_CAN_BUFFERS_2_4              (0)

#endif

#ifndef AO_CAN_BUFFERS_2_5

#define AO_CAN_BUFFERS_2_5              (0)

#endif

#ifndef AO_CAN_BUFFERS_2_6

#define AO_CAN_BUFFERS_2_6              (0)

#endif

#ifndef AO_CAN_BUFFERS_2_7

#define AO_CAN_BUFFERS_2_7              (0)

#endif

#ifndef AO_CAN_BUFFERS_2_8

#define AO_CAN_BUFFERS_2_8              (0)

#endif

#ifndef AO_CAN_BUFFERS_2_9

#define AO_CAN_BUFFERS_2_9              (0)

#endif

#ifndef AO_CAN_BUFFERS_2_10

#define AO_CAN_BUFFERS_2_10             (0)

#endif

#ifndef AO_CAN_BUFFERS_2_11

#define AO_CAN_BUFFERS_2_11             (0)

#endif

#ifndef AO_CAN_BUFFERS_2_12

#define AO_CAN_BUFFERS_2_12             (0)

#endif

#ifndef AO_CAN_BUFFERS_2_13

#define AO_CAN_BUFFERS_2_13             (0)

#endif

#ifndef AO_CAN_BUFFERS_2_14

#define AO_CAN_BUFFERS_2_14             (0)

#endif

#ifndef AO_CAN_BUFFERS_2_15

#define AO_CAN_BUFFERS_2_15             (0)

#endif

#ifndef AO_CAN_BUFFERS_2_16

#define AO_CAN_BUFFERS_2_16             (0)

#endif

#ifndef AO_CAN_BUFFERS_2_17

#define AO_CAN_BUFFERS_2_17             (0)

#endif

#ifndef AO_CAN_BUFFERS_2_18

#define AO_CAN_BUFFERS_2_18             (0)

#endif

#ifndef AO_CAN_BUFFERS_2_19

#define AO_CAN_BUFFERS_2_19             (0)

#endif

#ifndef AO_CAN_BUFFERS_2_20

#define AO_CAN_BUFFERS_2_20             (0)

#endif

#ifndef AO_CAN_BUFFERS_2_21

#define AO_CAN_BUFFERS_2_21             (0)

#endif

#ifndef AO_CAN_BUFFERS_2_22

#define AO_CAN_BUFFERS_2_22             (0)

#endif

#ifndef AO_CAN_BUFFERS_2_23

#define AO_CAN_BUFFERS_2_23             (0)

#endif

#ifndef AO_CAN_BUFFERS_2_24

#define AO_CAN_BUFFERS_2_24             (0)

#endif

#ifndef AO_CAN_BUFFERS_2_25

#define AO_CAN_BUFFERS_2_25             (0)

#endif

#ifndef AO_CAN_BUFFERS_2_26

#define AO_CAN_BUFFERS_2_26             (0)

#endif

#ifndef AO_CAN_BUFFERS_2_27

#define AO_CAN_BUFFERS_2_27             (0)

#endif

#ifndef AO_CAN_BUFFERS_2_28

#define AO_CAN_BUFFERS_2_28             (0)

#endif

#ifndef AO_CAN_BUFFERS_2_29

#define AO_CAN_BUFFERS_2_29             (0)

#endif

#ifndef AO_CAN_BUFFERS_2_30

#define AO_CAN_BUFFERS_2_30             (0)

#endif

#ifndef AO_CAN_BUFFERS_2_31

#define AO_CAN_BUFFERS_2_31             (0)

#endif

#ifndef AO_CAN_BUFFERS_2

#define AO_CAN_BUFFERS_2                                                    \
(                                                                           \
        AO_CAN_BUFFERS_2_0  +                                               \
        AO_CAN_BUFFERS_2_1  +                                               \
        AO_CAN_BUFFERS_2_2  +                                               \
        AO_CAN_BUFFERS_2_3  +                                               \
        AO_CAN_BUFFERS_2_4  +                                               \
        AO_CAN_BUFFERS_2_5  +                                               \
        AO_CAN_BUFFERS_2_6  +                                               \
        AO_CAN_BUFFERS_2_7  +                                               \
        AO_CAN_BUFFERS_2_8  +                                               \
        AO_CAN_BUFFERS_2_9  +                                               \
        AO_CAN_BUFFERS_2_10 +                                               \
        AO_CAN_BUFFERS_2_11 +                                               \
        AO_CAN_BUFFERS_2_12 +                                               \
        AO_CAN_BUFFERS_2_13 +                                               \
        AO_CAN_BUFFERS_2_14 +                                               \
        AO_CAN_BUFFERS_2_15 +                                               \
        AO_CAN_BUFFERS_2_16 +                                               \
        AO_CAN_BUFFERS_2_17 +                                               \
        AO_CAN_BUFFERS_2_18 +                                               \
        AO_CAN_BUFFERS_2_19 +                                               \
        AO_CAN_BUFFERS_2_20 +                                               \
        AO_CAN_BUFFERS_2_21 +                                               \
        AO_CAN_BUFFERS_2_22 +                                               \
        AO_CAN_BUFFERS_2_23 +                                               \
        AO_CAN_BUFFERS_2_24 +                                               \
        AO_CAN_BUFFERS_2_25 +                                               \
        AO_CAN_BUFFERS_2_26 +                                               \
        AO_CAN_BUFFERS_2_27 +                                               \
        AO_CAN_BUFFERS_2_28 +                                               \
        AO_CAN_BUFFERS_2_29 +                                               \
        AO_CAN_BUFFERS_2_30 +                                               \
        AO_CAN_BUFFERS_2_31                                                 \
)

#endif

#ifndef AO_CAN_BUS_2

#define AO_CAN_BUS_2                    (false)

#endif

#ifndef AO_CAN_FIFOS_RX_2

#define AO_CAN_FIFOS_RX_2               (0)

#endif

#ifndef AO_CAN_FIFOS_TX_2

#define AO_CAN_FIFOS_TX_2               (0)

#endif

#ifndef AO_CAN_FIFOS_2

#define AO_CAN_FIFOS_2                  ((AO_CAN_FIFOS_RX_2) + (AO_CAN_FIFOS_TX_2))

#endif

#ifndef AO_CAN_FILTER_EID_2_0

#define AO_CAN_FILTER_EID_2_0           (0)

#endif

#ifndef AO_CAN_FILTER_ENABLE_2_0

#define AO_CAN_FILTER_ENABLE_2_0        (false)

#endif

#ifndef AO_CAN_FILTER_FIFO_2_0

#define AO_CAN_FILTER_FIFO_2_0          (0)

#endif

#ifndef AO_CAN_FILTER_IDE_2_0

#define AO_CAN_FILTER_IDE_2_0           (0)

#endif

#ifndef AO_CAN_FILTER_MASK_2_0

#define AO_CAN_FILTER_MASK_2_0          (0)

#endif

#ifndef AO_CAN_FILTER_SID_2_0

#define AO_CAN_FILTER_SID_2_0           (0)

#endif

#ifndef AO_CAN_FILTER_EID_2_1

#define AO_CAN_FILTER_EID_2_1           (0)

#endif

#ifndef AO_CAN_FILTER_ENABLE_2_1

#define AO_CAN_FILTER_ENABLE_2_1        (false)

#endif

#ifndef AO_CAN_FILTER_FIFO_2_1

#define AO_CAN_FILTER_FIFO_2_1          (0)

#endif

#ifndef AO_CAN_FILTER_IDE_2_1

#define AO_CAN_FILTER_IDE_2_1           (0)

#endif

#ifndef AO_CAN_FILTER_MASK_2_1

#define AO_CAN_FILTER_MASK_2_1          (0)

#endif

#ifndef AO_CAN_FILTER_SID_2_1

#define AO_CAN_FILTER_SID_2_1           (0)

#endif

#ifndef AO_CAN_FILTER_EID_2_2

#define AO_CAN_FILTER_EID_2_2           (0)

#endif

#ifndef AO_CAN_FILTER_ENABLE_2_2

#define AO_CAN_FILTER_ENABLE_2_2        (false)

#endif

#ifndef AO_CAN_FILTER_FIFO_2_2

#define AO_CAN_FILTER_FIFO_2_2          (0)

#endif

#ifndef AO_CAN_FILTER_IDE_2_2

#define AO_CAN_FILTER_IDE_2_2           (0)

#endif

#ifndef AO_CAN_FILTER_MASK_2_2

#define AO_CAN_FILTER_MASK_2_2          (0)

#endif

#ifndef AO_CAN_FILTER_SID_2_2

#define AO_CAN_FILTER_SID_2_2           (0)

#endif

#ifndef AO_CAN_FILTER_EID_2_3

#define AO_CAN_FILTER_EID_2_3           (0)

#endif

#ifndef AO_CAN_FILTER_ENABLE_2_3

#define AO_CAN_FILTER_ENABLE_2_3        (false)

#endif

#ifndef AO_CAN_FILTER_FIFO_2_3

#define AO_CAN_FILTER_FIFO_2_3          (0)

#endif

#ifndef AO_CAN_FILTER_IDE_2_3

#define AO_CAN_FILTER_IDE_2_3           (0)

#endif

#ifndef AO_CAN_FILTER_MASK_2_3

#define AO_CAN_FILTER_MASK_2_3          (0)

#endif

#ifndef AO_CAN_FILTER_SID_2_3

#define AO_CAN_FILTER_SID_2_3           (0)

#endif

#ifndef AO_CAN_FILTER_EID_2_4

#define AO_CAN_FILTER_EID_2_4           (0)

#endif

#ifndef AO_CAN_FILTER_ENABLE_2_4

#define AO_CAN_FILTER_ENABLE_2_4        (false)

#endif

#ifndef AO_CAN_FILTER_FIFO_2_4

#define AO_CAN_FILTER_FIFO_2_4          (0)

#endif

#ifndef AO_CAN_FILTER_IDE_2_4

#define AO_CAN_FILTER_IDE_2_4           (0)

#endif

#ifndef AO_CAN_FILTER_MASK_2_4

#define AO_CAN_FILTER_MASK_2_4          (0)

#endif

#ifndef AO_CAN_FILTER_SID_2_4

#define AO_CAN_FILTER_SID_2_4           (0)

#endif

#ifndef AO_CAN_FILTER_EID_2_5

#define AO_CAN_FILTER_EID_2_5           (0)

#endif

#ifndef AO_CAN_FILTER_ENABLE_2_5

#define AO_CAN_FILTER_ENABLE_2_5        (false)

#endif

#ifndef AO_CAN_FILTER_FIFO_2_5

#define AO_CAN_FILTER_FIFO_2_5          (0)

#endif

#ifndef AO_CAN_FILTER_IDE_2_5

#define AO_CAN_FILTER_IDE_2_5           (0)

#endif

#ifndef AO_CAN_FILTER_MASK_2_5

#define AO_CAN_FILTER_MASK_2_5          (0)

#endif

#ifndef AO_CAN_FILTER_SID_2_5

#define AO_CAN_FILTER_SID_2_5           (0)

#endif

#ifndef AO_CAN_FILTER_EID_2_6

#define AO_CAN_FILTER_EID_2_6           (0)

#endif

#ifndef AO_CAN_FILTER_ENABLE_2_6

#define AO_CAN_FILTER_ENABLE_2_6        (false)

#endif

#ifndef AO_CAN_FILTER_FIFO_2_6

#define AO_CAN_FILTER_FIFO_2_6          (0)

#endif

#ifndef AO_CAN_FILTER_IDE_2_6

#define AO_CAN_FILTER_IDE_2_6           (0)

#endif

#ifndef AO_CAN_FILTER_MASK_2_6

#define AO_CAN_FILTER_MASK_2_6          (0)

#endif

#ifndef AO_CAN_FILTER_SID_2_6

#define AO_CAN_FILTER_SID_2_6           (0)

#endif

#ifndef AO_CAN_FILTER_EID_2_7

#define AO_CAN_FILTER_EID_2_7           (0)

#endif

#ifndef AO_CAN_FILTER_ENABLE_2_7

#define AO_CAN_FILTER_ENABLE_2_7        (false)

#endif

#ifndef AO_CAN_FILTER_FIFO_2_7

#define AO_CAN_FILTER_FIFO_2_7          (0)

#endif

#ifndef AO_CAN_FILTER_IDE_2_7

#define AO_CAN_FILTER_IDE_2_7           (0)

#endif

#ifndef AO_CAN_FILTER_MASK_2_7

#define AO_CAN_FILTER_MASK_2_7          (0)

#endif

#ifndef AO_CAN_FILTER_SID_2_7

#define AO_CAN_FILTER_SID_2_7           (0)

#endif

#ifndef AO_CAN_FILTER_EID_2_8

#define AO_CAN_FILTER_EID_2_8           (0)

#endif

#ifndef AO_CAN_FILTER_ENABLE_2_8

#define AO_CAN_FILTER_ENABLE_2_8        (false)

#endif

#ifndef AO_CAN_FILTER_FIFO_2_8

#define AO_CAN_FILTER_FIFO_2_8          (0)

#endif

#ifndef AO_CAN_FILTER_IDE_2_8

#define AO_CAN_FILTER_IDE_2_8           (0)

#endif

#ifndef AO_CAN_FILTER_MASK_2_8

#define AO_CAN_FILTER_MASK_2_8          (0)

#endif

#ifndef AO_CAN_FILTER_SID_2_8

#define AO_CAN_FILTER_SID_2_8           (0)

#endif

#ifndef AO_CAN_FILTER_EID_2_9

#define AO_CAN_FILTER_EID_2_9           (0)

#endif

#ifndef AO_CAN_FILTER_ENABLE_2_9

#define AO_CAN_FILTER_ENABLE_2_9        (false)

#endif

#ifndef AO_CAN_FILTER_FIFO_2_9

#define AO_CAN_FILTER_FIFO_2_9          (0)

#endif

#ifndef AO_CAN_FILTER_IDE_2_9

#define AO_CAN_FILTER_IDE_2_9           (0)

#endif

#ifndef AO_CAN_FILTER_MASK_2_9

#define AO_CAN_FILTER_MASK_2_9          (0)

#endif

#ifndef AO_CAN_FILTER_SID_2_9

#define AO_CAN_FILTER_SID_2_9           (0)

#endif

#ifndef AO_CAN_FILTER_EID_2_10

#define AO_CAN_FILTER_EID_2_10          (0)

#endif

#ifndef AO_CAN_FILTER_ENABLE_2_10

#define AO_CAN_FILTER_ENABLE_2_10       (false)

#endif

#ifndef AO_CAN_FILTER_FIFO_2_10

#define AO_CAN_FILTER_FIFO_2_10         (0)

#endif

#ifndef AO_CAN_FILTER_IDE_2_10

#define AO_CAN_FILTER_IDE_2_10          (0)

#endif

#ifndef AO_CAN_FILTER_MASK_2_10

#define AO_CAN_FILTER_MASK_2_10         (0)

#endif

#ifndef AO_CAN_FILTER_SID_2_10

#define AO_CAN_FILTER_SID_2_10          (0)

#endif

#ifndef AO_CAN_FILTER_EID_2_11

#define AO_CAN_FILTER_EID_2_11          (0)

#endif

#ifndef AO_CAN_FILTER_ENABLE_2_11

#define AO_CAN_FILTER_ENABLE_2_11       (false)

#endif

#ifndef AO_CAN_FILTER_FIFO_2_11

#define AO_CAN_FILTER_FIFO_2_11         (0)

#endif

#ifndef AO_CAN_FILTER_IDE_2_11

#define AO_CAN_FILTER_IDE_2_11          (0)

#endif

#ifndef AO_CAN_FILTER_MASK_2_11

#define AO_CAN_FILTER_MASK_2_11         (0)

#endif

#ifndef AO_CAN_FILTER_SID_2_11

#define AO_CAN_FILTER_SID_2_11          (0)

#endif

#ifndef AO_CAN_FILTER_EID_2_12

#define AO_CAN_FILTER_EID_2_12          (0)

#endif

#ifndef AO_CAN_FILTER_ENABLE_2_12

#define AO_CAN_FILTER_ENABLE_2_12       (false)

#endif

#ifndef AO_CAN_FILTER_FIFO_2_12

#define AO_CAN_FILTER_FIFO_2_12         (0)

#endif

#ifndef AO_CAN_FILTER_IDE_2_12

#define AO_CAN_FILTER_IDE_2_12          (0)

#endif

#ifndef AO_CAN_FILTER_MASK_2_12

#define AO_CAN_FILTER_MASK_2_12         (0)

#endif

#ifndef AO_CAN_FILTER_SID_2_12

#define AO_CAN_FILTER_SID_2_12          (0)

#endif

#ifndef AO_CAN_FILTER_EID_2_13

#define AO_CAN_FILTER_EID_2_13          (0)

#endif

#ifndef AO_CAN_FILTER_ENABLE_2_13

#define AO_CAN_FILTER_ENABLE_2_13       (false)

#endif

#ifndef AO_CAN_FILTER_FIFO_2_13

#define AO_CAN_FILTER_FIFO_2_13         (0)

#endif

#ifndef AO_CAN_FILTER_IDE_2_13

#define AO_CAN_FILTER_IDE_2_13          (0)

#endif

#ifndef AO_CAN_FILTER_MASK_2_13

#define AO_CAN_FILTER_MASK_2_13         (0)

#endif

#ifndef AO_CAN_FILTER_SID_2_13

#define AO_CAN_FILTER_SID_2_13          (0)

#endif

#ifndef AO_CAN_FILTER_EID_2_14

#define AO_CAN_FILTER_EID_2_14          (0)

#endif

#ifndef AO_CAN_FILTER_ENABLE_2_14

#define AO_CAN_FILTER_ENABLE_2_14       (false)

#endif

#ifndef AO_CAN_FILTER_FIFO_2_14

#define AO_CAN_FILTER_FIFO_2_14         (0)

#endif

#ifndef AO_CAN_FILTER_IDE_2_14

#define AO_CAN_FILTER_IDE_2_14          (0)

#endif

#ifndef AO_CAN_FILTER_MASK_2_14

#define AO_CAN_FILTER_MASK_2_14         (0)

#endif

#ifndef AO_CAN_FILTER_SID_2_14

#define AO_CAN_FILTER_SID_2_14          (0)

#endif

#ifndef AO_CAN_FILTER_EID_2_15

#define AO_CAN_FILTER_EID_2_15          (0)

#endif

#ifndef AO_CAN_FILTER_ENABLE_2_15

#define AO_CAN_FILTER_ENABLE_2_15       (false)

#endif

#ifndef AO_CAN_FILTER_FIFO_2_15

#define AO_CAN_FILTER_FIFO_2_15         (0)

#endif

#ifndef AO_CAN_FILTER_IDE_2_15

#define AO_CAN_FILTER_IDE_2_15          (0)

#endif

#ifndef AO_CAN_FILTER_MASK_2_15

#define AO_CAN_FILTER_MASK_2_15         (0)

#endif

#ifndef AO_CAN_FILTER_SID_2_15

#define AO_CAN_FILTER_SID_2_15          (0)

#endif

#ifndef AO_CAN_FILTER_EID_2_16

#define AO_CAN_FILTER_EID_2_16          (0)

#endif

#ifndef AO_CAN_FILTER_ENABLE_2_16

#define AO_CAN_FILTER_ENABLE_2_16       (false)

#endif

#ifndef AO_CAN_FILTER_FIFO_2_16

#define AO_CAN_FILTER_FIFO_2_16         (0)

#endif

#ifndef AO_CAN_FILTER_IDE_2_16

#define AO_CAN_FILTER_IDE_2_16          (0)

#endif

#ifndef AO_CAN_FILTER_MASK_2_16

#define AO_CAN_FILTER_MASK_2_16         (0)

#endif

#ifndef AO_CAN_FILTER_SID_2_16

#define AO_CAN_FILTER_SID_2_16          (0)

#endif

#ifndef AO_CAN_FILTER_EID_2_17

#define AO_CAN_FILTER_EID_2_17          (0)

#endif

#ifndef AO_CAN_FILTER_ENABLE_2_17

#define AO_CAN_FILTER_ENABLE_2_17       (false)

#endif

#ifndef AO_CAN_FILTER_FIFO_2_17

#define AO_CAN_FILTER_FIFO_2_17         (0)

#endif

#ifndef AO_CAN_FILTER_IDE_2_17

#define AO_CAN_FILTER_IDE_2_17          (0)

#endif

#ifndef AO_CAN_FILTER_MASK_2_17

#define AO_CAN_FILTER_MASK_2_17         (0)

#endif

#ifndef AO_CAN_FILTER_SID_2_17

#define AO_CAN_FILTER_SID_2_17          (0)

#endif

#ifndef AO_CAN_FILTER_EID_2_18

#define AO_CAN_FILTER_EID_2_18          (0)

#endif

#ifndef AO_CAN_FILTER_ENABLE_2_18

#define AO_CAN_FILTER_ENABLE_2_18       (false)

#endif

#ifndef AO_CAN_FILTER_FIFO_2_18

#define AO_CAN_FILTER_FIFO_2_18         (0)

#endif

#ifndef AO_CAN_FILTER_IDE_2_18

#define AO_CAN_FILTER_IDE_2_18          (0)

#endif

#ifndef AO_CAN_FILTER_MASK_2_18

#define AO_CAN_FILTER_MASK_2_18         (0)

#endif

#ifndef AO_CAN_FILTER_SID_2_18

#define AO_CAN_FILTER_SID_2_18          (0)

#endif

#ifndef AO_CAN_FILTER_EID_2_19

#define AO_CAN_FILTER_EID_2_19          (0)

#endif

#ifndef AO_CAN_FILTER_ENABLE_2_19

#define AO_CAN_FILTER_ENABLE_2_19       (false)

#endif

#ifndef AO_CAN_FILTER_FIFO_2_19

#define AO_CAN_FILTER_FIFO_2_19         (0)

#endif

#ifndef AO_CAN_FILTER_IDE_2_19

#define AO_CAN_FILTER_IDE_2_19          (0)

#endif

#ifndef AO_CAN_FILTER_MASK_2_19

#define AO_CAN_FILTER_MASK_2_19         (0)

#endif

#ifndef AO_CAN_FILTER_SID_2_19

#define AO_CAN_FILTER_SID_2_19          (0)

#endif

#ifndef AO_CAN_FILTER_EID_2_20

#define AO_CAN_FILTER_EID_2_20          (0)

#endif

#ifndef AO_CAN_FILTER_ENABLE_2_20

#define AO_CAN_FILTER_ENABLE_2_20       (false)

#endif

#ifndef AO_CAN_FILTER_FIFO_2_20

#define AO_CAN_FILTER_FIFO_2_20         (0)

#endif

#ifndef AO_CAN_FILTER_IDE_2_20

#define AO_CAN_FILTER_IDE_2_20          (0)

#endif

#ifndef AO_CAN_FILTER_MASK_2_20

#define AO_CAN_FILTER_MASK_2_20         (0)

#endif

#ifndef AO_CAN_FILTER_SID_2_20

#define AO_CAN_FILTER_SID_2_20          (0)

#endif

#ifndef AO_CAN_FILTER_EID_2_21

#define AO_CAN_FILTER_EID_2_21          (0)

#endif

#ifndef AO_CAN_FILTER_ENABLE_2_21

#define AO_CAN_FILTER_ENABLE_2_21       (false)

#endif

#ifndef AO_CAN_FILTER_FIFO_2_21

#define AO_CAN_FILTER_FIFO_2_21         (0)

#endif

#ifndef AO_CAN_FILTER_IDE_2_21

#define AO_CAN_FILTER_IDE_2_21          (0)

#endif

#ifndef AO_CAN_FILTER_MASK_2_21

#define AO_CAN_FILTER_MASK_2_21         (0)

#endif

#ifndef AO_CAN_FILTER_SID_2_21

#define AO_CAN_FILTER_SID_2_21          (0)

#endif

#ifndef AO_CAN_FILTER_EID_2_22

#define AO_CAN_FILTER_EID_2_22          (0)

#endif

#ifndef AO_CAN_FILTER_ENABLE_2_22

#define AO_CAN_FILTER_ENABLE_2_22       (false)

#endif

#ifndef AO_CAN_FILTER_FIFO_2_22

#define AO_CAN_FILTER_FIFO_2_22         (0)

#endif

#ifndef AO_CAN_FILTER_IDE_2_22

#define AO_CAN_FILTER_IDE_2_22          (0)

#endif

#ifndef AO_CAN_FILTER_MASK_2_22

#define AO_CAN_FILTER_MASK_2_22         (0)

#endif

#ifndef AO_CAN_FILTER_SID_2_22

#define AO_CAN_FILTER_SID_2_22          (0)

#endif

#ifndef AO_CAN_FILTER_EID_2_23

#define AO_CAN_FILTER_EID_2_23          (0)

#endif

#ifndef AO_CAN_FILTER_ENABLE_2_23

#define AO_CAN_FILTER_ENABLE_2_23       (false)

#endif

#ifndef AO_CAN_FILTER_FIFO_2_23

#define AO_CAN_FILTER_FIFO_2_23         (0)

#endif

#ifndef AO_CAN_FILTER_IDE_2_23

#define AO_CAN_FILTER_IDE_2_23          (0)

#endif

#ifndef AO_CAN_FILTER_MASK_2_23

#define AO_CAN_FILTER_MASK_2_23         (0)

#endif

#ifndef AO_CAN_FILTER_SID_2_23

#define AO_CAN_FILTER_SID_2_23          (0)

#endif

#ifndef AO_CAN_FILTER_EID_2_24

#define AO_CAN_FILTER_EID_2_24          (0)

#endif

#ifndef AO_CAN_FILTER_ENABLE_2_24

#define AO_CAN_FILTER_ENABLE_2_24       (false)

#endif

#ifndef AO_CAN_FILTER_FIFO_2_24

#define AO_CAN_FILTER_FIFO_2_24         (0)

#endif

#ifndef AO_CAN_FILTER_IDE_2_24

#define AO_CAN_FILTER_IDE_2_24          (0)

#endif

#ifndef AO_CAN_FILTER_MASK_2_24

#define AO_CAN_FILTER_MASK_2_24         (0)

#endif

#ifndef AO_CAN_FILTER_SID_2_24

#define AO_CAN_FILTER_SID_2_24          (0)

#endif

#ifndef AO_CAN_FILTER_EID_2_25

#define AO_CAN_FILTER_EID_2_25          (0)

#endif

#ifndef AO_CAN_FILTER_ENABLE_2_25

#define AO_CAN_FILTER_ENABLE_2_25       (false)

#endif

#ifndef AO_CAN_FILTER_FIFO_2_25

#define AO_CAN_FILTER_FIFO_2_25         (0)

#endif

#ifndef AO_CAN_FILTER_IDE_2_25

#define AO_CAN_FILTER_IDE_2_25          (0)

#endif

#ifndef AO_CAN_FILTER_MASK_2_25

#define AO_CAN_FILTER_MASK_2_25         (0)

#endif

#ifndef AO_CAN_FILTER_SID_2_25

#define AO_CAN_FILTER_SID_2_25          (0)

#endif

#ifndef AO_CAN_FILTER_EID_2_26

#define AO_CAN_FILTER_EID_2_26          (0)

#endif

#ifndef AO_CAN_FILTER_ENABLE_2_26

#define AO_CAN_FILTER_ENABLE_2_26       (false)

#endif

#ifndef AO_CAN_FILTER_FIFO_2_26

#define AO_CAN_FILTER_FIFO_2_26         (0)

#endif

#ifndef AO_CAN_FILTER_IDE_2_26

#define AO_CAN_FILTER_IDE_2_26          (0)

#endif

#ifndef AO_CAN_FILTER_MASK_2_26

#define AO_CAN_FILTER_MASK_2_26         (0)

#endif

#ifndef AO_CAN_FILTER_SID_2_26

#define AO_CAN_FILTER_SID_2_26          (0)

#endif

#ifndef AO_CAN_FILTER_EID_2_27

#define AO_CAN_FILTER_EID_2_27          (0)

#endif

#ifndef AO_CAN_FILTER_ENABLE_2_27

#define AO_CAN_FILTER_ENABLE_2_27       (false)

#endif

#ifndef AO_CAN_FILTER_FIFO_2_27

#define AO_CAN_FILTER_FIFO_2_27         (0)

#endif

#ifndef AO_CAN_FILTER_IDE_2_27

#define AO_CAN_FILTER_IDE_2_27          (0)

#endif

#ifndef AO_CAN_FILTER_MASK_2_27

#define AO_CAN_FILTER_MASK_2_27         (0)

#endif

#ifndef AO_CAN_FILTER_SID_2_27

#define AO_CAN_FILTER_SID_2_27          (0)

#endif

#ifndef AO_CAN_FILTER_EID_2_28

#define AO_CAN_FILTER_EID_2_28          (0)

#endif

#ifndef AO_CAN_FILTER_ENABLE_2_28

#define AO_CAN_FILTER_ENABLE_2_28       (false)

#endif

#ifndef AO_CAN_FILTER_FIFO_2_28

#define AO_CAN_FILTER_FIFO_2_28         (0)

#endif

#ifndef AO_CAN_FILTER_IDE_2_28

#define AO_CAN_FILTER_IDE_2_28          (0)

#endif

#ifndef AO_CAN_FILTER_MASK_2_28

#define AO_CAN_FILTER_MASK_2_28         (0)

#endif

#ifndef AO_CAN_FILTER_SID_2_28

#define AO_CAN_FILTER_SID_2_28          (0)

#endif

#ifndef AO_CAN_FILTER_EID_2_29

#define AO_CAN_FILTER_EID_2_29          (0)

#endif

#ifndef AO_CAN_FILTER_ENABLE_2_29

#define AO_CAN_FILTER_ENABLE_2_29       (false)

#endif

#ifndef AO_CAN_FILTER_FIFO_2_29

#define AO_CAN_FILTER_FIFO_2_29         (0)

#endif

#ifndef AO_CAN_FILTER_IDE_2_29

#define AO_CAN_FILTER_IDE_2_29          (0)

#endif

#ifndef AO_CAN_FILTER_MASK_2_29

#define AO_CAN_FILTER_MASK_2_29         (0)

#endif

#ifndef AO_CAN_FILTER_SID_2_29

#define AO_CAN_FILTER_SID_2_29          (0)

#endif

#ifndef AO_CAN_FILTER_EID_2_30

#define AO_CAN_FILTER_EID_2_30          (0)

#endif

#ifndef AO_CAN_FILTER_ENABLE_2_30

#define AO_CAN_FILTER_ENABLE_2_30       (false)

#endif

#ifndef AO_CAN_FILTER_FIFO_2_30

#define AO_CAN_FILTER_FIFO_2_30         (0)

#endif

#ifndef AO_CAN_FILTER_IDE_2_30

#define AO_CAN_FILTER_IDE_2_30          (0)

#endif

#ifndef AO_CAN_FILTER_MASK_2_30

#define AO_CAN_FILTER_MASK_2_30         (0)

#endif

#ifndef AO_CAN_FILTER_SID_2_30

#define AO_CAN_FILTER_SID_2_30          (0)

#endif

#ifndef AO_CAN_FILTER_EID_2_31

#define AO_CAN_FILTER_EID_2_31          (0)

#endif

#ifndef AO_CAN_FILTER_ENABLE_2_31

#define AO_CAN_FILTER_ENABLE_2_31       (false)

#endif

#ifndef AO_CAN_FILTER_FIFO_2_31

#define AO_CAN_FILTER_FIFO_2_31         (0)

#endif

#ifndef AO_CAN_FILTER_IDE_2_31

#define AO_CAN_FILTER_IDE_2_31          (0)

#endif

#ifndef AO_CAN_FILTER_MASK_2_31

#define AO_CAN_FILTER_MASK_2_31         (0)

#endif

#ifndef AO_CAN_FILTER_SID_2_31

#define AO_CAN_FILTER_SID_2_31          (0)

#endif

#ifndef AO_CAN_FILTER_MASK_EID_2_0

#define AO_CAN_FILTER_MASK_EID_2_0      (0)

#endif

#ifndef AO_CAN_FILTER_MASK_IDE_2_0

#define AO_CAN_FILTER_MASK_IDE_2_0      (0)

#endif

#ifndef AO_CAN_FILTER_MASK_SID_2_0

#define AO_CAN_FILTER_MASK_SID_2_0      (0)

#endif

#ifndef AO_CAN_FILTER_MASK_EID_2_1

#define AO_CAN_FILTER_MASK_EID_2_1      (0)

#endif

#ifndef AO_CAN_FILTER_MASK_IDE_2_1

#define AO_CAN_FILTER_MASK_IDE_2_1      (0)

#endif

#ifndef AO_CAN_FILTER_MASK_SID_2_1

#define AO_CAN_FILTER_MASK_SID_2_1      (0)

#endif

#ifndef AO_CAN_FILTER_MASK_EID_2_2

#define AO_CAN_FILTER_MASK_EID_2_2      (0)

#endif

#ifndef AO_CAN_FILTER_MASK_IDE_2_2

#define AO_CAN_FILTER_MASK_IDE_2_2      (0)

#endif

#ifndef AO_CAN_FILTER_MASK_SID_2_2

#define AO_CAN_FILTER_MASK_SID_2_2      (0)

#endif

#ifndef AO_CAN_FILTER_MASK_EID_2_3

#define AO_CAN_FILTER_MASK_EID_2_3      (0)

#endif

#ifndef AO_CAN_FILTER_MASK_IDE_2_3

#define AO_CAN_FILTER_MASK_IDE_2_3      (0)

#endif

#ifndef AO_CAN_FILTER_MASK_SID_2_3

#define AO_CAN_FILTER_MASK_SID_2_3      (0)

#endif

#ifndef AO_CAN_INVALID_2

#define AO_CAN_INVALID_2                (false)

#endif

#ifndef AO_CAN_MODE_2

#define AO_CAN_MODE_2                   (false)

#endif

#ifndef AO_CAN_OVERFLOW_2

#define AO_CAN_OVERFLOW_2               (false)

#endif

#ifndef AO_CAN_RX_2

#define AO_CAN_RX_2                     ((AO_CAN_FIFOS_RX_2) > 0 ? true : false)

#endif

#ifndef AO_CAN_SENT_2

#define AO_CAN_SENT_2                   (false)

#endif

#ifndef AO_CAN_SYSTEM_2

#define AO_CAN_SYSTEM_2                 (false)

#endif

#ifndef AO_CAN_TIMER_2

#define AO_CAN_TIMER_2                  (false)

#endif

#ifndef AO_CAN_TX_2

#define AO_CAN_TX_2                     ((AO_CAN_FIFOS_TX_2) > 0 ? true : false)

#endif

#ifndef AO_CAN_UNDERFLOW_2

#define AO_CAN_UNDERFLOW_2              (false)

#endif

#ifndef AO_CAN_WAKE_UP_2

#define AO_CAN_WAKE_UP_2                (false)

#endif

extern  ao_can_t                        ao_can_buffers_2[AO_CAN_BUFFERS_2];

extern  ao_send_obj_t                   ao_can_in_2     [AO_CAN_FIFOS_RX_2];

extern  ao_recv_obj_t                   ao_can_out_2    [AO_CAN_FIFOS_TX_2];

extern  ao_task_t                       ao_can_task_2;

void    ao_can_bus_2(                   ao_can_bus_info_t const * info);

void    ao_can_config_2();

void    ao_can_config_baud_2();

void    ao_can_config_fifos_2();

void    ao_can_config_filter_masks_2();

void    ao_can_config_filters_2();

void    ao_can_invalid_2(               ao_can_invalid_info_t const * info);

void    ao_can_listen_all_2();

void    ao_can_listen_only_2();

void    ao_can_loopback_2();

void    ao_can_mode_2(                  ao_can_mode_info_t const * info);

void    ao_can_normal_2();

void    ao_can_overflow_2(              ao_can_overflow_info_t const * info);

#ifndef ao_can_reg_2

#define ao_can_reg_2()                  ((ao_can_reg_t *) (_CAN2_BASE_ADDRESS))

#endif

void    ao_can_sent_2(                  ao_can_sent_info_t const * info);

void    ao_can_start_2();

void    ao_can_stop_2();

void    ao_can_system_2(                ao_can_system_info_t const * info);

void    ao_can_timer_2(                 ao_can_timer_info_t const * info);

void    ao_can_underflow_2(             ao_can_underflow_info_t const * info);

void    ao_can_wake_up_2(               ao_can_wake_up_info_t const * info);

```

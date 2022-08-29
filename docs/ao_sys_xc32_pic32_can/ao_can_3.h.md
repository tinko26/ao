---
author: "Stefan Wagner"
date: 2022-08-29
description: "The ao_sys_xc32_pic32_can/ao_can_3.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys_xc32_pic32_can/ao_can_3.h/ 
subtitle: "<code>ao_sys_xc32_pic32_can</code>"
title: "<code>ao_can_3.h</code>"
toc: true
---

#ifndef AO_CAN_3

#ifdef  _CAN3

#define AO_CAN_3                        (true)

#else

#define AO_CAN_3                        (false)

#endif

#endif

#ifndef AO_CAN_BAUD_3

#define AO_CAN_BAUD_3                   (100000)

#endif

#ifndef AO_CAN_BAUD_SAMPLE_3

#define AO_CAN_BAUD_SAMPLE_3            (85)

#endif

#ifndef AO_CAN_BAUD_SAMPLE_THRICE_3

#define AO_CAN_BAUD_SAMPLE_THRICE_3     (true)

#endif

#ifndef AO_CAN_BAUD_SJW_3

#define AO_CAN_BAUD_SJW_3               (1)

#endif

#ifndef AO_CAN_BAUD_WAKE_UP_FILTER_3

#define AO_CAN_BAUD_WAKE_UP_FILTER_3    (false)

#endif

#ifndef AO_CAN_BAUD_MAX_3

#define AO_CAN_BAUD_MAX_3               AO_CAN_BAUD_MAX(AO_SYS_CLOCK_CAN3)

#endif

#ifndef AO_CAN_BAUD_MIN_3

#define AO_CAN_BAUD_MIN_3               AO_CAN_BAUD_MIN(AO_SYS_CLOCK_CAN3)

#endif

#ifndef AO_CAN_BUFFERS_3_0

#define AO_CAN_BUFFERS_3_0              (0)

#endif

#ifndef AO_CAN_BUFFERS_3_1

#define AO_CAN_BUFFERS_3_1              (0)

#endif

#ifndef AO_CAN_BUFFERS_3_2

#define AO_CAN_BUFFERS_3_2              (0)

#endif

#ifndef AO_CAN_BUFFERS_3_3

#define AO_CAN_BUFFERS_3_3              (0)

#endif

#ifndef AO_CAN_BUFFERS_3_4

#define AO_CAN_BUFFERS_3_4              (0)

#endif

#ifndef AO_CAN_BUFFERS_3_5

#define AO_CAN_BUFFERS_3_5              (0)

#endif

#ifndef AO_CAN_BUFFERS_3_6

#define AO_CAN_BUFFERS_3_6              (0)

#endif

#ifndef AO_CAN_BUFFERS_3_7

#define AO_CAN_BUFFERS_3_7              (0)

#endif

#ifndef AO_CAN_BUFFERS_3_8

#define AO_CAN_BUFFERS_3_8              (0)

#endif

#ifndef AO_CAN_BUFFERS_3_9

#define AO_CAN_BUFFERS_3_9              (0)

#endif

#ifndef AO_CAN_BUFFERS_3_10

#define AO_CAN_BUFFERS_3_10             (0)

#endif

#ifndef AO_CAN_BUFFERS_3_11

#define AO_CAN_BUFFERS_3_11             (0)

#endif

#ifndef AO_CAN_BUFFERS_3_12

#define AO_CAN_BUFFERS_3_12             (0)

#endif

#ifndef AO_CAN_BUFFERS_3_13

#define AO_CAN_BUFFERS_3_13             (0)

#endif

#ifndef AO_CAN_BUFFERS_3_14

#define AO_CAN_BUFFERS_3_14             (0)

#endif

#ifndef AO_CAN_BUFFERS_3_15

#define AO_CAN_BUFFERS_3_15             (0)

#endif

#ifndef AO_CAN_BUFFERS_3_16

#define AO_CAN_BUFFERS_3_16             (0)

#endif

#ifndef AO_CAN_BUFFERS_3_17

#define AO_CAN_BUFFERS_3_17             (0)

#endif

#ifndef AO_CAN_BUFFERS_3_18

#define AO_CAN_BUFFERS_3_18             (0)

#endif

#ifndef AO_CAN_BUFFERS_3_19

#define AO_CAN_BUFFERS_3_19             (0)

#endif

#ifndef AO_CAN_BUFFERS_3_20

#define AO_CAN_BUFFERS_3_20             (0)

#endif

#ifndef AO_CAN_BUFFERS_3_21

#define AO_CAN_BUFFERS_3_21             (0)

#endif

#ifndef AO_CAN_BUFFERS_3_22

#define AO_CAN_BUFFERS_3_22             (0)

#endif

#ifndef AO_CAN_BUFFERS_3_23

#define AO_CAN_BUFFERS_3_23             (0)

#endif

#ifndef AO_CAN_BUFFERS_3_24

#define AO_CAN_BUFFERS_3_24             (0)

#endif

#ifndef AO_CAN_BUFFERS_3_25

#define AO_CAN_BUFFERS_3_25             (0)

#endif

#ifndef AO_CAN_BUFFERS_3_26

#define AO_CAN_BUFFERS_3_26             (0)

#endif

#ifndef AO_CAN_BUFFERS_3_27

#define AO_CAN_BUFFERS_3_27             (0)

#endif

#ifndef AO_CAN_BUFFERS_3_28

#define AO_CAN_BUFFERS_3_28             (0)

#endif

#ifndef AO_CAN_BUFFERS_3_29

#define AO_CAN_BUFFERS_3_29             (0)

#endif

#ifndef AO_CAN_BUFFERS_3_30

#define AO_CAN_BUFFERS_3_30             (0)

#endif

#ifndef AO_CAN_BUFFERS_3_31

#define AO_CAN_BUFFERS_3_31             (0)

#endif

#ifndef AO_CAN_BUFFERS_3

#define AO_CAN_BUFFERS_3                                                    \
(                                                                           \
        AO_CAN_BUFFERS_3_0  +                                               \
        AO_CAN_BUFFERS_3_1  +                                               \
        AO_CAN_BUFFERS_3_2  +                                               \
        AO_CAN_BUFFERS_3_3  +                                               \
        AO_CAN_BUFFERS_3_4  +                                               \
        AO_CAN_BUFFERS_3_5  +                                               \
        AO_CAN_BUFFERS_3_6  +                                               \
        AO_CAN_BUFFERS_3_7  +                                               \
        AO_CAN_BUFFERS_3_8  +                                               \
        AO_CAN_BUFFERS_3_9  +                                               \
        AO_CAN_BUFFERS_3_10 +                                               \
        AO_CAN_BUFFERS_3_11 +                                               \
        AO_CAN_BUFFERS_3_12 +                                               \
        AO_CAN_BUFFERS_3_13 +                                               \
        AO_CAN_BUFFERS_3_14 +                                               \
        AO_CAN_BUFFERS_3_15 +                                               \
        AO_CAN_BUFFERS_3_16 +                                               \
        AO_CAN_BUFFERS_3_17 +                                               \
        AO_CAN_BUFFERS_3_18 +                                               \
        AO_CAN_BUFFERS_3_19 +                                               \
        AO_CAN_BUFFERS_3_20 +                                               \
        AO_CAN_BUFFERS_3_21 +                                               \
        AO_CAN_BUFFERS_3_22 +                                               \
        AO_CAN_BUFFERS_3_23 +                                               \
        AO_CAN_BUFFERS_3_24 +                                               \
        AO_CAN_BUFFERS_3_25 +                                               \
        AO_CAN_BUFFERS_3_26 +                                               \
        AO_CAN_BUFFERS_3_27 +                                               \
        AO_CAN_BUFFERS_3_28 +                                               \
        AO_CAN_BUFFERS_3_29 +                                               \
        AO_CAN_BUFFERS_3_30 +                                               \
        AO_CAN_BUFFERS_3_31                                                 \
)

#endif

#ifndef AO_CAN_BUS_3

#define AO_CAN_BUS_3                    (false)

#endif

#ifndef AO_CAN_FIFOS_RX_3

#define AO_CAN_FIFOS_RX_3               (0)

#endif

#ifndef AO_CAN_FIFOS_TX_3

#define AO_CAN_FIFOS_TX_3               (0)

#endif

#ifndef AO_CAN_FIFOS_3

#define AO_CAN_FIFOS_3                  ((AO_CAN_FIFOS_RX_3) + (AO_CAN_FIFOS_TX_3))

#endif

#ifndef AO_CAN_FILTER_EID_3_0

#define AO_CAN_FILTER_EID_3_0           (0)

#endif

#ifndef AO_CAN_FILTER_ENABLE_3_0

#define AO_CAN_FILTER_ENABLE_3_0        (false)

#endif

#ifndef AO_CAN_FILTER_FIFO_3_0

#define AO_CAN_FILTER_FIFO_3_0          (0)

#endif

#ifndef AO_CAN_FILTER_IDE_3_0

#define AO_CAN_FILTER_IDE_3_0           (0)

#endif

#ifndef AO_CAN_FILTER_MASK_3_0

#define AO_CAN_FILTER_MASK_3_0          (0)

#endif

#ifndef AO_CAN_FILTER_SID_3_0

#define AO_CAN_FILTER_SID_3_0           (0)

#endif

#ifndef AO_CAN_FILTER_EID_3_1

#define AO_CAN_FILTER_EID_3_1           (0)

#endif

#ifndef AO_CAN_FILTER_ENABLE_3_1

#define AO_CAN_FILTER_ENABLE_3_1        (false)

#endif

#ifndef AO_CAN_FILTER_FIFO_3_1

#define AO_CAN_FILTER_FIFO_3_1          (0)

#endif

#ifndef AO_CAN_FILTER_IDE_3_1

#define AO_CAN_FILTER_IDE_3_1           (0)

#endif

#ifndef AO_CAN_FILTER_MASK_3_1

#define AO_CAN_FILTER_MASK_3_1          (0)

#endif

#ifndef AO_CAN_FILTER_SID_3_1

#define AO_CAN_FILTER_SID_3_1           (0)

#endif

#ifndef AO_CAN_FILTER_EID_3_2

#define AO_CAN_FILTER_EID_3_2           (0)

#endif

#ifndef AO_CAN_FILTER_ENABLE_3_2

#define AO_CAN_FILTER_ENABLE_3_2        (false)

#endif

#ifndef AO_CAN_FILTER_FIFO_3_2

#define AO_CAN_FILTER_FIFO_3_2          (0)

#endif

#ifndef AO_CAN_FILTER_IDE_3_2

#define AO_CAN_FILTER_IDE_3_2           (0)

#endif

#ifndef AO_CAN_FILTER_MASK_3_2

#define AO_CAN_FILTER_MASK_3_2          (0)

#endif

#ifndef AO_CAN_FILTER_SID_3_2

#define AO_CAN_FILTER_SID_3_2           (0)

#endif

#ifndef AO_CAN_FILTER_EID_3_3

#define AO_CAN_FILTER_EID_3_3           (0)

#endif

#ifndef AO_CAN_FILTER_ENABLE_3_3

#define AO_CAN_FILTER_ENABLE_3_3        (false)

#endif

#ifndef AO_CAN_FILTER_FIFO_3_3

#define AO_CAN_FILTER_FIFO_3_3          (0)

#endif

#ifndef AO_CAN_FILTER_IDE_3_3

#define AO_CAN_FILTER_IDE_3_3           (0)

#endif

#ifndef AO_CAN_FILTER_MASK_3_3

#define AO_CAN_FILTER_MASK_3_3          (0)

#endif

#ifndef AO_CAN_FILTER_SID_3_3

#define AO_CAN_FILTER_SID_3_3           (0)

#endif

#ifndef AO_CAN_FILTER_EID_3_4

#define AO_CAN_FILTER_EID_3_4           (0)

#endif

#ifndef AO_CAN_FILTER_ENABLE_3_4

#define AO_CAN_FILTER_ENABLE_3_4        (false)

#endif

#ifndef AO_CAN_FILTER_FIFO_3_4

#define AO_CAN_FILTER_FIFO_3_4          (0)

#endif

#ifndef AO_CAN_FILTER_IDE_3_4

#define AO_CAN_FILTER_IDE_3_4           (0)

#endif

#ifndef AO_CAN_FILTER_MASK_3_4

#define AO_CAN_FILTER_MASK_3_4          (0)

#endif

#ifndef AO_CAN_FILTER_SID_3_4

#define AO_CAN_FILTER_SID_3_4           (0)

#endif

#ifndef AO_CAN_FILTER_EID_3_5

#define AO_CAN_FILTER_EID_3_5           (0)

#endif

#ifndef AO_CAN_FILTER_ENABLE_3_5

#define AO_CAN_FILTER_ENABLE_3_5        (false)

#endif

#ifndef AO_CAN_FILTER_FIFO_3_5

#define AO_CAN_FILTER_FIFO_3_5          (0)

#endif

#ifndef AO_CAN_FILTER_IDE_3_5

#define AO_CAN_FILTER_IDE_3_5           (0)

#endif

#ifndef AO_CAN_FILTER_MASK_3_5

#define AO_CAN_FILTER_MASK_3_5          (0)

#endif

#ifndef AO_CAN_FILTER_SID_3_5

#define AO_CAN_FILTER_SID_3_5           (0)

#endif

#ifndef AO_CAN_FILTER_EID_3_6

#define AO_CAN_FILTER_EID_3_6           (0)

#endif

#ifndef AO_CAN_FILTER_ENABLE_3_6

#define AO_CAN_FILTER_ENABLE_3_6        (false)

#endif

#ifndef AO_CAN_FILTER_FIFO_3_6

#define AO_CAN_FILTER_FIFO_3_6          (0)

#endif

#ifndef AO_CAN_FILTER_IDE_3_6

#define AO_CAN_FILTER_IDE_3_6           (0)

#endif

#ifndef AO_CAN_FILTER_MASK_3_6

#define AO_CAN_FILTER_MASK_3_6          (0)

#endif

#ifndef AO_CAN_FILTER_SID_3_6

#define AO_CAN_FILTER_SID_3_6           (0)

#endif

#ifndef AO_CAN_FILTER_EID_3_7

#define AO_CAN_FILTER_EID_3_7           (0)

#endif

#ifndef AO_CAN_FILTER_ENABLE_3_7

#define AO_CAN_FILTER_ENABLE_3_7        (false)

#endif

#ifndef AO_CAN_FILTER_FIFO_3_7

#define AO_CAN_FILTER_FIFO_3_7          (0)

#endif

#ifndef AO_CAN_FILTER_IDE_3_7

#define AO_CAN_FILTER_IDE_3_7           (0)

#endif

#ifndef AO_CAN_FILTER_MASK_3_7

#define AO_CAN_FILTER_MASK_3_7          (0)

#endif

#ifndef AO_CAN_FILTER_SID_3_7

#define AO_CAN_FILTER_SID_3_7           (0)

#endif

#ifndef AO_CAN_FILTER_EID_3_8

#define AO_CAN_FILTER_EID_3_8           (0)

#endif

#ifndef AO_CAN_FILTER_ENABLE_3_8

#define AO_CAN_FILTER_ENABLE_3_8        (false)

#endif

#ifndef AO_CAN_FILTER_FIFO_3_8

#define AO_CAN_FILTER_FIFO_3_8          (0)

#endif

#ifndef AO_CAN_FILTER_IDE_3_8

#define AO_CAN_FILTER_IDE_3_8           (0)

#endif

#ifndef AO_CAN_FILTER_MASK_3_8

#define AO_CAN_FILTER_MASK_3_8          (0)

#endif

#ifndef AO_CAN_FILTER_SID_3_8

#define AO_CAN_FILTER_SID_3_8           (0)

#endif

#ifndef AO_CAN_FILTER_EID_3_9

#define AO_CAN_FILTER_EID_3_9           (0)

#endif

#ifndef AO_CAN_FILTER_ENABLE_3_9

#define AO_CAN_FILTER_ENABLE_3_9        (false)

#endif

#ifndef AO_CAN_FILTER_FIFO_3_9

#define AO_CAN_FILTER_FIFO_3_9          (0)

#endif

#ifndef AO_CAN_FILTER_IDE_3_9

#define AO_CAN_FILTER_IDE_3_9           (0)

#endif

#ifndef AO_CAN_FILTER_MASK_3_9

#define AO_CAN_FILTER_MASK_3_9          (0)

#endif

#ifndef AO_CAN_FILTER_SID_3_9

#define AO_CAN_FILTER_SID_3_9           (0)

#endif

#ifndef AO_CAN_FILTER_EID_3_10

#define AO_CAN_FILTER_EID_3_10          (0)

#endif

#ifndef AO_CAN_FILTER_ENABLE_3_10

#define AO_CAN_FILTER_ENABLE_3_10       (false)

#endif

#ifndef AO_CAN_FILTER_FIFO_3_10

#define AO_CAN_FILTER_FIFO_3_10         (0)

#endif

#ifndef AO_CAN_FILTER_IDE_3_10

#define AO_CAN_FILTER_IDE_3_10          (0)

#endif

#ifndef AO_CAN_FILTER_MASK_3_10

#define AO_CAN_FILTER_MASK_3_10         (0)

#endif

#ifndef AO_CAN_FILTER_SID_3_10

#define AO_CAN_FILTER_SID_3_10          (0)

#endif

#ifndef AO_CAN_FILTER_EID_3_11

#define AO_CAN_FILTER_EID_3_11          (0)

#endif

#ifndef AO_CAN_FILTER_ENABLE_3_11

#define AO_CAN_FILTER_ENABLE_3_11       (false)

#endif

#ifndef AO_CAN_FILTER_FIFO_3_11

#define AO_CAN_FILTER_FIFO_3_11         (0)

#endif

#ifndef AO_CAN_FILTER_IDE_3_11

#define AO_CAN_FILTER_IDE_3_11          (0)

#endif

#ifndef AO_CAN_FILTER_MASK_3_11

#define AO_CAN_FILTER_MASK_3_11         (0)

#endif

#ifndef AO_CAN_FILTER_SID_3_11

#define AO_CAN_FILTER_SID_3_11          (0)

#endif

#ifndef AO_CAN_FILTER_EID_3_12

#define AO_CAN_FILTER_EID_3_12          (0)

#endif

#ifndef AO_CAN_FILTER_ENABLE_3_12

#define AO_CAN_FILTER_ENABLE_3_12       (false)

#endif

#ifndef AO_CAN_FILTER_FIFO_3_12

#define AO_CAN_FILTER_FIFO_3_12         (0)

#endif

#ifndef AO_CAN_FILTER_IDE_3_12

#define AO_CAN_FILTER_IDE_3_12          (0)

#endif

#ifndef AO_CAN_FILTER_MASK_3_12

#define AO_CAN_FILTER_MASK_3_12         (0)

#endif

#ifndef AO_CAN_FILTER_SID_3_12

#define AO_CAN_FILTER_SID_3_12          (0)

#endif

#ifndef AO_CAN_FILTER_EID_3_13

#define AO_CAN_FILTER_EID_3_13          (0)

#endif

#ifndef AO_CAN_FILTER_ENABLE_3_13

#define AO_CAN_FILTER_ENABLE_3_13       (false)

#endif

#ifndef AO_CAN_FILTER_FIFO_3_13

#define AO_CAN_FILTER_FIFO_3_13         (0)

#endif

#ifndef AO_CAN_FILTER_IDE_3_13

#define AO_CAN_FILTER_IDE_3_13          (0)

#endif

#ifndef AO_CAN_FILTER_MASK_3_13

#define AO_CAN_FILTER_MASK_3_13         (0)

#endif

#ifndef AO_CAN_FILTER_SID_3_13

#define AO_CAN_FILTER_SID_3_13          (0)

#endif

#ifndef AO_CAN_FILTER_EID_3_14

#define AO_CAN_FILTER_EID_3_14          (0)

#endif

#ifndef AO_CAN_FILTER_ENABLE_3_14

#define AO_CAN_FILTER_ENABLE_3_14       (false)

#endif

#ifndef AO_CAN_FILTER_FIFO_3_14

#define AO_CAN_FILTER_FIFO_3_14         (0)

#endif

#ifndef AO_CAN_FILTER_IDE_3_14

#define AO_CAN_FILTER_IDE_3_14          (0)

#endif

#ifndef AO_CAN_FILTER_MASK_3_14

#define AO_CAN_FILTER_MASK_3_14         (0)

#endif

#ifndef AO_CAN_FILTER_SID_3_14

#define AO_CAN_FILTER_SID_3_14          (0)

#endif

#ifndef AO_CAN_FILTER_EID_3_15

#define AO_CAN_FILTER_EID_3_15          (0)

#endif

#ifndef AO_CAN_FILTER_ENABLE_3_15

#define AO_CAN_FILTER_ENABLE_3_15       (false)

#endif

#ifndef AO_CAN_FILTER_FIFO_3_15

#define AO_CAN_FILTER_FIFO_3_15         (0)

#endif

#ifndef AO_CAN_FILTER_IDE_3_15

#define AO_CAN_FILTER_IDE_3_15          (0)

#endif

#ifndef AO_CAN_FILTER_MASK_3_15

#define AO_CAN_FILTER_MASK_3_15         (0)

#endif

#ifndef AO_CAN_FILTER_SID_3_15

#define AO_CAN_FILTER_SID_3_15          (0)

#endif

#ifndef AO_CAN_FILTER_EID_3_16

#define AO_CAN_FILTER_EID_3_16          (0)

#endif

#ifndef AO_CAN_FILTER_ENABLE_3_16

#define AO_CAN_FILTER_ENABLE_3_16       (false)

#endif

#ifndef AO_CAN_FILTER_FIFO_3_16

#define AO_CAN_FILTER_FIFO_3_16         (0)

#endif

#ifndef AO_CAN_FILTER_IDE_3_16

#define AO_CAN_FILTER_IDE_3_16          (0)

#endif

#ifndef AO_CAN_FILTER_MASK_3_16

#define AO_CAN_FILTER_MASK_3_16         (0)

#endif

#ifndef AO_CAN_FILTER_SID_3_16

#define AO_CAN_FILTER_SID_3_16          (0)

#endif

#ifndef AO_CAN_FILTER_EID_3_17

#define AO_CAN_FILTER_EID_3_17          (0)

#endif

#ifndef AO_CAN_FILTER_ENABLE_3_17

#define AO_CAN_FILTER_ENABLE_3_17       (false)

#endif

#ifndef AO_CAN_FILTER_FIFO_3_17

#define AO_CAN_FILTER_FIFO_3_17         (0)

#endif

#ifndef AO_CAN_FILTER_IDE_3_17

#define AO_CAN_FILTER_IDE_3_17          (0)

#endif

#ifndef AO_CAN_FILTER_MASK_3_17

#define AO_CAN_FILTER_MASK_3_17         (0)

#endif

#ifndef AO_CAN_FILTER_SID_3_17

#define AO_CAN_FILTER_SID_3_17          (0)

#endif

#ifndef AO_CAN_FILTER_EID_3_18

#define AO_CAN_FILTER_EID_3_18          (0)

#endif

#ifndef AO_CAN_FILTER_ENABLE_3_18

#define AO_CAN_FILTER_ENABLE_3_18       (false)

#endif

#ifndef AO_CAN_FILTER_FIFO_3_18

#define AO_CAN_FILTER_FIFO_3_18         (0)

#endif

#ifndef AO_CAN_FILTER_IDE_3_18

#define AO_CAN_FILTER_IDE_3_18          (0)

#endif

#ifndef AO_CAN_FILTER_MASK_3_18

#define AO_CAN_FILTER_MASK_3_18         (0)

#endif

#ifndef AO_CAN_FILTER_SID_3_18

#define AO_CAN_FILTER_SID_3_18          (0)

#endif

#ifndef AO_CAN_FILTER_EID_3_19

#define AO_CAN_FILTER_EID_3_19          (0)

#endif

#ifndef AO_CAN_FILTER_ENABLE_3_19

#define AO_CAN_FILTER_ENABLE_3_19       (false)

#endif

#ifndef AO_CAN_FILTER_FIFO_3_19

#define AO_CAN_FILTER_FIFO_3_19         (0)

#endif

#ifndef AO_CAN_FILTER_IDE_3_19

#define AO_CAN_FILTER_IDE_3_19          (0)

#endif

#ifndef AO_CAN_FILTER_MASK_3_19

#define AO_CAN_FILTER_MASK_3_19         (0)

#endif

#ifndef AO_CAN_FILTER_SID_3_19

#define AO_CAN_FILTER_SID_3_19          (0)

#endif

#ifndef AO_CAN_FILTER_EID_3_20

#define AO_CAN_FILTER_EID_3_20          (0)

#endif

#ifndef AO_CAN_FILTER_ENABLE_3_20

#define AO_CAN_FILTER_ENABLE_3_20       (false)

#endif

#ifndef AO_CAN_FILTER_FIFO_3_20

#define AO_CAN_FILTER_FIFO_3_20         (0)

#endif

#ifndef AO_CAN_FILTER_IDE_3_20

#define AO_CAN_FILTER_IDE_3_20          (0)

#endif

#ifndef AO_CAN_FILTER_MASK_3_20

#define AO_CAN_FILTER_MASK_3_20         (0)

#endif

#ifndef AO_CAN_FILTER_SID_3_20

#define AO_CAN_FILTER_SID_3_20          (0)

#endif

#ifndef AO_CAN_FILTER_EID_3_21

#define AO_CAN_FILTER_EID_3_21          (0)

#endif

#ifndef AO_CAN_FILTER_ENABLE_3_21

#define AO_CAN_FILTER_ENABLE_3_21       (false)

#endif

#ifndef AO_CAN_FILTER_FIFO_3_21

#define AO_CAN_FILTER_FIFO_3_21         (0)

#endif

#ifndef AO_CAN_FILTER_IDE_3_21

#define AO_CAN_FILTER_IDE_3_21          (0)

#endif

#ifndef AO_CAN_FILTER_MASK_3_21

#define AO_CAN_FILTER_MASK_3_21         (0)

#endif

#ifndef AO_CAN_FILTER_SID_3_21

#define AO_CAN_FILTER_SID_3_21          (0)

#endif

#ifndef AO_CAN_FILTER_EID_3_22

#define AO_CAN_FILTER_EID_3_22          (0)

#endif

#ifndef AO_CAN_FILTER_ENABLE_3_22

#define AO_CAN_FILTER_ENABLE_3_22       (false)

#endif

#ifndef AO_CAN_FILTER_FIFO_3_22

#define AO_CAN_FILTER_FIFO_3_22         (0)

#endif

#ifndef AO_CAN_FILTER_IDE_3_22

#define AO_CAN_FILTER_IDE_3_22          (0)

#endif

#ifndef AO_CAN_FILTER_MASK_3_22

#define AO_CAN_FILTER_MASK_3_22         (0)

#endif

#ifndef AO_CAN_FILTER_SID_3_22

#define AO_CAN_FILTER_SID_3_22          (0)

#endif

#ifndef AO_CAN_FILTER_EID_3_23

#define AO_CAN_FILTER_EID_3_23          (0)

#endif

#ifndef AO_CAN_FILTER_ENABLE_3_23

#define AO_CAN_FILTER_ENABLE_3_23       (false)

#endif

#ifndef AO_CAN_FILTER_FIFO_3_23

#define AO_CAN_FILTER_FIFO_3_23         (0)

#endif

#ifndef AO_CAN_FILTER_IDE_3_23

#define AO_CAN_FILTER_IDE_3_23          (0)

#endif

#ifndef AO_CAN_FILTER_MASK_3_23

#define AO_CAN_FILTER_MASK_3_23         (0)

#endif

#ifndef AO_CAN_FILTER_SID_3_23

#define AO_CAN_FILTER_SID_3_23          (0)

#endif

#ifndef AO_CAN_FILTER_EID_3_24

#define AO_CAN_FILTER_EID_3_24          (0)

#endif

#ifndef AO_CAN_FILTER_ENABLE_3_24

#define AO_CAN_FILTER_ENABLE_3_24       (false)

#endif

#ifndef AO_CAN_FILTER_FIFO_3_24

#define AO_CAN_FILTER_FIFO_3_24         (0)

#endif

#ifndef AO_CAN_FILTER_IDE_3_24

#define AO_CAN_FILTER_IDE_3_24          (0)

#endif

#ifndef AO_CAN_FILTER_MASK_3_24

#define AO_CAN_FILTER_MASK_3_24         (0)

#endif

#ifndef AO_CAN_FILTER_SID_3_24

#define AO_CAN_FILTER_SID_3_24          (0)

#endif

#ifndef AO_CAN_FILTER_EID_3_25

#define AO_CAN_FILTER_EID_3_25          (0)

#endif

#ifndef AO_CAN_FILTER_ENABLE_3_25

#define AO_CAN_FILTER_ENABLE_3_25       (false)

#endif

#ifndef AO_CAN_FILTER_FIFO_3_25

#define AO_CAN_FILTER_FIFO_3_25         (0)

#endif

#ifndef AO_CAN_FILTER_IDE_3_25

#define AO_CAN_FILTER_IDE_3_25          (0)

#endif

#ifndef AO_CAN_FILTER_MASK_3_25

#define AO_CAN_FILTER_MASK_3_25         (0)

#endif

#ifndef AO_CAN_FILTER_SID_3_25

#define AO_CAN_FILTER_SID_3_25          (0)

#endif

#ifndef AO_CAN_FILTER_EID_3_26

#define AO_CAN_FILTER_EID_3_26          (0)

#endif

#ifndef AO_CAN_FILTER_ENABLE_3_26

#define AO_CAN_FILTER_ENABLE_3_26       (false)

#endif

#ifndef AO_CAN_FILTER_FIFO_3_26

#define AO_CAN_FILTER_FIFO_3_26         (0)

#endif

#ifndef AO_CAN_FILTER_IDE_3_26

#define AO_CAN_FILTER_IDE_3_26          (0)

#endif

#ifndef AO_CAN_FILTER_MASK_3_26

#define AO_CAN_FILTER_MASK_3_26         (0)

#endif

#ifndef AO_CAN_FILTER_SID_3_26

#define AO_CAN_FILTER_SID_3_26          (0)

#endif

#ifndef AO_CAN_FILTER_EID_3_27

#define AO_CAN_FILTER_EID_3_27          (0)

#endif

#ifndef AO_CAN_FILTER_ENABLE_3_27

#define AO_CAN_FILTER_ENABLE_3_27       (false)

#endif

#ifndef AO_CAN_FILTER_FIFO_3_27

#define AO_CAN_FILTER_FIFO_3_27         (0)

#endif

#ifndef AO_CAN_FILTER_IDE_3_27

#define AO_CAN_FILTER_IDE_3_27          (0)

#endif

#ifndef AO_CAN_FILTER_MASK_3_27

#define AO_CAN_FILTER_MASK_3_27         (0)

#endif

#ifndef AO_CAN_FILTER_SID_3_27

#define AO_CAN_FILTER_SID_3_27          (0)

#endif

#ifndef AO_CAN_FILTER_EID_3_28

#define AO_CAN_FILTER_EID_3_28          (0)

#endif

#ifndef AO_CAN_FILTER_ENABLE_3_28

#define AO_CAN_FILTER_ENABLE_3_28       (false)

#endif

#ifndef AO_CAN_FILTER_FIFO_3_28

#define AO_CAN_FILTER_FIFO_3_28         (0)

#endif

#ifndef AO_CAN_FILTER_IDE_3_28

#define AO_CAN_FILTER_IDE_3_28          (0)

#endif

#ifndef AO_CAN_FILTER_MASK_3_28

#define AO_CAN_FILTER_MASK_3_28         (0)

#endif

#ifndef AO_CAN_FILTER_SID_3_28

#define AO_CAN_FILTER_SID_3_28          (0)

#endif

#ifndef AO_CAN_FILTER_EID_3_29

#define AO_CAN_FILTER_EID_3_29          (0)

#endif

#ifndef AO_CAN_FILTER_ENABLE_3_29

#define AO_CAN_FILTER_ENABLE_3_29       (false)

#endif

#ifndef AO_CAN_FILTER_FIFO_3_29

#define AO_CAN_FILTER_FIFO_3_29         (0)

#endif

#ifndef AO_CAN_FILTER_IDE_3_29

#define AO_CAN_FILTER_IDE_3_29          (0)

#endif

#ifndef AO_CAN_FILTER_MASK_3_29

#define AO_CAN_FILTER_MASK_3_29         (0)

#endif

#ifndef AO_CAN_FILTER_SID_3_29

#define AO_CAN_FILTER_SID_3_29          (0)

#endif

#ifndef AO_CAN_FILTER_EID_3_30

#define AO_CAN_FILTER_EID_3_30          (0)

#endif

#ifndef AO_CAN_FILTER_ENABLE_3_30

#define AO_CAN_FILTER_ENABLE_3_30       (false)

#endif

#ifndef AO_CAN_FILTER_FIFO_3_30

#define AO_CAN_FILTER_FIFO_3_30         (0)

#endif

#ifndef AO_CAN_FILTER_IDE_3_30

#define AO_CAN_FILTER_IDE_3_30          (0)

#endif

#ifndef AO_CAN_FILTER_MASK_3_30

#define AO_CAN_FILTER_MASK_3_30         (0)

#endif

#ifndef AO_CAN_FILTER_SID_3_30

#define AO_CAN_FILTER_SID_3_30          (0)

#endif

#ifndef AO_CAN_FILTER_EID_3_31

#define AO_CAN_FILTER_EID_3_31          (0)

#endif

#ifndef AO_CAN_FILTER_ENABLE_3_31

#define AO_CAN_FILTER_ENABLE_3_31       (false)

#endif

#ifndef AO_CAN_FILTER_FIFO_3_31

#define AO_CAN_FILTER_FIFO_3_31         (0)

#endif

#ifndef AO_CAN_FILTER_IDE_3_31

#define AO_CAN_FILTER_IDE_3_31          (0)

#endif

#ifndef AO_CAN_FILTER_MASK_3_31

#define AO_CAN_FILTER_MASK_3_31         (0)

#endif

#ifndef AO_CAN_FILTER_SID_3_31

#define AO_CAN_FILTER_SID_3_31          (0)

#endif

#ifndef AO_CAN_FILTER_MASK_EID_3_0

#define AO_CAN_FILTER_MASK_EID_3_0      (0)

#endif

#ifndef AO_CAN_FILTER_MASK_IDE_3_0

#define AO_CAN_FILTER_MASK_IDE_3_0      (0)

#endif

#ifndef AO_CAN_FILTER_MASK_SID_3_0

#define AO_CAN_FILTER_MASK_SID_3_0      (0)

#endif

#ifndef AO_CAN_FILTER_MASK_EID_3_1

#define AO_CAN_FILTER_MASK_EID_3_1      (0)

#endif

#ifndef AO_CAN_FILTER_MASK_IDE_3_1

#define AO_CAN_FILTER_MASK_IDE_3_1      (0)

#endif

#ifndef AO_CAN_FILTER_MASK_SID_3_1

#define AO_CAN_FILTER_MASK_SID_3_1      (0)

#endif

#ifndef AO_CAN_FILTER_MASK_EID_3_2

#define AO_CAN_FILTER_MASK_EID_3_2      (0)

#endif

#ifndef AO_CAN_FILTER_MASK_IDE_3_2

#define AO_CAN_FILTER_MASK_IDE_3_2      (0)

#endif

#ifndef AO_CAN_FILTER_MASK_SID_3_2

#define AO_CAN_FILTER_MASK_SID_3_2      (0)

#endif

#ifndef AO_CAN_FILTER_MASK_EID_3_3

#define AO_CAN_FILTER_MASK_EID_3_3      (0)

#endif

#ifndef AO_CAN_FILTER_MASK_IDE_3_3

#define AO_CAN_FILTER_MASK_IDE_3_3      (0)

#endif

#ifndef AO_CAN_FILTER_MASK_SID_3_3

#define AO_CAN_FILTER_MASK_SID_3_3      (0)

#endif

#ifndef AO_CAN_INVALID_3

#define AO_CAN_INVALID_3                (false)

#endif

#ifndef AO_CAN_MODE_3

#define AO_CAN_MODE_3                   (false)

#endif

#ifndef AO_CAN_OVERFLOW_3

#define AO_CAN_OVERFLOW_3               (false)

#endif

#ifndef AO_CAN_RX_3

#define AO_CAN_RX_3                     ((AO_CAN_FIFOS_RX_3) > 0 ? true : false)

#endif

#ifndef AO_CAN_SENT_3

#define AO_CAN_SENT_3                   (false)

#endif

#ifndef AO_CAN_SYSTEM_3

#define AO_CAN_SYSTEM_3                 (false)

#endif

#ifndef AO_CAN_TIMER_3

#define AO_CAN_TIMER_3                  (false)

#endif

#ifndef AO_CAN_TX_3

#define AO_CAN_TX_3                     ((AO_CAN_FIFOS_TX_3) > 0 ? true : false)

#endif

#ifndef AO_CAN_UNDERFLOW_3

#define AO_CAN_UNDERFLOW_3              (false)

#endif

#ifndef AO_CAN_WAKE_UP_3

#define AO_CAN_WAKE_UP_3                (false)

#endif

extern  ao_can_t                        ao_can_buffers_3[AO_CAN_BUFFERS_3];

extern  ao_send_obj_t                   ao_can_in_3     [AO_CAN_FIFOS_RX_3];

extern  ao_recv_obj_t                   ao_can_out_3    [AO_CAN_FIFOS_TX_3];

extern  ao_task_t                       ao_can_task_3;

void    ao_can_bus_3(                   ao_can_bus_info_t const * info);

void    ao_can_config_3();

void    ao_can_config_baud_3();

void    ao_can_config_fifos_3();

void    ao_can_config_filter_masks_3();

void    ao_can_config_filters_3();

void    ao_can_invalid_3(               ao_can_invalid_info_t const * info);

void    ao_can_listen_all_3();

void    ao_can_listen_only_3();

void    ao_can_loopback_3();

void    ao_can_mode_3(                  ao_can_mode_info_t const * info);

void    ao_can_normal_3();

void    ao_can_overflow_3(              ao_can_overflow_info_t const * info);

#ifndef ao_can_reg_3

#define ao_can_reg_3()                  ((ao_can_reg_t *) (_CAN3_BASE_ADDRESS))

#endif

void    ao_can_sent_3(                  ao_can_sent_info_t const * info);

void    ao_can_start_3();

void    ao_can_stop_3();

void    ao_can_system_3(                ao_can_system_info_t const * info);

void    ao_can_timer_3(                 ao_can_timer_info_t const * info);

void    ao_can_underflow_3(             ao_can_underflow_info_t const * info);

void    ao_can_wake_up_3(               ao_can_wake_up_info_t const * info);


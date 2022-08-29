---
author: "Stefan Wagner"
breadcrumbs: 2
date: 2022-08-29
description: "The ao_sys_xc32_pic32_can/ao_can_4.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys_xc32_pic32_can/ao_can_4.h/ 
subtitle: "<code>ao_sys_xc32_pic32_can</code>"
title: "<code>ao_can_4.h</code>"
toc: true
---

```c
#ifndef AO_CAN_4

#ifdef  _CAN4

#define AO_CAN_4                        (true)

#else

#define AO_CAN_4                        (false)

#endif

#endif

#ifndef AO_CAN_BAUD_4

#define AO_CAN_BAUD_4                   (100000)

#endif

#ifndef AO_CAN_BAUD_SAMPLE_4

#define AO_CAN_BAUD_SAMPLE_4            (85)

#endif

#ifndef AO_CAN_BAUD_SAMPLE_THRICE_4

#define AO_CAN_BAUD_SAMPLE_THRICE_4     (true)

#endif

#ifndef AO_CAN_BAUD_SJW_4

#define AO_CAN_BAUD_SJW_4               (1)

#endif

#ifndef AO_CAN_BAUD_WAKE_UP_FILTER_4

#define AO_CAN_BAUD_WAKE_UP_FILTER_4    (false)

#endif

#ifndef AO_CAN_BAUD_MAX_4

#define AO_CAN_BAUD_MAX_4               AO_CAN_BAUD_MAX(AO_SYS_CLOCK_CAN4)

#endif

#ifndef AO_CAN_BAUD_MIN_4

#define AO_CAN_BAUD_MIN_4               AO_CAN_BAUD_MIN(AO_SYS_CLOCK_CAN4)

#endif

#ifndef AO_CAN_BUFFERS_4_0

#define AO_CAN_BUFFERS_4_0              (0)

#endif

#ifndef AO_CAN_BUFFERS_4_1

#define AO_CAN_BUFFERS_4_1              (0)

#endif

#ifndef AO_CAN_BUFFERS_4_2

#define AO_CAN_BUFFERS_4_2              (0)

#endif

#ifndef AO_CAN_BUFFERS_4_3

#define AO_CAN_BUFFERS_4_3              (0)

#endif

#ifndef AO_CAN_BUFFERS_4_4

#define AO_CAN_BUFFERS_4_4              (0)

#endif

#ifndef AO_CAN_BUFFERS_4_5

#define AO_CAN_BUFFERS_4_5              (0)

#endif

#ifndef AO_CAN_BUFFERS_4_6

#define AO_CAN_BUFFERS_4_6              (0)

#endif

#ifndef AO_CAN_BUFFERS_4_7

#define AO_CAN_BUFFERS_4_7              (0)

#endif

#ifndef AO_CAN_BUFFERS_4_8

#define AO_CAN_BUFFERS_4_8              (0)

#endif

#ifndef AO_CAN_BUFFERS_4_9

#define AO_CAN_BUFFERS_4_9              (0)

#endif

#ifndef AO_CAN_BUFFERS_4_10

#define AO_CAN_BUFFERS_4_10             (0)

#endif

#ifndef AO_CAN_BUFFERS_4_11

#define AO_CAN_BUFFERS_4_11             (0)

#endif

#ifndef AO_CAN_BUFFERS_4_12

#define AO_CAN_BUFFERS_4_12             (0)

#endif

#ifndef AO_CAN_BUFFERS_4_13

#define AO_CAN_BUFFERS_4_13             (0)

#endif

#ifndef AO_CAN_BUFFERS_4_14

#define AO_CAN_BUFFERS_4_14             (0)

#endif

#ifndef AO_CAN_BUFFERS_4_15

#define AO_CAN_BUFFERS_4_15             (0)

#endif

#ifndef AO_CAN_BUFFERS_4_16

#define AO_CAN_BUFFERS_4_16             (0)

#endif

#ifndef AO_CAN_BUFFERS_4_17

#define AO_CAN_BUFFERS_4_17             (0)

#endif

#ifndef AO_CAN_BUFFERS_4_18

#define AO_CAN_BUFFERS_4_18             (0)

#endif

#ifndef AO_CAN_BUFFERS_4_19

#define AO_CAN_BUFFERS_4_19             (0)

#endif

#ifndef AO_CAN_BUFFERS_4_20

#define AO_CAN_BUFFERS_4_20             (0)

#endif

#ifndef AO_CAN_BUFFERS_4_21

#define AO_CAN_BUFFERS_4_21             (0)

#endif

#ifndef AO_CAN_BUFFERS_4_22

#define AO_CAN_BUFFERS_4_22             (0)

#endif

#ifndef AO_CAN_BUFFERS_4_23

#define AO_CAN_BUFFERS_4_23             (0)

#endif

#ifndef AO_CAN_BUFFERS_4_24

#define AO_CAN_BUFFERS_4_24             (0)

#endif

#ifndef AO_CAN_BUFFERS_4_25

#define AO_CAN_BUFFERS_4_25             (0)

#endif

#ifndef AO_CAN_BUFFERS_4_26

#define AO_CAN_BUFFERS_4_26             (0)

#endif

#ifndef AO_CAN_BUFFERS_4_27

#define AO_CAN_BUFFERS_4_27             (0)

#endif

#ifndef AO_CAN_BUFFERS_4_28

#define AO_CAN_BUFFERS_4_28             (0)

#endif

#ifndef AO_CAN_BUFFERS_4_29

#define AO_CAN_BUFFERS_4_29             (0)

#endif

#ifndef AO_CAN_BUFFERS_4_30

#define AO_CAN_BUFFERS_4_30             (0)

#endif

#ifndef AO_CAN_BUFFERS_4_31

#define AO_CAN_BUFFERS_4_31             (0)

#endif

#ifndef AO_CAN_BUFFERS_4

#define AO_CAN_BUFFERS_4                                                    \
(                                                                           \
        AO_CAN_BUFFERS_4_0  +                                               \
        AO_CAN_BUFFERS_4_1  +                                               \
        AO_CAN_BUFFERS_4_2  +                                               \
        AO_CAN_BUFFERS_4_3  +                                               \
        AO_CAN_BUFFERS_4_4  +                                               \
        AO_CAN_BUFFERS_4_5  +                                               \
        AO_CAN_BUFFERS_4_6  +                                               \
        AO_CAN_BUFFERS_4_7  +                                               \
        AO_CAN_BUFFERS_4_8  +                                               \
        AO_CAN_BUFFERS_4_9  +                                               \
        AO_CAN_BUFFERS_4_10 +                                               \
        AO_CAN_BUFFERS_4_11 +                                               \
        AO_CAN_BUFFERS_4_12 +                                               \
        AO_CAN_BUFFERS_4_13 +                                               \
        AO_CAN_BUFFERS_4_14 +                                               \
        AO_CAN_BUFFERS_4_15 +                                               \
        AO_CAN_BUFFERS_4_16 +                                               \
        AO_CAN_BUFFERS_4_17 +                                               \
        AO_CAN_BUFFERS_4_18 +                                               \
        AO_CAN_BUFFERS_4_19 +                                               \
        AO_CAN_BUFFERS_4_20 +                                               \
        AO_CAN_BUFFERS_4_21 +                                               \
        AO_CAN_BUFFERS_4_22 +                                               \
        AO_CAN_BUFFERS_4_23 +                                               \
        AO_CAN_BUFFERS_4_24 +                                               \
        AO_CAN_BUFFERS_4_25 +                                               \
        AO_CAN_BUFFERS_4_26 +                                               \
        AO_CAN_BUFFERS_4_27 +                                               \
        AO_CAN_BUFFERS_4_28 +                                               \
        AO_CAN_BUFFERS_4_29 +                                               \
        AO_CAN_BUFFERS_4_30 +                                               \
        AO_CAN_BUFFERS_4_31                                                 \
)

#endif

#ifndef AO_CAN_BUS_4

#define AO_CAN_BUS_4                    (false)

#endif

#ifndef AO_CAN_FIFOS_RX_4

#define AO_CAN_FIFOS_RX_4               (0)

#endif

#ifndef AO_CAN_FIFOS_TX_4

#define AO_CAN_FIFOS_TX_4               (0)

#endif

#ifndef AO_CAN_FIFOS_4

#define AO_CAN_FIFOS_4                  ((AO_CAN_FIFOS_RX_4) + (AO_CAN_FIFOS_TX_4))

#endif

#ifndef AO_CAN_FILTER_EID_4_0

#define AO_CAN_FILTER_EID_4_0           (0)

#endif

#ifndef AO_CAN_FILTER_ENABLE_4_0

#define AO_CAN_FILTER_ENABLE_4_0        (false)

#endif

#ifndef AO_CAN_FILTER_FIFO_4_0

#define AO_CAN_FILTER_FIFO_4_0          (0)

#endif

#ifndef AO_CAN_FILTER_IDE_4_0

#define AO_CAN_FILTER_IDE_4_0           (0)

#endif

#ifndef AO_CAN_FILTER_MASK_4_0

#define AO_CAN_FILTER_MASK_4_0          (0)

#endif

#ifndef AO_CAN_FILTER_SID_4_0

#define AO_CAN_FILTER_SID_4_0           (0)

#endif

#ifndef AO_CAN_FILTER_EID_4_1

#define AO_CAN_FILTER_EID_4_1           (0)

#endif

#ifndef AO_CAN_FILTER_ENABLE_4_1

#define AO_CAN_FILTER_ENABLE_4_1        (false)

#endif

#ifndef AO_CAN_FILTER_FIFO_4_1

#define AO_CAN_FILTER_FIFO_4_1          (0)

#endif

#ifndef AO_CAN_FILTER_IDE_4_1

#define AO_CAN_FILTER_IDE_4_1           (0)

#endif

#ifndef AO_CAN_FILTER_MASK_4_1

#define AO_CAN_FILTER_MASK_4_1          (0)

#endif

#ifndef AO_CAN_FILTER_SID_4_1

#define AO_CAN_FILTER_SID_4_1           (0)

#endif

#ifndef AO_CAN_FILTER_EID_4_2

#define AO_CAN_FILTER_EID_4_2           (0)

#endif

#ifndef AO_CAN_FILTER_ENABLE_4_2

#define AO_CAN_FILTER_ENABLE_4_2        (false)

#endif

#ifndef AO_CAN_FILTER_FIFO_4_2

#define AO_CAN_FILTER_FIFO_4_2          (0)

#endif

#ifndef AO_CAN_FILTER_IDE_4_2

#define AO_CAN_FILTER_IDE_4_2           (0)

#endif

#ifndef AO_CAN_FILTER_MASK_4_2

#define AO_CAN_FILTER_MASK_4_2          (0)

#endif

#ifndef AO_CAN_FILTER_SID_4_2

#define AO_CAN_FILTER_SID_4_2           (0)

#endif

#ifndef AO_CAN_FILTER_EID_4_3

#define AO_CAN_FILTER_EID_4_3           (0)

#endif

#ifndef AO_CAN_FILTER_ENABLE_4_3

#define AO_CAN_FILTER_ENABLE_4_3        (false)

#endif

#ifndef AO_CAN_FILTER_FIFO_4_3

#define AO_CAN_FILTER_FIFO_4_3          (0)

#endif

#ifndef AO_CAN_FILTER_IDE_4_3

#define AO_CAN_FILTER_IDE_4_3           (0)

#endif

#ifndef AO_CAN_FILTER_MASK_4_3

#define AO_CAN_FILTER_MASK_4_3          (0)

#endif

#ifndef AO_CAN_FILTER_SID_4_3

#define AO_CAN_FILTER_SID_4_3           (0)

#endif

#ifndef AO_CAN_FILTER_EID_4_4

#define AO_CAN_FILTER_EID_4_4           (0)

#endif

#ifndef AO_CAN_FILTER_ENABLE_4_4

#define AO_CAN_FILTER_ENABLE_4_4        (false)

#endif

#ifndef AO_CAN_FILTER_FIFO_4_4

#define AO_CAN_FILTER_FIFO_4_4          (0)

#endif

#ifndef AO_CAN_FILTER_IDE_4_4

#define AO_CAN_FILTER_IDE_4_4           (0)

#endif

#ifndef AO_CAN_FILTER_MASK_4_4

#define AO_CAN_FILTER_MASK_4_4          (0)

#endif

#ifndef AO_CAN_FILTER_SID_4_4

#define AO_CAN_FILTER_SID_4_4           (0)

#endif

#ifndef AO_CAN_FILTER_EID_4_5

#define AO_CAN_FILTER_EID_4_5           (0)

#endif

#ifndef AO_CAN_FILTER_ENABLE_4_5

#define AO_CAN_FILTER_ENABLE_4_5        (false)

#endif

#ifndef AO_CAN_FILTER_FIFO_4_5

#define AO_CAN_FILTER_FIFO_4_5          (0)

#endif

#ifndef AO_CAN_FILTER_IDE_4_5

#define AO_CAN_FILTER_IDE_4_5           (0)

#endif

#ifndef AO_CAN_FILTER_MASK_4_5

#define AO_CAN_FILTER_MASK_4_5          (0)

#endif

#ifndef AO_CAN_FILTER_SID_4_5

#define AO_CAN_FILTER_SID_4_5           (0)

#endif

#ifndef AO_CAN_FILTER_EID_4_6

#define AO_CAN_FILTER_EID_4_6           (0)

#endif

#ifndef AO_CAN_FILTER_ENABLE_4_6

#define AO_CAN_FILTER_ENABLE_4_6        (false)

#endif

#ifndef AO_CAN_FILTER_FIFO_4_6

#define AO_CAN_FILTER_FIFO_4_6          (0)

#endif

#ifndef AO_CAN_FILTER_IDE_4_6

#define AO_CAN_FILTER_IDE_4_6           (0)

#endif

#ifndef AO_CAN_FILTER_MASK_4_6

#define AO_CAN_FILTER_MASK_4_6          (0)

#endif

#ifndef AO_CAN_FILTER_SID_4_6

#define AO_CAN_FILTER_SID_4_6           (0)

#endif

#ifndef AO_CAN_FILTER_EID_4_7

#define AO_CAN_FILTER_EID_4_7           (0)

#endif

#ifndef AO_CAN_FILTER_ENABLE_4_7

#define AO_CAN_FILTER_ENABLE_4_7        (false)

#endif

#ifndef AO_CAN_FILTER_FIFO_4_7

#define AO_CAN_FILTER_FIFO_4_7          (0)

#endif

#ifndef AO_CAN_FILTER_IDE_4_7

#define AO_CAN_FILTER_IDE_4_7           (0)

#endif

#ifndef AO_CAN_FILTER_MASK_4_7

#define AO_CAN_FILTER_MASK_4_7          (0)

#endif

#ifndef AO_CAN_FILTER_SID_4_7

#define AO_CAN_FILTER_SID_4_7           (0)

#endif

#ifndef AO_CAN_FILTER_EID_4_8

#define AO_CAN_FILTER_EID_4_8           (0)

#endif

#ifndef AO_CAN_FILTER_ENABLE_4_8

#define AO_CAN_FILTER_ENABLE_4_8        (false)

#endif

#ifndef AO_CAN_FILTER_FIFO_4_8

#define AO_CAN_FILTER_FIFO_4_8          (0)

#endif

#ifndef AO_CAN_FILTER_IDE_4_8

#define AO_CAN_FILTER_IDE_4_8           (0)

#endif

#ifndef AO_CAN_FILTER_MASK_4_8

#define AO_CAN_FILTER_MASK_4_8          (0)

#endif

#ifndef AO_CAN_FILTER_SID_4_8

#define AO_CAN_FILTER_SID_4_8           (0)

#endif

#ifndef AO_CAN_FILTER_EID_4_9

#define AO_CAN_FILTER_EID_4_9           (0)

#endif

#ifndef AO_CAN_FILTER_ENABLE_4_9

#define AO_CAN_FILTER_ENABLE_4_9        (false)

#endif

#ifndef AO_CAN_FILTER_FIFO_4_9

#define AO_CAN_FILTER_FIFO_4_9          (0)

#endif

#ifndef AO_CAN_FILTER_IDE_4_9

#define AO_CAN_FILTER_IDE_4_9           (0)

#endif

#ifndef AO_CAN_FILTER_MASK_4_9

#define AO_CAN_FILTER_MASK_4_9          (0)

#endif

#ifndef AO_CAN_FILTER_SID_4_9

#define AO_CAN_FILTER_SID_4_9           (0)

#endif

#ifndef AO_CAN_FILTER_EID_4_10

#define AO_CAN_FILTER_EID_4_10          (0)

#endif

#ifndef AO_CAN_FILTER_ENABLE_4_10

#define AO_CAN_FILTER_ENABLE_4_10       (false)

#endif

#ifndef AO_CAN_FILTER_FIFO_4_10

#define AO_CAN_FILTER_FIFO_4_10         (0)

#endif

#ifndef AO_CAN_FILTER_IDE_4_10

#define AO_CAN_FILTER_IDE_4_10          (0)

#endif

#ifndef AO_CAN_FILTER_MASK_4_10

#define AO_CAN_FILTER_MASK_4_10         (0)

#endif

#ifndef AO_CAN_FILTER_SID_4_10

#define AO_CAN_FILTER_SID_4_10          (0)

#endif

#ifndef AO_CAN_FILTER_EID_4_11

#define AO_CAN_FILTER_EID_4_11          (0)

#endif

#ifndef AO_CAN_FILTER_ENABLE_4_11

#define AO_CAN_FILTER_ENABLE_4_11       (false)

#endif

#ifndef AO_CAN_FILTER_FIFO_4_11

#define AO_CAN_FILTER_FIFO_4_11         (0)

#endif

#ifndef AO_CAN_FILTER_IDE_4_11

#define AO_CAN_FILTER_IDE_4_11          (0)

#endif

#ifndef AO_CAN_FILTER_MASK_4_11

#define AO_CAN_FILTER_MASK_4_11         (0)

#endif

#ifndef AO_CAN_FILTER_SID_4_11

#define AO_CAN_FILTER_SID_4_11          (0)

#endif

#ifndef AO_CAN_FILTER_EID_4_12

#define AO_CAN_FILTER_EID_4_12          (0)

#endif

#ifndef AO_CAN_FILTER_ENABLE_4_12

#define AO_CAN_FILTER_ENABLE_4_12       (false)

#endif

#ifndef AO_CAN_FILTER_FIFO_4_12

#define AO_CAN_FILTER_FIFO_4_12         (0)

#endif

#ifndef AO_CAN_FILTER_IDE_4_12

#define AO_CAN_FILTER_IDE_4_12          (0)

#endif

#ifndef AO_CAN_FILTER_MASK_4_12

#define AO_CAN_FILTER_MASK_4_12         (0)

#endif

#ifndef AO_CAN_FILTER_SID_4_12

#define AO_CAN_FILTER_SID_4_12          (0)

#endif

#ifndef AO_CAN_FILTER_EID_4_13

#define AO_CAN_FILTER_EID_4_13          (0)

#endif

#ifndef AO_CAN_FILTER_ENABLE_4_13

#define AO_CAN_FILTER_ENABLE_4_13       (false)

#endif

#ifndef AO_CAN_FILTER_FIFO_4_13

#define AO_CAN_FILTER_FIFO_4_13         (0)

#endif

#ifndef AO_CAN_FILTER_IDE_4_13

#define AO_CAN_FILTER_IDE_4_13          (0)

#endif

#ifndef AO_CAN_FILTER_MASK_4_13

#define AO_CAN_FILTER_MASK_4_13         (0)

#endif

#ifndef AO_CAN_FILTER_SID_4_13

#define AO_CAN_FILTER_SID_4_13          (0)

#endif

#ifndef AO_CAN_FILTER_EID_4_14

#define AO_CAN_FILTER_EID_4_14          (0)

#endif

#ifndef AO_CAN_FILTER_ENABLE_4_14

#define AO_CAN_FILTER_ENABLE_4_14       (false)

#endif

#ifndef AO_CAN_FILTER_FIFO_4_14

#define AO_CAN_FILTER_FIFO_4_14         (0)

#endif

#ifndef AO_CAN_FILTER_IDE_4_14

#define AO_CAN_FILTER_IDE_4_14          (0)

#endif

#ifndef AO_CAN_FILTER_MASK_4_14

#define AO_CAN_FILTER_MASK_4_14         (0)

#endif

#ifndef AO_CAN_FILTER_SID_4_14

#define AO_CAN_FILTER_SID_4_14          (0)

#endif

#ifndef AO_CAN_FILTER_EID_4_15

#define AO_CAN_FILTER_EID_4_15          (0)

#endif

#ifndef AO_CAN_FILTER_ENABLE_4_15

#define AO_CAN_FILTER_ENABLE_4_15       (false)

#endif

#ifndef AO_CAN_FILTER_FIFO_4_15

#define AO_CAN_FILTER_FIFO_4_15         (0)

#endif

#ifndef AO_CAN_FILTER_IDE_4_15

#define AO_CAN_FILTER_IDE_4_15          (0)

#endif

#ifndef AO_CAN_FILTER_MASK_4_15

#define AO_CAN_FILTER_MASK_4_15         (0)

#endif

#ifndef AO_CAN_FILTER_SID_4_15

#define AO_CAN_FILTER_SID_4_15          (0)

#endif

#ifndef AO_CAN_FILTER_EID_4_16

#define AO_CAN_FILTER_EID_4_16          (0)

#endif

#ifndef AO_CAN_FILTER_ENABLE_4_16

#define AO_CAN_FILTER_ENABLE_4_16       (false)

#endif

#ifndef AO_CAN_FILTER_FIFO_4_16

#define AO_CAN_FILTER_FIFO_4_16         (0)

#endif

#ifndef AO_CAN_FILTER_IDE_4_16

#define AO_CAN_FILTER_IDE_4_16          (0)

#endif

#ifndef AO_CAN_FILTER_MASK_4_16

#define AO_CAN_FILTER_MASK_4_16         (0)

#endif

#ifndef AO_CAN_FILTER_SID_4_16

#define AO_CAN_FILTER_SID_4_16          (0)

#endif

#ifndef AO_CAN_FILTER_EID_4_17

#define AO_CAN_FILTER_EID_4_17          (0)

#endif

#ifndef AO_CAN_FILTER_ENABLE_4_17

#define AO_CAN_FILTER_ENABLE_4_17       (false)

#endif

#ifndef AO_CAN_FILTER_FIFO_4_17

#define AO_CAN_FILTER_FIFO_4_17         (0)

#endif

#ifndef AO_CAN_FILTER_IDE_4_17

#define AO_CAN_FILTER_IDE_4_17          (0)

#endif

#ifndef AO_CAN_FILTER_MASK_4_17

#define AO_CAN_FILTER_MASK_4_17         (0)

#endif

#ifndef AO_CAN_FILTER_SID_4_17

#define AO_CAN_FILTER_SID_4_17          (0)

#endif

#ifndef AO_CAN_FILTER_EID_4_18

#define AO_CAN_FILTER_EID_4_18          (0)

#endif

#ifndef AO_CAN_FILTER_ENABLE_4_18

#define AO_CAN_FILTER_ENABLE_4_18       (false)

#endif

#ifndef AO_CAN_FILTER_FIFO_4_18

#define AO_CAN_FILTER_FIFO_4_18         (0)

#endif

#ifndef AO_CAN_FILTER_IDE_4_18

#define AO_CAN_FILTER_IDE_4_18          (0)

#endif

#ifndef AO_CAN_FILTER_MASK_4_18

#define AO_CAN_FILTER_MASK_4_18         (0)

#endif

#ifndef AO_CAN_FILTER_SID_4_18

#define AO_CAN_FILTER_SID_4_18          (0)

#endif

#ifndef AO_CAN_FILTER_EID_4_19

#define AO_CAN_FILTER_EID_4_19          (0)

#endif

#ifndef AO_CAN_FILTER_ENABLE_4_19

#define AO_CAN_FILTER_ENABLE_4_19       (false)

#endif

#ifndef AO_CAN_FILTER_FIFO_4_19

#define AO_CAN_FILTER_FIFO_4_19         (0)

#endif

#ifndef AO_CAN_FILTER_IDE_4_19

#define AO_CAN_FILTER_IDE_4_19          (0)

#endif

#ifndef AO_CAN_FILTER_MASK_4_19

#define AO_CAN_FILTER_MASK_4_19         (0)

#endif

#ifndef AO_CAN_FILTER_SID_4_19

#define AO_CAN_FILTER_SID_4_19          (0)

#endif

#ifndef AO_CAN_FILTER_EID_4_20

#define AO_CAN_FILTER_EID_4_20          (0)

#endif

#ifndef AO_CAN_FILTER_ENABLE_4_20

#define AO_CAN_FILTER_ENABLE_4_20       (false)

#endif

#ifndef AO_CAN_FILTER_FIFO_4_20

#define AO_CAN_FILTER_FIFO_4_20         (0)

#endif

#ifndef AO_CAN_FILTER_IDE_4_20

#define AO_CAN_FILTER_IDE_4_20          (0)

#endif

#ifndef AO_CAN_FILTER_MASK_4_20

#define AO_CAN_FILTER_MASK_4_20         (0)

#endif

#ifndef AO_CAN_FILTER_SID_4_20

#define AO_CAN_FILTER_SID_4_20          (0)

#endif

#ifndef AO_CAN_FILTER_EID_4_21

#define AO_CAN_FILTER_EID_4_21          (0)

#endif

#ifndef AO_CAN_FILTER_ENABLE_4_21

#define AO_CAN_FILTER_ENABLE_4_21       (false)

#endif

#ifndef AO_CAN_FILTER_FIFO_4_21

#define AO_CAN_FILTER_FIFO_4_21         (0)

#endif

#ifndef AO_CAN_FILTER_IDE_4_21

#define AO_CAN_FILTER_IDE_4_21          (0)

#endif

#ifndef AO_CAN_FILTER_MASK_4_21

#define AO_CAN_FILTER_MASK_4_21         (0)

#endif

#ifndef AO_CAN_FILTER_SID_4_21

#define AO_CAN_FILTER_SID_4_21          (0)

#endif

#ifndef AO_CAN_FILTER_EID_4_22

#define AO_CAN_FILTER_EID_4_22          (0)

#endif

#ifndef AO_CAN_FILTER_ENABLE_4_22

#define AO_CAN_FILTER_ENABLE_4_22       (false)

#endif

#ifndef AO_CAN_FILTER_FIFO_4_22

#define AO_CAN_FILTER_FIFO_4_22         (0)

#endif

#ifndef AO_CAN_FILTER_IDE_4_22

#define AO_CAN_FILTER_IDE_4_22          (0)

#endif

#ifndef AO_CAN_FILTER_MASK_4_22

#define AO_CAN_FILTER_MASK_4_22         (0)

#endif

#ifndef AO_CAN_FILTER_SID_4_22

#define AO_CAN_FILTER_SID_4_22          (0)

#endif

#ifndef AO_CAN_FILTER_EID_4_23

#define AO_CAN_FILTER_EID_4_23          (0)

#endif

#ifndef AO_CAN_FILTER_ENABLE_4_23

#define AO_CAN_FILTER_ENABLE_4_23       (false)

#endif

#ifndef AO_CAN_FILTER_FIFO_4_23

#define AO_CAN_FILTER_FIFO_4_23         (0)

#endif

#ifndef AO_CAN_FILTER_IDE_4_23

#define AO_CAN_FILTER_IDE_4_23          (0)

#endif

#ifndef AO_CAN_FILTER_MASK_4_23

#define AO_CAN_FILTER_MASK_4_23         (0)

#endif

#ifndef AO_CAN_FILTER_SID_4_23

#define AO_CAN_FILTER_SID_4_23          (0)

#endif

#ifndef AO_CAN_FILTER_EID_4_24

#define AO_CAN_FILTER_EID_4_24          (0)

#endif

#ifndef AO_CAN_FILTER_ENABLE_4_24

#define AO_CAN_FILTER_ENABLE_4_24       (false)

#endif

#ifndef AO_CAN_FILTER_FIFO_4_24

#define AO_CAN_FILTER_FIFO_4_24         (0)

#endif

#ifndef AO_CAN_FILTER_IDE_4_24

#define AO_CAN_FILTER_IDE_4_24          (0)

#endif

#ifndef AO_CAN_FILTER_MASK_4_24

#define AO_CAN_FILTER_MASK_4_24         (0)

#endif

#ifndef AO_CAN_FILTER_SID_4_24

#define AO_CAN_FILTER_SID_4_24          (0)

#endif

#ifndef AO_CAN_FILTER_EID_4_25

#define AO_CAN_FILTER_EID_4_25          (0)

#endif

#ifndef AO_CAN_FILTER_ENABLE_4_25

#define AO_CAN_FILTER_ENABLE_4_25       (false)

#endif

#ifndef AO_CAN_FILTER_FIFO_4_25

#define AO_CAN_FILTER_FIFO_4_25         (0)

#endif

#ifndef AO_CAN_FILTER_IDE_4_25

#define AO_CAN_FILTER_IDE_4_25          (0)

#endif

#ifndef AO_CAN_FILTER_MASK_4_25

#define AO_CAN_FILTER_MASK_4_25         (0)

#endif

#ifndef AO_CAN_FILTER_SID_4_25

#define AO_CAN_FILTER_SID_4_25          (0)

#endif

#ifndef AO_CAN_FILTER_EID_4_26

#define AO_CAN_FILTER_EID_4_26          (0)

#endif

#ifndef AO_CAN_FILTER_ENABLE_4_26

#define AO_CAN_FILTER_ENABLE_4_26       (false)

#endif

#ifndef AO_CAN_FILTER_FIFO_4_26

#define AO_CAN_FILTER_FIFO_4_26         (0)

#endif

#ifndef AO_CAN_FILTER_IDE_4_26

#define AO_CAN_FILTER_IDE_4_26          (0)

#endif

#ifndef AO_CAN_FILTER_MASK_4_26

#define AO_CAN_FILTER_MASK_4_26         (0)

#endif

#ifndef AO_CAN_FILTER_SID_4_26

#define AO_CAN_FILTER_SID_4_26          (0)

#endif

#ifndef AO_CAN_FILTER_EID_4_27

#define AO_CAN_FILTER_EID_4_27          (0)

#endif

#ifndef AO_CAN_FILTER_ENABLE_4_27

#define AO_CAN_FILTER_ENABLE_4_27       (false)

#endif

#ifndef AO_CAN_FILTER_FIFO_4_27

#define AO_CAN_FILTER_FIFO_4_27         (0)

#endif

#ifndef AO_CAN_FILTER_IDE_4_27

#define AO_CAN_FILTER_IDE_4_27          (0)

#endif

#ifndef AO_CAN_FILTER_MASK_4_27

#define AO_CAN_FILTER_MASK_4_27         (0)

#endif

#ifndef AO_CAN_FILTER_SID_4_27

#define AO_CAN_FILTER_SID_4_27          (0)

#endif

#ifndef AO_CAN_FILTER_EID_4_28

#define AO_CAN_FILTER_EID_4_28          (0)

#endif

#ifndef AO_CAN_FILTER_ENABLE_4_28

#define AO_CAN_FILTER_ENABLE_4_28       (false)

#endif

#ifndef AO_CAN_FILTER_FIFO_4_28

#define AO_CAN_FILTER_FIFO_4_28         (0)

#endif

#ifndef AO_CAN_FILTER_IDE_4_28

#define AO_CAN_FILTER_IDE_4_28          (0)

#endif

#ifndef AO_CAN_FILTER_MASK_4_28

#define AO_CAN_FILTER_MASK_4_28         (0)

#endif

#ifndef AO_CAN_FILTER_SID_4_28

#define AO_CAN_FILTER_SID_4_28          (0)

#endif

#ifndef AO_CAN_FILTER_EID_4_29

#define AO_CAN_FILTER_EID_4_29          (0)

#endif

#ifndef AO_CAN_FILTER_ENABLE_4_29

#define AO_CAN_FILTER_ENABLE_4_29       (false)

#endif

#ifndef AO_CAN_FILTER_FIFO_4_29

#define AO_CAN_FILTER_FIFO_4_29         (0)

#endif

#ifndef AO_CAN_FILTER_IDE_4_29

#define AO_CAN_FILTER_IDE_4_29          (0)

#endif

#ifndef AO_CAN_FILTER_MASK_4_29

#define AO_CAN_FILTER_MASK_4_29         (0)

#endif

#ifndef AO_CAN_FILTER_SID_4_29

#define AO_CAN_FILTER_SID_4_29          (0)

#endif

#ifndef AO_CAN_FILTER_EID_4_30

#define AO_CAN_FILTER_EID_4_30          (0)

#endif

#ifndef AO_CAN_FILTER_ENABLE_4_30

#define AO_CAN_FILTER_ENABLE_4_30       (false)

#endif

#ifndef AO_CAN_FILTER_FIFO_4_30

#define AO_CAN_FILTER_FIFO_4_30         (0)

#endif

#ifndef AO_CAN_FILTER_IDE_4_30

#define AO_CAN_FILTER_IDE_4_30          (0)

#endif

#ifndef AO_CAN_FILTER_MASK_4_30

#define AO_CAN_FILTER_MASK_4_30         (0)

#endif

#ifndef AO_CAN_FILTER_SID_4_30

#define AO_CAN_FILTER_SID_4_30          (0)

#endif

#ifndef AO_CAN_FILTER_EID_4_31

#define AO_CAN_FILTER_EID_4_31          (0)

#endif

#ifndef AO_CAN_FILTER_ENABLE_4_31

#define AO_CAN_FILTER_ENABLE_4_31       (false)

#endif

#ifndef AO_CAN_FILTER_FIFO_4_31

#define AO_CAN_FILTER_FIFO_4_31         (0)

#endif

#ifndef AO_CAN_FILTER_IDE_4_31

#define AO_CAN_FILTER_IDE_4_31          (0)

#endif

#ifndef AO_CAN_FILTER_MASK_4_31

#define AO_CAN_FILTER_MASK_4_31         (0)

#endif

#ifndef AO_CAN_FILTER_SID_4_31

#define AO_CAN_FILTER_SID_4_31          (0)

#endif

#ifndef AO_CAN_FILTER_MASK_EID_4_0

#define AO_CAN_FILTER_MASK_EID_4_0      (0)

#endif

#ifndef AO_CAN_FILTER_MASK_IDE_4_0

#define AO_CAN_FILTER_MASK_IDE_4_0      (0)

#endif

#ifndef AO_CAN_FILTER_MASK_SID_4_0

#define AO_CAN_FILTER_MASK_SID_4_0      (0)

#endif

#ifndef AO_CAN_FILTER_MASK_EID_4_1

#define AO_CAN_FILTER_MASK_EID_4_1      (0)

#endif

#ifndef AO_CAN_FILTER_MASK_IDE_4_1

#define AO_CAN_FILTER_MASK_IDE_4_1      (0)

#endif

#ifndef AO_CAN_FILTER_MASK_SID_4_1

#define AO_CAN_FILTER_MASK_SID_4_1      (0)

#endif

#ifndef AO_CAN_FILTER_MASK_EID_4_2

#define AO_CAN_FILTER_MASK_EID_4_2      (0)

#endif

#ifndef AO_CAN_FILTER_MASK_IDE_4_2

#define AO_CAN_FILTER_MASK_IDE_4_2      (0)

#endif

#ifndef AO_CAN_FILTER_MASK_SID_4_2

#define AO_CAN_FILTER_MASK_SID_4_2      (0)

#endif

#ifndef AO_CAN_FILTER_MASK_EID_4_3

#define AO_CAN_FILTER_MASK_EID_4_3      (0)

#endif

#ifndef AO_CAN_FILTER_MASK_IDE_4_3

#define AO_CAN_FILTER_MASK_IDE_4_3      (0)

#endif

#ifndef AO_CAN_FILTER_MASK_SID_4_3

#define AO_CAN_FILTER_MASK_SID_4_3      (0)

#endif

#ifndef AO_CAN_INVALID_4

#define AO_CAN_INVALID_4                (false)

#endif

#ifndef AO_CAN_MODE_4

#define AO_CAN_MODE_4                   (false)

#endif

#ifndef AO_CAN_OVERFLOW_4

#define AO_CAN_OVERFLOW_4               (false)

#endif

#ifndef AO_CAN_RX_4

#define AO_CAN_RX_4                     ((AO_CAN_FIFOS_RX_4) > 0 ? true : false)

#endif

#ifndef AO_CAN_SENT_4

#define AO_CAN_SENT_4                   (false)

#endif

#ifndef AO_CAN_SYSTEM_4

#define AO_CAN_SYSTEM_4                 (false)

#endif

#ifndef AO_CAN_TIMER_4

#define AO_CAN_TIMER_4                  (false)

#endif

#ifndef AO_CAN_TX_4

#define AO_CAN_TX_4                     ((AO_CAN_FIFOS_TX_4) > 0 ? true : false)

#endif

#ifndef AO_CAN_UNDERFLOW_4

#define AO_CAN_UNDERFLOW_4              (false)

#endif

#ifndef AO_CAN_WAKE_UP_4

#define AO_CAN_WAKE_UP_4                (false)

#endif

extern  ao_can_t                        ao_can_buffers_4[AO_CAN_BUFFERS_4];

extern  ao_send_obj_t                   ao_can_in_4     [AO_CAN_FIFOS_RX_4];

extern  ao_recv_obj_t                   ao_can_out_4    [AO_CAN_FIFOS_TX_4];

extern  ao_task_t                       ao_can_task_4;

void    ao_can_bus_4(                   ao_can_bus_info_t const * info);

void    ao_can_config_4();

void    ao_can_config_baud_4();

void    ao_can_config_fifos_4();

void    ao_can_config_filter_masks_4();

void    ao_can_config_filters_4();

void    ao_can_invalid_4(               ao_can_invalid_info_t const * info);

void    ao_can_listen_all_4();

void    ao_can_listen_only_4();

void    ao_can_loopback_4();

void    ao_can_mode_4(                  ao_can_mode_info_t const * info);

void    ao_can_normal_4();

void    ao_can_overflow_4(              ao_can_overflow_info_t const * info);

#ifndef ao_can_reg_4

#define ao_can_reg_4()                  ((ao_can_reg_t *) (_CAN4_BASE_ADDRESS))

#endif

void    ao_can_sent_4(                  ao_can_sent_info_t const * info);

void    ao_can_start_4();

void    ao_can_stop_4();

void    ao_can_system_4(                ao_can_system_info_t const * info);

void    ao_can_timer_4(                 ao_can_timer_info_t const * info);

void    ao_can_underflow_4(             ao_can_underflow_info_t const * info);

void    ao_can_wake_up_4(               ao_can_wake_up_info_t const * info);

```

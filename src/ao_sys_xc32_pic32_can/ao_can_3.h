// ----------------------------------------------------------------------------

// MIT License

// Copyright (c) 2022 Stefan Wagner

// Permission is hereby granted, free of charge, to any person obtaining a
// copy of this software and associated documentation files (the "Software"),
// to deal in the Software without restriction, including without limitation
// the rights to use, copy, modify, merge, publish, distribute, sublicense,
// and/or sell copies of the Software, and to permit persons to whom the
// Software is furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.

// ----------------------------------------------------------------------------

// CAN 3.

// ----------------------------------------------------------------------------

#include <ao_can.h>
#include <ao_recv_obj.h>
#include <ao_send_obj.h>
#include <ao_task.h>
#include <stdbool.h>
#include <xc.h>

// ----------------------------------------------------------------------------

#ifndef AO_CAN_3

#ifdef  _CAN3

#define AO_CAN_3                        (true)

#else

#define AO_CAN_3                        (false)

#endif

#endif

// ----------------------------------------------------------------------------

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

// ----------------------------------------------------------------------------

#ifndef AO_CAN_BAUD_MAX_3

#define AO_CAN_BAUD_MAX_3               ao_can_baud_max(AO_SYS_CLOCK_CAN3)

#endif

#ifndef AO_CAN_BAUD_MIN_3

#define AO_CAN_BAUD_MIN_3               ao_can_baud_min(AO_SYS_CLOCK_CAN3)

#endif

// ----------------------------------------------------------------------------

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

// ----------------------------------------------------------------------------

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

// ----------------------------------------------------------------------------

#ifndef AO_CAN_BUS_3

#define AO_CAN_BUS_3                    (false)

#endif

// ----------------------------------------------------------------------------

#ifndef AO_CAN_FIFOS_RX_3

#define AO_CAN_FIFOS_RX_3               (0)

#endif

#ifndef AO_CAN_FIFOS_TX_3

#define AO_CAN_FIFOS_TX_3               (0)

#endif

// ----------------------------------------------------------------------------

#ifndef AO_CAN_FIFOS_3

#define AO_CAN_FIFOS_3                  ((AO_CAN_FIFOS_RX_3) + (AO_CAN_FIFOS_TX_3))

#endif

// ----------------------------------------------------------------------------

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

// ----------------------------------------------------------------------------

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

// ----------------------------------------------------------------------------

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

// ----------------------------------------------------------------------------

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

// ----------------------------------------------------------------------------

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

// ----------------------------------------------------------------------------

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

// ----------------------------------------------------------------------------

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

// ----------------------------------------------------------------------------

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

// ----------------------------------------------------------------------------

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

// ----------------------------------------------------------------------------

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

// ----------------------------------------------------------------------------

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

// ----------------------------------------------------------------------------

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

// ----------------------------------------------------------------------------

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

// ----------------------------------------------------------------------------

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

// ----------------------------------------------------------------------------

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

// ----------------------------------------------------------------------------

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

// ----------------------------------------------------------------------------

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

// ----------------------------------------------------------------------------

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

// ----------------------------------------------------------------------------

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

// ----------------------------------------------------------------------------

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

// ----------------------------------------------------------------------------

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

// ----------------------------------------------------------------------------

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

// ----------------------------------------------------------------------------

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

// ----------------------------------------------------------------------------

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

// ----------------------------------------------------------------------------

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

// ----------------------------------------------------------------------------

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

// ----------------------------------------------------------------------------

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

// ----------------------------------------------------------------------------

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

// ----------------------------------------------------------------------------

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

// ----------------------------------------------------------------------------

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

// ----------------------------------------------------------------------------

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

// ----------------------------------------------------------------------------

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

// ----------------------------------------------------------------------------

#ifndef AO_CAN_FILTER_MASK_EID_3_0

#define AO_CAN_FILTER_MASK_EID_3_0      (0)

#endif

#ifndef AO_CAN_FILTER_MASK_IDE_3_0

#define AO_CAN_FILTER_MASK_IDE_3_0      (0)

#endif

#ifndef AO_CAN_FILTER_MASK_SID_3_0

#define AO_CAN_FILTER_MASK_SID_3_0      (0)

#endif

// ----------------------------------------------------------------------------

#ifndef AO_CAN_FILTER_MASK_EID_3_1

#define AO_CAN_FILTER_MASK_EID_3_1      (0)

#endif

#ifndef AO_CAN_FILTER_MASK_IDE_3_1

#define AO_CAN_FILTER_MASK_IDE_3_1      (0)

#endif

#ifndef AO_CAN_FILTER_MASK_SID_3_1

#define AO_CAN_FILTER_MASK_SID_3_1      (0)

#endif

// ----------------------------------------------------------------------------

#ifndef AO_CAN_FILTER_MASK_EID_3_2

#define AO_CAN_FILTER_MASK_EID_3_2      (0)

#endif

#ifndef AO_CAN_FILTER_MASK_IDE_3_2

#define AO_CAN_FILTER_MASK_IDE_3_2      (0)

#endif

#ifndef AO_CAN_FILTER_MASK_SID_3_2

#define AO_CAN_FILTER_MASK_SID_3_2      (0)

#endif

// ----------------------------------------------------------------------------

#ifndef AO_CAN_FILTER_MASK_EID_3_3

#define AO_CAN_FILTER_MASK_EID_3_3      (0)

#endif

#ifndef AO_CAN_FILTER_MASK_IDE_3_3

#define AO_CAN_FILTER_MASK_IDE_3_3      (0)

#endif

#ifndef AO_CAN_FILTER_MASK_SID_3_3

#define AO_CAN_FILTER_MASK_SID_3_3      (0)

#endif

// ----------------------------------------------------------------------------

#ifndef AO_CAN_INVALID_3

#define AO_CAN_INVALID_3                (false)

#endif

// ----------------------------------------------------------------------------

#ifndef AO_CAN_MODE_3

#define AO_CAN_MODE_3                   (false)

#endif

// ----------------------------------------------------------------------------

#ifndef AO_CAN_OVERFLOW_3

#define AO_CAN_OVERFLOW_3               (false)

#endif

// ----------------------------------------------------------------------------

#ifndef AO_CAN_RX_3

#define AO_CAN_RX_3                     ((AO_CAN_FIFOS_RX_3) > 0 ? true : false)

#endif

// ----------------------------------------------------------------------------

#ifndef AO_CAN_SENT_3

#define AO_CAN_SENT_3                   (false)

#endif

// ----------------------------------------------------------------------------

#ifndef AO_CAN_SYSTEM_3

#define AO_CAN_SYSTEM_3                 (false)

#endif

// ----------------------------------------------------------------------------

#ifndef AO_CAN_TIMER_3

#define AO_CAN_TIMER_3                  (false)

#endif

// ----------------------------------------------------------------------------

#ifndef AO_CAN_TX_3

#define AO_CAN_TX_3                     ((AO_CAN_FIFOS_TX_3) > 0 ? true : false)

#endif

// ----------------------------------------------------------------------------

#ifndef AO_CAN_UNDERFLOW_3

#define AO_CAN_UNDERFLOW_3              (false)

#endif

// ----------------------------------------------------------------------------

#ifndef AO_CAN_WAKE_UP_3

#define AO_CAN_WAKE_UP_3                (false)

#endif

// ----------------------------------------------------------------------------

extern  ao_can_t                        ao_can_buffers_3[AO_CAN_BUFFERS_3];

extern  ao_send_obj_t                   ao_can_in_3     [AO_CAN_FIFOS_RX_3];

extern  ao_recv_obj_t                   ao_can_out_3    [AO_CAN_FIFOS_TX_3];

extern  ao_task_t                       ao_can_task_3;

// ----------------------------------------------------------------------------

// This event is raised, when there is an error on the CAN bus.

// This event is raised every time there is a change in the current error state
// of the CAN module with respect to the CAN network.

// The error states are tracked by the CxTREC register.

// ----------------------------------------------------------------------------

void    ao_can_bus_3(                   ao_can_bus_info_t const * info);

// ----------------------------------------------------------------------------

void    ao_can_config_3();

void    ao_can_config_baud_3();

void    ao_can_config_fifos_3();

void    ao_can_config_filter_masks_3();

void    ao_can_config_filters_3();

// ----------------------------------------------------------------------------

// This event occurs, when there was an error in the last received message or
// transmitted message.

// However, the specific error is not available to the user application.

// ----------------------------------------------------------------------------

void    ao_can_invalid_3(               ao_can_invalid_info_t const * info);

// ----------------------------------------------------------------------------

void    ao_can_listen_all_3();

// ----------------------------------------------------------------------------

void    ao_can_listen_only_3();

// ----------------------------------------------------------------------------

void    ao_can_loopback_3();

// ----------------------------------------------------------------------------

// This event occurs upon an operation mode change.

// ----------------------------------------------------------------------------

void    ao_can_mode_3(                  ao_can_mode_info_t const * info);

// ----------------------------------------------------------------------------

void    ao_can_normal_3();

// ----------------------------------------------------------------------------

// This event occurs, when a message has been received, but the designated
// fifo is full.

// ----------------------------------------------------------------------------

void    ao_can_overflow_3(              ao_can_overflow_info_t const * info);

// ----------------------------------------------------------------------------

#ifndef ao_can_reg_3

#define ao_can_reg_3()                  ((ao_can_reg_t *) (_CAN3_BASE_ADDRESS))

#endif

// ----------------------------------------------------------------------------

// This event occurs, when all messages in a fifo have been transmitted.

// ----------------------------------------------------------------------------

void    ao_can_sent_3(                  ao_can_sent_info_t const * info);

// ----------------------------------------------------------------------------

void    ao_can_start_3();

void    ao_can_stop_3();

// ----------------------------------------------------------------------------

// This event occurs due to two types of errors, addressing errors and
// bandwidth errors.

// Both of these errors are fatal. After the event was raised, the CAN module
// will be stopped and started over again.

// An addressing error will occur, if the CAN module attempts to access a
// restricted memory location. Most likely, this results from

// * an invalid fifo base address, or

// * an invalid configuration of the fifo sizes in the CxFIFOCONi registers.

// A bandwidth error will occur, when the CAN module is unable to write a
// received message to memory before the next message arrives. Most likely,
// this results from the CAN interrupt being delayed for a too long period of
// time.

// ----------------------------------------------------------------------------

void    ao_can_system_3(                ao_can_system_info_t const * info);

// ----------------------------------------------------------------------------

// This event occurs, when the CAN timestamp timer overflows.

// ----------------------------------------------------------------------------

void    ao_can_timer_3(                 ao_can_timer_info_t const * info);

// ----------------------------------------------------------------------------

// This event occurs, when a remote transmission request (RTR) has been
// received, but the designated fifo to respond automatically is empty.

// ----------------------------------------------------------------------------

void    ao_can_underflow_3(             ao_can_underflow_info_t const * info);

// ----------------------------------------------------------------------------

// This event is raised, when activity is detected on the CAN bus while the
// CAN module is in sleep mode.

// ----------------------------------------------------------------------------

void    ao_can_wake_up_3(               ao_can_wake_up_info_t const * info);

// ----------------------------------------------------------------------------

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

// UART 6.

// ----------------------------------------------------------------------------

#include <ao_recv.h>
#include <ao_send.h>
#include <ao_sys.h>
#include <ao_task.h>
#include <ao_uart.h>
#include <stdbool.h>
#include <xc.h>

// ----------------------------------------------------------------------------

// Configuration.

// ----------------------------------------------------------------------------

#ifndef AO_UART_6

#define AO_UART_6                   (false)

#endif

// ----------------------------------------------------------------------------

#ifndef AO_UART_BAUD_6

#define AO_UART_BAUD_6              (9600)

#endif

// ----------------------------------------------------------------------------

#ifndef AO_UART_DATA_BITS_PARITY_6

#define AO_UART_DATA_BITS_PARITY_6  (AO_UART_DATA_BITS_8_PARITY_NONE)

#endif

// ----------------------------------------------------------------------------

#ifndef AO_UART_ERROR_6

#define AO_UART_ERROR_6             (false)

#endif

// ----------------------------------------------------------------------------

#ifndef AO_UART_LOOPBACK_6

#define AO_UART_LOOPBACK_6          (false)

#endif

// ----------------------------------------------------------------------------

#ifndef AO_UART_RX_6

#define AO_UART_RX_6                (false)

#endif

// ----------------------------------------------------------------------------

#ifndef AO_UART_STOP_BITS_6

#define AO_UART_STOP_BITS_6         (AO_UART_STOP_BITS_ONE)

#endif

// ----------------------------------------------------------------------------

#ifndef AO_UART_TX_6

#define AO_UART_TX_6                (false)

#endif

// ----------------------------------------------------------------------------

// Constants.

// ----------------------------------------------------------------------------

#ifndef AO_UART_BAUD_MAX_6

#define AO_UART_BAUD_MAX_6          AO_UART_BAUD_MAX(AO_SYS_CLOCK_UART6)

#endif

// ----------------------------------------------------------------------------

#ifndef AO_UART_BAUD_MAX_HI_6

#define AO_UART_BAUD_MAX_HI_6       AO_UART_BAUD_MAX_HI(AO_SYS_CLOCK_UART6)

#endif

#ifndef AO_UART_BAUD_MAX_LO_6

#define AO_UART_BAUD_MAX_LO_6       AO_UART_BAUD_MAX_LO(AO_SYS_CLOCK_UART6)

#endif

// ----------------------------------------------------------------------------

#ifndef AO_UART_BAUD_MIN_6

#define AO_UART_BAUD_MIN_6          AO_UART_BAUD_MIN(AO_SYS_CLOCK_UART6)

#endif

// ----------------------------------------------------------------------------

#ifndef AO_UART_BAUD_MIN_HI_6

#define AO_UART_BAUD_MIN_HI_6       AO_UART_BAUD_MIN_HI(AO_SYS_CLOCK_UART6)

#endif

#ifndef AO_UART_BAUD_MIN_LO_6

#define AO_UART_BAUD_MIN_LO_6       AO_UART_BAUD_MIN_LO(AO_SYS_CLOCK_UART6)

#endif

// ----------------------------------------------------------------------------

#ifndef ao_uart_reg_6

#define ao_uart_reg_6()                                                     \
(                                                                           \
    (ao_uart_reg_t *)                                                       \
    (                                                                       \
        _UART6_BASE_ADDRESS                                                 \
    )                                                                       \
)

#endif

// ----------------------------------------------------------------------------

void    ao_uart_start_6();

void    ao_uart_stop_6();

// ----------------------------------------------------------------------------

void    ao_uart_error_6(            ao_uart_error_t e);

// ----------------------------------------------------------------------------

extern  ao_send_t                   ao_uart_in_6;

extern  ao_recv_t                   ao_uart_out_6;

// ----------------------------------------------------------------------------

extern  ao_task_t                   ao_uart_task_6;

// ----------------------------------------------------------------------------

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

// UART 2.

// ----------------------------------------------------------------------------

#include <ao_recv.h>
#include <ao_send.h>
#include <ao_sys.h>
#include <ao_task.h>
#include <ao_uart.h>
#include <stdbool.h>
#include <xc.h>

// ----------------------------------------------------------------------------

#ifndef AO_UART_2

#ifdef  _UART2

#define AO_UART_2                       (true)

#else

#define AO_UART_2                       (false)

#endif

#endif

// ----------------------------------------------------------------------------

#ifndef AO_UART_RX_2

#define AO_UART_RX_2                    (false)

#endif

#ifndef AO_UART_TX_2

#define AO_UART_TX_2                    (false)

#endif

// ----------------------------------------------------------------------------

#ifndef AO_UART_BAUD_2

#define AO_UART_BAUD_2                  (9600)

#endif

// ----------------------------------------------------------------------------

#ifndef AO_UART_BAUD_MAX_2

#define AO_UART_BAUD_MAX_2              ao_uart_baud_max(AO_SYS_CLOCK_U2)

#endif

#ifndef AO_UART_BAUD_MIN_2

#define AO_UART_BAUD_MIN_2              ao_uart_baud_min(AO_SYS_CLOCK_U2)

#endif

// ----------------------------------------------------------------------------

#ifndef AO_UART_BAUD_HIGH_MAX_2

#define AO_UART_BAUD_HIGH_MAX_2         ao_uart_baud_high_max(AO_SYS_CLOCK_U2)

#endif

#ifndef AO_UART_BAUD_HIGH_MIN_2

#define AO_UART_BAUD_HIGH_MIN_2         ao_uart_baud_high_min(AO_SYS_CLOCK_U2)

#endif

// ----------------------------------------------------------------------------

#ifndef AO_UART_BAUD_LOW_MAX_2

#define AO_UART_BAUD_LOW_MAX_2          ao_uart_baud_low_max(AO_SYS_CLOCK_U2)

#endif

#ifndef AO_UART_BAUD_LOW_MIN_2

#define AO_UART_BAUD_LOW_MIN_2          ao_uart_baud_low_min(AO_SYS_CLOCK_U2)

#endif

// ----------------------------------------------------------------------------

#ifndef AO_UART_DATA_BITS_PARITY_2

#define AO_UART_DATA_BITS_PARITY_2      (AO_UART_DATA_BITS_8_PARITY_NONE)

#endif

#ifndef AO_UART_STOP_BITS_2

#define AO_UART_STOP_BITS_2             (AO_UART_STOP_BITS_ONE)

#endif

// ----------------------------------------------------------------------------

#ifndef AO_UART_ERROR_2

#define AO_UART_ERROR_2                 (false)

#endif

// ----------------------------------------------------------------------------

#ifndef AO_UART_LOOPBACK_2

#define AO_UART_LOOPBACK_2              (false)

#endif

// ----------------------------------------------------------------------------

extern  ao_send_t                       ao_uart_in_2;

extern  ao_recv_t                       ao_uart_out_2;

extern  ao_task_t                       ao_uart_task_2;

// ----------------------------------------------------------------------------

#ifndef ao_uart_baud_2

#define ao_uart_baud_2(f)               ao_uart_baud(ao_uart_reg_2(), AO_SYS_CLOCK_U2, f)

#endif

#ifndef ao_uart_baud_high_2

#define ao_uart_baud_high_2(f)          ao_uart_baud_high(ao_uart_reg_2(), AO_SYS_CLOCK_U2, f)

#endif

#ifndef ao_uart_baud_low_2

#define ao_uart_baud_low_2(f)           ao_uart_baud_low(ao_uart_reg_2(), AO_SYS_CLOCK_U2, f)

#endif

// ----------------------------------------------------------------------------

void    ao_uart_config_2();

void    ao_uart_config_baud_2();

void    ao_uart_config_frame_2();

void    ao_uart_config_loopback_2();

// ----------------------------------------------------------------------------

void    ao_uart_error_2(                ao_uart_error_info_t const * info);

// ----------------------------------------------------------------------------

#ifndef ao_uart_loopback_disable_2

#define ao_uart_loopback_disable_2()    ao_uart_loopback_disable(ao_uart_reg_2())

#endif

#ifndef ao_uart_loopback_enable_2

#define ao_uart_loopback_enable_2()     ao_uart_loopback_enable(ao_uart_reg_2())

#endif

// ----------------------------------------------------------------------------

#ifndef ao_uart_reg_2

#define ao_uart_reg_2()                 ((ao_uart_reg_t *) (_UART2_BASE_ADDRESS))

#endif

// ----------------------------------------------------------------------------

void    ao_uart_start_2();

void    ao_uart_stop_2();

// ----------------------------------------------------------------------------

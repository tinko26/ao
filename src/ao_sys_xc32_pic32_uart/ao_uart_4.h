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

// UART 4.

// ----------------------------------------------------------------------------

#include <ao_recv.h>
#include <ao_send.h>
#include <ao_sys.h>
#include <ao_task.h>
#include <ao_uart.h>
#include <stdbool.h>
#include <xc.h>

// ----------------------------------------------------------------------------

#ifndef AO_UART_4

#ifdef  _UART4

#define AO_UART_4                       (true)

#else

#define AO_UART_4                       (false)

#endif

#endif

// ----------------------------------------------------------------------------

#ifndef AO_UART_RX_4

#define AO_UART_RX_4                    (false)

#endif

#ifndef AO_UART_TX_4

#define AO_UART_TX_4                    (false)

#endif

// ----------------------------------------------------------------------------

#ifndef AO_UART_BAUD_4

#define AO_UART_BAUD_4                  (9600)

#endif

// ----------------------------------------------------------------------------

#ifndef AO_UART_BAUD_MAX_4

#define AO_UART_BAUD_MAX_4              ao_uart_baud_max(AO_SYS_CLOCK_U4)

#endif

#ifndef AO_UART_BAUD_MIN_4

#define AO_UART_BAUD_MIN_4              ao_uart_baud_min(AO_SYS_CLOCK_U4)

#endif

// ----------------------------------------------------------------------------

#ifndef AO_UART_BAUD_HIGH_MAX_4

#define AO_UART_BAUD_HIGH_MAX_4         ao_uart_baud_high_max(AO_SYS_CLOCK_U4)

#endif

#ifndef AO_UART_BAUD_HIGH_MIN_4

#define AO_UART_BAUD_HIGH_MIN_4         ao_uart_baud_high_min(AO_SYS_CLOCK_U4)

#endif

// ----------------------------------------------------------------------------

#ifndef AO_UART_BAUD_LOW_MAX_4

#define AO_UART_BAUD_LOW_MAX_4          ao_uart_baud_low_max(AO_SYS_CLOCK_U4)

#endif

#ifndef AO_UART_BAUD_LOW_MIN_4

#define AO_UART_BAUD_LOW_MIN_4          ao_uart_baud_low_min(AO_SYS_CLOCK_U4)

#endif

// ----------------------------------------------------------------------------

#ifndef AO_UART_DATA_BITS_PARITY_4

#define AO_UART_DATA_BITS_PARITY_4      (AO_UART_DATA_BITS_8_PARITY_NONE)

#endif

#ifndef AO_UART_STOP_BITS_4

#define AO_UART_STOP_BITS_4             (AO_UART_STOP_BITS_ONE)

#endif

// ----------------------------------------------------------------------------

#ifndef AO_UART_ERROR_4

#define AO_UART_ERROR_4                 (false)

#endif

// ----------------------------------------------------------------------------

#ifndef AO_UART_LOOPBACK_4

#define AO_UART_LOOPBACK_4              (false)

#endif

// ----------------------------------------------------------------------------

extern  ao_send_t                       ao_uart_in_4;

extern  ao_recv_t                       ao_uart_out_4;

extern  ao_task_t                       ao_uart_task_4;

// ----------------------------------------------------------------------------

#ifndef ao_uart_baud_4

#define ao_uart_baud_4(f)               ao_uart_baud(ao_uart_reg_4(), AO_SYS_CLOCK_U4, f)

#endif

#ifndef ao_uart_baud_high_4

#define ao_uart_baud_high_4(f)          ao_uart_baud_high(ao_uart_reg_4(), AO_SYS_CLOCK_U4, f)

#endif

#ifndef ao_uart_baud_low_4

#define ao_uart_baud_low_4(f)           ao_uart_baud_low(ao_uart_reg_4(), AO_SYS_CLOCK_U4, f)

#endif

// ----------------------------------------------------------------------------

void    ao_uart_config_4();

void    ao_uart_config_baud_4();

void    ao_uart_config_frame_4();

void    ao_uart_config_loopback_4();

// ----------------------------------------------------------------------------

void    ao_uart_error_4(                ao_uart_error_info_t const * info);

// ----------------------------------------------------------------------------

#ifndef ao_uart_loopback_disable_4

#define ao_uart_loopback_disable_4()    ao_uart_loopback_disable(ao_uart_reg_4())

#endif

#ifndef ao_uart_loopback_enable_4

#define ao_uart_loopback_enable_4()     ao_uart_loopback_enable(ao_uart_reg_4())

#endif

// ----------------------------------------------------------------------------

#ifndef ao_uart_reg_4

#define ao_uart_reg_4()                 ((ao_uart_reg_t *) (_UART4_BASE_ADDRESS))

#endif

// ----------------------------------------------------------------------------

void    ao_uart_start_4();

void    ao_uart_stop_4();

// ----------------------------------------------------------------------------

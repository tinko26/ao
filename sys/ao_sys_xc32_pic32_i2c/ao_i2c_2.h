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

// I2C 2.

// ----------------------------------------------------------------------------

#include <ao_i2c.h>
#include <ao_sys.h>
#include <stdbool.h>
#include <xc.h>

// ----------------------------------------------------------------------------

#ifndef AO_I2C_2

#ifdef  _I2C2

#define AO_I2C_2                        (true)

#else

#define AO_I2C_2                        (false)

#endif

#endif

// ----------------------------------------------------------------------------

#ifndef ao_i2c_ack_2

#define ao_i2c_ack_2(t)                 ao_i2c_ack(ao_i2c_reg_2(), t)

#endif

#ifndef ao_i2c_ack_from_2

#define ao_i2c_ack_from_2(t, b)         ao_i2c_ack_from(ao_i2c_reg_2(), t, b)

#endif

#ifndef ao_i2c_ack_forever_2

#define ao_i2c_ack_forever_2()          ao_i2c_ack_forever(ao_i2c_reg_2())

#endif

// ----------------------------------------------------------------------------

#ifndef ao_i2c_acked_2

#define ao_i2c_acked_2()                ao_i2c_acked(ao_i2c_reg_2())

#endif

// ----------------------------------------------------------------------------

#ifndef ao_i2c_baud_2

#define ao_i2c_baud_2(f)                ao_i2c_baud(ao_i2c_reg_2(), AO_SYS_CLOCK_I2C2, f)

#endif

// ----------------------------------------------------------------------------

#ifndef ao_i2c_nack_2

#define ao_i2c_nack_2(t)                ao_i2c_nack(ao_i2c_reg_2(), t)

#endif

#ifndef ao_i2c_nack_from_2

#define ao_i2c_nack_from_2(t, b)        ao_i2c_nack_from(ao_i2c_reg_2(), t, b)

#endif

#ifndef ao_i2c_nack_forever_2

#define ao_i2c_nack_forever_2()         ao_i2c_nack_forever(ao_i2c_reg_2())

#endif

// ----------------------------------------------------------------------------

#ifndef ao_i2c_nacked_2

#define ao_i2c_nacked_2()               ao_i2c_nacked(ao_i2c_reg_2())

#endif

// ----------------------------------------------------------------------------

#ifndef ao_i2c_recv_2

#define ao_i2c_recv_2(v, t)             ao_i2c_recv(ao_i2c_reg_2(), v, t)

#endif

#ifndef ao_i2c_recv_from_2

#define ao_i2c_recv_from_2(v, t, b)     ao_i2c_recv_from(ao_i2c_reg_2(), v, t, b)

#endif

#ifndef ao_i2c_recv_forever_2

#define ao_i2c_recv_forever_2(v)        ao_i2c_recv_forever(ao_i2c_reg_2(), v)

#endif

// ----------------------------------------------------------------------------

#ifndef ao_i2c_reg_2

#define ao_i2c_reg_2()                  ((ao_i2c_reg_t *) (_I2C2_BASE_ADDRESS))

#endif

// ----------------------------------------------------------------------------

#ifndef ao_i2c_restart_2

#define ao_i2c_restart_2(t)             ao_i2c_restart(ao_i2c_reg_2(), t)

#endif

#ifndef ao_i2c_restart_from_2

#define ao_i2c_restart_from_2(t, b)     ao_i2c_restart_from(ao_i2c_reg_2(), t, b)

#endif

#ifndef ao_i2c_restart_forever_2

#define ao_i2c_restart_forever_2()      ao_i2c_restart_forever(ao_i2c_reg_2())

#endif

// ----------------------------------------------------------------------------

#ifndef ao_i2c_send_2

#define ao_i2c_send_2(v, t)             ao_i2c_send(ao_i2c_reg_2(), v, t)

#endif

#ifndef ao_i2c_send_from_2

#define ao_i2c_send_from_2(v, t, b)     ao_i2c_send_from(ao_i2c_reg_2(), v, t, b)

#endif

#ifndef ao_i2c_send_forever_2

#define ao_i2c_send_forever_2(v)        ao_i2c_send_forever(ao_i2c_reg_2(), v)

#endif

// ----------------------------------------------------------------------------

#ifndef ao_i2c_start_2

#define ao_i2c_start_2(t)               ao_i2c_start(ao_i2c_reg_2(), t)

#endif

#ifndef ao_i2c_start_from_2

#define ao_i2c_start_from_2(t, b)       ao_i2c_start_from(ao_i2c_reg_2(), t, b)

#endif

#ifndef ao_i2c_start_forever_2

#define ao_i2c_start_forever_2()        ao_i2c_start_forever(ao_i2c_reg_2())

#endif

// ----------------------------------------------------------------------------

#ifndef ao_i2c_stop_2

#define ao_i2c_stop_2(t)                ao_i2c_stop(ao_i2c_reg_2(), t)

#endif

#ifndef ao_i2c_stop_from_2

#define ao_i2c_stop_from_2(t, b)        ao_i2c_stop_from(ao_i2c_reg_2(), t, b)

#endif

#ifndef ao_i2c_stop_forever_2

#define ao_i2c_stop_forever_2()         ao_i2c_stop_forever(ao_i2c_reg_2())

#endif

// ----------------------------------------------------------------------------

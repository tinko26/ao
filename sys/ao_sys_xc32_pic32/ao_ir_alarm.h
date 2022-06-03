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

// Alarm interrupt.

// ----------------------------------------------------------------------------

#include <ao_ir_ct.h>
#include <xc.h>

// ----------------------------------------------------------------------------

void    ao_alarm();

// ----------------------------------------------------------------------------

#ifndef ao_alarm_disable

#define ao_alarm_disable()  ao_ir_ct_disable()

#endif

#ifndef ao_alarm_enable

#define ao_alarm_enable()   ao_ir_ct_enable()

#endif

// ----------------------------------------------------------------------------

#ifndef ao_alarm_reply

#define ao_alarm_reply()    ao_ir_ct_reply()

#endif

#ifndef ao_alarm_request

#define ao_alarm_request()  ao_ir_ct_request()

#endif

// ----------------------------------------------------------------------------

#ifndef ao_alarm_set

#define ao_alarm_set(t)     _CP0_SET_COMPARE(t)

#endif

// ----------------------------------------------------------------------------

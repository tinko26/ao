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

// Timers.

// ----------------------------------------------------------------------------

#include <ao_alarm.h>
#include <ao_func.h>
#include <ao_time.h>

// ----------------------------------------------------------------------------

typedef struct  ao_timer_t      ao_timer_t;

// ----------------------------------------------------------------------------

#ifndef AO_TIMER

#define AO_TIMER

#endif

// ----------------------------------------------------------------------------

#ifndef AO_TIMER_T

#define AO_TIMER_T

// ----------------------------------------------------------------------------

struct  ao_timer_t
{
        ao_alarm_t              alarm;

        ao_proc_t               callback;

        void *                  callback_parameter;

        ao_time_t               end;

        ao_time_t               period;
};

// ----------------------------------------------------------------------------

#endif

// ----------------------------------------------------------------------------

void    ao_timer_start(         ao_timer_t * t, ao_time_t phase, ao_time_t period);

void    ao_timer_start_from(    ao_timer_t * t, ao_time_t phase, ao_time_t period, ao_time_t beginning);

// ----------------------------------------------------------------------------

void    ao_timer_stop(          ao_timer_t * t);

// ----------------------------------------------------------------------------

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

// Alarms.

// ----------------------------------------------------------------------------

#include <ao_alarm_queue.h>
#include <ao_func.h>
#include <ao_time.h>
#include <stdbool.h>

// ----------------------------------------------------------------------------

typedef struct  ao_alarm_t      ao_alarm_t;

// ----------------------------------------------------------------------------

#ifndef AO_ALARM

#define AO_ALARM

#endif

// ----------------------------------------------------------------------------

#ifndef AO_ALARM_DELAY

#define AO_ALARM_DELAY          (AO_MILLISECONDS(100))

#endif

// ----------------------------------------------------------------------------

#ifndef AO_ALARM_UPDATE

#define AO_ALARM_UPDATE                                                     \
(                                                                           \
        (AO_TIME_MAX)    -                                                  \
        (AO_ALARM_DELAY) +                                                  \
        1                                                                   \
)

#endif

// ----------------------------------------------------------------------------

#ifndef AO_ALARM_T

#define AO_ALARM_T

// ----------------------------------------------------------------------------

struct  ao_alarm_t
{
        ao_proc_t               callback;

        void *                  callback_parameter;

        ao_time_t               end;

        ao_alarm_queue_node_t   node;

        bool                    running;
};

// ----------------------------------------------------------------------------

#endif

// ----------------------------------------------------------------------------

void    ao_alarm_start(         ao_alarm_t * a, ao_time_t timeout);

void    ao_alarm_start_from(    ao_alarm_t * a, ao_time_t timeout, ao_time_t beginning);

// ----------------------------------------------------------------------------

void    ao_alarm_stop(          ao_alarm_t * a);

// ----------------------------------------------------------------------------

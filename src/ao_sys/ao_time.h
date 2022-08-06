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

#include <ao_count.h>

// ----------------------------------------------------------------------------

typedef ao_count_t                      ao_time_t;

// ----------------------------------------------------------------------------

#ifndef AO_INFINITY

#define AO_INFINITY                     (AO_COUNT_MAX)

#endif

// ----------------------------------------------------------------------------

#ifndef AO_TIME_MAX

#define AO_TIME_MAX                     (AO_COUNT_MAX)

#endif

#ifndef AO_TIME_MIN

#define AO_TIME_MIN                     (AO_COUNT_MIN)

#endif

// ----------------------------------------------------------------------------

#ifndef ao_now

#define ao_now()                        ao_count()

#endif

// ----------------------------------------------------------------------------

#ifndef ao_days

#define ao_days(x)                      ((x) * (AO_COUNT_FREQUENCY) * (86400))

#endif

#ifndef ao_days_from_time

#define ao_days_from_time(x)            ((x) / (AO_COUNT_FREQUENCY) / (86400))

#endif

#ifndef ao_hours

#define ao_hours(x)                     ((x) * (AO_COUNT_FREQUENCY) * (3600))

#endif

#ifndef ao_hours_from_time

#define ao_hours_from_time(x)           ((x) / (AO_COUNT_FREQUENCY) / (3600))

#endif

#ifndef ao_minutes

#define ao_minutes(x)                   ((x) * (AO_COUNT_FREQUENCY) * (60))

#endif

#ifndef ao_minutes_from_time

#define ao_minutes_from_time(x)         ((x) / (AO_COUNT_FREQUENCY) / (60))

#endif

#ifndef ao_seconds

#define ao_seconds(x)                   ((x) * (AO_COUNT_FREQUENCY))

#endif

#ifndef ao_seconds_from_time

#define ao_seconds_from_time(x)         ((x) / (AO_COUNT_FREQUENCY))

#endif

#ifndef ao_milliseconds

#define ao_milliseconds(x)              ((x) * (AO_COUNT_FREQUENCY) / (1000))

#endif

#ifndef ao_milliseconds_from_time

#define ao_milliseconds_from_time(x)    ((x) * (1000) / (AO_COUNT_FREQUENCY))

#endif

#ifndef ao_microseconds

#define ao_microseconds(x)              ((x) * (AO_COUNT_FREQUENCY) / (1000000))

#endif

#ifndef ao_microseconds_from_time

#define ao_microseconds_from_time(x)    ((x) * (1000000) / (AO_COUNT_FREQUENCY))

#endif

#ifndef ao_nanoseconds

#define ao_nanoseconds(x)               ((x) * (AO_COUNT_FREQUENCY) / (1000000000))

#endif

#ifndef ao_nanoseconds_from_time

#define ao_nanoseconds_from_time(x)     ((x) * (1000000000) / (AO_COUNT_FREQUENCY))

#endif

// ----------------------------------------------------------------------------

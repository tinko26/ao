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

#ifndef AO_DAYS

#define AO_DAYS(x)                      ((x) * (AO_COUNT_FREQUENCY) * (86400))

#endif

#ifndef AO_DAYS_FROM_TIME

#define AO_DAYS_FROM_TIME(x)            ((x) / (AO_COUNT_FREQUENCY) / (86400))

#endif

#ifndef AO_HOURS

#define AO_HOURS(x)                     ((x) * (AO_COUNT_FREQUENCY) * (3600))

#endif

#ifndef AO_HOURS_FROM_TIME

#define AO_HOURS_FROM_TIME(x)           ((x) / (AO_COUNT_FREQUENCY) / (3600))

#endif

#ifndef AO_MINUTES

#define AO_MINUTES(x)                   ((x) * (AO_COUNT_FREQUENCY) * (60))

#endif

#ifndef AO_MINUTES_FROM_TIME

#define AO_MINUTES_FROM_TIME(x)         ((x) / (AO_COUNT_FREQUENCY) / (60))

#endif

#ifndef AO_SECONDS

#define AO_SECONDS(x)                   ((x) * (AO_COUNT_FREQUENCY))

#endif

#ifndef AO_SECONDS_FROM_TIME

#define AO_SECONDS_FROM_TIME(x)         ((x) / (AO_COUNT_FREQUENCY))

#endif

#ifndef AO_MILLISECONDS

#define AO_MILLISECONDS(x)              ((x) * (AO_COUNT_FREQUENCY) / (1000))

#endif

#ifndef AO_MILLISECONDS_FROM_TIME

#define AO_MILLISECONDS_FROM_TIME(x)    ((x) * (1000) / (AO_COUNT_FREQUENCY))

#endif

#ifndef AO_MICROSECONDS

#define AO_MICROSECONDS(x)              ((x) * (AO_COUNT_FREQUENCY) / (1000000))

#endif

#ifndef AO_MICROSECONDS_FROM_TIME

#define AO_MICROSECONDS_FROM_TIME(x)    ((x) * (1000000) / (AO_COUNT_FREQUENCY))

#endif

#ifndef AO_NANOSECONDS

#define AO_NANOSECONDS(x)               ((x) * (AO_COUNT_FREQUENCY) / (1000000000))

#endif

#ifndef AO_NANOSECONDS_FROM_TIME

#define AO_NANOSECONDS_FROM_TIME(x)     ((x) * (1000000000) / (AO_COUNT_FREQUENCY))

#endif

// ----------------------------------------------------------------------------

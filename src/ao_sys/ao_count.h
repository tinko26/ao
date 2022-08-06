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

// Counter.

// This module wraps around a hardware counter incrementing at a constant rate.

// The counter makes up the basis for measuring time.

// The counter and a corresponding interrupt make up the basis for alarms.

// ----------------------------------------------------------------------------

#include <stdint.h>

// ----------------------------------------------------------------------------

typedef     uint32_t            ao_count_t;

// ----------------------------------------------------------------------------

#ifndef     AO_COUNT_MAX

#define     AO_COUNT_MAX        (UINT32_MAX)

#endif

#ifndef     AO_COUNT_MIN

#define     AO_COUNT_MIN        (0)

#endif

// ----------------------------------------------------------------------------

#ifndef     AO_COUNT_FREQUENCY

#define     AO_COUNT_FREQUENCY  (0)

#endif

// ----------------------------------------------------------------------------

ao_count_t  ao_count();

// ----------------------------------------------------------------------------

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

// Mathematics.

// ----------------------------------------------------------------------------

#include <stdbool.h>

// ----------------------------------------------------------------------------

#ifndef ao_abs

#define ao_abs(x)                   ((x) < (0) ? -(x) : (x))

#endif

// ----------------------------------------------------------------------------

#ifndef ao_clamp

#define ao_clamp(x, x_min, x_max)   ((x) <= (x_min) ? (x_min) : ((x) >= (x_max) ? (x_max) : (x)))

#endif

// ----------------------------------------------------------------------------

#ifndef ao_is_equal

#define ao_is_equal(x, y)           ((x) == (y) ? true : false)

#endif

#ifndef ao_is_greater

#define ao_is_greater(x, y)         ((x) >  (y) ? true : false)

#endif

#ifndef ao_is_greater_equal

#define ao_is_greater_equal(x, y)   ((x) >= (y) ? true : false)

#endif

#ifndef ao_is_less

#define ao_is_less(x, y)            ((x) <  (y) ? true : false)

#endif

#ifndef ao_is_less_equal

#define ao_is_less_equal(x, y)      ((x) <= (y) ? true : false)

#endif

#ifndef ao_is_negative

#define ao_is_negative(x)           ((x) <  (0) ? true : false)

#endif

#ifndef ao_is_positive

#define ao_is_positive(x)           ((x) >  (0) ? true : false)

#endif

#ifndef ao_is_zero

#define ao_is_zero(x)               ((x) == (0) ? true : false)

#endif

// ----------------------------------------------------------------------------

#ifndef ao_max

#define ao_max(x, y)                ((x) >= (y) ? (x) : (y))

#endif

// ----------------------------------------------------------------------------

#ifndef ao_min

#define ao_min(x, y)                ((x) <= (y) ? (x) : (y))

#endif

// ----------------------------------------------------------------------------

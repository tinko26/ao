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

#ifndef AO_ABS

#define AO_ABS(x)                   ((x) < (0) ? -(x) : (x))

#endif

// ----------------------------------------------------------------------------

#ifndef AO_CLAMP

#define AO_CLAMP(x, x_min, x_max)                                           \
(                                                                           \
        (x) <= (x_min)                                                      \
        ? (x_min)                                                           \
        :                                                                   \
        (                                                                   \
            (x) >= (x_max)                                                  \
            ? (x_max)                                                       \
            : (x)                                                           \
        )                                                                   \
)

#endif

// ----------------------------------------------------------------------------

#ifndef AO_IS_EQUAL

#define AO_IS_EQUAL(x, y)           ((x) == (y) ? true : false)

#endif

#ifndef AO_IS_GREATER

#define AO_IS_GREATER(x, y)         ((x) >  (y) ? true : false)

#endif

#ifndef AO_IS_GREATER_EQUAL

#define AO_IS_GREATER_EQUAL(x, y)   ((x) >= (y) ? true : false)

#endif

#ifndef AO_IS_LESS

#define AO_IS_LESS(x, y)            ((x) <  (y) ? true : false)

#endif

#ifndef AO_IS_LESS_EQUAL

#define AO_IS_LESS_EQUAL(x, y)      ((x) <= (y) ? true : false)

#endif

#ifndef AO_IS_NEGATIVE

#define AO_IS_NEGATIVE(x)           ((x) <  (0) ? true : false)

#endif

#ifndef AO_IS_POSITIVE

#define AO_IS_POSITIVE(x)           ((x) >  (0) ? true : false)

#endif

#ifndef AO_IS_ZERO

#define AO_IS_ZERO(x)               ((x) == (0) ? true : false)

#endif

// ----------------------------------------------------------------------------

#ifndef AO_MAX

#define AO_MAX(x, y)                ((x) >= (y) ? (x) : (y))

#endif

#ifndef AO_MIN

#define AO_MIN(x, y)                ((x) <= (y) ? (x) : (y))

#endif

// ----------------------------------------------------------------------------

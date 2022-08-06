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

// Integers.

// ----------------------------------------------------------------------------

#include <stdint.h>

// ----------------------------------------------------------------------------

typedef     int32_t             ao_int_t;

typedef     uint32_t            ao_uint_t;

// ----------------------------------------------------------------------------

#ifndef     AO_INT_SIZE

#define     AO_INT_SIZE         (4)

#endif

#ifndef     AO_INT_SIZE_LOG

#define     AO_INT_SIZE_LOG     (2)

#endif

// ----------------------------------------------------------------------------

#ifndef     AO_INT_MAX

#define     AO_INT_MAX          (INT32_MAX)

#endif

#ifndef     AO_INT_MIN

#define     AO_INT_MIN          (INT32_MIN)

#endif

// ----------------------------------------------------------------------------

#ifndef     AO_UINT_BITS

#define     AO_UINT_BITS        (32)

#endif

#ifndef     AO_UINT_BITS_LOG

#define     AO_UINT_BITS_LOG    (5)

#endif

// ----------------------------------------------------------------------------

#ifndef     AO_UINT_SIZE

#define     AO_UINT_SIZE        (4)

#endif

#ifndef     AO_UINT_SIZE_LOG

#define     AO_UINT_SIZE_LOG    (2)

#endif

// ----------------------------------------------------------------------------

#ifndef     AO_UINT_MAX

#define     AO_UINT_MAX         (UINT32_MAX)

#endif

#ifndef     AO_UINT_MIN

#define     AO_UINT_MIN         (0)

#endif

// ----------------------------------------------------------------------------

#ifndef     ao_clo

ao_uint_t   ao_clo(ao_uint_t x);

#endif

#ifndef     ao_clz

ao_uint_t   ao_clz(ao_uint_t x);

#endif

#ifndef     ao_cto

ao_uint_t   ao_cto(ao_uint_t x);

#endif

#ifndef     ao_ctz

ao_uint_t   ao_ctz(ao_uint_t x);

#endif

// ----------------------------------------------------------------------------

#ifndef     ao_ffs

ao_uint_t   ao_ffs(ao_uint_t x);

#endif

#ifndef     ao_fls

ao_uint_t   ao_fls(ao_uint_t x);

#endif

// ----------------------------------------------------------------------------

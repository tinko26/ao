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

// Unsigned integers.

// ----------------------------------------------------------------------------

#include <stdint.h>

// ----------------------------------------------------------------------------

typedef     uint32_t            ao_uint_t;

// ----------------------------------------------------------------------------

#ifndef     AO_UINT_BITS

#define     AO_UINT_BITS        (32)

#endif

#ifndef     AO_UINT_BITS_LOG

#define     AO_UINT_BITS_LOG    (5)

#endif

// ----------------------------------------------------------------------------

#ifndef     AO_UINT_MAX

#define     AO_UINT_MAX         (UINT32_MAX)

#endif

#ifndef     AO_UINT_MIN

#define     AO_UINT_MIN         (0)

#endif

// ----------------------------------------------------------------------------

#ifndef     AO_UINT_SIZE

#define     AO_UINT_SIZE        (4)

#endif

// ----------------------------------------------------------------------------

ao_uint_t   ao_clou(ao_uint_t x);

ao_uint_t   ao_clzu(ao_uint_t x);

ao_uint_t   ao_ctou(ao_uint_t x);

ao_uint_t   ao_ctzu(ao_uint_t x);

// ----------------------------------------------------------------------------

ao_uint_t   ao_ffsu(ao_uint_t x);

ao_uint_t   ao_flsu(ao_uint_t x);

// ----------------------------------------------------------------------------

ao_uint_t   ao_log2u(ao_uint_t x);

// ----------------------------------------------------------------------------

#ifndef     ao_log2u2

#define     ao_log2u2(x)        ((x) & 0x0000000000000002U ?  1                         : 0            )

#endif

#ifndef     ao_log2u4

#define     ao_log2u4(x)        ((x) & 0x000000000000000CU ?  2 + ao_log2u2( (x) >>  2) : ao_log2u2(x) )

#endif

#ifndef     ao_log2u8

#define     ao_log2u8(x)        ((x) & 0x00000000000000F0U ?  4 + ao_log2u4( (x) >>  4) : ao_log2u4(x) )

#endif

#ifndef     ao_log2u16

#define     ao_log2u16(x)       ((x) & 0x000000000000FF00U ?  8 + ao_log2u8( (x) >>  8) : ao_log2u8(x) )

#endif

#ifndef     ao_log2u32

#define     ao_log2u32(x)       ((x) & 0x00000000FFFF0000U ? 16 + ao_log2u16((x) >> 16) : ao_log2u16(x))

#endif

#ifndef     ao_log2u64

#define     ao_log2u64(x)       ((x) & 0xFFFFFFFF00000000U ? 32 + ao_log2u32((x) >> 32) : ao_log2u32(x))

#endif

// ----------------------------------------------------------------------------

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
#include <xc.h>

// ----------------------------------------------------------------------------

typedef uint32_t            ao_uint_t;

// ----------------------------------------------------------------------------

#ifndef AO_UINT_BITS

#define AO_UINT_BITS        (32)

#endif

#ifndef AO_UINT_BITS_LOG

#define AO_UINT_BITS_LOG    (5)

#endif

// ----------------------------------------------------------------------------

#ifndef AO_UINT_MAX

#define AO_UINT_MAX         (UINT32_MAX)

#endif

#ifndef AO_UINT_MIN

#define AO_UINT_MIN         (0)

#endif

// ----------------------------------------------------------------------------

#ifndef AO_UINT_SIZE

#define AO_UINT_SIZE        (4)

#endif

// ----------------------------------------------------------------------------

#ifndef ao_clou

#define ao_clou(x)          _clo(x)

#endif

#ifndef ao_clzu

#define ao_clzu(x)          _clz(x)

#endif

#ifndef ao_ctou

#define ao_ctou(x)          _ctz(~(x))

#endif

#ifndef ao_ctzu

#define ao_ctzu(x)          _ctz(x)

#endif

// ----------------------------------------------------------------------------

#ifndef ao_ffsu

#define ao_ffsu(x)          _ctz(x)

#endif

#ifndef ao_flsu

#define ao_flsu(x)          (31 - _clz(x))

#endif

// ----------------------------------------------------------------------------

#ifndef AO_LOG2U

#define AO_LOG2U(x)         AO_LOG2U32(x)

#endif

// ----------------------------------------------------------------------------

#ifndef AO_LOG2U2

#define AO_LOG2U2(x)        ((x) & 0x0000000000000002U ?  1                         : 0            )

#endif

#ifndef AO_LOG2U4

#define AO_LOG2U4(x)        ((x) & 0x000000000000000CU ?  2 + AO_LOG2U2( (x) >>  2) : AO_LOG2U2(x) )

#endif

#ifndef AO_LOG2U8

#define AO_LOG2U8(x)        ((x) & 0x00000000000000F0U ?  4 + AO_LOG2U4( (x) >>  4) : AO_LOG2U4(x) )

#endif

#ifndef AO_LOG2U16

#define AO_LOG2U16(x)       ((x) & 0x000000000000FF00U ?  8 + AO_LOG2U8( (x) >>  8) : AO_LOG2U8(x) )

#endif

#ifndef AO_LOG2U32

#define AO_LOG2U32(x)       ((x) & 0x00000000FFFF0000U ? 16 + AO_LOG2U16((x) >> 16) : AO_LOG2U16(x))

#endif

#ifndef AO_LOG2U64

#define AO_LOG2U64(x)       ((x) & 0xFFFFFFFF00000000U ? 32 + AO_LOG2U32((x) >> 32) : AO_LOG2U32(x))

#endif

// ----------------------------------------------------------------------------

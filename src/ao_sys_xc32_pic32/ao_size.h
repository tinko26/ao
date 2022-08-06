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

// Sizes.

// This module contains functions for size_t values.

// ----------------------------------------------------------------------------

#include <ao_uint.h>

// ----------------------------------------------------------------------------

#ifndef AO_SIZE_BITS

#define AO_SIZE_BITS        (AO_UINT_BITS)

#endif

#ifndef AO_SIZE_BITS_LOG

#define AO_SIZE_BITS_LOG    (AO_UINT_BITS_LOG)

#endif

// ----------------------------------------------------------------------------

#ifndef AO_SIZE_MAX

#define AO_SIZE_MAX         (AO_UINT_MAX)

#endif

#ifndef AO_SIZE_MIN

#define AO_SIZE_MIN         (AO_UINT_MIN)

#endif

// ----------------------------------------------------------------------------

#ifndef AO_SIZE_SIZE

#define AO_SIZE_SIZE        (AO_UINT_SIZE)

#endif

// ----------------------------------------------------------------------------

#ifndef ao_cloz

#define ao_cloz(x)          ao_clo(x)

#endif

#ifndef ao_clzz

#define ao_clzz(x)          ao_clz(x)

#endif

#ifndef ao_ctoz

#define ao_ctoz(x)          ao_cto(x)

#endif

#ifndef ao_ctzz

#define ao_ctzz(x)          ao_ctz(x)

#endif

// ----------------------------------------------------------------------------

#ifndef ao_ffsz

#define ao_ffsz(x)          ao_ffs(x)

#endif

#ifndef ao_flsz

#define ao_flsz(x)          ao_fls(x)

#endif

// ----------------------------------------------------------------------------

#ifndef ao_log2z

#define ao_log2z(x)         ao_log2u(x)

#endif

// ----------------------------------------------------------------------------

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

#include <stddef.h>
#include <stdint.h>

// ----------------------------------------------------------------------------

#ifndef AO_SIZE_BITS

#define AO_SIZE_BITS        (32)

#endif

#ifndef AO_SIZE_BITS_LOG

#define AO_SIZE_BITS_LOG    (5)

#endif

// ----------------------------------------------------------------------------

#ifndef AO_SIZE_MAX

#define AO_SIZE_MAX         (SIZE_MAX)

#endif

#ifndef AO_SIZE_MIN

#define AO_SIZE_MIN         (0)

#endif

// ----------------------------------------------------------------------------

#ifndef AO_SIZE_SIZE

#define AO_SIZE_SIZE        (4)

#endif

// ----------------------------------------------------------------------------

size_t  ao_cloz(size_t x);

size_t  ao_clzz(size_t x);

size_t  ao_ctoz(size_t x);

size_t  ao_ctzz(size_t x);

// ----------------------------------------------------------------------------

size_t  ao_ffsz(size_t x);

size_t  ao_flsz(size_t x);

// ----------------------------------------------------------------------------

size_t  ao_log2z(size_t x);

// ----------------------------------------------------------------------------

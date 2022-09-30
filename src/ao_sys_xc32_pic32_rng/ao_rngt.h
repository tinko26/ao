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

// True random number generator.

// ----------------------------------------------------------------------------

#include <stdint.h>
#include <xc.h>

// ----------------------------------------------------------------------------

#ifndef ao_rngt_disable

#define ao_rngt_disable()   { RNGCONbits.TRNGEN = 0; }

#endif

#ifndef ao_rngt_enable

#define ao_rngt_enable()    { RNGCONbits.TRNGEN = 1; }

#endif

// ----------------------------------------------------------------------------

#ifndef ao_rngt_bits

#define ao_rngt_bits()      (RNGCNT)

#endif

// ----------------------------------------------------------------------------

#ifndef ao_rngt_value

#define ao_rngt_value()     (((uint64_t) RNGSEED2 << 32) | (uint64_t) RNGSEED1)

#endif

#ifndef ao_rngt_value_hi

#define ao_rngt_value_hi()  (RNGSEED2)

#endif

#ifndef ao_rngt_value_lo

#define ao_rngt_value_lo()  (RNGSEED1)

#endif

// ----------------------------------------------------------------------------

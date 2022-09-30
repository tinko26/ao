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

// Pseudo-random number generator.

// ----------------------------------------------------------------------------

#include <stdint.h>
#include <xc.h>

// ----------------------------------------------------------------------------

#ifndef ao_rngp_disable

#define ao_rngp_disable()               { RNGCONbits.PRNGEN = 0; }

#endif

#ifndef ao_rngp_enable

#define ao_rngp_enable()                { RNGCONbits.PRNGEN = 1; }

#endif

// ----------------------------------------------------------------------------

#ifndef ao_rngp_bits

#define ao_rngp_bits()                  (RNGCONbits.PLEN)

#endif

// ----------------------------------------------------------------------------

#ifndef ao_rngp_continuous_disable

#define ao_rngp_continuous_disable()    { RNGCONbits.CONT = 0; }

#endif

#ifndef ao_rngp_continuous_enable

#define ao_rngp_continuous_enable()     { RNGCONbits.CONT = 1; }

#endif

// ----------------------------------------------------------------------------

#ifndef ao_rngp_poly

#define ao_rngp_poly()                                                      \
(                                                                           \
        (                                                                   \
            (uint64_t) RNGPOLY2 << 32                                       \
        )                                                                   \
        |                                                                   \
        (uint64_t) RNGPOLY1                                                 \
)

#endif

// ----------------------------------------------------------------------------

#ifndef ao_rngp_poly_hi

#define ao_rngp_poly_hi()               (RNGPOLY2)

#endif

#ifndef ao_rngp_poly_lo

#define ao_rngp_poly_lo()               (RNGPOLY1)

#endif

// ----------------------------------------------------------------------------

#ifndef ao_rngp_seed

#define ao_rngp_seed(x)                 ao_rngp_set_value(x)

#endif

// ----------------------------------------------------------------------------

#ifndef ao_rngp_seed_hi

#define ao_rngp_seed_hi(x)              ao_rngp_set_value_hi(x)

#endif

#ifndef ao_rngp_seed_lo

#define ao_rngp_seed_lo(x)              ao_rngp_set_value_lo(x)

#endif

// ----------------------------------------------------------------------------

#ifndef ao_rngp_seed_true

#define ao_rngp_seed_true(x)            { RNGCONbits.LOAD = 1; }

#endif

// ----------------------------------------------------------------------------

#ifndef ao_rngp_set_bits

#define ao_rngp_set_bits(x)             { RNGCONbits.PLEN = (uint32_t) (x); }

#endif

// ----------------------------------------------------------------------------

#ifndef ao_rngp_set_poly

#define ao_rngp_set_poly(x)                                                 \
{                                                                           \
        RNGPOLY2 = (uint32_t) (((uint64_t) (x) >> 32) & 0xFFFFFFFFULL);     \
        RNGPOLY1 = (uint32_t) (((uint64_t) (x) >>  0) & 0xFFFFFFFFULL);     \
}

#endif

// ----------------------------------------------------------------------------

#ifndef ao_rngp_set_poly_hi

#define ao_rngp_set_poly_hi(x)          { RNGPOLY2 = (uint32_t) (x); }

#endif

#ifndef ao_rngp_set_poly_lo

#define ao_rngp_set_poly_lo(x)          { RNGPOLY1 = (uint32_t) (x); }

#endif

// ----------------------------------------------------------------------------

#ifndef ao_rngp_set_value

#define ao_rngp_set_value(x)                                                \
{                                                                           \
        RNGNUMGEN2 = (uint32_t) (((uint64_t) (x) >> 32) & 0xFFFFFFFFULL);   \
        RNGNUMGEN1 = (uint32_t) (((uint64_t) (x) >>  0) & 0xFFFFFFFFULL);   \
}

#endif

// ----------------------------------------------------------------------------

#ifndef ao_rngp_set_value_hi

#define ao_rngp_set_value_hi(x)         { RNGNUMGEN2 = (uint32_t) (x); }

#endif

#ifndef ao_rngp_set_value_lo

#define ao_rngp_set_value_lo(x)         { RNGNUMGEN1 = (uint32_t) (x); }

#endif

// ----------------------------------------------------------------------------

#ifndef ao_rngp_value

#define ao_rngp_value()                                                     \
(                                                                           \
        (                                                                   \
            (uint64_t) RNGNUMGEN2 << 32                                     \
        )                                                                   \
        |                                                                   \
        (uint64_t) RNGNUMGEN1                                               \
)

#endif

// ----------------------------------------------------------------------------

#ifndef ao_rngp_value_hi

#define ao_rngp_value_hi()              (RNGNUMGEN2)

#endif

#ifndef ao_rngp_value_lo

#define ao_rngp_value_lo()              (RNGNUMGEN1)

#endif

// ----------------------------------------------------------------------------

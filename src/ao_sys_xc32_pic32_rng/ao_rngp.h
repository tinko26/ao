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

// The pseudo-random number generator generates numbers by generating a sequence of PLEN bits.

// The numbers are generated either continuously (RNGCON.CONT = 1) or after reading the RNGNUMGEN register (RNGCON.CONT = 0).

// Each new bit is shifted into the RNGNUMGEN register from the left at position PLEN - 1.

// New bit → RNGNUMGEN2 → RNGNUMGEN1 → Old bit.

// Consequently, the generator polynomial coefficients appear in the RNGPOLY register in reverse order.

// RNGPOLY1 bit  0 is the coefficient of the term x^(PLEN).

// RNGPOLY1 bit  1 is the coefficient of the term x^(PLEN -  1).

// RNGPOLY1 bit  2 is the coefficient of the term x^(PLEN -  2).

// ...

// RNGPOLY1 bit 31 is the coefficient of the term x^(PLEN - 31).

// RNGPOLY2 bit  0 is the coefficient of the term x^(PLEN - 32).

// RNGPOLY2 bit  1 is the coefficient of the term x^(PLEN - 33).

// ...

// RNGPOLY2 bit 31 is the coefficient of the term x^(PLEN - 63).

// ----------------------------------------------------------------------------

// @seeAlso

// https://en.wikipedia.org/wiki/Linear-feedback_shift_register

// ----------------------------------------------------------------------------

// @example

// @code

/*

    // Variables.

    ao_leds_t   ld;
    ao_leds_t   le;

    uint64_t    v;

    // True random number generator.

    // Wait until 42 bits have been generated.

    ao_rngt_enable();

    while (ao_rngt_bits() < 42);

    // Pseudo-random number generator.

    // Set the number of bits to 42.

    // Set the polynomial to x^42 + x^41 + x^20 + x^19 + 1.

    ao_rngp_bits_set(42);

    ao_rngp_poly_lo_set(0x00C00003);
    ao_rngp_poly_hi_set(0x00000000);

    // Seed by loading the value from the true random number generator.

    ao_rngp_seed_true();

    ao_rngp_enable();

    // Loop.

    while (1)
    {
        // Read the random number.

        v = ao_rngp_value();

        // LEDs.

        le = AO_LEDS_NONE;
        ld = AO_LEDS_NONE;

        if (v & (1 << 0)) { le |= AO_LEDS_0; } else { ld |= AO_LEDS_0; }
        if (v & (1 << 1)) { le |= AO_LEDS_1; } else { ld |= AO_LEDS_1; }
        if (v & (1 << 2)) { le |= AO_LEDS_2; } else { ld |= AO_LEDS_2; }

        ao_leds_enable(le);
        ao_leds_disable(ld);

        // We need to wait at least 42 clock cycles before reading the next
        // random number.

        ao_spin(AO_MILLISECONDS(100));
    }

 */

// @endCode

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

#ifndef ao_rngp_bits_set

#define ao_rngp_bits_set(x)             { RNGCONbits.PLEN = (uint32_t) (x); }

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

#define ao_rngp_poly()                  (((uint64_t) RNGPOLY2 << 32) | (uint64_t) RNGPOLY1)

#endif

#ifndef ao_rngp_poly_set

#define ao_rngp_poly_set(x)                                                 \
{                                                                           \
        RNGPOLY2 = (uint32_t) (((uint64_t) (x) >> 32) & 0xFFFFFFFFULL);     \
        RNGPOLY1 = (uint32_t) (((uint64_t) (x) >>  0) & 0xFFFFFFFFULL);     \
}

#endif

// ----------------------------------------------------------------------------

#ifndef ao_rngp_poly_hi

#define ao_rngp_poly_hi()               (RNGPOLY2)

#endif

#ifndef ao_rngp_poly_hi_set

#define ao_rngp_poly_hi_set(x)          { RNGPOLY2 = (uint32_t) (x); }

#endif

// ----------------------------------------------------------------------------

#ifndef ao_rngp_poly_lo

#define ao_rngp_poly_lo()               (RNGPOLY1)

#endif

#ifndef ao_rngp_poly_lo_set

#define ao_rngp_poly_lo_set(x)          { RNGPOLY1 = (uint32_t) (x); }

#endif

// ----------------------------------------------------------------------------

#ifndef ao_rngp_seed

#define ao_rngp_seed(x)                 ao_rngp_value_set(x)

#endif

// ----------------------------------------------------------------------------

#ifndef ao_rngp_seed_hi

#define ao_rngp_seed_hi(x)              ao_rngp_value_hi_set(x)

#endif

// ----------------------------------------------------------------------------

#ifndef ao_rngp_seed_lo

#define ao_rngp_seed_lo(x)              ao_rngp_value_lo_set(x)

#endif

// ----------------------------------------------------------------------------

#ifndef ao_rngp_seed_true

#define ao_rngp_seed_true(x)            { RNGCONbits.LOAD = 1; }

#endif

// ----------------------------------------------------------------------------

#ifndef ao_rngp_value

#define ao_rngp_value()                 (((uint64_t) RNGNUMGEN2 << 32) | (uint64_t) RNGNUMGEN1)

#endif

#ifndef ao_rngp_value_set

#define ao_rngp_value_set(x)                                                \
{                                                                           \
        RNGNUMGEN2 = (uint32_t) (((uint64_t) (x) >> 32) & 0xFFFFFFFFULL);   \
        RNGNUMGEN1 = (uint32_t) (((uint64_t) (x) >>  0) & 0xFFFFFFFFULL);   \
}

#endif

// ----------------------------------------------------------------------------

#ifndef ao_rngp_value_hi

#define ao_rngp_value_hi()              (RNGNUMGEN2)

#endif

#ifndef ao_rngp_value_hi_set

#define ao_rngp_value_hi_set(x)         { RNGNUMGEN2 = (uint32_t) (x); }

#endif

// ----------------------------------------------------------------------------

#ifndef ao_rngp_value_lo

#define ao_rngp_value_lo()              (RNGNUMGEN1)

#endif

#ifndef ao_rngp_value_lo_set

#define ao_rngp_value_lo_set(x)         { RNGNUMGEN1 = (uint32_t) (x); }

#endif

// ----------------------------------------------------------------------------

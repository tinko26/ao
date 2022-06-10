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

// Linear-feedback shift register.

// This module implements LFSR in Galois configuration.

// Each new bit is shifted into   the register from the left.

// Each old bit is shifted out of the register to   the right.

// The generator polynomial coefficients appear in natural order.

// Polynomial bit 0 is the coefficient of the term x^1.

// Polynomial bit 1 is the coefficient of the term x^2.

// Polynomial bit 2 is the coefficient of the term x^3.

// Polynomial bit 3 is the coefficient of the term x^4.

// ----------------------------------------------------------------------------

// @seeAlso

// https://en.wikipedia.org/wiki/Linear-feedback_shift_register

// ----------------------------------------------------------------------------

// @example

// @code

/*

    // Variables.

    size_t      i;

    ao_leds_t   ld;
    ao_leds_t   le;

    ao_lfsr32_t r;

    uint32_t    v;

    // Let n = 18 be the length of the LFSR.

    // Set the polynomial to x^18 + x^17 + x^15 + x^2 + 1.

    r.polynomial = 0x34002;

    // Set the seed to some random non-zero value in [1, 2^18 - 1].

    r.seed = 69081;

    // Loop.

    while (1)
    {
        // Value.

        v = r.seed;

        // LEDs.

        le = AO_LEDS_NONE;
        ld = AO_LEDS_NONE;

        if (v & (1 << 0)) { le |= AO_LEDS_0; } else { ld |= AO_LEDS_0; }
        if (v & (1 << 1)) { le |= AO_LEDS_1; } else { ld |= AO_LEDS_1; }
        if (v & (1 << 2)) { le |= AO_LEDS_2; } else { ld |= AO_LEDS_2; }

        ao_leds_enable(le);
        ao_leds_disable(ld);

        // Generate 18 bits.

        for (i = 0; i < 18; i++)
        {
            ao_lfsr32(&r);
        }

        // Spin.

        ao_spin(ao_milliseconds(100));
    }

 */

// @endCode

// ----------------------------------------------------------------------------

#include <stdint.h>

// ----------------------------------------------------------------------------

typedef struct  ao_lfsr8_t  ao_lfsr8_t;

typedef struct  ao_lfsr16_t ao_lfsr16_t;

typedef struct  ao_lfsr32_t ao_lfsr32_t;

typedef struct  ao_lfsr64_t ao_lfsr64_t;

// ----------------------------------------------------------------------------

#ifndef AO_LFSR8

#define AO_LFSR8

// ----------------------------------------------------------------------------

struct  ao_lfsr8_t
{
        uint8_t             polynomial;

        uint8_t             seed;
};

// ----------------------------------------------------------------------------

#endif

#ifndef AO_LFSR16

#define AO_LFSR16

// ----------------------------------------------------------------------------

struct  ao_lfsr16_t
{
        uint16_t            polynomial;

        uint16_t            seed;
};

// ----------------------------------------------------------------------------

#endif

#ifndef AO_LFSR32

#define AO_LFSR32

// ----------------------------------------------------------------------------

struct  ao_lfsr32_t
{
        uint32_t            polynomial;

        uint32_t            seed;
};

// ----------------------------------------------------------------------------

#endif

#ifndef AO_LFSR64

#define AO_LFSR64

// ----------------------------------------------------------------------------

struct  ao_lfsr64_t
{
        uint64_t            polynomial;

        uint64_t            seed;
};

// ----------------------------------------------------------------------------

#endif

// ----------------------------------------------------------------------------

void    ao_lfsr8(           ao_lfsr8_t  * r);

void    ao_lfsr16(          ao_lfsr16_t * r);

void    ao_lfsr32(          ao_lfsr32_t * r);

void    ao_lfsr64(          ao_lfsr64_t * r);

// ----------------------------------------------------------------------------

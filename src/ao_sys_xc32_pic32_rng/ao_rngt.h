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

// The true random number generator continuously generates new bits.

// Each new bit is shifted into the RNGSEED register from the right.

// Old bit ← RNGSEED2 ← RNGSEED1 ← New bit.

// ----------------------------------------------------------------------------

// @example

// @code

/*

    // Variables.

    ao_leds_t   ld;
    ao_leds_t   le;

    uint32_t    v;

    // Enable.

    ao_rngt_enable();

    while (1)
    {
        // Wait until 3 bits have been generated.

        while (ao_rngt_bits() < 3);

        // Read the random number.

        v = ao_rngt_value_lo();

        v = v & 0b111;

        // LEDs.

        le = AO_LEDS_NONE;
        ld = AO_LEDS_NONE;

        if (v & (1 << 0)) { le |= AO_LEDS_0; } else { ld |= AO_LEDS_0; }
        if (v & (1 << 1)) { le |= AO_LEDS_1; } else { ld |= AO_LEDS_1; }
        if (v & (1 << 2)) { le |= AO_LEDS_2; } else { ld |= AO_LEDS_2; }

        ao_leds_enable(le);
        ao_leds_disable(ld);

        // Spin.

        ao_spin(AO_MILLISECONDS(100));
    }

 */

// @endCode

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

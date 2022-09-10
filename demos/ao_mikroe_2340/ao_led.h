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

// LEDs.

// ----------------------------------------------------------------------------

#include <stdint.h>
#include <xc.h>

// ----------------------------------------------------------------------------

typedef enum    ao_leds_t   ao_leds_t;

// ----------------------------------------------------------------------------

#ifndef AO_LED_COUNT

#define AO_LED_COUNT        (4)

#endif

// ----------------------------------------------------------------------------

#ifndef AO_LEDS

#define AO_LEDS

// ----------------------------------------------------------------------------

enum    ao_leds_t
{
        AO_LEDS_NONE        = (0),

        AO_LEDS_0           = (1 << 0),

        AO_LEDS_1           = (1 << 1),

        AO_LEDS_2           = (1 << 2),

        AO_LEDS_3           = (1 << 3),

        AO_LEDS_ALL         = (1 << 4) - 1,

        AO_LEDS_A           = AO_LEDS_0,

        AO_LEDS_AB          = AO_LEDS_0 | AO_LEDS_1,

        AO_LEDS_ABC         = AO_LEDS_0 | AO_LEDS_1 | AO_LEDS_2,

        AO_LEDS_ABCD        = AO_LEDS_0 | AO_LEDS_1 | AO_LEDS_2 | AO_LEDS_3,

        AO_LEDS_ABD         = AO_LEDS_0 | AO_LEDS_1 | AO_LEDS_3,

        AO_LEDS_AC          = AO_LEDS_0 | AO_LEDS_2,

        AO_LEDS_ACD         = AO_LEDS_0 | AO_LEDS_2 | AO_LEDS_3,

        AO_LEDS_AD          = AO_LEDS_0 | AO_LEDS_3,

        AO_LEDS_B           = AO_LEDS_1,

        AO_LEDS_BC          = AO_LEDS_1 | AO_LEDS_2,

        AO_LEDS_BCD         = AO_LEDS_1 | AO_LEDS_2 | AO_LEDS_3,

        AO_LEDS_BD          = AO_LEDS_1 | AO_LEDS_3,

        AO_LEDS_C           = AO_LEDS_2,

        AO_LEDS_CD          = AO_LEDS_2 | AO_LEDS_3,

        AO_LEDS_D           = AO_LEDS_3
};

// ----------------------------------------------------------------------------

#endif

// ----------------------------------------------------------------------------

// Gets the LEDs that are enabled.

#ifndef ao_leds

#define ao_leds()                                                           \
(                                                                           \
{                                                                           \
        uint32_t a = LATA;                                                  \
        uint32_t e = LATE;                                                  \
                                                                            \
        (ao_leds_t)                                                         \
        (                                                                   \
            ((a >> 6) & 0x3) |                                              \
            ((e << 2) & 0xC)                                                \
        );                                                                  \
}                                                                           \
)

#endif

// ----------------------------------------------------------------------------

#ifndef ao_leds_disable

#define ao_leds_disable(leds)                                               \
{                                                                           \
        LATACLR = ((leds) & 3) << 6;                                        \
        LATECLR = ((leds) >> 2) & 3;                                        \
}

#endif

#ifndef ao_leds_enable

#define ao_leds_enable(leds)                                                \
{                                                                           \
        LATASET = ((leds) & 3) << 6;                                        \
        LATESET = ((leds) >> 2) & 3;                                        \
}

#endif

#ifndef ao_leds_toggle

#define ao_leds_toggle(leds)                                                \
{                                                                           \
        LATAINV = ((leds) & 3) << 6;                                        \
        LATEINV = ((leds) >> 2) & 3;                                        \
}

#endif

// ----------------------------------------------------------------------------

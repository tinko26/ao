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

#include <ao.h>
#include <stddef.h>

// ----------------------------------------------------------------------------

void main()
{
    ao_boot();

    ao_task_set_prio(&ao_mikroe_2935_task_a, 1);

    ao_mikroe_2935_start(AO_MIKROE_A);

    while (1) { }
}

// ----------------------------------------------------------------------------

void ao_mikroe_2935(size_t i, ao_mikroe_2935_t const * M)
{
    // Variables.

    (void) i;

    ao_float_t d, r, x, y;


    // Ready.

    if (M->ready)
    {
        // Magnetic field strengths.

        x = M->x;

        y = M->y;


        // Angle.

        r = ao_atan2(y, x);

        d = ao_rad2deg(r);

        d = d + 180;


        // White arrow on click board pointing ...

        // ... north.

        if (d <= 45)
        {
            ao_leds_disable(AO_LEDS_ACD);

            ao_leds_enable(AO_LEDS_B);
        }


        // ... west.

        else if (d <= 135)
        {
            ao_leds_disable(AO_LEDS_ABD);

            ao_leds_enable(AO_LEDS_C);
        }


        // ... south.

        else if (d <= 225)
        {
            ao_leds_disable(AO_LEDS_ABC);

            ao_leds_enable(AO_LEDS_D);
        }


        // ... east.

        else if (d <= 315)
        {
            ao_leds_disable(AO_LEDS_BCD);

            ao_leds_enable(AO_LEDS_A);
        }


        // ... north.

        else
        {
            ao_leds_disable(AO_LEDS_ACD);

            ao_leds_enable(AO_LEDS_B);
        }
    }
}

// ----------------------------------------------------------------------------

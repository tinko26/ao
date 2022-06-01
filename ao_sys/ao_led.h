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

typedef     enum    ao_leds_t   ao_leds_t;

// ----------------------------------------------------------------------------

#ifndef     AO_LED_COUNT

#define     AO_LED_COUNT        (0)

#endif

// ----------------------------------------------------------------------------

#ifndef     AO_LEDS

#define     AO_LEDS

// ----------------------------------------------------------------------------

enum        ao_leds_t
{
            AO_LEDS_ALL         = 0,

            AO_LEDS_NONE        = 0
};

// ----------------------------------------------------------------------------

#endif

// ----------------------------------------------------------------------------

// Gets the LEDs that are enabled.

ao_leds_t   ao_leds();

// ----------------------------------------------------------------------------

void        ao_leds_disable(    ao_leds_t x);

void        ao_leds_enable(     ao_leds_t x);

void        ao_leds_toggle(     ao_leds_t x);

// ----------------------------------------------------------------------------

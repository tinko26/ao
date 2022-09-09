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

// Buttons.

// ----------------------------------------------------------------------------

#include <xc.h>

// ----------------------------------------------------------------------------

typedef enum    ao_buttons_t    ao_buttons_t;

// ----------------------------------------------------------------------------

#ifndef AO_BUTTON_COUNT

#define AO_BUTTON_COUNT         (2)

#endif

// ----------------------------------------------------------------------------

#ifndef AO_BUTTONS

#define AO_BUTTONS

// ----------------------------------------------------------------------------

enum    ao_buttons_t
{
        AO_BUTTONS_0            = (1 << 0),

        AO_BUTTONS_1            = (1 << 1),

        AO_BUTTONS_ALL          = AO_BUTTONS_0 | AO_BUTTONS_1,

        AO_BUTTONS_NONE         = 0
};

// ----------------------------------------------------------------------------

#endif

// ----------------------------------------------------------------------------

// Gets the buttons that are down.

#ifndef ao_buttons

#define ao_buttons()                                                        \
(                                                                           \
        (ao_buttons_t)                                                      \
        (                                                                   \
            (((~PORTB) << 1) & 2) |                                         \
            (((~PORTC) >> 3) & 1)                                           \
        )                                                                   \
)

#endif

// ----------------------------------------------------------------------------

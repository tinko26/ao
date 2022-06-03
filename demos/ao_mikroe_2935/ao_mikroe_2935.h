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

// MikroElektronika.

// GeoMagnetic Click.

// ----------------------------------------------------------------------------

// @seeAlso

// https://www.mikroe.com/geomagnetic-click

// ----------------------------------------------------------------------------

#include <ao_float.h>
#include <stdbool.h>
#include <stddef.h>

// ----------------------------------------------------------------------------

typedef struct  ao_mikroe_2935_t    ao_mikroe_2935_t;

// ----------------------------------------------------------------------------

#ifndef AO_MIKROE_2935

#define AO_MIKROE_2935

// ----------------------------------------------------------------------------

struct  ao_mikroe_2935_t
{
        bool                        ready;

        ao_float_t                  x;      // µT.

        ao_float_t                  y;      // µT.

        ao_float_t                  z;      // µT.
};

// ----------------------------------------------------------------------------

#endif

// ----------------------------------------------------------------------------

void    ao_mikroe_2935(             size_t i, ao_mikroe_2935_t const * x);

// ----------------------------------------------------------------------------

void    ao_mikroe_2935_start(       size_t i);

void    ao_mikroe_2935_stop(        size_t i);

// ----------------------------------------------------------------------------

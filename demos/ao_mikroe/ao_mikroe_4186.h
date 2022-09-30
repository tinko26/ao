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

// EXPAND 5 Click.

// ----------------------------------------------------------------------------

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// ----------------------------------------------------------------------------

typedef     union   ao_mikroe_4186_t            ao_mikroe_4186_t;

typedef     union   ao_mikroe_4186_port_t       ao_mikroe_4186_port_t;

// ----------------------------------------------------------------------------

#ifndef     AO_MIKROE_4186

#define     AO_MIKROE_4186                      (false)

#endif

// ----------------------------------------------------------------------------

#ifndef     AO_MIKROE_4186_PORT_T

#define     AO_MIKROE_4186_PORT_T

// ----------------------------------------------------------------------------

union       ao_mikroe_4186_port_t
{
            uint8_t                             pins;

            struct
            {
                uint8_t                         pin0    : 1;

                uint8_t                         pin1    : 1;

                uint8_t                         pin2    : 1;

                uint8_t                         pin3    : 1;

                uint8_t                         pin4    : 1;

                uint8_t                         pin5    : 1;

                uint8_t                         pin6    : 1;

                uint8_t                         pin7    : 1;
            };
};

// ----------------------------------------------------------------------------

#endif

#ifndef     AO_MIKROE_4186_T

#define     AO_MIKROE_4186_T

// ----------------------------------------------------------------------------

union       ao_mikroe_4186_t
{
            uint32_t                            ports;

            struct
            {
                ao_mikroe_4186_port_t           port0;

                ao_mikroe_4186_port_t           port1;

                ao_mikroe_4186_port_t           port2;
            };
};

// ----------------------------------------------------------------------------

#endif

// ----------------------------------------------------------------------------

uint32_t    ao_mikroe_4186_get_config(          size_t i);

uint32_t    ao_mikroe_4186_get_input(           size_t i);

uint32_t    ao_mikroe_4186_get_output(          size_t i);

uint32_t    ao_mikroe_4186_get_polarity(        size_t i);

// ----------------------------------------------------------------------------

uint8_t     ao_mikroe_4186_get_port_config(     size_t i, size_t p);

uint8_t     ao_mikroe_4186_get_port_input(      size_t i, size_t p);

uint8_t     ao_mikroe_4186_get_port_output(     size_t i, size_t p);

uint8_t     ao_mikroe_4186_get_port_polarity(   size_t i, size_t p);

// ----------------------------------------------------------------------------

void        ao_mikroe_4186_int(                 size_t i);

// ----------------------------------------------------------------------------

void        ao_mikroe_4186_reset(               size_t i);

// ----------------------------------------------------------------------------

void        ao_mikroe_4186_set_config(          size_t i, uint32_t x);

void        ao_mikroe_4186_set_input(           size_t i, uint32_t x);

void        ao_mikroe_4186_set_output(          size_t i, uint32_t x);

void        ao_mikroe_4186_set_polarity(        size_t i, uint32_t x);

// ----------------------------------------------------------------------------

void        ao_mikroe_4186_set_port_config(     size_t i, size_t p, uint8_t x);

void        ao_mikroe_4186_set_port_input(      size_t i, size_t p, uint8_t x);

void        ao_mikroe_4186_set_port_output(     size_t i, size_t p, uint8_t x);

void        ao_mikroe_4186_set_port_polarity(   size_t i, size_t p, uint8_t x);

// ----------------------------------------------------------------------------

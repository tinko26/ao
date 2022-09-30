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

// Converting numbers to string.

// ----------------------------------------------------------------------------

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// ----------------------------------------------------------------------------

typedef struct  ao_print_t  ao_print_t;

// ----------------------------------------------------------------------------

#ifndef AO_PRINT

#define AO_PRINT

#endif

// ----------------------------------------------------------------------------

#ifndef AO_PRINT_T

#define AO_PRINT_T

// ----------------------------------------------------------------------------

struct  ao_print_t
{
        size_t              digits_exponent;

        size_t              digits_fractional;

        size_t              digits_integral;

        size_t              precision;

        size_t              radix;

        bool                right;

        bool                sign;

        bool                sign_exponent;

        bool                sign_space;

        bool                uppercase;

        size_t              width;
};

// ----------------------------------------------------------------------------

#endif

// ----------------------------------------------------------------------------

size_t  ao_printed(         char * s, size_t n, ao_print_t const * o, double const * v);

size_t  ao_printef(         char * s, size_t n, ao_print_t const * o, float const * v);

size_t  ao_printel(         char * s, size_t n, ao_print_t const * o, long double const * v);

// ----------------------------------------------------------------------------

size_t  ao_printfd(         char * s, size_t n, ao_print_t const * o, double const * v);

size_t  ao_printff(         char * s, size_t n, ao_print_t const * o, float const * v);

size_t  ao_printfl(         char * s, size_t n, ao_print_t const * o, long double const * v);

// ----------------------------------------------------------------------------

size_t  ao_printi8(         char * s, size_t n, ao_print_t const * o, int8_t const * v);

size_t  ao_printi16(        char * s, size_t n, ao_print_t const * o, int16_t const * v);

size_t  ao_printi32(        char * s, size_t n, ao_print_t const * o, int32_t const * v);

size_t  ao_printi64(        char * s, size_t n, ao_print_t const * o, int64_t const * v);

// ----------------------------------------------------------------------------

size_t  ao_printu8(         char * s, size_t n, ao_print_t const * o, uint8_t const * v);

size_t  ao_printu16(        char * s, size_t n, ao_print_t const * o, uint16_t const * v);

size_t  ao_printu32(        char * s, size_t n, ao_print_t const * o, uint32_t const * v);

size_t  ao_printu64(        char * s, size_t n, ao_print_t const * o, uint64_t const * v);

// ----------------------------------------------------------------------------

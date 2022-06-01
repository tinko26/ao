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

// Printing numbers.

// ----------------------------------------------------------------------------

#include <ao_float.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// ----------------------------------------------------------------------------

typedef struct  ao_print_t  ao_print_t;

// ----------------------------------------------------------------------------

#ifndef AO_PRINT

#define AO_PRINT

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

// @brief

// Prints a floating point number in scientific notation.

// @param [out] s           String.
// @param [in]  n           Maximum number of characters to write.
// @param [in]  o           Options.
// @param [in]  v           Value.

// @return

// On success, the number of characters written.

// On failure, zero.

size_t  ao_print_e(         char * s, size_t n, ao_print_t const * o, ao_float_t  const * v);

size_t  ao_print_e_d(       char * s, size_t n, ao_print_t const * o, double      const * v);

size_t  ao_print_e_f(       char * s, size_t n, ao_print_t const * o, float       const * v);

size_t  ao_print_e_l(       char * s, size_t n, ao_print_t const * o, long double const * v);

// ----------------------------------------------------------------------------

// @brief

// Prints a floating point number.

// @param [out] s           String.
// @param [in]  n           Maximum number of characters to write.
// @param [in]  o           Options.
// @param [in]  v           Value.

// @return

// On success, the number of characters written.

// On failure, zero.

size_t  ao_print_f(         char * s, size_t n, ao_print_t const * o, ao_float_t  const * v);

size_t  ao_print_f_d(       char * s, size_t n, ao_print_t const * o, double      const * v);

size_t  ao_print_f_f(       char * s, size_t n, ao_print_t const * o, float       const * v);

size_t  ao_print_f_l(       char * s, size_t n, ao_print_t const * o, long double const * v);

// ----------------------------------------------------------------------------

// @brief

// Prints a signed integer.

// @param [out] s           String.
// @param [in]  n           Maximum number of characters to write.
// @param [in]  o           Options.
// @param [in]  v           Value.

// @return

// On success, the number of characters written.

// On failure, zero.

size_t  ao_print_i_i8(      char * s, size_t n, ao_print_t const * o, int8_t  const * v);

size_t  ao_print_i_i16(     char * s, size_t n, ao_print_t const * o, int16_t const * v);

size_t  ao_print_i_i32(     char * s, size_t n, ao_print_t const * o, int32_t const * v);

size_t  ao_print_i_i64(     char * s, size_t n, ao_print_t const * o, int64_t const * v);

// ----------------------------------------------------------------------------

// @brief

// Prints an unsigned integer.

// @param [out] s           String.
// @param [in]  n           Maximum number of characters to write.
// @param [in]  o           Options.
// @param [in]  v           Value.

// @return

// On success, the number of characters written.

// On failure, zero.

size_t  ao_print_i_u8(      char * s, size_t n, ao_print_t const * o, uint8_t  const * v);

size_t  ao_print_i_u16(     char * s, size_t n, ao_print_t const * o, uint16_t const * v);

size_t  ao_print_i_u32(     char * s, size_t n, ao_print_t const * o, uint32_t const * v);

size_t  ao_print_i_u64(     char * s, size_t n, ao_print_t const * o, uint64_t const * v);

// ----------------------------------------------------------------------------

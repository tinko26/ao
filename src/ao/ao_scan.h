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

// Scanning numbers.

// ----------------------------------------------------------------------------

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// ----------------------------------------------------------------------------

typedef struct  ao_scan_t   ao_scan_t;

// ----------------------------------------------------------------------------

#ifndef AO_SCAN

#define AO_SCAN

// ----------------------------------------------------------------------------

struct  ao_scan_t
{
        size_t      radix;

        bool        seek;
};

// ----------------------------------------------------------------------------

#endif

// ----------------------------------------------------------------------------

// @brief

// Scans a decimal floating point number.

// @param [in]  s   String.
// @param [in]  n   Maximum number of characters to read.
// @param [in]  o   Options.
// @param [out] v   Value.

// @return

// On success, the number of characters read.

// On failure, zero.

size_t  ao_scand(   char const * s, size_t n, ao_scan_t const * o, double      * v);

size_t  ao_scanf(   char const * s, size_t n, ao_scan_t const * o, float       * v);

size_t  ao_scanl(   char const * s, size_t n, ao_scan_t const * o, long double * v);

// ----------------------------------------------------------------------------

// @brief

// Scans a signed integer.

// @param [in]  s   String.
// @param [in]  n   Maximum number of characters to read.
// @param [in]  o   Options.
// @param [out] v   Value.

// @return

// On success, the number of characters read.

// On failure, zero.

size_t  ao_scani8(  char const * s, size_t n, ao_scan_t const * o, int8_t  * v);

size_t  ao_scani16( char const * s, size_t n, ao_scan_t const * o, int16_t * v);

size_t  ao_scani32( char const * s, size_t n, ao_scan_t const * o, int32_t * v);

size_t  ao_scani64( char const * s, size_t n, ao_scan_t const * o, int64_t * v);

// ----------------------------------------------------------------------------

// @brief

// Scans an unsigned integer.

// @param [in]  s   String.
// @param [in]  n   Maximum number of characters to read.
// @param [in]  o   Options.
// @param [out] v   Value.

// @return

// On success, the number of characters read.

// On failure, zero.

size_t  ao_scanu8(  char const * s, size_t n, ao_scan_t const * o, uint8_t  * v);

size_t  ao_scanu16( char const * s, size_t n, ao_scan_t const * o, uint16_t * v);

size_t  ao_scanu32( char const * s, size_t n, ao_scan_t const * o, uint32_t * v);

size_t  ao_scanu64( char const * s, size_t n, ao_scan_t const * o, uint64_t * v);

// ----------------------------------------------------------------------------

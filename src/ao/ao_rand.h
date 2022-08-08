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

// Random value generators.

// ----------------------------------------------------------------------------

#include <stdbool.h>
#include <stdint.h>

// ----------------------------------------------------------------------------

typedef bool        (*  ao_randb_t)    ();

// ----------------------------------------------------------------------------

typedef double      (*  ao_randd_t)    ();

// ----------------------------------------------------------------------------

typedef float       (*  ao_randf_t)    ();

// ----------------------------------------------------------------------------

typedef int8_t      (*  ao_randi8_t)   ();

typedef int16_t     (*  ao_randi16_t)  ();

typedef int32_t     (*  ao_randi32_t)  ();

typedef int64_t     (*  ao_randi64_t)  ();

// ----------------------------------------------------------------------------

typedef long double (*  ao_randl_t)    ();

// ----------------------------------------------------------------------------

typedef uint8_t     (*  ao_randu8_t)   ();

typedef uint16_t    (*  ao_randu16_t)  ();

typedef uint32_t    (*  ao_randu32_t)  ();

typedef uint64_t    (*  ao_randu64_t)  ();

// ----------------------------------------------------------------------------

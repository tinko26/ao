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

// Allocator 2.

// Allocator based on the two-level segregated fit algorithm.

// ----------------------------------------------------------------------------

#include <ao_size.h>
#include <stdbool.h>
#include <stddef.h>

// ----------------------------------------------------------------------------

#ifndef AO_ALLOC_2

#define AO_ALLOC_2

#endif

// ----------------------------------------------------------------------------

#ifndef AO_ALLOC_ALLOCATED

#define AO_ALLOC_ALLOCATED          (false)

#endif

#ifndef AO_ALLOC_ALLOCATED_MAX

#define AO_ALLOC_ALLOCATED_MAX      (false)

#endif

// ----------------------------------------------------------------------------

#ifndef AO_ALLOC_FREE

#define AO_ALLOC_FREE               (false)

#endif

#ifndef AO_ALLOC_FREE_MIN

#define AO_ALLOC_FREE_MIN           (false)

#endif

// ----------------------------------------------------------------------------

#ifndef AO_ALLOC_SEGREGATION

#define AO_ALLOC_SEGREGATION        (3)

#endif

// ----------------------------------------------------------------------------

#ifndef AO_ALLOC_SEGREGATION_MIN

#define AO_ALLOC_SEGREGATION_MIN    (0)

#endif

#ifndef AO_ALLOC_SEGREGATION_MAX

#define AO_ALLOC_SEGREGATION_MAX    (AO_SIZE_BITS_LOG)

#endif

// ----------------------------------------------------------------------------

#ifndef AO_ALLOC_SIZE

#define AO_ALLOC_SIZE               (8192)

#endif

// ----------------------------------------------------------------------------

extern  size_t          volatile    ao_alloc_allocated;

extern  size_t          volatile    ao_alloc_allocated_max;

extern  size_t          volatile    ao_alloc_free;

extern  size_t          volatile    ao_alloc_free_min;

// ----------------------------------------------------------------------------

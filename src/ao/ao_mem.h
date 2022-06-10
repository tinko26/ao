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

// Memory blocks.

// ----------------------------------------------------------------------------

#include <stddef.h>
#include <stdint.h>

// ----------------------------------------------------------------------------

// Copies the first #n bytes from the memory block beginning at #s to the
// memory block beginning at #d.

// Copies the data directly.

// Therefore, the memory blocks should not overlap.

// Returns #d.

void *  ao_memcpy(void * d, void const * s, size_t n);

// ----------------------------------------------------------------------------

// Copies the first #n bytes from the memory block beginning at #s to the
// memory block beginning at #d.

// Copies the data using a temporary buffer.

// Therefore, the memory blocks can overlap.

// Returns #d.

void *  ao_memmove(void * d, void const * s, size_t n);

// ----------------------------------------------------------------------------

// Writes #v to the first #n bytes of the memory block beginning at #p.

// Returns #p.

void *  ao_memset(void * p, uint8_t v, size_t n);

// ----------------------------------------------------------------------------

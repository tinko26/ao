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

// Streams for acquired memory blocks.

// ----------------------------------------------------------------------------

#include <ao_stream4ptr.h>
#include <ao_time.h>

// ----------------------------------------------------------------------------

typedef ao_stream4ptr_t         ao_stream4acq_t;

// ----------------------------------------------------------------------------

typedef ao_spop_ptr_t           ao_spop_acq_t;

typedef ao_spush_ptr_t          ao_spush_acq_t;

// ----------------------------------------------------------------------------

#ifndef AO_STREAM4ACQ

#define AO_STREAM4ACQ

#endif

// ----------------------------------------------------------------------------

void    ao_spop_acq(            ao_spop_acq_t * p, ao_time_t timeout);

void    ao_spop_acq_from(       ao_spop_acq_t * p, ao_time_t timeout, ao_time_t beginning);

void    ao_spop_acq_forever(    ao_spop_acq_t * p);

// ----------------------------------------------------------------------------

void    ao_spop_acq_try(        ao_spop_acq_t * p);

// ----------------------------------------------------------------------------

void    ao_spop_acq_begin(      ao_spop_acq_t * p);

void    ao_spop_acq_end(        ao_spop_acq_t * p);

// ----------------------------------------------------------------------------

void    ao_spush_acq(           ao_spush_acq_t * p, ao_time_t timeout);

void    ao_spush_acq_from(      ao_spush_acq_t * p, ao_time_t timeout, ao_time_t beginning);

void    ao_spush_acq_forever(   ao_spush_acq_t * p);

// ----------------------------------------------------------------------------

void    ao_spush_acq_try(       ao_spush_acq_t * p);

// ----------------------------------------------------------------------------

void    ao_spush_acq_begin(     ao_spush_acq_t * p);

void    ao_spush_acq_end(       ao_spush_acq_t * p);

// ----------------------------------------------------------------------------

void    ao_spush_acq_override(  ao_spush_acq_t * p);

// ----------------------------------------------------------------------------

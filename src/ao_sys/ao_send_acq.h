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

// Sending acquired memory blocks.

// ----------------------------------------------------------------------------

#include <ao_send_ptr.h>
#include <ao_time.h>

// ----------------------------------------------------------------------------

typedef ao_send_ptr_t       ao_send_acq_t;

// ----------------------------------------------------------------------------

typedef ao_send_ptr_proc_t  ao_send_acq_proc_t;

// ----------------------------------------------------------------------------

#ifndef AO_SEND_ACQ

#define AO_SEND_ACQ

#endif

// ----------------------------------------------------------------------------

void    ao_send_acq(        ao_send_acq_t * s, ao_time_t timeout);

void    ao_send_acq_from(   ao_send_acq_t * s, ao_time_t timeout, ao_time_t beginning);

void    ao_send_acq_forever(ao_send_acq_t * s);

// ----------------------------------------------------------------------------

void    ao_send_acq_try(    ao_send_acq_t * s);

// ----------------------------------------------------------------------------

void    ao_send_acq_begin(  ao_send_acq_t * s);

void    ao_send_acq_end(    ao_send_acq_t * s);

// ----------------------------------------------------------------------------

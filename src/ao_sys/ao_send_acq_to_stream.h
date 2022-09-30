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

// Sending acquired memory blocks to streams.

// ----------------------------------------------------------------------------

#include <ao_send_acq.h>
#include <ao_stream4acq.h>

// ----------------------------------------------------------------------------

#ifndef AO_SEND_ACQ_TO_STREAM

#define AO_SEND_ACQ_TO_STREAM

#endif

// ----------------------------------------------------------------------------

void    ao_send_acq_to_stream
(
        ao_send_acq_t * s,

        ao_spush_acq_t * p
);

// ----------------------------------------------------------------------------

void    ao_send_acq_to_stream_override
(
        ao_send_acq_t * s,

        ao_spush_acq_t * p
);

// ----------------------------------------------------------------------------

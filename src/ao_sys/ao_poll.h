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

// Polling.

// ----------------------------------------------------------------------------

#include <ao_async.h>
#include <ao_time.h>

// ----------------------------------------------------------------------------

#ifndef AO_POLL

#define AO_POLL

#endif

// ----------------------------------------------------------------------------

void    ao_poll(            ao_async_t const * a, ao_time_t timeout);

void    ao_poll_from(       ao_async_t const * a, ao_time_t timeout, ao_time_t beginning);

void    ao_poll_forever(    ao_async_t const * a);

// ----------------------------------------------------------------------------

void    ao_poll_all(        ao_async_all_t * a, ao_time_t timeout);

void    ao_poll_all_from(   ao_async_all_t * a, ao_time_t timeout, ao_time_t beginning);

void    ao_poll_all_forever(ao_async_all_t * a);

// ----------------------------------------------------------------------------

void    ao_poll_any(        ao_async_any_t * a, ao_time_t timeout);

void    ao_poll_any_from(   ao_async_any_t * a, ao_time_t timeout, ao_time_t beginning);

void    ao_poll_any_forever(ao_async_any_t * a);

// ----------------------------------------------------------------------------

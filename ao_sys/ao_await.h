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

// Await.

// ----------------------------------------------------------------------------

#include <ao_async.h>
#include <ao_time.h>

// ----------------------------------------------------------------------------

#ifndef AO_AWAIT

#define AO_AWAIT

#endif

// ----------------------------------------------------------------------------

void    ao_await(               ao_async_t * x,     ao_time_t timeout);

void    ao_await_from(          ao_async_t * x,     ao_time_t timeout, ao_time_t beginning);

void    ao_await_forever(       ao_async_t * x);

// ----------------------------------------------------------------------------

void    ao_await_all(           ao_async_all_t * x, ao_time_t timeout);

void    ao_await_all_from(      ao_async_all_t * x, ao_time_t timeout, ao_time_t beginning);

void    ao_await_all_forever(   ao_async_all_t * x);

// ----------------------------------------------------------------------------

void    ao_await_any(           ao_async_any_t * x, ao_time_t timeout);

void    ao_await_any_from(      ao_async_any_t * x, ao_time_t timeout, ao_time_t beginning);

void    ao_await_any_forever(   ao_async_any_t * x);

// ----------------------------------------------------------------------------

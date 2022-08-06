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

// Readers-writer locking (preferring readers).

// ----------------------------------------------------------------------------

#include <ao_async.h>
#include <ao_list.h>
#include <ao_time.h>
#include <ao_uint.h>
#include <stdbool.h>

// ----------------------------------------------------------------------------

typedef struct  ao_rw_t             ao_rw_t;

typedef struct  ao_rw_lock_t        ao_rw_lock_t;

// ----------------------------------------------------------------------------

#ifndef AO_RW

#define AO_RW

// ----------------------------------------------------------------------------

struct  ao_rw_t
{
        ao_uint_t                   r_active;

        ao_list_t                   r_waiting;

        bool                        w_active;

        ao_list_t                   w_waiting;
};

// ----------------------------------------------------------------------------

#endif

#ifndef AO_RW_LOCK

#define AO_RW_LOCK

// ----------------------------------------------------------------------------

struct  ao_rw_lock_t
{
        ao_async_t                  async;

        ao_list_node_t              node;

        bool            volatile    result;

        ao_rw_t *                   rw;
};

// ----------------------------------------------------------------------------

#endif

// ----------------------------------------------------------------------------

bool    ao_rw_lock_read(            ao_rw_t * x, ao_time_t timeout);

bool    ao_rw_lock_read_forever(    ao_rw_t * x);

bool    ao_rw_lock_read_from(       ao_rw_t * x, ao_time_t timeout, ao_time_t beginning);

bool    ao_rw_lock_read_try(        ao_rw_t * x);

// ----------------------------------------------------------------------------

void    ao_rw_lock_read_begin(      ao_rw_lock_t * x);

void    ao_rw_lock_read_end(        ao_rw_lock_t * x);

// ----------------------------------------------------------------------------

bool    ao_rw_lock_write(           ao_rw_t * x, ao_time_t timeout);

bool    ao_rw_lock_write_forever(   ao_rw_t * x);

bool    ao_rw_lock_write_from(      ao_rw_t * x, ao_time_t timeout, ao_time_t beginning);

bool    ao_rw_lock_write_try(       ao_rw_t * x);

// ----------------------------------------------------------------------------

void    ao_rw_lock_write_begin(     ao_rw_lock_t * x);

void    ao_rw_lock_write_end(       ao_rw_lock_t * x);

// ----------------------------------------------------------------------------

void    ao_rw_unlock_read(          ao_rw_t * x);

// ----------------------------------------------------------------------------

void    ao_rw_unlock_write(         ao_rw_t * x);

// ----------------------------------------------------------------------------

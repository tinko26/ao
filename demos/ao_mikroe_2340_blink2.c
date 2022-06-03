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

#include <ao.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// ----------------------------------------------------------------------------

#define RED         (1 << 0)

#define GREEN       (1 << 1)

#define BLUE        (1 << 2)

// ----------------------------------------------------------------------------

#define CAPACITY    (16)

// ----------------------------------------------------------------------------

static  uint8_t     store[CAPACITY];

static  ao_stream_t stream =
{
        .buffer.capacity = CAPACITY,

        .buffer.store = store
};

static  ao_spop_t   pop  = { .stream = &stream };

static  ao_spush_t  push = { .stream = &stream };

// ----------------------------------------------------------------------------

static  void        task_recv_proc(void * x);

static  void        task_send_proc(void * x);

// ----------------------------------------------------------------------------

static  ao_task_t   task_recv = { .proc = task_recv_proc };

static  ao_task_t   task_send = { .proc = task_send_proc };

// ----------------------------------------------------------------------------

void main()
{
    ao_boot();

    ao_task_start(&task_recv);

    ao_task_start(&task_send);

    while (1) { }
}

// ----------------------------------------------------------------------------

void task_recv_proc(void * x)
{
    // Variables.

    (void) x;

    uint8_t c, r, g, b;

    ao_spop_t * P = &pop;


    // Ready.

    P->count_min = 1;

    P->count_max = 1;

    P->ptr = &c;

    ao_mikroe_2950_black(AO_MIKROE_A);

    ao_mikroe_2950_luminance(AO_MIKROE_A, 0xFF);


    // Loop.

    while (1)
    {
        ao_spop_forever(P);

        if (P->result)
        {
            r = c & RED ? 0xFF : 0x00;

            g = c & GREEN ? 0xFF : 0x00;

            b = c & BLUE ? 0xFF : 0x00;

            ao_mikroe_2950_color(AO_MIKROE_A, r, g, b);
        }
    }
}

void task_send_proc(void * x)
{
    // Variables.

    (void) x;

    uint8_t c = 0;

    ao_spush_t * P = &push;


    // Ready.

    P->count_max = 1;

    P->count_min = 1;

    P->ptr = &c;


    // Loop.

    while (1)
    {
        ao_spush_try(P);

        c = (c + 1) % 8;

        ao_sleep(ao_milliseconds(500));
    }
}

// ----------------------------------------------------------------------------

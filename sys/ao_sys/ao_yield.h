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

// Yield.

// ----------------------------------------------------------------------------

// @seeAlso

// https://en.wikipedia.org/wiki/Coroutine

// https://en.wikipedia.org/wiki/Producer-consumer_problem

// ----------------------------------------------------------------------------

// @example

// Producer-consumer problem.

// @code

/*

    ao_task_t * consumer;

    ao_task_t * producer;

    void consumer_proc(void * x)
    {
        while (1)
        {
            // Wait for the producer to produce something.

            ao_yield_to( producer );


            // Consume what the producer has produced.

            consume();
        }
    }

    void producer_proc(void * x)
    {
        while (1)
        {
            // Produce something.

            produce();


            // Wait for the consumer to consume what has been produced.

            ao_yield_to( consumer );
        }
    }

*/

// @endCode

// ----------------------------------------------------------------------------

#include <ao_task.h>

// ----------------------------------------------------------------------------

#ifndef AO_YIELD

#define AO_YIELD

#endif

// ----------------------------------------------------------------------------

// Forces a context switch.

// That is, the calling task gives up the CPU in favor of another task.

void    ao_yield();

// ----------------------------------------------------------------------------

// Puts the calling task to sleep and wakes up another task.

// This allows for tasks behaving similar to coroutines.

void    ao_yield_to(ao_task_t * t);

// ----------------------------------------------------------------------------

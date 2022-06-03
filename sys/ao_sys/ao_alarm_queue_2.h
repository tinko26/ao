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

// Alarm queue 2.

// This module implements an alarm queue based on a heap.

// The heap is stored in a statically allocated array.

// Therefore, the capacity of the alarm queue is both fixed and limited.

// Time complexities:

// Insert       O(log N)

// Peek         O(1)

// Remove       O(log N)

// Remove peek  O(log N)

// ----------------------------------------------------------------------------

// @seeAlso

// https://en.wikipedia.org/wiki/Binary_heap

// ----------------------------------------------------------------------------

#include <stdbool.h>
#include <stddef.h>

// ----------------------------------------------------------------------------

typedef size_t                      ao_alarm_queue_node_t;

// ----------------------------------------------------------------------------

#ifndef AO_ALARM_QUEUE_2

#define AO_ALARM_QUEUE_2

#endif

// ----------------------------------------------------------------------------

#ifndef AO_ALARM_QUEUE_ASSERT

#define AO_ALARM_QUEUE_ASSERT       (false)

#endif

#ifndef AO_ALARM_QUEUE_CAPACITY

#define AO_ALARM_QUEUE_CAPACITY     (128)

#endif

#ifndef AO_ALARM_QUEUE_COUNT_MAX

#define AO_ALARM_QUEUE_COUNT_MAX    (false)

#endif

// ----------------------------------------------------------------------------

extern  size_t          volatile    ao_alarm_queue_count;

extern  size_t          volatile    ao_alarm_queue_count_max;

// ----------------------------------------------------------------------------

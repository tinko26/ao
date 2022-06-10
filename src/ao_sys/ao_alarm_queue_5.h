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

// Alarm queue 5.

// This module implements an alarm queue based on a red-black tree.

// Time complexities:

// Insert       O(log N)

// Peek         O(log N)

// Remove       O(log N)

// Remove peek  O(log N)

// ----------------------------------------------------------------------------

// @seeAlso

// https://en.wikipedia.org/wiki/Red–black_tree

// ----------------------------------------------------------------------------

#include <ao_rb.h>
#include <stdbool.h>

// ----------------------------------------------------------------------------

typedef ao_rb_t                 ao_alarm_queue_t;

typedef ao_rb_node_t            ao_alarm_queue_node_t;

// ----------------------------------------------------------------------------

#ifndef AO_ALARM_QUEUE_5

#define AO_ALARM_QUEUE_5

#endif

// ----------------------------------------------------------------------------

#ifndef AO_ALARM_QUEUE_ASSERT

#define AO_ALARM_QUEUE_ASSERT   (false)

#endif

#ifndef AO_ALARM_QUEUE_CACHE

#define AO_ALARM_QUEUE_CACHE    (false)

#endif

// ----------------------------------------------------------------------------

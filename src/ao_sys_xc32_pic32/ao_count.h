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

// Counter.

// ----------------------------------------------------------------------------

#include <ao_sys.h>
#include <stdint.h>
#include <xc.h>

// ----------------------------------------------------------------------------

typedef uint32_t                    ao_count_t;

// ----------------------------------------------------------------------------

#ifndef AO_COUNT_MAX

#define AO_COUNT_MAX                (UINT32_MAX)

#endif

#ifndef AO_COUNT_MIN

#define AO_COUNT_MIN                (0)

#endif

// ----------------------------------------------------------------------------

#ifndef AO_COUNT_FREQUENCY

#define AO_COUNT_FREQUENCY          ((AO_SYS_SYSCLK) / 2)

#endif

// ----------------------------------------------------------------------------

#ifndef ao_count

#define ao_count()                  _CP0_GET_COUNT()

#endif

// ----------------------------------------------------------------------------

#ifndef ao_count_debug_continue

#define ao_count_debug_continue()   _CP0_BIS_DEBUG(_CP0_DEBUG_COUNTDM_MASK)

#endif

#ifndef ao_count_debug_stop

#define ao_count_debug_stop()       _CP0_BIC_DEBUG(_CP0_DEBUG_COUNTDM_MASK)

#endif

// ----------------------------------------------------------------------------

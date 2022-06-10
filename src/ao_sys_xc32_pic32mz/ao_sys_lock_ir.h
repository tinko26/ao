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

// System locking (interrupts).

// ----------------------------------------------------------------------------

// @example

// @code

/*

    // Lock all interrupts of priority level 4 or less.

    uint32_t p = 4;

    uint32_t x;

    x = ao_sys_lock_ir(p);
    {
        // ...

        // Critical section.

        // Interrupts are disabled up to and including priority level p.

        // ...
    }
    ao_sys_unlock_ir(x);

*/

// @endCode

// ----------------------------------------------------------------------------

#include <stdint.h>
#include <xc.h>

// ----------------------------------------------------------------------------

#ifndef AO_SYS_LOCK_IR

#define AO_SYS_LOCK_IR

// ----------------------------------------------------------------------------

static uint32_t ao_sys_lock_ir(uint32_t p)
{
    uint32_t x = _CP0_GET_VIEW_IPL();

    p = p << 2;

    if (x < p)
    {
        _CP0_SET_VIEW_IPL(p);
    }

    return x;
}

static void ao_sys_unlock_ir(uint32_t x)
{
    _CP0_SET_VIEW_IPL(x);
}

// ----------------------------------------------------------------------------

#endif

// ----------------------------------------------------------------------------

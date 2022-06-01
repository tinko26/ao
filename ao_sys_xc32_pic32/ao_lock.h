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

// Locking.

// This module defines locks.

// Locks are the basic mechanism for system-wide critical sections.

// Locks are used to synchronize access to low-level resources.

// ----------------------------------------------------------------------------

// Locking sets the interrupt priority level to the lock priority.

// That is, locking disables only those interrupts, whose priority is less than
// or equal to the lock priority.

// Higher-priority interrupts will remain enabled. However, these interrupts
// must not make system calls.

// ----------------------------------------------------------------------------

// @example

// @code

/*

    ao_lock_t x;

    ao_lock(&x);
    {
        // ...

        // Critical section.

        // ...
    }
    ao_unlock(&x);

*/

// @endCode

// ----------------------------------------------------------------------------

#include <ao_ir.h>
#include <ao_sys.h>
#include <stdint.h>

// ----------------------------------------------------------------------------

typedef uint32_t        ao_lock_t;

// ----------------------------------------------------------------------------

#ifndef AO_LOCK_PRIO

#define AO_LOCK_PRIO    (AO_IR_PRIO_MAX)

#endif

// ----------------------------------------------------------------------------

#ifndef ao_lock

#define ao_lock(x)      { *(x) = ao_sys_lock_ir(AO_LOCK_PRIO); }

#endif

#ifndef ao_unlock

#define ao_unlock(x)    { ao_sys_unlock_ir(*(x)); }

#endif

// ----------------------------------------------------------------------------

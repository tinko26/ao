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

// Prefetch cache interrupt.

// ----------------------------------------------------------------------------

#include <stdbool.h>
#include <sys/attribs.h>
#include <xc.h>

// ----------------------------------------------------------------------------

#ifndef AO_IR_PCACHE_ATTRIBUTE

#define AO_IR_PCACHE_ATTRIBUTE      __ISR(_PCACHE_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_PCACHE_PRIO

#define AO_IR_PCACHE_PRIO           (4)

#endif

#ifndef AO_IR_PCACHE_SUBPRIO

#define AO_IR_PCACHE_SUBPRIO        (0)

#endif

// ----------------------------------------------------------------------------

#ifndef ao_ir_pcache_disable

#define ao_ir_pcache_disable()      { IEC7CLR = _IEC7_PCACHEIE_MASK; }

#endif

#ifndef ao_ir_pcache_enable

#define ao_ir_pcache_enable()       { IEC7SET = _IEC7_PCACHEIE_MASK; }

#endif

#ifndef ao_ir_pcache_is_enabled

#define ao_ir_pcache_is_enabled()   ((IEC7 & _IEC7_PCACHEIE_MASK) ? true : false)

#endif

// ----------------------------------------------------------------------------

#ifndef ao_ir_pcache_is_pending

#define ao_ir_pcache_is_pending()   ((IFS7 & _IFS7_PCACHEIF_MASK) ? true : false)

#endif

#ifndef ao_ir_pcache_reply

#define ao_ir_pcache_reply()        { IFS7CLR = _IFS7_PCACHEIF_MASK; }

#endif

#ifndef ao_ir_pcache_request

#define ao_ir_pcache_request()      { IFS7SET = _IFS7_PCACHEIF_MASK; }

#endif

// ----------------------------------------------------------------------------

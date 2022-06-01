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

// Core timer interrupt.

// ----------------------------------------------------------------------------

#include <stdbool.h>
#include <sys/attribs.h>
#include <xc.h>

// ----------------------------------------------------------------------------

#ifndef AO_IR_CT_ATTRIBUTE

#define AO_IR_CT_ATTRIBUTE      __ISR(_CORE_TIMER_VECTOR, IPL3SOFT)

#endif

#ifndef AO_IR_CT_PRIO

#define AO_IR_CT_PRIO           (3)

#endif

#ifndef AO_IR_CT_SUBPRIO

#define AO_IR_CT_SUBPRIO        (0)

#endif

// ----------------------------------------------------------------------------

#ifndef ao_ir_ct_disable

#define ao_ir_ct_disable()      { IEC0CLR = _IEC0_CTIE_MASK; }

#endif

#ifndef ao_ir_ct_enable

#define ao_ir_ct_enable()       { IEC0SET = _IEC0_CTIE_MASK; }

#endif

#ifndef ao_ir_ct_is_enabled

#define ao_ir_ct_is_enabled()   ((IEC0 & _IEC0_CTIE_MASK) ? true : false)

#endif

// ----------------------------------------------------------------------------

#ifndef ao_ir_ct_is_pending

#define ao_ir_ct_is_pending()   ((IFS0 & _IFS0_CTIF_MASK) ? true : false)

#endif

#ifndef ao_ir_ct_reply

#define ao_ir_ct_reply()        { IFS0CLR = _IFS0_CTIF_MASK; }

#endif

#ifndef ao_ir_ct_request

#define ao_ir_ct_request()      { IFS0SET = _IFS0_CTIF_MASK; }

#endif

// ----------------------------------------------------------------------------

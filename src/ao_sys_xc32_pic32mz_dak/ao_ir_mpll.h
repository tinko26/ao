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

// Memory PLL interrupt.

// ----------------------------------------------------------------------------

#include <stdbool.h>
#include <sys/attribs.h>
#include <xc.h>

// ----------------------------------------------------------------------------

#ifndef AO_IR_MPLLFLT_ATTRIBUTE

#define AO_IR_MPLLFLT_ATTRIBUTE     __ISR(_MPLL_FAULT_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_MPLLFLT_PRIO

#define AO_IR_MPLLFLT_PRIO          (4)

#endif

#ifndef AO_IR_MPLLFLT_SUBPRIO

#define AO_IR_MPLLFLT_SUBPRIO       (0)

#endif

// ----------------------------------------------------------------------------

#ifndef ao_ir_mpllflt_disable

#define ao_ir_mpllflt_disable()     { IEC6CLR = _IEC6_MPLLFLTIE_MASK; }

#endif

#ifndef ao_ir_mpllflt_enable

#define ao_ir_mpllflt_enable()      { IEC6SET = _IEC6_MPLLFLTIE_MASK; }

#endif

#ifndef ao_ir_mpllflt_is_enabled

#define ao_ir_mpllflt_is_enabled()  ((IEC6 & _IEC6_MPLLFLTIE_MASK) ? true : false)

#endif

// ----------------------------------------------------------------------------

#ifndef ao_ir_mpllflt_is_pending

#define ao_ir_mpllflt_is_pending()  ((IFS6 & _IFS6_MPLLFLTIF_MASK) ? true : false)

#endif

#ifndef ao_ir_mpllflt_reply

#define ao_ir_mpllflt_reply()       { IFS6CLR = _IFS6_MPLLFLTIF_MASK; }

#endif

#ifndef ao_ir_mpllflt_request

#define ao_ir_mpllflt_request()     { IFS6SET = _IFS6_MPLLFLTIF_MASK; }

#endif

// ----------------------------------------------------------------------------

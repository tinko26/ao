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

// Core performance counter interrupt.

// ----------------------------------------------------------------------------

#include <stdbool.h>
#include <sys/attribs.h>
#include <xc.h>

// ----------------------------------------------------------------------------

#ifndef AO_IR_CPC_ATTRIBUTE

#define AO_IR_CPC_ATTRIBUTE     __ISR(_CORE_PERF_COUNT_VECTOR, IPL4SOFT)

#endif

#ifndef AO_IR_CPC_PRIO

#define AO_IR_CPC_PRIO          (4)

#endif

#ifndef AO_IR_CPC_SUBPRIO

#define AO_IR_CPC_SUBPRIO       (0)

#endif

// ----------------------------------------------------------------------------

#ifndef ao_ir_cpc_disable

#define ao_ir_cpc_disable()     { IEC7CLR = _IEC7_CPCIE_MASK; }

#endif

#ifndef ao_ir_cpc_enable

#define ao_ir_cpc_enable()      { IEC7SET = _IEC7_CPCIE_MASK; }

#endif

#ifndef ao_ir_cpc_is_enabled

#define ao_ir_cpc_is_enabled()  ((IEC7 & _IEC7_CPCIE_MASK) ? true : false)

#endif

// ----------------------------------------------------------------------------

#ifndef ao_ir_cpc_is_pending

#define ao_ir_cpc_is_pending()  ((IFS7 & _IFS7_CPCIF_MASK) ? true : false)

#endif

#ifndef ao_ir_cpc_reply

#define ao_ir_cpc_reply()       { IFS7CLR = _IFS7_CPCIF_MASK; }

#endif

#ifndef ao_ir_cpc_request

#define ao_ir_cpc_request()     { IFS7SET = _IFS7_CPCIF_MASK; }

#endif

// ----------------------------------------------------------------------------

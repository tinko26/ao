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

// Configurable Logic Cell interrupts.

// ----------------------------------------------------------------------------

#include <stdbool.h>
#include <sys/attribs.h>
#include <xc.h>

// ----------------------------------------------------------------------------

#ifndef AO_IR_CLC1_ATTRIBUTE

#define AO_IR_CLC1_ATTRIBUTE        __ISR(_CLC1_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_CLC1_PRIO

#define AO_IR_CLC1_PRIO             (4)

#endif

#ifndef AO_IR_CLC1_SUBPRIO

#define AO_IR_CLC1_SUBPRIO          (0)

#endif

// ----------------------------------------------------------------------------

#ifndef ao_ir_clc1_disable

#define ao_ir_clc1_disable()        { IEC7CLR = _IEC7_CLC1IE_MASK; }

#endif

#ifndef ao_ir_clc1_enable

#define ao_ir_clc1_enable()         { IEC7SET = _IEC7_CLC1IE_MASK; }

#endif

#ifndef ao_ir_clc1_is_enabled

#define ao_ir_clc1_is_enabled()     ((IEC7 & _IEC7_CLC1IE_MASK) ? true : false)

#endif

// ----------------------------------------------------------------------------

#ifndef ao_ir_clc1_is_pending

#define ao_ir_clc1_is_pending()     ((IFS7 & _IFS7_CLC1IF_MASK) ? true : false)

#endif

#ifndef ao_ir_clc1_reply

#define ao_ir_clc1_reply()          { IFS7CLR = _IFS7_CLC1IF_MASK; }

#endif

#ifndef ao_ir_clc1_request

#define ao_ir_clc1_request()        { IFS7SET = _IFS7_CLC1IF_MASK; }

#endif

// ----------------------------------------------------------------------------

#ifndef AO_IR_CLC2_ATTRIBUTE

#define AO_IR_CLC2_ATTRIBUTE        __ISR(_CLC2_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_CLC2_PRIO

#define AO_IR_CLC2_PRIO             (4)

#endif

#ifndef AO_IR_CLC2_SUBPRIO

#define AO_IR_CLC2_SUBPRIO          (0)

#endif

// ----------------------------------------------------------------------------

#ifndef ao_ir_clc2_disable

#define ao_ir_clc2_disable()        { IEC7CLR = _IEC7_CLC2IE_MASK; }

#endif

#ifndef ao_ir_clc2_enable

#define ao_ir_clc2_enable()         { IEC7SET = _IEC7_CLC2IE_MASK; }

#endif

#ifndef ao_ir_clc2_is_enabled

#define ao_ir_clc2_is_enabled()     ((IEC7 & _IEC7_CLC2IE_MASK) ? true : false)

#endif

// ----------------------------------------------------------------------------

#ifndef ao_ir_clc2_is_pending

#define ao_ir_clc2_is_pending()     ((IFS7 & _IFS7_CLC2IF_MASK) ? true : false)

#endif

#ifndef ao_ir_clc2_reply

#define ao_ir_clc2_reply()          { IFS7CLR = _IFS7_CLC2IF_MASK; }

#endif

#ifndef ao_ir_clc2_request

#define ao_ir_clc2_request()        { IFS7SET = _IFS7_CLC2IF_MASK; }

#endif

// ----------------------------------------------------------------------------

#ifndef AO_IR_CLC3_ATTRIBUTE

#define AO_IR_CLC3_ATTRIBUTE        __ISR(_CLC3_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_CLC3_PRIO

#define AO_IR_CLC3_PRIO             (4)

#endif

#ifndef AO_IR_CLC3_SUBPRIO

#define AO_IR_CLC3_SUBPRIO          (0)

#endif

// ----------------------------------------------------------------------------

#ifndef ao_ir_clc3_disable

#define ao_ir_clc3_disable()        { IEC7CLR = _IEC7_CLC3IE_MASK; }

#endif

#ifndef ao_ir_clc3_enable

#define ao_ir_clc3_enable()         { IEC7SET = _IEC7_CLC3IE_MASK; }

#endif

#ifndef ao_ir_clc3_is_enabled

#define ao_ir_clc3_is_enabled()     ((IEC7 & _IEC7_CLC3IE_MASK) ? true : false)

#endif

// ----------------------------------------------------------------------------

#ifndef ao_ir_clc3_is_pending

#define ao_ir_clc3_is_pending()     ((IFS7 & _IFS7_CLC3IF_MASK) ? true : false)

#endif

#ifndef ao_ir_clc3_reply

#define ao_ir_clc3_reply()          { IFS7CLR = _IFS7_CLC3IF_MASK; }

#endif

#ifndef ao_ir_clc3_request

#define ao_ir_clc3_request()        { IFS7SET = _IFS7_CLC3IF_MASK; }

#endif

// ----------------------------------------------------------------------------

#ifndef AO_IR_CLC4_ATTRIBUTE

#define AO_IR_CLC4_ATTRIBUTE        __ISR(_CLC4_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_CLC4_PRIO

#define AO_IR_CLC4_PRIO             (4)

#endif

#ifndef AO_IR_CLC4_SUBPRIO

#define AO_IR_CLC4_SUBPRIO          (0)

#endif

// ----------------------------------------------------------------------------

#ifndef ao_ir_clc4_disable

#define ao_ir_clc4_disable()        { IEC7CLR = _IEC7_CLC4IE_MASK; }

#endif

#ifndef ao_ir_clc4_enable

#define ao_ir_clc4_enable()         { IEC7SET = _IEC7_CLC4IE_MASK; }

#endif

#ifndef ao_ir_clc4_is_enabled

#define ao_ir_clc4_is_enabled()     ((IEC7 & _IEC7_CLC4IE_MASK) ? true : false)

#endif

// ----------------------------------------------------------------------------

#ifndef ao_ir_clc4_is_pending

#define ao_ir_clc4_is_pending()     ((IFS7 & _IFS7_CLC4IF_MASK) ? true : false)

#endif

#ifndef ao_ir_clc4_reply

#define ao_ir_clc4_reply()          { IFS7CLR = _IFS7_CLC4IF_MASK; }

#endif

#ifndef ao_ir_clc4_request

#define ao_ir_clc4_request()        { IFS7SET = _IFS7_CLC4IF_MASK; }

#endif

// ----------------------------------------------------------------------------

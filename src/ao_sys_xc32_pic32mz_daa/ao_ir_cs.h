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

// Core software interrupts.

// ----------------------------------------------------------------------------

#include <stdbool.h>
#include <sys/attribs.h>
#include <xc.h>

// ----------------------------------------------------------------------------

#ifndef AO_IR_CS0_ATTRIBUTE

#define AO_IR_CS0_ATTRIBUTE     __ISR(_CORE_SOFTWARE_0_VECTOR, IPL2SRS)

#endif

#ifndef AO_IR_CS0_PRIO

#define AO_IR_CS0_PRIO          (2)

#endif

#ifndef AO_IR_CS0_SUBPRIO

#define AO_IR_CS0_SUBPRIO       (0)

#endif

// ----------------------------------------------------------------------------

#ifndef ao_ir_cs0_disable

#define ao_ir_cs0_disable()     { IEC0CLR = _IEC0_CS0IE_MASK; }

#endif

#ifndef ao_ir_cs0_enable

#define ao_ir_cs0_enable()      { IEC0SET = _IEC0_CS0IE_MASK; }

#endif

#ifndef ao_ir_cs0_is_enabled

#define ao_ir_cs0_is_enabled()  ((IEC0 & _IEC0_CS0IE_MASK) ? true : false)

#endif

// ----------------------------------------------------------------------------

#ifndef ao_ir_cs0_is_pending

#define ao_ir_cs0_is_pending()  ((IFS0 & _IFS0_CS0IF_MASK) ? true : false)

#endif

#ifndef ao_ir_cs0_reply

#define ao_ir_cs0_reply()       { IFS0CLR = _IFS0_CS0IF_MASK; }

#endif

#ifndef ao_ir_cs0_request

#define ao_ir_cs0_request()     { IFS0SET = _IFS0_CS0IF_MASK; }

#endif

// ----------------------------------------------------------------------------

#ifndef AO_IR_CS1_ATTRIBUTE

#define AO_IR_CS1_ATTRIBUTE     __attribute__ ((naked, vector(_CORE_SOFTWARE_1_VECTOR)))

#endif

#ifndef AO_IR_CS1_PRIO

#define AO_IR_CS1_PRIO          (1)

#endif

#ifndef AO_IR_CS1_SUBPRIO

#define AO_IR_CS1_SUBPRIO       (0)

#endif

// ----------------------------------------------------------------------------

#ifndef ao_ir_cs1_disable

#define ao_ir_cs1_disable()     { IEC0CLR = _IEC0_CS1IE_MASK; }

#endif

#ifndef ao_ir_cs1_enable

#define ao_ir_cs1_enable()      { IEC0SET = _IEC0_CS1IE_MASK; }

#endif

#ifndef ao_ir_cs1_is_enabled

#define ao_ir_cs1_is_enabled()  ((IEC0 & _IEC0_CS1IE_MASK) ? true : false)

#endif

// ----------------------------------------------------------------------------

#ifndef ao_ir_cs1_is_pending

#define ao_ir_cs1_is_pending()  ((IFS0 & _IFS0_CS1IF_MASK) ? true : false)

#endif

#ifndef ao_ir_cs1_reply

#define ao_ir_cs1_reply()       { IFS0CLR = _IFS0_CS1IF_MASK; }

#endif

#ifndef ao_ir_cs1_request

#define ao_ir_cs1_request()     { IFS0SET = _IFS0_CS1IF_MASK; }

#endif

// ----------------------------------------------------------------------------

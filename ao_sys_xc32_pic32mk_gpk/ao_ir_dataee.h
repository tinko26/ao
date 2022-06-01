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

// Data EEPROM interrupt.

// ----------------------------------------------------------------------------

#include <stdbool.h>
#include <sys/attribs.h>
#include <xc.h>

// ----------------------------------------------------------------------------

#ifndef AO_IR_DATAEE_ATTRIBUTE

#define AO_IR_DATAEE_ATTRIBUTE      __ISR(_DATA_EE_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_DATAEE_PRIO

#define AO_IR_DATAEE_PRIO           (4)

#endif

#ifndef AO_IR_DATAEE_SUBPRIO

#define AO_IR_DATAEE_SUBPRIO        (0)

#endif

// ----------------------------------------------------------------------------

#ifndef ao_ir_dataee_disable

#define ao_ir_dataee_disable()      { IEC5CLR = _IEC5_DATAEEIE_MASK; }

#endif

#ifndef ao_ir_dataee_enable

#define ao_ir_dataee_enable()       { IEC5SET = _IEC5_DATAEEIE_MASK; }

#endif

#ifndef ao_ir_dataee_is_enabled

#define ao_ir_dataee_is_enabled()   ((IEC5 & _IEC5_DATAEEIE_MASK) ? true : false)

#endif

// ----------------------------------------------------------------------------

#ifndef ao_ir_dataee_is_pending

#define ao_ir_dataee_is_pending()   ((IFS5 & _IFS5_DATAEEIF_MASK) ? true : false)

#endif

#ifndef ao_ir_dataee_reply

#define ao_ir_dataee_reply()        { IFS5CLR = _IFS5_DATAEEIF_MASK; }

#endif

#ifndef ao_ir_dataee_request

#define ao_ir_dataee_request()      { IFS5SET = _IFS5_DATAEEIF_MASK; }

#endif

// ----------------------------------------------------------------------------

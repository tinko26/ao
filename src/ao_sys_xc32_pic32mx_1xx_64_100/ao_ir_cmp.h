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

// Comparator interrupts.

// ----------------------------------------------------------------------------

#include <stdbool.h>
#include <sys/attribs.h>
#include <xc.h>

// ----------------------------------------------------------------------------

#ifndef AO_IR_CMP1_ATTRIBUTE

#define AO_IR_CMP1_ATTRIBUTE        __ISR(_COMPARATOR_1_VECTOR, IPL4SOFT)

#endif

#ifndef AO_IR_CMP1_PRIO

#define AO_IR_CMP1_PRIO             (4)

#endif

#ifndef AO_IR_CMP1_SUBPRIO

#define AO_IR_CMP1_SUBPRIO          (0)

#endif

// ----------------------------------------------------------------------------

#ifndef ao_ir_cmp1_disable

#define ao_ir_cmp1_disable()        { IEC1CLR = _IEC1_CMP1IE_MASK; }

#endif

#ifndef ao_ir_cmp1_enable

#define ao_ir_cmp1_enable()         { IEC1SET = _IEC1_CMP1IE_MASK; }

#endif

#ifndef ao_ir_cmp1_is_enabled

#define ao_ir_cmp1_is_enabled()     ((IEC1 & _IEC1_CMP1IE_MASK) ? true : false)

#endif

// ----------------------------------------------------------------------------

#ifndef ao_ir_cmp1_is_pending

#define ao_ir_cmp1_is_pending()     ((IFS1 & _IFS1_CMP1IF_MASK) ? true : false)

#endif

#ifndef ao_ir_cmp1_reply

#define ao_ir_cmp1_reply()          { IFS1CLR = _IFS1_CMP1IF_MASK; }

#endif

#ifndef ao_ir_cmp1_request

#define ao_ir_cmp1_request()        { IFS1SET = _IFS1_CMP1IF_MASK; }

#endif

// ----------------------------------------------------------------------------

#ifndef AO_IR_CMP2_ATTRIBUTE

#define AO_IR_CMP2_ATTRIBUTE        __ISR(_COMPARATOR_2_VECTOR, IPL4SOFT)

#endif

#ifndef AO_IR_CMP2_PRIO

#define AO_IR_CMP2_PRIO             (4)

#endif

#ifndef AO_IR_CMP2_SUBPRIO

#define AO_IR_CMP2_SUBPRIO          (0)

#endif

// ----------------------------------------------------------------------------

#ifndef ao_ir_cmp2_disable

#define ao_ir_cmp2_disable()        { IEC1CLR = _IEC1_CMP2IE_MASK; }

#endif

#ifndef ao_ir_cmp2_enable

#define ao_ir_cmp2_enable()         { IEC1SET = _IEC1_CMP2IE_MASK; }

#endif

#ifndef ao_ir_cmp2_is_enabled

#define ao_ir_cmp2_is_enabled()     ((IEC1 & _IEC1_CMP2IE_MASK) ? true : false)

#endif

// ----------------------------------------------------------------------------

#ifndef ao_ir_cmp2_is_pending

#define ao_ir_cmp2_is_pending()     ((IFS1 & _IFS1_CMP2IF_MASK) ? true : false)

#endif

#ifndef ao_ir_cmp2_reply

#define ao_ir_cmp2_reply()          { IFS1CLR = _IFS1_CMP2IF_MASK; }

#endif

#ifndef ao_ir_cmp2_request

#define ao_ir_cmp2_request()        { IFS1SET = _IFS1_CMP2IF_MASK; }

#endif

// ----------------------------------------------------------------------------

#ifndef AO_IR_CMP3_ATTRIBUTE

#define AO_IR_CMP3_ATTRIBUTE        __ISR(_COMPARATOR_3_VECTOR, IPL4SOFT)

#endif

#ifndef AO_IR_CMP3_PRIO

#define AO_IR_CMP3_PRIO             (4)

#endif

#ifndef AO_IR_CMP3_SUBPRIO

#define AO_IR_CMP3_SUBPRIO          (0)

#endif

// ----------------------------------------------------------------------------

#ifndef ao_ir_cmp3_disable

#define ao_ir_cmp3_disable()        { IEC2CLR = _IEC2_CMP3IE_MASK; }

#endif

#ifndef ao_ir_cmp3_enable

#define ao_ir_cmp3_enable()         { IEC2SET = _IEC2_CMP3IE_MASK; }

#endif

#ifndef ao_ir_cmp3_is_enabled

#define ao_ir_cmp3_is_enabled()     ((IEC2 & _IEC2_CMP3IE_MASK) ? true : false)

#endif

// ----------------------------------------------------------------------------

#ifndef ao_ir_cmp3_is_pending

#define ao_ir_cmp3_is_pending()     ((IFS2 & _IFS2_CMP3IF_MASK) ? true : false)

#endif

#ifndef ao_ir_cmp3_reply

#define ao_ir_cmp3_reply()          { IFS2CLR = _IFS2_CMP3IF_MASK; }

#endif

#ifndef ao_ir_cmp3_request

#define ao_ir_cmp3_request()        { IFS2SET = _IFS2_CMP3IF_MASK; }

#endif

// ----------------------------------------------------------------------------

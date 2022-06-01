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

// Parallel master port interrupts.

// ----------------------------------------------------------------------------

#include <stdbool.h>
#include <sys/attribs.h>
#include <xc.h>

// ----------------------------------------------------------------------------

#ifndef AO_IR_PMP_ATTRIBUTE

#define AO_IR_PMP_ATTRIBUTE         __ISR(_PMP_VECTOR, IPL4SOFT)

#endif

#ifndef AO_IR_PMP_PRIO

#define AO_IR_PMP_PRIO              (4)

#endif

#ifndef AO_IR_PMP_SUBPRIO

#define AO_IR_PMP_SUBPRIO           (0)

#endif

// ----------------------------------------------------------------------------

#ifndef ao_ir_pmp_disable

#define ao_ir_pmp_disable()         { IEC1CLR = _IEC1_PMPIE_MASK; }

#endif

#ifndef ao_ir_pmp_enable

#define ao_ir_pmp_enable()          { IEC1SET = _IEC1_PMPIE_MASK; }

#endif

#ifndef ao_ir_pmp_is_enabled

#define ao_ir_pmp_is_enabled()      ((IEC1 & _IEC1_PMPIE_MASK) ? true : false)

#endif

// ----------------------------------------------------------------------------

#ifndef ao_ir_pmp_is_pending

#define ao_ir_pmp_is_pending()      ((IFS1 & _IFS1_PMPIF_MASK) ? true : false)

#endif

#ifndef ao_ir_pmp_reply

#define ao_ir_pmp_reply()           { IFS1CLR = _IFS1_PMPIF_MASK; }

#endif

#ifndef ao_ir_pmp_request

#define ao_ir_pmp_request()         { IFS1SET = _IFS1_PMPIF_MASK; }

#endif

// ----------------------------------------------------------------------------

#ifndef ao_ir_pmpe_disable

#define ao_ir_pmpe_disable()        { IEC2CLR = _IEC2_PMPEIE_MASK; }

#endif

#ifndef ao_ir_pmpe_enable

#define ao_ir_pmpe_enable()         { IEC2SET = _IEC2_PMPEIE_MASK; }

#endif

#ifndef ao_ir_pmpe_is_enabled

#define ao_ir_pmpe_is_enabled()     ((IEC2 & _IEC2_PMPEIE_MASK) ? true : false)

#endif

// ----------------------------------------------------------------------------

#ifndef ao_ir_pmpe_is_pending

#define ao_ir_pmpe_is_pending()     ((IFS2 & _IFS2_PMPEIF_MASK) ? true : false)

#endif

#ifndef ao_ir_pmpe_reply

#define ao_ir_pmpe_reply()          { IFS2CLR = _IFS2_PMPEIF_MASK; }

#endif

#ifndef ao_ir_pmpe_request

#define ao_ir_pmpe_request()        { IFS2SET = _IFS2_PMPEIF_MASK; }

#endif

// ----------------------------------------------------------------------------

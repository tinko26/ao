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

// Change notification interrupts.

// ----------------------------------------------------------------------------

#include <stdbool.h>
#include <sys/attribs.h>
#include <xc.h>

// ----------------------------------------------------------------------------

#ifndef AO_IR_CNA_ATTRIBUTE

#define AO_IR_CNA_ATTRIBUTE     __ISR(_CHANGE_NOTICE_A_VECTOR, IPL4SOFT)

#endif

#ifndef AO_IR_CNA_PRIO

#define AO_IR_CNA_PRIO          (4)

#endif

#ifndef AO_IR_CNA_SUBPRIO

#define AO_IR_CNA_SUBPRIO       (0)

#endif

// ----------------------------------------------------------------------------

#ifndef ao_ir_cna_disable

#define ao_ir_cna_disable()     { IEC1CLR = _IEC1_CNAIE_MASK; }

#endif

#ifndef ao_ir_cna_enable

#define ao_ir_cna_enable()      { IEC1SET = _IEC1_CNAIE_MASK; }

#endif

#ifndef ao_ir_cna_is_enabled

#define ao_ir_cna_is_enabled()  ((IEC1 & _IEC1_CNAIE_MASK) ? true : false)

#endif

// ----------------------------------------------------------------------------

#ifndef ao_ir_cna_is_pending

#define ao_ir_cna_is_pending()  ((IFS1 & _IFS1_CNAIF_MASK) ? true : false)

#endif

#ifndef ao_ir_cna_reply

#define ao_ir_cna_reply()       { IFS1CLR = _IFS1_CNAIF_MASK; }

#endif

#ifndef ao_ir_cna_request

#define ao_ir_cna_request()     { IFS1SET = _IFS1_CNAIF_MASK; }

#endif

// ----------------------------------------------------------------------------

#ifndef AO_IR_CNB_ATTRIBUTE

#define AO_IR_CNB_ATTRIBUTE     __ISR(_CHANGE_NOTICE_B_VECTOR, IPL4SOFT)

#endif

#ifndef AO_IR_CNB_PRIO

#define AO_IR_CNB_PRIO          (4)

#endif

#ifndef AO_IR_CNB_SUBPRIO

#define AO_IR_CNB_SUBPRIO       (0)

#endif

// ----------------------------------------------------------------------------

#ifndef ao_ir_cnb_disable

#define ao_ir_cnb_disable()     { IEC1CLR = _IEC1_CNBIE_MASK; }

#endif

#ifndef ao_ir_cnb_enable

#define ao_ir_cnb_enable()      { IEC1SET = _IEC1_CNBIE_MASK; }

#endif

#ifndef ao_ir_cnb_is_enabled

#define ao_ir_cnb_is_enabled()  ((IEC1 & _IEC1_CNBIE_MASK) ? true : false)

#endif

// ----------------------------------------------------------------------------

#ifndef ao_ir_cnb_is_pending

#define ao_ir_cnb_is_pending()  ((IFS1 & _IFS1_CNBIF_MASK) ? true : false)

#endif

#ifndef ao_ir_cnb_reply

#define ao_ir_cnb_reply()       { IFS1CLR = _IFS1_CNBIF_MASK; }

#endif

#ifndef ao_ir_cnb_request

#define ao_ir_cnb_request()     { IFS1SET = _IFS1_CNBIF_MASK; }

#endif

// ----------------------------------------------------------------------------

#ifndef AO_IR_CNC_ATTRIBUTE

#define AO_IR_CNC_ATTRIBUTE     __ISR(_CHANGE_NOTICE_C_VECTOR, IPL4SOFT)

#endif

#ifndef AO_IR_CNC_PRIO

#define AO_IR_CNC_PRIO          (4)

#endif

#ifndef AO_IR_CNC_SUBPRIO

#define AO_IR_CNC_SUBPRIO       (0)

#endif

// ----------------------------------------------------------------------------

#ifndef ao_ir_cnc_disable

#define ao_ir_cnc_disable()     { IEC1CLR = _IEC1_CNCIE_MASK; }

#endif

#ifndef ao_ir_cnc_enable

#define ao_ir_cnc_enable()      { IEC1SET = _IEC1_CNCIE_MASK; }

#endif

#ifndef ao_ir_cnc_is_enabled

#define ao_ir_cnc_is_enabled()  ((IEC1 & _IEC1_CNCIE_MASK) ? true : false)

#endif

// ----------------------------------------------------------------------------

#ifndef ao_ir_cnc_is_pending

#define ao_ir_cnc_is_pending()  ((IFS1 & _IFS1_CNCIF_MASK) ? true : false)

#endif

#ifndef ao_ir_cnc_reply

#define ao_ir_cnc_reply()       { IFS1CLR = _IFS1_CNCIF_MASK; }

#endif

#ifndef ao_ir_cnc_request

#define ao_ir_cnc_request()     { IFS1SET = _IFS1_CNCIF_MASK; }

#endif

// ----------------------------------------------------------------------------

#ifndef AO_IR_CND_ATTRIBUTE

#define AO_IR_CND_ATTRIBUTE     __ISR(_CHANGE_NOTICE_D_VECTOR, IPL4SOFT)

#endif

#ifndef AO_IR_CND_PRIO

#define AO_IR_CND_PRIO          (4)

#endif

#ifndef AO_IR_CND_SUBPRIO

#define AO_IR_CND_SUBPRIO       (0)

#endif

// ----------------------------------------------------------------------------

#ifndef ao_ir_cnd_disable

#define ao_ir_cnd_disable()     { IEC1CLR = _IEC1_CNDIE_MASK; }

#endif

#ifndef ao_ir_cnd_enable

#define ao_ir_cnd_enable()      { IEC1SET = _IEC1_CNDIE_MASK; }

#endif

#ifndef ao_ir_cnd_is_enabled

#define ao_ir_cnd_is_enabled()  ((IEC1 & _IEC1_CNDIE_MASK) ? true : false)

#endif

// ----------------------------------------------------------------------------

#ifndef ao_ir_cnd_is_pending

#define ao_ir_cnd_is_pending()  ((IFS1 & _IFS1_CNDIF_MASK) ? true : false)

#endif

#ifndef ao_ir_cnd_reply

#define ao_ir_cnd_reply()       { IFS1CLR = _IFS1_CNDIF_MASK; }

#endif

#ifndef ao_ir_cnd_request

#define ao_ir_cnd_request()     { IFS1SET = _IFS1_CNDIF_MASK; }

#endif

// ----------------------------------------------------------------------------

#ifndef AO_IR_CNE_ATTRIBUTE

#define AO_IR_CNE_ATTRIBUTE     __ISR(_CHANGE_NOTICE_E_VECTOR, IPL4SOFT)

#endif

#ifndef AO_IR_CNE_PRIO

#define AO_IR_CNE_PRIO          (4)

#endif

#ifndef AO_IR_CNE_SUBPRIO

#define AO_IR_CNE_SUBPRIO       (0)

#endif

// ----------------------------------------------------------------------------

#ifndef ao_ir_cne_disable

#define ao_ir_cne_disable()     { IEC1CLR = _IEC1_CNEIE_MASK; }

#endif

#ifndef ao_ir_cne_enable

#define ao_ir_cne_enable()      { IEC1SET = _IEC1_CNEIE_MASK; }

#endif

#ifndef ao_ir_cne_is_enabled

#define ao_ir_cne_is_enabled()  ((IEC1 & _IEC1_CNEIE_MASK) ? true : false)

#endif

// ----------------------------------------------------------------------------

#ifndef ao_ir_cne_is_pending

#define ao_ir_cne_is_pending()  ((IFS1 & _IFS1_CNEIF_MASK) ? true : false)

#endif

#ifndef ao_ir_cne_reply

#define ao_ir_cne_reply()       { IFS1CLR = _IFS1_CNEIF_MASK; }

#endif

#ifndef ao_ir_cne_request

#define ao_ir_cne_request()     { IFS1SET = _IFS1_CNEIF_MASK; }

#endif

// ----------------------------------------------------------------------------

#ifndef AO_IR_CNF_ATTRIBUTE

#define AO_IR_CNF_ATTRIBUTE     __ISR(_CHANGE_NOTICE_F_VECTOR, IPL4SOFT)

#endif

#ifndef AO_IR_CNF_PRIO

#define AO_IR_CNF_PRIO          (4)

#endif

#ifndef AO_IR_CNF_SUBPRIO

#define AO_IR_CNF_SUBPRIO       (0)

#endif

// ----------------------------------------------------------------------------

#ifndef ao_ir_cnf_disable

#define ao_ir_cnf_disable()     { IEC1CLR = _IEC1_CNFIE_MASK; }

#endif

#ifndef ao_ir_cnf_enable

#define ao_ir_cnf_enable()      { IEC1SET = _IEC1_CNFIE_MASK; }

#endif

#ifndef ao_ir_cnf_is_enabled

#define ao_ir_cnf_is_enabled()  ((IEC1 & _IEC1_CNFIE_MASK) ? true : false)

#endif

// ----------------------------------------------------------------------------

#ifndef ao_ir_cnf_is_pending

#define ao_ir_cnf_is_pending()  ((IFS1 & _IFS1_CNFIF_MASK) ? true : false)

#endif

#ifndef ao_ir_cnf_reply

#define ao_ir_cnf_reply()       { IFS1CLR = _IFS1_CNFIF_MASK; }

#endif

#ifndef ao_ir_cnf_request

#define ao_ir_cnf_request()     { IFS1SET = _IFS1_CNFIF_MASK; }

#endif

// ----------------------------------------------------------------------------

#ifndef AO_IR_CNG_ATTRIBUTE

#define AO_IR_CNG_ATTRIBUTE     __ISR(_CHANGE_NOTICE_G_VECTOR, IPL4SOFT)

#endif

#ifndef AO_IR_CNG_PRIO

#define AO_IR_CNG_PRIO          (4)

#endif

#ifndef AO_IR_CNG_SUBPRIO

#define AO_IR_CNG_SUBPRIO       (0)

#endif

// ----------------------------------------------------------------------------

#ifndef ao_ir_cng_disable

#define ao_ir_cng_disable()     { IEC1CLR = _IEC1_CNGIE_MASK; }

#endif

#ifndef ao_ir_cng_enable

#define ao_ir_cng_enable()      { IEC1SET = _IEC1_CNGIE_MASK; }

#endif

#ifndef ao_ir_cng_is_enabled

#define ao_ir_cng_is_enabled()  ((IEC1 & _IEC1_CNGIE_MASK) ? true : false)

#endif

// ----------------------------------------------------------------------------

#ifndef ao_ir_cng_is_pending

#define ao_ir_cng_is_pending()  ((IFS1 & _IFS1_CNGIF_MASK) ? true : false)

#endif

#ifndef ao_ir_cng_reply

#define ao_ir_cng_reply()       { IFS1CLR = _IFS1_CNGIF_MASK; }

#endif

#ifndef ao_ir_cng_request

#define ao_ir_cng_request()     { IFS1SET = _IFS1_CNGIF_MASK; }

#endif

// ----------------------------------------------------------------------------

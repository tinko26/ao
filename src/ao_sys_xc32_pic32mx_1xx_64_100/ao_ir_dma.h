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

// DMA interrupts.

// ----------------------------------------------------------------------------

#include <stdbool.h>
#include <sys/attribs.h>
#include <xc.h>

// ----------------------------------------------------------------------------

#ifndef AO_IR_DMA0_ATTRIBUTE

#define AO_IR_DMA0_ATTRIBUTE        __ISR(_DMA_0_VECTOR, IPL4SOFT)

#endif

#ifndef AO_IR_DMA0_PRIO

#define AO_IR_DMA0_PRIO             (4)

#endif

#ifndef AO_IR_DMA0_SUBPRIO

#define AO_IR_DMA0_SUBPRIO          (0)

#endif

// ----------------------------------------------------------------------------

#ifndef ao_ir_dma0_disable

#define ao_ir_dma0_disable()        { IEC2CLR = _IEC2_DMA0IE_MASK; }

#endif

#ifndef ao_ir_dma0_enable

#define ao_ir_dma0_enable()         { IEC2SET = _IEC2_DMA0IE_MASK; }

#endif

#ifndef ao_ir_dma0_is_enabled

#define ao_ir_dma0_is_enabled()     ((IEC2 & _IEC2_DMA0IE_MASK) ? true : false)

#endif

// ----------------------------------------------------------------------------

#ifndef ao_ir_dma0_is_pending

#define ao_ir_dma0_is_pending()     ((IFS2 & _IFS2_DMA0IF_MASK) ? true : false)

#endif

#ifndef ao_ir_dma0_reply

#define ao_ir_dma0_reply()          { IFS2CLR = _IFS2_DMA0IF_MASK; }

#endif

#ifndef ao_ir_dma0_request

#define ao_ir_dma0_request()        { IFS2SET = _IFS2_DMA0IF_MASK; }

#endif

// ----------------------------------------------------------------------------

#ifndef AO_IR_DMA1_ATTRIBUTE

#define AO_IR_DMA1_ATTRIBUTE        __ISR(_DMA_1_VECTOR, IPL4SOFT)

#endif

#ifndef AO_IR_DMA1_PRIO

#define AO_IR_DMA1_PRIO             (4)

#endif

#ifndef AO_IR_DMA1_SUBPRIO

#define AO_IR_DMA1_SUBPRIO          (0)

#endif

// ----------------------------------------------------------------------------

#ifndef ao_ir_dma1_disable

#define ao_ir_dma1_disable()        { IEC2CLR = _IEC2_DMA1IE_MASK; }

#endif

#ifndef ao_ir_dma1_enable

#define ao_ir_dma1_enable()         { IEC2SET = _IEC2_DMA1IE_MASK; }

#endif

#ifndef ao_ir_dma1_is_enabled

#define ao_ir_dma1_is_enabled()     ((IEC2 & _IEC2_DMA1IE_MASK) ? true : false)

#endif

// ----------------------------------------------------------------------------

#ifndef ao_ir_dma1_is_pending

#define ao_ir_dma1_is_pending()     ((IFS2 & _IFS2_DMA1IF_MASK) ? true : false)

#endif

#ifndef ao_ir_dma1_reply

#define ao_ir_dma1_reply()          { IFS2CLR = _IFS2_DMA1IF_MASK; }

#endif

#ifndef ao_ir_dma1_request

#define ao_ir_dma1_request()        { IFS2SET = _IFS2_DMA1IF_MASK; }

#endif

// ----------------------------------------------------------------------------

#ifndef AO_IR_DMA2_ATTRIBUTE

#define AO_IR_DMA2_ATTRIBUTE        __ISR(_DMA_2_VECTOR, IPL4SOFT)

#endif

#ifndef AO_IR_DMA2_PRIO

#define AO_IR_DMA2_PRIO             (4)

#endif

#ifndef AO_IR_DMA2_SUBPRIO

#define AO_IR_DMA2_SUBPRIO          (0)

#endif

// ----------------------------------------------------------------------------

#ifndef ao_ir_dma2_disable

#define ao_ir_dma2_disable()        { IEC2CLR = _IEC2_DMA2IE_MASK; }

#endif

#ifndef ao_ir_dma2_enable

#define ao_ir_dma2_enable()         { IEC2SET = _IEC2_DMA2IE_MASK; }

#endif

#ifndef ao_ir_dma2_is_enabled

#define ao_ir_dma2_is_enabled()     ((IEC2 & _IEC2_DMA2IE_MASK) ? true : false)

#endif

// ----------------------------------------------------------------------------

#ifndef ao_ir_dma2_is_pending

#define ao_ir_dma2_is_pending()     ((IFS2 & _IFS2_DMA2IF_MASK) ? true : false)

#endif

#ifndef ao_ir_dma2_reply

#define ao_ir_dma2_reply()          { IFS2CLR = _IFS2_DMA2IF_MASK; }

#endif

#ifndef ao_ir_dma2_request

#define ao_ir_dma2_request()        { IFS2SET = _IFS2_DMA2IF_MASK; }

#endif

// ----------------------------------------------------------------------------

#ifndef AO_IR_DMA3_ATTRIBUTE

#define AO_IR_DMA3_ATTRIBUTE        __ISR(_DMA_3_VECTOR, IPL4SOFT)

#endif

#ifndef AO_IR_DMA3_PRIO

#define AO_IR_DMA3_PRIO             (4)

#endif

#ifndef AO_IR_DMA3_SUBPRIO

#define AO_IR_DMA3_SUBPRIO          (0)

#endif

// ----------------------------------------------------------------------------

#ifndef ao_ir_dma3_disable

#define ao_ir_dma3_disable()        { IEC2CLR = _IEC2_DMA3IE_MASK; }

#endif

#ifndef ao_ir_dma3_enable

#define ao_ir_dma3_enable()         { IEC2SET = _IEC2_DMA3IE_MASK; }

#endif

#ifndef ao_ir_dma3_is_enabled

#define ao_ir_dma3_is_enabled()     ((IEC2 & _IEC2_DMA3IE_MASK) ? true : false)

#endif

// ----------------------------------------------------------------------------

#ifndef ao_ir_dma3_is_pending

#define ao_ir_dma3_is_pending()     ((IFS2 & _IFS2_DMA3IF_MASK) ? true : false)

#endif

#ifndef ao_ir_dma3_reply

#define ao_ir_dma3_reply()          { IFS2CLR = _IFS2_DMA3IF_MASK; }

#endif

#ifndef ao_ir_dma3_request

#define ao_ir_dma3_request()        { IFS2SET = _IFS2_DMA3IF_MASK; }

#endif

// ----------------------------------------------------------------------------

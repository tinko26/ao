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

// USB interrupts.

// ----------------------------------------------------------------------------

#include <stdbool.h>
#include <sys/attribs.h>
#include <xc.h>

// ----------------------------------------------------------------------------

#ifndef AO_IR_USB_ATTRIBUTE

#define AO_IR_USB_ATTRIBUTE         __ISR(_USB_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_USB_PRIO

#define AO_IR_USB_PRIO              (4)

#endif

#ifndef AO_IR_USB_SUBPRIO

#define AO_IR_USB_SUBPRIO           (0)

#endif

// ----------------------------------------------------------------------------

#ifndef ao_ir_usb_disable

#define ao_ir_usb_disable()         { IEC4CLR = _IEC4_USBIE_MASK; }

#endif

#ifndef ao_ir_usb_enable

#define ao_ir_usb_enable()          { IEC4SET = _IEC4_USBIE_MASK; }

#endif

#ifndef ao_ir_usb_is_enabled

#define ao_ir_usb_is_enabled()      ((IEC4 & _IEC4_USBIE_MASK) ? true : false)

#endif

// ----------------------------------------------------------------------------

#ifndef ao_ir_usb_is_pending

#define ao_ir_usb_is_pending()      ((IFS4 & _IFS4_USBIF_MASK) ? true : false)

#endif

#ifndef ao_ir_usb_reply

#define ao_ir_usb_reply()           { IFS4CLR = _IFS4_USBIF_MASK; }

#endif

#ifndef ao_ir_usb_request

#define ao_ir_usb_request()         { IFS4SET = _IFS4_USBIF_MASK; }

#endif

// ----------------------------------------------------------------------------

#ifndef AO_IR_USBDMA_ATTRIBUTE

#define AO_IR_USBDMA_ATTRIBUTE      __ISR(_USB_DMA_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_USBDMA_PRIO

#define AO_IR_USBDMA_PRIO           (4)

#endif

#ifndef AO_IR_USBDMA_SUBPRIO

#define AO_IR_USBDMA_SUBPRIO        (0)

#endif

// ----------------------------------------------------------------------------

#ifndef ao_ir_usbdma_disable

#define ao_ir_usbdma_disable()      { IEC4CLR = _IEC4_USBDMAIE_MASK; }

#endif

#ifndef ao_ir_usbdma_enable

#define ao_ir_usbdma_enable()       { IEC4SET = _IEC4_USBDMAIE_MASK; }

#endif

#ifndef ao_ir_usbdma_is_enabled

#define ao_ir_usbdma_is_enabled()   ((IEC4 & _IEC4_USBDMAIE_MASK) ? true : false)

#endif

// ----------------------------------------------------------------------------

#ifndef ao_ir_usbdma_is_pending

#define ao_ir_usbdma_is_pending()   ((IFS4 & _IFS4_USBDMAIF_MASK) ? true : false)

#endif

#ifndef ao_ir_usbdma_reply

#define ao_ir_usbdma_reply()        { IFS4CLR = _IFS4_USBDMAIF_MASK; }

#endif

#ifndef ao_ir_usbdma_request

#define ao_ir_usbdma_request()      { IFS4SET = _IFS4_USBDMAIF_MASK; }

#endif

// ----------------------------------------------------------------------------

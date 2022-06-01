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

#ifndef AO_IR_USB1_ATTRIBUTE

#define AO_IR_USB1_ATTRIBUTE        __ISR(_USB_1_VECTOR, IPL4SOFT)

#endif

#ifndef AO_IR_USB1_PRIO

#define AO_IR_USB1_PRIO             (4)

#endif

#ifndef AO_IR_USB1_SUBPRIO

#define AO_IR_USB1_SUBPRIO          (0)

#endif

// ----------------------------------------------------------------------------

#ifndef ao_ir_usb1_disable

#define ao_ir_usb1_disable()        { IEC1CLR = _IEC1_USB1IE_MASK; }

#endif

#ifndef ao_ir_usb1_enable

#define ao_ir_usb1_enable()         { IEC1SET = _IEC1_USB1IE_MASK; }

#endif

#ifndef ao_ir_usb1_is_enabled

#define ao_ir_usb1_is_enabled()     ((IEC1 & _IEC1_USB1IE_MASK) ? true : false)

#endif

// ----------------------------------------------------------------------------

#ifndef ao_ir_usb1_is_pending

#define ao_ir_usb1_is_pending()     ((IFS1 & _IFS1_USB1IF_MASK) ? true : false)

#endif

#ifndef ao_ir_usb1_reply

#define ao_ir_usb1_reply()          { IFS1CLR = _IFS1_USB1IF_MASK; }

#endif

#ifndef ao_ir_usb1_request

#define ao_ir_usb1_request()        { IFS1SET = _IFS1_USB1IF_MASK; }

#endif

// ----------------------------------------------------------------------------

#ifndef AO_IR_USB2_ATTRIBUTE

#define AO_IR_USB2_ATTRIBUTE        __ISR(_USB_2_VECTOR, IPL4SOFT)

#endif

#ifndef AO_IR_USB2_PRIO

#define AO_IR_USB2_PRIO             (4)

#endif

#ifndef AO_IR_USB2_SUBPRIO

#define AO_IR_USB2_SUBPRIO          (0)

#endif

// ----------------------------------------------------------------------------

#ifndef ao_ir_usb2_disable

#define ao_ir_usb2_disable()        { IEC7CLR = _IEC7_USB2IE_MASK; }

#endif

#ifndef ao_ir_usb2_enable

#define ao_ir_usb2_enable()         { IEC7SET = _IEC7_USB2IE_MASK; }

#endif

#ifndef ao_ir_usb2_is_enabled

#define ao_ir_usb2_is_enabled()     ((IEC7 & _IEC7_USB2IE_MASK) ? true : false)

#endif

// ----------------------------------------------------------------------------

#ifndef ao_ir_usb2_is_pending

#define ao_ir_usb2_is_pending()     ((IFS7 & _IFS7_USB2IF_MASK) ? true : false)

#endif

#ifndef ao_ir_usb2_reply

#define ao_ir_usb2_reply()          { IFS7CLR = _IFS7_USB2IF_MASK; }

#endif

#ifndef ao_ir_usb2_request

#define ao_ir_usb2_request()        { IFS7SET = _IFS7_USB2IF_MASK; }

#endif

// ----------------------------------------------------------------------------

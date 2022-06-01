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

// @seeAlso

// MIPS Technologies. M5150 Software User’s Manual.

// MD00980.

// ----------------------------------------------------------------------------

// @seeAlso

// Microchip. PIC32 Family Reference Manual. Section 50.

// DS60001192.

// ----------------------------------------------------------------------------

typedef enum    ao_sys_exc_t    ao_sys_exc_t;

// ----------------------------------------------------------------------------

#ifndef AO_SYS_EXC

#define AO_SYS_EXC

// ----------------------------------------------------------------------------

enum    ao_sys_exc_t
{
        AO_SYS_EXC_INT          = 0x00,

        AO_SYS_EXC_MOD          = 0x01,

        AO_SYS_EXC_TLBL         = 0x02,

        AO_SYS_EXC_TLBS         = 0x03,

        AO_SYS_EXC_ADEL         = 0x04,

        AO_SYS_EXC_ADES         = 0x05,

        AO_SYS_EXC_IBE          = 0x06,

        AO_SYS_EXC_DBE          = 0x07,

        AO_SYS_EXC_SYS          = 0x08,

        AO_SYS_EXC_BP           = 0x09,

        AO_SYS_EXC_RI           = 0x0A,

        AO_SYS_EXC_CPU          = 0x0B,

        AO_SYS_EXC_OV           = 0x0C,

        AO_SYS_EXC_TR           = 0x0D,

        AO_SYS_EXC_FPE          = 0x0F,

        AO_SYS_EXC_TLBRI        = 0x13,

        AO_SYS_EXC_TLBEI        = 0x14,

        AO_SYS_EXC_WATCH        = 0x17,

        AO_SYS_EXC_MCHECK       = 0x18,

        AO_SYS_EXC_DSPDIS       = 0x1A
};

// ----------------------------------------------------------------------------

#endif

// ----------------------------------------------------------------------------

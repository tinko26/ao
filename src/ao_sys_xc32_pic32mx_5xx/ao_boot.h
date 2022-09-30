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

// Booting.

// ----------------------------------------------------------------------------

#include <ao_ir.h>
#include <xc.h>

// ----------------------------------------------------------------------------

#ifndef ao_boot_ir_can1

#define ao_boot_ir_can1()                                                   \
{                                                                           \
        IPC11bits.CAN1IP = (AO_IR_CAN1_PRIO);                               \
        IPC11bits.CAN1IS = (AO_IR_CAN1_SUBPRIO);                            \
}

#endif

#ifndef ao_boot_ir_can2

#define ao_boot_ir_can2()                                                   \
{                                                                           \
        IPC11bits.CAN2IP = (AO_IR_CAN2_PRIO);                               \
        IPC11bits.CAN2IS = (AO_IR_CAN2_SUBPRIO);                            \
}

#endif

// ----------------------------------------------------------------------------

#ifndef ao_boot_ir_cs0

#define ao_boot_ir_cs0()                                                    \
{                                                                           \
        IPC0bits.CS0IP = (AO_IR_CS0_PRIO);                                  \
        IPC0bits.CS0IS = (AO_IR_CS0_SUBPRIO);                               \
}

#endif

#ifndef ao_boot_ir_cs1

#define ao_boot_ir_cs1()                                                    \
{                                                                           \
        IPC0bits.CS1IP = (AO_IR_CS1_PRIO);                                  \
        IPC0bits.CS1IS = (AO_IR_CS1_SUBPRIO);                               \
}

#endif

// ----------------------------------------------------------------------------

#ifndef ao_boot_ir_ct

#define ao_boot_ir_ct()                                                     \
{                                                                           \
        IPC0bits.CTIP = (AO_IR_CT_PRIO);                                    \
        IPC0bits.CTIS = (AO_IR_CT_SUBPRIO);                                 \
}

#endif

// ----------------------------------------------------------------------------

#ifndef ao_boot_ir_int0

#define ao_boot_ir_int0()                                                   \
{                                                                           \
        IPC0bits.INT0IP = (AO_IR_INT0_PRIO);                                \
        IPC0bits.INT0IS = (AO_IR_INT0_SUBPRIO);                             \
}

#endif

#ifndef ao_boot_ir_int1

#define ao_boot_ir_int1()                                                   \
{                                                                           \
        IPC1bits.INT1IP = (AO_IR_INT1_PRIO);                                \
        IPC1bits.INT1IS = (AO_IR_INT1_SUBPRIO);                             \
}

#endif

#ifndef ao_boot_ir_int2

#define ao_boot_ir_int2()                                                   \
{                                                                           \
        IPC2bits.INT2IP = (AO_IR_INT2_PRIO);                                \
        IPC2bits.INT2IS = (AO_IR_INT2_SUBPRIO);                             \
}

#endif

#ifndef ao_boot_ir_int3

#define ao_boot_ir_int3()                                                   \
{                                                                           \
        IPC3bits.INT3IP = (AO_IR_INT3_PRIO);                                \
        IPC3bits.INT3IS = (AO_IR_INT3_SUBPRIO);                             \
}

#endif

#ifndef ao_boot_ir_int4

#define ao_boot_ir_int4()                                                   \
{                                                                           \
        IPC4bits.INT4IP = (AO_IR_INT4_PRIO);                                \
        IPC4bits.INT4IS = (AO_IR_INT4_SUBPRIO);                             \
}

#endif

// ----------------------------------------------------------------------------

#ifndef ao_boot_ir_u1

#define ao_boot_ir_u1()                                                     \
{                                                                           \
        IPC6bits.U1IP = (AO_IR_U1_PRIO);                                    \
        IPC6bits.U1IS = (AO_IR_U1_SUBPRIO);                                 \
}

#endif

#ifndef ao_boot_ir_u2

#define ao_boot_ir_u2()                                                     \
{                                                                           \
        IPC8bits.U2IP = (AO_IR_U2_PRIO);                                    \
        IPC8bits.U2IS = (AO_IR_U2_SUBPRIO);                                 \
}

#endif

#ifndef ao_boot_ir_u3

#define ao_boot_ir_u3()                                                     \
{                                                                           \
        IPC7bits.U3IP = (AO_IR_U3_PRIO);                                    \
        IPC7bits.U3IS = (AO_IR_U3_SUBPRIO);                                 \
}

#endif

#ifndef ao_boot_ir_u4

#define ao_boot_ir_u4()                                                     \
{                                                                           \
        IPC12bits.U4IP = (AO_IR_U4_PRIO);                                   \
        IPC12bits.U4IS = (AO_IR_U4_SUBPRIO);                                \
}

#endif

#ifndef ao_boot_ir_u5

#define ao_boot_ir_u5()                                                     \
{                                                                           \
        IPC12bits.U5IP = (AO_IR_U5_PRIO);                                   \
        IPC12bits.U5IS = (AO_IR_U5_SUBPRIO);                                \
}

#endif

#ifndef ao_boot_ir_u6

#define ao_boot_ir_u6()                                                     \
{                                                                           \
        IPC12bits.U6IP = (AO_IR_U6_PRIO);                                   \
        IPC12bits.U6IS = (AO_IR_U6_SUBPRIO);                                \
}

#endif

// ----------------------------------------------------------------------------

void    ao_boot_sys_pcache();

// ----------------------------------------------------------------------------

#include_next <ao_boot.h>

// ----------------------------------------------------------------------------

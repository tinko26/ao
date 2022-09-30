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
        IPC37bits.CAN1IP = (AO_IR_CAN1_PRIO);                               \
        IPC37bits.CAN1IS = (AO_IR_CAN1_SUBPRIO);                            \
}

#endif

#ifndef ao_boot_ir_can2

#define ao_boot_ir_can2()                                                   \
{                                                                           \
        IPC38bits.CAN2IP = (AO_IR_CAN2_PRIO);                               \
        IPC38bits.CAN2IS = (AO_IR_CAN2_SUBPRIO);                            \
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
        IPC2bits.INT1IP = (AO_IR_INT1_PRIO);                                \
        IPC2bits.INT1IS = (AO_IR_INT1_SUBPRIO);                             \
}

#endif

#ifndef ao_boot_ir_int2

#define ao_boot_ir_int2()                                                   \
{                                                                           \
        IPC3bits.INT2IP = (AO_IR_INT2_PRIO);                                \
        IPC3bits.INT2IS = (AO_IR_INT2_SUBPRIO);                             \
}

#endif

#ifndef ao_boot_ir_int3

#define ao_boot_ir_int3()                                                   \
{                                                                           \
        IPC4bits.INT3IP = (AO_IR_INT3_PRIO);                                \
        IPC4bits.INT3IS = (AO_IR_INT3_SUBPRIO);                             \
}

#endif

#ifndef ao_boot_ir_int4

#define ao_boot_ir_int4()                                                   \
{                                                                           \
        IPC5bits.INT4IP = (AO_IR_INT4_PRIO);                                \
        IPC5bits.INT4IS = (AO_IR_INT4_SUBPRIO);                             \
}

#endif

// ----------------------------------------------------------------------------

#ifndef ao_boot_ir_srs

#define ao_boot_ir_srs()                                                    \
{                                                                           \
        PRISSbits.PRI1SS = 0;                                               \
        PRISSbits.PRI2SS = 2;                                               \
        PRISSbits.PRI3SS = 3;                                               \
        PRISSbits.PRI4SS = 4;                                               \
        PRISSbits.PRI5SS = 5;                                               \
        PRISSbits.PRI6SS = 6;                                               \
        PRISSbits.PRI7SS = 7;                                               \
}

#endif

// ----------------------------------------------------------------------------

#ifndef ao_boot_ir_u1e

#define ao_boot_ir_u1e()                                                    \
{                                                                           \
        IPC28bits.U1EIP = (AO_IR_U1E_PRIO);                                 \
        IPC28bits.U1EIS = (AO_IR_U1E_SUBPRIO);                              \
}

#endif

#ifndef ao_boot_ir_u1rx

#define ao_boot_ir_u1rx()                                                   \
{                                                                           \
        IPC28bits.U1RXIP = (AO_IR_U1RX_PRIO);                               \
        IPC28bits.U1RXIS = (AO_IR_U1RX_SUBPRIO);                            \
}

#endif

#ifndef ao_boot_ir_u1tx

#define ao_boot_ir_u1tx()                                                   \
{                                                                           \
        IPC28bits.U1TXIP = (AO_IR_U1TX_PRIO);                               \
        IPC28bits.U1TXIS = (AO_IR_U1TX_SUBPRIO);                            \
}

#endif

#ifndef ao_boot_ir_u2e

#define ao_boot_ir_u2e()                                                    \
{                                                                           \
        IPC36bits.U2EIP = (AO_IR_U2E_PRIO);                                 \
        IPC36bits.U2EIS = (AO_IR_U2E_SUBPRIO);                              \
}

#endif

#ifndef ao_boot_ir_u2rx

#define ao_boot_ir_u2rx()                                                   \
{                                                                           \
        IPC36bits.U2RXIP = (AO_IR_U2RX_PRIO);                               \
        IPC36bits.U2RXIS = (AO_IR_U2RX_SUBPRIO);                            \
}

#endif

#ifndef ao_boot_ir_u2tx

#define ao_boot_ir_u2tx()                                                   \
{                                                                           \
        IPC36bits.U2TXIP = (AO_IR_U2TX_PRIO);                               \
        IPC36bits.U2TXIS = (AO_IR_U2TX_SUBPRIO);                            \
}

#endif

#ifndef ao_boot_ir_u3e

#define ao_boot_ir_u3e()                                                    \
{                                                                           \
        IPC39bits.U3EIP = (AO_IR_U3E_PRIO);                                 \
        IPC39bits.U3EIS = (AO_IR_U3E_SUBPRIO);                              \
}

#endif

#ifndef ao_boot_ir_u3rx

#define ao_boot_ir_u3rx()                                                   \
{                                                                           \
        IPC39bits.U3RXIP = (AO_IR_U3RX_PRIO);                               \
        IPC39bits.U3RXIS = (AO_IR_U3RX_SUBPRIO);                            \
}

#endif

#ifndef ao_boot_ir_u3tx

#define ao_boot_ir_u3tx()                                                   \
{                                                                           \
        IPC39bits.U3TXIP = (AO_IR_U3TX_PRIO);                               \
        IPC39bits.U3TXIS = (AO_IR_U3TX_SUBPRIO);                            \
}

#endif

#ifndef ao_boot_ir_u4e

#define ao_boot_ir_u4e()                                                    \
{                                                                           \
        IPC42bits.U4EIP = (AO_IR_U4E_PRIO);                                 \
        IPC42bits.U4EIS = (AO_IR_U4E_SUBPRIO);                              \
}

#endif

#ifndef ao_boot_ir_u4rx

#define ao_boot_ir_u4rx()                                                   \
{                                                                           \
        IPC42bits.U4RXIP = (AO_IR_U4RX_PRIO);                               \
        IPC42bits.U4RXIS = (AO_IR_U4RX_SUBPRIO);                            \
}

#endif

#ifndef ao_boot_ir_u4tx

#define ao_boot_ir_u4tx()                                                   \
{                                                                           \
        IPC43bits.U4TXIP = (AO_IR_U4TX_PRIO);                               \
        IPC43bits.U4TXIS = (AO_IR_U4TX_SUBPRIO);                            \
}

#endif

#ifndef ao_boot_ir_u5e

#define ao_boot_ir_u5e()                                                    \
{                                                                           \
        IPC44bits.U5EIP = (AO_IR_U5E_PRIO);                                 \
        IPC44bits.U5EIS = (AO_IR_U5E_SUBPRIO);                              \
}

#endif

#ifndef ao_boot_ir_u5rx

#define ao_boot_ir_u5rx()                                                   \
{                                                                           \
        IPC45bits.U5RXIP = (AO_IR_U5RX_PRIO);                               \
        IPC45bits.U5RXIS = (AO_IR_U5RX_SUBPRIO);                            \
}

#endif

#ifndef ao_boot_ir_u5tx

#define ao_boot_ir_u5tx()                                                   \
{                                                                           \
        IPC45bits.U5TXIP = (AO_IR_U5TX_PRIO);                               \
        IPC45bits.U5TXIS = (AO_IR_U5TX_SUBPRIO);                            \
}

#endif

#ifndef ao_boot_ir_u6e

#define ao_boot_ir_u6e()                                                    \
{                                                                           \
        IPC47bits.U6EIP = (AO_IR_U6E_PRIO);                                 \
        IPC47bits.U6EIS = (AO_IR_U6E_SUBPRIO);                              \
}

#endif

#ifndef ao_boot_ir_u6rx

#define ao_boot_ir_u6rx()                                                   \
{                                                                           \
        IPC47bits.U6RXIP = (AO_IR_U6RX_PRIO);                               \
        IPC47bits.U6RXIS = (AO_IR_U6RX_SUBPRIO);                            \
}

#endif

#ifndef ao_boot_ir_u6tx

#define ao_boot_ir_u6tx()                                                   \
{                                                                           \
        IPC47bits.U6TXIP = (AO_IR_U6TX_PRIO);                               \
        IPC47bits.U6TXIS = (AO_IR_U6TX_SUBPRIO);                            \
}

#endif

// ----------------------------------------------------------------------------

void    ao_boot_sys_pcache();

// ----------------------------------------------------------------------------

#include_next <ao_boot.h>

// ----------------------------------------------------------------------------

---
author: "Stefan Wagner"
date: 2022-09-22
draft: true
permalink: /api/src/ao_sys_xc32_pic32mk_gpg/ao_boot.h/
toc: true
---

# Include

[`ao_ir.h`](ao_ir.h.md) <br/>
`xc.h`

# Functions

## `ao_boot_ir_cs0`

```c
#define ao_boot_ir_cs0()                \
{                                       \
    IPC0bits.CS0IP = AO_IR_CS0_PRIO;    \
    IPC0bits.CS0IS = AO_IR_CS0_SUBPRIO; \
}
```

Sets up both priority and subpriority of the core software interrupt 0.

## `ao_boot_ir_cs1`

```c
#define ao_boot_ir_cs1()                \
{                                       \
    IPC0bits.CS1IP = AO_IR_CS1_PRIO;    \
    IPC0bits.CS1IS = AO_IR_CS1_SUBPRIO; \
}
```

Sets up both priority and subpriority of the core software interrupt 1.

## `ao_boot_ir_ct`

```c
#define ao_boot_ir_ct()               \
{                                     \
    IPC0bits.CTIP = AO_IR_CT_PRIO;    \
    IPC0bits.CTIS = AO_IR_CT_SUBPRIO; \
}
```

Sets up both priority and subpriority of the core timer interrupt.

## `ao_boot_ir_int0`

```c
#define ao_boot_ir_int0()                 \
{                                         \
    IPC0bits.INT0IP = AO_IR_INT0_PRIO;    \
    IPC0bits.INT0IS = AO_IR_INT0_SUBPRIO; \
}
```

Sets up both priority and subpriority of the external interrupt 0.

## `ao_boot_ir_int1`

```c
#define ao_boot_ir_int1()                 \
{                                         \
    IPC2bits.INT1IP = AO_IR_INT1_PRIO;    \
    IPC2bits.INT1IS = AO_IR_INT1_SUBPRIO; \
}
```

Sets up both priority and subpriority of the external interrupt 1.

## `ao_boot_ir_int2`

```c
#define ao_boot_ir_int2()                 \
{                                         \
    IPC3bits.INT2IP = AO_IR_INT2_PRIO;    \
    IPC3bits.INT2IS = AO_IR_INT2_SUBPRIO; \
}
```

Sets up both priority and subpriority of the external interrupt 2.

## `ao_boot_ir_int3`

```c
#define ao_boot_ir_int3()                 \
{                                         \
    IPC4bits.INT3IP = AO_IR_INT3_PRIO;    \
    IPC4bits.INT3IS = AO_IR_INT3_SUBPRIO; \
}
```

Sets up both priority and subpriority of the external interrupt 3.

## `ao_boot_ir_int4`

```c
#define ao_boot_ir_int4()                 \
{                                         \
    IPC5bits.INT4IP = AO_IR_INT4_PRIO;    \
    IPC5bits.INT4IS = AO_IR_INT4_SUBPRIO; \
}
```

Sets up both priority and subpriority of the external interrupt 4.

## `ao_boot_ir_srs`

```c
#define ao_boot_ir_srs()  \
{                         \
    PRISSbits.PRI1SS = 0; \
    PRISSbits.PRI2SS = 2; \
    PRISSbits.PRI3SS = 3; \
    PRISSbits.PRI4SS = 4; \
    PRISSbits.PRI5SS = 5; \
    PRISSbits.PRI6SS = 6; \
    PRISSbits.PRI7SS = 7; \
}
```

Sets up the usage of a shadow register set for all priorities. Especially, this function prevents priority 1 interrupts, hence the task switch interrupt, from using a shadow register set.

## `ao_boot_ir_u1e`

```c
#define ao_boot_ir_u1e()                \
{                                       \
    IPC9bits.U1EIP = AO_IR_U1E_PRIO;    \
    IPC9bits.U1EIS = AO_IR_U1E_SUBPRIO; \
}
```

Sets up both priority and subpriority of the UART 1 error interrupt.

## `ao_boot_ir_u1rx`

```c
#define ao_boot_ir_u1rx()                 \
{                                         \
    IPC9bits.U1RXIP = AO_IR_U1RX_PRIO;    \
    IPC9bits.U1RXIS = AO_IR_U1RX_SUBPRIO; \
}
```

Sets up both priority and subpriority of the UART 1 receive interrupt.

## `ao_boot_ir_u1tx`

```c
#define ao_boot_ir_u1tx()                  \
{                                          \
    IPC10bits.U1TXIP = AO_IR_U1TX_PRIO;    \
    IPC10bits.U1TXIS = AO_IR_U1TX_SUBPRIO; \
}
```

Sets up both priority and subpriority of the UART 1 transmit interrupt.

## `ao_boot_ir_u2e`

```c
#define ao_boot_ir_u2e()                 \
{                                        \
    IPC14bits.U2EIP = AO_IR_U2E_PRIO;    \
    IPC14bits.U2EIS = AO_IR_U2E_SUBPRIO; \
}
```

Sets up both priority and subpriority of the UART 2 error interrupt.

## `ao_boot_ir_u2rx`

```c
#define ao_boot_ir_u2rx()                  \
{                                          \
    IPC14bits.U2RXIP = AO_IR_U2RX_PRIO;    \
    IPC14bits.U2RXIS = AO_IR_U2RX_SUBPRIO; \
}
```

Sets up both priority and subpriority of the UART 2 receive interrupt.

## `ao_boot_ir_u2tx`

```c
#define ao_boot_ir_u2tx()                  \
{                                          \
    IPC14bits.U2TXIP = AO_IR_U2TX_PRIO;    \
    IPC14bits.U2TXIS = AO_IR_U2TX_SUBPRIO; \
}
```

Sets up both priority and subpriority of the UART 2 transmit interrupt.

## `ao_boot_sys_pcache`

```c
void ao_boot_sys_pcache();
```

Sets up the prefetch cache.

# Include Next

[`ao_boot.h`](../ao_sys_xc32_pic32/ao_boot.h.md)

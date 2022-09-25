---
author: "Stefan Wagner"
date: 2022-09-25
draft: true
permalink: /api/src/ao_sys_xc32_pic32mz_dak/ao_boot.h/
toc: true
---

# Include

| [`ao_ir.h`](ao_ir.h.md) |
| `xc.h` |

# Functions

## `ao_boot_ir_can1`

```c
#define ao_boot_ir_can1()                  \
{                                          \
    IPC37bits.CAN1IP = AO_IR_CAN1_PRIO;    \
    IPC37bits.CAN1IS = AO_IR_CAN1_SUBPRIO; \
}
```

Sets up both priority and subpriority of the CAN 1 interrupt.

## `ao_boot_ir_can2`

```c
#define ao_boot_ir_can2()                  \
{                                          \
    IPC38bits.CAN2IP = AO_IR_CAN2_PRIO;    \
    IPC38bits.CAN2IS = AO_IR_CAN2_SUBPRIO; \
}
```

Sets up both priority and subpriority of the CAN 2 interrupt.

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

Sets up the usage of a shadow register set for all priorities. Especially, this function prevents priority 1 interrupts, hence the task interrupt, from using a shadow register set.

## `ao_boot_ir_u1e`

```c
#define ao_boot_ir_u1e()                 \
{                                        \
    IPC28bits.U1EIP = AO_IR_U1E_PRIO;    \
    IPC28bits.U1EIS = AO_IR_U1E_SUBPRIO; \
}
```

Sets up both priority and subpriority of the UART 1 error interrupt.

## `ao_boot_ir_u1rx`

```c
#define ao_boot_ir_u1rx()                  \
{                                          \
    IPC28bits.U1RXIP = AO_IR_U1RX_PRIO;    \
    IPC28bits.U1RXIS = AO_IR_U1RX_SUBPRIO; \
}
```

Sets up both priority and subpriority of the UART 1 receive interrupt.

## `ao_boot_ir_u1tx`

```c
#define ao_boot_ir_u1tx()                  \
{                                          \
    IPC28bits.U1TXIP = AO_IR_U1TX_PRIO;    \
    IPC28bits.U1TXIS = AO_IR_U1TX_SUBPRIO; \
}
```

Sets up both priority and subpriority of the UART 1 transmit interrupt.

## `ao_boot_ir_u2e`

```c
#define ao_boot_ir_u2e()                 \
{                                        \
    IPC36bits.U2EIP = AO_IR_U2E_PRIO;    \
    IPC36bits.U2EIS = AO_IR_U2E_SUBPRIO; \
}
```

Sets up both priority and subpriority of the UART 2 error interrupt.

## `ao_boot_ir_u2rx`

```c
#define ao_boot_ir_u2rx()                  \
{                                          \
    IPC36bits.U2RXIP = AO_IR_U2RX_PRIO;    \
    IPC36bits.U2RXIS = AO_IR_U2RX_SUBPRIO; \
}
```

Sets up both priority and subpriority of the UART 2 receive interrupt.

## `ao_boot_ir_u2tx`

```c
#define ao_boot_ir_u2tx()                  \
{                                          \
    IPC36bits.U2TXIP = AO_IR_U2TX_PRIO;    \
    IPC36bits.U2TXIS = AO_IR_U2TX_SUBPRIO; \
}
```

Sets up both priority and subpriority of the UART 2 transmit interrupt.

## `ao_boot_ir_u3e`

```c
#define ao_boot_ir_u3e()                 \
{                                        \
    IPC39bits.U3EIP = AO_IR_U3E_PRIO;    \
    IPC39bits.U3EIS = AO_IR_U3E_SUBPRIO; \
}
```

Sets up both priority and subpriority of the UART 3 error interrupt.

## `ao_boot_ir_u3rx`

```c
#define ao_boot_ir_u3rx()                  \
{                                          \
    IPC39bits.U3RXIP = AO_IR_U3RX_PRIO;    \
    IPC39bits.U3RXIS = AO_IR_U3RX_SUBPRIO; \
}
```

Sets up both priority and subpriority of the UART 3 receive interrupt.

## `ao_boot_ir_u3tx`

```c
#define ao_boot_ir_u3tx()                  \
{                                          \
    IPC39bits.U3TXIP = AO_IR_U3TX_PRIO;    \
    IPC39bits.U3TXIS = AO_IR_U3TX_SUBPRIO; \
}
```

Sets up both priority and subpriority of the UART 3 transmit interrupt.

## `ao_boot_ir_u4e`

```c
#define ao_boot_ir_u4e()                 \
{                                        \
    IPC42bits.U4EIP = AO_IR_U4E_PRIO;    \
    IPC42bits.U4EIS = AO_IR_U4E_SUBPRIO; \
}
```

Sets up both priority and subpriority of the UART 4 error interrupt.

## `ao_boot_ir_u4rx`

```c
#define ao_boot_ir_u4rx()                  \
{                                          \
    IPC42bits.U4RXIP = AO_IR_U4RX_PRIO;    \
    IPC42bits.U4RXIS = AO_IR_U4RX_SUBPRIO; \
}
```

Sets up both priority and subpriority of the UART 4 receive interrupt.

## `ao_boot_ir_u4tx`

```c
#define ao_boot_ir_u4tx()                  \
{                                          \
    IPC43bits.U4TXIP = AO_IR_U4TX_PRIO;    \
    IPC43bits.U4TXIS = AO_IR_U4TX_SUBPRIO; \
}
```

Sets up both priority and subpriority of the UART 4 transmit interrupt.

## `ao_boot_ir_u5e`

```c
#define ao_boot_ir_u5e()                 \
{                                        \
    IPC44bits.U5EIP = AO_IR_U5E_PRIO;    \
    IPC44bits.U5EIS = AO_IR_U5E_SUBPRIO; \
}
```

Sets up both priority and subpriority of the UART 5 error interrupt.

## `ao_boot_ir_u5rx`

```c
#define ao_boot_ir_u5rx()                  \
{                                          \
    IPC45bits.U5RXIP = AO_IR_U5RX_PRIO;    \
    IPC45bits.U5RXIS = AO_IR_U5RX_SUBPRIO; \
}
```

Sets up both priority and subpriority of the UART 5 receive interrupt.

## `ao_boot_ir_u5tx`

```c
#define ao_boot_ir_u5tx()                  \
{                                          \
    IPC45bits.U5TXIP = AO_IR_U5TX_PRIO;    \
    IPC45bits.U5TXIS = AO_IR_U5TX_SUBPRIO; \
}
```

Sets up both priority and subpriority of the UART 5 transmit interrupt.

## `ao_boot_ir_u6e`

```c
#define ao_boot_ir_u6e()                 \
{                                        \
    IPC47bits.U6EIP = AO_IR_U6E_PRIO;    \
    IPC47bits.U6EIS = AO_IR_U6E_SUBPRIO; \
}
```

Sets up both priority and subpriority of the UART 6 error interrupt.

## `ao_boot_ir_u6rx`

```c
#define ao_boot_ir_u6rx()                  \
{                                          \
    IPC47bits.U6RXIP = AO_IR_U6RX_PRIO;    \
    IPC47bits.U6RXIS = AO_IR_U6RX_SUBPRIO; \
}
```

Sets up both priority and subpriority of the UART 6 receive interrupt.

## `ao_boot_ir_u6tx`

```c
#define ao_boot_ir_u6tx()                  \
{                                          \
    IPC47bits.U6TXIP = AO_IR_U6TX_PRIO;    \
    IPC47bits.U6TXIS = AO_IR_U6TX_SUBPRIO; \
}
```

Sets up both priority and subpriority of the UART 6 transmit interrupt.

## `ao_boot_sys_pcache`

```c
void ao_boot_sys_pcache();
```

Sets up the prefetch cache.

# Include Next

| [`ao_boot.h`](../ao_sys_xc32_pic32/ao_boot.h.md) |

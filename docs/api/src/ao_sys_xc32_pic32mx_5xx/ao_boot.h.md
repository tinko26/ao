---
author: "Stefan Wagner"
date: 2022-09-22
draft: true
permalink: /api/src/ao_sys_xc32_pic32mx_5xx/ao_boot.h/
toc: true
---

# Include

| [`ao_ir.h`](ao_ir.h.md) |
| `xc.h` |

# Functions

## `ao_boot_ir_can1`

```c
#define ao_boot_ir_can1()                    \
{                                            \
    IPC11bits.CAN1IP = (AO_IR_CAN1_PRIO);    \
    IPC11bits.CAN1IS = (AO_IR_CAN1_SUBPRIO); \
}
```

Sets up both priority and subpriority of the CAN 1 interrupt.

## `ao_boot_ir_can2`

```c
#define ao_boot_ir_can2()                    \
{                                            \
    IPC11bits.CAN2IP = (AO_IR_CAN2_PRIO);    \
    IPC11bits.CAN2IS = (AO_IR_CAN2_SUBPRIO); \
}
```

Sets up both priority and subpriority of the CAN 2 interrupt.

## `ao_boot_ir_cs0`

```c
#define ao_boot_ir_cs0()                  \
{                                         \
    IPC0bits.CS0IP = (AO_IR_CS0_PRIO);    \
    IPC0bits.CS0IS = (AO_IR_CS0_SUBPRIO); \
}
```

Sets up both priority and subpriority of the core software interrupt 0.

## `ao_boot_ir_cs1`

```c
#define ao_boot_ir_cs1()                  \
{                                         \
    IPC0bits.CS1IP = (AO_IR_CS1_PRIO);    \
    IPC0bits.CS1IS = (AO_IR_CS1_SUBPRIO); \
}
```

Sets up both priority and subpriority of the core software interrupt 1.

## `ao_boot_ir_ct`

```c
#define ao_boot_ir_ct()                 \
{                                       \
    IPC0bits.CTIP = (AO_IR_CT_PRIO);    \
    IPC0bits.CTIS = (AO_IR_CT_SUBPRIO); \
}
```

Sets up both priority and subpriority of the core timer interrupt.

## `ao_boot_ir_int0`

```c
#define ao_boot_ir_int0()                   \
{                                           \
    IPC0bits.INT0IP = (AO_IR_INT0_PRIO);    \
    IPC0bits.INT0IS = (AO_IR_INT0_SUBPRIO); \
}
```

Sets up both priority and subpriority of the external interrupt 0.

## `ao_boot_ir_int1`

```c
#define ao_boot_ir_int1()                   \
{                                           \
    IPC1bits.INT1IP = (AO_IR_INT1_PRIO);    \
    IPC1bits.INT1IS = (AO_IR_INT1_SUBPRIO); \
}
```

Sets up both priority and subpriority of the external interrupt 1.

## `ao_boot_ir_int2`

```c
#define ao_boot_ir_int2()                   \
{                                           \
    IPC2bits.INT2IP = (AO_IR_INT2_PRIO);    \
    IPC2bits.INT2IS = (AO_IR_INT2_SUBPRIO); \
}
```

Sets up both priority and subpriority of the external interrupt 2.

## `ao_boot_ir_int3`

```c
#define ao_boot_ir_int3()                   \
{                                           \
    IPC3bits.INT3IP = (AO_IR_INT3_PRIO);    \
    IPC3bits.INT3IS = (AO_IR_INT3_SUBPRIO); \
}
```

Sets up both priority and subpriority of the external interrupt 3.

## `ao_boot_ir_int4`

```c
#define ao_boot_ir_int4()                   \
{                                           \
    IPC4bits.INT4IP = (AO_IR_INT4_PRIO);    \
    IPC4bits.INT4IS = (AO_IR_INT4_SUBPRIO); \
}
```

Sets up both priority and subpriority of the external interrupt 4.

## `ao_boot_ir_u1`

```c
#define ao_boot_ir_u1()                 \
{                                       \
    IPC6bits.U1IP = (AO_IR_U1_PRIO);    \
    IPC6bits.U1IS = (AO_IR_U1_SUBPRIO); \
}
```

Sets up both priority and subpriority of the UART 1 interrupt.

## `ao_boot_ir_u2`

```c
#define ao_boot_ir_u2()                 \
{                                       \
    IPC8bits.U2IP = (AO_IR_U2_PRIO);    \
    IPC8bits.U2IS = (AO_IR_U2_SUBPRIO); \
}
```

Sets up both priority and subpriority of the UART 2 interrupt.

## `ao_boot_ir_u3`

```c
#define ao_boot_ir_u3()                 \
{                                       \
    IPC7bits.U3IP = (AO_IR_U3_PRIO);    \
    IPC7bits.U3IS = (AO_IR_U3_SUBPRIO); \
}
```

Sets up both priority and subpriority of the UART 3 interrupt.

## `ao_boot_ir_u4`

```c
#define ao_boot_ir_u4()                  \
{                                        \
    IPC12bits.U4IP = (AO_IR_U4_PRIO);    \
    IPC12bits.U4IS = (AO_IR_U4_SUBPRIO); \
}
```

Sets up both priority and subpriority of the UART 4 interrupt.

## `ao_boot_ir_u5`

```c
#define ao_boot_ir_u5()                  \
{                                        \
    IPC12bits.U5IP = (AO_IR_U5_PRIO);    \
    IPC12bits.U5IS = (AO_IR_U5_SUBPRIO); \
}
```

Sets up both priority and subpriority of the UART 5 interrupt.

## `ao_boot_ir_u6`

```c
#define ao_boot_ir_u6()                  \
{                                        \
    IPC12bits.U6IP = (AO_IR_U6_PRIO);    \
    IPC12bits.U6IS = (AO_IR_U6_SUBPRIO); \
}
```

Sets up both priority and subpriority of the UART 6 interrupt.

## `ao_boot_sys_pcache`

```c
void ao_boot_sys_pcache();
```

Sets up the prefetch cache.

# Include Next

| [`ao_boot.h`](../ao_sys_xc32_pic32mx/ao_boot.h.md) |

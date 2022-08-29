---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The ao_sys_xc32_pic32mx_5xx/ao_boot.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys_xc32_pic32mx_5xx/ao_boot.h/ 
subtitle: "ao_sys_xc32_pic32mx_5xx"
title: "ao_boot.h"
toc: true
---

```c
#include <ao_ir.h>
#include <ao_sys.h>
#include <xc.h>

#ifndef ao_boot_ir_adc

#define ao_boot_ir_adc()                                                    \
{                                                                           \
        IPC6bits.AD1IP = AO_IR_ADC_PRIO;                                    \
        IPC6bits.AD1IS = AO_IR_ADC_SUBPRIO;                                 \
}

#endif

#ifndef ao_boot_ir_can1

#define ao_boot_ir_can1()                                                   \
{                                                                           \
        IPC11bits.CAN1IP = AO_IR_CAN1_PRIO;                                 \
        IPC11bits.CAN1IS = AO_IR_CAN1_SUBPRIO;                              \
}

#endif

#ifndef ao_boot_ir_can2

#define ao_boot_ir_can2()                                                   \
{                                                                           \
        IPC11bits.CAN2IP = AO_IR_CAN2_PRIO;                                 \
        IPC11bits.CAN2IS = AO_IR_CAN2_SUBPRIO;                              \
}

#endif

#ifndef ao_boot_ir_cmp1

#define ao_boot_ir_cmp1()                                                   \
{                                                                           \
        IPC7bits.CMP1IP = AO_IR_CMP1_PRIO;                                  \
        IPC7bits.CMP1IS = AO_IR_CMP1_SUBPRIO;                               \
}

#endif

#ifndef ao_boot_ir_cmp2

#define ao_boot_ir_cmp2()                                                   \
{                                                                           \
        IPC7bits.CMP2IP = AO_IR_CMP2_PRIO;                                  \
        IPC7bits.CMP2IS = AO_IR_CMP2_SUBPRIO;                               \
}

#endif

#ifndef ao_boot_ir_cn

#define ao_boot_ir_cn()                                                     \
{                                                                           \
        IPC6bits.CNIP = AO_IR_CN_PRIO;                                      \
        IPC6bits.CNIS = AO_IR_CN_SUBPRIO;                                   \
}

#endif

#ifndef ao_boot_ir_cs0

#define ao_boot_ir_cs0()                                                    \
{                                                                           \
        IPC0bits.CS0IP = AO_IR_CS0_PRIO;                                    \
        IPC0bits.CS0IS = AO_IR_CS0_SUBPRIO;                                 \
}

#endif

#ifndef ao_boot_ir_cs1

#define ao_boot_ir_cs1()                                                    \
{                                                                           \
        IPC0bits.CS1IP = AO_IR_CS1_PRIO;                                    \
        IPC0bits.CS1IS = AO_IR_CS1_SUBPRIO;                                 \
}

#endif

#ifndef ao_boot_ir_ct

#define ao_boot_ir_ct()                                                     \
{                                                                           \
        IPC0bits.CTIP = AO_IR_CT_PRIO;                                      \
        IPC0bits.CTIS = AO_IR_CT_SUBPRIO;                                   \
}

#endif

#ifndef ao_boot_ir_dma0

#define ao_boot_ir_dma0()                                                   \
{                                                                           \
        IPC9bits.DMA0IP = AO_IR_DMA0_PRIO;                                  \
        IPC9bits.DMA0IS = AO_IR_DMA0_SUBPRIO;                               \
}

#endif

#ifndef ao_boot_ir_dma1

#define ao_boot_ir_dma1()                                                   \
{                                                                           \
        IPC9bits.DMA1IP = AO_IR_DMA1_PRIO;                                  \
        IPC9bits.DMA1IS = AO_IR_DMA1_SUBPRIO;                               \
}

#endif

#ifndef ao_boot_ir_dma2

#define ao_boot_ir_dma2()                                                   \
{                                                                           \
        IPC9bits.DMA2IP = AO_IR_DMA2_PRIO;                                  \
        IPC9bits.DMA2IS = AO_IR_DMA2_SUBPRIO;                               \
}

#endif

#ifndef ao_boot_ir_dma3

#define ao_boot_ir_dma3()                                                   \
{                                                                           \
        IPC9bits.DMA3IP = AO_IR_DMA3_PRIO;                                  \
        IPC9bits.DMA3IS = AO_IR_DMA3_SUBPRIO;                               \
}

#endif

#ifndef ao_boot_ir_dma4

#define ao_boot_ir_dma4()                                                   \
{                                                                           \
        IPC10bits.DMA4IP = AO_IR_DMA4_PRIO;                                 \
        IPC10bits.DMA4IS = AO_IR_DMA4_SUBPRIO;                              \
}

#endif

#ifndef ao_boot_ir_dma5

#define ao_boot_ir_dma5()                                                   \
{                                                                           \
        IPC10bits.DMA5IP = AO_IR_DMA5_PRIO;                                 \
        IPC10bits.DMA5IS = AO_IR_DMA5_SUBPRIO;                              \
}

#endif

#ifndef ao_boot_ir_dma6

#define ao_boot_ir_dma6()                                                   \
{                                                                           \
        IPC10bits.DMA6IP = AO_IR_DMA6_PRIO;                                 \
        IPC10bits.DMA6IS = AO_IR_DMA6_SUBPRIO;                              \
}

#endif

#ifndef ao_boot_ir_dma7

#define ao_boot_ir_dma7()                                                   \
{                                                                           \
        IPC10bits.DMA7IP = AO_IR_DMA7_PRIO;                                 \
        IPC10bits.DMA7IS = AO_IR_DMA7_SUBPRIO;                              \
}

#endif

#ifndef ao_boot_ir_eth

#define ao_boot_ir_eth()                                                    \
{                                                                           \
        IPC12bits.ETHIP = AO_IR_ETH_PRIO;                                   \
        IPC12bits.ETHIS = AO_IR_ETH_SUBPRIO;                                \
}

#endif

#ifndef ao_boot_ir_fce

#define ao_boot_ir_fce()                                                    \
{                                                                           \
        IPC11bits.FCEIP = AO_IR_FCE_PRIO;                                   \
        IPC11bits.FCEIS = AO_IR_FCE_SUBPRIO;                                \
}

#endif

#ifndef ao_boot_ir_fscm

#define ao_boot_ir_fscm()                                                   \
{                                                                           \
        IPC8bits.FSCMIP = AO_IR_FSCM_PRIO;                                  \
        IPC8bits.FSCMIS = AO_IR_FSCM_SUBPRIO;                               \
}

#endif

#ifndef ao_boot_ir_i2c1

#define ao_boot_ir_i2c1()                                                   \
{                                                                           \
        IPC6bits.I2C1IP = AO_IR_I2C1_PRIO;                                  \
        IPC6bits.I2C1IS = AO_IR_I2C1_SUBPRIO;                               \
}

#endif

#ifndef ao_boot_ir_i2c2

#define ao_boot_ir_i2c2()                                                   \
{                                                                           \
        IPC8bits.I2C2IP = AO_IR_I2C2_PRIO;                                  \
        IPC8bits.I2C2IS = AO_IR_I2C2_SUBPRIO;                               \
}

#endif

#ifndef ao_boot_ir_i2c3

#define ao_boot_ir_i2c3()                                                   \
{                                                                           \
        IPC6bits.I2C3IP = AO_IR_I2C3_PRIO;                                  \
        IPC6bits.I2C3IS = AO_IR_I2C3_SUBPRIO;                               \
}

#endif

#ifndef ao_boot_ir_i2c4

#define ao_boot_ir_i2c4()                                                   \
{                                                                           \
        IPC7bits.I2C4IP = AO_IR_I2C4_PRIO;                                  \
        IPC7bits.I2C4IS = AO_IR_I2C4_SUBPRIO;                               \
}

#endif

#ifndef ao_boot_ir_i2c5

#define ao_boot_ir_i2c5()                                                   \
{                                                                           \
        IPC8bits.I2C5IP = AO_IR_I2C5_PRIO;                                  \
        IPC8bits.I2C5IS = AO_IR_I2C5_SUBPRIO;                               \
}

#endif

#ifndef ao_boot_ir_ic1

#define ao_boot_ir_ic1()                                                    \
{                                                                           \
        IPC1bits.IC1IP = AO_IR_IC1_PRIO;                                    \
        IPC1bits.IC1IS = AO_IR_IC1_SUBPRIO;                                 \
}

#endif

#ifndef ao_boot_ir_ic2

#define ao_boot_ir_ic2()                                                    \
{                                                                           \
        IPC2bits.IC2IP = AO_IR_IC2_PRIO;                                    \
        IPC2bits.IC2IS = AO_IR_IC2_SUBPRIO;                                 \
}

#endif

#ifndef ao_boot_ir_ic3

#define ao_boot_ir_ic3()                                                    \
{                                                                           \
        IPC3bits.IC3IP = AO_IR_IC3_PRIO;                                    \
        IPC3bits.IC3IS = AO_IR_IC3_SUBPRIO;                                 \
}

#endif

#ifndef ao_boot_ir_ic4

#define ao_boot_ir_ic4()                                                    \
{                                                                           \
        IPC4bits.IC4IP = AO_IR_IC4_PRIO;                                    \
        IPC4bits.IC4IS = AO_IR_IC4_SUBPRIO;                                 \
}

#endif

#ifndef ao_boot_ir_ic5

#define ao_boot_ir_ic5()                                                    \
{                                                                           \
        IPC5bits.IC5IP = AO_IR_IC5_PRIO;                                    \
        IPC5bits.IC5IS = AO_IR_IC5_SUBPRIO;                                 \
}

#endif

#ifndef ao_boot_ir_int0

#define ao_boot_ir_int0()                                                   \
{                                                                           \
        IPC0bits.INT0IP = AO_IR_INT0_PRIO;                                  \
        IPC0bits.INT0IS = AO_IR_INT0_SUBPRIO;                               \
}

#endif

#ifndef ao_boot_ir_int1

#define ao_boot_ir_int1()                                                   \
{                                                                           \
        IPC1bits.INT1IP = AO_IR_INT1_PRIO;                                  \
        IPC1bits.INT1IS = AO_IR_INT1_SUBPRIO;                               \
}

#endif

#ifndef ao_boot_ir_int2

#define ao_boot_ir_int2()                                                   \
{                                                                           \
        IPC2bits.INT2IP = AO_IR_INT2_PRIO;                                  \
        IPC2bits.INT2IS = AO_IR_INT2_SUBPRIO;                               \
}

#endif

#ifndef ao_boot_ir_int3

#define ao_boot_ir_int3()                                                   \
{                                                                           \
        IPC3bits.INT3IP = AO_IR_INT3_PRIO;                                  \
        IPC3bits.INT3IS = AO_IR_INT3_SUBPRIO;                               \
}

#endif

#ifndef ao_boot_ir_int4

#define ao_boot_ir_int4()                                                   \
{                                                                           \
        IPC4bits.INT4IP = AO_IR_INT4_PRIO;                                  \
        IPC4bits.INT4IS = AO_IR_INT4_SUBPRIO;                               \
}

#endif

#ifndef ao_boot_ir_oc1

#define ao_boot_ir_oc1()                                                    \
{                                                                           \
        IPC1bits.OC1IP = AO_IR_OC1_PRIO;                                    \
        IPC1bits.OC1IS = AO_IR_OC1_SUBPRIO;                                 \
}

#endif

#ifndef ao_boot_ir_oc2

#define ao_boot_ir_oc2()                                                    \
{                                                                           \
        IPC2bits.OC2IP = AO_IR_OC2_PRIO;                                    \
        IPC2bits.OC2IS = AO_IR_OC2_SUBPRIO;                                 \
}

#endif

#ifndef ao_boot_ir_oc3

#define ao_boot_ir_oc3()                                                    \
{                                                                           \
        IPC3bits.OC3IP = AO_IR_OC3_PRIO;                                    \
        IPC3bits.OC3IS = AO_IR_OC3_SUBPRIO;                                 \
}

#endif

#ifndef ao_boot_ir_oc4

#define ao_boot_ir_oc4()                                                    \
{                                                                           \
        IPC4bits.OC4IP = AO_IR_OC4_PRIO;                                    \
        IPC4bits.OC4IS = AO_IR_OC4_SUBPRIO;                                 \
}

#endif

#ifndef ao_boot_ir_oc5

#define ao_boot_ir_oc5()                                                    \
{                                                                           \
        IPC5bits.OC5IP = AO_IR_OC5_PRIO;                                    \
        IPC5bits.OC5IS = AO_IR_OC5_SUBPRIO;                                 \
}

#endif

#ifndef ao_boot_ir_pmp

#define ao_boot_ir_pmp()                                                    \
{                                                                           \
        IPC7bits.PMPIP = AO_IR_PMP_PRIO;                                    \
        IPC7bits.PMPIS = AO_IR_PMP_SUBPRIO;                                 \
}

#endif

#ifndef ao_boot_ir_rtcc

#define ao_boot_ir_rtcc()                                                   \
{                                                                           \
        IPC8bits.RTCCIP = AO_IR_RTCC_PRIO;                                  \
        IPC8bits.RTCCIS = AO_IR_RTCC_SUBPRIO;                               \
}

#endif

#ifndef ao_boot_ir_spi1

#define ao_boot_ir_spi1()                                                   \
{                                                                           \
        IPC5bits.SPI1IP = AO_IR_SPI1_PRIO;                                  \
        IPC5bits.SPI1IS = AO_IR_SPI1_SUBPRIO;                               \
}

#endif

#ifndef ao_boot_ir_spi2

#define ao_boot_ir_spi2()                                                   \
{                                                                           \
        IPC7bits.SPI2IP = AO_IR_SPI2_PRIO;                                  \
        IPC7bits.SPI2IS = AO_IR_SPI2_SUBPRIO;                               \
}

#endif

#ifndef ao_boot_ir_spi3

#define ao_boot_ir_spi3()                                                   \
{                                                                           \
        IPC6bits.SPI3IP = AO_IR_SPI3_PRIO;                                  \
        IPC6bits.SPI3IS = AO_IR_SPI3_SUBPRIO;                               \
}

#endif

#ifndef ao_boot_ir_spi4

#define ao_boot_ir_spi4()                                                   \
{                                                                           \
        IPC8bits.SPI4IP = AO_IR_SPI4_PRIO;                                  \
        IPC8bits.SPI4IS = AO_IR_SPI4_SUBPRIO;                               \
}

#endif

#ifndef ao_boot_ir_t1

#define ao_boot_ir_t1()                                                     \
{                                                                           \
        IPC1bits.T1IP = AO_IR_T1_PRIO;                                      \
        IPC1bits.T1IS = AO_IR_T1_SUBPRIO;                                   \
}

#endif

#ifndef ao_boot_ir_t2

#define ao_boot_ir_t2()                                                     \
{                                                                           \
        IPC2bits.T2IP = AO_IR_T2_PRIO;                                      \
        IPC2bits.T2IS = AO_IR_T2_SUBPRIO;                                   \
}

#endif

#ifndef ao_boot_ir_t3

#define ao_boot_ir_t3()                                                     \
{                                                                           \
        IPC3bits.T3IP = AO_IR_T3_PRIO;                                      \
        IPC3bits.T3IS = AO_IR_T3_SUBPRIO;                                   \
}

#endif

#ifndef ao_boot_ir_t4

#define ao_boot_ir_t4()                                                     \
{                                                                           \
        IPC4bits.T4IP = AO_IR_T4_PRIO;                                      \
        IPC4bits.T4IS = AO_IR_T4_SUBPRIO;                                   \
}

#endif

#ifndef ao_boot_ir_t5

#define ao_boot_ir_t5()                                                     \
{                                                                           \
        IPC5bits.T5IP = AO_IR_T5_PRIO;                                      \
        IPC5bits.T5IS = AO_IR_T5_SUBPRIO;                                   \
}

#endif

#ifndef ao_boot_ir_u1

#define ao_boot_ir_u1()                                                     \
{                                                                           \
        IPC6bits.U1IP = AO_IR_U1_PRIO;                                      \
        IPC6bits.U1IS = AO_IR_U1_SUBPRIO;                                   \
}

#endif

#ifndef ao_boot_ir_u2

#define ao_boot_ir_u2()                                                     \
{                                                                           \
        IPC8bits.U2IP = AO_IR_U2_PRIO;                                      \
        IPC8bits.U2IS = AO_IR_U2_SUBPRIO;                                   \
}

#endif

#ifndef ao_boot_ir_u3

#define ao_boot_ir_u3()                                                     \
{                                                                           \
        IPC7bits.U3IP = AO_IR_U3_PRIO;                                      \
        IPC7bits.U3IS = AO_IR_U3_SUBPRIO;                                   \
}

#endif

#ifndef ao_boot_ir_u4

#define ao_boot_ir_u4()                                                     \
{                                                                           \
        IPC12bits.U4IP = AO_IR_U4_PRIO;                                     \
        IPC12bits.U4IS = AO_IR_U4_SUBPRIO;                                  \
}

#endif

#ifndef ao_boot_ir_u5

#define ao_boot_ir_u5()                                                     \
{                                                                           \
        IPC12bits.U5IP = AO_IR_U5_PRIO;                                     \
        IPC12bits.U5IS = AO_IR_U5_SUBPRIO;                                  \
}

#endif

#ifndef ao_boot_ir_u6

#define ao_boot_ir_u6()                                                     \
{                                                                           \
        IPC12bits.U6IP = AO_IR_U6_PRIO;                                     \
        IPC12bits.U6IS = AO_IR_U6_SUBPRIO;                                  \
}

#endif

#ifndef ao_boot_ir_usb

#define ao_boot_ir_usb()                                                    \
{                                                                           \
        IPC11bits.USBIP = AO_IR_USB_PRIO;                                   \
        IPC11bits.USBIS = AO_IR_USB_SUBPRIO;                                \
}

#endif

void    ao_boot_sys_pcache();

#include_next <ao_boot.h>

```

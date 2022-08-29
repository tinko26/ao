---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The /src/ao_sys_xc32_pic32mx_1xx/ao_boot.h file of the ao real-time operating system."
draft: true
permalink: /src/ao_sys_xc32_pic32mx_1xx/ao_boot.h/ 
subtitle: ""
title: "ao_boot.h"
toc: true
---

# Overview

...

# Includes

```c
#include <ao_ir.h>
#include <xc.h>

#ifndef ao_boot_ir_adc

#define ao_boot_ir_adc()                                                    \
{                                                                           \
        IPC5bits.AD1IP = AO_IR_ADC_PRIO;                                    \
        IPC5bits.AD1IS = AO_IR_ADC_SUBPRIO;                                 \
}

#endif

#ifndef ao_boot_ir_cmp1

#define ao_boot_ir_cmp1()                                                   \
{                                                                           \
        IPC6bits.CMP1IP = AO_IR_CMP1_PRIO;                                  \
        IPC6bits.CMP1IS = AO_IR_CMP1_SUBPRIO;                               \
}

#endif

#ifndef ao_boot_ir_cmp2

#define ao_boot_ir_cmp2()                                                   \
{                                                                           \
        IPC7bits.CMP2IP = AO_IR_CMP2_PRIO;                                  \
        IPC7bits.CMP2IS = AO_IR_CMP2_SUBPRIO;                               \
}

#endif

#ifndef ao_boot_ir_cmp3

#define ao_boot_ir_cmp3()                                                   \
{                                                                           \
        IPC7bits.CMP2IP = AO_IR_CMP3_PRIO;                                  \
        IPC7bits.CMP2IS = AO_IR_CMP3_SUBPRIO;                               \
}

#endif

#ifndef ao_boot_ir_cn

#define ao_boot_ir_cn()                                                     \
{                                                                           \
        IPC8bits.CNIP = AO_IR_CN_PRIO;                                      \
        IPC8bits.CNIS = AO_IR_CN_SUBPRIO;                                   \
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

#ifndef ao_boot_ir_ctmu

#define ao_boot_ir_ctmu()                                                   \
{                                                                           \
        IPC9bits.CTIP = AO_IR_CTMU_PRIO;                                    \
        IPC9bits.CTIS = AO_IR_CTMU_SUBPRIO;                                 \
}

#endif

#ifndef ao_boot_ir_dma0

#define ao_boot_ir_dma0()                                                   \
{                                                                           \
        IPC10bits.DMA0IP = AO_IR_DMA0_PRIO;                                 \
        IPC10bits.DMA0IS = AO_IR_DMA0_SUBPRIO;                              \
}

#endif

#ifndef ao_boot_ir_dma1

#define ao_boot_ir_dma1()                                                   \
{                                                                           \
        IPC10bits.DMA1IP = AO_IR_DMA1_PRIO;                                 \
        IPC10bits.DMA1IS = AO_IR_DMA1_SUBPRIO;                              \
}

#endif

#ifndef ao_boot_ir_dma2

#define ao_boot_ir_dma2()                                                   \
{                                                                           \
        IPC10bits.DMA2IP = AO_IR_DMA2_PRIO;                                 \
        IPC10bits.DMA2IS = AO_IR_DMA2_SUBPRIO;                              \
}

#endif

#ifndef ao_boot_ir_dma3

#define ao_boot_ir_dma3()                                                   \
{                                                                           \
        IPC10bits.DMA3IP = AO_IR_DMA3_PRIO;                                 \
        IPC10bits.DMA3IS = AO_IR_DMA3_SUBPRIO;                              \
}

#endif

#ifndef ao_boot_ir_fce

#define ao_boot_ir_fce()                                                    \
{                                                                           \
        IPC6bits.FCEIP = AO_IR_FCE_PRIO;                                    \
        IPC6bits.FCEIS = AO_IR_FCE_SUBPRIO;                                 \
}

#endif

#ifndef ao_boot_ir_fscm

#define ao_boot_ir_fscm()                                                   \
{                                                                           \
        IPC6bits.FSCMIP = AO_IR_FSCM_PRIO;                                  \
        IPC6bits.FSCMIS = AO_IR_FSCM_SUBPRIO;                               \
}

#endif

#ifndef ao_boot_ir_i2c1

#define ao_boot_ir_i2c1()                                                   \
{                                                                           \
        IPC8bits.I2C1IP = AO_IR_I2C1_PRIO;                                  \
        IPC8bits.I2C1IS = AO_IR_I2C1_SUBPRIO;                               \
}

#endif

#ifndef ao_boot_ir_i2c2

#define ao_boot_ir_i2c2()                                                   \
{                                                                           \
        IPC9bits.I2C2IP = AO_IR_I2C2_PRIO;                                  \
        IPC9bits.I2C2IS = AO_IR_I2C2_SUBPRIO;                               \
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
        IPC8bits.PMPIP = AO_IR_PMP_PRIO;                                    \
        IPC8bits.PMPIS = AO_IR_PMP_SUBPRIO;                                 \
}

#endif

#ifndef ao_boot_ir_rtcc

#define ao_boot_ir_rtcc()                                                   \
{                                                                           \
        IPC6bits.RTCCIP = AO_IR_RTCC_PRIO;                                  \
        IPC6bits.RTCCIS = AO_IR_RTCC_SUBPRIO;                               \
}

#endif

#ifndef ao_boot_ir_spi1

#define ao_boot_ir_spi1()                                                   \
{                                                                           \
        IPC7bits.SPI1IP = AO_IR_SPI1_PRIO;                                  \
        IPC7bits.SPI1IS = AO_IR_SPI1_SUBPRIO;                               \
}

#endif

#ifndef ao_boot_ir_spi2

#define ao_boot_ir_spi2()                                                   \
{                                                                           \
        IPC9bits.SPI2IP = AO_IR_SPI2_PRIO;                                  \
        IPC9bits.SPI2IS = AO_IR_SPI2_SUBPRIO;                               \
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
        IPC8bits.U1IP = AO_IR_U1_PRIO;                                      \
        IPC8bits.U1IS = AO_IR_U1_SUBPRIO;                                   \
}

#endif

#ifndef ao_boot_ir_u2

#define ao_boot_ir_u2()                                                     \
{                                                                           \
        IPC9bits.U2IP = AO_IR_U2_PRIO;                                      \
        IPC9bits.U2IS = AO_IR_U2_SUBPRIO;                                   \
}

#endif

#ifndef ao_boot_ir_usb

#define ao_boot_ir_usb()                                                    \
{                                                                           \
        IPC7bits.USBIP = AO_IR_USB_PRIO;                                    \
        IPC7bits.USBIS = AO_IR_USB_SUBPRIO;                                 \
}

#endif

void    ao_boot_sys_pcache();

#include_next <ao_boot.h>

```

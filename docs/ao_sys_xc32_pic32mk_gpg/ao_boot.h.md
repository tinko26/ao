---
author: "Stefan Wagner"
breadcrumbs: 2
date: 2022-08-29
description: "The ao_sys_xc32_pic32mk_gpg/ao_boot.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys_xc32_pic32mk_gpg/ao_boot.h/ 
subtitle: "<code>ao_sys_xc32_pic32mk_gpg</code>"
title: "<code>ao_boot.h</code>"
toc: true
---

```c
#ifndef ao_boot_ir_ad1

#define ao_boot_ir_ad1()                                                    \
{                                                                           \
        IPC23bits.AD1IP = AO_IR_AD1_PRIO;                                   \
        IPC23bits.AD1IS = AO_IR_AD1_SUBPRIO;                                \
}

#endif

#ifndef ao_boot_ir_ad1ar

#define ao_boot_ir_ad1ar()                                                  \
{                                                                           \
        IPC25bits.AD1ARIP = AO_IR_AD1AR_PRIO;                               \
        IPC25bits.AD1ARIS = AO_IR_AD1AR_SUBPRIO;                            \
}

#endif

#ifndef ao_boot_ir_ad1d0

#define ao_boot_ir_ad1d0()                                                  \
{                                                                           \
        IPC26bits.AD1D0IP = AO_IR_AD1D0_PRIO;                               \
        IPC26bits.AD1D0IS = AO_IR_AD1D0_SUBPRIO;                            \
}

#endif

#ifndef ao_boot_ir_ad1d1

#define ao_boot_ir_ad1d1()                                                  \
{                                                                           \
        IPC26bits.AD1D1IP = AO_IR_AD1D1_PRIO;                               \
        IPC26bits.AD1D1IS = AO_IR_AD1D1_SUBPRIO;                            \
}

#endif

#ifndef ao_boot_ir_ad1d2

#define ao_boot_ir_ad1d2()                                                  \
{                                                                           \
        IPC27bits.AD1D2IP = AO_IR_AD1D2_PRIO;                               \
        IPC27bits.AD1D2IS = AO_IR_AD1D2_SUBPRIO;                            \
}

#endif

#ifndef ao_boot_ir_ad1d3

#define ao_boot_ir_ad1d3()                                                  \
{                                                                           \
        IPC27bits.AD1D3IP = AO_IR_AD1D3_PRIO;                               \
        IPC27bits.AD1D3IS = AO_IR_AD1D3_SUBPRIO;                            \
}

#endif

#ifndef ao_boot_ir_ad1d4

#define ao_boot_ir_ad1d4()                                                  \
{                                                                           \
        IPC27bits.AD1D4IP = AO_IR_AD1D4_PRIO;                               \
        IPC27bits.AD1D4IS = AO_IR_AD1D4_SUBPRIO;                            \
}

#endif

#ifndef ao_boot_ir_ad1d5

#define ao_boot_ir_ad1d5()                                                  \
{                                                                           \
        IPC27bits.AD1D5IP = AO_IR_AD1D5_PRIO;                               \
        IPC27bits.AD1D5IS = AO_IR_AD1D5_SUBPRIO;                            \
}

#endif

#ifndef ao_boot_ir_ad1d6

#define ao_boot_ir_ad1d6()                                                  \
{                                                                           \
        IPC28bits.AD1D6IP = AO_IR_AD1D6_PRIO;                               \
        IPC28bits.AD1D6IS = AO_IR_AD1D6_SUBPRIO;                            \
}

#endif

#ifndef ao_boot_ir_ad1d7

#define ao_boot_ir_ad1d7()                                                  \
{                                                                           \
        IPC28bits.AD1D7IP = AO_IR_AD1D7_PRIO;                               \
        IPC28bits.AD1D7IS = AO_IR_AD1D7_SUBPRIO;                            \
}

#endif

#ifndef ao_boot_ir_ad1d8

#define ao_boot_ir_ad1d8()                                                  \
{                                                                           \
        IPC28bits.AD1D8IP = AO_IR_AD1D8_PRIO;                               \
        IPC28bits.AD1D8IS = AO_IR_AD1D8_SUBPRIO;                            \
}

#endif

#ifndef ao_boot_ir_ad1d9

#define ao_boot_ir_ad1d9()                                                  \
{                                                                           \
        IPC28bits.AD1D9IP = AO_IR_AD1D9_PRIO;                               \
        IPC28bits.AD1D9IS = AO_IR_AD1D9_SUBPRIO;                            \
}

#endif

#ifndef ao_boot_ir_ad1d10

#define ao_boot_ir_ad1d10()                                                 \
{                                                                           \
        IPC29bits.AD1D10IP = AO_IR_AD1D10_PRIO;                             \
        IPC29bits.AD1D10IS = AO_IR_AD1D10_SUBPRIO;                          \
}

#endif

#ifndef ao_boot_ir_ad1d11

#define ao_boot_ir_ad1d11()                                                 \
{                                                                           \
        IPC29bits.AD1D11IP = AO_IR_AD1D11_PRIO;                             \
        IPC29bits.AD1D11IS = AO_IR_AD1D11_SUBPRIO;                          \
}

#endif

#ifndef ao_boot_ir_ad1d12

#define ao_boot_ir_ad1d12()                                                 \
{                                                                           \
        IPC29bits.AD1D12IP = AO_IR_AD1D12_PRIO;                             \
        IPC29bits.AD1D12IS = AO_IR_AD1D12_SUBPRIO;                          \
}

#endif

#ifndef ao_boot_ir_ad1d13

#define ao_boot_ir_ad1d13()                                                 \
{                                                                           \
        IPC29bits.AD1D13IP = AO_IR_AD1D13_PRIO;                             \
        IPC29bits.AD1D13IS = AO_IR_AD1D13_SUBPRIO;                          \
}

#endif

#ifndef ao_boot_ir_ad1d14

#define ao_boot_ir_ad1d14()                                                 \
{                                                                           \
        IPC30bits.AD1D14IP = AO_IR_AD1D14_PRIO;                             \
        IPC30bits.AD1D14IS = AO_IR_AD1D14_SUBPRIO;                          \
}

#endif

#ifndef ao_boot_ir_ad1d15

#define ao_boot_ir_ad1d15()                                                 \
{                                                                           \
        IPC30bits.AD1D15IP = AO_IR_AD1D15_PRIO;                             \
        IPC30bits.AD1D15IS = AO_IR_AD1D15_SUBPRIO;                          \
}

#endif

#ifndef ao_boot_ir_ad1d16

#define ao_boot_ir_ad1d16()                                                 \
{                                                                           \
        IPC30bits.AD1D16IP = AO_IR_AD1D16_PRIO;                             \
        IPC30bits.AD1D16IS = AO_IR_AD1D16_SUBPRIO;                          \
}

#endif

#ifndef ao_boot_ir_ad1d17

#define ao_boot_ir_ad1d17()                                                 \
{                                                                           \
        IPC30bits.AD1D17IP = AO_IR_AD1D17_PRIO;                             \
        IPC30bits.AD1D17IS = AO_IR_AD1D17_SUBPRIO;                          \
}

#endif

#ifndef ao_boot_ir_ad1d18

#define ao_boot_ir_ad1d18()                                                 \
{                                                                           \
        IPC31bits.AD1D18IP = AO_IR_AD1D18_PRIO;                             \
        IPC31bits.AD1D18IS = AO_IR_AD1D18_SUBPRIO;                          \
}

#endif

#ifndef ao_boot_ir_ad1d19

#define ao_boot_ir_ad1d19()                                                 \
{                                                                           \
        IPC31bits.AD1D19IP = AO_IR_AD1D19_PRIO;                             \
        IPC31bits.AD1D19IS = AO_IR_AD1D19_SUBPRIO;                          \
}

#endif

#ifndef ao_boot_ir_ad1d24

#define ao_boot_ir_ad1d24()                                                 \
{                                                                           \
        IPC32bits.AD1D24IP = AO_IR_AD1D24_PRIO;                             \
        IPC32bits.AD1D24IS = AO_IR_AD1D24_SUBPRIO;                          \
}

#endif

#ifndef ao_boot_ir_ad1d25

#define ao_boot_ir_ad1d25()                                                 \
{                                                                           \
        IPC32bits.AD1D25IP = AO_IR_AD1D25_PRIO;                             \
        IPC32bits.AD1D25IS = AO_IR_AD1D25_SUBPRIO;                          \
}

#endif

#ifndef ao_boot_ir_ad1d26

#define ao_boot_ir_ad1d26()                                                 \
{                                                                           \
        IPC33bits.AD1D26IP = AO_IR_AD1D26_PRIO;                             \
        IPC33bits.AD1D26IS = AO_IR_AD1D26_SUBPRIO;                          \
}

#endif

#ifndef ao_boot_ir_ad1d27

#define ao_boot_ir_ad1d27()                                                 \
{                                                                           \
        IPC33bits.AD1D27IP = AO_IR_AD1D27_PRIO;                             \
        IPC33bits.AD1D27IS = AO_IR_AD1D27_SUBPRIO;                          \
}

#endif

#ifndef ao_boot_ir_ad1d40

#define ao_boot_ir_ad1d40()                                                 \
{                                                                           \
        IPC36bits.AD1D40IP = AO_IR_AD1D40_PRIO;                             \
        IPC36bits.AD1D40IS = AO_IR_AD1D40_SUBPRIO;                          \
}

#endif

#ifndef ao_boot_ir_ad1d41

#define ao_boot_ir_ad1d41()                                                 \
{                                                                           \
        IPC36bits.AD1D41IP = AO_IR_AD1D41_PRIO;                             \
        IPC36bits.AD1D41IS = AO_IR_AD1D41_SUBPRIO;                          \
}

#endif

#ifndef ao_boot_ir_ad1d46

#define ao_boot_ir_ad1d46()                                                 \
{                                                                           \
        IPC38bits.AD1D46IP = AO_IR_AD1D46_PRIO;                             \
        IPC38bits.AD1D46IS = AO_IR_AD1D46_SUBPRIO;                          \
}

#endif

#ifndef ao_boot_ir_ad1d47

#define ao_boot_ir_ad1d47()                                                 \
{                                                                           \
        IPC38bits.AD1D47IP = AO_IR_AD1D47_PRIO;                             \
        IPC38bits.AD1D47IS = AO_IR_AD1D47_SUBPRIO;                          \
}

#endif

#ifndef ao_boot_ir_ad1d48

#define ao_boot_ir_ad1d48()                                                 \
{                                                                           \
        IPC38bits.AD1D48IP = AO_IR_AD1D48_PRIO;                             \
        IPC38bits.AD1D48IS = AO_IR_AD1D48_SUBPRIO;                          \
}

#endif

#ifndef ao_boot_ir_ad1d49

#define ao_boot_ir_ad1d49()                                                 \
{                                                                           \
        IPC38bits.AD1D49IP = AO_IR_AD1D49_PRIO;                             \
        IPC38bits.AD1D49IS = AO_IR_AD1D49_SUBPRIO;                          \
}

#endif

#ifndef ao_boot_ir_ad1d50

#define ao_boot_ir_ad1d50()                                                 \
{                                                                           \
        IPC39bits.AD1D50IP = AO_IR_AD1D50_PRIO;                             \
        IPC39bits.AD1D50IS = AO_IR_AD1D50_SUBPRIO;                          \
}

#endif

#ifndef ao_boot_ir_ad1d53

#define ao_boot_ir_ad1d53()                                                 \
{                                                                           \
        IPC39bits.AD1D53IP = AO_IR_AD1D53_PRIO;                             \
        IPC39bits.AD1D53IS = AO_IR_AD1D53_SUBPRIO;                          \
}

#endif

#ifndef ao_boot_ir_ad1dc1

#define ao_boot_ir_ad1dc1()                                                 \
{                                                                           \
        IPC23bits.AD1DC1IP = AO_IR_AD1DC1_PRIO;                             \
        IPC23bits.AD1DC1IS = AO_IR_AD1DC1_SUBPRIO;                          \
}

#endif

#ifndef ao_boot_ir_ad1dc2

#define ao_boot_ir_ad1dc2()                                                 \
{                                                                           \
        IPC23bits.AD1DC2IP = AO_IR_AD1DC2_PRIO;                             \
        IPC23bits.AD1DC2IS = AO_IR_AD1DC2_SUBPRIO;                          \
}

#endif

#ifndef ao_boot_ir_ad1dc3

#define ao_boot_ir_ad1dc3()                                                 \
{                                                                           \
        IPC61bits.AD1DC3IP = AO_IR_AD1DC3_PRIO;                             \
        IPC61bits.AD1DC3IS = AO_IR_AD1DC3_SUBPRIO;                          \
}

#endif

#ifndef ao_boot_ir_ad1dc4

#define ao_boot_ir_ad1dc4()                                                 \
{                                                                           \
        IPC61bits.AD1DC4IP = AO_IR_AD1DC4_PRIO;                             \
        IPC61bits.AD1DC4IS = AO_IR_AD1DC4_SUBPRIO;                          \
}

#endif

#ifndef ao_boot_ir_ad1df1

#define ao_boot_ir_ad1df1()                                                 \
{                                                                           \
        IPC24bits.AD1DF1IP = AO_IR_AD1DF1_PRIO;                             \
        IPC24bits.AD1DF1IS = AO_IR_AD1DF1_SUBPRIO;                          \
}

#endif

#ifndef ao_boot_ir_ad1df2

#define ao_boot_ir_ad1df2()                                                 \
{                                                                           \
        IPC24bits.AD1DF2IP = AO_IR_AD1DF2_PRIO;                             \
        IPC24bits.AD1DF2IS = AO_IR_AD1DF2_SUBPRIO;                          \
}

#endif

#ifndef ao_boot_ir_ad1df3

#define ao_boot_ir_ad1df3()                                                 \
{                                                                           \
        IPC24bits.AD1DF3IP = AO_IR_AD1DF3_PRIO;                             \
        IPC24bits.AD1DF3IS = AO_IR_AD1DF3_SUBPRIO;                          \
}

#endif

#ifndef ao_boot_ir_ad1df4

#define ao_boot_ir_ad1df4()                                                 \
{                                                                           \
        IPC24bits.AD1DF4IP = AO_IR_AD1DF4_PRIO;                             \
        IPC24bits.AD1DF4IS = AO_IR_AD1DF4_SUBPRIO;                          \
}

#endif

#ifndef ao_boot_ir_ad1eos

#define ao_boot_ir_ad1eos()                                                 \
{                                                                           \
        IPC25bits.AD1EOSIP = AO_IR_AD1EOS_PRIO;                             \
        IPC25bits.AD1EOSIS = AO_IR_AD1EOS_SUBPRIO;                          \
}

#endif

#ifndef ao_boot_ir_ad1fcbt

#define ao_boot_ir_ad1fcbt()                                                \
{                                                                           \
        IPC26bits.AD1FCBTIP = AO_IR_AD1FCBT_PRIO;                           \
        IPC26bits.AD1FCBTIS = AO_IR_AD1FCBT_SUBPRIO;                        \
}

#endif

#ifndef ao_boot_ir_ad1fi

#define ao_boot_ir_ad1fi()                                                  \
{                                                                           \
        IPC25bits.AD1F1IP = AO_IR_AD1FI_PRIO;                               \
        IPC25bits.AD1F1IS = AO_IR_AD1FI_SUBPRIO;                            \
}

#endif

#ifndef ao_boot_ir_ad1g

#define ao_boot_ir_ad1g()                                                   \
{                                                                           \
        IPC26bits.AD1G1IP = AO_IR_AD1G_PRIO;                                \
        IPC26bits.AD1G1IS = AO_IR_AD1G_SUBPRIO;                             \
}

#endif

#ifndef ao_boot_ir_ad1rs

#define ao_boot_ir_ad1rs()                                                  \
{                                                                           \
        IPC25bits.AD1RSIP = AO_IR_AD1RS_PRIO;                               \
        IPC25bits.AD1RSIS = AO_IR_AD1RS_SUBPRIO;                            \
}

#endif

#ifndef ao_boot_ir_can1

#define ao_boot_ir_can1()                                                   \
{                                                                           \
        IPC41bits.CAN1IP = AO_IR_CAN1_PRIO;                                 \
        IPC41bits.CAN1IS = AO_IR_CAN1_SUBPRIO;                              \
}

#endif

#ifndef ao_boot_ir_cfdc

#define ao_boot_ir_cfdc()                                                   \
{                                                                           \
        IPC63bits.CFDCIP = AO_IR_CFDC_PRIO;                                 \
        IPC63bits.CFDCIS = AO_IR_CFDC_SUBPRIO;                              \
}

#endif

#ifndef ao_boot_ir_clc1

#define ao_boot_ir_clc1()                                                   \
{                                                                           \
        IPC62bits.CLC1IP = AO_IR_CLC1_PRIO;                                 \
        IPC62bits.CLC1IS = AO_IR_CLC1_SUBPRIO;                              \
}

#endif

#ifndef ao_boot_ir_clc2

#define ao_boot_ir_clc2()                                                   \
{                                                                           \
        IPC62bits.CLC2IP = AO_IR_CLC2_PRIO;                                 \
        IPC62bits.CLC2IS = AO_IR_CLC2_SUBPRIO;                              \
}

#endif

#ifndef ao_boot_ir_clc3

#define ao_boot_ir_clc3()                                                   \
{                                                                           \
        IPC62bits.CLC3IP = AO_IR_CLC3_PRIO;                                 \
        IPC62bits.CLC3IS = AO_IR_CLC3_SUBPRIO;                              \
}

#endif

#ifndef ao_boot_ir_clc4

#define ao_boot_ir_clc4()                                                   \
{                                                                           \
        IPC63bits.CLC4IP = AO_IR_CLC4_PRIO;                                 \
        IPC62bits.CLC4IS = AO_IR_CLC4_SUBPRIO;                              \
}

#endif

#ifndef ao_boot_ir_cmp1

#define ao_boot_ir_cmp1()                                                   \
{                                                                           \
        IPC8bits.CMP1IP = AO_IR_CMP1_PRIO;                                  \
        IPC8bits.CMP1IS = AO_IR_CMP1_SUBPRIO;                               \
}

#endif

#ifndef ao_boot_ir_cmp2

#define ao_boot_ir_cmp2()                                                   \
{                                                                           \
        IPC8bits.CMP2IP = AO_IR_CMP2_PRIO;                                  \
        IPC8bits.CMP2IS = AO_IR_CMP2_SUBPRIO;                               \
}

#endif

#ifndef ao_boot_ir_cmp3

#define ao_boot_ir_cmp3()                                                   \
{                                                                           \
        IPC40bits.CMP3IP = AO_IR_CMP3_PRIO;                                 \
        IPC40bits.CMP3IS = AO_IR_CMP3_SUBPRIO;                              \
}

#endif

#ifndef ao_boot_ir_cmp4

#define ao_boot_ir_cmp4()                                                   \
{                                                                           \
        IPC40bits.CMP4IP = AO_IR_CMP4_PRIO;                                 \
        IPC40bits.CMP4IS = AO_IR_CMP4_SUBPRIO;                              \
}

#endif

#ifndef ao_boot_ir_cmp5

#define ao_boot_ir_cmp5()                                                   \
{                                                                           \
        IPC40bits.CMP5IP = AO_IR_CMP5_PRIO;                                 \
        IPC40bits.CMP5IS = AO_IR_CMP5_SUBPRIO;                              \
}

#endif

#ifndef ao_boot_ir_cna

#define ao_boot_ir_cna()                                                    \
{                                                                           \
        IPC11bits.CNAIP = AO_IR_CNA_PRIO;                                   \
        IPC11bits.CNAIS = AO_IR_CNA_SUBPRIO;                                \
}

#endif

#ifndef ao_boot_ir_cnb

#define ao_boot_ir_cnb()                                                    \
{                                                                           \
        IPC11bits.CNBIP = AO_IR_CNB_PRIO;                                   \
        IPC11bits.CNBIS = AO_IR_CNB_SUBPRIO;                                \
}

#endif

#ifndef ao_boot_ir_cnc

#define ao_boot_ir_cnc()                                                    \
{                                                                           \
        IPC11bits.CNCIP = AO_IR_CNC_PRIO;                                   \
        IPC11bits.CNCIS = AO_IR_CNC_SUBPRIO;                                \
}

#endif

#ifndef ao_boot_ir_cnd

#define ao_boot_ir_cnd()                                                    \
{                                                                           \
        IPC11bits.CNDIP = AO_IR_CND_PRIO;                                   \
        IPC11bits.CNDIS = AO_IR_CND_SUBPRIO;                                \
}

#endif

#ifndef ao_boot_ir_cne

#define ao_boot_ir_cne()                                                    \
{                                                                           \
        IPC12bits.CNEIP = AO_IR_CNE_PRIO;                                   \
        IPC12bits.CNEIS = AO_IR_CNE_SUBPRIO;                                \
}

#endif

#ifndef ao_boot_ir_cnf

#define ao_boot_ir_cnf()                                                    \
{                                                                           \
        IPC12bits.CNFIP = AO_IR_CNF_PRIO;                                   \
        IPC12bits.CNFIS = AO_IR_CNF_SUBPRIO;                                \
}

#endif

#ifndef ao_boot_ir_cng

#define ao_boot_ir_cng()                                                    \
{                                                                           \
        IPC12bits.CNGIP = AO_IR_CNG_PRIO;                                   \
        IPC12bits.CNGIS = AO_IR_CNG_SUBPRIO;                                \
}

#endif

#ifndef ao_boot_ir_cpc

#define ao_boot_ir_cpc()                                                    \
{                                                                           \
        IPC63bits.CPCIP = AO_IR_CPC_PRIO;                                   \
        IPC63bits.CPCIS = AO_IR_CPC_SUBPRIO;                                \
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
        IPC17bits.CTMUIP = AO_IR_CTMU_PRIO;                                 \
        IPC17bits.CTMUIS = AO_IR_CTMU_SUBPRIO;                              \
}

#endif

#ifndef ao_boot_ir_dma0

#define ao_boot_ir_dma0()                                                   \
{                                                                           \
        IPC18bits.DMA0IP = AO_IR_DMA0_PRIO;                                 \
        IPC18bits.DMA0IS = AO_IR_DMA0_SUBPRIO;                              \
}

#endif

#ifndef ao_boot_ir_dma1

#define ao_boot_ir_dma1()                                                   \
{                                                                           \
        IPC18bits.DMA1IP = AO_IR_DMA1_PRIO;                                 \
        IPC18bits.DMA1IS = AO_IR_DMA1_SUBPRIO;                              \
}

#endif

#ifndef ao_boot_ir_dma2

#define ao_boot_ir_dma2()                                                   \
{                                                                           \
        IPC18bits.DMA2IP = AO_IR_DMA2_PRIO;                                 \
        IPC18bits.DMA2IS = AO_IR_DMA2_SUBPRIO;                              \
}

#endif

#ifndef ao_boot_ir_dma3

#define ao_boot_ir_dma3()                                                   \
{                                                                           \
        IPC18bits.DMA3IP = AO_IR_DMA3_PRIO;                                 \
        IPC18bits.DMA3IS = AO_IR_DMA3_SUBPRIO;                              \
}

#endif

#ifndef ao_boot_ir_dma4

#define ao_boot_ir_dma4()                                                   \
{                                                                           \
        IPC45bits.DMA4IP = AO_IR_DMA4_PRIO;                                 \
        IPC45bits.DMA4IS = AO_IR_DMA4_SUBPRIO;                              \
}

#endif

#ifndef ao_boot_ir_dma5

#define ao_boot_ir_dma5()                                                   \
{                                                                           \
        IPC45bits.DMA5IP = AO_IR_DMA5_PRIO;                                 \
        IPC45bits.DMA5IS = AO_IR_DMA5_SUBPRIO;                              \
}

#endif

#ifndef ao_boot_ir_dma6

#define ao_boot_ir_dma6()                                                   \
{                                                                           \
        IPC46bits.DMA6IP = AO_IR_DMA6_PRIO;                                 \
        IPC46bits.DMA6IS = AO_IR_DMA6_SUBPRIO;                              \
}

#endif

#ifndef ao_boot_ir_dma7

#define ao_boot_ir_dma7()                                                   \
{                                                                           \
        IPC46bits.DMA7IP = AO_IR_DMA7_PRIO;                                 \
        IPC46bits.DMA7IS = AO_IR_DMA7_SUBPRIO;                              \
}

#endif

#ifndef ao_boot_ir_fce

#define ao_boot_ir_fce()                                                    \
{                                                                           \
        IPC7bits.FCEIP = AO_IR_FCE_PRIO;                                    \
        IPC7bits.FCEIS = AO_IR_FCE_SUBPRIO;                                 \
}

#endif

#ifndef ao_boot_ir_i2c1b

#define ao_boot_ir_i2c1b()                                                  \
{                                                                           \
        IPC10bits.I2C1BIP = AO_IR_I2C1B_PRIO;                               \
        IPC10bits.I2C1BIS = AO_IR_I2C1B_SUBPRIO;                            \
}

#endif

#ifndef ao_boot_ir_i2c1m

#define ao_boot_ir_i2c1m()                                                  \
{                                                                           \
        IPC10bits.I2C1MIP = AO_IR_I2C1M_PRIO;                               \
        IPC10bits.I2C1MIS = AO_IR_I2C1M_SUBPRIO;                            \
}

#endif

#ifndef ao_boot_ir_i2c1s

#define ao_boot_ir_i2c1s()                                                  \
{                                                                           \
        IPC10bits.I2C1SIP = AO_IR_I2C1S_PRIO;                               \
        IPC10bits.I2C1SIS = AO_IR_I2C1S_SUBPRIO;                            \
}

#endif

#ifndef ao_boot_ir_i2c2b

#define ao_boot_ir_i2c2b()                                                  \
{                                                                           \
        IPC14bits.I2C2BIP = AO_IR_I2C2B_PRIO;                               \
        IPC14bits.I2C2BIS = AO_IR_I2C2B_SUBPRIO;                            \
}

#endif

#ifndef ao_boot_ir_i2c2m

#define ao_boot_ir_i2c2m()                                                  \
{                                                                           \
        IPC15bits.I2C2MIP = AO_IR_I2C2M_PRIO;                               \
        IPC15bits.I2C2MIS = AO_IR_I2C2M_SUBPRIO;                            \
}

#endif

#ifndef ao_boot_ir_i2c2s

#define ao_boot_ir_i2c2s()                                                  \
{                                                                           \
        IPC15bits.I2C2SIP = AO_IR_I2C2S_PRIO;                               \
        IPC15bits.I2C2SIS = AO_IR_I2C2S_SUBPRIO;                            \
}

#endif

#ifndef ao_boot_ir_ic1

#define ao_boot_ir_ic1()                                                    \
{                                                                           \
        IPC1bits.IC1IP = AO_IR_IC1_PRIO;                                    \
        IPC1bits.IC1IS = AO_IR_IC1_SUBPRIO;                                 \
}

#endif

#ifndef ao_boot_ir_ic1e

#define ao_boot_ir_ic1e()                                                   \
{                                                                           \
        IPC1bits.IC1EIP = AO_IR_IC1E_PRIO;                                  \
        IPC1bits.IC1EIS = AO_IR_IC1E_SUBPRIO;                               \
}

#endif

#ifndef ao_boot_ir_ic2

#define ao_boot_ir_ic2()                                                    \
{                                                                           \
        IPC2bits.IC2IP = AO_IR_IC2_PRIO;                                    \
        IPC2bits.IC2IS = AO_IR_IC2_SUBPRIO;                                 \
}

#endif

#ifndef ao_boot_ir_ic2e

#define ao_boot_ir_ic2e()                                                   \
{                                                                           \
        IPC2bits.IC2EIP = AO_IR_IC2E_PRIO;                                  \
        IPC2bits.IC2EIS = AO_IR_IC2E_SUBPRIO;                               \
}

#endif

#ifndef ao_boot_ir_ic3

#define ao_boot_ir_ic3()                                                    \
{                                                                           \
        IPC4bits.IC3IP = AO_IR_IC3_PRIO;                                    \
        IPC4bits.IC3IS = AO_IR_IC3_SUBPRIO;                                 \
}

#endif

#ifndef ao_boot_ir_ic3e

#define ao_boot_ir_ic3e()                                                   \
{                                                                           \
        IPC3bits.IC3EIP = AO_IR_IC3E_PRIO;                                  \
        IPC3bits.IC3EIS = AO_IR_IC3E_SUBPRIO;                               \
}

#endif

#ifndef ao_boot_ir_ic4

#define ao_boot_ir_ic4()                                                    \
{                                                                           \
        IPC5bits.IC4IP = AO_IR_IC4_PRIO;                                    \
        IPC5bits.IC4IS = AO_IR_IC4_SUBPRIO;                                 \
}

#endif

#ifndef ao_boot_ir_ic4e

#define ao_boot_ir_ic4e()                                                   \
{                                                                           \
        IPC5bits.IC4EIP = AO_IR_IC4E_PRIO;                                  \
        IPC5bits.IC4EIS = AO_IR_IC4E_SUBPRIO;                               \
}

#endif

#ifndef ao_boot_ir_ic5

#define ao_boot_ir_ic5()                                                    \
{                                                                           \
        IPC6bits.IC5IP = AO_IR_IC5_PRIO;                                    \
        IPC6bits.IC5IS = AO_IR_IC5_SUBPRIO;                                 \
}

#endif

#ifndef ao_boot_ir_ic5e

#define ao_boot_ir_ic5e()                                                   \
{                                                                           \
        IPC6bits.IC5EIP = AO_IR_IC5E_PRIO;                                  \
        IPC6bits.IC5EIS = AO_IR_IC5E_SUBPRIO;                               \
}

#endif

#ifndef ao_boot_ir_ic6

#define ao_boot_ir_ic6()                                                    \
{                                                                           \
        IPC19bits.IC6IP = AO_IR_IC6_PRIO;                                   \
        IPC19bits.IC6IS = AO_IR_IC6_SUBPRIO;                                \
}

#endif

#ifndef ao_boot_ir_ic6e

#define ao_boot_ir_ic6e()                                                   \
{                                                                           \
        IPC19bits.IC6EIP = AO_IR_IC6E_PRIO;                                 \
        IPC19bits.IC6EIS = AO_IR_IC6E_SUBPRIO;                              \
}

#endif

#ifndef ao_boot_ir_ic7

#define ao_boot_ir_ic7()                                                    \
{                                                                           \
        IPC20bits.IC7IP = AO_IR_IC7_PRIO;                                   \
        IPC20bits.IC7IS = AO_IR_IC7_SUBPRIO;                                \
}

#endif

#ifndef ao_boot_ir_ic7e

#define ao_boot_ir_ic7e()                                                   \
{                                                                           \
        IPC20bits.IC7EIP = AO_IR_IC7E_PRIO;                                 \
        IPC20bits.IC7EIS = AO_IR_IC7E_SUBPRIO;                              \
}

#endif

#ifndef ao_boot_ir_ic8

#define ao_boot_ir_ic8()                                                    \
{                                                                           \
        IPC21bits.IC8IP = AO_IR_IC8_PRIO;                                   \
        IPC21bits.IC8IS = AO_IR_IC8_SUBPRIO;                                \
}

#endif

#ifndef ao_boot_ir_ic8e

#define ao_boot_ir_ic8e()                                                   \
{                                                                           \
        IPC21bits.IC8EIP = AO_IR_IC8E_PRIO;                                 \
        IPC21bits.IC8EIS = AO_IR_IC8E_SUBPRIO;                              \
}

#endif

#ifndef ao_boot_ir_ic9

#define ao_boot_ir_ic9()                                                    \
{                                                                           \
        IPC22bits.IC9IP = AO_IR_IC9_PRIO;                                   \
        IPC22bits.IC9IS = AO_IR_IC9_SUBPRIO;                                \
}

#endif

#ifndef ao_boot_ir_ic9e

#define ao_boot_ir_ic9e()                                                   \
{                                                                           \
        IPC22bits.IC9EIP = AO_IR_IC9E_PRIO;                                 \
        IPC22bits.IC9EIS = AO_IR_IC9E_SUBPRIO;                              \
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
        IPC2bits.INT1IP = AO_IR_INT1_PRIO;                                  \
        IPC2bits.INT1IS = AO_IR_INT1_SUBPRIO;                               \
}

#endif

#ifndef ao_boot_ir_int2

#define ao_boot_ir_int2()                                                   \
{                                                                           \
        IPC3bits.INT2IP = AO_IR_INT2_PRIO;                                  \
        IPC3bits.INT2IS = AO_IR_INT2_SUBPRIO;                               \
}

#endif

#ifndef ao_boot_ir_int3

#define ao_boot_ir_int3()                                                   \
{                                                                           \
        IPC4bits.INT3IP = AO_IR_INT3_PRIO;                                  \
        IPC4bits.INT3IS = AO_IR_INT3_SUBPRIO;                               \
}

#endif

#ifndef ao_boot_ir_int4

#define ao_boot_ir_int4()                                                   \
{                                                                           \
        IPC5bits.INT4IP = AO_IR_INT4_PRIO;                                  \
        IPC5bits.INT4IS = AO_IR_INT4_SUBPRIO;                               \
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
        IPC3bits.OC2IP = AO_IR_OC2_PRIO;                                    \
        IPC3bits.OC2IS = AO_IR_OC2_SUBPRIO;                                 \
}

#endif

#ifndef ao_boot_ir_oc3

#define ao_boot_ir_oc3()                                                    \
{                                                                           \
        IPC4bits.OC3IP = AO_IR_OC3_PRIO;                                    \
        IPC4bits.OC3IS = AO_IR_OC3_SUBPRIO;                                 \
}

#endif

#ifndef ao_boot_ir_oc4

#define ao_boot_ir_oc4()                                                    \
{                                                                           \
        IPC5bits.OC4IP = AO_IR_OC4_PRIO;                                    \
        IPC5bits.OC4IS = AO_IR_OC4_SUBPRIO;                                 \
}

#endif

#ifndef ao_boot_ir_oc5

#define ao_boot_ir_oc5()                                                    \
{                                                                           \
        IPC6bits.OC5IP = AO_IR_OC5_PRIO;                                    \
        IPC6bits.OC5IS = AO_IR_OC5_SUBPRIO;                                 \
}

#endif

#ifndef ao_boot_ir_oc6

#define ao_boot_ir_oc6()                                                    \
{                                                                           \
        IPC19bits.OC6IP = AO_IR_OC6_PRIO;                                   \
        IPC19bits.OC6IS = AO_IR_OC6_SUBPRIO;                                \
}

#endif

#ifndef ao_boot_ir_oc7

#define ao_boot_ir_oc7()                                                    \
{                                                                           \
        IPC20bits.OC7IP = AO_IR_OC7_PRIO;                                   \
        IPC20bits.OC7IS = AO_IR_OC7_SUBPRIO;                                \
}

#endif

#ifndef ao_boot_ir_oc8

#define ao_boot_ir_oc8()                                                    \
{                                                                           \
        IPC21bits.OC8IP = AO_IR_OC8_PRIO;                                   \
        IPC21bits.OC8IS = AO_IR_OC8_SUBPRIO;                                \
}

#endif

#ifndef ao_boot_ir_oc9

#define ao_boot_ir_oc9()                                                    \
{                                                                           \
        IPC22bits.OC9IP = AO_IR_OC9_PRIO;                                   \
        IPC22bits.OC9IS = AO_IR_OC9_SUBPRIO;                                \
}

#endif

#ifndef ao_boot_ir_pcache

#define ao_boot_ir_pcache()                                                 \
{                                                                           \
        IPC61bits.PCACHEIP = AO_IR_PCACHE_PRIO;                             \
        IPC61bits.PCACHEIS = AO_IR_PCACHE_SUBPRIO;                          \
}

#endif

#ifndef ao_boot_ir_pwm1

#define ao_boot_ir_pwm1()                                                   \
{                                                                           \
        IPC43bits.PWM1IP = AO_IR_PWM1_PRIO;                                 \
        IPC43bits.PWM1IS = AO_IR_PWM1_SUBPRIO;                              \
}

#endif

#ifndef ao_boot_ir_pwm2

#define ao_boot_ir_pwm2()                                                   \
{                                                                           \
        IPC43bits.PWM2IP = AO_IR_PWM2_PRIO;                                 \
        IPC43bits.PWM2IS = AO_IR_PWM2_SUBPRIO;                              \
}

#endif

#ifndef ao_boot_ir_pwm3

#define ao_boot_ir_pwm3()                                                   \
{                                                                           \
        IPC43bits.PWM3IP = AO_IR_PWM3_PRIO;                                 \
        IPC43bits.PWM3IS = AO_IR_PWM3_SUBPRIO;                              \
}

#endif

#ifndef ao_boot_ir_pwm4

#define ao_boot_ir_pwm4()                                                   \
{                                                                           \
        IPC44bits.PWM4IP = AO_IR_PWM4_PRIO;                                 \
        IPC44bits.PWM4IS = AO_IR_PWM4_SUBPRIO;                              \
}

#endif

#ifndef ao_boot_ir_pwm5

#define ao_boot_ir_pwm5()                                                   \
{                                                                           \
        IPC44bits.PWM5IP = AO_IR_PWM5_PRIO;                                 \
        IPC44bits.PWM5IS = AO_IR_PWM5_SUBPRIO;                              \
}

#endif

#ifndef ao_boot_ir_pwm6

#define ao_boot_ir_pwm6()                                                   \
{                                                                           \
        IPC44bits.PWM6IP = AO_IR_PWM6_PRIO;                                 \
        IPC44bits.PWM6IS = AO_IR_PWM6_SUBPRIO;                              \
}

#endif

#ifndef ao_boot_ir_pwm7

#define ao_boot_ir_pwm7()                                                   \
{                                                                           \
        IPC59bits.PWM7IP = AO_IR_PWM7_PRIO;                                 \
        IPC59bits.PWM7IS = AO_IR_PWM7_SUBPRIO;                              \
}

#endif

#ifndef ao_boot_ir_pwm8

#define ao_boot_ir_pwm8()                                                   \
{                                                                           \
        IPC59bits.PWM8IP = AO_IR_PWM8_PRIO;                                 \
        IPC59bits.PWM8IS = AO_IR_PWM8_SUBPRIO;                              \
}

#endif

#ifndef ao_boot_ir_pwm9

#define ao_boot_ir_pwm9()                                                   \
{                                                                           \
        IPC60bits.PWM9IP = AO_IR_PWM9_PRIO;                                 \
        IPC60bits.PWM9IS = AO_IR_PWM9_SUBPRIO;                              \
}

#endif

#ifndef ao_boot_ir_pwmpevt

#define ao_boot_ir_pwmpevt()                                                \
{                                                                           \
        IPC42bits.PWMPEVTIP = AO_IR_PWMPEVT_PRIO;                           \
        IPC42bits.PWMPEVTSIP = AO_IR_PWMPEVT_SUBPRIO;                       \
}

#endif

#ifndef ao_boot_ir_pwmsevt

#define ao_boot_ir_pwmsevt()                                                \
{                                                                           \
        IPC43bits.PWMSIP = AO_IR_PWMSEVT_PRIO;                              \
        IPC43bits.PWMSIS = AO_IR_PWMSEVT_SUBPRIO;                           \
}

#endif

#ifndef ao_boot_ir_qei1

#define ao_boot_ir_qei1()                                                   \
{                                                                           \
        IPC42bits.QEI1IP = AO_IR_QEI1_PRIO;                                 \
        IPC42bits.QEI1IS = AO_IR_QEI1_SUBPRIO;                              \
}

#endif

#ifndef ao_boot_ir_qei2

#define ao_boot_ir_qei2()                                                   \
{                                                                           \
        IPC42bits.QEI2IP = AO_IR_QEI2_PRIO;                                 \
        IPC42bits.QEI2IS = AO_IR_QEI2_SUBPRIO;                              \
}

#endif

#ifndef ao_boot_ir_qei3

#define ao_boot_ir_qei3()                                                   \
{                                                                           \
        IPC47bits.QEI3IP = AO_IR_QEI3_PRIO;                                 \
        IPC47bits.QEI3IS = AO_IR_QEI3_SUBPRIO;                              \
}

#endif

#ifndef ao_boot_ir_rtcc

#define ao_boot_ir_rtcc()                                                   \
{                                                                           \
        IPC7bits.RTCCIP = AO_IR_RTCC_PRIO;                                  \
        IPC7bits.RTCCIS = AO_IR_RTCC_SUBPRIO;                               \
}

#endif

#ifndef ao_boot_ir_sb

#define ao_boot_ir_sb()                                                     \
{                                                                           \
        IPC57bits.SBIP = AO_IR_SB_PRIO;                                     \
        IPC57bits.SBIS = AO_IR_SB_SUBPRIO;                                  \
}

#endif

#ifndef ao_boot_ir_spi1e

#define ao_boot_ir_spi1e()                                                  \
{                                                                           \
        IPC8bits.SPI1EIP = AO_IR_SPI1E_PRIO;                                \
        IPC8bits.SPI1EIS = AO_IR_SPI1E_SUBPRIO;                             \
}

#endif

#ifndef ao_boot_ir_spi1rx

#define ao_boot_ir_spi1rx()                                                 \
{                                                                           \
        IPC9bits.SPI1RXIP = AO_IR_SPI1RX_PRIO;                              \
        IPC9bits.SPI1RXIS = AO_IR_SPI1RX_SUBPRIO;                           \
}

#endif

#ifndef ao_boot_ir_spi1tx

#define ao_boot_ir_spi1tx()                                                 \
{                                                                           \
        IPC9bits.SPI1TXIP = AO_IR_SPI1TX_PRIO;                              \
        IPC9bits.SPI1TXIS = AO_IR_SPI1TX_SUBPRIO;                           \
}

#endif

#ifndef ao_boot_ir_spi2e

#define ao_boot_ir_spi2e()                                                  \
{                                                                           \
        IPC13bits.SPI2EIP = AO_IR_SPI2E_PRIO;                               \
        IPC13bits.SPI2EIS = AO_IR_SPI2E_SUBPRIO;                            \
}

#endif

#ifndef ao_boot_ir_spi2rx

#define ao_boot_ir_spi2rx()                                                 \
{                                                                           \
        IPC13bits.SPI2RXIP = AO_IR_SPI2RX_PRIO;                             \
        IPC13bits.SPI2RXIS = AO_IR_SPI2RX_SUBPRIO;                          \
}

#endif

#ifndef ao_boot_ir_spi2tx

#define ao_boot_ir_spi2tx()                                                 \
{                                                                           \
        IPC13bits.SPI2TXIP = AO_IR_SPI2TX_PRIO;                             \
        IPC13bits.SPI2TXIS = AO_IR_SPI2TX_SUBPRIO;                          \
}

#endif

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
        IPC6bits.T5IP = AO_IR_T5_PRIO;                                      \
        IPC6bits.T5IS = AO_IR_T5_SUBPRIO;                                   \
}

#endif

#ifndef ao_boot_ir_t6

#define ao_boot_ir_t6()                                                     \
{                                                                           \
        IPC19bits.T6IP = AO_IR_T6_PRIO;                                     \
        IPC19bits.T6IS = AO_IR_T6_SUBPRIO;                                  \
}

#endif

#ifndef ao_boot_ir_t7

#define ao_boot_ir_t7()                                                     \
{                                                                           \
        IPC20bits.T7IP = AO_IR_T7_PRIO;                                     \
        IPC20bits.T7IS = AO_IR_T7_SUBPRIO;                                  \
}

#endif

#ifndef ao_boot_ir_t8

#define ao_boot_ir_t8()                                                     \
{                                                                           \
        IPC21bits.T8IP = AO_IR_T8_PRIO;                                     \
        IPC21bits.T8IS = AO_IR_T8_SUBPRIO;                                  \
}

#endif

#ifndef ao_boot_ir_t9

#define ao_boot_ir_t9()                                                     \
{                                                                           \
        IPC22bits.T9IP = AO_IR_T9_PRIO;                                     \
        IPC22bits.T9IS = AO_IR_T9_SUBPRIO;                                  \
}

#endif

#ifndef ao_boot_ir_u1e

#define ao_boot_ir_u1e()                                                    \
{                                                                           \
        IPC9bits.U1EIP = AO_IR_U1E_PRIO;                                    \
        IPC9bits.U1EIS = AO_IR_U1E_SUBPRIO;                                 \
}

#endif

#ifndef ao_boot_ir_u1rx

#define ao_boot_ir_u1rx()                                                   \
{                                                                           \
        IPC9bits.U1RXIP = AO_IR_U1RX_PRIO;                                  \
        IPC9bits.U1RXIS = AO_IR_U1RX_SUBPRIO;                               \
}

#endif

#ifndef ao_boot_ir_u1tx

#define ao_boot_ir_u1tx()                                                   \
{                                                                           \
        IPC10bits.U1TXIP = AO_IR_U1TX_PRIO;                                 \
        IPC10bits.U1TXIS = AO_IR_U1TX_SUBPRIO;                              \
}

#endif

#ifndef ao_boot_ir_u2e

#define ao_boot_ir_u2e()                                                    \
{                                                                           \
        IPC14bits.U2EIP = AO_IR_U2E_PRIO;                                   \
        IPC14bits.U2EIS = AO_IR_U2E_SUBPRIO;                                \
}

#endif

#ifndef ao_boot_ir_u2rx

#define ao_boot_ir_u2rx()                                                   \
{                                                                           \
        IPC14bits.U2RXIP = AO_IR_U2RX_PRIO;                                 \
        IPC14bits.U2RXIS = AO_IR_U2RX_SUBPRIO;                              \
}

#endif

#ifndef ao_boot_ir_u2tx

#define ao_boot_ir_u2tx()                                                   \
{                                                                           \
        IPC14bits.U2TXIP = AO_IR_U2TX_PRIO;                                 \
        IPC14bits.U2TXIS = AO_IR_U2TX_SUBPRIO;                              \
}

#endif

void    ao_boot_sys_pcache();

```

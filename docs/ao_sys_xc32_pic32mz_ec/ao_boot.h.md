---
author: "Stefan Wagner"
breadcrumbs: 2
date: 2022-08-29
description: "The ao_sys_xc32_pic32mz_ec/ao_boot.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys_xc32_pic32mz_ec/ao_boot.h/ 
subtitle: "<code>ao_sys_xc32_pic32mz_ec</code>"
title: "<code>ao_boot.h</code>"
toc: true
---

```c
#ifndef ao_boot_ir_adc

#define ao_boot_ir_adc()                                                    \
{                                                                           \
        IPC11bits.ADCIP = AO_IR_ADC_PRIO;                                   \
        IPC11bits.ADCIS = AO_IR_ADC_SUBPRIO;                                \
}

#endif

#ifndef ao_boot_ir_adcd0

#define ao_boot_ir_adcd0()                                                  \
{                                                                           \
        IPC14bits.ADCD0IP = AO_IR_ADCD0_PRIO;                               \
        IPC14bits.ADCD0IS = AO_IR_ADCD0_SUBPRIO;                            \
}

#endif

#ifndef ao_boot_ir_adcd1

#define ao_boot_ir_adcd1()                                                  \
{                                                                           \
        IPC15bits.ADCD1IP = AO_IR_ADCD1_PRIO;                               \
        IPC15bits.ADCD1IS = AO_IR_ADCD1_SUBPRIO;                            \
}

#endif

#ifndef ao_boot_ir_adcd2

#define ao_boot_ir_adcd2()                                                  \
{                                                                           \
        IPC15bits.ADCD2IP = AO_IR_ADCD2_PRIO;                               \
        IPC15bits.ADCD2IS = AO_IR_ADCD2_SUBPRIO;                            \
}

#endif

#ifndef ao_boot_ir_adcd3

#define ao_boot_ir_adcd3()                                                  \
{                                                                           \
        IPC15bits.ADCD3IP = AO_IR_ADCD3_PRIO;                               \
        IPC15bits.ADCD3IS = AO_IR_ADCD3_SUBPRIO;                            \
}

#endif

#ifndef ao_boot_ir_adcd4

#define ao_boot_ir_adcd4()                                                  \
{                                                                           \
        IPC15bits.ADCD4IP = AO_IR_ADCD4_PRIO;                               \
        IPC15bits.ADCD4IS = AO_IR_ADCD4_SUBPRIO;                            \
}

#endif

#ifndef ao_boot_ir_adcd5

#define ao_boot_ir_adcd5()                                                  \
{                                                                           \
        IPC16bits.ADCD5IP = AO_IR_ADCD5_PRIO;                               \
        IPC16bits.ADCD5IS = AO_IR_ADCD5_SUBPRIO;                            \
}

#endif

#ifndef ao_boot_ir_adcd6

#define ao_boot_ir_adcd6()                                                  \
{                                                                           \
        IPC16bits.ADCD6IP = AO_IR_ADCD6_PRIO;                               \
        IPC16bits.ADCD6IS = AO_IR_ADCD6_SUBPRIO;                            \
}

#endif

#ifndef ao_boot_ir_adcd7

#define ao_boot_ir_adcd7()                                                  \
{                                                                           \
        IPC16bits.ADCD7IP = AO_IR_ADCD7_PRIO;                               \
        IPC16bits.ADCD7IS = AO_IR_ADCD7_SUBPRIO;                            \
}

#endif

#ifndef ao_boot_ir_adcd8

#define ao_boot_ir_adcd8()                                                  \
{                                                                           \
        IPC16bits.ADCD8IP = AO_IR_ADCD8_PRIO;                               \
        IPC16bits.ADCD8IS = AO_IR_ADCD8_SUBPRIO;                            \
}

#endif

#ifndef ao_boot_ir_adcd9

#define ao_boot_ir_adcd9()                                                  \
{                                                                           \
        IPC17bits.ADCD9IP = AO_IR_ADCD9_PRIO;                               \
        IPC17bits.ADCD9IS = AO_IR_ADCD9_SUBPRIO;                            \
}

#endif

#ifndef ao_boot_ir_adcd10

#define ao_boot_ir_adcd10()                                                 \
{                                                                           \
        IPC17bits.ADCD10IP = AO_IR_ADCD10_PRIO;                             \
        IPC17bits.ADCD10IS = AO_IR_ADCD10_SUBPRIO;                          \
}

#endif

#ifndef ao_boot_ir_adcd11

#define ao_boot_ir_adcd11()                                                 \
{                                                                           \
        IPC17bits.ADCD11IP = AO_IR_ADCD11_PRIO;                             \
        IPC17bits.ADCD11IS = AO_IR_ADCD11_SUBPRIO;                          \
}

#endif

#ifndef ao_boot_ir_adcd12

#define ao_boot_ir_adcd12()                                                 \
{                                                                           \
        IPC17bits.ADCD12IP = AO_IR_ADCD12_PRIO;                             \
        IPC17bits.ADCD12IS = AO_IR_ADCD12_SUBPRIO;                          \
}

#endif

#ifndef ao_boot_ir_adcd13

#define ao_boot_ir_adcd13()                                                 \
{                                                                           \
        IPC18bits.ADCD13IP = AO_IR_ADCD13_PRIO;                             \
        IPC18bits.ADCD13IS = AO_IR_ADCD13_SUBPRIO;                          \
}

#endif

#ifndef ao_boot_ir_adcd14

#define ao_boot_ir_adcd14()                                                 \
{                                                                           \
        IPC18bits.ADCD14IP = AO_IR_ADCD14_PRIO;                             \
        IPC18bits.ADCD14IS = AO_IR_ADCD14_SUBPRIO;                          \
}

#endif

#ifndef ao_boot_ir_adcd15

#define ao_boot_ir_adcd15()                                                 \
{                                                                           \
        IPC18bits.ADCD15IP = AO_IR_ADCD15_PRIO;                             \
        IPC18bits.ADCD15IS = AO_IR_ADCD15_SUBPRIO;                          \
}

#endif

#ifndef ao_boot_ir_adcd16

#define ao_boot_ir_adcd16()                                                 \
{                                                                           \
        IPC18bits.ADCD16IP = AO_IR_ADCD16_PRIO;                             \
        IPC18bits.ADCD16IS = AO_IR_ADCD16_SUBPRIO;                          \
}

#endif

#ifndef ao_boot_ir_adcd17

#define ao_boot_ir_adcd17()                                                 \
{                                                                           \
        IPC19bits.ADCD17IP = AO_IR_ADCD17_PRIO;                             \
        IPC19bits.ADCD17IS = AO_IR_ADCD17_SUBPRIO;                          \
}

#endif

#ifndef ao_boot_ir_adcd18

#define ao_boot_ir_adcd18()                                                 \
{                                                                           \
        IPC19bits.ADCD18IP = AO_IR_ADCD18_PRIO;                             \
        IPC19bits.ADCD18IS = AO_IR_ADCD18_SUBPRIO;                          \
}

#endif

#ifndef ao_boot_ir_adcd19

#define ao_boot_ir_adcd19()                                                 \
{                                                                           \
        IPC19bits.ADCD19IP = AO_IR_ADCD19_PRIO;                             \
        IPC19bits.ADCD19IS = AO_IR_ADCD19_SUBPRIO;                          \
}

#endif

#ifndef ao_boot_ir_adcd20

#define ao_boot_ir_adcd20()                                                 \
{                                                                           \
        IPC19bits.ADCD20IP = AO_IR_ADCD20_PRIO;                             \
        IPC19bits.ADCD20IS = AO_IR_ADCD20_SUBPRIO;                          \
}

#endif

#ifndef ao_boot_ir_adcd21

#define ao_boot_ir_adcd21()                                                 \
{                                                                           \
        IPC20bits.ADCD21IP = AO_IR_ADCD21_PRIO;                             \
        IPC20bits.ADCD21IS = AO_IR_ADCD21_SUBPRIO;                          \
}

#endif

#ifndef ao_boot_ir_adcd22

#define ao_boot_ir_adcd22()                                                 \
{                                                                           \
        IPC20bits.ADCD22IP = AO_IR_ADCD22_PRIO;                             \
        IPC20bits.ADCD22IS = AO_IR_ADCD22_SUBPRIO;                          \
}

#endif

#ifndef ao_boot_ir_adcd23

#define ao_boot_ir_adcd23()                                                 \
{                                                                           \
        IPC20bits.ADCD23IP = AO_IR_ADCD23_PRIO;                             \
        IPC20bits.ADCD23IS = AO_IR_ADCD23_SUBPRIO;                          \
}

#endif

#ifndef ao_boot_ir_adcd24

#define ao_boot_ir_adcd24()                                                 \
{                                                                           \
        IPC20bits.ADCD24IP = AO_IR_ADCD24_PRIO;                             \
        IPC20bits.ADCD24IS = AO_IR_ADCD24_SUBPRIO;                          \
}

#endif

#ifndef ao_boot_ir_adcd25

#define ao_boot_ir_adcd25()                                                 \
{                                                                           \
        IPC21bits.ADCD25IP = AO_IR_ADCD25_PRIO;                             \
        IPC21bits.ADCD25IS = AO_IR_ADCD25_SUBPRIO;                          \
}

#endif

#ifndef ao_boot_ir_adcd26

#define ao_boot_ir_adcd26()                                                 \
{                                                                           \
        IPC21bits.ADCD26IP = AO_IR_ADCD26_PRIO;                             \
        IPC21bits.ADCD26IS = AO_IR_ADCD26_SUBPRIO;                          \
}

#endif

#ifndef ao_boot_ir_adcd27

#define ao_boot_ir_adcd27()                                                 \
{                                                                           \
        IPC21bits.ADCD27IP = AO_IR_ADCD27_PRIO;                             \
        IPC21bits.ADCD27IS = AO_IR_ADCD27_SUBPRIO;                          \
}

#endif

#ifndef ao_boot_ir_adcd28

#define ao_boot_ir_adcd28()                                                 \
{                                                                           \
        IPC21bits.ADCD28IP = AO_IR_ADCD28_PRIO;                             \
        IPC21bits.ADCD28IS = AO_IR_ADCD28_SUBPRIO;                          \
}

#endif

#ifndef ao_boot_ir_adcd29

#define ao_boot_ir_adcd29()                                                 \
{                                                                           \
        IPC22bits.ADCD29IP = AO_IR_ADCD29_PRIO;                             \
        IPC22bits.ADCD29IS = AO_IR_ADCD29_SUBPRIO;                          \
}

#endif

#ifndef ao_boot_ir_adcd30

#define ao_boot_ir_adcd30()                                                 \
{                                                                           \
        IPC22bits.ADCD30IP = AO_IR_ADCD30_PRIO;                             \
        IPC22bits.ADCD30IS = AO_IR_ADCD30_SUBPRIO;                          \
}

#endif

#ifndef ao_boot_ir_adcd31

#define ao_boot_ir_adcd31()                                                 \
{                                                                           \
        IPC22bits.ADCD31IP = AO_IR_ADCD31_PRIO;                             \
        IPC22bits.ADCD31IS = AO_IR_ADCD31_SUBPRIO;                          \
}

#endif

#ifndef ao_boot_ir_adcd32

#define ao_boot_ir_adcd32()                                                 \
{                                                                           \
        IPC22bits.ADCD32IP = AO_IR_ADCD32_PRIO;                             \
        IPC22bits.ADCD32IS = AO_IR_ADCD32_SUBPRIO;                          \
}

#endif

#ifndef ao_boot_ir_adcd33

#define ao_boot_ir_adcd33()                                                 \
{                                                                           \
        IPC23bits.ADCD33IP = AO_IR_ADCD33_PRIO;                             \
        IPC23bits.ADCD33IS = AO_IR_ADCD33_SUBPRIO;                          \
}

#endif

#ifndef ao_boot_ir_adcd34

#define ao_boot_ir_adcd34()                                                 \
{                                                                           \
        IPC23bits.ADCD34IP = AO_IR_ADCD34_PRIO;                             \
        IPC23bits.ADCD34IS = AO_IR_ADCD34_SUBPRIO;                          \
}

#endif

#ifndef ao_boot_ir_adcd35

#define ao_boot_ir_adcd35()                                                 \
{                                                                           \
        IPC23bits.ADCD35IP = AO_IR_ADCD35_PRIO;                             \
        IPC23bits.ADCD35IS = AO_IR_ADCD35_SUBPRIO;                          \
}

#endif

#ifndef ao_boot_ir_adcd36

#define ao_boot_ir_adcd36()                                                 \
{                                                                           \
        IPC23bits.ADCD36IP = AO_IR_ADCD36_PRIO;                             \
        IPC23bits.ADCD36IS = AO_IR_ADCD36_SUBPRIO;                          \
}

#endif

#ifndef ao_boot_ir_adcd37

#define ao_boot_ir_adcd37()                                                 \
{                                                                           \
        IPC24bits.ADCD37IP = AO_IR_ADCD37_PRIO;                             \
        IPC24bits.ADCD37IS = AO_IR_ADCD37_SUBPRIO;                          \
}

#endif

#ifndef ao_boot_ir_adcd38

#define ao_boot_ir_adcd38()                                                 \
{                                                                           \
        IPC24bits.ADCD38IP = AO_IR_ADCD38_PRIO;                             \
        IPC24bits.ADCD38IS = AO_IR_ADCD38_SUBPRIO;                          \
}

#endif

#ifndef ao_boot_ir_adcd39

#define ao_boot_ir_adcd39()                                                 \
{                                                                           \
        IPC24bits.ADCD39IP = AO_IR_ADCD39_PRIO;                             \
        IPC24bits.ADCD39IS = AO_IR_ADCD39_SUBPRIO;                          \
}

#endif

#ifndef ao_boot_ir_adcd40

#define ao_boot_ir_adcd40()                                                 \
{                                                                           \
        IPC24bits.ADCD40IP = AO_IR_ADCD40_PRIO;                             \
        IPC24bits.ADCD40IS = AO_IR_ADCD40_SUBPRIO;                          \
}

#endif

#ifndef ao_boot_ir_adcd41

#define ao_boot_ir_adcd41()                                                 \
{                                                                           \
        IPC25bits.ADCD41IP = AO_IR_ADCD41_PRIO;                             \
        IPC25bits.ADCD41IS = AO_IR_ADCD41_SUBPRIO;                          \
}

#endif

#ifndef ao_boot_ir_adcd42

#define ao_boot_ir_adcd42()                                                 \
{                                                                           \
        IPC25bits.ADCD42IP = AO_IR_ADCD42_PRIO;                             \
        IPC25bits.ADCD42IS = AO_IR_ADCD42_SUBPRIO;                          \
}

#endif

#ifndef ao_boot_ir_adcd43

#define ao_boot_ir_adcd43()                                                 \
{                                                                           \
        IPC25bits.ADCD43IP = AO_IR_ADCD43_PRIO;                             \
        IPC25bits.ADCD43IS = AO_IR_ADCD43_SUBPRIO;                          \
}

#endif

#ifndef ao_boot_ir_adcd44

#define ao_boot_ir_adcd44()                                                 \
{                                                                           \
        IPC25bits.ADCD44IP = AO_IR_ADCD44_PRIO;                             \
        IPC25bits.ADCD44IS = AO_IR_ADCD44_SUBPRIO;                          \
}

#endif

#ifndef ao_boot_ir_adcdc1

#define ao_boot_ir_adcdc1()                                                 \
{                                                                           \
        IPC11bits.ADCDC1IP = AO_IR_ADCDC1_PRIO;                             \
        IPC11bits.ADCDC1IS = AO_IR_ADCDC1_SUBPRIO;                          \
}

#endif

#ifndef ao_boot_ir_adcdc2

#define ao_boot_ir_adcdc2()                                                 \
{                                                                           \
        IPC11bits.ADCDC2IP = AO_IR_ADCDC2_PRIO;                             \
        IPC11bits.ADCDC2IS = AO_IR_ADCDC2_SUBPRIO;                          \
}

#endif

#ifndef ao_boot_ir_adcdc3

#define ao_boot_ir_adcdc3()                                                 \
{                                                                           \
        IPC12bits.ADCDC3IP = AO_IR_ADCDC3_PRIO;                             \
        IPC12bits.ADCDC3IS = AO_IR_ADCDC3_SUBPRIO;                          \
}

#endif

#ifndef ao_boot_ir_adcdc4

#define ao_boot_ir_adcdc4()                                                 \
{                                                                           \
        IPC12bits.ADCDC4IP = AO_IR_ADCDC4_PRIO;                             \
        IPC12bits.ADCDC4IS = AO_IR_ADCDC4_SUBPRIO;                          \
}

#endif

#ifndef ao_boot_ir_adcdc5

#define ao_boot_ir_adcdc5()                                                 \
{                                                                           \
        IPC12bits.ADCDC5IP = AO_IR_ADCDC5_PRIO;                             \
        IPC12bits.ADCDC5IS = AO_IR_ADCDC5_SUBPRIO;                          \
}

#endif

#ifndef ao_boot_ir_adcdc6

#define ao_boot_ir_adcdc6()                                                 \
{                                                                           \
        IPC12bits.ADCDC6IP = AO_IR_ADCDC6_PRIO;                             \
        IPC12bits.ADCDC6IS = AO_IR_ADCDC6_SUBPRIO;                          \
}

#endif

#ifndef ao_boot_ir_adcdf1

#define ao_boot_ir_adcdf1()                                                 \
{                                                                           \
        IPC13bits.ADCDF1IP = AO_IR_ADCDF1_PRIO;                             \
        IPC13bits.ADCDF1IS = AO_IR_ADCDF1_SUBPRIO;                          \
}

#endif

#ifndef ao_boot_ir_adcdf2

#define ao_boot_ir_adcdf2()                                                 \
{                                                                           \
        IPC13bits.ADCDF2IP = AO_IR_ADCDF2_PRIO;                             \
        IPC13bits.ADCDF2IS = AO_IR_ADCDF2_SUBPRIO;                          \
}

#endif

#ifndef ao_boot_ir_adcdf3

#define ao_boot_ir_adcdf3()                                                 \
{                                                                           \
        IPC13bits.ADCDF3IP = AO_IR_ADCDF3_PRIO;                             \
        IPC13bits.ADCDF3IS = AO_IR_ADCDF3_SUBPRIO;                          \
}

#endif

#ifndef ao_boot_ir_adcdf4

#define ao_boot_ir_adcdf4()                                                 \
{                                                                           \
        IPC13bits.ADCDF4IP = AO_IR_ADCDF4_PRIO;                             \
        IPC13bits.ADCDF4IS = AO_IR_ADCDF4_SUBPRIO;                          \
}

#endif

#ifndef ao_boot_ir_adcdf5

#define ao_boot_ir_adcdf5()                                                 \
{                                                                           \
        IPC14bits.ADCDF5IP = AO_IR_ADCDF5_PRIO;                             \
        IPC14bits.ADCDF5IS = AO_IR_ADCDF5_SUBPRIO;                          \
}

#endif

#ifndef ao_boot_ir_adcdf6

#define ao_boot_ir_adcdf6()                                                 \
{                                                                           \
        IPC14bits.ADCDF6IP = AO_IR_ADCDF6_PRIO;                             \
        IPC14bits.ADCDF6IS = AO_IR_ADCDF6_SUBPRIO;                          \
}

#endif

#ifndef ao_boot_ir_can1

#define ao_boot_ir_can1()                                                   \
{                                                                           \
        IPC37bits.CAN1IP = AO_IR_CAN1_PRIO;                                 \
        IPC37bits.CAN1IS = AO_IR_CAN1_SUBPRIO;                              \
}

#endif

#ifndef ao_boot_ir_can2

#define ao_boot_ir_can2()                                                   \
{                                                                           \
        IPC38bits.CAN2IP = AO_IR_CAN2_PRIO;                                 \
        IPC38bits.CAN2IS = AO_IR_CAN2_SUBPRIO;                              \
}

#endif

#ifndef ao_boot_ir_cfdc

#define ao_boot_ir_cfdc()                                                   \
{                                                                           \
        IPC26bits.CFDCIP = AO_IR_CFDC_PRIO;                                 \
        IPC26bits.CFDCIS = AO_IR_CFDC_SUBPRIO;                              \
}

#endif

#ifndef ao_boot_ir_cmp1

#define ao_boot_ir_cmp1()                                                   \
{                                                                           \
        IPC32bits.CMP1IP = AO_IR_CMP1_PRIO;                                 \
        IPC32bits.CMP1IS = AO_IR_CMP1_SUBPRIO;                              \
}

#endif

#ifndef ao_boot_ir_cmp2

#define ao_boot_ir_cmp2()                                                   \
{                                                                           \
        IPC32bits.CMP2IP = AO_IR_CMP2_PRIO;                                 \
        IPC32bits.CMP2IS = AO_IR_CMP2_SUBPRIO;                              \
}

#endif

#ifndef ao_boot_ir_cna

#define ao_boot_ir_cna()                                                    \
{                                                                           \
        IPC29bits.CNAIP = AO_IR_CNA_PRIO;                                   \
        IPC29bits.CNAIS = AO_IR_CNA_SUBPRIO;                                \
}

#endif

#ifndef ao_boot_ir_cnb

#define ao_boot_ir_cnb()                                                    \
{                                                                           \
        IPC29bits.CNBIP = AO_IR_CNB_PRIO;                                   \
        IPC29bits.CNBIS = AO_IR_CNB_SUBPRIO;                                \
}

#endif

#ifndef ao_boot_ir_cnc

#define ao_boot_ir_cnc()                                                    \
{                                                                           \
        IPC30bits.CNCIP = AO_IR_CNC_PRIO;                                   \
        IPC30bits.CNCIS = AO_IR_CNC_SUBPRIO;                                \
}

#endif

#ifndef ao_boot_ir_cnd

#define ao_boot_ir_cnd()                                                    \
{                                                                           \
        IPC30bits.CNDIP = AO_IR_CND_PRIO;                                   \
        IPC30bits.CNDIS = AO_IR_CND_SUBPRIO;                                \
}

#endif

#ifndef ao_boot_ir_cne

#define ao_boot_ir_cne()                                                    \
{                                                                           \
        IPC30bits.CNEIP = AO_IR_CNE_PRIO;                                   \
        IPC30bits.CNEIS = AO_IR_CNE_SUBPRIO;                                \
}

#endif

#ifndef ao_boot_ir_cnf

#define ao_boot_ir_cnf()                                                    \
{                                                                           \
        IPC30bits.CNFIP = AO_IR_CNF_PRIO;                                   \
        IPC30bits.CNFIS = AO_IR_CNF_SUBPRIO;                                \
}

#endif

#ifndef ao_boot_ir_cng

#define ao_boot_ir_cng()                                                    \
{                                                                           \
        IPC31bits.CNGIP = AO_IR_CNG_PRIO;                                   \
        IPC31bits.CNGIS = AO_IR_CNG_SUBPRIO;                                \
}

#endif

#ifndef ao_boot_ir_cnh

#define ao_boot_ir_cnh()                                                    \
{                                                                           \
        IPC31bits.CNHIP = AO_IR_CNH_PRIO;                                   \
        IPC31bits.CNHIS = AO_IR_CNH_SUBPRIO;                                \
}

#endif

#ifndef ao_boot_ir_cnj

#define ao_boot_ir_cnj()                                                    \
{                                                                           \
        IPC31bits.CNJIP = AO_IR_CNJ_PRIO;                                   \
        IPC31bits.CNJIS = AO_IR_CNJ_SUBPRIO;                                \
}

#endif

#ifndef ao_boot_ir_cnk

#define ao_boot_ir_cnk()                                                    \
{                                                                           \
        IPC31bits.CNKIP = AO_IR_CNK_PRIO;                                   \
        IPC31bits.CNKIS = AO_IR_CNK_SUBPRIO;                                \
}

#endif

#ifndef ao_boot_ir_cpc

#define ao_boot_ir_cpc()                                                    \
{                                                                           \
        IPC26bits.CPCIP = AO_IR_CPC_PRIO;                                   \
        IPC26bits.CPCIS = AO_IR_CPC_SUBPRIO;                                \
}

#endif

#ifndef ao_boot_ir_crpt

#define ao_boot_ir_crpt()                                                   \
{                                                                           \
        IPC26bits.CRPTIP = AO_IR_CRPT_PRIO;                                 \
        IPC26bits.CRPTIS = AO_IR_CRPT_SUBPRIO;                              \
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
        IPC33bits.DMA0IP = AO_IR_DMA0_PRIO;                                 \
        IPC33bits.DMA0IS = AO_IR_DMA0_SUBPRIO;                              \
}

#endif

#ifndef ao_boot_ir_dma1

#define ao_boot_ir_dma1()                                                   \
{                                                                           \
        IPC33bits.DMA1IP = AO_IR_DMA1_PRIO;                                 \
        IPC33bits.DMA1IS = AO_IR_DMA1_SUBPRIO;                              \
}

#endif

#ifndef ao_boot_ir_dma2

#define ao_boot_ir_dma2()                                                   \
{                                                                           \
        IPC34bits.DMA2IP = AO_IR_DMA2_PRIO;                                 \
        IPC34bits.DMA2IS = AO_IR_DMA2_SUBPRIO;                              \
}

#endif

#ifndef ao_boot_ir_dma3

#define ao_boot_ir_dma3()                                                   \
{                                                                           \
        IPC34bits.DMA3IP = AO_IR_DMA3_PRIO;                                 \
        IPC34bits.DMA3IS = AO_IR_DMA3_SUBPRIO;                              \
}

#endif

#ifndef ao_boot_ir_dma4

#define ao_boot_ir_dma4()                                                   \
{                                                                           \
        IPC34bits.DMA4IP = AO_IR_DMA4_PRIO;                                 \
        IPC34bits.DMA4IS = AO_IR_DMA4_SUBPRIO;                              \
}

#endif

#ifndef ao_boot_ir_dma5

#define ao_boot_ir_dma5()                                                   \
{                                                                           \
        IPC34bits.DMA5IP = AO_IR_DMA5_PRIO;                                 \
        IPC34bits.DMA5IS = AO_IR_DMA5_SUBPRIO;                              \
}

#endif

#ifndef ao_boot_ir_dma6

#define ao_boot_ir_dma6()                                                   \
{                                                                           \
        IPC35bits.DMA6IP = AO_IR_DMA6_PRIO;                                 \
        IPC35bits.DMA6IS = AO_IR_DMA6_SUBPRIO;                              \
}

#endif

#ifndef ao_boot_ir_dma7

#define ao_boot_ir_dma7()                                                   \
{                                                                           \
        IPC35bits.DMA7IP = AO_IR_DMA7_PRIO;                                 \
        IPC35bits.DMA7IS = AO_IR_DMA7_SUBPRIO;                              \
}

#endif

#ifndef ao_boot_ir_eth

#define ao_boot_ir_eth()                                                    \
{                                                                           \
        IPC38bits.ETHIP = AO_IR_ETH_PRIO;                                   \
        IPC38bits.ETHIS = AO_IR_ETH_SUBPRIO;                                \
}

#endif

#ifndef ao_boot_ir_fce

#define ao_boot_ir_fce()                                                    \
{                                                                           \
        IPC41bits.FCEIP = AO_IR_FCE_PRIO;                                   \
        IPC41bits.FCEIS = AO_IR_FCE_SUBPRIO;                                \
}

#endif

#ifndef ao_boot_ir_i2c1b

#define ao_boot_ir_i2c1b()                                                  \
{                                                                           \
        IPC28bits.I2C1BIP = AO_IR_I2C1B_PRIO;                               \
        IPC28bits.I2C1BIS = AO_IR_I2C1B_SUBPRIO;                            \
}

#endif

#ifndef ao_boot_ir_i2c1m

#define ao_boot_ir_i2c1m()                                                  \
{                                                                           \
        IPC29bits.I2C1MIP = AO_IR_I2C1M_PRIO;                               \
        IPC29bits.I2C1MIS = AO_IR_I2C1M_SUBPRIO;                            \
}

#endif

#ifndef ao_boot_ir_i2c1s

#define ao_boot_ir_i2c1s()                                                  \
{                                                                           \
        IPC29bits.I2C1SIP = AO_IR_I2C1S_PRIO;                               \
        IPC29bits.I2C1SIS = AO_IR_I2C1S_SUBPRIO;                            \
}

#endif

#ifndef ao_boot_ir_i2c2b

#define ao_boot_ir_i2c2b()                                                  \
{                                                                           \
        IPC37bits.I2C2BIP = AO_IR_I2C2B_PRIO;                               \
        IPC37bits.I2C2BIS = AO_IR_I2C2B_SUBPRIO;                            \
}

#endif

#ifndef ao_boot_ir_i2c2m

#define ao_boot_ir_i2c2m()                                                  \
{                                                                           \
        IPC37bits.I2C2MIP = AO_IR_I2C2M_PRIO;                               \
        IPC37bits.I2C2MIS = AO_IR_I2C2M_SUBPRIO;                            \
}

#endif

#ifndef ao_boot_ir_i2c2s

#define ao_boot_ir_i2c2s()                                                  \
{                                                                           \
        IPC37bits.I2C2SIP = AO_IR_I2C2S_PRIO;                               \
        IPC37bits.I2C2SIS = AO_IR_I2C2S_SUBPRIO;                            \
}

#endif

#ifndef ao_boot_ir_i2c3b

#define ao_boot_ir_i2c3b()                                                  \
{                                                                           \
        IPC40bits.I2C3BIP = AO_IR_I2C3B_PRIO;                               \
        IPC40bits.I2C3BIS = AO_IR_I2C3B_SUBPRIO;                            \
}

#endif

#ifndef ao_boot_ir_i2c3m

#define ao_boot_ir_i2c3m()                                                  \
{                                                                           \
        IPC40bits.I2C3MIP = AO_IR_I2C3M_PRIO;                               \
        IPC40bits.I2C3MIS = AO_IR_I2C3M_SUBPRIO;                            \
}

#endif

#ifndef ao_boot_ir_i2c3s

#define ao_boot_ir_i2c3s()                                                  \
{                                                                           \
        IPC40bits.I2C3SIP = AO_IR_I2C3S_PRIO;                               \
        IPC40bits.I2C3SIS = AO_IR_I2C3S_SUBPRIO;                            \
}

#endif

#ifndef ao_boot_ir_i2c4b

#define ao_boot_ir_i2c4b()                                                  \
{                                                                           \
        IPC43bits.I2C4BIP = AO_IR_I2C4B_PRIO;                               \
        IPC43bits.I2C4BIS = AO_IR_I2C4B_SUBPRIO;                            \
}

#endif

#ifndef ao_boot_ir_i2c4m

#define ao_boot_ir_i2c4m()                                                  \
{                                                                           \
        IPC43bits.I2C4MIP = AO_IR_I2C4M_PRIO;                               \
        IPC43bits.I2C4MIS = AO_IR_I2C4M_SUBPRIO;                            \
}

#endif

#ifndef ao_boot_ir_i2c4s

#define ao_boot_ir_i2c4s()                                                  \
{                                                                           \
        IPC43bits.I2C4SIP = AO_IR_I2C4S_PRIO;                               \
        IPC43bits.I2C4SIS = AO_IR_I2C4S_SUBPRIO;                            \
}

#endif

#ifndef ao_boot_ir_i2c5b

#define ao_boot_ir_i2c5b()                                                  \
{                                                                           \
        IPC45bits.I2C5BIP = AO_IR_I2C5B_PRIO;                               \
        IPC45bits.I2C5BIS = AO_IR_I2C5B_SUBPRIO;                            \
}

#endif

#ifndef ao_boot_ir_i2c5m

#define ao_boot_ir_i2c5m()                                                  \
{                                                                           \
        IPC46bits.I2C5MIP = AO_IR_I2C5M_PRIO;                               \
        IPC46bits.I2C5MIS = AO_IR_I2C5M_SUBPRIO;                            \
}

#endif

#ifndef ao_boot_ir_i2c5s

#define ao_boot_ir_i2c5s()                                                  \
{                                                                           \
        IPC45bits.I2C5SIP = AO_IR_I2C5S_PRIO;                               \
        IPC45bits.I2C5SIS = AO_IR_I2C5S_SUBPRIO;                            \
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
        IPC7bits.IC6IP = AO_IR_IC6_PRIO;                                    \
        IPC7bits.IC6IS = AO_IR_IC6_SUBPRIO;                                 \
}

#endif

#ifndef ao_boot_ir_ic6e

#define ao_boot_ir_ic6e()                                                   \
{                                                                           \
        IPC7bits.IC6EIP = AO_IR_IC6E_PRIO;                                  \
        IPC7bits.IC6EIS = AO_IR_IC6E_SUBPRIO;                               \
}

#endif

#ifndef ao_boot_ir_ic7

#define ao_boot_ir_ic7()                                                    \
{                                                                           \
        IPC8bits.IC7IP = AO_IR_IC7_PRIO;                                    \
        IPC8bits.IC7IS = AO_IR_IC7_SUBPRIO;                                 \
}

#endif

#ifndef ao_boot_ir_ic7e

#define ao_boot_ir_ic7e()                                                   \
{                                                                           \
        IPC8bits.IC7EIP = AO_IR_IC7E_PRIO;                                  \
        IPC8bits.IC7EIS = AO_IR_IC7E_SUBPRIO;                               \
}

#endif

#ifndef ao_boot_ir_ic8

#define ao_boot_ir_ic8()                                                    \
{                                                                           \
        IPC9bits.IC8IP = AO_IR_IC8_PRIO;                                    \
        IPC9bits.IC8IS = AO_IR_IC8_SUBPRIO;                                 \
}

#endif

#ifndef ao_boot_ir_ic8e

#define ao_boot_ir_ic8e()                                                   \
{                                                                           \
        IPC9bits.IC8EIP = AO_IR_IC8E_PRIO;                                  \
        IPC9bits.IC8EIS = AO_IR_IC8E_SUBPRIO;                               \
}

#endif

#ifndef ao_boot_ir_ic9

#define ao_boot_ir_ic9()                                                    \
{                                                                           \
        IPC10bits.IC9IP = AO_IR_IC9_PRIO;                                   \
        IPC10bits.IC9IS = AO_IR_IC9_SUBPRIO;                                \
}

#endif

#ifndef ao_boot_ir_ic9e

#define ao_boot_ir_ic9e()                                                   \
{                                                                           \
        IPC10bits.IC9EIP = AO_IR_IC9E_PRIO;                                 \
        IPC10bits.IC9EIS = AO_IR_IC9E_SUBPRIO;                              \
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
        IPC7bits.OC6IP = AO_IR_OC6_PRIO;                                    \
        IPC7bits.OC6IS = AO_IR_OC6_SUBPRIO;                                 \
}

#endif

#ifndef ao_boot_ir_oc7

#define ao_boot_ir_oc7()                                                    \
{                                                                           \
        IPC8bits.OC7IP = AO_IR_OC7_PRIO;                                    \
        IPC8bits.OC7IS = AO_IR_OC7_SUBPRIO;                                 \
}

#endif

#ifndef ao_boot_ir_oc8

#define ao_boot_ir_oc8()                                                    \
{                                                                           \
        IPC9bits.OC8IP = AO_IR_OC8_PRIO;                                    \
        IPC9bits.OC8IS = AO_IR_OC8_SUBPRIO;                                 \
}

#endif

#ifndef ao_boot_ir_oc9

#define ao_boot_ir_oc9()                                                    \
{                                                                           \
        IPC10bits.OC9IP = AO_IR_OC9_PRIO;                                   \
        IPC10bits.OC9IS = AO_IR_OC9_SUBPRIO;                                \
}

#endif

#ifndef ao_boot_ir_pmp

#define ao_boot_ir_pmp()                                                    \
{                                                                           \
        IPC32bits.PMPIP = AO_IR_PMP_PRIO;                                   \
        IPC32bits.PMPIS = AO_IR_PMP_SUBPRIO;                                \
}

#endif

#ifndef ao_boot_ir_pmpe

#define ao_boot_ir_pmpe()                                                   \
{                                                                           \
        IPC32bits.PMPEIP = AO_IR_PMPE_PRIO;                                 \
        IPC32bits.PMPEIS = AO_IR_PMPE_SUBPRIO;                              \
}

#endif

#ifndef ao_boot_ir_pre

#define ao_boot_ir_pre()                                                    \
{                                                                           \
        IPC42bits.PREIP = AO_IR_PRE_PRIO;                                   \
        IPC42bits.PREIS = AO_IR_PRE_SUBPRIO;                                \
}

#endif

#ifndef ao_boot_ir_rtcc

#define ao_boot_ir_rtcc()                                                   \
{                                                                           \
        IPC41bits.RTCCIP = AO_IR_RTCC_PRIO;                                 \
        IPC41bits.RTCCIS = AO_IR_RTCC_SUBPRIO;                              \
}

#endif

#ifndef ao_boot_ir_sb

#define ao_boot_ir_sb()                                                     \
{                                                                           \
        IPC26bits.SBIP = AO_IR_SB_PRIO;                                     \
        IPC26bits.SBIS = AO_IR_SB_SUBPRIO;                                  \
}

#endif

#ifndef ao_boot_ir_spi1e

#define ao_boot_ir_spi1e()                                                  \
{                                                                           \
        IPC27bits.SPI1EIP = AO_IR_SPI1E_PRIO;                               \
        IPC27bits.SPI1EIS = AO_IR_SPI1E_SUBPRIO;                            \
}

#endif

#ifndef ao_boot_ir_spi1rx

#define ao_boot_ir_spi1rx()                                                 \
{                                                                           \
        IPC27bits.SPI1RXIP = AO_IR_SPI1RX_PRIO;                             \
        IPC27bits.SPI1RXIS = AO_IR_SPI1RX_SUBPRIO;                          \
}

#endif

#ifndef ao_boot_ir_spi1tx

#define ao_boot_ir_spi1tx()                                                 \
{                                                                           \
        IPC27bits.SPI1TXIP = AO_IR_SPI1TX_PRIO;                             \
        IPC27bits.SPI1TXIS = AO_IR_SPI1TX_SUBPRIO;                          \
}

#endif

#ifndef ao_boot_ir_spi2e

#define ao_boot_ir_spi2e()                                                  \
{                                                                           \
        IPC35bits.SPI2EIP = AO_IR_SPI2E_PRIO;                               \
        IPC35bits.SPI2EIS = AO_IR_SPI2E_SUBPRIO;                            \
}

#endif

#ifndef ao_boot_ir_spi2rx

#define ao_boot_ir_spi2rx()                                                 \
{                                                                           \
        IPC35bits.SPI2RXIP = AO_IR_SPI2RX_PRIO;                             \
        IPC35bits.SPI2RXIS = AO_IR_SPI2RX_SUBPRIO;                          \
}

#endif

#ifndef ao_boot_ir_spi2tx

#define ao_boot_ir_spi2tx()                                                 \
{                                                                           \
        IPC36bits.SPI2TXIP = AO_IR_SPI2TX_PRIO;                             \
        IPC36bits.SPI2TXIS = AO_IR_SPI2TX_SUBPRIO;                          \
}

#endif

#ifndef ao_boot_ir_spi3e

#define ao_boot_ir_spi3e()                                                  \
{                                                                           \
        IPC38bits.SPI3EIP = AO_IR_SPI3E_PRIO;                               \
        IPC38bits.SPI3EIS = AO_IR_SPI3E_SUBPRIO;                            \
}

#endif

#ifndef ao_boot_ir_spi3rx

#define ao_boot_ir_spi3rx()                                                 \
{                                                                           \
        IPC38bits.SPI3RXIP = AO_IR_SPI3RX_PRIO;                             \
        IPC38bits.SPI3RXIS = AO_IR_SPI3RX_SUBPRIO;                          \
}

#endif

#ifndef ao_boot_ir_spi3tx

#define ao_boot_ir_spi3tx()                                                 \
{                                                                           \
        IPC39bits.SPI3TXIP = AO_IR_SPI3TX_PRIO;                             \
        IPC39bits.SPI3TXIS = AO_IR_SPI3TX_SUBPRIO;                          \
}

#endif

#ifndef ao_boot_ir_spi4e

#define ao_boot_ir_spi4e()                                                  \
{                                                                           \
        IPC40bits.SPI4EIP = AO_IR_SPI4E_PRIO;                               \
        IPC40bits.SPI4EIS = AO_IR_SPI4E_SUBPRIO;                            \
}

#endif

#ifndef ao_boot_ir_spi4rx

#define ao_boot_ir_spi4rx()                                                 \
{                                                                           \
        IPC41bits.SPI4RXIP = AO_IR_SPI4RX_PRIO;                             \
        IPC41bits.SPI4RXIS = AO_IR_SPI4RX_SUBPRIO;                          \
}

#endif

#ifndef ao_boot_ir_spi4tx

#define ao_boot_ir_spi4tx()                                                 \
{                                                                           \
        IPC41bits.SPI4TXIP = AO_IR_SPI4TX_PRIO;                             \
        IPC41bits.SPI4TXIS = AO_IR_SPI4TX_SUBPRIO;                          \
}

#endif

#ifndef ao_boot_ir_spi5e

#define ao_boot_ir_spi5e()                                                  \
{                                                                           \
        IPC44bits.SPI5EIP = AO_IR_SPI5E_PRIO;                               \
        IPC44bits.SPI5EIS = AO_IR_SPI5E_SUBPRIO;                            \
}

#endif

#ifndef ao_boot_ir_spi5rx

#define ao_boot_ir_spi5rx()                                                 \
{                                                                           \
        IPC44bits.SPI5RXIP = AO_IR_SPI5RX_PRIO;                             \
        IPC44bits.SPI5RXIS = AO_IR_SPI5RX_SUBPRIO;                          \
}

#endif

#ifndef ao_boot_ir_spi5tx

#define ao_boot_ir_spi5tx()                                                 \
{                                                                           \
        IPC44bits.SPI5TXIP = AO_IR_SPI5TX_PRIO;                             \
        IPC44bits.SPI5TXIS = AO_IR_SPI5TX_SUBPRIO;                          \
}

#endif

#ifndef ao_boot_ir_spi6e

#define ao_boot_ir_spi6e()                                                  \
{                                                                           \
        IPC46bits.SPI6EIP = AO_IR_SPI6E_PRIO;                               \
        IPC46bits.SPI6EIS = AO_IR_SPI6E_SUBPRIO;                            \
}

#endif

#ifndef ao_boot_ir_spi6rx

#define ao_boot_ir_spi6rx()                                                 \
{                                                                           \
        IPC46bits.SPI6RXIP = AO_IR_SPI6RX_PRIO;                             \
        IPC46bits.SPI6RXIS = AO_IR_SPI6RX_SUBPRIO;                          \
}

#endif

#ifndef ao_boot_ir_spi6tx

#define ao_boot_ir_spi6tx()                                                 \
{                                                                           \
        IPC46bits.SPI6TXIP = AO_IR_SPI6TX_PRIO;                             \
        IPC46bits.SPI6TXIS = AO_IR_SPI6TX_SUBPRIO;                          \
}

#endif

#ifndef ao_boot_ir_sqi1

#define ao_boot_ir_sqi1()                                                   \
{                                                                           \
        IPC42bits.SQI1IP = AO_IR_SQI1_PRIO;                                 \
        IPC42bits.SQI1IS = AO_IR_SQI1_SUBPRIO;                              \
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
        IPC7bits.T6IP = AO_IR_T6_PRIO;                                      \
        IPC7bits.T6IS = AO_IR_T6_SUBPRIO;                                   \
}

#endif

#ifndef ao_boot_ir_t7

#define ao_boot_ir_t7()                                                     \
{                                                                           \
        IPC8bits.T7IP = AO_IR_T7_PRIO;                                      \
        IPC8bits.T7IS = AO_IR_T7_SUBPRIO;                                   \
}

#endif

#ifndef ao_boot_ir_t8

#define ao_boot_ir_t8()                                                     \
{                                                                           \
        IPC9bits.T8IP = AO_IR_T8_PRIO;                                      \
        IPC9bits.T8IS = AO_IR_T8_SUBPRIO;                                   \
}

#endif

#ifndef ao_boot_ir_t9

#define ao_boot_ir_t9()                                                     \
{                                                                           \
        IPC10bits.T9IP = AO_IR_T9_PRIO;                                     \
        IPC10bits.T9IS = AO_IR_T9_SUBPRIO;                                  \
}

#endif

#ifndef ao_boot_ir_u1e

#define ao_boot_ir_u1e()                                                    \
{                                                                           \
        IPC28bits.U1EIP = AO_IR_U1E_PRIO;                                   \
        IPC28bits.U1EIS = AO_IR_U1E_SUBPRIO;                                \
}

#endif

#ifndef ao_boot_ir_u1rx

#define ao_boot_ir_u1rx()                                                   \
{                                                                           \
        IPC28bits.U1RXIP = AO_IR_U1RX_PRIO;                                 \
        IPC28bits.U1RXIS = AO_IR_U1RX_SUBPRIO;                              \
}

#endif

#ifndef ao_boot_ir_u1tx

#define ao_boot_ir_u1tx()                                                   \
{                                                                           \
        IPC28bits.U1TXIP = AO_IR_U1TX_PRIO;                                 \
        IPC28bits.U1TXIS = AO_IR_U1TX_SUBPRIO;                              \
}

#endif

#ifndef ao_boot_ir_u2e

#define ao_boot_ir_u2e()                                                    \
{                                                                           \
        IPC36bits.U2EIP = AO_IR_U2E_PRIO;                                   \
        IPC36bits.U2EIS = AO_IR_U2E_SUBPRIO;                                \
}

#endif

#ifndef ao_boot_ir_u2rx

#define ao_boot_ir_u2rx()                                                   \
{                                                                           \
        IPC36bits.U2RXIP = AO_IR_U2RX_PRIO;                                 \
        IPC36bits.U2RXIS = AO_IR_U2RX_SUBPRIO;                              \
}

#endif

#ifndef ao_boot_ir_u2tx

#define ao_boot_ir_u2tx()                                                   \
{                                                                           \
        IPC36bits.U2TXIP = AO_IR_U2TX_PRIO;                                 \
        IPC36bits.U2TXIS = AO_IR_U2TX_SUBPRIO;                              \
}

#endif

#ifndef ao_boot_ir_u3e

#define ao_boot_ir_u3e()                                                    \
{                                                                           \
        IPC39bits.U3EIP = AO_IR_U3E_PRIO;                                   \
        IPC39bits.U3EIS = AO_IR_U3E_SUBPRIO;                                \
}

#endif

#ifndef ao_boot_ir_u3rx

#define ao_boot_ir_u3rx()                                                   \
{                                                                           \
        IPC39bits.U3RXIP = AO_IR_U3RX_PRIO;                                 \
        IPC39bits.U3RXIS = AO_IR_U3RX_SUBPRIO;                              \
}

#endif

#ifndef ao_boot_ir_u3tx

#define ao_boot_ir_u3tx()                                                   \
{                                                                           \
        IPC39bits.U3TXIP = AO_IR_U3TX_PRIO;                                 \
        IPC39bits.U3TXIS = AO_IR_U3TX_SUBPRIO;                              \
}

#endif

#ifndef ao_boot_ir_u4e

#define ao_boot_ir_u4e()                                                    \
{                                                                           \
        IPC42bits.U4EIP = AO_IR_U4E_PRIO;                                   \
        IPC42bits.U4EIS = AO_IR_U4E_SUBPRIO;                                \
}

#endif

#ifndef ao_boot_ir_u4rx

#define ao_boot_ir_u4rx()                                                   \
{                                                                           \
        IPC42bits.U4RXIP = AO_IR_U4RX_PRIO;                                 \
        IPC42bits.U4RXIS = AO_IR_U4RX_SUBPRIO;                              \
}

#endif

#ifndef ao_boot_ir_u4tx

#define ao_boot_ir_u4tx()                                                   \
{                                                                           \
        IPC43bits.U4TXIP = AO_IR_U4TX_PRIO;                                 \
        IPC43bits.U4TXIS = AO_IR_U4TX_SUBPRIO;                              \
}

#endif

#ifndef ao_boot_ir_u5e

#define ao_boot_ir_u5e()                                                    \
{                                                                           \
        IPC44bits.U5EIP = AO_IR_U5E_PRIO;                                   \
        IPC44bits.U5EIS = AO_IR_U5E_SUBPRIO;                                \
}

#endif

#ifndef ao_boot_ir_u5rx

#define ao_boot_ir_u5rx()                                                   \
{                                                                           \
        IPC45bits.U5RXIP = AO_IR_U5RX_PRIO;                                 \
        IPC45bits.U5RXIS = AO_IR_U5RX_SUBPRIO;                              \
}

#endif

#ifndef ao_boot_ir_u5tx

#define ao_boot_ir_u5tx()                                                   \
{                                                                           \
        IPC45bits.U5TXIP = AO_IR_U5TX_PRIO;                                 \
        IPC45bits.U5TXIS = AO_IR_U5TX_SUBPRIO;                              \
}

#endif

#ifndef ao_boot_ir_u6e

#define ao_boot_ir_u6e()                                                    \
{                                                                           \
        IPC47bits.U6EIP = AO_IR_U6E_PRIO;                                   \
        IPC47bits.U6EIS = AO_IR_U6E_SUBPRIO;                                \
}

#endif

#ifndef ao_boot_ir_u6rx

#define ao_boot_ir_u6rx()                                                   \
{                                                                           \
        IPC47bits.U6RXIP = AO_IR_U6RX_PRIO;                                 \
        IPC47bits.U6RXIS = AO_IR_U6RX_SUBPRIO;                              \
}

#endif

#ifndef ao_boot_ir_u6tx

#define ao_boot_ir_u6tx()                                                   \
{                                                                           \
        IPC47bits.U6TXIP = AO_IR_U6TX_PRIO;                                 \
        IPC47bits.U6TXIS = AO_IR_U6TX_SUBPRIO;                              \
}

#endif

#ifndef ao_boot_ir_usb

#define ao_boot_ir_usb()                                                    \
{                                                                           \
        IPC33bits.USBIP = AO_IR_USB_PRIO;                                   \
        IPC33bits.USBIS = AO_IR_USB_SUBPRIO;                                \
}

#endif

#ifndef ao_boot_ir_usbdma

#define ao_boot_ir_usbdma()                                                 \
{                                                                           \
        IPC33bits.USBDMAIP = AO_IR_USBDMA_PRIO;                             \
        IPC33bits.USBDMAIS = AO_IR_USBDMA_SUBPRIO;                          \
}

#endif

void    ao_boot_sys_pcache();

```

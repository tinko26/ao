---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The ao_sys_xc32_pic32_spi/ao_spi.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys_xc32_pic32_spi/ao_spi.h/ 
subtitle: ""
title: "ao_spi.h"
toc: true
---

```c
#include <stdbool.h>
#include <stdint.h>

typedef struct  ao_spi_reg_t            ao_spi_reg_t;

typedef struct  ao_spi_reg_brg_t        ao_spi_reg_brg_t;

typedef struct  ao_spi_reg_buf_t        ao_spi_reg_buf_t;

typedef struct  ao_spi_reg_con_t        ao_spi_reg_con_t;

typedef struct  ao_spi_reg_con2_t       ao_spi_reg_con2_t;

typedef struct  ao_spi_reg_stat_t       ao_spi_reg_stat_t;

#ifndef AO_SPI

#define AO_SPI

#endif

#ifndef AO_SPI_BRG_BITS

#define AO_SPI_BRG_BITS                 (13)

#endif

#ifndef AO_SPI_BRG_MAX

#define AO_SPI_BRG_MAX                  ((1 << (AO_SPI_BRG_BITS)) - 1)

#endif

#ifndef AO_SPI_BRG_MIN

#define AO_SPI_BRG_MIN                  (0)

#endif

#ifndef AO_SPI_ENHBUF

#define AO_SPI_ENHBUF                   (true)

#endif

#ifndef AO_SPI_REG_BRG

#define AO_SPI_REG_BRG

struct  ao_spi_reg_brg_t
{
        union
        {
            uint32_t        volatile    reg;

            struct
            {
                uint32_t    volatile    brg         : 13;
            }
                                        bits;
        };

        uint32_t            volatile    clr;

        uint32_t            volatile    set;

        uint32_t            volatile    inv;
};

#endif

#ifndef AO_SPI_REG_BUF

#define AO_SPI_REG_BUF

struct  ao_spi_reg_buf_t
{
        union
        {
            uint32_t        volatile    reg;

            struct
            {
                uint32_t    volatile    data        : 32;
            }
                                        bits;
        };

        uint32_t            volatile                : 32;

        uint32_t            volatile                : 32;

        uint32_t            volatile                : 32;
};

#endif

#ifndef AO_SPI_REG_CON

#define AO_SPI_REG_CON

struct  ao_spi_reg_con_t
{
        union
        {
            uint32_t        volatile    reg;

            struct
            {
                uint32_t    volatile    srxisel     :  2;

                uint32_t    volatile    stxisel     :  2;

                uint32_t    volatile    dissdi      :  1;

                uint32_t    volatile    msten       :  1;

                uint32_t    volatile    ckp         :  1;

                uint32_t    volatile    ssen        :  1;

                uint32_t    volatile    cke         :  1;

                uint32_t    volatile    smp         :  1;

                uint32_t    volatile    mode16      :  1;

                uint32_t    volatile    mode32      :  1;

                uint32_t    volatile    dissdo      :  1;

                uint32_t    volatile    sidl        :  1;

                uint32_t    volatile                :  1;

                uint32_t    volatile    on          :  1;

                uint32_t    volatile    enhbuf      :  1;

                uint32_t    volatile    spife       :  1;

                uint32_t    volatile                :  5;

                uint32_t    volatile    mclksel     :  1;

                uint32_t    volatile    frmcnt      :  3;

                uint32_t    volatile    frmsypw     :  1;

                uint32_t    volatile    mssen       :  1;

                uint32_t    volatile    frmpol      :  1;

                uint32_t    volatile    frmsync     :  1;

                uint32_t    volatile    frmen       :  1;
            }
                                        bits;
        };

        uint32_t            volatile    clr;

        uint32_t            volatile    set;

        uint32_t            volatile    inv;
};

#endif

#ifndef AO_SPI_REG_CON2

#define AO_SPI_REG_CON2

struct  ao_spi_reg_con2_t
{
        union
        {
            uint32_t        volatile    reg;

            struct
            {
                uint32_t    volatile    audmod      :  2;

                uint32_t    volatile                :  1;

                uint32_t    volatile    audmono     :  1;

                uint32_t    volatile                :  3;

                uint32_t    volatile    auden       :  1;

                uint32_t    volatile    igntur      :  1;

                uint32_t    volatile    ignrov      :  1;

                uint32_t    volatile    spituren    :  1;

                uint32_t    volatile    spiroven    :  1;

                uint32_t    volatile    frmerren    :  1;

                uint32_t    volatile                :  2;

                uint32_t    volatile    spisgnext   :  1;
            }
                                        bits;
        };

        uint32_t            volatile    clr;

        uint32_t            volatile    set;

        uint32_t            volatile    inv;
};

#endif

#ifndef AO_SPI_REG_STAT

#define AO_SPI_REG_STAT

struct  ao_spi_reg_stat_t
{
        union
        {
            uint32_t        volatile    reg;

            struct
            {
                uint32_t    volatile    spirbf      :  1;

                uint32_t    volatile    spitbf      :  1;

                uint32_t    volatile                :  1;

                uint32_t    volatile    spitbe      :  1;

                uint32_t    volatile                :  1;

                uint32_t    volatile    spirbe      :  1;

                uint32_t    volatile    spirov      :  1;

                uint32_t    volatile    srmt        :  1;

                uint32_t    volatile    spitur      :  1;

                uint32_t    volatile                :  2;

                uint32_t    volatile    spibusy     :  1;

                uint32_t    volatile    frmerr      :  1;

                uint32_t    volatile                :  3;

                uint32_t    volatile    txbufelm    :  5;

                uint32_t    volatile                :  3;

                uint32_t    volatile    rxbufelm    :  5;
            }
                                        bits;
        };

        uint32_t            volatile    clr;

        uint32_t            volatile    set;

        uint32_t            volatile    inv;
};

#endif

#ifndef AO_SPI_REG

#define AO_SPI_REG

struct  ao_spi_reg_t
{
        ao_spi_reg_con_t                con;

        ao_spi_reg_stat_t               stat;

        ao_spi_reg_buf_t                buf;

        ao_spi_reg_brg_t                brg;

        ao_spi_reg_con2_t               con2;
};

#endif

void    ao_spi_baud
(
        ao_spi_reg_t *                  r,

        uint32_t                        f_pbclk,

        uint32_t                        f
);

#ifndef AO_SPI_BAUD_MAX

#define AO_SPI_BAUD_MAX(f_pbclk)        ((f_pbclk) / (2 * ((AO_SPI_BRG_MIN) + 1)))

#endif

#ifndef AO_SPI_BAUD_MIN

#define AO_SPI_BAUD_MIN(f_pbclk)        (1 + (((f_pbclk) - 1) / (2 * ((AO_SPI_BRG_MAX) + 1))))

#endif

```

---
author: "Stefan Wagner"
breadcrumbs: 2
date: 2022-08-29
description: "The ao_sys_xc32_pic32_uart/ao_uart.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys_xc32_pic32_uart/ao_uart.h/ 
subtitle: "<code>ao_sys_xc32_pic32_uart</code>"
title: "<code>ao_uart.h</code>"
toc: true
---

```c
typedef enum    ao_uart_error_flags_t       ao_uart_error_flags_t;

typedef struct  ao_uart_error_info_t        ao_uart_error_info_t;

typedef struct  ao_uart_reg_t               ao_uart_reg_t;

typedef struct  ao_uart_reg_brg_t           ao_uart_reg_brg_t;

typedef struct  ao_uart_reg_mode_t          ao_uart_reg_mode_t;

typedef struct  ao_uart_reg_rx_t            ao_uart_reg_rx_t;

typedef struct  ao_uart_reg_sta_t           ao_uart_reg_sta_t;

typedef struct  ao_uart_reg_tx_t            ao_uart_reg_tx_t;

#ifndef AO_UART

#define AO_UART

#endif

#ifndef AO_UART_BRG_BITS

#define AO_UART_BRG_BITS                    (16)

#endif

#ifndef AO_UART_BRG_MAX

#define AO_UART_BRG_MAX                     ((1 << (AO_UART_BRG_BITS)) - 1)

#endif

#ifndef AO_UART_BRG_MIN

#define AO_UART_BRG_MIN                     (0)

#endif

#ifndef AO_UART_DATA_BITS_8_PARITY_NONE

#define AO_UART_DATA_BITS_8_PARITY_NONE     (0b00)

#endif

#ifndef AO_UART_DATA_BITS_8_PARITY_EVEN

#define AO_UART_DATA_BITS_8_PARITY_EVEN     (0b01)

#endif

#ifndef AO_UART_DATA_BITS_8_PARITY_ODD

#define AO_UART_DATA_BITS_8_PARITY_ODD      (0b10)

#endif

#ifndef AO_UART_DATA_BITS_9_PARITY_NONE

#define AO_UART_DATA_BITS_9_PARITY_NONE     (0b11)

#endif

#ifndef AO_UART_FIFO_CAPACITY

#define AO_UART_FIFO_CAPACITY               (8)

#endif

#ifndef AO_UART_STOP_BITS_ONE

#define AO_UART_STOP_BITS_ONE               (0)

#endif

#ifndef AO_UART_STOP_BITS_TWO

#define AO_UART_STOP_BITS_TWO               (1)

#endif

#ifndef AO_UART_ERROR_FLAGS

#define AO_UART_ERROR_FLAGS

enum    ao_uart_error_flags_t
{
        AO_UART_ERROR_ALL                   = 0x0E,

        AO_UART_ERROR_FRAMING               = 0x04,

        AO_UART_ERROR_NONE                  = 0,

        AO_UART_ERROR_OVERRUN               = 0x02,

        AO_UART_ERROR_PARITY                = 0x08,
};

#endif

#ifndef AO_UART_ERROR_INFO

#define AO_UART_ERROR_INFO

struct  ao_uart_error_info_t
{
        ao_uart_error_flags_t               flags;
};

#endif

#ifndef AO_UART_REG_BRG

#define AO_UART_REG_BRG

struct  ao_uart_reg_brg_t
{
        union
        {
            uint32_t            volatile    reg;

            struct
            {
                uint32_t        volatile    brg     : 16;
            }
                                            bits;
        };

        uint32_t                volatile    clr;

        uint32_t                volatile    set;

        uint32_t                volatile    inv;
};

#endif

#ifndef AO_UART_REG_MODE

#define AO_UART_REG_MODE

struct  ao_uart_reg_mode_t
{
        union
        {
            uint32_t            volatile    reg;

            struct
            {
                uint32_t        volatile    stsel   :  1;

                uint32_t        volatile    pdsel   :  2;

                uint32_t        volatile    brgh    :  1;

                uint32_t        volatile    rxinv   :  1;

                uint32_t        volatile    abaud   :  1;

                uint32_t        volatile    lpback  :  1;

                uint32_t        volatile    wake    :  1;

                uint32_t        volatile    uen     :  2;

                uint32_t        volatile            :  1;

                uint32_t        volatile    rtsmd   :  1;

                uint32_t        volatile    iren    :  1;

                uint32_t        volatile    sidl    :  1;

                uint32_t        volatile            :  1;

                uint32_t        volatile    on      :  1;

                uint32_t        volatile    runovf  :  1;

                uint32_t        volatile    clksel  :  2;

                uint32_t        volatile            :  3;

                uint32_t        volatile    active  :  1;

                uint32_t        volatile    slpen   :  1;
            }
                                            bits;
        };

        uint32_t                volatile    clr;

        uint32_t                volatile    set;

        uint32_t                volatile    inv;
};

#endif

#ifndef AO_UART_REG_RX

#define AO_UART_REG_RX

struct  ao_uart_reg_rx_t
{
        union
        {
            uint32_t            volatile    reg;

            struct
            {
                uint32_t        volatile    rx      :  9;
            }
                                            bits;
        };

        uint32_t                volatile            : 32;

        uint32_t                volatile            : 32;

        uint32_t                volatile            : 32;
};

#endif

#ifndef AO_UART_REG_STA

#define AO_UART_REG_STA

struct  ao_uart_reg_sta_t
{
        union
        {
            uint32_t            volatile    reg;

            struct
            {
                uint32_t        volatile    urxda   :  1;

                uint32_t        volatile    oerr    :  1;

                uint32_t        volatile    ferr    :  1;

                uint32_t        volatile    perr    :  1;

                uint32_t        volatile    ridle   :  1;

                uint32_t        volatile    adden   :  1;

                uint32_t        volatile    urxisel :  2;

                uint32_t        volatile    trmt    :  1;

                uint32_t        volatile    utxbf   :  1;

                uint32_t        volatile    utxen   :  1;

                uint32_t        volatile    utxbrk  :  1;

                uint32_t        volatile    urxen   :  1;

                uint32_t        volatile    utxinv  :  1;

                uint32_t        volatile    utxisel :  2;

                uint32_t        volatile    addr    :  8;

                uint32_t        volatile    adm_en  :  1;
            }
                                            bits;
        };

        uint32_t                volatile    clr;

        uint32_t                volatile    set;

        uint32_t                volatile    inv;
};

#endif

#ifndef AO_UART_REG_TX

#define AO_UART_REG_TX

struct  ao_uart_reg_tx_t
{
        union
        {
            uint32_t            volatile    reg;

            struct
            {
                uint32_t        volatile    tx      :  9;
            }
                                            bits;
        };

        uint32_t                volatile            : 32;

        uint32_t                volatile            : 32;

        uint32_t                volatile            : 32;
};

#endif

#ifndef AO_UART_REG

#define AO_UART_REG

struct  ao_uart_reg_t
{
        ao_uart_reg_mode_t                  mode;

        ao_uart_reg_sta_t                   sta;

        ao_uart_reg_tx_t                    tx;

        ao_uart_reg_rx_t                    rx;

        ao_uart_reg_brg_t                   brg;
};

#endif

void    ao_uart_baud
(
        ao_uart_reg_t *                     r,

        uint32_t                            f_pbclk,

        uint32_t                            f
);

#ifndef AO_UART_BAUD_MAX

#define AO_UART_BAUD_MAX(f_pbclk)           AO_UART_BAUD_HIGH_MAX(f_pbclk)

#endif

#ifndef AO_UART_BAUD_MIN

#define AO_UART_BAUD_MIN(f_pbclk)           AO_UART_BAUD_LOW_MIN(f_pbclk)

#endif

void    ao_uart_baud_high
(
        ao_uart_reg_t *                     r,

        uint32_t                            f_pbclk,

        uint32_t                            f
);

#ifndef AO_UART_BAUD_HIGH_MAX

#define AO_UART_BAUD_HIGH_MAX(f_pbclk)      ((f_pbclk) / (4 * ((AO_UART_BRG_MIN) + 1)))

#endif

#ifndef AO_UART_BAUD_HIGH_MIN

#define AO_UART_BAUD_HIGH_MIN(f_pbclk)      (1 + (((f_pbclk) - 1) / (4 * ((AO_UART_BRG_MAX) + 1))))

#endif

void    ao_uart_baud_low
(
        ao_uart_reg_t *                     r,

        uint32_t                            f_pbclk,

        uint32_t                            f
);

#ifndef AO_UART_BAUD_LOW_MAX

#define AO_UART_BAUD_LOW_MAX(f_pbclk)       ((f_pbclk) / (16 * ((AO_UART_BRG_MIN) + 1)))

#endif

#ifndef AO_UART_BAUD_LOW_MIN

#define AO_UART_BAUD_LOW_MIN(f_pbclk)       (1 + (((f_pbclk) - 1) / (16 * ((AO_UART_BRG_MAX) + 1))))

#endif

void    ao_uart_loopback_disable(           ao_uart_reg_t * r);

void    ao_uart_loopback_enable(            ao_uart_reg_t * r);

```

---
author: "Stefan Wagner"
date: 2022-08-29
description: "The ao_sys_xc32_pic32_uart/ao_uart_5.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys_xc32_pic32_uart/ao_uart_5.h/ 
subtitle: "<code>ao_sys_xc32_pic32_uart</code>"
title: "<code>ao_uart_5.h</code>"
toc: true
---

#ifndef AO_UART_5

#ifdef  _UART5

#define AO_UART_5                       (true)

#else

#define AO_UART_5                       (false)

#endif

#endif

#ifndef AO_UART_RX_5

#define AO_UART_RX_5                    (false)

#endif

#ifndef AO_UART_TX_5

#define AO_UART_TX_5                    (false)

#endif

#ifndef AO_UART_BAUD_5

#define AO_UART_BAUD_5                  (9600)

#endif

#ifndef AO_UART_BAUD_MAX_5

#define AO_UART_BAUD_MAX_5              AO_UART_BAUD_MAX(AO_SYS_CLOCK_U5)

#endif

#ifndef AO_UART_BAUD_MIN_5

#define AO_UART_BAUD_MIN_5              AO_UART_BAUD_MIN(AO_SYS_CLOCK_U5)

#endif

#ifndef AO_UART_BAUD_HIGH_MAX_5

#define AO_UART_BAUD_HIGH_MAX_5         AO_UART_BAUD_HIGH_MAX(AO_SYS_CLOCK_U5)

#endif

#ifndef AO_UART_BAUD_HIGH_MIN_5

#define AO_UART_BAUD_HIGH_MIN_5         AO_UART_BAUD_HIGH_MIN(AO_SYS_CLOCK_U5)

#endif

#ifndef AO_UART_BAUD_LOW_MAX_5

#define AO_UART_BAUD_LOW_MAX_5          AO_UART_BAUD_LOW_MAX(AO_SYS_CLOCK_U5)

#endif

#ifndef AO_UART_BAUD_LOW_MIN_5

#define AO_UART_BAUD_LOW_MIN_5          AO_UART_BAUD_LOW_MIN(AO_SYS_CLOCK_U5)

#endif

#ifndef AO_UART_DATA_BITS_PARITY_5

#define AO_UART_DATA_BITS_PARITY_5      (AO_UART_DATA_BITS_8_PARITY_NONE)

#endif

#ifndef AO_UART_STOP_BITS_5

#define AO_UART_STOP_BITS_5             (AO_UART_STOP_BITS_ONE)

#endif

#ifndef AO_UART_ERROR_5

#define AO_UART_ERROR_5                 (false)

#endif

#ifndef AO_UART_LOOPBACK_5

#define AO_UART_LOOPBACK_5              (false)

#endif

extern  ao_send_t                       ao_uart_in_5;

extern  ao_recv_t                       ao_uart_out_5;

extern  ao_task_t                       ao_uart_task_5;

#ifndef ao_uart_baud_5

#define ao_uart_baud_5(f)               ao_uart_baud(ao_uart_reg_5(), AO_SYS_CLOCK_U5, f)

#endif

#ifndef ao_uart_baud_high_5

#define ao_uart_baud_high_5(f)          ao_uart_baud_high(ao_uart_reg_5(), AO_SYS_CLOCK_U5, f)

#endif

#ifndef ao_uart_baud_low_5

#define ao_uart_baud_low_5(f)           ao_uart_baud_low(ao_uart_reg_5(), AO_SYS_CLOCK_U5, f)

#endif

void    ao_uart_config_5();

void    ao_uart_config_baud_5();

void    ao_uart_config_frame_5();

void    ao_uart_config_loopback_5();

void    ao_uart_error_5(                ao_uart_error_info_t const * info);

#ifndef ao_uart_loopback_disable_5

#define ao_uart_loopback_disable_5()    ao_uart_loopback_disable(ao_uart_reg_5())

#endif

#ifndef ao_uart_loopback_enable_5

#define ao_uart_loopback_enable_5()     ao_uart_loopback_enable(ao_uart_reg_5())

#endif

#ifndef ao_uart_reg_5

#define ao_uart_reg_5()                 ((ao_uart_reg_t *) (_UART5_BASE_ADDRESS))

#endif

void    ao_uart_start_5();

void    ao_uart_stop_5();


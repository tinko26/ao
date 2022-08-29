---
author: "Stefan Wagner"
breadcrumbs: 2
date: 2022-08-29
description: "The ao_sys_xc32_pic32_uart/ao_uart_6.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys_xc32_pic32_uart/ao_uart_6.h/ 
subtitle: "<code>ao_sys_xc32_pic32_uart</code>"
title: "<code>ao_uart_6.h</code>"
toc: true
---

```c
#ifndef AO_UART_6

#ifdef  _UART6

#define AO_UART_6                       (true)

#else

#define AO_UART_6                       (false)

#endif

#endif

#ifndef AO_UART_RX_6

#define AO_UART_RX_6                    (false)

#endif

#ifndef AO_UART_TX_6

#define AO_UART_TX_6                    (false)

#endif

#ifndef AO_UART_BAUD_6

#define AO_UART_BAUD_6                  (9600)

#endif

#ifndef AO_UART_BAUD_MAX_6

#define AO_UART_BAUD_MAX_6              AO_UART_BAUD_MAX(AO_SYS_CLOCK_U6)

#endif

#ifndef AO_UART_BAUD_MIN_6

#define AO_UART_BAUD_MIN_6              AO_UART_BAUD_MIN(AO_SYS_CLOCK_U6)

#endif

#ifndef AO_UART_BAUD_HIGH_MAX_6

#define AO_UART_BAUD_HIGH_MAX_6         AO_UART_BAUD_HIGH_MAX(AO_SYS_CLOCK_U6)

#endif

#ifndef AO_UART_BAUD_HIGH_MIN_6

#define AO_UART_BAUD_HIGH_MIN_6         AO_UART_BAUD_HIGH_MIN(AO_SYS_CLOCK_U6)

#endif

#ifndef AO_UART_BAUD_LOW_MAX_6

#define AO_UART_BAUD_LOW_MAX_6          AO_UART_BAUD_LOW_MAX(AO_SYS_CLOCK_U6)

#endif

#ifndef AO_UART_BAUD_LOW_MIN_6

#define AO_UART_BAUD_LOW_MIN_6          AO_UART_BAUD_LOW_MIN(AO_SYS_CLOCK_U6)

#endif

#ifndef AO_UART_DATA_BITS_PARITY_6

#define AO_UART_DATA_BITS_PARITY_6      (AO_UART_DATA_BITS_8_PARITY_NONE)

#endif

#ifndef AO_UART_STOP_BITS_6

#define AO_UART_STOP_BITS_6             (AO_UART_STOP_BITS_ONE)

#endif

#ifndef AO_UART_ERROR_6

#define AO_UART_ERROR_6                 (false)

#endif

#ifndef AO_UART_LOOPBACK_6

#define AO_UART_LOOPBACK_6              (false)

#endif

extern  ao_send_t                       ao_uart_in_6;

extern  ao_recv_t                       ao_uart_out_6;

extern  ao_task_t                       ao_uart_task_6;

#ifndef ao_uart_baud_6

#define ao_uart_baud_6(f)               ao_uart_baud(ao_uart_reg_6(), AO_SYS_CLOCK_U6, f)

#endif

#ifndef ao_uart_baud_high_6

#define ao_uart_baud_high_6(f)          ao_uart_baud_high(ao_uart_reg_6(), AO_SYS_CLOCK_U6, f)

#endif

#ifndef ao_uart_baud_low_6

#define ao_uart_baud_low_6(f)           ao_uart_baud_low(ao_uart_reg_6(), AO_SYS_CLOCK_U6, f)

#endif

void    ao_uart_config_6();

void    ao_uart_config_baud_6();

void    ao_uart_config_frame_6();

void    ao_uart_config_loopback_6();

void    ao_uart_error_6(                ao_uart_error_info_t const * info);

#ifndef ao_uart_loopback_disable_6

#define ao_uart_loopback_disable_6()    ao_uart_loopback_disable(ao_uart_reg_6())

#endif

#ifndef ao_uart_loopback_enable_6

#define ao_uart_loopback_enable_6()     ao_uart_loopback_enable(ao_uart_reg_6())

#endif

#ifndef ao_uart_reg_6

#define ao_uart_reg_6()                 ((ao_uart_reg_t *) (_UART6_BASE_ADDRESS))

#endif

void    ao_uart_start_6();

void    ao_uart_stop_6();

```

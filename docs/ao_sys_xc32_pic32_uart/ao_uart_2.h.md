---
author: "Stefan Wagner"
breadcrumbs: 2
date: 2022-08-29
description: "The ao_sys_xc32_pic32_uart/ao_uart_2.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys_xc32_pic32_uart/ao_uart_2.h/ 
subtitle: "<code>ao_sys_xc32_pic32_uart</code>"
title: "<code>ao_uart_2.h</code>"
toc: true
---

```c
#ifndef AO_UART_2

#ifdef  _UART2

#define AO_UART_2                       (true)

#else

#define AO_UART_2                       (false)

#endif

#endif

#ifndef AO_UART_RX_2

#define AO_UART_RX_2                    (false)

#endif

#ifndef AO_UART_TX_2

#define AO_UART_TX_2                    (false)

#endif

#ifndef AO_UART_BAUD_2

#define AO_UART_BAUD_2                  (9600)

#endif

#ifndef AO_UART_BAUD_MAX_2

#define AO_UART_BAUD_MAX_2              AO_UART_BAUD_MAX(AO_SYS_CLOCK_U2)

#endif

#ifndef AO_UART_BAUD_MIN_2

#define AO_UART_BAUD_MIN_2              AO_UART_BAUD_MIN(AO_SYS_CLOCK_U2)

#endif

#ifndef AO_UART_BAUD_HIGH_MAX_2

#define AO_UART_BAUD_HIGH_MAX_2         AO_UART_BAUD_HIGH_MAX(AO_SYS_CLOCK_U2)

#endif

#ifndef AO_UART_BAUD_HIGH_MIN_2

#define AO_UART_BAUD_HIGH_MIN_2         AO_UART_BAUD_HIGH_MIN(AO_SYS_CLOCK_U2)

#endif

#ifndef AO_UART_BAUD_LOW_MAX_2

#define AO_UART_BAUD_LOW_MAX_2          AO_UART_BAUD_LOW_MAX(AO_SYS_CLOCK_U2)

#endif

#ifndef AO_UART_BAUD_LOW_MIN_2

#define AO_UART_BAUD_LOW_MIN_2          AO_UART_BAUD_LOW_MIN(AO_SYS_CLOCK_U2)

#endif

#ifndef AO_UART_DATA_BITS_PARITY_2

#define AO_UART_DATA_BITS_PARITY_2      (AO_UART_DATA_BITS_8_PARITY_NONE)

#endif

#ifndef AO_UART_STOP_BITS_2

#define AO_UART_STOP_BITS_2             (AO_UART_STOP_BITS_ONE)

#endif

#ifndef AO_UART_ERROR_2

#define AO_UART_ERROR_2                 (false)

#endif

#ifndef AO_UART_LOOPBACK_2

#define AO_UART_LOOPBACK_2              (false)

#endif

extern  ao_send_t                       ao_uart_in_2;

extern  ao_recv_t                       ao_uart_out_2;

extern  ao_task_t                       ao_uart_task_2;

#ifndef ao_uart_baud_2

#define ao_uart_baud_2(f)               ao_uart_baud(ao_uart_reg_2(), AO_SYS_CLOCK_U2, f)

#endif

#ifndef ao_uart_baud_high_2

#define ao_uart_baud_high_2(f)          ao_uart_baud_high(ao_uart_reg_2(), AO_SYS_CLOCK_U2, f)

#endif

#ifndef ao_uart_baud_low_2

#define ao_uart_baud_low_2(f)           ao_uart_baud_low(ao_uart_reg_2(), AO_SYS_CLOCK_U2, f)

#endif

void    ao_uart_config_2();

void    ao_uart_config_baud_2();

void    ao_uart_config_frame_2();

void    ao_uart_config_loopback_2();

void    ao_uart_error_2(                ao_uart_error_info_t const * info);

#ifndef ao_uart_loopback_disable_2

#define ao_uart_loopback_disable_2()    ao_uart_loopback_disable(ao_uart_reg_2())

#endif

#ifndef ao_uart_loopback_enable_2

#define ao_uart_loopback_enable_2()     ao_uart_loopback_enable(ao_uart_reg_2())

#endif

#ifndef ao_uart_reg_2

#define ao_uart_reg_2()                 ((ao_uart_reg_t *) (_UART2_BASE_ADDRESS))

#endif

void    ao_uart_start_2();

void    ao_uart_stop_2();

```

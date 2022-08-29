---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The ao_sys_xc32_pic32_uart/ao_uart_1.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys_xc32_pic32_uart/ao_uart_1.h/ 
subtitle: ""
title: "ao_uart_1.h"
toc: true
---

```c
#include <ao_recv.h>
#include <ao_send.h>
#include <ao_sys.h>
#include <ao_task.h>
#include <ao_uart.h>
#include <stdbool.h>
#include <xc.h>

#ifndef AO_UART_1

#ifdef  _UART1

#define AO_UART_1                       (true)

#else

#define AO_UART_1                       (false)

#endif

#endif

#ifndef AO_UART_RX_1

#define AO_UART_RX_1                    (false)

#endif

#ifndef AO_UART_TX_1

#define AO_UART_TX_1                    (false)

#endif

#ifndef AO_UART_BAUD_1

#define AO_UART_BAUD_1                  (9600)

#endif

#ifndef AO_UART_BAUD_MAX_1

#define AO_UART_BAUD_MAX_1              AO_UART_BAUD_MAX(AO_SYS_CLOCK_U1)

#endif

#ifndef AO_UART_BAUD_MIN_1

#define AO_UART_BAUD_MIN_1              AO_UART_BAUD_MIN(AO_SYS_CLOCK_U1)

#endif

#ifndef AO_UART_BAUD_HIGH_MAX_1

#define AO_UART_BAUD_HIGH_MAX_1         AO_UART_BAUD_HIGH_MAX(AO_SYS_CLOCK_U1)

#endif

#ifndef AO_UART_BAUD_HIGH_MIN_1

#define AO_UART_BAUD_HIGH_MIN_1         AO_UART_BAUD_HIGH_MIN(AO_SYS_CLOCK_U1)

#endif

#ifndef AO_UART_BAUD_LOW_MAX_1

#define AO_UART_BAUD_LOW_MAX_1          AO_UART_BAUD_LOW_MAX(AO_SYS_CLOCK_U1)

#endif

#ifndef AO_UART_BAUD_LOW_MIN_1

#define AO_UART_BAUD_LOW_MIN_1          AO_UART_BAUD_LOW_MIN(AO_SYS_CLOCK_U1)

#endif

#ifndef AO_UART_DATA_BITS_PARITY_1

#define AO_UART_DATA_BITS_PARITY_1      (AO_UART_DATA_BITS_8_PARITY_NONE)

#endif

#ifndef AO_UART_STOP_BITS_1

#define AO_UART_STOP_BITS_1             (AO_UART_STOP_BITS_ONE)

#endif

#ifndef AO_UART_ERROR_1

#define AO_UART_ERROR_1                 (false)

#endif

#ifndef AO_UART_LOOPBACK_1

#define AO_UART_LOOPBACK_1              (false)

#endif

extern  ao_send_t                       ao_uart_in_1;

extern  ao_recv_t                       ao_uart_out_1;

extern  ao_task_t                       ao_uart_task_1;

#ifndef ao_uart_baud_1

#define ao_uart_baud_1(f)               ao_uart_baud(ao_uart_reg_1(), AO_SYS_CLOCK_U1, f)

#endif

#ifndef ao_uart_baud_high_1

#define ao_uart_baud_high_1(f)          ao_uart_baud_high(ao_uart_reg_1(), AO_SYS_CLOCK_U1, f)

#endif

#ifndef ao_uart_baud_low_1

#define ao_uart_baud_low_1(f)           ao_uart_baud_low(ao_uart_reg_1(), AO_SYS_CLOCK_U1, f)

#endif

void    ao_uart_config_1();

void    ao_uart_config_baud_1();

void    ao_uart_config_frame_1();

void    ao_uart_config_loopback_1();

void    ao_uart_error_1(                ao_uart_error_info_t const * info);

#ifndef ao_uart_loopback_disable_1

#define ao_uart_loopback_disable_1()    ao_uart_loopback_disable(ao_uart_reg_1())

#endif

#ifndef ao_uart_loopback_enable_1

#define ao_uart_loopback_enable_1()     ao_uart_loopback_enable(ao_uart_reg_1())

#endif

#ifndef ao_uart_reg_1

#define ao_uart_reg_1()                 ((ao_uart_reg_t *) (_UART1_BASE_ADDRESS))

#endif

void    ao_uart_start_1();

void    ao_uart_stop_1();

```

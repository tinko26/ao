---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The ao_sys_xc32_pic32_i2c/ao_i2c_5.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys_xc32_pic32_i2c/ao_i2c_5.h/ 
subtitle: ""
title: "ao_i2c_5.h"
toc: true
---

```c
#include <ao_i2c.h>
#include <ao_sys.h>
#include <stdbool.h>
#include <xc.h>

#ifndef AO_I2C_5

#ifdef  _I2C5

#define AO_I2C_5                        (true)

#else

#define AO_I2C_5                        (false)

#endif

#endif

#ifndef ao_i2c_ack_5

#define ao_i2c_ack_5(t)                 ao_i2c_ack(ao_i2c_reg_5(), t)

#endif

#ifndef ao_i2c_ack_from_5

#define ao_i2c_ack_from_5(t, b)         ao_i2c_ack_from(ao_i2c_reg_5(), t, b)

#endif

#ifndef ao_i2c_ack_forever_5

#define ao_i2c_ack_forever_5()          ao_i2c_ack_forever(ao_i2c_reg_5())

#endif

#ifndef ao_i2c_acked_5

#define ao_i2c_acked_5()                ao_i2c_acked(ao_i2c_reg_5())

#endif

#ifndef ao_i2c_baud_5

#define ao_i2c_baud_5(f)                ao_i2c_baud(ao_i2c_reg_5(), AO_SYS_CLOCK_I2C5, f)

#endif

#ifndef ao_i2c_nack_5

#define ao_i2c_nack_5(t)                ao_i2c_nack(ao_i2c_reg_5(), t)

#endif

#ifndef ao_i2c_nack_from_5

#define ao_i2c_nack_from_5(t, b)        ao_i2c_nack_from(ao_i2c_reg_5(), t, b)

#endif

#ifndef ao_i2c_nack_forever_5

#define ao_i2c_nack_forever_5()         ao_i2c_nack_forever(ao_i2c_reg_5())

#endif

#ifndef ao_i2c_nacked_5

#define ao_i2c_nacked_5()               ao_i2c_nacked(ao_i2c_reg_5())

#endif

#ifndef ao_i2c_recv_5

#define ao_i2c_recv_5(v, t)             ao_i2c_recv(ao_i2c_reg_5(), v, t)

#endif

#ifndef ao_i2c_recv_from_5

#define ao_i2c_recv_from_5(v, t, b)     ao_i2c_recv_from(ao_i2c_reg_5(), v, t, b)

#endif

#ifndef ao_i2c_recv_forever_5

#define ao_i2c_recv_forever_5(v)        ao_i2c_recv_forever(ao_i2c_reg_5(), v)

#endif

#ifndef ao_i2c_reg_5

#define ao_i2c_reg_5()                  ((ao_i2c_reg_t *) (_I2C5_BASE_ADDRESS))

#endif

#ifndef ao_i2c_restart_5

#define ao_i2c_restart_5(t)             ao_i2c_restart(ao_i2c_reg_5(), t)

#endif

#ifndef ao_i2c_restart_from_5

#define ao_i2c_restart_from_5(t, b)     ao_i2c_restart_from(ao_i2c_reg_5(), t, b)

#endif

#ifndef ao_i2c_restart_forever_5

#define ao_i2c_restart_forever_5()      ao_i2c_restart_forever(ao_i2c_reg_5())

#endif

#ifndef ao_i2c_send_5

#define ao_i2c_send_5(v, t)             ao_i2c_send(ao_i2c_reg_5(), v, t)

#endif

#ifndef ao_i2c_send_from_5

#define ao_i2c_send_from_5(v, t, b)     ao_i2c_send_from(ao_i2c_reg_5(), v, t, b)

#endif

#ifndef ao_i2c_send_forever_5

#define ao_i2c_send_forever_5(v)        ao_i2c_send_forever(ao_i2c_reg_5(), v)

#endif

#ifndef ao_i2c_start_5

#define ao_i2c_start_5(t)               ao_i2c_start(ao_i2c_reg_5(), t)

#endif

#ifndef ao_i2c_start_from_5

#define ao_i2c_start_from_5(t, b)       ao_i2c_start_from(ao_i2c_reg_5(), t, b)

#endif

#ifndef ao_i2c_start_forever_5

#define ao_i2c_start_forever_5()        ao_i2c_start_forever(ao_i2c_reg_5())

#endif

#ifndef ao_i2c_stop_5

#define ao_i2c_stop_5(t)                ao_i2c_stop(ao_i2c_reg_5(), t)

#endif

#ifndef ao_i2c_stop_from_5

#define ao_i2c_stop_from_5(t, b)        ao_i2c_stop_from(ao_i2c_reg_5(), t, b)

#endif

#ifndef ao_i2c_stop_forever_5

#define ao_i2c_stop_forever_5()         ao_i2c_stop_forever(ao_i2c_reg_5())

#endif

```

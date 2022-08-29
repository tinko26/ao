---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The /src/ao_sys_xc32_pic32_i2c/ao_i2c_4.h file of the ao real-time operating system."
draft: true
permalink: /src/ao_sys_xc32_pic32_i2c/ao_i2c_4.h/ 
subtitle: ""
title: "ao_i2c_4.h"
toc: true
---

# Overview

...

# Includes

```c
#include <ao_i2c.h>
#include <ao_sys.h>
#include <stdbool.h>
#include <xc.h>

#ifndef AO_I2C_4

#ifdef  _I2C4

#define AO_I2C_4                        (true)

#else

#define AO_I2C_4                        (false)

#endif

#endif

#ifndef ao_i2c_ack_4

#define ao_i2c_ack_4(t)                 ao_i2c_ack(ao_i2c_reg_4(), t)

#endif

#ifndef ao_i2c_ack_from_4

#define ao_i2c_ack_from_4(t, b)         ao_i2c_ack_from(ao_i2c_reg_4(), t, b)

#endif

#ifndef ao_i2c_ack_forever_4

#define ao_i2c_ack_forever_4()          ao_i2c_ack_forever(ao_i2c_reg_4())

#endif

#ifndef ao_i2c_acked_4

#define ao_i2c_acked_4()                ao_i2c_acked(ao_i2c_reg_4())

#endif

#ifndef ao_i2c_baud_4

#define ao_i2c_baud_4(f)                ao_i2c_baud(ao_i2c_reg_4(), AO_SYS_CLOCK_I2C4, f)

#endif

#ifndef ao_i2c_nack_4

#define ao_i2c_nack_4(t)                ao_i2c_nack(ao_i2c_reg_4(), t)

#endif

#ifndef ao_i2c_nack_from_4

#define ao_i2c_nack_from_4(t, b)        ao_i2c_nack_from(ao_i2c_reg_4(), t, b)

#endif

#ifndef ao_i2c_nack_forever_4

#define ao_i2c_nack_forever_4()         ao_i2c_nack_forever(ao_i2c_reg_4())

#endif

#ifndef ao_i2c_nacked_4

#define ao_i2c_nacked_4()               ao_i2c_nacked(ao_i2c_reg_4())

#endif

#ifndef ao_i2c_recv_4

#define ao_i2c_recv_4(v, t)             ao_i2c_recv(ao_i2c_reg_4(), v, t)

#endif

#ifndef ao_i2c_recv_from_4

#define ao_i2c_recv_from_4(v, t, b)     ao_i2c_recv_from(ao_i2c_reg_4(), v, t, b)

#endif

#ifndef ao_i2c_recv_forever_4

#define ao_i2c_recv_forever_4(v)        ao_i2c_recv_forever(ao_i2c_reg_4(), v)

#endif

#ifndef ao_i2c_reg_4

#define ao_i2c_reg_4()                  ((ao_i2c_reg_t *) (_I2C4_BASE_ADDRESS))

#endif

#ifndef ao_i2c_restart_4

#define ao_i2c_restart_4(t)             ao_i2c_restart(ao_i2c_reg_4(), t)

#endif

#ifndef ao_i2c_restart_from_4

#define ao_i2c_restart_from_4(t, b)     ao_i2c_restart_from(ao_i2c_reg_4(), t, b)

#endif

#ifndef ao_i2c_restart_forever_4

#define ao_i2c_restart_forever_4()      ao_i2c_restart_forever(ao_i2c_reg_4())

#endif

#ifndef ao_i2c_send_4

#define ao_i2c_send_4(v, t)             ao_i2c_send(ao_i2c_reg_4(), v, t)

#endif

#ifndef ao_i2c_send_from_4

#define ao_i2c_send_from_4(v, t, b)     ao_i2c_send_from(ao_i2c_reg_4(), v, t, b)

#endif

#ifndef ao_i2c_send_forever_4

#define ao_i2c_send_forever_4(v)        ao_i2c_send_forever(ao_i2c_reg_4(), v)

#endif

#ifndef ao_i2c_start_4

#define ao_i2c_start_4(t)               ao_i2c_start(ao_i2c_reg_4(), t)

#endif

#ifndef ao_i2c_start_from_4

#define ao_i2c_start_from_4(t, b)       ao_i2c_start_from(ao_i2c_reg_4(), t, b)

#endif

#ifndef ao_i2c_start_forever_4

#define ao_i2c_start_forever_4()        ao_i2c_start_forever(ao_i2c_reg_4())

#endif

#ifndef ao_i2c_stop_4

#define ao_i2c_stop_4(t)                ao_i2c_stop(ao_i2c_reg_4(), t)

#endif

#ifndef ao_i2c_stop_from_4

#define ao_i2c_stop_from_4(t, b)        ao_i2c_stop_from(ao_i2c_reg_4(), t, b)

#endif

#ifndef ao_i2c_stop_forever_4

#define ao_i2c_stop_forever_4()         ao_i2c_stop_forever(ao_i2c_reg_4())

#endif

```

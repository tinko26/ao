---
author: "Stefan Wagner"
date: 2022-08-29
description: "The ao_sys_xc32_pic32_i2c/ao_i2c_3.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys_xc32_pic32_i2c/ao_i2c_3.h/ 
subtitle: "<code>ao_sys_xc32_pic32_i2c</code>"
title: "<code>ao_i2c_3.h</code>"
toc: true
---

#ifndef AO_I2C_3

#ifdef  _I2C3

#define AO_I2C_3                        (true)

#else

#define AO_I2C_3                        (false)

#endif

#endif

#ifndef ao_i2c_ack_3

#define ao_i2c_ack_3(t)                 ao_i2c_ack(ao_i2c_reg_3(), t)

#endif

#ifndef ao_i2c_ack_from_3

#define ao_i2c_ack_from_3(t, b)         ao_i2c_ack_from(ao_i2c_reg_3(), t, b)

#endif

#ifndef ao_i2c_ack_forever_3

#define ao_i2c_ack_forever_3()          ao_i2c_ack_forever(ao_i2c_reg_3())

#endif

#ifndef ao_i2c_acked_3

#define ao_i2c_acked_3()                ao_i2c_acked(ao_i2c_reg_3())

#endif

#ifndef ao_i2c_baud_3

#define ao_i2c_baud_3(f)                ao_i2c_baud(ao_i2c_reg_3(), AO_SYS_CLOCK_I2C3, f)

#endif

#ifndef ao_i2c_nack_3

#define ao_i2c_nack_3(t)                ao_i2c_nack(ao_i2c_reg_3(), t)

#endif

#ifndef ao_i2c_nack_from_3

#define ao_i2c_nack_from_3(t, b)        ao_i2c_nack_from(ao_i2c_reg_3(), t, b)

#endif

#ifndef ao_i2c_nack_forever_3

#define ao_i2c_nack_forever_3()         ao_i2c_nack_forever(ao_i2c_reg_3())

#endif

#ifndef ao_i2c_nacked_3

#define ao_i2c_nacked_3()               ao_i2c_nacked(ao_i2c_reg_3())

#endif

#ifndef ao_i2c_recv_3

#define ao_i2c_recv_3(v, t)             ao_i2c_recv(ao_i2c_reg_3(), v, t)

#endif

#ifndef ao_i2c_recv_from_3

#define ao_i2c_recv_from_3(v, t, b)     ao_i2c_recv_from(ao_i2c_reg_3(), v, t, b)

#endif

#ifndef ao_i2c_recv_forever_3

#define ao_i2c_recv_forever_3(v)        ao_i2c_recv_forever(ao_i2c_reg_3(), v)

#endif

#ifndef ao_i2c_reg_3

#define ao_i2c_reg_3()                  ((ao_i2c_reg_t *) (_I2C3_BASE_ADDRESS))

#endif

#ifndef ao_i2c_restart_3

#define ao_i2c_restart_3(t)             ao_i2c_restart(ao_i2c_reg_3(), t)

#endif

#ifndef ao_i2c_restart_from_3

#define ao_i2c_restart_from_3(t, b)     ao_i2c_restart_from(ao_i2c_reg_3(), t, b)

#endif

#ifndef ao_i2c_restart_forever_3

#define ao_i2c_restart_forever_3()      ao_i2c_restart_forever(ao_i2c_reg_3())

#endif

#ifndef ao_i2c_send_3

#define ao_i2c_send_3(v, t)             ao_i2c_send(ao_i2c_reg_3(), v, t)

#endif

#ifndef ao_i2c_send_from_3

#define ao_i2c_send_from_3(v, t, b)     ao_i2c_send_from(ao_i2c_reg_3(), v, t, b)

#endif

#ifndef ao_i2c_send_forever_3

#define ao_i2c_send_forever_3(v)        ao_i2c_send_forever(ao_i2c_reg_3(), v)

#endif

#ifndef ao_i2c_start_3

#define ao_i2c_start_3(t)               ao_i2c_start(ao_i2c_reg_3(), t)

#endif

#ifndef ao_i2c_start_from_3

#define ao_i2c_start_from_3(t, b)       ao_i2c_start_from(ao_i2c_reg_3(), t, b)

#endif

#ifndef ao_i2c_start_forever_3

#define ao_i2c_start_forever_3()        ao_i2c_start_forever(ao_i2c_reg_3())

#endif

#ifndef ao_i2c_stop_3

#define ao_i2c_stop_3(t)                ao_i2c_stop(ao_i2c_reg_3(), t)

#endif

#ifndef ao_i2c_stop_from_3

#define ao_i2c_stop_from_3(t, b)        ao_i2c_stop_from(ao_i2c_reg_3(), t, b)

#endif

#ifndef ao_i2c_stop_forever_3

#define ao_i2c_stop_forever_3()         ao_i2c_stop_forever(ao_i2c_reg_3())

#endif


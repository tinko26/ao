---
author: "Stefan Wagner"
breadcrumbs: 2
date: 2022-08-29
description: "The ao_sys_xc32_pic32_i2c/ao_i2c_1.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys_xc32_pic32_i2c/ao_i2c_1.h/ 
subtitle: "<code>ao_sys_xc32_pic32_i2c</code>"
title: "<code>ao_i2c_1.h</code>"
toc: true
---

```c
#ifndef AO_I2C_1

#ifdef  _I2C1

#define AO_I2C_1                        (true)

#else

#define AO_I2C_1                        (false)

#endif

#endif

#ifndef ao_i2c_ack_1

#define ao_i2c_ack_1(t)                 ao_i2c_ack(ao_i2c_reg_1(), t)

#endif

#ifndef ao_i2c_ack_from_1

#define ao_i2c_ack_from_1(t, b)         ao_i2c_ack_from(ao_i2c_reg_1(), t, b)

#endif

#ifndef ao_i2c_ack_forever_1

#define ao_i2c_ack_forever_1()          ao_i2c_ack_forever(ao_i2c_reg_1())

#endif

#ifndef ao_i2c_acked_1

#define ao_i2c_acked_1()                ao_i2c_acked(ao_i2c_reg_1())

#endif

#ifndef ao_i2c_baud_1

#define ao_i2c_baud_1(f)                ao_i2c_baud(ao_i2c_reg_1(), AO_SYS_CLOCK_I2C1, f)

#endif

#ifndef ao_i2c_nack_1

#define ao_i2c_nack_1(t)                ao_i2c_nack(ao_i2c_reg_1(), t)

#endif

#ifndef ao_i2c_nack_from_1

#define ao_i2c_nack_from_1(t, b)        ao_i2c_nack_from(ao_i2c_reg_1(), t, b)

#endif

#ifndef ao_i2c_nack_forever_1

#define ao_i2c_nack_forever_1()         ao_i2c_nack_forever(ao_i2c_reg_1())

#endif

#ifndef ao_i2c_nacked_1

#define ao_i2c_nacked_1()               ao_i2c_nacked(ao_i2c_reg_1())

#endif

#ifndef ao_i2c_recv_1

#define ao_i2c_recv_1(v, t)             ao_i2c_recv(ao_i2c_reg_1(), v, t)

#endif

#ifndef ao_i2c_recv_from_1

#define ao_i2c_recv_from_1(v, t, b)     ao_i2c_recv_from(ao_i2c_reg_1(), v, t, b)

#endif

#ifndef ao_i2c_recv_forever_1

#define ao_i2c_recv_forever_1(v)        ao_i2c_recv_forever(ao_i2c_reg_1(), v)

#endif

#ifndef ao_i2c_reg_1

#define ao_i2c_reg_1()                  ((ao_i2c_reg_t *) (_I2C1_BASE_ADDRESS))

#endif

#ifndef ao_i2c_restart_1

#define ao_i2c_restart_1(t)             ao_i2c_restart(ao_i2c_reg_1(), t)

#endif

#ifndef ao_i2c_restart_from_1

#define ao_i2c_restart_from_1(t, b)     ao_i2c_restart_from(ao_i2c_reg_1(), t, b)

#endif

#ifndef ao_i2c_restart_forever_1

#define ao_i2c_restart_forever_1()      ao_i2c_restart_forever(ao_i2c_reg_1())

#endif

#ifndef ao_i2c_send_1

#define ao_i2c_send_1(v, t)             ao_i2c_send(ao_i2c_reg_1(), v, t)

#endif

#ifndef ao_i2c_send_from_1

#define ao_i2c_send_from_1(v, t, b)     ao_i2c_send_from(ao_i2c_reg_1(), v, t, b)

#endif

#ifndef ao_i2c_send_forever_1

#define ao_i2c_send_forever_1(v)        ao_i2c_send_forever(ao_i2c_reg_1(), v)

#endif

#ifndef ao_i2c_start_1

#define ao_i2c_start_1(t)               ao_i2c_start(ao_i2c_reg_1(), t)

#endif

#ifndef ao_i2c_start_from_1

#define ao_i2c_start_from_1(t, b)       ao_i2c_start_from(ao_i2c_reg_1(), t, b)

#endif

#ifndef ao_i2c_start_forever_1

#define ao_i2c_start_forever_1()        ao_i2c_start_forever(ao_i2c_reg_1())

#endif

#ifndef ao_i2c_stop_1

#define ao_i2c_stop_1(t)                ao_i2c_stop(ao_i2c_reg_1(), t)

#endif

#ifndef ao_i2c_stop_from_1

#define ao_i2c_stop_from_1(t, b)        ao_i2c_stop_from(ao_i2c_reg_1(), t, b)

#endif

#ifndef ao_i2c_stop_forever_1

#define ao_i2c_stop_forever_1()         ao_i2c_stop_forever(ao_i2c_reg_1())

#endif

```

---
author: "Stefan Wagner"
breadcrumbs: 2
date: 2022-08-29
description: "The ao_sys_xc32_pic32/ao_ir_alarm.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys_xc32_pic32/ao_ir_alarm.h/ 
subtitle: "<code>ao_sys_xc32_pic32</code>"
title: "<code>ao_ir_alarm.h</code>"
toc: true
---

```c
void    ao_alarm();

#ifndef ao_alarm_disable

#define ao_alarm_disable()  ao_ir_ct_disable()

#endif

#ifndef ao_alarm_enable

#define ao_alarm_enable()   ao_ir_ct_enable()

#endif

#ifndef ao_alarm_reply

#define ao_alarm_reply()    ao_ir_ct_reply()

#endif

#ifndef ao_alarm_request

#define ao_alarm_request()  ao_ir_ct_request()

#endif

#ifndef ao_alarm_set

#define ao_alarm_set(t)     _CP0_SET_COMPARE(t)

#endif

```

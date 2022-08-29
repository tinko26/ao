---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The /src/ao_sys_xc32_pic32/ao_ir_alarm.h file of the ao real-time operating system."
draft: true
permalink: /src/ao_sys_xc32_pic32/ao_ir_alarm.h/ 
subtitle: ""
title: "ao_ir_alarm.h"
toc: true
---

# Overview

...

# Includes

```c
#include <ao_ir_ct.h>
#include <xc.h>

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

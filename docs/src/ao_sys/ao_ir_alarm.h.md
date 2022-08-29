---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The /src/ao_sys/ao_ir_alarm.h file of the ao real-time operating system."
draft: true
permalink: /src/ao_sys/ao_ir_alarm.h/ 
subtitle: ""
title: "ao_ir_alarm.h"
toc: true
---

# Overview

...

# Includes

```c
#include <ao_time.h>

void    ao_alarm();

void    ao_alarm_disable();

void    ao_alarm_enable();

void    ao_alarm_reply();

void    ao_alarm_request();

void    ao_alarm_set(ao_time_t t);

```

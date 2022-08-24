---
author: "Stefan Wagner"
date: 2022-08-14
description: "The ao_ir_alarm.h module of the ao real-time operating system."
draft: false
permalink: /modules/ir-alarm/
title: "ao_ir_alarm.h"
---

# Overview

This module declares functions for controlling the alarm interrupt as well as a callback function for the interrupt handler. This module is abstract, that is, an implementation must be provided by a port package in order to support [alarms](../alarms.md).

## Functions

Enable or disable the interrupt, respectively.

```c
void ao_alarm_enable();
void ao_alarm_disable();
```

Request an interrupt or reply thereto, respectively.

```c
void ao_alarm_request();
void ao_alarm_reply();
```

Set the [time](time.md) for the next interrupt.

```c
void ao_alarm_set(ao_time_t t);
```

## Callback

Callback for the interrupt handler. Actually, this function is implemented by the [`ao_alarm.h`](alarm.md) module.

```c
void ao_alarm();
```

## Porting

The port must implement an interrupt handler, which in turn must execute the callback function. 

On start-up, the alarm interrupt must be disabled.

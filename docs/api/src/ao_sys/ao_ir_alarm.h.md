---
author: "Stefan Wagner"
date: 2022-08-31
draft: true
permalink: /api/src/ao_sys/ao_ir_alarm.h/
toc: true
---

# Overview

This module declares functions for controlling the alarm interrupt as well as a callback function for the interrupt handler. This module is abstract, that is, an implementation must be provided by a port package in order to support alarms.

# Include

```c
#include <ao_time.h>
```

# Functions

Callback for the interrupt handler. Actually, this function is implemented by the [`ao_alarm.h`](ao_alarm.h.md) module.

```c
void ao_alarm();
```

Enable or disable the interrupt.

```c
void ao_alarm_enable();
void ao_alarm_disable();
```

Request the interrupt or reply thereto.

```c
void ao_alarm_request();
void ao_alarm_reply();
```

Set the time for the next interrupt.

```c
void ao_alarm_set(ao_time_t t);
```

# Porting

The port must implement an interrupt handler, which in turn must execute the callback function.

On start-up, the alarm interrupt must be disabled.

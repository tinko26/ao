---
author: "Stefan Wagner"
date: 2022-08-11
description: ""
draft: false
permalink: /kernel/count/
title: "Hardware Counter"
---

# Hardware Counter

The `ao_count.h` module encapsulates a hardware counter that increments continuously at a constant rate. The counter makes up the basis for measuring time. Additionally, this counter and a corresponding [interrupt](ir-alarm.md) make up the basis for [alarms](alarm.md).

The module defines the `ao_count_t` type, which is an unsigned integer that can hold a value of the hardware counter. Additionally, it defines the following constants.

The minimum and maximum value, respectively.

```c
#define AO_COUNT_MIN
#define AO_COUNT_MAX
```

The frequency, in Hertz, at which the counter is incremented.

```c
#define AO_COUNT_FREQUENCY
```

Finally, the module contains a function that returns the current value of the hardware counter.

```c
ao_count_t ao_count();
```
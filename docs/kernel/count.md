---
author: "Stefan Wagner"
date: 2022-08-08
description: "The Hardware Counter of the ao Real-Time Operating System (RTOS)."
draft: true
permalink: /kernel/count/
title: "Hardware Counter"
---

# Hardware Counter

The `ao_count.h` module encapsulates a hardware counter that increments continuously at a constant rate. The counter makes up the basis for measuring time. Additionally, this counter and a corresponding interrupt make up the basis for alarms.

The module defines the `ao_count_t`, which is an unsigned integer that can hold a value of the hardware counter. Additionally, it the defines the following constants.

The minimum and maximum value, respectively.

```c
#define AO_COUNT_MIN
#define AO_COUNT_MAX
```

The frequency, in Hertz, at which the is incremented.

```c
#define AO_COUNT_FREQUENCY
```

Additionally, the module contains a function that returns the current value of the hardware counter.

```c
ao_count_t ao_count();
```

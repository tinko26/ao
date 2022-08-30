---
author: "Stefan Wagner"
date: 2022-08-11
description: "The ao_spin.h module of the ao real-time operating system."
draft: false
permalink: /modules/spin/
title: "<code>ao_spin.h</code>"
toc: true
---

# Overview

This module defines functions for spinning or busy waiting, respectively, that can be used to generate time delays.  In the simplest form, a thread of execution can spin for a specified time span.

```c
ao_spin(AO_MILLISECONDS(500));
```

The starting point is determined by the function at its beginning. Since the execution of a function can be delayed, for example by an interrupt, this could be inaccurate. Therefore, the starting point can be specified explicitly. Especially, this is useful in loops.

```c
ao_time_t beginning = ao_now();
ao_time_t period = AO_MILLISECONDS(500);

while (1)
{
    ao_spin_from(period, beginning);
    // Toggle pin.
    beginning += period;
}
```

When specifying an infinite timeout, the spinning functions never return. However, there is a special overload for this purpose.

```c
void ao_spin_forever();
```

## External Links

[https://en.wikipedia.org/wiki/Busy_waiting](https://en.wikipedia.org/wiki/Busy_waiting)
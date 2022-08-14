---
author: "Stefan Wagner"
date: 2022-08-11
description: ""
draft: false
permalink: /kernel/spin/
title: "Spinning"
---

# Spinning

The `ao_spin.h` module defines functions for spinning or busy waiting, respectively, that can be used to generate time delays.  In the simplest form, a thread of execution can spin for a specified time span.

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

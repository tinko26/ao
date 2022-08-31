---
api: true
author: "Stefan Wagner"
date: 2022-08-31
description: "The /src/ao_sys/ao_spin.h file of the ao real-time operating system."
draft: true
permalink: /api/src/ao_sys/ao_spin.h/
subtitle: "Spinning"
title: "ao_spin.h"
toc: true
wiki:
- title: "Busy waiting"
  url: https://en.wikipedia.org/wiki/Busy_waiting
---

# Overview

This module defines functions for spinning or busy waiting, respectively, that can be used to generate time delays. 

# Include

```c
#include <ao_time.h>
```

# Functions

```c
void ao_spin(ao_time_t timeout);
```

```c
void ao_spin_from(ao_time_t timeout, ao_time_t beginning);
```

```c
void ao_spin_forever();
```

# Usage

In the simplest form, a thread of execution can spin for a specified time span.

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

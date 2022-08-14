---
author: "Stefan Wagner"
date: 2022-08-14
description: "The ao_assert.h module of the ao real-time operating system."
draft: true
permalink: /modules/assert/
title: "ao_assert.h"
---

# ao_assert.h

This module defines a single macro function that performs a runtime [assertion](https://en.wikipedia.org/wiki/Assertion_(software_development)) on a given expression. If the expression compares equal to zero, then the assertion fails. 

```c
#define ao_assert(exp)
```

Although the standard library contains a similar macro function, it is not available in a freestanding runtime environment. Also, the actions taken by that macro function upon failure are not part of a freestanding runtime environment, namely printing a diagnostic message and terminating the program. 

Especially, outputting a message is probably not a good option in an embedded system, because it requires specific hardware, such as a serial port, which might not be available, and it consumes quite an amount of resources. Therefore, the default implementation simply executes a [breakpoint](break.md) upon failure.

```c
#define ao_assert(exp)  \
{                       \
    if (!(exp))         \
    {                   \
        ao_break();     \
    }                   \
}
```

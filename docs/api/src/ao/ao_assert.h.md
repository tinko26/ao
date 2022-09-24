---
author: "Stefan Wagner"
date: 2022-09-24
draft: true
external:
- https://en.wikipedia.org/wiki/Assertion_(software_development) : "Assertion"
permalink: /api/src/ao/ao_assert.h/
seealso:
- /api/src/ao/ao_break.h/
toc: true
---

# Notes

This module defines a single macro function that performs a runtime assertion on a given expression.

Although the standard library contains a similar macro function, it is not available in a freestanding runtime environment. Also, the actions taken by that macro function upon failure are not part of a freestanding runtime environment, namely printing a diagnostic message and terminating the program.

Especially, outputting a message is probably not a good option in an embedded system, because it requires specific hardware, such as a serial port, which might not be available, and it consumes quite an amount of resources. Therefore, the default implementation simply executes a breakpoint upon failure.

# Include

[`ao_break.h`](ao_break.h.md)

# Identifier

```c
#define AO_ASSERT
```

# Functions

## `ao_assert`

```c
#define ao_assert(exp) \
{                      \
    if (!(exp))        \
    {                  \
        ao_break();    \
    }                  \
}
```

Performs a runtime assertion on the given expression. If the expression compares equal to zero, then the assertion fails.

---
author: "Stefan Wagner"
date: 2022-10-10
draft: true
external:
- https://en.wikipedia.org/wiki/Assertion_(software_development) : "Assertion"
permalink: /api/src/ao/ao_assert.h/
toc: true
---

# Notes

This module defines two macro functions that perform a runtime or static assertion, respectively, on a given expression.

## Runtime assertions

Although the standard library contains a macro function for runtime assertions, it is not available in a freestanding runtime environment, because the `assert.h` header file is available in a hosted runtime environment, only. Also, the actions taken by that macro function upon failure are not part of a freestanding runtime environment, namely printing a diagnostic message and terminating the program.

Especially, outputting a message is probably not a good option in an embedded system, because it requires specific hardware, such as a serial port, which might not be available, and it consumes quite an amount of resources. Therefore, the default implementation simply executes a breakpoint upon failure.

## Static assertions

...

# Include

| [`ao_break.h`](ao_break.h.md) |

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

## `ao_static_assert`

```c
#define ao_static_assert(exp, msg) _Static_assert(exp, msg)
```

Performs a compile-time assertion on the given expression. If the expression compares equal to zero, then the assertion fails. In that case, the compiler outputs the specified diagnostic message.

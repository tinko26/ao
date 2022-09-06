---
author: "Stefan Wagner"
date: 2022-08-31
draft: true
external:
- https://docs.microsoft.com/en-us/dotnet/api/system.threading.autoresetevent : "AutoResetEvent"
permalink: /api/src/ao_sys/ao_are.h/
toc: true
---

# Overview

...

microsoft: "Represents a thread synchronization event that, when signaled, resets automatically after releasing a single waiting thread."

...

# Include

```c
#include <ao_async.h>
#include <ao_list.h>
#include <ao_time.h>
#include <stdbool.h>
```

# Typedefs

```c
typedef struct ao_are_t      ao_are_t;
```

```c
typedef struct ao_are_wait_t ao_are_wait_t;
```

# Types

## `ao_are_t`

This type represents an auto-reset event.

```c
struct ao_are_t
{
ao_list_t list;
bool      state;
};
```

It consists of the following members.

| `list` | |
| `state` | |

## `ao_are_wait_t`

This type represents the waiting for an auto-reset event.

```c
struct ao_are_wait_t
{
ao_are_t * are;
ao_async_t async;
ao_list_node_t node;
bool volatile result;
};
```

It consists of the following members.

| `are` | |
| `async` | |
| `node` | |
| `result` | |

# Functions

Clear an auto-reset event, i.e. set its state to `false`. This function can be called from both task and interrupt context.

```c
void ao_are_clear(ao_are_t * x);
```

Set an auto-reset event, i.e. set its state to `true`. Eventually, this wakes up the first waiting task. This function can be called from both task and interrupt context.

```c
void ao_are_set(ao_are_t * x);
```

Wait for an auto-reset event with a timeout and optional beginning.

```c
bool ao_are_wait(     ao_are_t * x, ao_time_t timeout);
bool ao_are_wait_from(ao_are_t * x, ao_time_t timeout, ao_time_t beginning);
```

Wait for an auto-reset event indefinitely.

```c
bool ao_are_wait_forever(ao_are_t * x);
```

Wait for an auto-reset event in a non-blocking fashion.

```c
bool ao_are_wait_try(ao_are_t * x);
```

Begin or end the waiting for an auto-reset event, respectively.

```c
void ao_are_wait_begin(ao_are_wait_t * x);
void ao_are_wait_end(  ao_are_wait_t * x);
```

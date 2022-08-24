---
author: "Stefan Wagner"
date: 2022-08-16
description: "The ao_are.h module of the ao real-time operating system."
draft: true
permalink: /modules/are/
title: "ao_are.h"
---

# Overview

...

microsoft: "Represents a thread synchronization event that, when signaled, resets automatically after releasing a single waiting thread."

...

## Types

### Auto-Reset Event

The `ao_are_t` type represents an auto-reset event.

```c
struct ao_are_t
{
    ao_list_t list;
    bool      state;
};
```

It consists of the following members.

| Member | |
|--------|-|
| `list` | ... |
| `state` | ... |

### Auto-Reset Event Waiting

The `ao_are_wait_t` type represents the waiting for an auto-reset event.

```c
struct ao_are_wait_t
{
    ao_are_t *     are;
    ao_async_t     async;
    ao_list_node_t node;
    bool volatile  result;
};
```

It consists of the following members.

| Member | |
|--------|-|
| `are` | ... |
| `async` | ... |
| `node` | ... |
| `result` | ... |

## Functions

Clearing an auto-reset event sets its state to `false`.

```c
ao_are_t * a;
```

```c
ao_are_clear(a);
```

In contrast, setting an auto-reset event sets its state to `true`. Eventually, it wakes up the first waiting task.

```c
ao_are_set(a);
```

Both clearing and setting an auto-reset event can be called from both task and interrupt context. However, the waiting functions must be called by a task.

```c
bool r;
```

```c
r = ao_are_wait(a, AO_MILLISECONDS(500));

if (r)
{
    // Auto-reset event has been set and this task has been woken up.
}
```

## External Links

[https://docs.microsoft.com/en-us/dotnet/api/system.threading.autoresetevent](https://docs.microsoft.com/en-us/dotnet/api/system.threading.autoresetevent)

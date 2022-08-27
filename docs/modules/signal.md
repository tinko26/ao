---
author: "Stefan Wagner"
date: 2022-08-17
description: "The ao_signal.h module of the ao real-time operating system."
draft: true
permalink: /modules/signal/
title: "<code>ao_signal.h"
---

# Overview

...

## Types

### Signal

The `ao_signal_t` type represents a signal.

```c
struct ao_signal_t
{
    ao_list_t list;
};
```

It consists of the following members.

| Member | |
|--------|-|
| `list` | The list of waiting tasks. |

### Signal Waiting

The `ao_signal_wait_t` type represents the waiting for a signal.

```c
struct ao_signal_wait_t
{
    ao_async_t     async;
    ao_list_node_t node;
    bool volatile  result;
    ao_signal_t *  signal;
};
```

It consists of the following members.

| Member | |
|--------|-|
| `async` | The asynchronous event. |
| `node` | The node for the signal's waiting list. |
| `result` | Indicates whether the waiting task has been notified. |
| `signal` | The signal. |

## Functions

### Waiting

...

### Notifying

...

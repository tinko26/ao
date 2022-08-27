---
author: "Stefan Wagner"
date: 2022-08-16
description: "The ao_monitor.h module of the ao real-time operating system."
draft: true
permalink: /modules/monitor/
title: "<code>ao_monitor.h</code>"
---

# Overview

...

## Example

...

Producer-consumer problem

...

## Types

### Monitor

The `ao_monitor_t` type represents a monitor.

```c
struct ao_monitor_t
{
    ao_list_t    list;
    ao_mutex_t * mutex;
};
```

It consists of the following members.

| Member | |
|--------|-|
| `list` | ... |
| `mutex` | ... |

### Monitor Entering

The `ao_monitor_enter_t` type represents the entering of a monitor.

```c
struct ao_monitor_enter_t
{
    ao_async_t      async;
    ao_monitor_t *  monitor;
    ao_mutex_lock_t mutex_lock;
    bool volatile   result;
};
```

It consists of the following members.

| Member | |
|--------|-|
| `async` | ... |
| `monitor` | ... |
| `mutex_lock` | ... |
| `result` | ... |

### Monitor Waiting

The `ao_monitor_wait_t` type represents the waiting for a monitor.

```c
struct ao_monitor_wait_t
{
    ao_async_t          async;
    ao_monitor_t *      monitor;
    union
    {
        ao_mutex_lock_t mutex_lock;
        ao_list_node_t  node;
    };
    bool volatile       result;
    bool volatile       waiting;
};
```

It consists of the following members.

| Member | |
|--------|-|
| `async` | ... |
| `monitor` | ... |
| `mutex_lock` | ... |
| `node` | ... |
| `result` | ... |
| `waiting` | ... |

## Functions

### Entering and Exiting

...

### Notifying

...

### Waiting

...

## External Links

[https://en.wikipedia.org/wiki/Monitor_(synchronization)](https://en.wikipedia.org/wiki/Monitor_(synchronization))

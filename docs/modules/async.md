---
author: "Stefan Wagner"
date: 2022-08-16
description: "The ao_async.h module of the ao real-time operating system."
draft: true
permalink: /modules/async/
title: "ao_async.h"
---

# Overview

...

## Types

### Asynchronous Event

The `ao_async_t` type represents an asynchronous event.

```c
struct ao_async_t
{
    ao_proc_t     callback;
    void *        callback_parameter;
    bool volatile checked;
};
```

It consists of the following members.

| Member | |
|--------|-|
| `callback` | The callback. |
| `callback_parameter` | The callback parameter. |
| `checked` | Indicates whether the asynchronous event has happened. |

### Waiting for All Asynchronous Events

The `ao_async_all_t` type represents the waiting for all out of a collection of asynchronous events.

```c
struct ao_async_all_t
{
    ao_async_t      async;
    size_t          count;
    size_t volatile count_checked;
    bool   volatile result;
    ao_async_t **   store;
};
```

It consists of the following members.

| Member | |
|--------|-|
| `async` | ... |
| `count` | ... |
| `count_checked` | ... |
| `result` | ... |
| `store` | ... |

### Waiting for Any Asynchronous Event

The `ao_async_any_t` type represents the waiting for one out of a collection of asynchronous events.

```c
struct ao_async_any_t
{
    ao_async_t    async;
    size_t        count;
    bool volatile result;
    ao_async_t ** store;
};
```

It consists of the following members.

| Member | |
|--------|-|
| `async` | ... |
| `count` | ... |
| `result` | ... |
| `store` | ... |

## Functions

### Waiting for All Asynchronous Events

...

### Waiting for Any Asynchronous Event

...

---
author: "Stefan Wagner"
date: 2022-09-27
draft: true
permalink: /api/src/ao_sys/ao_await.h/
toc: true
---

# Notes

This module defines functions for awaiting asynchronous events.

# Include

| [`ao_async.h`](ao_async.h.md) |
| [`ao_time.h`](ao_time.h.md) |

# Functions

## `ao_await`
## `ao_await_from`

```c
void ao_await     (ao_async_t * async, ao_time_t timeout);
void ao_await_from(ao_async_t * async, ao_time_t timeout, ao_time_t beginning);
```

Awaits an asynchronous event in a blocking fashion with a timeout and optional beginning.

## `ao_await_forever`

```c
void ao_await_forever(ao_async_t * async);
```

Awaits an asynchronous event indefinitely in a blocking fashion.

## `ao_await_all`
## `ao_await_all_from`

```c
void ao_await_all     (ao_async_all_t * async_all, ao_time_t timeout);
void ao_await_all_from(ao_async_all_t * async_all, ao_time_t timeout, ao_time_t beginning);
```

Awaits all out of a set of asynchronous events in a blocking fashion with a timeout and optional beginning.

## `ao_await_all_forever`

```c
void ao_await_all_forever(ao_async_all_t * async_all);
```

Awaits all out of a set of asynchronous events indefinitely in a blocking fashion.

## `ao_await_any`
## `ao_await_any_from`

```c
void ao_await_any     (ao_async_any_t * async_any, ao_time_t timeout);
void ao_await_any_from(ao_async_any_t * async_any, ao_time_t timeout, ao_time_t beginning);
```

Awaits any one out of a set of asynchronous events in a blocking fashion with a timeout and optional beginning.

## `ao_await_any_forever`

```c
void ao_await_any_forever(ao_async_any_t * async_any);
```

Awaits any one out of a set of asynchronous events indefinitely in a blocking fashion.

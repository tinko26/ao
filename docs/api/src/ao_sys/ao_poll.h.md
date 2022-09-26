---
author: "Stefan Wagner"
date: 2022-09-13
draft: true
permalink: /api/src/ao_sys/ao_poll.h/
toc: true
---

# Include

| [`ao_async.h`](ao_async.h.md) |
| [`ao_time.h`](ao_time.h.md) |

# Identifier

```c
#define AO_POLL
```

# Functions

## `ao_poll`
## `ao_poll_from`

```c
void ao_poll     (ao_async_t const * async, ao_time_t timeout);
void ao_poll_from(ao_async_t const * async, ao_time_t timeout, ao_time_t beginning);
```

Polls an asynchronous event with a timeout and an optional beginning.

## `ao_poll_forever`

```c
void ao_poll_forever(ao_async_t const * async);
```

Polls an asynchronous event indefinitely.

## `ao_poll_all`
## `ao_poll_all_from`

```c
void ao_poll_all     (ao_async_all_t * async_all, ao_time_t timeout);
void ao_poll_all_from(ao_async_all_t * async_all, ao_time_t timeout, ao_time_t beginning);
```

Polls all out of a set of asynchronous events with a timeout and an optional beginning.

## `ao_poll_all_forever`

```c
void ao_poll_all_forever(ao_async_all_t * async_all);
```

Polls all out of a set of asynchronous events indefinitely.

## `ao_poll_any`
## `ao_poll_any_from`

```c
void ao_poll_any     (ao_async_any_t * async_any, ao_time_t timeout);
void ao_poll_any_from(ao_async_any_t * async_any, ao_time_t timeout, ao_time_t beginning);
```

Polls any one out of a set of asynchronous events with a timeout and an optional beginning.

## `ao_poll_any_forever`

```c
void ao_poll_any_forever(ao_async_any_t * async_any);
```

Polls any one out of a set of asynchronous events indefinitely.

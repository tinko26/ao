---
author: "Stefan Wagner"
date: 2022-09-26
draft: true
permalink: /api/src/ao_sys/ao_send.h/
toc: true
---

# Notes

This module provides an abstraction for sending to an opaque destination.

# Include

| [`ao_async.h`](ao_async.h.md) |
| [`ao_func.h`](../ao/ao_func.h.md) |
| [`ao_time.h`](ao_time.h.md) |
| `stdbool.h` |
| `stddef.h` |

# Types

## `ao_send_t`

```c
typedef struct ao_send_t ao_send_t;
```

Represents the sending of data.

## `ao_send_proc_t`

```c
typedef void (* ao_send_proc_t)
(
    ao_send_t * send
);
```

Represents a function beginning or ending a sending.

# Struct

## `ao_send_t`

```c
struct ao_send_t
{
    ao_async_t      async;
    ao_send_proc_t  begin;
    size_t volatile count;
    size_t          count_max;
    size_t          count_min;
    ao_send_proc_t  end;
    void *          parameter;
    void *          ptr;
    bool   volatile result;
};
```

| `async` | The asynchronous event. |
| `begin` | The function beginning the sending. |
| `count` | The number of sent bytes. |
| `count_max` | The maximum number of bytes to send. |
| `count_min` | The minimum number of bytes to send. |
| `end` | The function ending the sending. |
| `parameter` | An additional parameter. |
| `ptr` | Points to the data to send. |
| `result` | The result. |

# Functions

## `ao_send`
## `ao_send_from`

```c
void ao_send     (ao_send_t * s, ao_time_t timeout);
void ao_send_from(ao_send_t * s, ao_time_t timeout, ao_time_t beginning);
```

Sends in a blocking fashion with a timeout and an optional beginning.

## `ao_send_forever`

```c
void ao_send_forever(ao_send_t * s);
```

Sends indefinitely in a blocking fashion.

## `ao_send_try`

```c
void ao_send_try(ao_send_t * s);
```

Sends in a non-blocking fashion.

## `ao_send_begin`
## `ao_send_end`

```c
void ao_send_begin(ao_send_t * s);
void ao_send_end  (ao_send_t * s);
```

Begins or ends, respectively, a sending.

---
author: "Stefan Wagner"
date: 2022-08-31
draft: true
permalink: /api/src/ao_sys/ao_send.h/
toc: true
---

# Include

```c
#include <ao_async.h>
#include <ao_func.h>
#include <ao_time.h>
#include <stdbool.h>
#include <stddef.h>
```

# Typedefs

```c
typedef struct ao_send_t ao_send_t;
```

```c
typedef void (* ao_send_proc_t)
(
    ao_send_t * x
);
```

# Types

## `ao_send_t`

This type represents the sending of data.

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

It consists of the following members.

| `async` | The asynchronous event. |
| `begin` | The function beginning the sending. |
| `count` | The number of sent bytes. |
| `count_max` | The maximum number of bytes to send. |
| `count_min` | The minimum number of bytes to send. |
| `end` | The function ending the sending. |
| `parameter` | An additional parameter. |
| `ptr` | Points to the data to send. |
| `result` | Indicates whether the data has been sent. |

## `ao_send_proc_t`

This type represents a function beginning or ending a sending.

# Functions

## `ao_send`
## `ao_send_from`

```c
void ao_send(     ao_send_t * x, ao_time_t timeout);
void ao_send_from(ao_send_t * x, ao_time_t timeout, ao_time_t beginning);
```

## `ao_send_forever`

```c
void ao_send_forever(ao_send_t * x);
```

## `ao_send_try`

```c
void ao_send_try(ao_send_t * x);
```

## `ao_send_begin`
## `ao_send_end`

```c
void ao_send_begin(ao_send_t * x);
void ao_send_end(  ao_send_t * x);
```

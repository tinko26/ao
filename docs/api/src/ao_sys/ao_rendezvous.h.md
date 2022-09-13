---
author: "Stefan Wagner"
date: 2022-09-13
draft: true
external:
- https://en.wikipedia.org/wiki/Rendezvous_(Plan_9) : "Rendezvous"
permalink: /api/src/ao_sys/ao_rendezvous.h/
toc: true
---

# Notes

This module defines execution barriers, where two tasks can synchronize and exchange data.

# Include

```c
#include <ao_async.h>
#include <ao_time.h>
#include <stdbool.h>
```

# Identifier

```c
#define AO_RENDEZVOUS
```

# Types

## `ao_rendezvous_t`

```c
typedef struct ao_rendezvous_t ao_rendezvous_t;
```

```c
struct ao_rendezvous_t
{
    ao_rendezvous_wait_t * wait;
};
```

This type represents a rendezvous. It consists of the following members.

| `wait` | The waiting. |

## `ao_rendezvous_wait_t`

```c
typedef struct ao_rendezvous_wait_t ao_rendezvous_wait_t;
```

```c
struct ao_rendezvous_wait_t
{
    ao_async_t               async;
    ao_rendezvous_exchange_t exchange;
    void *                   exchange_parameter;
    void *                   ptr_in;
    void *                   ptr_out;
    ao_rendezvous_t *        rendezvous;
    bool volatile            result;
};
```

This type represents the waiting for a rendezvous. It consists of the following members.

| `async` | The asynchronous event. |
| `exchange` | The exchange function. |
| `exchange_parameter` | The exchange function parameter. |
| `ptr_in` | Points to data to receive from the other task. |
| `ptr_out` | Points to data to send to the other task. |
| `rendezvous` | The rendezvous. |
| `result` | The result.  |

## `ao_rendezvous_exchange_t`

```c
typedef void (* ao_rendezvous_exchange_t)
(
    void * ptr_in_other,
    void * ptr_out_self,
    void * parameter
);
```

This type represents the exchanging of data at a rendezvous. It takes three parameters. First, a pointer to data provided by the other task. Second, a pointer to a location to store that data (or anything else). Third, an additional parameter that can be used to tweak the exchanging.

# Functions

## `ao_rendezvous`
## `ao_rendezvous_from`

```c
void ao_rendezvous     (ao_rendezvous_wait_t * x, ao_time_t timeout);
void ao_rendezvous_from(ao_rendezvous_wait_t * x, ao_time_t timeout, ao_time_t beginning);
```

Waits for a rendezvous in a blocking fashion with a timeout and an optional beginning.

## `ao_rendezvous_forever`

```c
void ao_rendezvous_forever(ao_rendezvous_wait_t * x);
```

Waits for a rendezvous indefinitely in a blocking fashion.

## `ao_rendezvous_try`

```c
void ao_rendezvous_try(ao_rendezvous_wait_t * x);
```

Waits for a rendezvous in a non-blocking fashion.

## `ao_rendezvous_begin`
## `ao_rendezvous_end`

```c
void ao_rendezvous_begin(ao_rendezvous_wait_t * x);
void ao_rendezvous_end  (ao_rendezvous_wait_t * x);
```

Begins or ends, respectively, a waiting for a rendezvous.

---
author: "Stefan Wagner"
date: 2022-08-16
description: "The ao_rendezvous.h module of the ao real-time operating system."
draft: true
permalink: /modules/rendezvous/
title: "<code>ao_rendezvous.h"
---

# Overview

...

## Types

### Rendezvous

The `ao_rendezvous_t` type represents a rendezvous.

```c
struct ao_rendezvous_t
{
    ao_rendezvous_wait_t * wait;
};
```

It consists of the following member.

| Member | |
|--------|-|
| `wait` | The waiting task. The value is `NULL`, if no task is waiting. |

### Rendezvous Waiting

The `ao_rendezvous_wait_t` type represents the waiting for a rendezvous.

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

It consists of the following members.

| Member | |
|--------|-|
| `async` | The asynchronous event. |
| `exchange` | The exchange function. |
| `exchange_parameter` | The exchange function parameter. |
| `ptr_in` | Points to data to receive from the other task. |
| `ptr_out` | Points to data to send to the other task. |
| `rendezvous` | The rendezvous. |
| `result` | Indicates whether a rendezvous has happened.  |

### Rendezvous Exchanging

The `ao_rendezvous_exchange_t` type represents the exchanging of data at a rendezvous. It takes three parameters. First, a pointer to data provided by the other task. Second, a pointer to a location to store that data (or anything else). Third, an additional parameter that can be used to tweak the exchanging.

```c
typedef void (* ao_rendezvous_exchange_t)
(
    void * ptr_in_other,
    void * ptr_out_self,
    void * parameter
);
```

## Functions

...

Set up the exchange function. Assume tasks are exchanging doubles.

```c
void exchange(void * pin, void * pout, void * parameter)
{
    double * din = pin;
    double * dout = pout;

    *dout = *din;
}
```

Set up the waiting.

```c
double din;
double dout = 3.14159;
ao_rendezvous_t * r
ao_rendezvous_wait_t * w;
```

```c
w->exchange = exchange;
w->ptr_in = &din;
w->ptr_out = &dout;
w->rendezvous = r;
```

```c
ao_rendezvous(w, AO_MILLISECONDS(500));

if (w->result)
{
    // A rendezvous has happened.

    if (din > dout)
    {
        // Other task has sent a greater value.
    }
}
```

...

## External Links

[https://en.wikipedia.org/wiki/Rendezvous_(Plan_9)](https://en.wikipedia.org/wiki/Rendezvous_(Plan_9))

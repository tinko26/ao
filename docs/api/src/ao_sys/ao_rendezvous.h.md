---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The /src/ao_sys/ao_rendezvous.h file of the ao real-time operating system."
draft: true
permalink: /api/src/ao_sys/ao_rendezvous.h/
subtitle: ""
title: "ao_rendezvous.h"
toc: true
---

# Include

```c
#include <ao_async.h>
#include <ao_time.h>
#include <stdbool.h>
```

# Typedefs

```c
typedef struct ao_rendezvous_t ao_rendezvous_t;
```

```c
typedef struct ao_rendezvous_wait_t ao_rendezvous_wait_t;
```

```c
typedef void (* ao_rendezvous_exchange_t)
(
void * ptr_in_other,
void * ptr_out_self,
void * parameter
);
```

# Types

## `ao_rendezvous_t`

```c
struct ao_rendezvous_t
{
    ao_rendezvous_wait_t * wait;
};
```

Members:

| `wait` | |

## `ao_rendezvous_wait_t`

```c
struct ao_rendezvous_wait_t
{
    ao_async_t async;
    ao_rendezvous_exchange_t exchange;
    void * exchange_parameter;
    void * ptr_in;
    void * ptr_out;
    ao_rendezvous_t * rendezvous;
    bool volatile result;
};
```

Members:

| `async` | |
| `exchange` | |
| `exchange_parameter` | |
| `ptr_in` | |
| `ptr_out` | |
| `rendezvous` | |
| `result` | |

# Functions

```c
void ao_rendezvous( ao_rendezvous_wait_t * x, ao_time_t timeout);
```

```c
void ao_rendezvous_from( ao_rendezvous_wait_t * x, ao_time_t timeout, ao_time_t beginning);
```

```c
void ao_rendezvous_forever( ao_rendezvous_wait_t * x);
```

```c
void ao_rendezvous_try( ao_rendezvous_wait_t * x);
```

```c
void ao_rendezvous_begin( ao_rendezvous_wait_t * x);
```

```c
void ao_rendezvous_end( ao_rendezvous_wait_t * x);
```


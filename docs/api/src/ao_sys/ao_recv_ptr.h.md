---
author: "Stefan Wagner"
date: 2022-08-31
draft: true
permalink: /api/src/ao_sys/ao_recv_ptr.h/
toc: true
---

# Include

```c
#include <ao_async.h>
#include <ao_time.h>
#include <stdbool.h>
```

# Identifier

```c
#define AO_RECV_PTR
```

# Types

## `ao_recv_ptr_t`

```c
typedef struct ao_recv_ptr_t ao_recv_ptr_t;
```

```c
struct ao_recv_ptr_t
{
    ao_async_t         async;
    ao_recv_ptr_proc_t begin;
    ao_recv_ptr_proc_t end;
    void *             parameter;
    void * volatile    ptr;
    bool   volatile    result;
};
```

This type represents the receiving of a pointer. It consists of the following members.

| `async` | The asynchronous event. |
| `begin` | The function beginning the receiving. |
| `end` | The function ending the receiving. |
| `parameter` | An additional parameter. |
| `ptr` | The received pointer. |
| `result` | Indicates whether a pointer has been received. |

## `ao_recv_ptr_proc_t`

```c
typedef void (* ao_recv_ptr_proc_t)
(
    ao_recv_ptr_t * x
);
```

This type represents a function beginning or ending a receiving.

# Functions

## `ao_recv_ptr`
## `ao_recv_ptr_from`

```c
void ao_recv_ptr(     ao_recv_ptr_t * x, ao_time_t timeout);
void ao_recv_ptr_from(ao_recv_ptr_t * x, ao_time_t timeout, ao_time_t beginning);
```

## `ao_recv_ptr_forever`

```c
void ao_recv_ptr_forever(ao_recv_ptr_t * x);
```

## `ao_recv_ptr_try`

```c
void ao_recv_ptr_try(ao_recv_ptr_t * x);
```

## `ao_recv_ptr_begin`
## `ao_recv_ptr_end`

```c
void ao_recv_ptr_begin(ao_recv_ptr_t * x);
void ao_recv_ptr_end(  ao_recv_ptr_t * x);
```

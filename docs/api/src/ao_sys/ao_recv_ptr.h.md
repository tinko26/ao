---
author: "Stefan Wagner"
date: 2022-09-13
draft: true
permalink: /api/src/ao_sys/ao_recv_ptr.h/
toc: true
---

# Notes

This module provides an abstraction for receiving pointers from an opaque source.

# Include

| [`ao_async.h`](ao_async.h.md) |
| [`ao_time.h`](ao_time.h.md) |
| `stdbool.h` |

# Identifier

```c
#define AO_RECV_PTR
```

# Types

## `ao_recv_ptr_t`

```c
typedef struct ao_recv_ptr_t ao_recv_ptr_t;
```

This type represents the receiving of a pointer.

## `ao_recv_ptr_proc_t`

```c
typedef void (* ao_recv_ptr_proc_t)
(
    ao_recv_ptr_t * x
);
```

This type represents a function beginning or ending a receiving of a pointer.

# Structs

## `ao_recv_ptr_t`

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

| `async` | The asynchronous event. |
| `begin` | The function beginning the receiving. |
| `end` | The function ending the receiving. |
| `parameter` | An additional parameter. |
| `ptr` | The received pointer. |
| `result` | The result. |

# Functions

## `ao_recv_ptr`
## `ao_recv_ptr_from`

```c
void ao_recv_ptr     (ao_recv_ptr_t * x, ao_time_t timeout);
void ao_recv_ptr_from(ao_recv_ptr_t * x, ao_time_t timeout, ao_time_t beginning);
```

Receives a pointer in a blocking fashion with a timeout and an optional beginning.

## `ao_recv_ptr_forever`

```c
void ao_recv_ptr_forever(ao_recv_ptr_t * x);
```

Receives a pointer indefinitely in a blocking fashion.

## `ao_recv_ptr_try`

```c
void ao_recv_ptr_try(ao_recv_ptr_t * x);
```

Receives a pointer in a non-blocking fashion.

## `ao_recv_ptr_begin`
## `ao_recv_ptr_end`

```c
void ao_recv_ptr_begin(ao_recv_ptr_t * x);
void ao_recv_ptr_end  (ao_recv_ptr_t * x);
```

Begins or ends, respectively, a receiving of a pointer.

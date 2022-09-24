---
author: "Stefan Wagner"
date: 2022-09-13
draft: true
permalink: /api/src/ao_sys/ao_send_ptr.h/
toc: true
---

# Notes

This module provides an abstraction for sending pointers to an opaque destination.

# Include

| [`ao_async.h`](ao_async.h.md) |
| [`ao_time.h`](ao_time.h.md) |
| `stdbool.h` |

# Identifier

```c
#define AO_SEND_PTR
```

# Types

## `ao_send_ptr_t`

```c
typedef struct ao_send_ptr_t ao_send_ptr_t;
```

This type represents the sending of a pointer.

## `ao_send_ptr_proc_t`

```c
typedef void (* ao_send_ptr_proc_t)
(
    ao_send_ptr_t * x
);
```

This type represents a function beginning or ending a sending of a pointer.

# Structs

## `ao_send_ptr_t`

```c
struct ao_send_ptr_t
{
    ao_async_t         async;
    ao_send_ptr_proc_t begin;
    ao_send_ptr_proc_t end;
    void *             parameter;
    void *             ptr;
    bool volatile      result;
};
```

| `async` | The asynchronous event. |
| `begin` | The function beginning the sending. |
| `end` | The function ending the sending. |
| `parameter` | An additional parameter. |
| `ptr` | The pointer to send. |
| `result` | The result. |

# Functions

## `ao_send_ptr`
## `ao_send_ptr_from`

```c
void ao_send_ptr     (ao_send_ptr_t * x, ao_time_t timeout);
void ao_send_ptr_from(ao_send_ptr_t * x, ao_time_t timeout, ao_time_t beginning);
```

Sends a pointer in a blocking fashion with a timeout and an optional beginning.

## `ao_send_ptr_forever`

```c
void ao_send_ptr_forever(ao_send_ptr_t * x);
```

Sends a pointer indefinitely in a blocking fashion.

## `ao_send_ptr_try`

```c
void ao_send_ptr_try(ao_send_ptr_t * x);
```

Sends a pointer in a non-blocking fashion.

## `ao_send_ptr_begin`
## `ao_send_ptr_end`

```c
void ao_send_ptr_begin(ao_send_ptr_t * x);
void ao_send_ptr_end  (ao_send_ptr_t * x);
```

Begins or ends, respectively, a sending of a pointer.

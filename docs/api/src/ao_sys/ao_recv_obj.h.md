---
author: "Stefan Wagner"
date: 2022-09-26
draft: true
permalink: /api/src/ao_sys/ao_recv_obj.h/
toc: true
---

# Notes

This module provides an abstraction for receiving objects from an opaque source.

# Include

| [`ao_async.h`](ao_async.h.md) |
| [`ao_time.h`](ao_time.h.md) |
| `stdbool.h` |

# Identifier

```c
#define AO_RECV_OBJ
```

# Types

## `ao_recv_obj_t`

```c
typedef struct ao_recv_obj_t ao_recv_obj_t;
```

This type represents the receiving of an object.

## `ao_recv_obj_proc_t`

```c
typedef void (* ao_recv_obj_proc_t)
(
    ao_recv_obj_t * recv
);
```

This type represents a function beginning or ending a receiving of an object.

# Structs

## `ao_recv_obj_t`

```c
struct ao_recv_obj_t
{
    ao_async_t         async;
    ao_recv_obj_proc_t begin;
    ao_recv_obj_proc_t end;
    void *             parameter;
    void *             ptr;
    bool volatile      result;
};
```

| `async` | The asynchronous event. |
| `begin` | The function beginning the receiving. |
| `end` | The function ending the receiving. |
| `parameter` | An additional parameter. |
| `ptr` | A pointer to a location to store the received object. |
| `result` | The result. |

# Functions

## `ao_recv_obj`
## `ao_recv_obj_from`

```c
void ao_recv_obj     (ao_recv_obj_t * recv, ao_time_t timeout);
void ao_recv_obj_from(ao_recv_obj_t * recv, ao_time_t timeout, ao_time_t beginning);
```

Receives an object in a blocking fashion with a timeout and an optional beginning.

## `ao_recv_obj_forever`

```c
void ao_recv_obj_forever(ao_recv_obj_t * recv);
```

Receives an object indefinitely in a blocking fashion.

## `ao_recv_obj_try`

```c
void ao_recv_obj_try(ao_recv_obj_t * recv);
```

Receives an object in a non-blocking fashion.

## `ao_recv_obj_begin`
## `ao_recv_obj_end`

```c
void ao_recv_obj_begin(ao_recv_obj_t * recv);
void ao_recv_obj_end  (ao_recv_obj_t * recv);
```

Begins or ends, respectively, a receiving of an object.

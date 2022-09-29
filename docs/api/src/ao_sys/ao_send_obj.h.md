---
author: "Stefan Wagner"
date: 2022-09-26
draft: true
permalink: /api/src/ao_sys/ao_send_obj.h/
toc: true
---

# Notes

This module provides an abstraction for sending objects to an opaque destination.

# Include

| [`ao_async.h`](ao_async.h.md) |
| [`ao_time.h`](ao_time.h.md) |
| `stdbool.h` |

# Types

## `ao_send_obj_t`

```c
typedef struct ao_send_obj_t ao_send_obj_t;
```

Represents the sending of an object.

## `ao_send_obj_proc_t`

```c
typedef void (* ao_send_obj_proc_t)
(
    ao_send_obj_t * send
);
```

Represents a function beginning or ending a sending of an object.

# Structs

## `ao_send_obj_t`

```c
struct ao_send_obj_t
{
    ao_async_t         async;
    ao_send_obj_proc_t begin;
    ao_send_obj_proc_t end;
    void *             parameter;
    void *             ptr;
    bool volatile      result;
};
```

| `async` | The asynchronous event. |
| `begin` | The function beginning the sending. |
| `end` | The function ending the sending. |
| `parameter` | An additional parameter. |
| `ptr` | A pointer to the object to send. |
| `result` | The result. |

# Functions

## `ao_send_obj`
## `ao_send_obj_from`

```c
void ao_send_obj     (ao_send_obj_t * s, ao_time_t timeout);
void ao_send_obj_from(ao_send_obj_t * s, ao_time_t timeout, ao_time_t beginning);
```

Sends an object in a blocking fashion with a timeout and an optional beginning.

## `ao_send_obj_forever`

```c
void ao_send_obj_forever(ao_send_obj_t * s);
```

Sends an object indefinitely in a blocking fashion.

## `ao_send_obj_try`

```c
void ao_send_obj_try(ao_send_obj_t * s);
```

Sends an object in a non-blocking fashion.

## `ao_send_obj_begin`
## `ao_send_obj_end`

```c
void ao_send_obj_begin(ao_send_obj_t * s);
void ao_send_obj_end  (ao_send_obj_t * s);
```

Begins or ends, respectively, a sending of an object.

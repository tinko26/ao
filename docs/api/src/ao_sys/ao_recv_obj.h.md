---
author: "Stefan Wagner"
date: 2022-08-31
draft: true
permalink: /api/src/ao_sys/ao_recv_obj.h/
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
#define AO_RECV_OBJ
```

# Types

## `ao_recv_obj_t`

```c
typedef struct ao_recv_obj_t ao_recv_obj_t;
```

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

This type represents the receiving of an object. It consists of the following members.

| `async` | The asynchronous event. |
| `begin` | The function beginning the receiving. |
| `end` | The function ending the receiving. |
| `parameter` | An additional parameter. |
| `ptr` | A pointer to a location to store the received object. |
| `result` | Indicates whether an object has been received. |

## `ao_recv_obj_proc_t`

```c
typedef void (* ao_recv_obj_proc_t)
(
    ao_recv_obj_t * x
);
```

This type represents a function beginning or ending a receiving.

# Functions

## `ao_recv_obj`
## `ao_recv_obj_from`

```c
void ao_recv_obj(     ao_recv_obj_t * x, ao_time_t timeout);
void ao_recv_obj_from(ao_recv_obj_t * x, ao_time_t timeout, ao_time_t beginning);
```

## `ao_recv_obj_forever`

```c
void ao_recv_obj_forever(ao_recv_obj_t * x);
```

## `ao_recv_obj_try`

```c
void ao_recv_obj_try(ao_recv_obj_t * x);
```

## `ao_recv_obj_begin`
## `ao_recv_obj_end`

```c
void ao_recv_obj_begin(ao_recv_obj_t * x);
void ao_recv_obj_end(  ao_recv_obj_t * x);
```

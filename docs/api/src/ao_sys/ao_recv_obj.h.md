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

# Typedefs

```c
typedef struct ao_recv_obj_t ao_recv_obj_t;
```

```c
typedef void (* ao_recv_obj_proc_t)
(
    ao_recv_obj_t * x
);
```

# Types

## `ao_recv_obj_t`

This type represents the receiving of an object.

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

It consists of the following members.

| `async` | The asynchronous event. |
| `begin` | The function beginning the receiving. |
| `end` | The function ending the receiving. |
| `parameter` | An additional parameter. |
| `ptr` | A pointer to a location to store the received object. |
| `result` | Indicates whether an object has been received. |

## `ao_recv_obj_proc_t`

This type represents a function beginning or ending a receiving.

# Functions

```c
void ao_recv_obj(ao_recv_obj_t * x, ao_time_t timeout);
```

```c
void ao_recv_obj_from(ao_recv_obj_t * x, ao_time_t timeout, ao_time_t beginning);
```

```c
void ao_recv_obj_forever(ao_recv_obj_t * x);
```

```c
void ao_recv_obj_try(ao_recv_obj_t * x);
```

```c
void ao_recv_obj_begin(ao_recv_obj_t * x);
```

```c
void ao_recv_obj_end(ao_recv_obj_t * x);
```

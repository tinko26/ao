---
author: "Stefan Wagner"
date: 2022-08-31
draft: true
permalink: /api/src/ao_sys/ao_send_obj.h/
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
typedef struct ao_send_obj_t ao_send_obj_t;
```

```c
typedef void (* ao_send_obj_proc_t)
(
    ao_send_obj_t * x
);
```

# Types

## `ao_send_obj_t`

This type represents the sending of an object.

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

It consists of the following members.

| `async` | The asynchronous event. |
| `begin` | The function beginning the sending. |
| `end` | The function ending the sending. |
| `parameter` | An additional parameter. |
| `ptr` | A pointer to the object to send. |
| `result` | Indicates whether the object has been sent. |

## `ao_send_obj_proc_t`

This type represents a function beginning or ending a sending.

# Functions

```c
void ao_send_obj(ao_send_obj_t * x, ao_time_t timeout);
```

```c
void ao_send_obj_from(ao_send_obj_t * x, ao_time_t timeout, ao_time_t beginning);
```

```c
void ao_send_obj_forever(ao_send_obj_t * x);
```

```c
void ao_send_obj_try(ao_send_obj_t * x);
```

```c
void ao_send_obj_begin(ao_send_obj_t * x);
```

```c
void ao_send_obj_end(ao_send_obj_t * x);
```

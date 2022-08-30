---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The /src/ao_sys/ao_send_obj.h file of the ao real-time operating system."
draft: true
permalink: /src/ao_sys/ao_send_obj.h/
subtitle: ""
title: "ao_send_obj.h"
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
typedef void (* ao_send_obj_proc_t) (ao_send_obj_t * x);
```

# Types

## `ao_send_obj_t`

```c
struct ao_send_obj_t
{
    ao_async_t async;
    ao_send_obj_proc_t begin;
    ao_send_obj_proc_t end;
    void * parameter;
    void * ptr;
    bool volatile result;
};
```

Members:

| `async` | |
| `begin` | |
| `end` | |
| `parameter` | |
| `ptr` | |
| `result` | |

# Functions

```c
void ao_send_obj( ao_send_obj_t * x, ao_time_t timeout);
```

```c
void ao_send_obj_from( ao_send_obj_t * x, ao_time_t timeout, ao_time_t beginning);
```

```c
void ao_send_obj_forever( ao_send_obj_t * x);
```

```c
void ao_send_obj_try( ao_send_obj_t * x);
```

```c
void ao_send_obj_begin( ao_send_obj_t * x);
```

```c
void ao_send_obj_end( ao_send_obj_t * x);
```


---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The /src/ao_sys/ao_send_ptr.h file of the ao real-time operating system."
draft: true
permalink: /src/ao_sys/ao_send_ptr.h/
subtitle: ""
title: "ao_send_ptr.h"
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
typedef struct ao_send_ptr_t ao_send_ptr_t;
```

```c
typedef void (* ao_send_ptr_proc_t) (ao_send_ptr_t * x);
```

# Types

## `ao_send_ptr_t`

```c
struct ao_send_ptr_t
{
    ao_async_t async;
    ao_send_ptr_proc_t begin;
    ao_send_ptr_proc_t end;
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
void ao_send_ptr( ao_send_ptr_t * x, ao_time_t timeout);
```

```c
void ao_send_ptr_from( ao_send_ptr_t * x, ao_time_t timeout, ao_time_t beginning);
```

```c
void ao_send_ptr_forever( ao_send_ptr_t * x);
```

```c
void ao_send_ptr_try( ao_send_ptr_t * x);
```

```c
void ao_send_ptr_begin( ao_send_ptr_t * x);
```

```c
void ao_send_ptr_end( ao_send_ptr_t * x);
```


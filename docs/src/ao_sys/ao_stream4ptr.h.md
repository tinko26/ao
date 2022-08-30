---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The /src/ao_sys/ao_stream4ptr.h file of the ao real-time operating system."
draft: true
permalink: /src/ao_sys/ao_stream4ptr.h/
subtitle: ""
title: "ao_stream4ptr.h"
toc: true
---

# Include

```c
#include <ao_async.h>
#include <ao_buffer4ptr.h>
#include <ao_list.h>
#include <ao_time.h>
#include <stdbool.h>
```

# Typedefs

```c
typedef struct ao_stream4ptr_t ao_stream4ptr_t;
```

```c
typedef struct ao_spop_ptr_t ao_spop_ptr_t;
```

```c
typedef struct ao_spush_ptr_t ao_spush_ptr_t;
```

# Types

## `ao_stream4ptr_t`

```c
struct ao_stream4ptr_t
{
    ao_buffer4ptr_t buffer;
    ao_list_t pop;
    ao_list_t push;
};
```

Members:

| `buffer` | |
| `pop` | |
| `push` | |

## `ao_spop_ptr_t`

```c
struct ao_spop_ptr_t
{
    ao_async_t async;
    ao_list_node_t node;
    void * volatile ptr;
    bool volatile result;
    ao_stream4ptr_t * stream;
};
```

Members:

| `async` | |
| `node` | |
| `ptr` | |
| `result` | |
| `stream` | |

## `ao_spush_ptr_t`

```c
struct ao_spush_ptr_t
{
    ao_async_t async;
    ao_list_node_t node;
    void * ptr;
    void * volatile ptr_override;
    bool volatile result;
    bool volatile result_override;
    ao_stream4ptr_t * stream;
};
```

Members:

| `async` | |
| `node` | |
| `ptr` | |
| `ptr_override` | |
| `result` | |
| `result_override` | |
| `stream` | |

# Functions

```c
void ao_spop_ptr( ao_spop_ptr_t * x, ao_time_t timeout);
```

```c
void ao_spop_ptr_from( ao_spop_ptr_t * x, ao_time_t timeout, ao_time_t beginning);
```

```c
void ao_spop_ptr_forever( ao_spop_ptr_t * x);
```

```c
void ao_spop_ptr_try( ao_spop_ptr_t * x);
```

```c
void ao_spop_ptr_begin( ao_spop_ptr_t * x);
```

```c
void ao_spop_ptr_end( ao_spop_ptr_t * x);
```

```c
void ao_spush_acq( ao_spush_ptr_t * x, ao_time_t timeout);
```

```c
void ao_spush_acq_from( ao_spush_ptr_t * x, ao_time_t timeout, ao_time_t beginning);
```

```c
void ao_spush_acq_forever( ao_spush_ptr_t * x);
```

```c
void ao_spush_acq_try( ao_spush_ptr_t * x);
```

```c
void ao_spush_acq_begin( ao_spush_ptr_t * x);
```

```c
void ao_spush_acq_end( ao_spush_ptr_t * x);
```

```c
void ao_spush_acq_override( ao_spush_ptr_t * x);
```

```c
void ao_spush_ptr( ao_spush_ptr_t * x, ao_time_t timeout);
```

```c
void ao_spush_ptr_from( ao_spush_ptr_t * x, ao_time_t timeout, ao_time_t beginning);
```

```c
void ao_spush_ptr_forever( ao_spush_ptr_t * x);
```

```c
void ao_spush_ptr_try( ao_spush_ptr_t * x);
```

```c
void ao_spush_ptr_begin( ao_spush_ptr_t * x);
```

```c
void ao_spush_ptr_end( ao_spush_ptr_t * x);
```

```c
void ao_spush_ptr_override( ao_spush_ptr_t * x);
```


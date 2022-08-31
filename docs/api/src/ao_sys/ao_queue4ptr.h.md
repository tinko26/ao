---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The /src/ao_sys/ao_queue4ptr.h file of the ao real-time operating system."
draft: true
permalink: /api/src/ao_sys/ao_queue4ptr.h/
subtitle: ""
title: "ao_queue4ptr.h"
toc: true
---

# Include

```c
#include <ao_async.h>
#include <ao_heap4ptr.h>
#include <ao_list.h>
#include <ao_time.h>
#include <stdbool.h>
```

# Typedefs

```c
typedef struct ao_queue4ptr_t ao_queue4ptr_t;
```

```c
typedef struct ao_qinsert_ptr_t ao_qinsert_ptr_t;
```

```c
typedef struct ao_qpop_ptr_t ao_qpop_ptr_t;
```

# Types

## `ao_queue4ptr_t`

```c
struct ao_queue4ptr_t
{
    ao_heap4ptr_t heap;
    ao_list_t insert;
    ao_list_t pop;
};
```

It consists of the following members.

| `heap` | |
| `insert` | |
| `pop` | |

## `ao_qinsert_ptr_t`

```c
struct ao_qinsert_ptr_t
{
    ao_async_t async;
    ao_list_node_t node;
    void * ptr;
    ao_queue4ptr_t * queue;
    bool volatile result;
};
```

It consists of the following members.

| `async` | |
| `node` | |
| `ptr` | |
| `queue` | |
| `result` | |

## `ao_qpop_ptr_t`

```c
struct ao_qpop_ptr_t
{
    ao_async_t async;
    ao_list_node_t node;
    void * volatile ptr;
    ao_queue4ptr_t * queue;
    bool volatile result;
};
```

It consists of the following members.

| `async` | |
| `node` | |
| `ptr` | |
| `queue` | |
| `result` | |

# Functions

```c
void ao_qinsert_acq( ao_qinsert_ptr_t * x, ao_time_t timeout);
```

```c
void ao_qinsert_acq_from( ao_qinsert_ptr_t * x, ao_time_t timeout, ao_time_t beginning);
```

```c
void ao_qinsert_acq_forever( ao_qinsert_ptr_t * x);
```

```c
void ao_qinsert_acq_try( ao_qinsert_ptr_t * x);
```

```c
void ao_qinsert_acq_begin( ao_qinsert_ptr_t * x);
```

```c
void ao_qinsert_acq_end( ao_qinsert_ptr_t * x);
```

```c
void ao_qinsert_ptr( ao_qinsert_ptr_t * x, ao_time_t timeout);
```

```c
void ao_qinsert_ptr_from( ao_qinsert_ptr_t * x, ao_time_t timeout, ao_time_t beginning);
```

```c
void ao_qinsert_ptr_forever( ao_qinsert_ptr_t * x);
```

```c
void ao_qinsert_ptr_try( ao_qinsert_ptr_t * x);
```

```c
void ao_qinsert_ptr_begin( ao_qinsert_ptr_t * x);
```

```c
void ao_qinsert_ptr_end( ao_qinsert_ptr_t * x);
```

```c
void ao_qpop_ptr( ao_qpop_ptr_t * x, ao_time_t timeout);
```

```c
void ao_qpop_ptr_from( ao_qpop_ptr_t * x, ao_time_t timeout, ao_time_t beginning);
```

```c
void ao_qpop_ptr_forever( ao_qpop_ptr_t * x);
```

```c
void ao_qpop_ptr_try( ao_qpop_ptr_t * x);
```

```c
void ao_qpop_ptr_begin( ao_qpop_ptr_t * x);
```

```c
void ao_qpop_ptr_end( ao_qpop_ptr_t * x);
```


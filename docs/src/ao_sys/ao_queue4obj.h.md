---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The /src/ao_sys/ao_queue4obj.h file of the ao real-time operating system."
draft: true
permalink: /src/ao_sys/ao_queue4obj.h/
subtitle: ""
title: "ao_queue4obj.h"
toc: true
---

# Include

```c
#include <ao_async.h>
#include <ao_heap4obj.h>
#include <ao_list.h>
#include <ao_time.h>
#include <stdbool.h>
```

# Typedefs

```c
typedef struct ao_queue4obj_t ao_queue4obj_t;
```

```c
typedef struct ao_qinsert_obj_t ao_qinsert_obj_t;
```

```c
typedef struct ao_qpop_obj_t ao_qpop_obj_t;
```

# Types

## `ao_queue4obj_t`

```c
struct ao_queue4obj_t
{
    ao_heap4obj_t heap;
    ao_list_t insert;
    ao_list_t pop;
};
```

Members:

| `heap` | |
| `insert` | |
| `pop` | |

## `ao_qinsert_obj_t`

```c
struct ao_qinsert_obj_t
{
    ao_async_t async;
    ao_list_node_t node;
    void * ptr;
    ao_queue4obj_t * queue;
    bool volatile result;
};
```

Members:

| `async` | |
| `node` | |
| `ptr` | |
| `queue` | |
| `result` | |

## `ao_qpop_obj_t`

```c
struct ao_qpop_obj_t
{
    ao_async_t async;
    ao_list_node_t node;
    void * ptr;
    ao_queue4obj_t * queue;
    bool volatile result;
};
```

Members:

| `async` | |
| `node` | |
| `ptr` | |
| `queue` | |
| `result` | |

# Functions

```c
void ao_qinsert_obj( ao_qinsert_obj_t * x, ao_time_t timeout);
```

```c
void ao_qinsert_obj_from( ao_qinsert_obj_t * x, ao_time_t timeout, ao_time_t beginning);
```

```c
void ao_qinsert_obj_forever( ao_qinsert_obj_t * x);
```

```c
void ao_qinsert_obj_try( ao_qinsert_obj_t * x);
```

```c
void ao_qinsert_obj_begin( ao_qinsert_obj_t * x);
```

```c
void ao_qinsert_obj_end( ao_qinsert_obj_t * x);
```

```c
void ao_qpop_obj( ao_qpop_obj_t * x, ao_time_t timeout);
```

```c
void ao_qpop_obj_from( ao_qpop_obj_t * x, ao_time_t timeout, ao_time_t beginning);
```

```c
void ao_qpop_obj_forever( ao_qpop_obj_t * x);
```

```c
void ao_qpop_obj_try( ao_qpop_obj_t * x);
```

```c
void ao_qpop_obj_begin( ao_qpop_obj_t * x);
```

```c
void ao_qpop_obj_end( ao_qpop_obj_t * x);
```


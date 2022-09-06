---
author: "Stefan Wagner"
date: 2022-08-31
draft: true
permalink: /api/src/ao_sys/ao_queue4obj.h/
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
typedef struct ao_queue4obj_t   ao_queue4obj_t;
```

```c
typedef struct ao_qinsert_obj_t ao_qinsert_obj_t;
```

```c
typedef struct ao_qpop_obj_t    ao_qpop_obj_t;
```

# Types

## `ao_queue4obj_t`

This type represents a queue for objects.

```c
struct ao_queue4obj_t
{
ao_heap4obj_t heap;
ao_list_t     insert;
ao_list_t     pop;
};
```

It consists of the following members.

| `heap` | The heap storing the data. |
| `insert` | The list of tasks attempting to insert data into the queue. |
| `pop` | The list of tasks attempting to pop data from the queue. |

## `ao_qinsert_obj_t`

This type represents the inserting into a queue for objects.

```c
struct ao_qinsert_obj_t
{
ao_async_t       async;
ao_list_node_t   node;
void *           ptr;
ao_queue4obj_t * queue;
bool volatile    result;
};
```

It consists of the following members.

| `async` | The asynchronous event. |
| `node` | The node for the queue's list of inserting tasks. |
| `ptr` | Points to the data to insert. |
| `queue` | The queue. |
| `result` | Indicates whether data has been inserted into the queue. |

## `ao_qpop_obj_t`

This type represents the popping from a queue for objects.

```c
struct ao_qpop_obj_t
{
ao_async_t       async;
ao_list_node_t   node;
void *           ptr;
ao_queue4obj_t * queue;
bool volatile    result;
};
```

It consists of the following members.

| `async` | The asynchronous event. |
| `node` | The node for the queue's list of popping tasks. |
| `ptr` | Points to a location to store the data to pop. |
| `queue` | The queue. |
| `result` | Indicates whether data has been popped from the queue. |

# Functions

```c
void ao_qinsert_obj(ao_qinsert_obj_t * x, ao_time_t timeout);
```

```c
void ao_qinsert_obj_from(ao_qinsert_obj_t * x, ao_time_t timeout, ao_time_t beginning);
```

```c
void ao_qinsert_obj_forever(ao_qinsert_obj_t * x);
```

```c
void ao_qinsert_obj_try(ao_qinsert_obj_t * x);
```

```c
void ao_qinsert_obj_begin(ao_qinsert_obj_t * x);
```

```c
void ao_qinsert_obj_end(ao_qinsert_obj_t * x);
```

```c
void ao_qpop_obj(ao_qpop_obj_t * x, ao_time_t timeout);
```

```c
void ao_qpop_obj_from(ao_qpop_obj_t * x, ao_time_t timeout, ao_time_t beginning);
```

```c
void ao_qpop_obj_forever(ao_qpop_obj_t * x);
```

```c
void ao_qpop_obj_try(ao_qpop_obj_t * x);
```

```c
void ao_qpop_obj_begin(ao_qpop_obj_t * x);
```

```c
void ao_qpop_obj_end(ao_qpop_obj_t * x);
```

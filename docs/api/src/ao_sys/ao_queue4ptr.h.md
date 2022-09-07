---
author: "Stefan Wagner"
date: 2022-08-31
draft: true
permalink: /api/src/ao_sys/ao_queue4ptr.h/
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
typedef struct ao_queue4ptr_t   ao_queue4ptr_t;
```

```c
typedef struct ao_qinsert_ptr_t ao_qinsert_ptr_t;
```

```c
typedef struct ao_qpop_ptr_t    ao_qpop_ptr_t;
```

# Types

## `ao_queue4ptr_t`

This type represents a queue for pointers.

```c
struct ao_queue4ptr_t
{
    ao_heap4ptr_t heap;
    ao_list_t     insert;
    ao_list_t     pop;
};
```

It consists of the following members.

| `heap` | The heap storing the pointers. |
| `insert` | The list of tasks attempting to insert a pointer into the queue. |
| `pop` | The list of tasks attempting to pop a pointer from the queue. |

## `ao_qinsert_ptr_t`

This type represents the inserting into a queue for pointers.

```c
struct ao_qinsert_ptr_t
{
    ao_async_t       async;
    ao_list_node_t   node;
    void *           ptr;
    ao_queue4ptr_t * queue;
    bool volatile    result;
};
```

It consists of the following members.

| `async` | The asynchronous event. |
| `node` | The node for the queue's list of inserting tasks. |
| `ptr` | The pointer to insert. |
| `queue` | The queue. |
| `result` | Indicates whether the pointer has been inserted into the queue. |

## `ao_qpop_ptr_t`

This type represents the popping from a queue for pointers.

```c
struct ao_qpop_ptr_t
{
    ao_async_t       async;
    ao_list_node_t   node;
    void * volatile  ptr;
    ao_queue4ptr_t * queue;
    bool   volatile  result;
};
```

It consists of the following members.

| `async` | The asynchronous event. |
| `node` | The node for the queue's list of popping tasks. |
| `ptr` | The pointer popped from the queue. |
| `queue` | The queue. |
| `result` | Indicates whether a pointer has been popped from the queue. |

# Functions

```c
void ao_qinsert_acq(ao_qinsert_ptr_t * x, ao_time_t timeout);
```

```c
void ao_qinsert_acq_from(ao_qinsert_ptr_t * x, ao_time_t timeout, ao_time_t beginning);
```

```c
void ao_qinsert_acq_forever(ao_qinsert_ptr_t * x);
```

```c
void ao_qinsert_acq_try(ao_qinsert_ptr_t * x);
```

```c
void ao_qinsert_acq_begin(ao_qinsert_ptr_t * x);
```

```c
void ao_qinsert_acq_end(ao_qinsert_ptr_t * x);
```

```c
void ao_qinsert_ptr(ao_qinsert_ptr_t * x, ao_time_t timeout);
```

```c
void ao_qinsert_ptr_from(ao_qinsert_ptr_t * x, ao_time_t timeout, ao_time_t beginning);
```

```c
void ao_qinsert_ptr_forever(ao_qinsert_ptr_t * x);
```

```c
void ao_qinsert_ptr_try(ao_qinsert_ptr_t * x);
```

```c
void ao_qinsert_ptr_begin(ao_qinsert_ptr_t * x);
```

```c
void ao_qinsert_ptr_end(ao_qinsert_ptr_t * x);
```

```c
void ao_qpop_ptr(ao_qpop_ptr_t * x, ao_time_t timeout);
```

```c
void ao_qpop_ptr_from(ao_qpop_ptr_t * x, ao_time_t timeout, ao_time_t beginning);
```

```c
void ao_qpop_ptr_forever(ao_qpop_ptr_t * x);
```

```c
void ao_qpop_ptr_try(ao_qpop_ptr_t * x);
```

```c
void ao_qpop_ptr_begin(ao_qpop_ptr_t * x);
```

```c
void ao_qpop_ptr_end(ao_qpop_ptr_t * x);
```

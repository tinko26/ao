---
author: "Stefan Wagner"
date: 2022-09-13
draft: true
permalink: /api/src/ao_sys/ao_queue4ptr.h/
toc: true
---

# Include

[`ao_async.h`](ao_async.h.md) <br/>
[`ao_heap4ptr.h`](../ao/ao_heap4ptr.h.md) <br/>
[`ao_list.h`](../ao/ao_list.h.md) <br/>
[`ao_time.h`](ao_time.h.md) <br/>
`stdbool.h`

# Identifier

```c
#define AO_QUEUE4PTR
```

# Types

## `ao_queue4ptr_t`

```c
typedef struct ao_queue4ptr_t ao_queue4ptr_t;
```

```c
struct ao_queue4ptr_t
{
    ao_heap4ptr_t heap;
    ao_list_t     insert;
    ao_list_t     pop;
};
```

This type represents a queue for pointers. It consists of the following members.

| `heap` | The heap. |
| `insert` | The list of insertings. |
| `pop` | The list of poppings. |

## `ao_qinsert_ptr_t`

```c
typedef struct ao_qinsert_ptr_t ao_qinsert_ptr_t;
```

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

This type represents the inserting into a queue for pointers. It consists of the following members.

| `async` | The asynchronous event. |
| `node` | The node for the queue's list of insertings. |
| `ptr` | The pointer to insert. |
| `queue` | The queue. |
| `result` | The result. |

## `ao_qpop_ptr_t`

```c
typedef struct ao_qpop_ptr_t ao_qpop_ptr_t;
```

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

This type represents the popping from a queue for pointers. It consists of the following members.

| `async` | The asynchronous event. |
| `node` | The node for the queue's list of poppings. |
| `ptr` | The pointer that has been popped. |
| `queue` | The queue. |
| `result` | The result. |

# Functions

## `ao_qinsert_acq`
## `ao_qinsert_acq_from`

```c
void ao_qinsert_acq     (ao_qinsert_ptr_t * x, ao_time_t timeout);
void ao_qinsert_acq_from(ao_qinsert_ptr_t * x, ao_time_t timeout, ao_time_t beginning);
```

Inserts a pointer to an acquired memory block into a queue in a blocking fashion with a timeout and an optional beginning.

## `ao_qinsert_acq_forever`

```c
void ao_qinsert_acq_forever(ao_qinsert_ptr_t * x);
```

Inserts a pointer to an acquired memory block into a queue indefinitely in a blocking fashion.

## `ao_qinsert_acq_try`

```c
void ao_qinsert_acq_try(ao_qinsert_ptr_t * x);
```

Inserts a pointer to an acquired memory block into a queue in a non-blocking fashion.

## `ao_qinsert_acq_begin`
## `ao_qinsert_acq_end`

```c
void ao_qinsert_acq_begin(ao_qinsert_ptr_t * x);
void ao_qinsert_acq_end  (ao_qinsert_ptr_t * x);
```

Begins or ends, respectively, an inserting of a pointer to an acquired memory block into a queue.

## `ao_qinsert_ptr`
## `ao_qinsert_ptr_from`

```c
void ao_qinsert_ptr     (ao_qinsert_ptr_t * x, ao_time_t timeout);
void ao_qinsert_ptr_from(ao_qinsert_ptr_t * x, ao_time_t timeout, ao_time_t beginning);
```

Inserts a pointer into a queue in a blocking fashion with a timeout and an optional beginning.

## `ao_qinsert_ptr_forever`

```c
void ao_qinsert_ptr_forever(ao_qinsert_ptr_t * x);
```

Inserts a pointer into a queue indefinitely in a blocking fashion.

## `ao_qinsert_ptr_try`

```c
void ao_qinsert_ptr_try(ao_qinsert_ptr_t * x);
```

Inserts a pointer into a queue in a non-blocking fashion.

## `ao_qinsert_ptr_begin`
## `ao_qinsert_ptr_end`

```c
void ao_qinsert_ptr_begin(ao_qinsert_ptr_t * x);
void ao_qinsert_ptr_end  (ao_qinsert_ptr_t * x);
```

Begins or ends, respectively, an inserting of a pointer into a queue.

## `ao_qpop_ptr`
## `ao_qpop_ptr_from`

```c
void ao_qpop_ptr     (ao_qpop_ptr_t * x, ao_time_t timeout);
void ao_qpop_ptr_from(ao_qpop_ptr_t * x, ao_time_t timeout, ao_time_t beginning);
```

Pops a pointer from a queue in a blocking fashion with a timeout and an optional beginning.

## `ao_qpop_ptr_forever`

```c
void ao_qpop_ptr_forever(ao_qpop_ptr_t * x);
```

Pops a pointer from a queue indefinitely in a blocking fashion.

## `ao_qpop_ptr_try`

```c
void ao_qpop_ptr_try(ao_qpop_ptr_t * x);
```

Pops a pointer from a queue in a non-blocking fashion.

## `ao_qpop_ptr_begin`
## `ao_qpop_ptr_end`

```c
void ao_qpop_ptr_begin(ao_qpop_ptr_t * x);
void ao_qpop_ptr_end  (ao_qpop_ptr_t * x);
```

Begins or ends, respectively, a popping of a pointer from a queue.
